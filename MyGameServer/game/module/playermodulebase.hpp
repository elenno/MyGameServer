#ifndef __PLAYER_MODULE_BASE_HPP__
#define __PLAYER_MODULE_BASE_HPP__

class PlayerModuleBase
{
public:
	static const int IGNORE_DIRTY_FLAG_COUNT_DOWN = 100;
	static const int SAVE_INTERVAL_S = 1;
	static const int SERIALIZE_BUFFER_SIZE = 65536;

public:
	PlayerModuleBase();
	virtual ~PlayerModuleBase();

	virtual bool Serialize(char* buffer, int buffer_size, int* out_length) = 0;
	void Save();
	void SetDirty(bool is_dirty);
	void Update(unsigned int now_second);
	inline bool IsDirty() const { return m_is_dirty; }

private:
	bool m_is_dirty;
	unsigned int m_last_save_timestamp;
	int m_ignore_dirty_flag_countdown;
};

#endif