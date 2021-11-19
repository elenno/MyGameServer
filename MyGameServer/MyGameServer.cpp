// MyGameServer.cpp: 定义应用程序的入口点。
//

#include "MyGameServer.h"
#include "servercommon/networkmodule/networkmodule.hpp"
#include "libhv/EventLoop.h"

int main()
{
	NetworkModuleInitData data;

	NetworkModule network;
	network.Init(data);
	network.Start();

	network.Listen(8888);

	printf("start listen to 8888\n");

	while (1) hv_sleep(100);

	return 0;
}
