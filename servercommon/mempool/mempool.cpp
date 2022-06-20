#include "mempool.hpp"
#include <algorithm>

MemPool::MemPool(unsigned int alloc_size, unsigned int increase_num, const std::string& name)
	: m_alloc_size(alloc_size), m_increase_num(increase_num), m_name(name)
{
	this->Increase();
}

void MemPool::Release()
{
	std::for_each(m_increase_records.begin(), m_increase_records.end(), [](void* mem) {
		::free(mem);
	});
}

MemPool::~MemPool()
{

}

void* MemPool::Alloc(size_t size)
{
	if (m_pool.empty())
	{
		this->Increase();
		//if (m_pool.empty())
		//{
		//	std::string reason = "MemPool[" + m_name + "] Bad Alloc";
		//	throw std::exception(reason.c_str());
		//}
	}

	void* mem = m_pool.top();
	m_pool.pop();
	m_alloc_records.insert(mem);

	return mem;
}

void MemPool::Free(void* mem)
{
	std::set<void*>::iterator it = m_alloc_records.find(mem);
	if (it != m_alloc_records.end())
	{
		m_pool.push(*it);
		m_alloc_records.erase(mem);
	}
	else
	{
		//std::string reason = "MemPool[" + m_name + "] Mem Not Created From Pool";
		//throw std::exception(reason.c_str());
	}
}

bool MemPool::IsMemFromThisPool(void* mem) const
{
	return m_alloc_records.find(mem) != m_alloc_records.end();
}

void MemPool::Increase()
{
	void* mem = malloc(m_alloc_size * m_increase_num);
	if (!mem) return;

	for (unsigned int i = 0; i < m_increase_num; ++i)
	{
		void* p = (char*)mem + (m_alloc_size * i);
		m_pool.push(p);
	}

	m_increase_records.push_back(mem);
}


