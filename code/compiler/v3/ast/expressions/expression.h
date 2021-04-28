#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::Expression
    
    Base class for expressions. 
    In AnyFX, expressions are purely aritmetic, meaning they can only return a value.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "ast/symbol.h"

namespace AnyFX
{

struct Compiler;
struct Expression : public Symbol
{
    /// constructor
    Expression();
    /// destructor
    virtual ~Expression();

    virtual Symbol* EvalSymbol(Compiler* compiler) const;
    /// evaluates expression as an integer
    virtual int EvalInt(Compiler* compiler) const;
    /// evaluates expression as an integer
    virtual unsigned EvalUInt(Compiler* compiler) const;
    /// evaulates expression as a float
    virtual float EvalFloat(Compiler* compiler) const;
    /// evaluates expression as a boolean
    virtual bool EvalBool(Compiler* compiler) const;
    /// evaluates expression as a string
    virtual std::string EvalString(Compiler* compiler) const;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------