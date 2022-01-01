#ifndef __MODULE_DEF_HPP__
#define __MODULE_DEF_HPP__

static const char* MODULE_TYPE_NETWORK = "NetworkModule";
static const char* MODULE_TYPE_BUSINESS = "BusinessModule";

struct ModuleEventMsg
{
	ModuleEventMsg() : type(0), data_length(0), buffer(nullptr) {}

	int type;
	int data_length;
	char* buffer;
};


enum MODULE_EVENT_TYPE
{
	NETWORK_TO_BUSINESS = 0,
};


#endif