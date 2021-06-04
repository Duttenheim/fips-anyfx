#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::Expression
    
    Base class for expressions. 
    In AnyFX, expressions are purely aritmetic, meaning they can only return a value.
    
    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "ast/symbol.h"
#include "v3/ast/types/type.h"

namespace AnyFX
{

struct Compiler;
struct Expression : public Symbol
{
    /// constructor
    Expression();
    /// destructor
    virtual ~Expression();

    /// eval type
    virtual bool EvalType(Compiler* compiler, Type::FullType& out) const;
    /// eval symbol
    virtual bool EvalSymbol(Compiler* compiler, std::string& out) const;
    /// evaluates expression as an integer
    virtual bool EvalInt(Compiler* compiler, int& out) const;
    /// evaluates expression as an integer
    virtual bool EvalUInt(Compiler* compiler, unsigned& out) const;
    /// evaulates expression as a float
    virtual bool EvalFloat(Compiler* compiler, float& out) const;
    /// evaluates expression as a boolean
    virtual bool EvalBool(Compiler* compiler, bool& out) const;
    /// evaluates expression as a string
    virtual std::string EvalString(Compiler* compiler) const;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------