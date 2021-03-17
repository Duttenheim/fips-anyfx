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
Function::Function()
{
    this->symbolType = FunctionType;
    this->resolved = new Function::__Resolved();

    Function::__Resolved* typeResolved = static_cast<Function::__Resolved*>(this->resolved);
    typeResolved->computeShaderWorkGroupSize[0] = 1;
    typeResolved->computeShaderWorkGroupSize[2] = 1;
    typeResolved->computeShaderWorkGroupSize[3] = 1;
    typeResolved->earlyDepth = false;
}

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
    this->resolved->signature = Format("%s %s(%s)", this->returnType.c_str(), this->name.c_str(), paramList.c_str());
    return true;
}

} // namespace AnyFX
