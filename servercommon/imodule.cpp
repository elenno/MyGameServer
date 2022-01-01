#include "imodule.hpp"

IModule::IModule()
{
	m_loop_ptr = std::make_shared<hv::EventLoop>();
}

IModule::~IModule()
{

}
