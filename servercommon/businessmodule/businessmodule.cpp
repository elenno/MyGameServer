#include "businessmodule.hpp"
#include "servercommon/module_def.hpp"
#include "servercommon/networkmodule/inetworkmodule.hpp"

BusinessModule::BusinessModule()
{

}

BusinessModule::~BusinessModule()
{

}

int BusinessModule::Init()
{
	return 0;
}

int BusinessModule::Start()
{
	this->GetEventLoop()->run();
	return 0;
}

int BusinessModule::Stop()
{
	this->GetEventLoop()->stop();
	return 0;
}

int BusinessModule::Release()
{
	return 0;
}

int BusinessModule::Update()
{
	return 0;
}

void BusinessModule::OnEventMessage(const ModuleEventMsg& msg)
{
	
}

void BusinessModule::SetNetworkModule(std::shared_ptr<INetworkModule> network)
{
	m_network_module = network;
}

void BusinessModule::RegisterNetworkCallback(std::shared_ptr<INetworkCallback> callback)
{
	std::shared_ptr<INetworkModule> network_module = m_network_module.lock();
	if (network_module)
	{
		network_module->RegisterCallback(callback);
	}
}

