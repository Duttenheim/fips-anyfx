//------------------------------------------------------------------------------
//  binaryexpression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "binaryexpression.h"
#include "ast/function.h"
#include "compiler.h"
#include "util.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
BinaryExpression::BinaryExpression(uint32_t op, Expression* left, Expression* right) 
    : op(op)
    , left(left)
    , right(right)
{
    this->symbolType = Symbol::BinaryExpressionType;
}


//------------------------------------------------------------------------------
/**
*/
BinaryExpression::~BinaryExpression()
{
    delete this->left;
    delete this->right;
}

//------------------------------------------------------------------------------
/**
*/
bool
BinaryExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    bool ret = true;
    Type::FullType leftType, rightType;
    ret &= this->left->EvalType(compiler, leftType);
    ret &= this->right->EvalType(compiler, rightType);

    Type* leftTypeSymbol = compiler->GetSymbol<Type>(leftType.name);
    Type* rightTypeSymbol = compiler->GetSymbol<Type>(rightType.name);

    std::string functionName = Format("operator%s", FourCCToString(this->op).c_str());
    std::vector<Symbol*> functions = leftTypeSymbol->GetSymbols(functionName);
    Symbol* matchingOverload = Function::MatchOverload(compiler, functions, { rightType });
    if (matchingOverload != nullptr)
    {
        Function* fun = static_cast<Function*>(matchingOverload);
        out = fun->returnType;
    }
    else
    {
        ret = false;
    }
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool
BinaryExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    bool ret = true;
    ret &= this->left->EvalSymbol(compiler, out);
    if (this->right != nullptr)
        ret &= this->right->EvalSymbol(compiler, out);
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalInt(Compiler* compiler, int& out) const
{
    int lVal, rVal;
    this->left->EvalInt(compiler, lVal);
    this->right->EvalInt(compiler, rVal);

    if (this->op == '+')
    {
        out = lVal + rVal;
    }
    else if (this->op == '-')
    {
        out = lVal - rVal;
    }
    else if (this->op == '*')
    {
        out = lVal * rVal;
    }
    else if (this->op == '/')
    {
        out = lVal / rVal;
    }
    else if (this->op == '%')
    {
        out = lVal % rVal;
    }
    else if (this->op == '^')
    {
        out = lVal ^ rVal;
    }
    else if (this->op == '|')
    {
        out = lVal | rVal;
    }
    else if (this->op == '&')
    {
        out = lVal & rVal;
    }
    else if (this->op == '>>')
    {
        out = lVal >> rVal;
    }
    else if (this->op == '<<')
    {
        out = lVal << rVal;
    }
    else if (this->op == '||')
    {
        out = (int)(lVal || rVal);
    }
    else if (this->op == '&&')
    {
        out = (int)(lVal & rVal);
    }
    else if (this->op == '<')
    {
        out = (int)(lVal < rVal);
    }
    else if (this->op == '>')
    {
        out = (int)(lVal > rVal);
    }
    else if (this->op == '<=')
    {
        out = (int)(lVal <= rVal);
    }
    else if (this->op == '>=')
    {
        out = (int)(lVal >= rVal);
    }
    else if (this->op == '==')
    {
        out = (int)(lVal == rVal);
    }
    else if (this->op == '!=')
    {
        out = (int)(lVal != rVal);
    }
    else
    {
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
BinaryExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    unsigned lVal, rVal;
    this->left->EvalUInt(compiler, lVal);
    this->right->EvalUInt(compiler, rVal);

    if (this->op == '+')
    {
        out = lVal + rVal;
    }
    else if (this->op == '-')
    {
        out = lVal - rVal;
    }
    else if (this->op == '*')
    {
        out = lVal * rVal;
    }
    else if (this->op == '/')
    {
        out = lVal / rVal;
    }
    else if (this->op == '%')
    {
        out = lVal % rVal;
    }
    else if (this->op == '^')
    {
        out = lVal ^ rVal;
    }
    else if (this->op == '|')
    {
        out = lVal | rVal;
    }
    else if (this->op == '&')
    {
        out = lVal & rVal;
    }
    else if (this->op == '>>')
    {
        out = lVal >> rVal;
    }
    else if (this->op == '<<')
    {
        out = lVal << rVal;
    }
    else if (this->op == '||')
    {
        out = (unsigned)(lVal || rVal);
    }
    else if (this->op == '&&')
    {
        out = (unsigned)(lVal & rVal);
    }
    else if (this->op == '<')
    {
        out = (unsigned)(lVal < rVal);
    }
    else if (this->op == '>')
    {
        out = (unsigned)(lVal > rVal);
    }
    else if (this->op == '<=')
    {
        out = (unsigned)(lVal <= rVal);
    }
    else if (this->op == '>=')
    {
        out = (unsigned)(lVal >= rVal);
    }
    else if (this->op == '==')
    {
        out = (unsigned)(lVal == rVal);
    }
    else if (this->op == '!=')
    {
        out = (unsigned)(lVal != rVal);
    }
    else
    {
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalFloat(Compiler* compiler, float& out) const
{
    float lVal, rVal;
    this->left->EvalFloat(compiler, lVal);
    this->right->EvalFloat(compiler, rVal);

    if (this->op == '+')
    {
        out = lVal + rVal;
    }
    else if (this->op == '-')
    {
        out = lVal - rVal;
    }
    else if (this->op == '*')
    {
        out = lVal * rVal;
    }
    else if (this->op == '/')
    {
        out = lVal / rVal;
    }
    else
    {
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(Compiler* compiler, bool& out) const
{
    Type::FullType lhsType, rhsType;
    this->left->EvalType(compiler, lhsType);
    this->right->EvalType(compiler, rhsType);

    bool ret = true;
    if (lhsType.name == "int")
    {
        int lVal;
        ret &= this->left->EvalInt(compiler, lVal);
        if (rhsType.name == "float")
        {
            float rVal;
            ret &= this->right->EvalFloat(compiler, rVal);
            out = EvalBool(lVal, rVal, compiler);
        }
        else if (rhsType.name == "int")
        {
            int rVal;
            ret &= this->right->EvalInt(compiler, rVal);
            out = EvalBool(lVal, rVal, compiler);
        }
    }
    else if (lhsType.name == "float")
    {
        float lVal;
        ret &= this->left->EvalFloat(compiler, lVal);
        if (rhsType.name == "int")
        {
            int rVal;
            ret &= this->right->EvalInt(compiler, rVal);
            out = EvalBool(lVal, rVal, compiler);
        }
        else if (rhsType.name == "float")
        {
            float rVal;
            ret &= this->right->EvalFloat(compiler, rVal);
            out = EvalBool(lVal, rVal, compiler);
        }
    }
    else if (lhsType.name == "bool")
    {
        bool lVal;
        ret &= this->left->EvalBool(compiler, lVal);
        if (rhsType.name == "bool")
        {
            bool rVal;
            ret &= this->right->EvalBool(compiler, rVal);
            out = EvalBool(lVal, rVal, compiler);
        }
    }
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
BinaryExpression::EvalString(Compiler* compiler) const
{
    std::string left, right;
    left = this->left->EvalString(compiler);
    right = this->right->EvalString(compiler);
    return Format("%s %s %s", left.c_str(), FourCCToString(this->op).c_str(), right.c_str());
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(int lhs, int rhs, Compiler* compiler) const
{
    if (this->op == '<')
    {
        return lhs < rhs;
    }
    else if (this->op == '>')
    {
        return lhs > rhs;
    }
    else if (this->op == '<=')
    {
        return lhs <= rhs;
    }
    else if (this->op == '>=')
    {
        return lhs >= rhs;
    }
    else if (this->op == '==')
    {
        return lhs == rhs;
    }
    else if (this->op == '!=')
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between int and int", FourCCToString(this->op).c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(float lhs, int rhs, Compiler* compiler) const
{
    if (this->op == '<')
    {
        return lhs < rhs;
    }
    else if (this->op == '>')
    {
        return lhs > rhs;
    }
    else if (this->op == '<=')
    {
        return lhs <= rhs;
    }
    else if (this->op == '>=')
    {
        return lhs >= rhs;
    }
    else if (this->op == '==')
    {
        return lhs == rhs;
    }
    else if (this->op == '!=')
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between float and int", FourCCToString(this->op).c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(int lhs, float rhs, Compiler* compiler) const
{
    if (this->op == '<')
    {
        return lhs < rhs;
    }
    else if (this->op == '>')
    {
        return lhs > rhs;
    }
    else if (this->op == '<=')
    {
        return lhs <= rhs;
    }
    else if (this->op == '>=')
    {
        return lhs >= rhs;
    }
    else if (this->op == '==')
    {
        return lhs == rhs;
    }
    else if (this->op == '!=')
    {
        return lhs != rhs;
    }
    else if (this->op == '||')
    {
        return lhs || rhs;
    }
    else if (this->op == '&&')
    {
        return lhs && rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between int and float", FourCCToString(this->op).c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(float lhs, float rhs, Compiler* compiler) const
{
    if (this->op == '<')
    {
        return lhs < rhs;
    }
    else if (this->op == '>')
    {
        return lhs > rhs;
    }
    else if (this->op == '<=')
    {
        return lhs <= rhs;
    }
    else if (this->op == '>=')
    {
        return lhs >= rhs;
    }
    else if (this->op == '==')
    {
        return lhs == rhs;
    }
    else if (this->op == '!=')
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between float and float", FourCCToString(this->op).c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(bool lhs, bool rhs, Compiler* compiler) const
{
    if (this->op == '==')
    {
        return lhs == rhs;
    }
    else if (this->op == '!=')
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between bool and bool", FourCCToString(this->op).c_str());
        compiler->Error(msg, this);
        return false;
    }
}
} // namespace AnyFX