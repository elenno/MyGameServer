#include "world.hpp"
#include "module/playermanager.hpp"
#include <cpp_redis/cpp_redis>
#include "servercommon/asynctask/asynctaskmanager.hpp"
#include "servercommon/redis/redismanager.hpp"
#include "servercommon/module_manager.hpp"

extern volatile bool g_server_stop;

World& World::Instance()
{
	static World instance;
	return instance;
}

void World::OnServerStart()
{
	this->StartAsyncTaskThread();
	this->ConnectToRedis();
}

void World::Update(unsigned int now_second)
{
	AsyncTaskManager::Instance().LogicThreadUpdate();

	PlayerManager::Instance().Update(now_second);
}

void World::OnRecv(int fd, const char* data, int length)
{

}

void World::StopServer(const char* reason /*= nullptr*/)
{
	if (reason)
	{
		printf("World::StopServer reason[%s]\n", reason);
	}

	g_server_stop = true;
}

World::~World()
{

}

World::World()
{

}

void World::ConnectToRedis()
{
	// 连不上就会挂掉，reconnect
	if (!RedisManager::Instance().Connect("127.0.0.1", 6379))
	{
		printf("ConnectToRedis Failed! Stop Server");
		this->StopServer("ConnectToRedis Failed");
	}
}

void World::StartAsyncTaskThread()
{
	AsyncTaskManager::Instance().StartAsyncThread();
}

