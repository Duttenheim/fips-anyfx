//------------------------------------------------------------------------------
// shaderbase.cc
// (C) 2016 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "shaderbase.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ShaderBase::ShaderBase()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
ShaderBase::~ShaderBase()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void
ShaderBase::OnLoaded()
{
	// empty, override in subclass
}

} // namespace AnyFX