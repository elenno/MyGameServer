#include "networkmodule.hpp"
#include "libhv/hloop.h"
#include "tcpserver.hpp"
#include "servercommon/module_manager.hpp"
#include "servercommon/module_def.hpp"
#include "inetworkcallback.hpp"
#include "libhv/hsocket.h"
#include <sstream>
#include "servercommon/mempool/serverclmempool.h"

NetworkModule::NetworkModule()
{
	m_tcp_server = std::make_shared<TcpServer>();
}

NetworkModule::~NetworkModule()
{

}

int NetworkModule::Init()
{
	m_init_data.enable_unpack = true;
	m_init_data.unpack_setting.length_field_coding = ENCODE_BY_LITTEL_ENDIAN;
	m_init_data.worker_num = 4;

	return 0;
}

int NetworkModule::Start()
{
	if (m_init_data.enable_unpack)
	{
		m_tcp_server->setUnpack(&m_init_data.unpack_setting);
	}
	m_tcp_server->setWorkerNum(m_init_data.worker_num);
	if (m_init_data.with_tls)
	{
		m_tcp_server->withTLS(m_init_data.tls_cert_file.c_str(), m_init_data.tls_key_file.c_str());
	}

	m_tcp_server->onConnection = std::bind(&NetworkModule::OnConnection, this, std::placeholders::_1);
	m_tcp_server->onMessage = std::bind(&NetworkModule::OnRecv, this, std::placeholders::_1, std::placeholders::_2);
	m_tcp_server->onWriteComplete = std::bind(&NetworkModule::OnWriteComplete, this, std::placeholders::_1, std::placeholders::_2);

	m_tcp_server->start(true);

	printf("NetworkModule::Start\n");

	this->GetEventLoop()->run();
	
	return 0;
}

int NetworkModule::Stop()
{
	m_tcp_server->stop(true);
	this->GetEventLoop()->stop();
	return 0;
}

int NetworkModule::Release()
{
	return 0;
}

int NetworkModule::Update()
{
	return 0;
}

void NetworkModule::RegisterCallback(std::shared_ptr<INetworkCallback> callback)
{
	for (CallbackPtr cb : m_callback_list)
	{
		if (auto shared_cb = cb.lock())
		{
			if (shared_cb == callback) 
			{
				throw std::exception("callback duplicate");
			}
		}
	}

	m_callback_list.push_back(std::shared_ptr<INetworkCallback>(callback));
}

bool EasyResolveAddr(sockaddr_u* addr, unsigned short* port, std::string* ip)
{
	if (NULL != port)
	{
		*port = sockaddr_port(addr);
	}

	if (NULL != ip)
	{
		char ip_buffer[16] = { 0 };
		*ip = sockaddr_ip(addr, ip_buffer, sizeof(ip_buffer));
	}

	return true;
}

void NetworkModule::OnConnection(const hv::SocketChannelPtr& channel)
{
	if (channel->isConnected())
	{
		printf("OnConnection peeraddr[%s]\n", channel->peeraddr().c_str());

		std::string localaddr = channel->localaddr();
		std::string peeraddr = channel->peeraddr();

		unsigned short listen_port = 0;
		unsigned short peer_port = 0;
		std::string peer_ip;
			
		if (!EasyResolveAddr((sockaddr_u* )hio_localaddr(channel->io()), &listen_port, NULL))
		{
			printf("NetworkModule::OnConnection resolve localaddr failed!\n");
			channel->close();
			return;
		}

		if (!EasyResolveAddr((sockaddr_u*)hio_peeraddr(channel->io()), &peer_port, &peer_ip))
		{
			printf("NetworkModule::OnConnection resolve peeraddr failed!\n");
			channel->close();
			return;
		}

		this->CallbackOnAccept(listen_port, channel->fd(), peer_ip.c_str(), peer_port);
	}
	else if (channel->isClosed())
	{
		printf("OnConnection disconnected peeraddr[%s]\n", channel->peeraddr().c_str());

		this->CallbackOnDisconnect(channel->fd());
	}
}

void NetworkModule::OnRecv(const hv::SocketChannelPtr& channel, hv::Buffer* buffer)
{
	printf("NetworkModule::OnMessage peeraddr[%s] msg[%s] length[%u]\n", channel->peeraddr().c_str(), (const char*)buffer->data(), (unsigned int)buffer->size());

	int length = *(int*)((const char*)buffer->data() + m_tcp_server->unpack_setting.length_field_offset);
	const char* body = (const char*)buffer->data() + m_tcp_server->unpack_setting.body_offset;

	this->CallbackOnRecv(channel->fd(), body, length);
}

void NetworkModule::OnWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* buffer)
{

}

void NetworkModule::CallbackOnAccept(unsigned short listen_port, int fd, const char* peer_ip, unsigned short peer_port)
{
	for (CallbackPtr cb : m_callback_list)
	{
		auto callback = cb.lock();
		if (!callback)
		{
			continue;
		}

		auto loop = callback->GetEventLoopPtr();
		if (!loop)
		{
			continue;
		}

		loop->runInLoop([=] {
			callback->OnAccept(listen_port, fd, peer_ip, peer_port);
		});
	}
}

void NetworkModule::CallbackOnDisconnect(int fd)
{
	for (CallbackPtr cb : m_callback_list)
	{
		auto callback = cb.lock();
		if (!callback)
		{
			continue;
		}

		auto loop = callback->GetEventLoopPtr();
		if (!loop)
		{
			continue;
		}

		loop->runInLoop([=] {
			callback->OnDisconnect(fd);
			});
	}
}

void NetworkModule::CallbackOnRecv(int fd, const char* data, int length)
{
	if (!data) return;
	if (length <= 0) return;

	for (CallbackPtr cb : m_callback_list)
	{
		auto callback = cb.lock();
		if (!callback)
		{
			continue;
		}

		auto loop = callback->GetEventLoopPtr();
		if (!loop)
		{
			continue;
		}

		char* buffer = (char*) new ServerMsgMem[length];
		memcpy(buffer, data, length);
		loop->runInLoop([=] {
			callback->OnRecv(fd, buffer, length);
			ServerMsgMem* tmp = (ServerMsgMem *) buffer;
			delete[] tmp;
			});
	}
}

bool NetworkModule::Listen(unsigned short port, const char* host /*= "0.0.0.0"*/)
{
	return m_tcp_server->ListenAndStartAccept(port);
}

