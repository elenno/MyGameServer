#ifndef __NETWORK_MODULE_HPP__
#define __NETWORK_MODULE_HPP__

#include <string>
#include <vector>
#include "libhv/hv.h"
#include "libhv/hloop.h"
#include "libhv/Channel.h"
#include "servercommon/networkmodule/inetworkmodule.hpp"

class TcpServer;

struct NetworkModuleInitData
{
	NetworkModuleInitData() : worker_num(std::thread::hardware_concurrency()) , with_tls(false), enable_unpack(false) {}

	int worker_num;
	bool with_tls;
	std::string tls_cert_file;
	std::string tls_key_file;
	bool enable_unpack;
	unpack_setting_t unpack_setting;
};

class INetworkCallback;
class NetworkModule : public INetworkModule
{
public:
	typedef std::shared_ptr<TcpServer> TcpServerPtr;
	typedef std::weak_ptr<INetworkCallback> CallbackPtr;
	typedef std::vector<CallbackPtr> CallbackList;

public:
	NetworkModule();
	virtual ~NetworkModule();

	virtual int Init();
	virtual int Start();
	virtual int Stop();
	virtual int Release();
	virtual int Update();

	/*
	 注册网络消息回调
	 @callback	网络回调
	*/
	virtual void RegisterCallback(std::shared_ptr<INetworkCallback> callback);

	/*
	 开始监听端口
	 @port		监听端口
	 @host		监听的host
	 @Return	是否成功监听
	*/
	virtual bool Listen(unsigned short port, const char* host = "0.0.0.0");

	virtual void OnEventMessage(const ModuleEventMsg& msg) {}

	void OnConnection(const hv::SocketChannelPtr& channel);
	void OnRecv(const hv::SocketChannelPtr& channel, hv::Buffer* buffer);
	void OnWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* buffer);

private:
	void CallbackOnAccept(unsigned short listen_port, int fd, const char* peer_ip, unsigned short peer_port);
	void CallbackOnDisconnect(int fd);
	void CallbackOnRecv(int fd, const char* data, int length);

	NetworkModuleInitData m_init_data;
	TcpServerPtr m_tcp_server;
	CallbackList m_callback_list;
};


#endif