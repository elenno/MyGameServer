#ifndef __TCP_SERVER_HPP__
#define __TCP_SERVER_HPP__

#include "libhv/hsocket.h"
#include "libhv/hssl.h"
#include "libhv/hlog.h"

#include "libhv/EventLoop.h"
#include "libhv/EventLoopThreadPool.h"
#include "libhv/Callback.h"
#include "libhv/Channel.h"

class TcpServer {
public:
    TcpServer();

    virtual ~TcpServer();

    bool ListenAndStartAccept(int post, const char* host = "0.0.0.0");

    //@retval >=0 listenfd, <0 error
    int createsocket(int port, const char* host = "0.0.0.0");

    void setMaxConnectionNum(uint32_t num);

    void setWorkerNum(int num);

    void start(bool wait_threads_started = true);

    void stop(bool wait_threads_stopped = true);

    hv::EventLoopPtr loop(int idx = -1);

    hloop_t* hloop(int idx = -1);

    int withTLS(const char* cert_file, const char* key_file);

    void setUnpack(unpack_setting_t* setting);

    // channel
    const hv::SocketChannelPtr& addChannel(hio_t* io);

    void removeChannel(const hv::SocketChannelPtr& channel);

    size_t connectionNum();

    void SetConnectionCallback(hv::ConnectionCallback cb);
    void SetMessageCallback(hv::MessageCallback cb);
    void SetWriteCompleteCallback(hv::WriteCompleteCallback cb);

private:
    static void onAccept(hio_t* connio);

public:
    bool                    tls;
    bool                    enable_unpack;
    unpack_setting_t        unpack_setting;
    // Callback
    hv::ConnectionCallback      onConnection;
    hv::MessageCallback         onMessage;
    hv::WriteCompleteCallback   onWriteComplete;

    uint32_t                max_connections;

private:
    // fd => SocketChannelPtr
    std::map<int, hv::SocketChannelPtr> channels; // GUAREDE_BY(mutex_)
    std::mutex mutex_;
    hv::EventLoopThreadPool worker_loops;
    hv::EventLoopThread acceptor_loop;
};


#endif
