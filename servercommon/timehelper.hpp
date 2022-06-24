#ifndef __TIME_HELPER_HPP__
#define __TIME_HELPER_HPP__

#include "libhv/htime.h"

namespace TimeHelper
{
	unsigned int Timestamp()
	{
		timeval tv;
		gettimeofday(&tv, nullptr);
		return static_cast<unsigned int>(tv.tv_sec);
	}
}

#endif