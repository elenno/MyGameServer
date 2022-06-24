#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include <map>

class Player;
class PlayerManager
{
public:
	typedef std::map<int, Player*> PlayerMap;

public:
	static PlayerManager& Instance();

	void Update(unsigned int now_second);

	void AddPlayer(Player* player);
	Player* GetPlayer(int player_id);
	void RemovePlayer(int player_id);

private:
	PlayerManager();
	~PlayerManager();
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator= (const PlayerManager&) = delete;

	PlayerMap m_player_map;
};

#endif