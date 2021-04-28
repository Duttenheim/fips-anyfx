//------------------------------------------------------------------------------
//  @file returnstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "returnstatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ReturnStatement::ReturnStatement(Expression* returnValue)
    : returnValue(returnValue)
{
    this->symbolType = ReturnStatementType;
}

} // namespace AnyFX
