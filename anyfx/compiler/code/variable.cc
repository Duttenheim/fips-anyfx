//------------------------------------------------------------------------------
//  variable.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "variable.h"
#include "typechecker.h"
#include "util.h"
#include "shader.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Variable::Variable() :
    hasDefaultValue(false),
    isSubroutine(false),
    arrayType(NoArray),
    arraySize(1),
    format(NoFormat),
    accessMode(Access::NoAccess),
    qualifierFlags(NoQualifiers),
    isUniform(true),
    hasAnnotation(false),
    group(0),
    binding(-1),
    index(0)
{
    this->symbolType = Symbol::VariableType;
}

//------------------------------------------------------------------------------
/**
*/
Variable::~Variable()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
void
Variable::AddValue(const DataType& type, const ValueList& value)
{
    std::pair<DataType, ValueList> pair;
    pair.first = type;
    pair.second = value;
    this->hasDefaultValue = true;
    this->valueTable.push_back(pair);
}

//------------------------------------------------------------------------------
/**
*/
void
Variable::AddValue(const ValueList& value)
{
    std::pair<DataType, ValueList> pair;
    pair.first = this->type;
    pair.second = value;
    this->hasDefaultValue = true;
    this->valueTable.push_back(pair);
}

//------------------------------------------------------------------------------
/**
*/
void
Variable::Preprocess()
{
    // evaluate qualifiers
    unsigned i;
    for (i = 0; i < this->qualifiers.size(); i++)
    {
        const std::string& qualifier = this->qualifiers[i];

        if (qualifier == "rgba32f")				                                this->format = Variable::RGBA32F;
        else if (qualifier == "rgba16f")		                                this->format = Variable::RGBA16F;
        else if (qualifier == "rg32f")			                                this->format = Variable::RG32F;
        else if (qualifier == "rg16f")			                                this->format = Variable::RG16F;
        else if (qualifier == "r11g11b10f")		                                this->format = Variable::R11G11B10F;
        else if (qualifier == "r32f")			                                this->format = Variable::R32F;
        else if (qualifier == "r16f")			                                this->format = Variable::R16F;
        else if (qualifier == "rgba16")			                                this->format = Variable::RGBA16;
        else if (qualifier == "rgba8")			                                this->format = Variable::RGBA8;
        else if (qualifier == "rgb10a2")		                                this->format = Variable::RGB10A2;
        else if (qualifier == "rg16")			                                this->format = Variable::RG16;
        else if (qualifier == "rg8")			                                this->format = Variable::RG8;
        else if (qualifier == "r16")			                                this->format = Variable::R16;
        else if (qualifier == "r8")				                                this->format = Variable::R8;
        else if (qualifier == "rgba16snorm")	                                this->format = Variable::RGBA16SNORM;
        else if (qualifier == "rgba8snorm")		                                this->format = Variable::RGBA8SNORM;
        else if (qualifier == "rg16snorm")		                                this->format = Variable::RG16SNORM;
        else if (qualifier == "rg8snorm")		                                this->format = Variable::RG8SNORM;
        else if (qualifier == "r16snorm")		                                this->format = Variable::R16SNORM;
        else if (qualifier == "r8snorm")		                                this->format = Variable::R8SNORM;
        else if (qualifier == "rgba32i")		                                this->format = Variable::RGBA32I;
        else if (qualifier == "rgba16i")		                                this->format = Variable::RGBA16I;
        else if (qualifier == "rgba8i")			                                this->format = Variable::RGBA8I;
        else if (qualifier == "rg32i")			                                this->format = Variable::RG32I;
        else if (qualifier == "rg16i")			                                this->format = Variable::RG16I;
        else if (qualifier == "rg8i")			                                this->format = Variable::RG8I;
        else if (qualifier == "r32i")			                                this->format = Variable::R32I;
        else if (qualifier == "r16i")			                                this->format = Variable::R16I;
        else if (qualifier == "r8i")			                                this->format = Variable::R8I;
        else if (qualifier == "rgba32ui")		                                this->format = Variable::RGBA32UI;
        else if (qualifier == "rgba16ui")		                                this->format = Variable::RGBA16UI;
        else if (qualifier == "rgba8ui")		                                this->format = Variable::RGBA8UI;
        else if (qualifier == "rg32ui")			                                this->format = Variable::RG32UI;
        else if (qualifier == "rg16ui")			                                this->format = Variable::RG16UI;
        else if (qualifier == "rg8ui")			                                this->format = Variable::RG8UI;
        else if (qualifier == "r32ui")			                                this->format = Variable::R32UI;
        else if (qualifier == "r16ui")			                                this->format = Variable::R16UI;
        else if (qualifier == "r8ui")			                                this->format = Variable::R8UI;
        else if (qualifier == "read")			                                this->accessMode |= Access::Read;
        else if (qualifier == "write")			                                this->accessMode |= Access::Write;
        else if (qualifier == "readwrite" || qualifier == "read_write")		    this->accessMode |= Access::ReadWrite;
        else if (qualifier == "atomic")                                         this->accessMode |= Access::Atomic;
        else if (qualifier == "volatile")                                       this->accessMode |= Access::Volatile;
        else if (qualifier == "groupshared" || qualifier == "group_shared")     this->qualifierFlags |= Variable::GroupShared;
        else if (qualifier == "shared")                                         this->qualifierFlags |= Variable::Shared;
        else if (qualifier == "bindless")                                       this->qualifierFlags |= Variable::Bindless;
        else if (qualifier == "raypayload")                                     this->qualifierFlags |= Variable::RayPayload;
        else
        {
            std::string message = AnyFX::Format("Unknown qualifier '%s', %s\n", qualifier.c_str(), this->ErrorSuffix().c_str());
            AnyFX::Emit(message.c_str());
        }
    }

    // mark variable as uniform
    if (this->qualifierFlags & Variable::GroupShared)
    {
        this->isUniform = false;
    }
}

