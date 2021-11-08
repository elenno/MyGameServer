#include "networkmodule.hpp"
#include "libhv/hloop.h"
#include "tcpserver.hpp"

NetworkModule::NetworkModule() : m_tcp_server(nullptr)
{
	m_tcp_server = new TcpServer();
}

NetworkModule::~NetworkModule()
{
	if (nullptr != m_tcp_server)
	{
		delete m_tcp_server;
		m_tcp_server = nullptr;
	}
}

bool NetworkModule::Init(const NetworkModuleInitData& init_data)
{
	m_init_data = init_data;
	return true;
}

int NetworkModule::Start()
{
	m_tcp_server->start(true);
	return 0;
}

bool NetworkModule::Listen(int port)
{
	return m_tcp_server->ListenAndStartAccept(port);
}

