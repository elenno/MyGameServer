#ifndef __BUSINESS_MODULE_HPP__
#define __BUSINESS_MODULE_HPP__

#include "servercommon/imodule.hpp"
#include "libhv/hv.h"
#include "libhv/hloop.h"


class INetworkCallback;
class INetworkModule;
class BusinessModule : public IModule
{
public:
	BusinessModule();
	virtual ~BusinessModule();

	virtual int Init();
	virtual int Start();
	virtual int Stop();
	virtual int Release();
	virtual int Update();

	virtual void OnEventMessage(const ModuleEventMsg& msg);

	void SetNetworkModule(std::shared_ptr<INetworkModule> network);
	void RegisterNetworkCallback(std::shared_ptr<INetworkCallback> callback);
protected:
	std::weak_ptr<INetworkModule> m_network_module;

	//BusinessModule应拥有其他所有Module的weak指针，可直接调用其他Module( 即BusinessModule是高一级的）
};

#endif