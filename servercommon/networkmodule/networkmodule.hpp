#ifndef __NETWORK_MODULE_HPP__
#define __NETWORK_MODULE_HPP__

#include <string>
#include "hv.h"

struct NetworkModuleInitData
{
	std::string host;
	int port;
	int worker_num;
};

class NetworkModule
{
public:
	NetworkModule();
	~NetworkModule();

	bool Init(const NetworkModuleInitData& init_data);
	int Start();

	int WorkerLoopRun(hloop_t* loop);
	int AcceptorLoopRun(hloop_t* loop);
private:
	void OnAccept(hio_t* io);
	hloop_t* GetNextLoop();
	void OnAcceptInWorkerLoop(hevent_t* ev);
	const SocketChannelPtr& AddChannel(hio_t* io);
	void RemoveChannel(const SocketChannelPtr& channel);
	void RegisterOnReadCallback(const SocketChannelPtr& channel);
	void RegisterOnWriteCallback(const SocketChannelPtr& channel);
	void RegisterOnCloseCallback(const SocketChannelPtr& channel);

	std::string m_host;
	int m_port;
	int m_worker_num;
	int m_cur_worker_loop;

	hloop_t* m_acceptor_loop;
	std::vector<hloop_t*> m_worker_loops;
	std::vector<std::thread> m_worker_threads;

	// fd => SocketChannelPtr
	std::map<int, SocketChannelPtr> m_channels; // GUAREDE_BY(m_channel_mutex_)
	std::mutex                      m_channel_mutex_;
};


#endif