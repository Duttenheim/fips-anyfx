#pragma once
//------------------------------------------------------------------------------
/**
    @class SamplerRow
    
    Intermediate representation of a single sampler setting inside a sampler object. Gets consumed by actual sampler.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "types.h"
#include "util.h"
#include "samplertexturelist.h"
#include "expressions/expression.h"
namespace AnyFX
{

class SamplerRow
{
public:

	enum AdressMode
	{
		Wrap,
		Mirror,
		Clamp,
		Border,
		MirrorOnce,

		NumAddressModes
	};

	enum FilterMode
	{
		MinMagMipPoint,
		MinMagMipLinear,
		MinMagPointMipLinear,
		MinMipPointMagLinear,
		MinPointMipMagLinear,
		MinLinearMipMagPoint,
		MinMipLinearMagPoint,
		MinMagLinearMipPoint,
		Anisotropic,
		Point,
		Linear,

		NumFilterModes
	};

	enum ComparisonFunction
	{
		Never,
		Less,
		LEqual,
		Greater,
		GEqual,
		Equal,
		NEqual,
		Always,

		NumComparisonFunctions,

		InvalidComparisonFunction
	};

	enum BorderColorMode
	{
		Transparent,
		Black,
		White
	};

	enum FlagType
	{
		ExpressionFlagType,
		StringFlagType,
		TextureListFlagType,

		NumFlagTypes
	};

	enum EnumFlag
	{
		Filter,
		AddressU,
		AddressV,
		AddressW,
		ComparisonFunc,
		BorderColor,

		NumEnumFlags
	};

	enum BoolFlag
	{
		Comparison,
		Unnormalized,

		NumBoolFlags
	};

	enum FloatFlag
	{
		LodBias,
		MinLod,
		MaxLod,
		MaxAnisotropic,

		NumFloatFlags
	};
	
	/// constructor
	SamplerRow();
	/// destructor
	virtual ~SamplerRow();

	/// get flag type
	const FlagType& GetFlagType() const;
	/// get flag index, this basically tells us the enum offset 
	const std::string& GetFlag() const;

	/// sets expression value
	void SetExpression(const std::string& flag, Expression* expr);
	/// gets expression value
	Expression* GetExpression() const;
	/// sets a string value
	void SetString(const std::string& flag, const std::string& value);
	/// gets string value
	const std::string& GetString() const;
	/// set texture list
	void SetTextures(const SamplerTextureList& list);
	/// get texture list
	const SamplerTextureList& GetTextures() const;

	/// converts int flag to string
	static const std::string StringFlagToString(const EnumFlag& flag);
private:

	FlagType flagType;
	SamplerTextureList textureList;
	std::string flag;
	
	Expression* expr;
	vector<Expression*, 4> rgbExprs;
	std::string stringValue;
}; 

//------------------------------------------------------------------------------
/**
*/
inline const SamplerRow::FlagType& 
SamplerRow::GetFlagType() const
{
	return this->flagType;
}

//------------------------------------------------------------------------------
/**
*/
inline const std::string&
SamplerRow::GetFlag() const
{
	return this->flag;
}

//------------------------------------------------------------------------------
/**
*/
inline const std::string& 
SamplerRow::GetString() const
{
	assert(this->flagType == StringFlagType);
	return this->stringValue;
}

//------------------------------------------------------------------------------
/**
*/
inline const SamplerTextureList& 
SamplerRow::GetTextures() const
{
	assert(this->flagType == TextureListFlagType);
	return this->textureList;
}

//------------------------------------------------------------------------------
/**
*/
inline Expression* 
SamplerRow::GetExpression() const
{
	assert(this->flagType == ExpressionFlagType);
	return this->expr;
}

} // namespace AnyFX
//------------------------------------------------------------------------------
