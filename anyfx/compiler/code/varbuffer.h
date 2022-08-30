#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::VarBuffer
    
    A VarBuffer denotes an object which acts like a buffered struct. 
    This type of object is bound to the rendering pipeline through a buffer.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <string>
#include <vector>
#include "variable.h"
#include "symbol.h"
#include "annotation.h"
namespace AnyFX
{
class VarBuffer : public Symbol
{
public:
    /// constructor
    VarBuffer();
    /// destructor
    virtual ~VarBuffer();

    /// set annotation
    void SetAnnotation(const Annotation& annotation);

    /// add variable
    void AddVariable(const Variable& var);
    /// get variables
    const std::vector<Variable>& GetVariables() const;

    /// set the array size expression
    void SetArrayExpression(Expression* expression);

    /// set the name of the struct variable
    void SetStructName(const std::string& name);

    /// get if varblock is shared
    bool IsShared() const;

    /// sorts variables in varblock
    void SortVariables();

    /// type checks var block
    void TypeCheck(TypeChecker& typechecker);
    /// compiles var block
    void Compile(BinWriter& writer);

    /// get binding
    const Variable::Binding GetBinding() const;

    /// format variable to fit target language
    std::string Format(const Header& header) const;

private:

    /// converts access pattern to string based on header
    std::string FormatBufferAccess(const Header& header) const;
    friend class Effect;
    std::vector<Variable> variables;
    std::map<std::string, unsigned> offsetsByName;

    Variable::ArrayType arrayType;
    Expression* arraySizeExpression;
    unsigned arraySize;
    std::string structName;

    unsigned alignedSize;

    unsigned group;
    unsigned binding;
    
    bool hasAnnotation;
    Annotation annotation;

    unsigned accessMode;
}; 

//------------------------------------------------------------------------------
/**
*/
inline void
VarBuffer::SetAnnotation(const Annotation& annotation)
{
    this->annotation = annotation;
    this->hasAnnotation = true;
}

//------------------------------------------------------------------------------
/**
*/
inline bool 
VarBuffer::IsShared() const
{
    return HasFlags(this->qualifierFlags, Qualifiers::Shared);
}

//------------------------------------------------------------------------------
/**
*/
inline const std::vector<Variable>& 
VarBuffer::GetVariables() const
{
    return this->variables;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
VarBuffer::SetArrayExpression(Expression* expression)
{
    // if the expression is null but the SetArrayExpression is triggered, treat it as an unsized array
    if (expression == nullptr)
        this->arrayType = Variable::ArrayType::UnsizedArray;
    else
        this->arrayType = Variable::ArrayType::SimpleArray;
    this->arraySizeExpression = expression;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
VarBuffer::SetStructName(const std::string& name)
{
    this->structName = name;
}

} // namespace AnyFX
//------------------------------------------------------------------------------
