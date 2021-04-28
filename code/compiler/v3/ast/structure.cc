//------------------------------------------------------------------------------
//  @file structure.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "structure.h"
#include "compiler.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Structure::Structure()
{
    this->symbolType = StructureType;
    this->code = UserType;
    this->resolved = new Structure::__Resolved;
    Structure::__Resolved* typeResolved = static_cast<Structure::__Resolved*>(this->resolved);
    typeResolved->usageFlags.bits = 0x0;
    typeResolved->accessBits.bits = 0x0;
    typeResolved->binding = __Resolved::NOT_BOUND;
    typeResolved->group = __Resolved::NOT_BOUND;
    typeResolved->byteSize = 0;
    
}

} // namespace AnyFX
