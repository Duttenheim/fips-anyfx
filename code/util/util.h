#pragma once
//------------------------------------------------------------------------------
/**
    @file util.h

    Implements Emit, Error and Assert, as well as removes some MSVC warnings.

    2012 Gustav Sterbrant
*/
//------------------------------------------------------------------------------

#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <type_traits>

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
*/
inline const std::string
FourCCToString(uint32_t fourCC)
{
    char buf[4];
    uint32_t masks[4] =
    {
        0x000000FF
        , 0x0000FF00
        , 0x00FF0000
        , 0xFF000000
    };
    for (int i = 3, shift = 0; i >= 0; i--)
    {
        buf[i] = (char)((fourCC & masks[i]) >> shift);
        shift += 8;
    }
    return std::string(buf, 4);
}

//------------------------------------------------------------------------------
/**
	Neat macro to make enums act as bit flags, be able to check if bits are set, and convert to integers
*/
#define ENUM_OPERATORS(TYPE) \
	constexpr TYPE operator|(TYPE a, TYPE b) { return static_cast<TYPE>(static_cast<unsigned>(a) | static_cast<unsigned>(b)); }\
	constexpr TYPE operator&(TYPE a, TYPE b) { return static_cast<TYPE>(static_cast<unsigned>(a) & static_cast<unsigned>(b)); }\
	constexpr TYPE& operator|=(TYPE& a, TYPE b) { a = static_cast<TYPE>(static_cast<unsigned>(a) | static_cast<unsigned>(b)); return a; }\
	constexpr TYPE& operator&=(TYPE& a, TYPE b) { a = static_cast<TYPE>(static_cast<unsigned>(a) & static_cast<unsigned>(b)); return a; }\
	constexpr TYPE operator|(TYPE a, unsigned b) { return static_cast<TYPE>(static_cast<unsigned>(a) | b); }\
	constexpr TYPE operator&(TYPE a, unsigned b) { return static_cast<TYPE>(static_cast<unsigned>(a) & b); }\
	constexpr TYPE& operator|=(TYPE& a, unsigned b) { a = static_cast<TYPE>(static_cast<unsigned>(a) | b); return a; }\
	constexpr TYPE& operator&=(TYPE& a, unsigned b) { a = static_cast<TYPE>(static_cast<unsigned>(a) & b); return a; }\
	constexpr unsigned operator|(unsigned a, TYPE b) { return a | static_cast<unsigned>(b); }\
	constexpr unsigned operator&(unsigned a, TYPE b) { return a & static_cast<unsigned>(b); }\
	constexpr unsigned& operator|=(unsigned& a, TYPE b) { a = a | static_cast<unsigned>(b); return a; }\
	constexpr unsigned& operator&=(unsigned& a, TYPE b) { a = a & static_cast<unsigned>(b); return a; }\
	constexpr bool operator>(TYPE a, unsigned b) { return static_cast<unsigned>(a) > b; }\
	constexpr bool operator>(unsigned a, TYPE b) { return a > static_cast<unsigned>(b); }\
	constexpr bool operator<(TYPE a, unsigned b) { return static_cast<unsigned>(a) < b; }\
	constexpr bool operator<(unsigned a, TYPE b) { return a < static_cast<unsigned>(b); }\
	constexpr bool HasFlags(const TYPE& a, TYPE flags) { return (a & flags) == flags; }\
	constexpr typename std::underlying_type<TYPE>::type EnumToInt(TYPE a) { return static_cast<typename std::underlying_type<TYPE>::type>(a); }\
    constexpr TYPE IntToEnum(typename std::underlying_type<TYPE>::type a) { return static_cast<TYPE>(a); }

} // namespace AnyFX
