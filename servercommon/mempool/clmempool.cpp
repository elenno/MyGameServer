#include "clmempool.hpp"
#include "mempool.hpp"
#include <cassert>
#include <sstream>

CLMemPool::CLMemPool()
{
	
}

CLMemPool::~CLMemPool()
{

}

void CLMemPool::Init(std::string name, unsigned int* alloc_size_list, int num, unsigned int increase_num /*= 32*/)
{
	assert(m_pools.empty());
	m_pools.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		if (i > 0 && alloc_size_list[i] <= alloc_size_list[i - 1])
		{
			std::string reason = "CLMemPool Length List Must Be Ascending Sorting";
			throw std::exception(reason.c_str());
		}

		std::stringstream ss;
		ss << name << "_" << i;
		m_pools.push_back(std::make_shared<MemPool>(alloc_size_list[i], increase_num, ss.str()));
	}
}

void* CLMemPool::Alloc(size_t size)
{
	for (size_t i = 0; i < m_pools.size(); ++i)
	{
		if (m_pools[i]->GetAllocSize() >= size)
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			return m_pools[i]->Alloc(size);
		}
	}

	return ::malloc(size);
}

void CLMemPool::Free(void* mem)
{
	for (size_t i = 0; i < m_pools.size(); ++i)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_pools[i]->IsMemFromThisPool(mem))
		{
			m_pools[i]->Free(mem);
			return;
		}
	}
	
	return ::free(mem);
}

