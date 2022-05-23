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
	 ע��������Ϣ�ص�
	 @callback	����ص�
	*/
	virtual void RegisterCallback(std::shared_ptr<INetworkCallback> callback) = 0;

	/*
	 ��ʼ�����˿�
	 @port		�����˿�
	 @host		������host
	 @Return	�Ƿ�ɹ�����
	*/
	virtual bool Listen(unsigned short port, const char* host = "0.0.0.0") = 0;
};

#endif