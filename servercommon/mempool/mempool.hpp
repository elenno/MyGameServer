#ifndef __MEM_POOL_HPP__
#define __MEM_POOL_HPP__

// 定长内存池（非线程安全）
#include <string>
#include <vector>
#include <stack>
#include <set>

class MemPool
{
public:
	MemPool(unsigned int alloc_size, unsigned int increase_num, const std::string& name);
	virtual ~MemPool();

	void* Alloc(size_t size);
	void Free(void* mem);

	unsigned int GetAllocSize() const { return m_alloc_size; }
	bool IsMemFromThisPool(void* mem) const;
protected:
	void Increase();

	unsigned int m_alloc_size;
	unsigned int m_increase_num;
	std::string m_name;

	std::vector<void*> m_increase_records; // 用于析构时回收
	
	std::stack<void*> m_pool;
	std::set<void*> m_alloc_records;

private:
	MemPool(const MemPool&);
	MemPool& operator= (const MemPool&);

	void Release();
};




#endif