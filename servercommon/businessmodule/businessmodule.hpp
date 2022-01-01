#ifndef __BUSINESS_MODULE_HPP__
#define __BUSINESS_MODULE_HPP__

#include "servercommon/imodule.hpp"
#include "libhv/hv.h"
#include "libhv/hloop.h"

class BusinessModule : public IModule
{
public:
	BusinessModule();
	~BusinessModule();

	virtual int Init();
	virtual int Start();
	virtual int Stop();
	virtual int Release();

	virtual void OnEventMessage(const ModuleEventMsg& msg);
};

#endif