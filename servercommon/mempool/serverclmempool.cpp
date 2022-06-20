
#include "serverclmempool.h"

#include "servercommon/mempool/clmempool.hpp"

namespace servermempool
{
	class ServerCLMemPool: public CLMemPool 
	{
	public:
		ServerCLMemPool():CLMemPool()
		{
			unsigned int length_list[] = {32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
			this->Init("ServerCLMemPool", length_list, 16, 16);
		}

		virtual ~ServerCLMemPool()
		{
		}
	};
	ServerCLMemPool g_server_mem_pool;
}


void * ServerMsgMem::operator new[](size_t c)
{
	return servermempool::g_server_mem_pool.Alloc((unsigned int)c);
}

void ServerMsgMem::operator delete[](void *m)
{
	servermempool::g_server_mem_pool.Free(m);
}

