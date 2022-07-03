#ifndef __ASYNC_TASK_MANAGER_HPP__
#define __ASYNC_TASK_MANAGER_HPP__

#include <queue>
#include <mutex>

struct AsyncTaskInitConfig
{
	AsyncTaskInitConfig() : max_task_num_in_queue(0) {}

	int max_task_num_in_queue;
};

class IAsyncTask;
class AsyncTaskManager
{
public:
	typedef std::queue<IAsyncTask*> AsyncTaskQueue;

public:
	AsyncTaskManager();
	~AsyncTaskManager();

	static AsyncTaskManager& Instance();

	void Init(const AsyncTaskInitConfig& init_cfg);
	bool AddTask(IAsyncTask* task);

	void LogicThreadUpdate();
	void AsyncThreadLoop();
	void StopAsyncThread();

	void StartAsyncThread();
private:
	AsyncTaskManager& operator=(const AsyncTaskManager&) = delete;
	AsyncTaskManager(const AsyncTaskManager&) = delete;

	void ExtractTaskInPendingQueueWithLock(AsyncTaskQueue* out_queue);
	void ExcuteTasksInQueue(AsyncTaskQueue& queue);
	void ExcuteTasksCallback();

	AsyncTaskQueue m_pending_task_queue;
	AsyncTaskQueue m_finished_task_queue;
	std::mutex m_mutex;
	std::condition_variable m_cond;
	std::thread m_async_thread;

	int m_max_task_num_in_queue;
	volatile bool m_is_stop;
	bool m_has_started;
};



#endif