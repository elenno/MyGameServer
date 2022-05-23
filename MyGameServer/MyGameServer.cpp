// MyGameServer.cpp: 定义应用程序的入口点。
//

#include "MyGameServer.h"
#include "servercommon/networkmodule/networkmodule.hpp"
#include "libhv/EventLoop.h"
#include "servercommon/module_manager.hpp"
#include "game/logicmodule.hpp"

int main()
{
	hlog_set_file("log/hlog");

	std::shared_ptr<NetworkModule> network_module_ptr = std::make_shared<NetworkModule>();
	ModuleManager::Instance().RegisterModule("NetworkModule", network_module_ptr);

	std::shared_ptr<LogicModule> logic_module_ptr = std::make_shared<LogicModule>();
	ModuleManager::Instance().RegisterModule("LogicModule", logic_module_ptr);

	ModuleManager::Instance().Run();

	char command[1024] = { 0 };
	while (gets_s(command))
	{
		if (strcmp(command, "stop") == 0)
		{
			printf("Server Will Stop Now\n");
			break;
		}
	}
	ModuleManager::Instance().Stop();

	system("pause");
	return 0;
}
