#include "world.hpp"
#include "module/playermanager.hpp"

World& World::Instance()
{
	static World instance;
	return instance;
}

void World::Update(unsigned int now_second)
{
	PlayerManager::Instance().Update(now_second);
}

World::~World()
{

}

World::World()
{

}

