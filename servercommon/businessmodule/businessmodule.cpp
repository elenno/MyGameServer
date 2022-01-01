#include "businessmodule.hpp"

BusinessModule::BusinessModule()
{

}

BusinessModule::~BusinessModule()
{

}

int BusinessModule::Init()
{
	return 0;
}

int BusinessModule::Start()
{
	this->GetEventLoop()->run();
	return 0;
}

int BusinessModule::Stop()
{
	this->GetEventLoop()->stop();
	return 0;
}

int BusinessModule::Release()
{
	return 0;
}

void BusinessModule::OnEventMessage(const ModuleEventMsg& msg)
{

}

