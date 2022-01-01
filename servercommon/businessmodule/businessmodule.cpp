#include "businessmodule.hpp"
#include "servercommon/module_def.hpp"

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
	if (NETWORK_TO_BUSINESS == msg.type)
	{
		this->OnRecvMsgFromNetwork(msg.buffer, msg.data_length);
	}

}

void BusinessModule::OnRecvMsgFromNetwork(const char* data, unsigned int length)
{
	std::string msg(data, length);
	printf("OnRecvMsgFromNetwork data[%s] length[%u]\n", msg.c_str(), (unsigned int)msg.length());
}

