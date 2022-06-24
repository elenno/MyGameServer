#ifndef __PLAYER_DEF_HPP__
#define __PLAYER_DEF_HPP__

#include "gamedef.hpp"

struct PlayerInitParam
{
	int player_id;
	PlayerName player_name;
	UserName user_name;
	
	unsigned int create_player_timestamp;
	unsigned int last_login_timestamp;
	unsigned int last_logout_timestamp;
};

#endif