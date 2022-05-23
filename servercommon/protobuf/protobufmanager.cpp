#include "protobufmanager.hpp"
#include "google/protobuf/stubs/common.h"
#include "servercommon/protobuf/proto/testPackage.testProto.pb.h"

ProtobufMgr* ProtobufMgr::Instance()
{
	static ProtobufMgr instance;
	return &instance;
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
		// 检测可能出现的因使用不当导致Message实例变得臃肿的情况
		long long spaceused = m_proto_list[type]->SpaceUsedLong();
		if (spaceused > 500000)
		{
			assert(0);
		}
#endif

		// 当被调用过很多次以后，可能会积聚了大量内存（因使用不当），这里保险起见删掉之前的Message实例，释放掉之前已用的内存	
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
	m_proto_list[PROTO_CS_SEARCH_REQUEST] = new CS_SearchRequest();
	m_proto_list[PROTO_SC_SEARCH_REQUEST] = new SC_SearchRequest();

	static_assert(PROTO_TYPE_MAX == 2, "Adding New Proto Should Add Here");

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

