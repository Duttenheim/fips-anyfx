//------------------------------------------------------------------------------
//  varbuffer.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "varbuffer.h"
#include "parameter.h"
#include <algorithm>
#include "typechecker.h"
#include "shader.h"
#include "effect.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
VarBuffer::VarBuffer() :
    alignedSize(0),
    hasAnnotation(false),
    group(0),
    binding(-1),
    accessMode(NoAccess),
    arraySizeExpression(nullptr),
    arrayType(Variable::ArrayType::NoArray),
    arraySize(1)
{
    this->symbolType = Symbol::VarbufferType;
}

//------------------------------------------------------------------------------
/**
*/
VarBuffer::~VarBuffer()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
void
VarBuffer::AddVariable(const Variable& var)
{
    this->variables.push_back(var);
}

//------------------------------------------------------------------------------
/**
*/
void
VarBuffer::TypeCheck(TypeChecker& typechecker)
{
    // add varblock, if failed we must have a redefinition
    if (!typechecker.AddSymbol(this)) return;

    // type check annotation
    if (this->hasAnnotation)
    {
        this->annotation.TypeCheck(typechecker);
    }

    // evaluate qualifiers
    for (unsigned i = 0; i < this->qualifiers.size(); i++)
    {
        const std::string& qualifier = this->qualifiers[i];
        if (qualifier == "shared")                                      this->qualifierFlags |= Qualifiers::Shared;
        else if (qualifier == "read")                                   this->accessMode |= Access::Read;
        else if (qualifier == "readwrite" || qualifier == "read_write") this->accessMode |= Access::ReadWrite;
        else if (qualifier == "write")                                  this->accessMode |= Access::Write;
        else if (qualifier == "atomic")                                 this->accessMode |= Access::Atomic;
        else if (qualifier == "volatile")                               this->accessMode |= Access::Volatile;
        else
        {
            std::string message = AnyFX::Format("Unknown qualifier '%s', %s\n", qualifier.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
    }

    for (unsigned i = 0; i < this->qualifierExpressions.size(); i++)
    {
        const std::string& qualifier = this->qualifierExpressions[i].name;
        Expression* expr = this->qualifierExpressions[i].expr;
        if (qualifier == "group") this->group = expr->EvalUInt(typechecker);
        else if (qualifier == "binding") this->binding = expr->EvalUInt(typechecker);
        else
        {
            std::string message = AnyFX::Format("Unknown qualifier '%s', %s\n", qualifier.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
        delete expr;
    }

    // get the binding location and increment the global counter
    if (this->binding == -1)
    {
        if (typechecker.GetHeader().GetType() == Header::GLSL)
        {
            this->binding = Shader::bindingIndices[1]++;
        }
        else if (typechecker.GetHeader().GetType() == Header::SPIRV)
        {
            this->binding = Shader::bindingIndices[this->group]++;
        }
    }
    else
    {
        if (typechecker.GetHeader().GetType() == Header::GLSL)
        {
            Shader::bindingIndices[1] = std::max(this->binding + 1, Shader::bindingIndices[1]);
        }
        else if (typechecker.GetHeader().GetType() == Header::SPIRV)
        {
            Shader::bindingIndices[this->group] = std::max(this->binding + 1, Shader::bindingIndices[this->group]);
        }
    }

    if (this->arraySizeExpression != nullptr)
    {
        this->arraySize = this->arraySizeExpression->EvalUInt(typechecker);
        delete this->arraySizeExpression;
    }


    const Header& header = typechecker.GetHeader();
    if (header.GetType() != Header::GLSL && header.GetType() != Header::SPIRV)
    {
        std::string message = AnyFX::Format("Varbuffers are only supported in OpenGL, %s\n", this->ErrorSuffix().c_str());
        typechecker.Error(message, this->GetFile(), this->GetLine());
    }
    else
    {
        if ((header.GetMajor() < 4 && header.GetMinor() < 3) && header.GetType() != Header::SPIRV)
        {
            std::string message = AnyFX::Format("Varbuffers are only supported in OpenGL 4.3+, %s\n", this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
    }

    unsigned offset = 0;
    unsigned i;
    for (i = 0; i < this->variables.size(); i++)
    {
        Variable& var = this->variables[i];

        std::string internalName = var.name;
        if (!this->structName.empty())
            var.name = AnyFX::Format("%s.%s", this->structName.c_str(), var.name.c_str());

        if (var.GetArrayType() == Variable::UnsizedArray && i < this->variables.size() - 1)
        {
            std::string message = AnyFX::Format("Varbuffers can only have its last member as an unsized array, %s\n", var.GetName().c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }

        // if we have a struct, we need to unroll it, and calculate the offsets
        const DataType& type = var.GetDataType();

        // avoid adding actual struct
        if (type.GetType() == DataType::UserType)
        {
            // unroll structures to generate variables with proper names, they should come in the same order as the suboffsets
            Structure* structure = dynamic_cast<Structure*>(typechecker.GetSymbol(type.GetName()));
            if (structure->GetUsage() == Structure::VarblockStorage)
                typechecker.Error(AnyFX::Format("struct %s is used in a varblock, but is elsewhere used in a varbuffer", structure->GetName().c_str()), this->GetFile(), this->GetLine());
            structure->SetUsage(Structure::VarbufferStorage);
            structure->UpdateAlignmentAndSize(typechecker);
        }

        var.TypeCheck(typechecker);

        // handle offset later, now we know array size
        unsigned size = 0;
        unsigned alignment = 0;
        if (header.GetType() == Header::GLSL || header.GetType() == Header::SPIRV)
            Effect::GetAlignmentGLSL(var.GetDataType(), var.GetArraySize(), size, alignment, false, false, typechecker);

        // align offset with current alignment
        if (offset % alignment > 0)
        {
            var.padding = alignment - (offset % alignment);
            offset = offset + alignment - (offset % alignment);
        }
        else
            var.padding = 0;
        var.alignedOffset = offset;

        // avoid adding actual struct
        if (type.GetType() == DataType::UserType)
        {
            // unroll structures to generate variables with proper names, they should come in the same order as the suboffsets
            Structure* structure = dynamic_cast<Structure*>(typechecker.GetSymbol(type.GetName()));
            structure->ResolveOffsets(typechecker, this->offsetsByName);
        }
        else
        {
            // add offset to list
            this->offsetsByName[var.GetName()] = offset;
        }

        // offset should be size of struct, round of
        offset += size;
    }

    this->alignedSize = offset;
}

//------------------------------------------------------------------------------
/**
*/
std::string
VarBuffer::Format(const Header& header) const
{
    std::string formattedCode;

    // varbuffers of this type are only available in GLSL4+
    if (header.GetType() == Header::GLSL)
    {
        std::string layout = AnyFX::Format("layout(std430, binding=%d) %s buffer ", this->binding, this->FormatBufferAccess(header).c_str());
        formattedCode.append(layout);
    }
    else if (header.GetType() == Header::SPIRV)
    {
        std::string layout = AnyFX::Format("layout(std430, set=%d, binding=%d) %s buffer ", this->group, this->binding, this->FormatBufferAccess(header).c_str());
        formattedCode.append(layout);
    }
    else if (header.GetType() == Header::C)
    {
        formattedCode.append("struct ");
    }
    
    formattedCode.append(this->GetName());
    formattedCode.append("\n{\n");

    unsigned i;
    for (i = 0; i < this->variables.size(); i++)
    {
        const Variable& var = this->variables[i];

        // add padding member if we have a positive padding
        if (header.GetType() == Header::C && var.padding > 0)
        {
            int pads = var.padding / 4;
            int remainder = var.padding % 4;
            unsigned j;
            for (j = 0; j < pads; j++)
                formattedCode.append(AnyFX::Format("/* Padding */ unsigned int : %d;\n", 32));

            if (remainder > 0)
                formattedCode.append(AnyFX::Format("/* Padding */ unsigned int : %d;\n", remainder * 8));
            
        }

        // write variable offset, in most languages, every float4 boundary must be 16 bit aligned
        formattedCode.append(AnyFX::Format("/* Offset:%d */", var.alignedOffset));

        // format code and add to code
        formattedCode.append(var.Format(header, true));
    }
    
    // finalize and return
    if (this->structName.empty())
        formattedCode.append("};\n\n");
    else
    {
        std::string fullStructName = this->structName;
        if (this->arrayType == Variable::ArrayType::UnsizedArray)
            fullStructName.append("[]");
        else if (this->arrayType == Variable::ArrayType::SimpleArray)
            fullStructName.append(AnyFX::Format("[%d]", this->arraySize));
        formattedCode.append(AnyFX::Format("} %s;\n\n", fullStructName.c_str()));
    }
    return formattedCode;
}

//------------------------------------------------------------------------------
/**
*/
void
VarBuffer::Compile(BinWriter& writer)
{
    writer.WriteString(this->name);
    writer.WriteUInt(this->alignedSize);
    writer.WriteUInt(ToInteger(this->qualifierFlags));
    writer.WriteUInt(this->binding);
    writer.WriteUInt(this->group);

    // write if annotation is used
    writer.WriteBool(this->hasAnnotation);

    // compile annotation if
    if (this->hasAnnotation)
    {
        this->annotation.Compile(writer);
    }	

    // write offsets
    writer.WriteUInt(this->offsetsByName.size());
    std::map<std::string, unsigned>::const_iterator it = this->offsetsByName.begin();
    for (; it != this->offsetsByName.end(); it++)
    {
        writer.WriteString((*it).first);
        writer.WriteUInt((*it).second);
    }
}

//------------------------------------------------------------------------------
/**
    qsort hook for sorting parameters
*/
bool
VarbufferParamCompare(const Variable& v1, const Variable& v2)
{
    return v1.GetByteSize() * v1.GetArraySize() > v2.GetByteSize() * v1.GetArraySize();
}

//------------------------------------------------------------------------------
/**
    sort variables based on type size in decreasing order, meaning the first value has the biggest size
    (this only needs to be here because there seems to be some bug with uniform buffers (GLSL) on ATI cards)
    but it's always good practice to properly pack your data ;)
*/
void 
VarBuffer::SortVariables()
{
    std::sort(this->variables.begin(), this->variables.end(), VarbufferParamCompare);
}

//------------------------------------------------------------------------------
/**
*/
std::string
VarBuffer::FormatBufferAccess(const Header& header) const
{
    std::string accessQualifiers;
    if (header.GetType() == Header::GLSL || header.GetType() == Header::SPIRV)
    {
        if ((this->accessMode & Access::Read) == Access::Read)
            accessQualifiers.append("readonly ");
        if ((this->accessMode & Access::Write) == Access::Write)
            accessQualifiers.append("writeonly ");
        if ((this->accessMode & Access::ReadWrite) == Access::ReadWrite)
            accessQualifiers.append("restrict ");
        if ((this->accessMode & Access::Atomic) == Access::Atomic)
            accessQualifiers.append("coherent ");
        if ((this->accessMode & Access::Volatile) == Access::Volatile)
            accessQualifiers.append("volatile ");

        if (accessQualifiers.size() > 0)
            accessQualifiers.pop_back();
    }
    else
    {
        // IMPLEMENT ME
    }

    // fallthrough
    return accessQualifiers;
}
} // namespace AnyFX
