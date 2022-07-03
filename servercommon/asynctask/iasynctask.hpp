#ifndef __I_ASYNC_TASK_HPP__
#define __I_ASYNC_TASK_HPP__

class IAsyncTask
{
public:
	virtual int DoTask() = 0;
	virtual int DoCallBack() = 0;
	virtual void Destroy() = 0;

protected:
	virtual ~IAsyncTask() {}
	IAsyncTask() {}

private:
	
};

#endif