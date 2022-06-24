#ifndef __LOGIC_MODULE_HPP__
#define __LOGIC_MODULE_HPP__

#include "servercommon/businessmodule/businessmodule.hpp"
#include <memory>
#include "module/playermanager.hpp"

class LogicNetworkCallback;
class LogicModule : public BusinessModule, public std::enable_shared_from_this<LogicModule>
{
public:
	LogicModule();
	virtual ~LogicModule();

	virtual int Init();
	virtual int Start();
	virtual int Stop();
	virtual int Release();
	virtual int Update();

protected:
	std::shared_ptr<LogicNetworkCallback> m_network_callback;
};


#endif