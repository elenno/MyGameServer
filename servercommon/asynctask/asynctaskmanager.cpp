#include "asynctaskmanager.hpp"
#include "iasynctask.hpp"
#include <mutex>

AsyncTaskManager::AsyncTaskManager() : m_max_task_num_in_queue(0), m_is_stop(false), m_has_started(false)
{
	
}

void AsyncTaskManager::ExtractTaskInPendingQueueWithLock(AsyncTaskQueue* out_queue)
{
	if (NULL != out_queue)
	{
		std::swap(*out_queue, m_pending_task_queue);
	}
}

void AsyncTaskManager::ExcuteTasksInQueue(AsyncTaskQueue& queue) // 异步线程调用
{
	AsyncTaskQueue finished_queue;
	while (!queue.empty())
	{
		IAsyncTask* task = queue.front();
		queue.pop();
		task->DoTask();
		finished_queue.push(task);
	}

	{
		std::lock_guard<std::mutex> guard(m_mutex);
		std::swap(m_finished_task_queue, finished_queue);
	}
}

void AsyncTaskManager::ExcuteTasksCallback() // 逻辑线程调用
{
	AsyncTaskQueue temp_queue;

	{
		std::lock_guard<std::mutex> guard(m_mutex);
		std::swap(temp_queue, m_finished_task_queue);
	}

	while (!temp_queue.empty())
	{
		IAsyncTask* task = temp_queue.front();
		temp_queue.pop();
		task->DoCallBack();
		task->Destroy(); // 异步任务callback完就销毁
	}
}

AsyncTaskManager::~AsyncTaskManager()
{
	this->StopAsyncThread();
}

#ifdef __linux__
static AsyncTaskManager* g_async_task_mgr_instance = NULL;
static MutexLock g_async_task_mgr_instance_mutex;
#endif
AsyncTaskManager& AsyncTaskManager::Instance()
{
#ifdef __linux__
	// linux下暂时没有支持c++11,所以采用双检锁+内存屏障保证不出现乱序执行new AsyncTaskManager()导致的问题
	if (NULL == g_async_task_mgr_instance)
	{
		MutexGuard guard(&g_async_task_mgr_instance_mutex);
		barrier();
		if (NULL == g_async_task_mgr_instance)
		{
			g_async_task_mgr_instance = new AsyncTaskManager();
		}
	}

	return *g_async_task_mgr_instance;
#endif

#ifdef _MSC_VER
	static AsyncTaskManager instance; // c++11后保证正确线程安全，只会有一个实例
	return instance;
#endif
}

void AsyncTaskManager::Init(const AsyncTaskInitConfig& init_cfg)
{
	m_max_task_num_in_queue = init_cfg.max_task_num_in_queue;
}

bool AsyncTaskManager::AddTask(IAsyncTask* task) // 逻辑线程调用
{
	if (NULL == task) return false;

	{
		std::lock_guard<std::mutex> guard(m_mutex);

		if (m_max_task_num_in_queue > 0 && m_pending_task_queue.size() > m_max_task_num_in_queue) return false;

		m_pending_task_queue.push(task);
	}

	m_cond.notify_one();

	return true;
}

void AsyncTaskManager::LogicThreadUpdate()
{
	this->ExcuteTasksCallback();
}

void AsyncTaskManager::AsyncThreadLoop()
{
	while (!m_is_stop)
	{
		AsyncTaskQueue queue;
		
		{
			std::unique_lock<std::mutex> lock(m_mutex);
			while (m_pending_task_queue.empty())
			{
				m_cond.wait(lock);
			}
			this->ExtractTaskInPendingQueueWithLock(&queue);
		}

		this->ExcuteTasksInQueue(queue);
	}
}

void AsyncTaskManager::StopAsyncThread()
{
	if (m_has_started && !m_is_stop)
	{
		m_is_stop = true;
		m_cond.notify_all();
		m_async_thread.join();
	}	
}

void AsyncTaskManager::StartAsyncThread()
{
	// 暂时只启动一个异步线程,如果有多个异步线程，需要使用异步任务的业务代码是线程安全的，这样会增加开发和维护成本
	m_has_started = true;
	m_async_thread = std::thread{ &AsyncTaskManager::AsyncThreadLoop, this };
}

