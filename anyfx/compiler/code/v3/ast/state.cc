//------------------------------------------------------------------------------
//  @file state.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "state.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
State::~State()
{
    for (Entry& entry : this->entries)
    {
        delete entry.arraySizeExpression;
        delete entry.value;
    }
}

} // namespace AnyFX
