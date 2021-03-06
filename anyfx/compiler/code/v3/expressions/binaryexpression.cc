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
BinaryExpression::BinaryExpression(const std::string& op, Expression* left, Expression* right) :
    op(op),
    left(left),
    right(right)
{
    // empty
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
BinaryExpression::EvalSymbol(Compiler* compiler)
{
    Symbol* lhs = this->left->EvalSymbol(compiler);
    Symbol* rhs = this->right->EvalSymbol(compiler);

    if (lhs == rhs)
    {	
        return lhs;
    }
    else if (lhs->symbolType == IntType)
    {
        if (rhs->symbolType == FloatType)
        {
            return rhs;
        }
    }
    else if (lhs->symbolType == FloatType)
    {
        if (rhs->symbolType == IntType)
        {
            return lhs;
        }
    }

    std::string msg = Format("Type '%s' cannot use binary operator '%s' with type '%s'", lhs->TypeToString().c_str(), this->op.c_str(), rhs->TypeToString().c_str());
    compiler->Error(msg, this);
    return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
int 
BinaryExpression::EvalInt(Compiler* compiler)
{
    int lVal = this->left->EvalInt(compiler);
    int rVal = this->right->EvalInt(compiler);

    if (this->op == "+")
    {
        return lVal + rVal;
    }
    else if (this->op == "-")
    {
        return lVal - rVal;
    }
    else if (this->op == "*")
    {
        return lVal * rVal;
    }
    else if (this->op == "/")
    {
        return lVal / rVal;
    }
    else if (this->op == "<")
    {
        return (int)(lVal < rVal);
    }
    else if (this->op == ">")
    {
        return (int)(lVal > rVal);
    }
    else if (this->op == "<=")
    {
        return (int)(lVal <= rVal);
    }
    else if (this->op == ">=")
    {
        return (int)(lVal >= rVal);
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' with int", this->op.c_str());
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
unsigned
BinaryExpression::EvalUInt(Compiler* compiler)
{
    unsigned lVal = this->left->EvalUInt(compiler);
    unsigned rVal = this->right->EvalUInt(compiler);

    if (this->op == "+")
    {
        return lVal + rVal;
    }
    else if (this->op == "-")
    {
        return lVal - rVal;
    }
    else if (this->op == "*")
    {
        return lVal * rVal;
    }
    else if (this->op == "/")
    {
        return lVal / rVal;
    }
    else if (this->op == "<")
    {
        return (unsigned)(lVal < rVal);
    }
    else if (this->op == ">")
    {
        return (unsigned)(lVal > rVal);
    }
    else if (this->op == "<=")
    {
        return (unsigned)(lVal <= rVal);
    }
    else if (this->op == ">=")
    {
        return (unsigned)(lVal >= rVal);
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' with int, %s\n", this->op.c_str(), this->GetLocation().c_str());
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
float 
BinaryExpression::EvalFloat(Compiler* compiler)
{
    float lVal = this->left->EvalFloat(compiler);
    float rVal = this->right->EvalFloat(compiler);

    if (this->op == "+")
    {
        return lVal + rVal;
    }
    else if (this->op == "-")
    {
        return lVal - rVal;
    }
    else if (this->op == "*")
    {
        return lVal * rVal;
    }
    else if (this->op == "/")
    {
        return lVal / rVal;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' with float, %s\n", this->op.c_str(), this->GetLocation().c_str());
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(Compiler* compiler)
{
    Symbol* lhs = this->left->EvalSymbol(compiler);
    Symbol* rhs = this->right->EvalSymbol(compiler);

    if (lhs->symbolType == IntType)
    {
        int lVal = this->left->EvalInt(compiler);
        if (rhs->symbolType == FloatType)
        {
            float rVal = this->right->EvalFloat(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else if (rhs->symbolType == IntType)
        {
            int rVal = this->right->EvalInt(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else goto error;
    }
    else if (lhs->symbolType == FloatType)
    {
        float lVal = this->left->EvalFloat(compiler);
        if (rhs->symbolType == IntType)
        {
            float rVal = this->right->EvalInt(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else if (rhs->symbolType == FloatType)
        {
            float rVal = this->right->EvalInt(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else goto error;
    }
    else if (lhs->symbolType == BoolType)
    {
        bool lVal = this->left->EvalBool(compiler);
        if (rhs->symbolType == BoolType)
        {
            bool rVal = this->right->EvalBool(compiler);
            return EvalBool(lVal, rVal, compiler);
        }
        else goto error;
    }

    else goto error;

error:
    std::string msg = Format("Type '%s' cannot use binary operator '%s' with type '%s'", lhs->TypeToString().c_str(), this->op.c_str(), rhs->TypeToString().c_str());
    compiler->Error(msg, this);
    return false;

}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(int lhs, int rhs, Compiler* compiler)
{
    if (this->op == "<")
    {
        return lhs < rhs;
    }
    else if (this->op == ">")
    {
        return lhs > rhs;
    }
    else if (this->op == "<=")
    {
        return lhs <= rhs;
    }
    else if (this->op == ">=")
    {
        return lhs >= rhs;
    }
    else if (this->op == "==")
    {
        return lhs == rhs;
    }
    else if (this->op == "!=")
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between int and int", this->op.c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(float lhs, int rhs, Compiler* compiler)
{
    if (this->op == "<")
    {
        return lhs < rhs;
    }
    else if (this->op == ">")
    {
        return lhs > rhs;
    }
    else if (this->op == "<=")
    {
        return lhs <= rhs;
    }
    else if (this->op == ">=")
    {
        return lhs >= rhs;
    }
    else if (this->op == "==")
    {
        return lhs == rhs;
    }
    else if (this->op == "!=")
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between float and int", this->op.c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(int lhs, float rhs, Compiler* compiler)
{
    if (this->op == "<")
    {
        return lhs < rhs;
    }
    else if (this->op == ">")
    {
        return lhs > rhs;
    }
    else if (this->op == "<=")
    {
        return lhs <= rhs;
    }
    else if (this->op == ">=")
    {
        return lhs >= rhs;
    }
    else if (this->op == "==")
    {
        return lhs == rhs;
    }
    else if (this->op == "!=")
    {
        return lhs != rhs;
    }
    else if (this->op == "||")
    {
        return lhs || rhs;
    }
    else if (this->op == "&&")
    {
        return lhs && rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between int and float", this->op.c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(float lhs, float rhs, Compiler* compiler)
{
    if (this->op == "<")
    {
        return lhs < rhs;
    }
    else if (this->op == ">")
    {
        return lhs > rhs;
    }
    else if (this->op == "<=")
    {
        return lhs <= rhs;
    }
    else if (this->op == ">=")
    {
        return lhs >= rhs;
    }
    else if (this->op == "==")
    {
        return lhs == rhs;
    }
    else if (this->op == "!=")
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between float and float", this->op.c_str());
        compiler->Error(msg, this);
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
BinaryExpression::EvalBool(bool lhs, bool rhs, Compiler* compiler)
{
    if (this->op == "==")
    {
        return lhs == rhs;
    }
    else if (this->op == "!=")
    {
        return lhs != rhs;
    }
    else
    {
        std::string msg = Format("Invalid operator '%s' between bool and bool", this->op.c_str());
        compiler->Error(msg, this);
        return false;
    }
}
} // namespace AnyFX