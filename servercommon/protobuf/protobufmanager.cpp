#include "protobufmanager.hpp"
#include "google/protobuf/stubs/common.h"
#include "servercommon/protobuf/role_battle_data.pb.h"
#include "servercommon/protobuf/platform_battle_role_data.pb.h"
#include "servercommon/protobuf/cloud_arena_fight_record_list.pb.h"

ProtobufMgr* gProtoBufMgr = NULL;
ProtobufMgr* ProtobufMgr::Instance()
{
	if (NULL == gProtoBufMgr)
	{
		gProtoBufMgr = new ProtobufMgr();
	}

	return gProtoBufMgr;
}

google::protobuf::Message* ProtobufMgr::GetProtoMessage(int type)
{
	if (type < 0 || type >= PROTO_TYPE_MAX)
	{
		return NULL;
	}

	if (m_used_times[type] > 100)
	{
#ifdef _DEBUG
		// �����ܳ��ֵ���ʹ�ò�������Messageʵ�����ӷ�׵����
		int spaceused = m_proto_list[type]->SpaceUsed();
		if (spaceused > 500000)
		{
			assert(0);
		}
#endif

		// �������ù��ܶ���Ժ󣬿��ܻ�����˴����ڴ棨��ʹ�ò����������ﱣ�����ɾ��֮ǰ��Messageʵ�����ͷŵ�֮ǰ���õ��ڴ�	
		google::protobuf::Message* new_message = m_proto_list[type]->New();
		delete m_proto_list[type];
		m_proto_list[type] = new_message;
		
		m_used_times[type] = 0;
	}

	google::protobuf::Message* message = m_proto_list[type];
	message->Clear();

	++m_used_times[type];

	return message;
}

ProtobufMgr::ProtobufMgr()
{
	m_proto_list[PROTO_ROLE_BATTLE_DATA] = new PB_RoleBattleData();
	m_proto_list[PROTO_PLATFORM_ROLE_DATA] = new PB_PlatformBattleRoleData();
	m_proto_list[PROTO_BATTLE_CHARACTER_DATA] = new PB_BattleCharacterData();
	m_proto_list[PROTO_CLOUD_ARENA_FIGHT_RECORD_LIST_DATA] = new PB_CloudArenaFightRecordList();

	UNSTD_STATIC_CHECK(PROTO_TYPE_MAX == 4);

	memset(m_used_times, 0, sizeof(m_used_times));
}

ProtobufMgr::~ProtobufMgr()
{
	for (int i = 0; i < PROTO_TYPE_MAX; ++i)
	{
		if (NULL != m_proto_list[i])
		{
			delete m_proto_list[i];
			m_proto_list[i] = NULL;
		}
	}

	google::protobuf::ShutdownProtobufLibrary();
}

