#pragma once
//------------------------------------------------------------------------------
/**
    types.h
    
    Contains data types used to maintain initializers and data types
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "util.h"
namespace AnyFX
{

template<typename T, int S>
struct vector
{
	T v[S];
};

template<typename T, int R, int C>
struct matrix
{
	T m[R][C];
};

enum Qualifiers
{
	NoQualifiers    = 0x0,
	Shared          = 0x1,		// resource should have the same layout despite the shader (useful for include headers)
	Push            = 0x2,	    // resource is a push-constant block
	RangeBind       = 0x4		// resource can be bound as a range of a buffer	
};
typedef unsigned int QualifierFlags;
ENUM_OPERATORS(Qualifiers)

enum Access
{
    NoAccess    = 0x0,
    Read        = 0x1,
    Write       = 0x2,
    ReadWrite   = 0x4,
    Atomic      = 0x8,
    Volatile    = 0x10
};
typedef unsigned int AccessFlags;
ENUM_OPERATORS(Access)

//------------------------------------------------------------------------------
/**
*/
inline bool 
HasFlags(const unsigned int flags, const unsigned int flag)
{
    return ((flags & flag) == flag);
}

}
