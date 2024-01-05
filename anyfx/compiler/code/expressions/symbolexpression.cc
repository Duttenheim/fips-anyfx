//------------------------------------------------------------------------------
//  symbolexpression.cc
//  (C) 2020 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "symbolexpression.h"
#include "symbol.h"
#include "variable.h"
#include "util.h"
#include <string>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
SymbolExpression::SymbolExpression(const std::string symbol)
	: symbol(symbol)
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
SymbolExpression::~SymbolExpression()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
AnyFX::DataType
SymbolExpression::EvalType(TypeChecker& typechecker)
{
	DataType type;
	Symbol* symbol = typechecker.GetSymbol(this->symbol);
	if (symbol)
	{
		switch (symbol->GetType())
		{
		case Symbol::VariableType:
		{
            Variable* constant = static_cast<Variable*>(symbol);
			type = constant->GetDataType();
			break;
		}
		}
	}
	return type;
}

//------------------------------------------------------------------------------
/**
*/
int
SymbolExpression::EvalInt(TypeChecker& typechecker)
{
	Symbol* symbol = typechecker.GetSymbol(this->symbol);
	if (symbol)
	{
		switch (symbol->GetType())
		{
		case Symbol::VariableType:
		{
			Variable* constant = static_cast<Variable*>(symbol);
            if (!constant->IsConst())
            {
                std::string msg = AnyFX::Format("Symbol '%s' must be a constant", constant->GetName().c_str());
                typechecker.Error(msg, this->GetFile(), this->GetLine());
            }

			unsigned numValues = constant->GetNumValues();
			if (numValues > 1)
			{
				std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", constant->GetName().c_str());
				typechecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				return std::stoi(constant->GetValue(0).GetString().c_str());
			}
			break;
		}
		default:
			std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->GetName().c_str());
			typechecker.Error(msg, this->GetFile(), this->GetLine());
			break;
		}
	}
	return -1;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
SymbolExpression::EvalUInt(TypeChecker& typechecker)
{
	Symbol* symbol = typechecker.GetSymbol(this->symbol);
	if (symbol)
	{
		switch (symbol->GetType())
		{
		case Symbol::VariableType:
		{
            Variable* constant = static_cast<Variable*>(symbol);
            if (!constant->IsConst())
            {
                std::string msg = AnyFX::Format("Symbol '%s' must be a constant", constant->GetName().c_str());
                typechecker.Error(msg, this->GetFile(), this->GetLine());
            }

			unsigned numValues = constant->GetNumValues();
			if (numValues > 1)
			{
				std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", constant->GetName().c_str());
				typechecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				return std::stoul(constant->GetValue(0).GetString().c_str());
			}
			break;
		}
		default:
			std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->GetName().c_str());
			typechecker.Error(msg, this->GetFile(), this->GetLine());
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------------------------
/**
*/
float
SymbolExpression::EvalFloat(TypeChecker& typechecker)
{
	Symbol* symbol = typechecker.GetSymbol(this->symbol);
	if (symbol)
	{
		switch (symbol->GetType())
		{
		case Symbol::VariableType:
		{
            Variable* constant = static_cast<Variable*>(symbol);
            if (!constant->IsConst())
            {
                std::string msg = AnyFX::Format("Symbol '%s' must be a constant", constant->GetName().c_str());
                typechecker.Error(msg, this->GetFile(), this->GetLine());
            }

			unsigned numValues = constant->GetNumValues();
			if (numValues > 1)
			{
				std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", constant->GetName().c_str());
				typechecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				return std::stof(constant->GetValue(0).GetString().c_str());
			}
			break;
		}
		default:
			std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->GetName().c_str());
			typechecker.Error(msg, this->GetFile(), this->GetLine());
			break;
		}
	}
	return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
bool
SymbolExpression::EvalBool(TypeChecker& typechecker)
{
	Symbol* symbol = typechecker.GetSymbol(this->symbol);
	if (symbol)
	{
		switch (symbol->GetType())
		{
		case Symbol::VariableType:
		{
            Variable* constant = static_cast<Variable*>(symbol);
            if (!constant->IsConst())
            {
                std::string msg = AnyFX::Format("Symbol '%s' must be a constant", constant->GetName().c_str());
                typechecker.Error(msg, this->GetFile(), this->GetLine());
            }

			unsigned numValues = constant->GetNumValues();
			if (numValues > 1)
			{
				std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", constant->GetName().c_str());
				typechecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				return std::stoi(constant->GetValue(0).GetString().c_str());
			}
			break;
		}
		default:
			std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->GetName().c_str());
			typechecker.Error(msg, this->GetFile(), this->GetLine());
			break;
		}
	}
	return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
SymbolExpression::EvalString(TypeChecker& typechecker)
{
	return this->symbol;
}

} // namespace AnyFX