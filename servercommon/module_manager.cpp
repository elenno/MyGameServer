#include "module_manager.hpp"
#include "servercommon/imodule.hpp"
#include "module_def.hpp"

ModuleManager& ModuleManager::Instance()
{
	static ModuleManager g_module_mgr; // c++11这样就已经是线程安全的
	return g_module_mgr;
}

bool ModuleManager::RegisterModule(const std::string& module_name, IModule* module_ptr)
{
	if (this->CheckModuleExist(module_name)) return false;

	this->RegisterModuleImpl(module_name, module_ptr);
	return true;
}

bool ModuleManager::PostEvent(const std::string& module_name, const ModuleEventMsg& msg)
{
	IModule* mod = this->GetModuleByName(module_name);
	if (nullptr == mod) return false;

	mod->GetEventLoop()->postEvent([mod, &msg](hv::Event* ev) {
		mod->OnEventMessage(msg);
		if (msg.buffer != nullptr)
		{
			delete msg.buffer;
		}
	});

	return true;
}

IModule* ModuleManager::GetModuleByName(const std::string& module_name)
{
	ModuleMap::iterator it = m_module_map.find(module_name);
	if (it != m_module_map.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}

void ModuleManager::Run()
{
	m_loop_thread_list.reserve(m_module_map.size());
	for (auto it = m_module_map.begin(); it != m_module_map.end(); ++it)
	{
		IModule* module_ptr = it->second;
		module_ptr->Init();

		hv::EventLoopThreadPtr thread = std::make_shared<hv::EventLoopThread>();
		m_loop_thread_list.push_back(thread);
		thread->start(true, [module_ptr]() { return module_ptr->Start(); });
	}
}

void ModuleManager::Stop()
{
	for (auto it = m_module_map.begin(); it != m_module_map.end(); ++it)
	{
		IModule* module_ptr = it->second;
		module_ptr->Stop();
		module_ptr->Release();
	}

	for (auto it = m_loop_thread_list.begin(); it != m_loop_thread_list.end(); ++it)
	{
		hv::EventLoopThreadPtr thread = *it;
		thread->stop(true);
	}
}

bool ModuleManager::CheckModuleExist(const std::string& module_name)
{
	return nullptr != this->GetModuleByName(module_name);
}

void ModuleManager::RegisterModuleImpl(const std::string& module_name, IModule* module_ptr)
{
	m_module_map.insert(ModuleMap::value_type(module_name, module_ptr));
}

