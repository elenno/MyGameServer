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
		// �����ܳ��ֵ���ʹ�ò�������Messageʵ�����ӷ�׵����
		long long spaceused = m_proto_list[type]->SpaceUsedLong();
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

