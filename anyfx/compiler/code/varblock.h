#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::VarBlock
    
    A variable block describes an updatable set of variables.
    
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
class VarBlock : public Symbol
{
public:

    /// constructor
    VarBlock();
    /// destructor
    virtual ~VarBlock();

    /// Destroy
    void Destroy() override;

    /// set annotation
    void SetAnnotation(const Annotation& annotation);

    /// add variable
    void AddVariable(Variable* var);
    
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

    friend class Effect;
    std::vector<Variable*> variables;
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
}; 

//------------------------------------------------------------------------------
/**
*/
inline void
VarBlock::SetAnnotation(const Annotation& annotation)
{
    this->annotation = annotation;
    this->hasAnnotation = true;
}

//------------------------------------------------------------------------------
/**
*/
inline bool 
VarBlock::IsShared() const
{
    return HasFlags(this->qualifierFlags, Qualifiers::Shared);
}

//------------------------------------------------------------------------------
/**
*/
inline void 
VarBlock::SetArrayExpression(Expression* expression)
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
VarBlock::SetStructName(const std::string& name)
{
    this->structName = name;
}

} // namespace AnyFX
//------------------------------------------------------------------------------
