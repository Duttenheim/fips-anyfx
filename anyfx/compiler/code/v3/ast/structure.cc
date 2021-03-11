//------------------------------------------------------------------------------
//  @file structure.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "structure.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Structure::Structure()
{
    this->symbolType = StructureType;
}

//------------------------------------------------------------------------------
/**
*/
Structure::~Structure()
{
    for (Variable* var : this->variables)
    {
        delete var;
    }
}

} // namespace AnyFX
