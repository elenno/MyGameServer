#include "logicnetworkcallback.hpp"
#include "servercommon/protobuf/protobufmanager.hpp"
#include "google/protobuf/message.h"
#include "servercommon/protobuf/proto/testPackage.testProto.pb.h"

LogicNetworkCallback::LogicNetworkCallback(std::shared_ptr<LogicModule> module_ptr)
{
	m_logic_module_ptr = module_ptr;
}

LogicNetworkCallback::~LogicNetworkCallback()
{

}

void LogicNetworkCallback::OnAccept(unsigned short listen_port, int fd, const char* peer_ip, unsigned short peer_port)
{

}

void LogicNetworkCallback::OnRecv(int fd, const char* data, int length)
{
	static const int HEADER_LENGTH = 4;
	if (length < HEADER_LENGTH)
	{
		assert(0);
		return;
	}

	int msg_type = *(int*)data;
	const char* proto_data = data + HEADER_LENGTH;
	int proto_len = length - HEADER_LENGTH;

	CS_SearchRequest* message = (CS_SearchRequest* )ProtobufMgr::Instance()->GetProtoMessage(PROTO_CS_SEARCH_REQUEST);
	if (NULL == message)
	{
		assert(0);
		return;
	}

	if (!message->ParseFromArray(proto_data, proto_len))
	{
		assert(0);
		return;
	}

	printf("hahaha   str=%s\n", message->cur_time().c_str());
}

void LogicNetworkCallback::OnDisconnect(int fd)
{

}

void LogicNetworkCallback::OnConnect(bool result, int handle, int fd, unsigned int ip, unsigned short port)
{

}

