#ifndef __PROTOBUF_MANAGER_HPP__
#define __PROTOBUF_MANAGER_HPP__

#include "servercommon/servercommon.h"
#include "google/protobuf/message.h"

enum PROTO_TYPE
{
	PROTO_ROLE_BATTLE_DATA,
	PROTO_PLATFORM_ROLE_DATA,
	PROTO_BATTLE_CHARACTER_DATA,
	PROTO_CLOUD_ARENA_FIGHT_RECORD_LIST_DATA,
	PROTO_TYPE_MAX,
};

class ProtobufMgr
{
public:
	static ProtobufMgr* Instance();
	google::protobuf::Message* GetProtoMessage(int type);

private:
	google::protobuf::Message* m_proto_list[PROTO_TYPE_MAX];
	int m_used_times[PROTO_TYPE_MAX];

	INSTANCE_FORBID_COPY_AND_EXTERIAL_CREATE(ProtobufMgr);
};


#endif