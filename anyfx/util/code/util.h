#ifndef UTIL_H
#define UTIL_H
//------------------------------------------------------------------------------
/**
    @file util.h

    Implements Emit, Error and Assert, as well as removes some MSVC warnings.

    2012 Gustav Sterbrant
*/

#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <type_traits>
#include <immintrin.h>

// remove warning for vsnprintf
#pragma warning( disable : 4996 )

// remove incompatibility with C linkage warning
#pragma warning( disable : 4190 )

// remove loss of data conversion from double to float
#pragma warning( disable : 4244 )

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
    Uses va_list to format message
*/
static void
Emit(const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
	va_end(args);
}

//------------------------------------------------------------------------------
/**
    Simple cout for error
*/
static void
Error(const char* msg)
{
	Emit("error: %s\n", msg);
	abort();
}

//------------------------------------------------------------------------------
/**
	Formats const char* to std::string
*/
static std::string
Format(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	char buf[4096];
	vsnprintf(buf, sizeof(buf), format, args);
	std::string retVal(buf);
	va_end(args);
	return retVal;
}


//------------------------------------------------------------------------------
/**
	Compares const char* with std::string
*/
static bool
operator==(const char* lhs, const std::string& rhs)
{
	return rhs.compare(lhs) == 0;
}

//------------------------------------------------------------------------------
/**
	Compares std::string with const char*
*/
static bool
operator==(const std::string& lhs, const char* rhs)
{
	return lhs.compare(rhs) == 0;
}

//------------------------------------------------------------------------------
/**
	Neat macro to make enums act as bit flags, be able to check if bits are set, and convert to integers
*/
#define ENUM_OPERATORS(TYPE) \
	inline TYPE operator|(TYPE a, TYPE b) { return static_cast<TYPE>(static_cast<unsigned>(a) | static_cast<unsigned>(b)); }\
	inline TYPE operator&(TYPE a, TYPE b) { return static_cast<TYPE>(static_cast<unsigned>(a) & static_cast<unsigned>(b)); }\
	inline TYPE& operator|=(TYPE& a, TYPE b) { a = static_cast<TYPE>(static_cast<unsigned>(a) | static_cast<unsigned>(b)); return a; }\
	inline TYPE& operator&=(TYPE& a, TYPE b) { a = static_cast<TYPE>(static_cast<unsigned>(a) & static_cast<unsigned>(b)); return a; }\
	inline TYPE operator|(TYPE a, unsigned b) { return static_cast<TYPE>(static_cast<unsigned>(a) | b); }\
	inline TYPE operator&(TYPE a, unsigned b) { return static_cast<TYPE>(static_cast<unsigned>(a) & b); }\
	inline TYPE& operator|=(TYPE& a, unsigned b) { a = static_cast<TYPE>(static_cast<unsigned>(a) | b); return a; }\
	inline TYPE& operator&=(TYPE& a, unsigned b) { a = static_cast<TYPE>(static_cast<unsigned>(a) & b); return a; }\
	inline unsigned operator|(unsigned a, TYPE b) { return a | static_cast<unsigned>(b); }\
	inline unsigned operator&(unsigned a, TYPE b) { return a & static_cast<unsigned>(b); }\
	inline unsigned& operator|=(unsigned& a, TYPE b) { a = a | static_cast<unsigned>(b); return a; }\
	inline unsigned& operator&=(unsigned& a, TYPE b) { a = a & static_cast<unsigned>(b); return a; }\
	inline bool operator>(TYPE a, unsigned b) { return static_cast<unsigned>(a) > b; }\
	inline bool operator>(unsigned a, TYPE b) { return a > static_cast<unsigned>(b); }\
	inline bool operator<(TYPE a, unsigned b) { return static_cast<unsigned>(a) < b; }\
	inline bool operator<(unsigned a, TYPE b) { return a < static_cast<unsigned>(b); }\
	inline bool HasFlags(const TYPE& a, TYPE flags) { return (a & flags) == flags; }\


//------------------------------------------------------------------------------
/**
*/
inline unsigned
FirstOne(unsigned long long value)
{
#if __WIN32__
    unsigned long count = 0;
    _BitScanForward64(&count, value);
#else
    int count = __builtin_ctz(value);
#endif
    return count;
}


//------------------------------------------------------------------------------
/**
*/
inline unsigned long long
PopCnt(unsigned long long value)
{
    return _mm_popcnt_u64(value);
}

} // namespace AnyFX


#endif // UTIL_H
