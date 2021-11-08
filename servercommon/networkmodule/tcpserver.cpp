#include "tcpserver.hpp"
#include "libhv/hv.h"

TcpServer::TcpServer()
{
	tls = false;
	enable_unpack = false;
	max_connections = 0xFFFFFFFF;
}

TcpServer::~TcpServer()
{

}

bool TcpServer::ListenAndStartAccept(int post, const char* host /* = "0.0.0.0" */)
{
	int fd = this->createsocket(post, host);
	if (fd < 0) return false;

	acceptor_loop.loop()->postEvent(
		[this, fd](hv::Event* ev) {
			assert(fd >= 0);
			hio_t* listenio = haccept(this->acceptor_loop.hloop(), fd, onAccept);
			hevent_set_userdata(listenio, this);
			if (tls) {
				hio_enable_ssl(listenio);
			}
		}
	);

	return true;
}

int TcpServer::createsocket(int port, const char* host /*= "0.0.0.0"*/)
{
	return Listen(port, host);
}

void TcpServer::setMaxConnectionNum(uint32_t num)
{
	max_connections = num;
}

void TcpServer::setWorkerNum(int num)
{
	worker_loops.setThreadNum(num);
}

void TcpServer::start(bool wait_threads_started /*= true*/)
{
	acceptor_loop.start(wait_threads_started);
	worker_loops.start(wait_threads_started);
}

void TcpServer::stop(bool wait_threads_stopped /*= true*/)
{
	acceptor_loop.stop(wait_threads_stopped);
	worker_loops.stop(wait_threads_stopped);
}

hv::EventLoopPtr TcpServer::loop(int idx /*= -1*/)
{
	return worker_loops.loop(idx);
}

hloop_t* TcpServer::hloop(int idx /*= -1*/)
{
	return worker_loops.hloop(idx);
}

int TcpServer::withTLS(const char* cert_file, const char* key_file)
{
	if (cert_file) {
		hssl_ctx_init_param_t param;
		memset(&param, 0, sizeof(param));
		param.crt_file = cert_file;
		param.key_file = key_file;
		param.endpoint = HSSL_SERVER;
		if (hssl_ctx_init(&param) == NULL) {
			fprintf(stderr, "hssl_ctx_init failed!\n");
			return -1;
		}
	}
	tls = true;
	return 0;
}

void TcpServer::setUnpack(unpack_setting_t* setting)
{
	if (setting) {
		enable_unpack = true;
		unpack_setting = *setting;
	}
	else {
		enable_unpack = false;
	}
}

const hv::SocketChannelPtr& TcpServer::addChannel(hio_t* io)
{
	int fd = hio_fd(io);
	auto channel = hv::SocketChannelPtr(new hv::SocketChannel(io));
	std::lock_guard<std::mutex> locker(mutex_);
	channels[fd] = channel;
	return channels[fd];
}

void TcpServer::removeChannel(const hv::SocketChannelPtr& channel)
{
	int fd = channel->fd();
	std::lock_guard<std::mutex> locker(mutex_);
	channels.erase(fd);
}

size_t TcpServer::connectionNum()
{
	std::lock_guard<std::mutex> locker(mutex_);
	return channels.size();
}

void TcpServer::onAccept(hio_t* connio)
{
	TcpServer* server = (TcpServer*)hevent_userdata(connio);
	if (server->connectionNum() >= server->max_connections) {
		hlogw("over max_connections");
		hio_close(connio);
		return;
	}

	const hv::SocketChannelPtr& channel = server->addChannel(connio);
	channel->status = hv::SocketChannel::CONNECTED;

	printf("onAccept from [%s]\n", channel->peeraddr().c_str());

	channel->onread = [server, &channel](hv::Buffer* buf) {
		if (server->onMessage) {
			server->onMessage(channel, buf);
		}
	};
	channel->onwrite = [server, &channel](hv::Buffer* buf) {
		if (server->onWriteComplete) {
			server->onWriteComplete(channel, buf);
		}
	};
	channel->onclose = [server, &channel]() {
		channel->status = hv::SocketChannel::CLOSED;
		if (server->onConnection) {
			server->onConnection(channel);
		}
		server->removeChannel(channel);
		// NOTE: After removeChannel, channel may be destroyed,
		// so in this lambda function, no code should be added below.
	};

	if (server->enable_unpack) {
		channel->setUnpack(&server->unpack_setting);
	}
	channel->startRead();
	if (server->onConnection) {
		server->onConnection(channel);
	}
}
