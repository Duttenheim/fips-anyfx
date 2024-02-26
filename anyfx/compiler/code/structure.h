#pragma once
//------------------------------------------------------------------------------
/**
    @class Structure
    
    Implements user-defined types.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <string>
#include <vector>
#include "parameter.h"
#include "symbol.h"
#include "variable.h"
namespace AnyFX
{

class Structure : public Symbol
{
public:

	enum Usage
	{
		Ordinary,		 // struct is used as a container to be passed as parameters
		VarblockStorage, // struct is used in a varblock
		VarbufferStorage // struct is used in a varbuffer
	};
	/// constructor
	Structure();
	/// destructor
	virtual ~Structure();

	/// adds a parameter
	void AddParameter(const Parameter& param);
	/// gets parameters
	const std::vector<Parameter>& GetParameters() const;

    /// calculates the bit size of struct
    unsigned CalculateSize() const;

	/// format structure to fit target language
	std::string Format(const Header& header) const;

	/// resolve parameter offsets recursively
	void ResolveOffsets(TypeChecker& typechecker, std::map<std::string, unsigned>& offsets);
	/// update alignment and size, which happens when called from a varblock or varbuffer
	void UpdateAlignmentAndSize(TypeChecker& typechecker);
	/// set the usage
	void SetUsage(const Usage usage);
	/// get the usage
	const Usage GetUsage() const;
    /// Get pointer usage
    const bool IsPointer() const { return this->isPointer; }

	/// type checks structure
	void TypeCheck(TypeChecker& typechecker);

private:
	friend class Effect;
    friend class Parameter;
    friend class Variable;

    /// check if structure contains type
    bool IsRecursive(TypeChecker& typeChecker);

	std::vector<Parameter> parameters;
	unsigned alignedSize;
	unsigned alignment;
	unsigned padding;
	Usage usage;

    bool isPointer;
    unsigned pointerAlignment;
}; 


//------------------------------------------------------------------------------
/**
*/
inline void
Structure::SetUsage(const Structure::Usage usage)
{
	this->usage = usage;
}

//------------------------------------------------------------------------------
/**
*/
inline const Structure::Usage
Structure::GetUsage() const
{
	return this->usage;
}


} // namespace AnyFX

//------------------------------------------------------------------------------
