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

	hv::EventLoop* loop = new hv::EventLoop();
	loop->run();

	return 0;
}
