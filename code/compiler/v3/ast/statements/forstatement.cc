//------------------------------------------------------------------------------
//  @file forstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "forstatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ForStatement::ForStatement(const std::vector<Variable*> declarations, Expression* condition, Expression* loop, Statement* contents)
    : declarations(declarations)
    , condition(condition)
    , loop(loop)
    , contents(contents)
{
    this->symbolType = ForStatementType;
}

//------------------------------------------------------------------------------
/**
*/
ForStatement::~ForStatement()
{
    for (Variable* var : this->declarations)
        delete var;
    delete this->condition;
    delete this->loop;
    delete this->contents;
}

} // namespace AnyFX
