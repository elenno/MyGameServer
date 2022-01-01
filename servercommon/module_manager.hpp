#ifndef __MODULE_MANAGER_HPP__
#define __MODULE_MANAGER_HPP__

#include <map>
#include <string>
#include <vector>
#include "libhv/EventLoopThread.h"

class IModule;
struct ModuleEventMsg;
class ModuleManager
{
public:
	typedef std::map<std::string, IModule*> ModuleMap;
	typedef std::vector<hv::EventLoopThreadPtr> LoopThreadList;

public:
	static ModuleManager& Instance();

	bool RegisterModule(const std::string& module_name, IModule* module_ptr);
	bool PostEvent(const std::string& module_name, const ModuleEventMsg& msg);
	IModule* GetModuleByName(const std::string& module_name);

	void Run();
	void Stop();
private:
	ModuleManager() {};
	~ModuleManager() {};
	ModuleManager& operator= (const ModuleManager&);
	ModuleManager(const ModuleManager&);

	bool CheckModuleExist(const std::string& module_name);
	void RegisterModuleImpl(const std::string& module_name, IModule* module_ptr);

	ModuleMap m_module_map;
	LoopThreadList m_loop_thread_list;
};

#endif