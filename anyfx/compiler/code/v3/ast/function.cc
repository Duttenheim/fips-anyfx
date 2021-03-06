//------------------------------------------------------------------------------
//  @file function.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "function.h"
#include "util.h"
#include "variable.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
bool
Function::EndOfParse(Compiler* compiler)
{
    std::string paramList;
    for (size_t i = 0; i < this->parameters.size(); i++)
    {
        Variable* var = reinterpret_cast<Variable*>(this->parameters[i]);
        if (i > 0)
            paramList.append(",");
        paramList.append(var->type);
    }
    this->signature = Format("%s %s(%s)", this->returnType.c_str(), this->name.c_str(), paramList.c_str());
    return true;
}

} // namespace AnyFX
