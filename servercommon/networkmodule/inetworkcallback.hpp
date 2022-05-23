#ifndef __I_NETWORK_CALLBACK_HPP__
#define __I_NETWORK_CALLBACK_HPP__

#include "servercommon/imodule.hpp"

class INetworkCallback
{
public:
	virtual ~INetworkCallback() {}

	void SetCallbackModule(std::shared_ptr<IModule> module_ptr) 
	{
		m_module_ptr = module_ptr;
	}

	/*
	 单有连接accept时则回调该函数
	 @listen_port	本地端端口
	 @fd			该连接的fd
	 @ip			对端地址，点分十进制
	 @port			对端端口号
	*/
	virtual void OnAccept(unsigned short listen_port, int fd, const char* peer_ip, unsigned short peer_port) = 0;

	/*
	 当收到网络消息时回调该函数
	 @netid			网络消息来源的netid
	 @data			网络数据
	 @length		数据长度
	*/
	virtual void OnRecv(int fd, const char* data, int length) = 0;

	/*
	 当有网络断开的时候回调该函数
	 @netid			断开的网络连接的netid
	*/
	virtual void OnDisconnect(int fd) = 0;

	/*
	 当调用异步ConnectAsyn结果返回后回调
	 @result		连接结果是否成功
	 @handle		ConnectAsyn时的输出参数handle
	 @netid			连接成功时，netid时所得连接的网络层id
	 @ip			连接ip
	 @port			连接port
	*/
	virtual void OnConnect(bool result, int handle, int fd, unsigned int ip, unsigned short port) = 0;

	hv::EventLoopPtr GetEventLoopPtr() const 
	{ 
		auto module_ptr = m_module_ptr.lock();
		if (module_ptr)
		{
			return module_ptr->GetEventLoop();
		}
		return nullptr; 
	}

protected:
	std::weak_ptr<IModule> m_module_ptr;
};


#endif