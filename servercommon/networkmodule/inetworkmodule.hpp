#ifndef __I_NETWORK_MODULE_HPP__
#define __I_NETWORK_MODULE_HPP__

#include "servercommon/imodule.hpp"

class INetworkCallback;
class INetworkModule : public IModule
{
public:
	virtual int Init() = 0;
	virtual int Start() = 0;
	virtual int Stop() = 0;
	virtual int Release() = 0;
	virtual int Update() = 0;
	virtual void OnEventMessage(const ModuleEventMsg& msg) = 0;

	/*
	 注册网络消息回调
	 @callback	网络回调
	*/
	virtual void RegisterCallback(std::shared_ptr<INetworkCallback> callback) = 0;

	/*
	 开始监听端口
	 @port		监听端口
	 @host		监听的host
	 @Return	是否成功监听
	*/
	virtual bool Listen(unsigned short port, const char* host = "0.0.0.0") = 0;
};

#endif