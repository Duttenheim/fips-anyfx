//------------------------------------------------------------------------------
//  binaryexpression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "binaryexpression.h"
#include "compiler.h"
#include "util.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
BinaryExpression::BinaryExpression(uint32_t op, Expression* left, Expression* right) :
    op(op),
    left(left),
    right(right)
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
Symbol*
BinaryExpression::EvalSymbol(Compiler* compiler) const
{
    Symbol* lhs = this->left->EvalSymbol(compiler);
    Symbol* rhs = this->right->EvalSymbol(compiler);

    if (lhs == rhs)
    {	
        return lhs;
    }
    else if (lhs->symbolType == IntExpressionType)
    {
        if (rhs->symbolType == FloatExpressionType)
        {
            return rhs;
        }
    }
    else if (lhs->symbolType == FloatExpressionType)
    {
        if (rhs->symbolType == IntExpressionType)
        {
            return lhs;
        }
    }

    std::string msg = Format("Type '%s' cannot use binary operator '%s' with type '%s'", lhs->TypeToString().c_str(), FourCCToString(this->op).c_str(), rhs->TypeToString().c_str());
    compiler->Error(msg, this);
    return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
int 
BinaryExpression::EvalInt(Compiler* compiler) const
{
    int lVal = this->left->EvalInt(compiler);
    int rVal = this->right->EvalInt(compiler);

    if (this->op == '+')
    {
        return lVal + rVal;
    }
    else if (this->op == '-')
    {
        return lVal - rVal;
    }
    else if (this->op == '*')
    {
        return lVal * rVal;
    }
    else if (this->op == '/')
    {
        return lVal / rVal;
    }
    else if (this->op == '%')
    {
        return lVal % rVal;
    }
    else if (this->op == '^')
    {
        return lVal ^ rVal;
    }
    else if (this->op == '|')
    {
        return lVal | rVal;
    }
    else if (this->op == '&')
    {
        return lVal & rVal;
    }
    else if (this->op == '>>')
    {
        return lVal >> rVal;
    }
    else if (this->op == '<<')
    {
        return lVal << rVal;
    }
    else if (this->op == '||')
    {
        return (int)(lVal || rVal);
    }
    else if (this->op == '&&')
    {
        return (int)(lVal & rVal);
    }
    else if (this->op == '<')
    {
        return (int)(lVal < rVal);
    }
    else if (this->op == '>')
    {
        return (int)(lVal > rVal);
    }
    else if (this->op == '<=')
    {
        return (int)(lVal <= rVal);
    }
    else if (this->op == '>=')
    {
        return (int)(lVal >= rVal);
    }
    else if (this->op == '==')
    {
        return (int)(lVal == rVal);
    }
    else if (this->op == '!=')
    {
        return (int)(lVal != rVal);
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' with int", FourCCToString(this->op).c_str());
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
unsigned
BinaryExpression::EvalUInt(Compiler* compiler) const
{
    unsigned lVal = this->left->EvalUInt(compiler);
    unsigned rVal = this->right->EvalUInt(compiler);

    if (this->op == '+')
    {
        return lVal + rVal;
    }
    else if (this->op == '-')
    {
        return lVal - rVal;
    }
    else if (this->op == '*')
    {
        return lVal * rVal;
    }
    else if (this->op == '/')
    {
        return lVal / rVal;
    }
    else if (this->op == '%')
    {
        return lVal % rVal;
    }
    else if (this->op == '^')
    {
        return lVal ^ rVal;
    }
    else if (this->op == '|')
    {
        return lVal | rVal;
    }
    else if (this->op == '&')
    {
        return lVal & rVal;
    }
    else if (this->op == '>>')
    {
        return lVal >> rVal;
    }
    else if (this->op == '<<')
    {
        return lVal << rVal;
    }
    else if (this->op == '||')
    {
        return (unsigned)(lVal || rVal);
    }
    else if (this->op == '&&')
    {
        return (unsigned)(lVal & rVal);
    }
    else if (this->op == '<')
    {
        return (unsigned)(lVal < rVal);
    }
    else if (this->op == '>')
    {
        return (unsigned)(lVal > rVal);
    }
    else if (this->op == '<=')
    {
        return (unsigned)(lVal <= rVal);
    }
    else if (this->op == '>=')
    {
        return (unsigned)(lVal >= rVal);
    }
    else if (this->op == '==')
    {
        return (unsigned)(lVal == rVal);
    }
    else if (this->op == '!=')
    {
        return (unsigned)(lVal != rVal);
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' with int, %s\n", FourCCToString(this->op).c_str(), this->GetLocation().c_str());
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
float 
BinaryExpression::EvalFloat(Compiler* compiler) const
{
    float lVal = this->left->EvalFloat(compiler);
    float rVal = this->right->EvalFloat(compiler);

    if (this->op == '+')
    {
        return lVal + rVal;
    }
    else if (this->op == '-')
    {
        return lVal - rVal;
    }
    else if (this->op == '*')
    {
        return lVal * rVal;
    }
    else if (this->op == '/')
    {
        return lVal / rVal;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' with float, %s\n", FourCCToString(this->op).c_str(), this->GetLocation().c_str());
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(Compiler* compiler) const
{
    Symbol* lhs = this->left->EvalSymbol(compiler);
    Symbol* rhs = this->right->EvalSymbol(compiler);

    if (lhs->symbolType == IntExpressionType)
    {
        int lVal = this->left->EvalInt(compiler);
        if (rhs->symbolType == FloatExpressionType)
        {
            float rVal = this->right->EvalFloat(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else if (rhs->symbolType == IntExpressionType)
        {
            int rVal = this->right->EvalInt(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else goto error;
    }
    else if (lhs->symbolType == FloatExpressionType)
    {
        float lVal = this->left->EvalFloat(compiler);
        if (rhs->symbolType == IntExpressionType)
        {
            float rVal = this->right->EvalInt(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else if (rhs->symbolType == FloatExpressionType)
        {
            float rVal = this->right->EvalInt(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else goto error;
    }
    else if (lhs->symbolType == BoolExpressionType)
    {
        bool lVal = this->left->EvalBool(compiler);
        if (rhs->symbolType == BoolExpressionType)
        {
            bool rVal = this->right->EvalBool(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else goto error;
    }

    else goto error;

error:
    std::string msg = Format("Type '%s' cannot use binary operator '%s' with type '%s'", lhs->TypeToString().c_str(), FourCCToString(this->op).c_str(), rhs->TypeToString().c_str());
    compiler->Error(msg, this);
    return false;

}

//------------------------------------------------------------------------------
/**
*/
std::string 
BinaryExpression::EvalString(Compiler* compiler) const
{
    return Format("%s %s %s", this->left->EvalString(compiler).c_str(), FourCCToString(this->op).c_str(), this->right->EvalString(compiler).c_str());
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