#include "player.hpp"
#include "servercommon/playerdef.hpp"
#include "servercommon/common_function.hpp"
#include <algorithm>
#include "playermodulebase.hpp"

Player::Player() : m_player_id(0), m_create_player_timestamp(0u), m_last_login_timestamp(0u), m_last_logout_timestamp(0u)
{
	memset(m_name, 0, sizeof(m_name));
	memset(m_user_name, 0, sizeof(m_user_name));
}

Player::~Player()
{

}

void Player::Update(unsigned int now_second)
{
	for (auto it : m_player_module_map)
	{
		PlayerModuleBase* ptr = it.second;
		ptr->Update(now_second);
	}
}

void Player::Init(const PlayerInitParam& init_param)
{
	m_player_id = init_param.player_id;
	F_STRNCPY(m_name, init_param.player_name, sizeof(m_name));
	F_STRNCPY(m_user_name, init_param.player_name, sizeof(m_user_name));
	m_create_player_timestamp = init_param.create_player_timestamp;
	m_last_login_timestamp = init_param.last_login_timestamp;
	m_last_logout_timestamp = init_param.last_logout_timestamp;
}

void Player::GetInitParam(PlayerInitParam* out_param)
{
	out_param->player_id = m_player_id;
	F_STRNCPY(out_param->player_name, m_name, sizeof(out_param->player_name));
	F_STRNCPY(out_param->user_name, m_user_name, sizeof(out_param->user_name));
	out_param->create_player_timestamp = m_create_player_timestamp;
	out_param->last_login_timestamp = m_last_login_timestamp;
	out_param->last_logout_timestamp = m_last_logout_timestamp;
}