//------------------------------------------------------------------------------
/**
*/
void
Variable::TypeCheck(TypeChecker& typechecker)
{
    // if type is user defined, check if symbol is defined
    if (this->GetDataType().GetType() == DataType::UserType)
    {
        if (!typechecker.HasSymbol(this->GetDataType().GetName()))
        {
            std::string msg = AnyFX::Format("Undefined type '%s', %s\n", this->GetDataType().GetName().c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(msg, this->GetFile(), this->GetLine());
        }
    }

    // add variable, if failed we must have a redefinition
    if (!typechecker.AddSymbol(this)) return;

    // type check annotation
    if (this->hasAnnotation)
    {
        this->annotation.TypeCheck(typechecker);
    }

    for (unsigned i = 0; i < this->qualifierExpressions.size(); i++)
    {
        const std::string& qualifier = this->qualifierExpressions[i].name;
        Expression* expr = this->qualifierExpressions[i].expr;
        if (qualifier == "group") this->group = expr->EvalUInt(typechecker);
        else if (qualifier == "index") this->index = expr->EvalUInt(typechecker);
        else if (qualifier == "binding") this->binding = expr->EvalUInt(typechecker);
        else
        {
            std::string message = AnyFX::Format("Unknown qualifier '%s', %s\n", qualifier.c_str(), this->ErrorSuffix().c_str());
            AnyFX::Emit(message.c_str());
        }
        delete expr;
    }

    // if binding is invalid, automatically resolve binding
    if (this->binding == -1)
    {
        // get the binding location and increment the global counter
        if (typechecker.GetHeader().GetType() == Header::GLSL)
        {
            if (this->type.GetType() >= DataType::SAMPLER_TYPES_BEGIN && this->type.GetType() <= DataType::SAMPLER_TYPES_END)
            {
                this->binding = Shader::bindingIndices[2]++;
            }
            else if (this->type.GetType() >= DataType::IMAGE_TYPES_BEGIN && this->type.GetType() <= DataType::IMAGE_TYPES_END)
            {
                this->binding = Shader::bindingIndices[3]++;
            }

        }
        else if (typechecker.GetHeader().GetType() == Header::SPIRV)
        {
            if ((this->type.GetType() >= DataType::SAMPLER_TYPES_BEGIN && this->type.GetType() <= DataType::TEXTURE_TYPES_END) ||
                (this->type.GetType() >= DataType::INPUT_ATTACHMENT_TYPES_BEGIN && this->type.GetType() <= DataType::INPUT_ATTACHMENT_TYPES_END) ||
                (this->type.GetType() == DataType::AccelerationStructure))
            {
                this->binding = Shader::bindingIndices[this->group]++;
            }
        }
    }
    else
    {
        // if we already have a binding from an expression, bump all future bindings to the next slot
        if (typechecker.GetHeader().GetType() == Header::GLSL)
        {
            if (this->type.GetType() >= DataType::SAMPLER_TYPES_BEGIN && this->type.GetType() <= DataType::SAMPLER_TYPES_END)
                Shader::bindingIndices[2] = std::max(this->binding + 1, Shader::bindingIndices[2]);
            else if (this->type.GetType() >= DataType::IMAGE_TYPES_BEGIN && this->type.GetType() <= DataType::IMAGE_TYPES_END)
                Shader::bindingIndices[3] = std::max(this->binding + 1, Shader::bindingIndices[3]);

        }
        else if (typechecker.GetHeader().GetType() == Header::SPIRV)
        {
            if ((this->type.GetType() >= DataType::SAMPLER_TYPES_BEGIN && this->type.GetType() <= DataType::TEXTURE_TYPES_END) || 
                (this->type.GetType() >= DataType::INPUT_ATTACHMENT_TYPES_BEGIN && this->type.GetType() <= DataType::INPUT_ATTACHMENT_TYPES_END))
            {
                Shader::bindingIndices[this->group] = std::max(this->binding + 1, Shader::bindingIndices[this->group]);
            }
        }
    }

    // check to see that the user type is valid to be used with a variable
    if (this->type.GetType() == DataType::UserType)
    {
        // check that usertype is valid
        Symbol* sym = typechecker.GetSymbol(this->type.GetName());
        if (0 != sym)
        {
            if (sym->GetType() != Symbol::StructureType && sym->GetType() != Symbol::SubroutineType)
            {
                std::string msg = AnyFX::Format("Type '%s' must be either a struct or a subroutine prototype, %s\n", this->type.GetName().c_str(), this->ErrorSuffix().c_str());
                typechecker.Error(msg, this->GetFile(), this->GetLine());
            }

            if (sym->GetType() == Symbol::SubroutineType)
            {
                this->isSubroutine = true;
            }
        }
        else
        {
            std::string msg = AnyFX::Format("Type '%s' undefined, %s\n", this->type.GetName().c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(msg, this->GetFile(), this->GetLine());
        }
    }

    if (this->isSubroutine && this->arrayType != ArrayType::NoArray)
    {
        std::string msg = AnyFX::Format("Variable cannot be both a subroutine method pointer and an array, %s\n", this->ErrorSuffix().c_str());
        typechecker.Error(msg, this->GetFile(), this->GetLine());
    }

    // evaluate array size
    if (this->arrayType != ArrayType::NoArray)
    {
        this->EvaluateArraySize(typechecker);
    }
    
    unsigned i, j;

    // format value table
    for (i = 0; i < this->valueTable.size(); i++)
    {
        this->valueTable[i].second.ConvertToString(this->valueTable[i].first, typechecker);
    }

    // delete expressions in value list
    for (i = 0; i < this->valueTable.size(); i++)
    {
        const ValueList& valueList = this->valueTable[i].second;
        for (j = 0; j < valueList.GetNumValues(); j++)
        {
            if (valueList.GetValue(j)) delete valueList.GetValue(j);
        }		
    }

    // groupshared is not valid on textures or images
    if (this->GetDataType().GetType() >= DataType::Sampler1D && this->GetDataType().GetType() <= DataType::AtomicCounter)
    {
        if (this->qualifierFlags & Variable::GroupShared)
        {
            std::string message = AnyFX::Format("Qualifier 'groupshared' is not allowed on opaque types (images, samplers and counters), %s\n", this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
    }

    // evaluate type correctness of array initializers
    if (this->arrayType != ArrayType::NoArray)
    {
        if (this->valueTable.size() != 0)
        {
            // if we have an int-array, float-array, bool-array...
            if (this->arrayType == SimpleArray)
            {
                std::pair<DataType, ValueList> pair = this->valueTable[0];
                if (this->type.GetStyle() != DataType::Generic)
                {
                    std::string message = AnyFX::Format("Non-basic types (types other than float, double, bool, int, uint and short) needs explicit type initializers, %s\n", this->ErrorSuffix().c_str());
                    typechecker.Error(message, this->GetFile(), this->GetLine());
                }
                if (pair.second.GetNumValues() != this->arraySizes[0])
                {
                    std::string message = AnyFX::Format("Wrong amount of initializers for array, got %d values, expected %d, %s\n", pair.second.GetNumValues(), this->arraySizes[0], this->ErrorSuffix().c_str());
                    typechecker.Error(message, this->GetFile(), this->GetLine());
                }
            }
            else if (this->valueTable.size() != this->arraySizes[0])
            {
                std::string message = AnyFX::Format("Wrong amount of initializers for array, got %d initializers, expected %d, %s\n", this->valueTable.size(), this->arraySizes[0], this->ErrorSuffix().c_str());
                typechecker.Error(message, this->GetFile(), this->GetLine());
            }	

            unsigned i;
            for (i = 0; i < this->valueTable.size(); i++)
            {
                std::pair<DataType, ValueList> pair = this->valueTable[i];
                if (pair.first != this->type)
                {
                    std::string message = AnyFX::Format("Array initializer at index %d has different type than array, %s\n", i+1, this->ErrorSuffix().c_str());
                    typechecker.Error(message, this->GetFile(), this->GetLine());
                }
                unsigned numVals = pair.second.GetNumValues();
                DataType::Dimensions dims = DataType::ToDimensions(this->GetDataType());
                if (numVals != dims.x)
                {
                    std::string message = AnyFX::Format("Initializer at index %d is not completely initialized, got %d initializers, expected %d, %s\n", i+1, numVals, dims.x, this->ErrorSuffix().c_str());
                    typechecker.Error(message, this->GetFile(), this->GetLine());
                }
            }
        }
    }
    else
    {
        // get vector size of this type
        DataType::Dimensions dims = DataType::ToDimensions(this->GetDataType());
        for (i = 0; i < this->valueTable.size(); i++)
        {
            std::pair<DataType, ValueList> pair = this->valueTable[i];
            if (pair.first != this->type)
            {
                std::string message = AnyFX::Format("Cannot implicitly cast from '%s' to '%s', %s\n", DataType::ToString(this->type).c_str(), DataType::ToString(pair.first).c_str(), this->ErrorSuffix().c_str());
                typechecker.Error(message, this->GetFile(), this->GetLine());
            }
            if (pair.second.GetNumValues() != dims.x * dims.y)
            {
                std::string message = AnyFX::Format("Type constructor at index %d isn't fully initialized, got %d values, expected %d, %s\n", i+1, pair.second.GetNumValues(), dims.x, this->ErrorSuffix().c_str());
                typechecker.Error(message, this->GetFile(), this->GetLine());
            }
        }
    }


    // assume we have a format set when we have an image
    if (this->type.GetType() >= DataType::Image1D && this->type.GetType() <= DataType::ImageCubeArray)
    {
        if (this->accessMode == Access::NoAccess)
        {
            std::string message = AnyFX::Format("Variable '%s' is of image type but does not have a required access qualifier, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
        else if (typechecker.GetHeader().GetType() != Header::SPIRV)
        {
            if (this->accessMode != Access::Write)
            {
                if (this->format == NoFormat)
                {
                    std::string message = AnyFX::Format("Variable '%s' is of image type but does not have a required format qualifier, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
                    typechecker.Error(message, this->GetFile(), this->GetLine());
                }
            }
        }		
    }
    else
    {
        if (this->format != NoFormat)
        {
            std::string message = AnyFX::Format("Variable '%s' has an image format qualifier, but is not an image variable, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Warning(message, this->GetFile(), this->GetLine());
        }

        if (this->accessMode != Access::NoAccess)
        {
            std::string message = AnyFX::Format("Variable '%s' has an image access qualifier, but is not an image variable, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Warning(message, this->GetFile(), this->GetLine());
        }
    }
    
    const Header::Type type = typechecker.GetHeader().GetType();
    if (type == Header::GLSL || type == Header::SPIRV)
    {
        if (this->type.GetStyle() != DataType::GLSL && this->type.GetStyle() != DataType::Generic)
        {
            std::string message = AnyFX::Format("Variable '%s' is not formatted in GLSL, although compilation target is GLSL, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Warning(message, this->GetFile(), this->GetLine());
        }
    }
    else if (type == Header::HLSL)
    {
        if (this->type.GetStyle() != DataType::HLSL && this->type.GetStyle() != DataType::Generic)
        {
            std::string message = AnyFX::Format("Variable '%s' is not formatted in HLSL, although compilation target is HLSL, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Warning(message, this->GetFile(), this->GetLine());
        }
    }
}

//------------------------------------------------------------------------------
/**
*/
void
Variable::Compile(BinWriter& writer)
{
    bool shared = (this->qualifierFlags & Variable::Shared) == 0 ? false : true;
    writer.WriteString(this->name);
    writer.WriteBool(shared);
    writer.WriteBool((this->qualifierFlags & Bindless) != 0);
    writer.WriteUInt(this->binding);
    writer.WriteUInt(this->group);
    writer.WriteInt(this->type.GetType());

    // if this is a compute variable, write the format and access mode to stream
    if (this->type.GetType() >= DataType::Image1D && this->type.GetType() <= DataType::ImageCubeArray)
    {
        writer.WriteInt(this->format);
        writer.WriteInt(this->accessMode);
    }

    // write if annotation is used
    writer.WriteBool(this->hasAnnotation);
    if (this->hasAnnotation)
    {
        this->annotation.Compile(writer);
    }	

    // write if this variable is an array
    writer.WriteBool(this->arrayType != ArrayType::NoArray);

    if (this->arraySizes.empty())
    {
        // one fake array size, and with the dimension of 1
        writer.WriteInt(1);
        writer.WriteInt(1);
    }
    else
    {
        // write count of sizes, then each size
        writer.WriteInt(this->arraySizes.size());
        for (size_t i = 0; i < this->arraySizes.size(); i++)
        {
            writer.WriteInt(this->arraySizes[i]);
        }
    }

    // write if variable is a subroutine method pointer
    writer.WriteBool(this->isSubroutine);

    // write if we have a default value
    writer.WriteBool(this->hasDefaultValue);
    
    if (this->HasDefaultValue())
    {
        // we want to concatenate all values into a single string
        std::string valueString;

        // reformat all string as a long list of values
        unsigned i;
        for (i = 0; i < this->valueTable.size(); i++)
        {
            if (i > 0)
            {
                valueString.append(", ");
            }
            valueString.append(this->valueTable[i].second.GetString());
        }

        // write amount of array default variables
        writer.WriteString(valueString);
    }
}

//------------------------------------------------------------------------------
/**
*/
const Variable::Binding 
Variable::GetBinding() const
{
    Binding ret;
    if (this->type.GetType() >= DataType::ALL_TEXTURE_TYPES_BEGIN && this->type.GetType() <= DataType::ALL_TEXTURE_TYPES_END)
    {
        ret.type = Binding::Type::Texture;
        ret.binding.texture = { this->binding };
        ret.group = this->group;
        ret.name = this->name;
    }
    return ret;
}

//------------------------------------------------------------------------------
/**
    Format variable code, this is pretty generic and is only dependent on how to format the types
*/
std::string
Variable::Format(const Header& header, bool inVarblock) const
{
    std::string formattedCode;

    if (header.GetFlags() & Header::NoSubroutines && this->isSubroutine) return formattedCode;

    if (header.GetType() == Header::GLSL)
    {
        if (this->type.GetType() >= DataType::Image1D && this->type.GetType() <= DataType::ImageCubeArray)
        {
            if (this->format == NoFormat)
            {
                formattedCode.append(AnyFX::Format("layout(binding=%d) %s ", this->binding, this->FormatImageAccess(header).c_str()));
            }
            else
            {
                formattedCode.append(AnyFX::Format("layout(binding=%d %s) %s ", this->binding, this->FormatImageFormat(header).c_str(), this->FormatImageAccess(header).c_str()));
            }
        }    
        else if (this->type.GetType() >= DataType::Sampler1D && this->type.GetType() <= DataType::SamplerCubeArray)
        {
            if (this->qualifierFlags & Bindless) formattedCode.append(AnyFX::Format("layout(binding=%d, bindless_sampler) ", this->binding));
            else								 formattedCode.append(AnyFX::Format("layout(binding=%d) ", this->binding));
        }

        else if (this->type.GetType() >= DataType::Matrix2x2 && this->type.GetType() <= DataType::Matrix4x4 && inVarblock)
        {
            formattedCode.append("layout(column_major) ");
        }
    }
    else if (header.GetType() == Header::SPIRV)
    {
        if (this->type.GetType() >= DataType::Image1D && this->type.GetType() <= DataType::ImageCubeArray)
        {
            if (this->format == NoFormat)
            {
                formattedCode.append(AnyFX::Format("layout(set=%d, binding=%d) ", this->group, this->binding));
                formattedCode.append(this->FormatImageAccess(header));
                formattedCode.append(" ");
            }
            else
            {
                formattedCode.append(AnyFX::Format("layout(set=%d, binding=%d, ", this->group, this->binding));
                formattedCode.append(this->FormatImageFormat(header));
                formattedCode.append(") ");
                formattedCode.append(this->FormatImageAccess(header));
                formattedCode.append(" ");
            }
        }
        else if (this->type.GetType() >= DataType::Sampler1D && this->type.GetType() <= DataType::TextureCubeArray)
        {
            formattedCode.append(AnyFX::Format("layout(set=%d, binding=%d) ", this->group, this->binding));
        }
        else if (this->type.GetType() >= DataType::Matrix2x2 && this->type.GetType() <= DataType::Matrix4x4 && inVarblock)
        {
            formattedCode.append("layout(column_major) ");
        }
        else if (this->type.GetType() >= DataType::InputAttachment && this->type.GetType() <= DataType::InputAttachmentUIntegerMS)
        {
            // make sure to only generate input attachments for fragment shaders
            formattedCode.append("#ifdef PIXEL_SHADER\n");
            formattedCode.append(AnyFX::Format("layout(input_attachment_index=%d, set=%d, binding=%d) ", this->index, this->group, this->binding));
        }
        else if (this->type.GetType() == DataType::AccelerationStructure)
        {
            formattedCode.append(AnyFX::Format("layout(set=%d, binding=%d) ", this->group, this->binding));
        }
    }

    // add GLSL uniform qualifier
    if ((header.GetType() == Header::GLSL || header.GetType() == Header::SPIRV) && !inVarblock)
    {
        if (this->isSubroutine)                 formattedCode.append("subroutine ");
        if (this->qualifierFlags & GroupShared) formattedCode.append("shared ");
        else                                    formattedCode.append("uniform ");
    }

    // get name without parents
    size_t offset = this->name.rfind('.');
    std::string leafName = offset != std::string::npos ? this->name.substr(offset + 1) : this->name;
    
    // if c, an unsized struct is just a pointer to it...
    if (header.GetType() == Header::C)
    {
        DataType::Dimensions dims = DataType::ToDimensions(this->GetDataType());
        formattedCode.append("\t");
        formattedCode.append(DataType::ToProfileType(this->GetDataType(), header.GetType()));

        if (this->arrayType != ArrayType::NoArray)
        {
            if (this->arrayType != UnsizedArray)
            {
                std::string arrayDimensions;
                for (size_t i = 0; i < this->arraySizes.size(); i++)
                {
                    arrayDimensions.append(AnyFX::Format("[%d]", this->arraySizes[i]));
                }
                formattedCode.append(AnyFX::Format(" %s%s", leafName.c_str(), arrayDimensions.c_str()));
            }
            else
            {
                formattedCode.append("*");
                formattedCode.append(" ");
                formattedCode.append(leafName);
            }
        }
        else
        {
            formattedCode.append(" ");
            formattedCode.append(leafName);
        }

        if (dims.x > 1 || dims.y > 1)
        {
            // round up 3 column vectors to 4 if we have a matrix
            if (dims.x == 3 && dims.y > 1)
                formattedCode.append(AnyFX::Format("[%d][%d]", dims.y, 4));
            else
                formattedCode.append(AnyFX::Format("[%d]", dims.x * dims.y));
        }
    }
    else
    { 
        formattedCode.append("\t");
        formattedCode.append(DataType::ToProfileType(this->GetDataType(), header.GetType()));
        formattedCode.append(" ");
        formattedCode.append(leafName);
        if (this->arrayType != ArrayType::NoArray)
        {
            for (size_t i = 0; i < this->arraySizes.size(); i++)
            {
                if (this->arrayType == UnsizedArray)
                    formattedCode.append("[]");
                else
                    formattedCode.append(AnyFX::Format("[%d]", this->arraySizes[i]));
            }
        }
    }

    formattedCode.append(";\n");

    // input attachments are only available in fragment shaders in SPIR-V
    if (header.GetType() == Header::SPIRV && this->type.GetType() >= DataType::InputAttachment && this->type.GetType() <= DataType::InputAttachmentUIntegerMS)
        formattedCode.append("#endif //PIXEL_SHADER\n");
    return formattedCode;
}

//------------------------------------------------------------------------------
/**
*/
const unsigned 
Variable::GetByteSize() const
{
    return DataType::ToByteSize(this->type);
}

//------------------------------------------------------------------------------
/**
*/
std::string 
Variable::FormatImageFormat(const Header& header) const
{
    if (header.GetType() == Header::GLSL || header.GetType() == Header::SPIRV)
    {
        switch (this->format)
        {
        case NoFormat:
            return "";
        case RGBA32F:
            return "rgba32f";
        case RGBA16F:
            return "rgba16f";
        case RG32F:
            return "rg32f";
        case RG16F:
            return "rg16f";
        case R11G11B10F:
            return "r11f_g11f_b10f";
        case R32F:
            return "r32f";
        case R16F:
            return "r16f";
        case RGBA16:
            return "rgba16";
        case RGB10A2:
            return "rgb10_a2";
        case RGBA8:
            return "rgba8";
        case RG16:
            return "rg16";
        case RG8:
            return "rg8";
        case R16:
            return "r16";			
        case R8:
            return "r8";
        case RGBA16SNORM:
            return "rgba16_snorm";
        case RGBA8SNORM:
            return "rgba8_snorm";
        case RG16SNORM:
            return "rg16_snorm";
        case RG8SNORM:
            return "rg8_snorm";
        case R16SNORM:
            return "r16_snorm";
        case R8SNORM:
            return "r8_snorm";
        case RGBA32I:
            return "rgba32i";
        case RGBA16I:
            return "rgba16i";
        case RGBA8I:
            return "rgba8i";
        case RG32I:
            return "rg32i";
        case RG16I:
            return "rg16i";
        case RG8I:
            return "rg8i";
        case R32I:
            return "r32i";
        case R16I:
            return "r16i";
        case R8I:
            return "r8i";
        case RGBA32UI:
            return "rgba32ui";
        case RGBA16UI:
            return "rgba16ui";
        case RGBA8UI:
            return "rgba8ui";
        case RG32UI:
            return "rg32ui";
        case RG16UI:
            return "rg16ui";
        case RG8UI:
            return "rg8ui";
        case R32UI:
            return "r32ui";
        case R16UI:
            return "r16ui";
        case R8UI:
            return "r8ui";
        }
    }
    else
    {
        // IMPLEMENT ME
    }

    // fallthrough
    return "";
}

//------------------------------------------------------------------------------
/**
*/
std::string 
Variable::FormatImageAccess(const Header& header) const
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

//------------------------------------------------------------------------------
/**
*/
void 
Variable::EvaluateArraySize(TypeChecker& typechecker)
{
    for (size_t i = 0; i < this->sizeExpressions.size(); i++)
    {
        this->arraySizes.push_back(this->sizeExpressions[i]->EvalInt(typechecker));
        this->arraySize *= this->arraySizes.back();        
        delete this->sizeExpressions[i];
    }
    this->sizeExpressions.clear();

    if (this->arrayType == SimpleArray && this->valueTable.size() > 0)
    {
        this->arraySizes.push_back(this->valueTable[0].second.GetNumValues());
        this->arraySize = this->valueTable[0].second.GetNumValues();
    }
    else if (this->arrayType == TypedArray)
    {
        this->arraySizes.push_back(this->valueTable.size());
        this->arraySize = this->valueTable.size();
    }
    else if (this->arrayType == UnsizedArray)
    {
        // an unsized array should count as a single type when determining the size, since it's practically undecided.
        this->arraySizes.push_back(1);
        this->arraySize = 1;
    }
}
} // namespace AnyFX
