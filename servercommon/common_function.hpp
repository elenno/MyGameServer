#ifndef __COMMON_FUNCTION_HPP__
#define __COMMON_FUNCTION_HPP__

#include <cassert>

#define F_STRNCPY(dst_str, src_str, dst_len)					\
{                                                               \
	assert(dst_len > 0);										\
	assert(dst_str && src_str);									\
	strncpy_s(dst_str, dst_len, src_str, dst_len - 1);			\
}

#endif