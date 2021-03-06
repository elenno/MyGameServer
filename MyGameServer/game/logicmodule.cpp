#include "logicmodule.hpp"
#include "logicnetworkcallback.hpp"
#include "servercommon/networkmodule/inetworkmodule.hpp"
#include "servercommon/module_manager.hpp"
#include "servercommon/timehelper.hpp"
#include "world.hpp"

LogicModule::LogicModule()
{

}

LogicModule::~LogicModule()
{

}

int LogicModule::Init()
{
	BusinessModule::Init();

	//TODO ??????

	m_network_callback = std::make_shared<LogicNetworkCallback>(shared_from_this());
	m_network_callback->SetCallbackModule(shared_from_this());

	std::shared_ptr<INetworkModule> network_module_ptr = std::dynamic_pointer_cast<INetworkModule>(ModuleManager::Instance().GetModuleByName("NetworkModule"));
	if (network_module_ptr)
	{
		this->SetNetworkModule(network_module_ptr);
		this->RegisterNetworkCallback(m_network_callback);
	}

	return 0;
}

int LogicModule::Start()
{
	//TODO ??????
	std::shared_ptr<INetworkModule> network_module_ptr = std::dynamic_pointer_cast<INetworkModule>(ModuleManager::Instance().GetModuleByName("NetworkModule"));
	if (network_module_ptr)
	{
		if (!network_module_ptr->Listen(8888))
		{
			ModuleManager::Instance().Stop();
			return -1;
		}
		else
		{
			printf(" LogicModule::Start listen 8888\n");
		}
	}

	World::Instance().OnServerStart();

	BusinessModule::Start(); // ??????????
	return 0;
}

int LogicModule::Stop()
{
	BusinessModule::Stop();

	return 0;
}

int LogicModule::Release()
{
	BusinessModule::Release();

	return 0;
}

int LogicModule::Update()
{
	BusinessModule::Update();

	hv::EventLoopPtr loop = this->GetEventLoop();

	static const int INTERVAL_MS = 250;
	loop->setInterval(INTERVAL_MS, [](hv::TimerID) {
		unsigned int now_second = TimeHelper::Timestamp();
		World::Instance().Update(now_second);
	});

	return 0;
}

