#ifndef __THREAD_SAFE_MEM_POOL_HPP__
#define __THREAD_SAFE_MEM_POOL_HPP__

#include <mutex>

// 线程安全的定长内存池
class MemPool;
class TSMemPool
{
public:
	TSMemPool(unsigned int alloc_size, unsigned int increase_num, const std::string& name);
	virtual ~TSMemPool();

	void* Alloc(size_t size);
	void Free(void* mem);

protected:

	std::mutex m_mutex;
	std::shared_ptr<MemPool> m_mem_pool;
private:
	TSMemPool(const TSMemPool&);
	TSMemPool& operator= (const TSMemPool&);
};


#endif