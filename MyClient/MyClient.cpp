// MyClient.cpp: 定义应用程序的入口点。
//

#include "MyClient.h"
#include "libhv/TcpClient.h"
#include "libhv/EventLoop.h"
#include "libhv/htime.h"
#include "libhv/hbuf.h"
#include "servercommon/protobuf/protobufmanager.hpp"
#include "servercommon/protocol/msgcode.h"
#include "servercommon/protobuf/proto/testPackage.testProto.pb.h"

void Send(const hv::SocketChannelPtr& channel, void* data, unsigned int length)
{
	static char UNPACK_FLAG = UNPACK_BY_LENGTH_FIELD;
	static HVLBuf send_buffer;
	send_buffer.clear();
	send_buffer.append(&UNPACK_FLAG, sizeof(UNPACK_FLAG));
	send_buffer.append(&length, sizeof(length));
	send_buffer.append(data, length);

	channel->write(send_buffer.data(), send_buffer.size());
}

void Send(const hv::SocketChannelPtr& channel, int msg_type, void* msg, unsigned int msg_length)
{
	static HVLBuf send_buffer;
	send_buffer.clear();
	send_buffer.append(&msg_type, sizeof(msg_type));
	send_buffer.append(msg, msg_length);

	Send(channel, send_buffer.data(), send_buffer.size());
}

int main()
{
	hv::TcpClient client;
	int clientfd = client.createsocket(8888, "127.0.0.1");
	if (clientfd < 0)
	{
		return -10;
	}
	printf("client fd[%d]\n", clientfd);

	client.onConnection = [](const hv::SocketChannelPtr& channel) {
		std::string peeraddr = channel->peeraddr();
		if (channel->isConnected()) {
			printf("connected to %s! connfd=%d\n", peeraddr.c_str(), channel->fd());

			// send(time) every 3s
			hv::setInterval(3000, [channel](hv::TimerID timerID) {
				if (channel->isConnected()) {
					char str[DATETIME_FMT_BUFLEN] = { 0 };
					datetime_t dt = datetime_now();
					datetime_fmt(&dt, str);

					CS_SearchRequest* message = (CS_SearchRequest*)ProtobufMgr::Instance()->GetProtoMessage(PROTO_CS_SEARCH_REQUEST);
					if (message)
					{
						message->set_cur_time(str);
						std::string encoded_str = message->SerializeAsString();
						int length = message->GetCachedSize();
						Send(channel, Protocol::CS_SEARCH_REQUEST, (void*)encoded_str.data(), length);
					}				
				}
				else {
					hv::killTimer(timerID);
				}
			});		
		}
		else {
			printf("disconnected to %s! connfd=%d\n", peeraddr.c_str(), channel->fd());
		}
	};

	client.onMessage = [](const hv::SocketChannelPtr& channel, hv::Buffer* buf) {
		printf("< %.*s\n", (int)buf->size(), (char*)buf->data());
	};
	client.onWriteComplete = [](const hv::SocketChannelPtr & channel, hv::Buffer* buf) {
		printf("> %.*s\n", (int)buf->size(), (char*)buf->data());
	};
	// reconnect: 1,2,4,8,10,10,10...
	hv::ReconnectInfo reconn;
	reconn.min_delay = 1000;
	reconn.max_delay = 10000;
	reconn.delay_policy = 2;
	client.setReconnect(&reconn);
	unpack_setting_s setting;
	client.enable_unpack = true;
	client.start();

	while (1) hv_sleep(1);

	return 0;
}
