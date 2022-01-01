#ifndef __MODULE_DEF_HPP__
#define __MODULE_DEF_HPP__

static const char* MODULE_TYPE_NETWORK = "NetworkModule";
static const char* MODULE_TYPE_BUSINESS = "BusinessModule";

#include "libhv/Buffer.h"

struct ModuleEventMsg
{
	ModuleEventMsg() : type(0), data_length(0), buffer(nullptr) {}

	void Alloc(unsigned int len) { buffer = new char[len]; data_length = len; }
	void Free() const { delete[] buffer; }
	void CopyFromHVBuffer(hv::Buffer* hbuf) { this->Alloc(hbuf->size()); memcpy(buffer, hbuf->data(), data_length); }
	void CopyFromBuffer(const char* buf, unsigned int len) { this->Alloc(len); memcpy(buffer, buf, data_length); }

	int type;
	unsigned int data_length;
	char* buffer;
};


enum MODULE_EVENT_TYPE
{
	NETWORK_TO_BUSINESS = 0,
};


#endif