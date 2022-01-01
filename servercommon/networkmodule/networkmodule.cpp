#include "networkmodule.hpp"
#include "libhv/hloop.h"
#include "tcpserver.hpp"
#include "servercommon/module_manager.hpp"
#include "servercommon/module_def.hpp"

NetworkModule::NetworkModule()
{
	m_tcp_server = std::make_shared<TcpServer>();
}

NetworkModule::~NetworkModule()
{

}

int NetworkModule::Init()
{
	m_init_data.listen_port = 8888;
	m_init_data.enable_unpack = false;
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
	m_tcp_server->onMessage = std::bind(&NetworkModule::OnMessage, this, std::placeholders::_1, std::placeholders::_2);
	m_tcp_server->onWriteComplete = std::bind(&NetworkModule::OnWriteComplete, this, std::placeholders::_1, std::placeholders::_2);

	m_tcp_server->start(true);
	
	this->Listen(m_init_data.listen_port);

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

void NetworkModule::OnConnection(const hv::SocketChannelPtr& channel)
{
	if (channel->isConnected())
	{
		printf("OnConnection peeraddr[%s]\n", channel->peeraddr().c_str());
	}
	else if (channel->isClosed())
	{
		printf("OnConnection disconnected peeraddr[%s]\n", channel->peeraddr().c_str());
	}
}

void NetworkModule::OnMessage(const hv::SocketChannelPtr& channel, hv::Buffer* buffer)
{
	printf("OnMessage peeraddr[%s] msg[%s] length[%u]\n", channel->peeraddr().c_str(), (const char*)buffer->data(), (unsigned int)buffer->size());

	ModuleEventMsg msg;
	msg.type = NETWORK_TO_BUSINESS;
	msg.CopyFromHVBuffer(buffer);
	ModuleManager::Instance().PostEvent(MODULE_TYPE_BUSINESS, msg);
}

void NetworkModule::OnWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* buffer)
{

}

bool NetworkModule::Listen(int port)
{
	return m_tcp_server->ListenAndStartAccept(port);
}

