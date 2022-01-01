﻿// MyGameServer.cpp: 定义应用程序的入口点。
//

#include "MyGameServer.h"
#include "servercommon/networkmodule/networkmodule.hpp"
#include "libhv/EventLoop.h"
#include "servercommon/module_manager.hpp"
#include "servercommon/businessmodule/businessmodule.hpp"

int main()
{
	hlog_set_file("log/hlog");

	NetworkModule* network_module_ptr = new NetworkModule();
	ModuleManager::Instance().RegisterModule("NetworkModule", network_module_ptr);

	BusinessModule* business_module_ptr = new BusinessModule();
	ModuleManager::Instance().RegisterModule("BusinessModule", business_module_ptr);

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
