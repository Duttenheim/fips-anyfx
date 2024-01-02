//------------------------------------------------------------------------------
//  structure.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "structure.h"
#include "typechecker.h"
#include "effect.h"
#include <algorithm>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Structure::Structure() :
	alignedSize(0),
	padding(0),
	usage(Ordinary)
{
	this->symbolType = Symbol::StructureType;
}

//------------------------------------------------------------------------------
/**
*/
Structure::~Structure()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void
Structure::AddParameter(const Parameter& param)
{
	this->parameters.push_back(param);
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<Parameter>& 
Structure::GetParameters() const
{
	return this->parameters;
}

//------------------------------------------------------------------------------
/**
*/
unsigned 
Structure::CalculateSize() const
{
    unsigned sum = 0;

    unsigned i;
    for (i = 0; i < this->parameters.size(); i++)
    {
        const Parameter& param = this->parameters[i];
        sum += DataType::ToByteSize(param.GetDataType());
    }
    return sum;
}

//------------------------------------------------------------------------------
/**
*/
bool
Structure::IsRecursive(TypeChecker& typeChecker)
{
    unsigned i;
    for (i = 0; i < this->parameters.size(); i++)
    {
        const Parameter& param = this->parameters[i];
        if (param.GetDataType().GetType() == DataType::UserType)
        {
            Symbol* sym = typeChecker.GetSymbol(param.GetDataType().GetName());
            if (this == sym)
            {
                return true;
            }
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string
Structure::Format(const Header& header) const
{
	std::string formattedCode;

	formattedCode.append("struct ");	
    if (header.GetType() == Header::C)
        formattedCode.append("alignas(16) ");

	formattedCode.append(this->GetName());
	formattedCode.append("\n{\n");

	unsigned input, output;
	input = output = 0;
	unsigned i;
	for (i = 0; i < this->parameters.size(); i++)
	{
		const Parameter& param = this->parameters[i];

		// add padding member if we have a positive padding
		if (header.GetType() == Header::C && param.padding > 0)
		{
			int pads = param.padding / 4;
			int remainder = param.padding % 4;
			unsigned j;
			for (j = 0; j < pads; j++)
				formattedCode.append(AnyFX::Format("/* Padding */ unsigned int : %d;\n", 32));

			if (remainder > 0)
				formattedCode.append(AnyFX::Format("/* Padding */ unsigned int : %d;\n", remainder * 8));
		}

		// write variable offset, in most languages, every float4 boundary must be 16 bit aligned
		formattedCode.append(AnyFX::Format("/* Offset:%d */", param.alignedOffset));

		// generate parameter with a seemingly invalid shader, since 
		formattedCode.append(param.Format(header, input, output));
	}

	if (header.GetType() == Header::C && this->padding > 0)
	{
		int pads = this->padding / 4;
		int remainder = this->padding % 4;
		for (i = 0; i < pads; i++)
			formattedCode.append(AnyFX::Format("/* Structure Padding */ unsigned int : %d;\n", 32));

		if (remainder > 0)
			formattedCode.append(AnyFX::Format("/* Structure Padding */ unsigned int : %d;\n", remainder * 8));
	}
		

	formattedCode.append("};\n\n");
	return formattedCode;
}

//------------------------------------------------------------------------------
/**
*/
void 
Structure::ResolveOffsets(TypeChecker& typechecker, std::map<std::string, unsigned>& offsets)
{
	unsigned i;
	for (i = 0; i < this->parameters.size(); i++)
	{
		const Parameter& param = this->parameters[i];

		// if we have a struct in struct, unroll inner struct (recursively)
		const DataType& type = param.GetDataType();

		// unroll if struct
		if (type.GetType() == DataType::UserType)
		{
			Structure* str = dynamic_cast<Structure*>(typechecker.GetSymbol(type.GetName()));
			if (str)
				str->ResolveOffsets(typechecker, offsets);
		}
		else
		{
			offsets[param.name] = param.alignedOffset;
		}
	}
}

//------------------------------------------------------------------------------
/**
*/
void 
Structure::UpdateAlignmentAndSize(TypeChecker& typechecker)
{
	const Header& header = typechecker.GetHeader();

	unsigned offset = 0;
	unsigned i;
	unsigned maxAlignment = this->usage == VarblockStorage ? 16 : 0;
	for (i = 0; i < this->parameters.size(); i++)
	{
		Parameter& param = this->parameters[i];

		// handle offset later, now we know array size
		unsigned size = 0;
		unsigned alignment = 0;
		if (header.GetType() == Header::GLSL || header.GetType() == Header::SPIRV)
		{
			Effect::GetAlignmentGLSL(param.GetDataType(), param.GetArraySize(), size, alignment, this->usage != VarbufferStorage, true, typechecker);
		}

		maxAlignment = std::max(alignment, maxAlignment);
		//size = Effect::RoundToPow2(size, alignment);
		
		// align offset with current alignment
		if (offset % alignment > 0)
		{
			param.padding = alignment - (offset % alignment);
			offset = offset + alignment - (offset % alignment);
		}
		else
			param.padding = 0;
		param.alignedOffset = offset;

		offset += size;
	}
	this->alignedSize = offset;
	this->alignment = maxAlignment;

	// calculate structure alignment
	if (this->alignedSize % maxAlignment > 0)
	{
		this->padding = maxAlignment - (this->alignedSize % maxAlignment);
		this->alignedSize = this->alignedSize + maxAlignment - (this->alignedSize % maxAlignment);
	}
	else
		this->padding = 0;
}

//------------------------------------------------------------------------------
/**
*/
void
Structure::TypeCheck(TypeChecker& typechecker)
{
	// attempt to add structure, if this fails, we must stop type checking for this structure
	if (!typechecker.AddSymbol(this)) return;

    // also make sure no two structures are recursively included within eachother
    if (this->IsRecursive(typechecker))
    {
        std::string msg = AnyFX::Format("Recursive inclusion of structures detected, %s\n", this->ErrorSuffix().c_str());
        typechecker.Error(msg, this->GetFile(), this->GetLine());
    }

	this->alignedSize = 0;
	unsigned i;
	for (i = 0; i < this->parameters.size(); i++)
	{
		Parameter& param = this->parameters[i];
		param.TypeCheck(typechecker);

		this->alignedSize += DataType::ToByteSize(param.GetDataType());
	}
}

} // namespace AnyFX
