#ifndef __PROTOBUF_MANAGER_HPP__
#define __PROTOBUF_MANAGER_HPP__

namespace google
{
	namespace protobuf
	{
		class Message;
	}
}

enum PROTO_TYPE
{
	PROTO_CS_SEARCH_REQUEST,
	PROTO_SC_SEARCH_REQUEST,
	PROTO_TYPE_MAX,
};

class ProtobufMgr
{
public:
	static ProtobufMgr* Instance();
	google::protobuf::Message* GetProtoMessage(int type);

private:
	ProtobufMgr();
	~ProtobufMgr();
	ProtobufMgr(const ProtobufMgr&);
	ProtobufMgr& operator=(const ProtobufMgr&);

	google::protobuf::Message* m_proto_list[PROTO_TYPE_MAX];
	int m_used_times[PROTO_TYPE_MAX];
};


#endif