//------------------------------------------------------------------------------
//  typechecker.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "typechecker.h"
#include "util.h"
#include "symbol.h"

namespace AnyFX
{

TypeChecker* TypeChecker::instance = 0;
//------------------------------------------------------------------------------
/**
*/
TypeChecker::TypeChecker() :
	errorCount(0),
	warningCount(0)
{
	assert(0 == instance);
	instance = this;
}

//------------------------------------------------------------------------------
/**
*/
TypeChecker::~TypeChecker()
{
	assert(0 != instance);
	instance = 0;
}

//------------------------------------------------------------------------------
/**
*/
TypeChecker* 
TypeChecker::Instance()
{
	assert(0 != instance);
	return instance;
}

//------------------------------------------------------------------------------
/**
*/
bool
TypeChecker::AddSymbol(Symbol* symbol)
{
	if (this->symbols.find(symbol->GetName()) != this->symbols.end())
	{
		Symbol* origSymbol = this->symbols[symbol->GetName()];
		if (origSymbol->GetSignature() == symbol->GetSignature())
		{
			std::string err;
			if (origSymbol->IsReserved())										err = Format("Symbol '%s' is a reserved name and can not be used.", symbol->GetName().c_str());
			else																err = Format("Symbol '%s' redefinition at %d in %s. Previously defined near row %d in %s\n", symbol->GetName().c_str(), symbol->GetLine(), symbol->GetFile().c_str(), origSymbol->GetLine(), origSymbol->GetFile().c_str());
			this->Error(err, symbol->GetFile(), symbol->GetLine());
			return false;
		}        
		else
		{
			// register with signature instead, this however makes the symbol unable to be looked up
			this->symbols[symbol->GetSignature()] = symbol;
			return true;
		}
	}
	else
	{
		this->symbols[symbol->GetName()] = symbol;
		return true;
	}
}

//------------------------------------------------------------------------------
/**
*/
bool
TypeChecker::HasSymbol(const std::string& name)
{
	return this->symbols.find(name) != this->symbols.end();
}

//------------------------------------------------------------------------------
/**
*/
Symbol*
TypeChecker::GetSymbol(const std::string& name)
{
    auto it = this->symbols.find(name);
	if (it == this->symbols.end())
	{
		std::string err = Format("Symbol '%s' is not defined\n", name.c_str());
		this->errorBuffer += err;
		this->errorCount++;
		return nullptr;
	}
	else
	{
        return (*it).second;
	}
}

//------------------------------------------------------------------------------
/**
*/
void 
TypeChecker::ReplaceSymbol(Symbol* symbol)
{
    auto& it = this->symbols.find(symbol->GetName());
    if (it != this->symbols.end())
    {
        it->second = symbol;
    }
}

//------------------------------------------------------------------------------
/**
*/
void
TypeChecker::Error(const std::string& message, const std::string& file, const unsigned line)
{
	std::string filename = file.substr(1, file.length() - 2);
	std::string msg = Format("%s(%d) : error:%s\n", filename.c_str(), line, message.c_str());
	this->errorBuffer += msg;
	this->errorCount++;
}

//------------------------------------------------------------------------------
/**
*/
void
TypeChecker::Warning(const std::string& message, const std::string& file, const unsigned line)
{
	std::string filename = file.substr(1, file.length() - 2);
	std::string msg = Format("%s(%d) : warning:%s\n", filename.c_str(), line, message.c_str());
	this->errorBuffer += msg;
	this->warningCount++;
}

//------------------------------------------------------------------------------
/**
*/
void
TypeChecker::LinkError(const std::string& message, const std::string& file, const unsigned line)
{
	std::string filename = file.substr(1, file.length() - 2);
	std::string msg = Format("%s(%d) : error:%s\n", filename.c_str(), line, message.c_str());
	this->errorBuffer += msg;
	this->errorCount++;
}

//------------------------------------------------------------------------------
/**
*/
void
TypeChecker::LinkWarning(const std::string& message, const std::string& file, const unsigned line)
{
	std::string filename = file.substr(1, file.length() - 2);
	std::string msg = Format("%s(%d) : warning:%s\n", filename.c_str(), line, message.c_str());
	this->errorBuffer += msg;
	this->warningCount++;
}

//------------------------------------------------------------------------------
/**
*/
const TypeChecker::Status 
TypeChecker::GetStatus() const
{
	if (this->errorCount > 0)
	{
		return Failed;
	}
    else if (this->warningCount > 0)
    {
        return Warnings;
    }
    else
    {
        return Success;
    }
}

} // namespace AnyFX