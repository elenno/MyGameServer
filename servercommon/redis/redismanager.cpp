#include "servercommon/redis/redismanager.hpp"

RedisManager& RedisManager::Instance()
{
	static RedisManager instance;
	return instance;
}

bool RedisManager::Connect(const std::string& host, unsigned int port)
{
	//TODO ¥¶¿Ìexception
	try
	{
		m_client.connect(host, port);
		return m_client.is_connected();
	}
	catch (cpp_redis::redis_error& e)
	{
		printf("RedisManager::Connect Exception:%s\n", e.what());
		return false;
	}
}

RedisManager::~RedisManager()
{

}

RedisManager::RedisManager()
{

}

