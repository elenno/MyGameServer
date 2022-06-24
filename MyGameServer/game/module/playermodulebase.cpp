#include "playermodulebase.hpp"
#include "servercommon/mempool/serverclmempool.h"
#include <cassert>

PlayerModuleBase::PlayerModuleBase() : m_is_dirty(false), m_last_save_timestamp(0u), m_ignore_dirty_flag_countdown(IGNORE_DIRTY_FLAG_COUNT_DOWN)
{

}

PlayerModuleBase::~PlayerModuleBase()
{

}

void PlayerModuleBase::Save()
{
	char* buffer = (char*)new ServerMsgMem[SERIALIZE_BUFFER_SIZE];
	int length = 0;
	if (this->Serialize(buffer, SERIALIZE_BUFFER_SIZE, &length))
	{
		//TODO ´æÆðÀ´
	}
	else
	{
		assert(0);
	}
}

void PlayerModuleBase::SetDirty(bool is_dirty)
{
	m_is_dirty = is_dirty;
}

void PlayerModuleBase::Update(unsigned int now_second)
{
	if (m_last_save_timestamp + SAVE_INTERVAL_S > now_second)
	{
		return;
	}

	m_ignore_dirty_flag_countdown -= 1;

	if (!this->IsDirty() && m_ignore_dirty_flag_countdown > 0)
	{
		return;
	}

	m_ignore_dirty_flag_countdown = IGNORE_DIRTY_FLAG_COUNT_DOWN;
	m_last_save_timestamp = now_second;
	m_is_dirty = false;

	this->Save();
}
