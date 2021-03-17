//------------------------------------------------------------------------------
//  @file compoundvariable.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "compoundvariable.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
CompoundVariable::CompoundVariable()
    : Variable()
{
    this->symbolType = CompoundResourceType;
}

//------------------------------------------------------------------------------
/**
*/
CompoundVariable::~CompoundVariable()
{
}

} // namespace AnyFX
