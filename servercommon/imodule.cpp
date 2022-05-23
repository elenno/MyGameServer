#include "imodule.hpp"

IModule::IModule()
{
	m_loop_ptr = std::make_shared<hv::EventLoop>();
	this->LoopUpdate();
}

IModule::~IModule()
{

}

void IModule::LoopUpdate()
{
	m_loop_ptr->queueInLoop([this]{
		this->Update();
		this->LoopUpdate();
		});
	
	//m_loop_ptr->setInterval(1, [this](hv::TimerID) {
	//	this->Update();
	//	this->LoopUpdate();
	//	});
}
