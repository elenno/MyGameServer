// MyGameServer.cpp: 定义应用程序的入口点。
//

#include "MyGameServer.h"
#include "servercommon/networkmodule/networkmodule.hpp"

int main()
{
	NetworkModuleInitData data;
	data.host = "0.0.0.0";
	data.port = 8888;
	data.worker_num = 4;

	NetworkModule network;
	network.Init(data);
	network.Start();

	return 0;
}
