#ifndef __REDIS_MANAGER_HPP__
#define __REDIS_MANAGER_HPP__

#include <cpp_redis/cpp_redis>

class RedisManager
{
public:
	static RedisManager& Instance();

	bool Connect(const std::string& host, unsigned int port);

private:
	RedisManager();
	~RedisManager();
	RedisManager& operator=(const RedisManager&) = delete;
	RedisManager(const RedisManager&) = delete;

	cpp_redis::client m_client;
};


#endif