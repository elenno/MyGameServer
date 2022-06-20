#ifndef __CUSTOM_LENGTH_MEM_POOL_HPP__
#define __CUSTOM_LENGTH_MEM_POOL_HPP__

#include <mutex>
#include <vector>

/*
	Custom length memory pool
	可定制长度的内存池，使用定长内存池MemPool来组合成可定制长度的内存池

	使用：该类使用Init来初始化定制长度，考虑到内存池使用时可能作为全局数据存在，无法调用Init函数，在此
	情况下，请继承该类，在子类的构造函数中调用CLMemPool::Init函数

	PS：Init过后使用Alloc和Free，线程安全
*/

class MemPool;
class CLMemPool
{
public:
	CLMemPool();
	virtual ~CLMemPool();

	void Init(std::string name, unsigned int* alloc_size_list, int num, unsigned int increase_num = 32);

	void* Alloc(size_t size);
	void Free(void* mem);

protected:

	std::mutex m_mutex;
	std::vector<std::shared_ptr<MemPool> > m_pools;
private:
	CLMemPool(const CLMemPool&);
	CLMemPool& operator= (const CLMemPool&);
};


#endif