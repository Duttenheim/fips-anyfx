#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::Symbol
    
    Basic object representation, contains basic information for an AnyFX symbol.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "compileable.h"

#include <string>
namespace AnyFX
{
class Symbol : public Compileable
{
public:

    enum Type
    {
        ProgramType,
        RenderStateType,
        SamplerType,
        VariableType,
        VarblockType,
        VarbufferType,
        SubroutineType,
        FunctionType,
        ConstantType,
        StructureType,

        NumSymbolTypes
    };

    /// constructor
    Symbol();
    /// destructor
    virtual ~Symbol();

    /// set name of program
    void SetName(const std::string& name);
    /// gets name of program
    const std::string& GetName() const;
    /// set if symbol is a reserved (by the compiler)
    void SetReserved(bool b);
    /// get if symbol is reserved
    const bool IsReserved() const;

    /// returns type of symbol
    const Type& GetType() const;
    /// get signature of symbol
    const std::string& GetSignature() const;

        /// add qualifier to varblock
    void AddQualifier(const std::string& qualifier);
    /// get number of qualifiers
    const size_t GetNumQualifiers() const;
    /// get qualifier by index
    const std::string& GetQualifier(unsigned i) const;

    /// add expression qualifier to varblock
    void AddQualifierExpression(const QualifierExpression& qualifier);
    /// get number of expression qualifiers
    const size_t GetNumQualifierExpressions() const;
    /// get name of expression qualifier
    const QualifierExpression& GetQualifierExpression(unsigned i) const;

protected:

    bool reserved;
    std::string name;
    std::string signature;
    Type symbolType;

    Qualifiers qualifierFlags;
    std::vector<std::string> qualifiers;
    std::vector<QualifierExpression> qualifierExpressions;
}; 

//------------------------------------------------------------------------------
/**
*/
inline void
Symbol::SetName(const std::string& name)
{
    this->name = name;
}

//------------------------------------------------------------------------------
/**
*/
inline const std::string& 
Symbol::GetName() const
{
    return this->name;
}

//------------------------------------------------------------------------------
/**
*/
inline void
Symbol::SetReserved(bool b)
{
    this->reserved = b;
    this->file = "<intrinsic>";
    this->line = 0;    
}

//------------------------------------------------------------------------------
/**
*/
inline const bool
Symbol::IsReserved() const
{
    return this->reserved;
}

//------------------------------------------------------------------------------
/**
*/
inline const Symbol::Type& 
Symbol::GetType() const
{
    return this->symbolType;
}

//------------------------------------------------------------------------------
/**
*/
inline const std::string&
Symbol::GetSignature() const
{
    return this->signature;
}

//------------------------------------------------------------------------------
/**
*/
inline void
Symbol::AddQualifier(const std::string& qualifier)
{
    this->qualifiers.push_back(qualifier);
}

//------------------------------------------------------------------------------
/**
*/
inline const size_t
Symbol::GetNumQualifiers() const
{
    return this->qualifiers.size();
}

//------------------------------------------------------------------------------
/**
*/
inline const std::string&
Symbol::GetQualifier(unsigned i) const
{
    return this->qualifiers[i];
}

//------------------------------------------------------------------------------
/**
*/
inline void
Symbol::AddQualifierExpression(const QualifierExpression& qualifier)
{
    this->qualifierExpressions.push_back(qualifier);
}

//------------------------------------------------------------------------------
/**
*/
inline const size_t
Symbol::GetNumQualifierExpressions() const
{
    return this->qualifierExpressions.size();
}

//------------------------------------------------------------------------------
/**
*/
inline const QualifierExpression&
Symbol::GetQualifierExpression(unsigned i) const
{
    return this->qualifierExpressions[i];
}


} // namespace AnyFX
//------------------------------------------------------------------------------