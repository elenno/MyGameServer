#include "playermanager.hpp"
#include "player.hpp"

PlayerManager& PlayerManager::Instance()
{
	//C++11开始这样就已经线程安全了
	static PlayerManager instance;
	return instance;
}

void PlayerManager::Update(unsigned int now_second)
{
	for (auto it : m_player_map)
	{
		Player* player = it.second;
		player->Update(now_second);
	}
}

void PlayerManager::AddPlayer(Player* player)
{
	m_player_map.insert(PlayerMap::value_type(player->GetPlayerId(), player));
}

Player* PlayerManager::GetPlayer(int player_id)
{
	auto it = m_player_map.find(player_id);
	if (it == m_player_map.end()) return NULL;

	return it->second;
}

void PlayerManager::RemovePlayer(int player_id)
{
	m_player_map.erase(player_id);
}

PlayerManager::PlayerManager()
{

}

PlayerManager::~PlayerManager()
{

}

