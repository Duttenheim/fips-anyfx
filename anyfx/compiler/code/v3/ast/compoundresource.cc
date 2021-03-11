//------------------------------------------------------------------------------
//  @file compoundresource.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "compoundresource.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
CompoundResource::CompoundResource()
    : arraySizeExpression(nullptr)
{
    this->symbolType = CompoundResourceType;
}

//------------------------------------------------------------------------------
/**
*/
CompoundResource::~CompoundResource()
{
}

} // namespace AnyFX
