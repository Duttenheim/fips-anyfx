//------------------------------------------------------------------------------
//  @file declarationstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "declarationstatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
DeclarationStatement::DeclarationStatement(const std::string& type, const std::string& name, const std::vector<std::string>& qualifiers, Expression* initializer)
    : type(type)
    , name(name)
    , qualifiers(qualifiers)
    , initializer(initializer)
{
    this->symbolType = DeclarationStatementType;
}

} // namespace AnyFX
