#ifndef __CUSTOM_LENGTH_MEM_POOL_HPP__
#define __CUSTOM_LENGTH_MEM_POOL_HPP__

#include <mutex>
#include <vector>

/*
	Custom length memory pool
	�ɶ��Ƴ��ȵ��ڴ�أ�ʹ�ö����ڴ��MemPool����ϳɿɶ��Ƴ��ȵ��ڴ��

	ʹ�ã�����ʹ��Init����ʼ�����Ƴ��ȣ����ǵ��ڴ��ʹ��ʱ������Ϊȫ�����ݴ��ڣ��޷�����Init�������ڴ�
	����£���̳и��࣬������Ĺ��캯���е���CLMemPool::Init����

	PS��Init����ʹ��Alloc��Free���̰߳�ȫ
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