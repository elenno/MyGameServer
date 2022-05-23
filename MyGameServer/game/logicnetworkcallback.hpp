#ifndef __LOGIC_NETWORK_CALLBACK_HPP__
#define __LOGIC_NETWORK_CALLBACK_HPP__

#include "servercommon/networkmodule/inetworkcallback.hpp"
#include <memory>

class LogicModule;
class IModule;
class LogicNetworkCallback : public INetworkCallback
{
public:
	LogicNetworkCallback(std::shared_ptr<LogicModule> module_ptr);
	virtual ~LogicNetworkCallback();

	virtual void OnAccept(unsigned short listen_port, int fd, const char* peer_ip, unsigned short peer_port);
	virtual void OnRecv(int fd, const char* data, int length);
	virtual void OnDisconnect(int fd);
	virtual void OnConnect(bool result, int handle, int fd, unsigned int ip, unsigned short port);
protected:

	std::weak_ptr<LogicModule> m_logic_module_ptr;
};

#endif