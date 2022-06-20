#include "tsmempool.hpp"
#include "mempool.hpp"

TSMemPool::TSMemPool(unsigned int alloc_size, unsigned int increase_num, const std::string& name)
{
	m_mem_pool = std::make_shared<MemPool>(alloc_size, increase_num, name);
}

TSMemPool::~TSMemPool()
{

}

void* TSMemPool::Alloc(size_t size)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_mem_pool->Alloc(size);
}

void TSMemPool::Free(void* mem)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_mem_pool->Free(mem);
}

