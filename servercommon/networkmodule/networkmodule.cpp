#include "networkmodule.hpp"
#include "hloop.h"

NetworkModule::NetworkModule() : m_port(0u), m_worker_num(0), m_cur_worker_loop(0)
{

}

NetworkModule::~NetworkModule()
{

}

bool NetworkModule::Init(const NetworkModuleInitData& init_data)
{
	m_host = init_data.host;
	m_port = init_data.port;
	m_worker_num = init_data.worker_num;
	assert(m_worker_num > 0);
	assert(m_port > 0 && m_port < 65535);
	if (m_host.empty())
	{
		m_host = "0.0.0.0";
	}
	m_worker_loops.reserve(m_worker_num);
	m_cur_worker_loop = 0;
}

int NetworkModule::Start()
{
	for (int i = 0; i < m_worker_num; ++i)
	{
		hloop_t* loop = hloop_new(HLOOP_FLAG_AUTO_FREE);
		m_worker_loops.push_back(loop);
		std::thread t(std::bind(&NetworkModule::WorkerLoopRun, this, loop));
	}
	
	m_acceptor_loop = hloop_new(HLOOP_FLAG_AUTO_FREE);
	this->AcceptorLoopRun(m_acceptor_loop);

	return 0;
}

int NetworkModule::WorkerLoopRun(hloop_t* loop)
{
	hloop_run(loop);
	return 0;
}

int NetworkModule::AcceptorLoopRun(hloop_t* loop)
{
	hio_t* listenio = hloop_create_tcp_server(loop, m_host.c_str(), m_port, &NetworkModule::OnAccept);
	if (listenio == NULL) 
	{
		exit(1);
	}
	hloop_run(loop);
	return 0;
}

void NetworkModule::OnAccept(hio_t* io)
{
	hio_detach(io);

	hloop_t* worker_loop = this->GetNextLoop();
	assert(NULL != worker_loop);

	hevent_t ev;
	memset(&ev, 0, sizeof(ev));
	ev.loop = worker_loop;
	ev.cb = std::function(std::bind(&NetworkModule::OnAcceptInWorkerLoop, this));
	ev.userdata = io;
	hloop_post_event(worker_loop, &ev);
}

hloop_t* NetworkModule::GetNextLoop()
{
	if (m_worker_loops.empty()) return NULL;

	hloop_t* loop = m_worker_loops[m_cur_worker_loop];
	m_cur_worker_loop = (m_cur_worker_loop + 1) % (int)m_worker_loops.size();
	return loop;
}

void NetworkModule::OnAcceptInWorkerLoop(hevent_t* ev)
{
	hloop_t* loop = ev->loop;
	hio_t* io = (hio_t*)hevent_userdata(ev);
	hio_attach(loop, io);

	char localaddrstr[SOCKADDR_STRLEN] = { 0 };
	char peeraddrstr[SOCKADDR_STRLEN] = { 0 };
	printf("tid=%ld connfd=%d [%s] <= [%s]\n",
		(long)hv_gettid(),
		(int)hio_fd(io),
		SOCKADDR_STR(hio_localaddr(io), localaddrstr),
		SOCKADDR_STR(hio_peeraddr(io), peeraddrstr));

	auto channel_ptr = this->AddChannel(io);

	this->RegisterOnReadCallback(channel_ptr);
	this->RegisterOnWriteCallback(channel_ptr);
	this->RegisterOnCloseCallback(channel_ptr);

	channel_ptr->startRead();
}

const SocketChannelPtr& NetworkModule::AddChannel(hio_t* io)
{
	auto channel = SocketChannelPtr(new SocketChannel(io));
	int fd = ptr->fd();
	
	{
		std::lock_guard<std::mutex> lock(m_channel_mutex_);
		m_channels[fd] = ptr;
	}
}

void NetworkModule::RemoveChannel(const SocketChannelPtr& channel)
{
	int fd = channel->fd();

	{
		std::lock_guard<std::mutex> lock(m_channel_mutex_);
		m_channels.erase(fd);
	}
}

void NetworkModule::RegisterOnReadCallback(const SocketChannelPtr& channel)
{
	channel->onread = [this, channel](Buffer* buffer) {
		printf("On Read!\n");
	}
}

void NetworkModule::RegisterOnWriteCallback(const SocketChannelPtr& channel)
{
	channel->onwrite = [this, channel](Buffer* buffer) {
		printf("On Write Complete!\n");
	}
}

void NetworkModule::RegisterOnCloseCallback(const SocketChannelPtr& channel)
{
	channel->onclose = [this, channel]() {
		printf("On Close!\n");
	}
	this->RemoveChannel(channel);
}

