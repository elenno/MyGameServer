#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "servercommon/gamedef.hpp"
#include <map>
#include <string>

struct PlayerInitParam;
class PlayerModuleBase;
class Player
{
public:
	typedef std::map<std::string, PlayerModuleBase*> PlayerModuleMap;

public:
	Player();
	~Player();

	void Update(unsigned int now_second);

	void Init(const PlayerInitParam& init_param);
	void GetInitParam(PlayerInitParam* out_param);

	inline int GetPlayerId() const { return m_player_id; }
	inline const char* GetPlayerName() const { return m_name; }
	
private:
	int m_player_id;
	PlayerName m_name;
	UserName m_user_name;

	unsigned int m_create_player_timestamp;
	unsigned int m_last_login_timestamp;
	unsigned int m_last_logout_timestamp;

	PlayerModuleMap m_player_module_map;
};

#endif