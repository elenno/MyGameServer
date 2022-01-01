#ifndef __NETWORK_MODULE_HPP__
#define __NETWORK_MODULE_HPP__

#include <string>
#include "libhv/hv.h"
#include "libhv/hloop.h"
#include "libhv/Channel.h"
#include "servercommon/imodule.hpp"

class TcpServer;

struct NetworkModuleInitData
{
	NetworkModuleInitData() : worker_num(std::thread::hardware_concurrency()) , with_tls(false), enable_unpack(false), listen_port(0) {}

	int worker_num;
	bool with_tls;
	std::string tls_cert_file;
	std::string tls_key_file;
	bool enable_unpack;
	unpack_setting_t unpack_setting;
	int listen_port;
};

class NetworkModule : public IModule
{
public:
	typedef std::shared_ptr<TcpServer> TcpServerPtr;

public:
	NetworkModule();
	~NetworkModule();

	virtual int Init();
	virtual int Start();
	virtual int Stop();
	virtual int Release();

	virtual void OnEventMessage(const ModuleEventMsg& msg) {}

	void OnConnection(const hv::SocketChannelPtr& channel);
	void OnMessage(const hv::SocketChannelPtr& channel, hv::Buffer* buffer);
	void OnWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* buffer);

private:
	bool Listen(int port);

	NetworkModuleInitData m_init_data;
	TcpServerPtr m_tcp_server;
};


#endif