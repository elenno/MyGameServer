#ifndef __I_MODULE_HPP__
#define __I_MODULE_HPP__

#include "libhv/EventLoop.h"
#include "libhv/EventLoopThread.h"

struct ModuleEventMsg;
class IModule
{
public:
	IModule();
	virtual ~IModule();

	virtual int Init() = 0;
	virtual int Start() = 0;
	virtual int Stop() = 0;
	virtual int Release() = 0;
	virtual int Update() = 0;

	hv::EventLoopPtr GetEventLoop() { return m_loop_ptr; }

	virtual void OnEventMessage(const ModuleEventMsg& msg) = 0;

private:
	

protected:
	void LoopUpdate();

	hv::EventLoopPtr m_loop_ptr;
};


#endif