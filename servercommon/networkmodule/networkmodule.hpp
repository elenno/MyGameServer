#ifndef __NETWORK_MODULE_HPP__
#define __NETWORK_MODULE_HPP__

#include <string>
#include "libhv/hv.h"
#include "libhv/hloop.h"
#include "libhv/Channel.h"

class TcpServer;

struct NetworkModuleInitData
{
	NetworkModuleInitData() : worker_num(std::thread::hardware_concurrency()) , with_tls(false) { }

	int worker_num;
	bool with_tls;
	std::string tls_cert_file;
	std::string tls_key_file;
};

class NetworkModule
{
public:
	NetworkModule();
	~NetworkModule();

	bool Init(const NetworkModuleInitData& init_data);
	int Start();

	bool Listen(int port);
	
private:
	NetworkModuleInitData m_init_data;
	TcpServer* m_tcp_server;
};


#endif