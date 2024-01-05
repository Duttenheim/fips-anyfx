//------------------------------------------------------------------------------
//  drawstate.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "renderstate.h"
#include "types.h"
#include "typechecker.h"
namespace AnyFX
{


//------------------------------------------------------------------------------
/**
*/
RenderState::RenderState() :
	hasAnnotation(false)
{
	this->symbolType = Symbol::RenderStateType;

	// set enumerated flags
	this->drawEnumFlags[RenderStateRow::StencilFrontFunc] = this->drawEnumFlags[RenderStateRow::StencilBackFunc] = RenderStateRow::Always;
	this->drawEnumFlags[RenderStateRow::StencilFrontDepthFailOp] = this->drawEnumFlags[RenderStateRow::StencilBackDepthFailOp] = RenderStateRow::Keep;
	this->drawEnumFlags[RenderStateRow::StencilFrontPassOp] = this->drawEnumFlags[RenderStateRow::StencilBackPassOp] = RenderStateRow::Keep;
	this->drawEnumFlags[RenderStateRow::StencilFrontFailOp] = this->drawEnumFlags[RenderStateRow::StencilBackFailOp] = RenderStateRow::Keep;
	this->drawEnumFlags[RenderStateRow::DepthFunc] = RenderStateRow::Less;
	this->drawEnumFlags[RenderStateRow::CullMode] = RenderStateRow::Back;
	this->drawEnumFlags[RenderStateRow::RasterizerMode] = RenderStateRow::Fill;
	this->drawEnumFlags[RenderStateRow::WindingMode] = RenderStateRow::CW;
	this->drawEnumFlags[RenderStateRow::SampleCount] = RenderStateRow::Bits1;
	this->drawEnumFlags[RenderStateRow::LogicOp] = RenderStateRow::Copy;
	
	// set default blend flags
	unsigned i;
	for (i = 0; i < MaxNumRenderTargets; i++)
	{
		this->blendBoolFlags[i][BlendStateRow::BlendEnabled] = false;
		this->blendEnumFlags[i][BlendStateRow::SrcBlend] = BlendStateRow::One;
		this->blendEnumFlags[i][BlendStateRow::DstBlend] = BlendStateRow::Zero;
		this->blendEnumFlags[i][BlendStateRow::BlendOp] = BlendStateRow::Add;
		this->blendEnumFlags[i][BlendStateRow::SrcBlendAlpha] = BlendStateRow::One;
		this->blendEnumFlags[i][BlendStateRow::DstBlendAlpha] = BlendStateRow::Zero;
		this->blendEnumFlags[i][BlendStateRow::BlendOpAlpha] = BlendStateRow::Add;	
	}

	// set default render settings
	this->drawBoolFlags[RenderStateRow::DepthEnabled] = true;
	this->drawBoolFlags[RenderStateRow::DepthWrite] = true;
	this->drawBoolFlags[RenderStateRow::DepthClamp] = false;
	this->drawBoolFlags[RenderStateRow::SeparateBlend] = false;
	this->drawBoolFlags[RenderStateRow::ScissorEnabled] = false;
	this->drawBoolFlags[RenderStateRow::StencilEnabled] = false;
	this->drawBoolFlags[RenderStateRow::MultisampleEnabled] = false;
	this->drawBoolFlags[RenderStateRow::AlphaToCoverageEnabled] = false;
	this->drawBoolFlags[RenderStateRow::AlphaToOneEnabled] = false;
	this->drawBoolFlags[RenderStateRow::PolygonOffsetEnabled] = false;
	this->drawBoolFlags[RenderStateRow::RasterizerDiscardEnabled] = false;
	this->drawBoolFlags[RenderStateRow::LogicOpEnabled] = false;

	this->drawIntFlags[RenderStateRow::StencilFrontRef] = 0xFF;
	this->drawIntFlags[RenderStateRow::StencilBackRef] = 0xFF;
	this->drawUintFlags[RenderStateRow::StencilReadMask] = 0xFF;
	this->drawUintFlags[RenderStateRow::StencilWriteMask] = 0;

	this->drawFloatFlags[RenderStateRow::PolygonOffsetFactor] = 0.0f;
	this->drawFloatFlags[RenderStateRow::PolygonOffsetUnits] = 0.0f;
	this->drawFloatFlags[RenderStateRow::MinSampleShading] = 0.0f;
	this->drawFloatFlags[RenderStateRow::MinDepthBounds] = 0.0f;
	this->drawFloatFlags[RenderStateRow::MaxDepthBounds] = 10000.0f;
	this->drawFloatFlags[RenderStateRow::LineWidth] = 1.0f;
}

//------------------------------------------------------------------------------
/**
*/
RenderState::~RenderState()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void 
RenderState::ConsumeRenderRow(const RenderStateRow& row)
{
	this->renderStateRows.push_back(row);
}

//------------------------------------------------------------------------------
/**
*/
void
RenderState::ConsumeBlendRow(const BlendStateRow& row)
{
	this->blendStateRows.push_back(row);
}

//------------------------------------------------------------------------------
/**
*/
void
RenderState::TypeCheck(TypeChecker& typechecker)
{
	// add render state, if failed we must have a redefinition
	if (!typechecker.AddSymbol(this)) return;

	// process entries
	this->EvaluateEntries(typechecker);

	// report all if any unwanted options
	unsigned i;
	for (i = 0; i < this->invalidExpressionFlags.size(); i++)
	{
		std::string msg = AnyFX::Format("Render state field '%s' is invalid, %s\n", this->invalidExpressionFlags[i].c_str(), this->ErrorSuffix().c_str());
		typechecker.Error(msg, this->GetFile(), this->GetLine());
	}

	for (i = 0; i < this->invalidStringFlags.size(); i++)
	{
		std::string msg = AnyFX::Format("Render state field '%s' is invalid, %s\n", this->invalidStringFlags[i].c_str(), this->ErrorSuffix().c_str());
		typechecker.Error(msg, this->GetFile(), this->GetLine());
	}

	for (i = 0; i < this->invalidValues.size(); i++)
	{
		std::string msg = AnyFX::Format("Invalid value '%s' for flag '%s', %s\n", this->invalidValues[i].value.c_str(), this->invalidValues[i].flag.c_str(), this->ErrorSuffix().c_str());
		typechecker.Error(msg, this->GetFile(), this->GetLine());
	}

	// type check annotation
	if (this->hasAnnotation)
	{
		this->annotation.TypeCheck(typechecker);
	}

	// fail type checking if the name of this render state is placeholder
	if (this->name == "placeholder")
	{
		std::string message = AnyFX::Format("Type error: Render state with name 'placeholder' is not allowed, %s", this->ErrorSuffix().c_str());
		typechecker.Error(message, this->GetFile(), this->GetLine());
	}
}

//------------------------------------------------------------------------------
/**
*/
void 
RenderState::Compile(BinWriter& writer)
{
	// write name
	writer.WriteString(this->name);

	// write if annotation is used
	writer.WriteBool(this->hasAnnotation);

	// compile annotation if
	if (this->hasAnnotation)
	{
		this->annotation.Compile(writer);
	}	

	// write blend flags
	unsigned i;
	for (i = 0; i < MaxNumRenderTargets; i++)
	{
		// write bool flags
		unsigned j;
		for (j = 0; j < BlendStateRow::NumBoolFlags; j++)
		{
			// write bool flags
			writer.WriteBool(blendBoolFlags[i][j]);
		}
		
		for (j = 0; j < BlendStateRow::NumEnumFlags; j++)
		{
			// writer blend flags
			writer.WriteInt(blendEnumFlags[i][j]);
		}
	}


	// write draw bool flags
	for (i = 0; i < RenderStateRow::NumBoolFlags; i++)
	{
		writer.WriteBool(drawBoolFlags[i]);
	}

	// write enumerated draw flags
	for (i = 0; i < RenderStateRow::NumEnumFlags; i++)
	{
		writer.WriteUInt(drawEnumFlags[i]);
	}

	// write draw int flags
	for (i = 0; i < RenderStateRow::NumIntFlags; i++)
	{
		writer.WriteInt(drawIntFlags[i]);
	}

	// write draw uint flags
	for (i = 0; i < RenderStateRow::NumUintFlags; i++)
	{
		writer.WriteUInt(drawUintFlags[i]);
	}

	// write draw float flags
	for (i = 0; i < RenderStateRow::NumFloatFlags; i++)
	{
		writer.WriteFloat(drawFloatFlags[i]);
	}
}

//------------------------------------------------------------------------------
/**
*/
void 
RenderState::EvaluateEntries(TypeChecker& typeChecker)
{
	for (int i = 0; i < this->renderStateRows.size(); i++)
	{
		RenderStateRow& row = this->renderStateRows[i];
		if (row.GetFlag() == "DepthFunc")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Never")									flagVal = RenderStateRow::Never;
			else if (flag == "Less")								flagVal = RenderStateRow::Less;
			else if (flag == "Lequal" || flag == "LessEqual")		flagVal = RenderStateRow::LEqual;
			else if (flag == "Greater")								flagVal = RenderStateRow::Greater;
			else if (flag == "Gequal" || flag == "GreaterEqual")	flagVal = RenderStateRow::GEqual;
			else if (flag == "Equal")								flagVal = RenderStateRow::Equal;
			else if (flag == "Nequal" || flag == "NotEqual")		flagVal = RenderStateRow::NEqual;
			else if (flag == "Always")								flagVal = RenderStateRow::Always;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::DepthFunc] = flagVal;
		}
		else if (row.GetFlag() == "FillMode")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Fill")								flagVal = RenderStateRow::Fill;
			else if (flag == "Line")						flagVal = RenderStateRow::Line;
			else if (flag == "Point")						flagVal = RenderStateRow::Point;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::RasterizerMode] = flagVal;
		}
		else if (row.GetFlag() == "CullMode")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Back")								flagVal = RenderStateRow::Back;
			else if (flag == "Front")						flagVal = RenderStateRow::Front;
			else if (flag == "None")						flagVal = RenderStateRow::None;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::CullMode] = flagVal;
		}
		else if (row.GetFlag() == "WindingMode")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "CW")								flagVal = RenderStateRow::CW;
			else if (flag == "CCW")							flagVal = RenderStateRow::CCW;

			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::WindingMode] = flagVal;
		}
		else if (row.GetFlag() == "SampleCount")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Bits1")							flagVal = RenderStateRow::Bits1;
			else if (flag == "Bits2")						flagVal = RenderStateRow::Bits2;
			else if (flag == "Bits4")						flagVal = RenderStateRow::Bits4;
			else if (flag == "Bits8")						flagVal = RenderStateRow::Bits8;
			else if (flag == "Bits16")						flagVal = RenderStateRow::Bits16;
			else if (flag == "Bits32")						flagVal = RenderStateRow::Bits32;
			else if (flag == "Bits64")						flagVal = RenderStateRow::Bits64;

			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::SampleCount] = flagVal;
		}
		else if (row.GetFlag() == "LogicOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Clear")							flagVal = RenderStateRow::Clear;
			else if (flag == "And")							flagVal = RenderStateRow::And;
			else if (flag == "AndReverse")					flagVal = RenderStateRow::AndReverse;
			else if (flag == "Copy")						flagVal = RenderStateRow::Copy;
			else if (flag == "AndInverted")					flagVal = RenderStateRow::AndInverted;
			else if (flag == "NoOp")						flagVal = RenderStateRow::NoOp;
			else if (flag == "Xor")							flagVal = RenderStateRow::Xor;
			else if (flag == "Or")							flagVal = RenderStateRow::Or;
			else if (flag == "Nor")							flagVal = RenderStateRow::Nor;
			else if (flag == "Equivalent")					flagVal = RenderStateRow::Equivalent;
			else if (flag == "Inverted")					flagVal = RenderStateRow::Inverted;
			else if (flag == "OrReverse")					flagVal = RenderStateRow::OrReverse;
			else if (flag == "CopyInverted")				flagVal = RenderStateRow::CopyInverted;
			else if (flag == "OrInverted")					flagVal = RenderStateRow::OrInverted;
			else if (flag == "Nand")						flagVal = RenderStateRow::Nand;
			else if (flag == "Set")							flagVal = RenderStateRow::Set;

			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::LogicOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilFrontFailOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontFailOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilBackFailOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilBackFailOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilFrontPassOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontPassOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilBackPassOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilBackPassOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilFrontDepthFailOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontDepthFailOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilBackDepthFailOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilBackDepthFailOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilFrontFunc")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Never")						flagVal = RenderStateRow::Never;
			else if (flag == "Less")					flagVal = RenderStateRow::Less;
			else if (flag == "Lequal")					flagVal = RenderStateRow::LEqual;
			else if (flag == "Greater")					flagVal = RenderStateRow::Greater;
			else if (flag == "Gequal")					flagVal = RenderStateRow::GEqual;
			else if (flag == "Equal")					flagVal = RenderStateRow::Equal;
			else if (flag == "Nequal")					flagVal = RenderStateRow::NEqual;
			else if (flag == "Always")					flagVal = RenderStateRow::Always;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontFunc] = flagVal;
		}
		else if (row.GetFlag() == "StencilBackFunc")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Never")						flagVal = RenderStateRow::Never;
			else if (flag == "Less")					flagVal = RenderStateRow::Less;
			else if (flag == "Lequal")					flagVal = RenderStateRow::LEqual;
			else if (flag == "Greater")					flagVal = RenderStateRow::Greater;
			else if (flag == "Gequal")					flagVal = RenderStateRow::GEqual;
			else if (flag == "Equal")					flagVal = RenderStateRow::Equal;
			else if (flag == "Nequal")					flagVal = RenderStateRow::NEqual;
			else if (flag == "Always")					flagVal = RenderStateRow::Always;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilBackFunc] = flagVal;
		}
		else if (row.GetFlag() == "StencilFailOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontFailOp] = flagVal;
			this->drawEnumFlags[RenderStateRow::StencilBackFailOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilPassOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontPassOp] = flagVal;
			this->drawEnumFlags[RenderStateRow::StencilBackPassOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilDepthFailOp")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Keep")					flagVal = RenderStateRow::Keep;
			else if (flag == "Zero")			flagVal = RenderStateRow::Zero;
			else if (flag == "Replace")			flagVal = RenderStateRow::Replace;
			else if (flag == "Increase")		flagVal = RenderStateRow::Increase;
			else if (flag == "IncreaseWrap")	flagVal = RenderStateRow::IncreaseWrap;
			else if (flag == "Decrease")		flagVal = RenderStateRow::Decrease;
			else if (flag == "DecreaseWrap")	flagVal = RenderStateRow::DecreaseWrap;
			else if (flag == "Invert")			flagVal = RenderStateRow::Invert;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontDepthFailOp] = flagVal;
			this->drawEnumFlags[RenderStateRow::StencilBackDepthFailOp] = flagVal;
		}
		else if (row.GetFlag() == "StencilFunc")
		{
			const std::string& flag = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal = -1;

			if (flag == "Never")						flagVal = RenderStateRow::Never;
			else if (flag == "Less")					flagVal = RenderStateRow::Less;
			else if (flag == "Lequal")					flagVal = RenderStateRow::LEqual;
			else if (flag == "Greater")					flagVal = RenderStateRow::Greater;
			else if (flag == "Gequal")					flagVal = RenderStateRow::GEqual;
			else if (flag == "Equal")					flagVal = RenderStateRow::Equal;
			else if (flag == "Nequal")					flagVal = RenderStateRow::NEqual;
			else if (flag == "Always")					flagVal = RenderStateRow::Always;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), flag };
				this->invalidValues.push_back(foo);
				return;
			}

			this->drawEnumFlags[RenderStateRow::StencilFrontFunc] = flagVal;
			this->drawEnumFlags[RenderStateRow::StencilBackFunc] = flagVal;
		}
		else if (row.GetFlag() == "StencilFrontRef")			this->drawIntFlags[RenderStateRow::StencilFrontRef] = row.GetExpression()->EvalInt(typeChecker);
		else if (row.GetFlag() == "StencilBackRef")				this->drawIntFlags[RenderStateRow::StencilBackRef] = row.GetExpression()->EvalInt(typeChecker);
		else if (row.GetFlag() == "StencilReadMask")			this->drawUintFlags[RenderStateRow::StencilReadMask] = row.GetExpression()->EvalUInt(typeChecker);
		else if (row.GetFlag() == "StencilWriteMask")			this->drawUintFlags[RenderStateRow::StencilWriteMask] = row.GetExpression()->EvalUInt(typeChecker);
		else if (row.GetFlag() == "DepthEnabled")				this->drawBoolFlags[RenderStateRow::DepthEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "DepthWrite")					this->drawBoolFlags[RenderStateRow::DepthWrite] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "DepthClamp")					this->drawBoolFlags[RenderStateRow::DepthClamp] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "SeparateBlend")				this->drawBoolFlags[RenderStateRow::SeparateBlend] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "ScissorEnabled")				this->drawBoolFlags[RenderStateRow::ScissorEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "StencilEnabled")				this->drawBoolFlags[RenderStateRow::StencilEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "AlphaToCoverageEnabled")		this->drawBoolFlags[RenderStateRow::AlphaToCoverageEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "AlphaToOneEnabled")			this->drawBoolFlags[RenderStateRow::AlphaToOneEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "MultisampleEnabled")			this->drawBoolFlags[RenderStateRow::MultisampleEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "RasterizerDiscardEnabled")	this->drawBoolFlags[RenderStateRow::RasterizerDiscardEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "LogicOpEnabled")				this->drawBoolFlags[RenderStateRow::LogicOpEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "PolygonOffsetEnabled")		this->drawBoolFlags[RenderStateRow::PolygonOffsetEnabled] = row.GetExpression()->EvalBool(typeChecker);
		else if (row.GetFlag() == "PolygonOffsetFactor")		this->drawFloatFlags[RenderStateRow::PolygonOffsetFactor] = row.GetExpression()->EvalFloat(typeChecker);
		else if (row.GetFlag() == "PolygonOffsetUnits")			this->drawFloatFlags[RenderStateRow::PolygonOffsetUnits] = row.GetExpression()->EvalFloat(typeChecker);
		else if (row.GetFlag() == "MinSampleShading")			this->drawFloatFlags[RenderStateRow::MinSampleShading] = row.GetExpression()->EvalFloat(typeChecker);
		else if (row.GetFlag() == "MinDepthBounds")				this->drawFloatFlags[RenderStateRow::MinDepthBounds] = row.GetExpression()->EvalFloat(typeChecker);
		else if (row.GetFlag() == "MaxDepthBounds")				this->drawFloatFlags[RenderStateRow::MaxDepthBounds] = row.GetExpression()->EvalFloat(typeChecker);
		else if (row.GetFlag() == "LineWidth")					this->drawFloatFlags[RenderStateRow::LineWidth] = row.GetExpression()->EvalFloat(typeChecker);
		else this->invalidExpressionFlags.push_back(row.GetFlag());

		// delete expression
		delete row.GetExpression();
	}

	for (int i = 0; i < this->blendStateRows.size(); i++)
	{
		BlendStateRow& row = this->blendStateRows[i];
		if (row.GetFlag() == "SrcBlend")
		{
			const std::string& value = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal;
			if (value == "Zero")						flagVal = BlendStateRow::Zero;
			else if (value == "One")					flagVal = BlendStateRow::One;
			else if (value == "SrcColor")				flagVal = BlendStateRow::SrcColor;
			else if (value == "OneMinusSrcColor")		flagVal = BlendStateRow::OneMinusSrcColor;
			else if (value == "DstColor")				flagVal = BlendStateRow::DstColor;
			else if (value == "OneMinusDstColor")		flagVal = BlendStateRow::OneMinusDstColor;
			else if (value == "SrcAlpha")				flagVal = BlendStateRow::SrcAlpha;
			else if (value == "OneMinusSrcAlpha")		flagVal = BlendStateRow::OneMinusSrcAlpha;
			else if (value == "DstAlpha")				flagVal = BlendStateRow::DstAlpha;
			else if (value == "OneMinusDstAlpha")		flagVal = BlendStateRow::OneMinusDstAlpha;
			else if (value == "SrcAlphaSaturate")		flagVal = BlendStateRow::SrcAlphaSaturate;
			else if (value == "ConstantColor")			flagVal = BlendStateRow::ConstantColor;
			else if (value == "OneMinusConstantColor")	flagVal = BlendStateRow::OneMinusConstantColor;
			else if (value == "ConstantAlpha")			flagVal = BlendStateRow::ConstantAlpha;
			else if (value == "OneMinusConstantAlpha")	flagVal = BlendStateRow::OneMinusConstantAlpha;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), value };
				this->invalidValues.push_back(foo);
				return;
			}

			int renderTarget = row.GetRenderTarget()->EvalInt(typeChecker);
			if (renderTarget > MaxNumRenderTargets)
			{
				std::string msg = AnyFX::Format("Blend index '%d' must be lower than %d (maximum amount of render targets) in '%s', %s\n", renderTarget, MaxNumRenderTargets, this->name.c_str(), this->ErrorSuffix().c_str());
				typeChecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				this->blendEnumFlags[renderTarget][BlendStateRow::SrcBlend] = flagVal;
			}
		}
		else if (row.GetFlag() == "DstBlend")
		{
			const std::string& value = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal;
			if (value == "Zero")						flagVal = BlendStateRow::Zero;
			else if (value == "One")					flagVal = BlendStateRow::One;
			else if (value == "SrcColor")				flagVal = BlendStateRow::SrcColor;
			else if (value == "OneMinusSrcColor")		flagVal = BlendStateRow::OneMinusSrcColor;
			else if (value == "DstColor")				flagVal = BlendStateRow::DstColor;
			else if (value == "OneMinusDstColor")		flagVal = BlendStateRow::OneMinusDstColor;
			else if (value == "SrcAlpha")				flagVal = BlendStateRow::SrcAlpha;
			else if (value == "OneMinusSrcAlpha")		flagVal = BlendStateRow::OneMinusSrcAlpha;
			else if (value == "DstAlpha")				flagVal = BlendStateRow::DstAlpha;
			else if (value == "OneMinusDstAlpha")		flagVal = BlendStateRow::OneMinusDstAlpha;
			else if (value == "SrcAlphaSaturate")		flagVal = BlendStateRow::SrcAlphaSaturate;
			else if (value == "ConstantColor")			flagVal = BlendStateRow::ConstantColor;
			else if (value == "OneMinusConstantColor")	flagVal = BlendStateRow::OneMinusConstantColor;
			else if (value == "ConstantAlpha")			flagVal = BlendStateRow::ConstantAlpha;
			else if (value == "OneMinusConstantAlpha")	flagVal = BlendStateRow::OneMinusConstantAlpha;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), value };
				this->invalidValues.push_back(foo);
				return;
			}

			int renderTarget = row.GetRenderTarget()->EvalInt(typeChecker);
			if (renderTarget > MaxNumRenderTargets)
			{
				std::string msg = AnyFX::Format("Blend index '%d' must be lower than %d (maximum amount of render targets) in '%s', %s\n", renderTarget, MaxNumRenderTargets, this->name.c_str(), this->ErrorSuffix().c_str());
				typeChecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				this->blendEnumFlags[renderTarget][BlendStateRow::DstBlend] = flagVal;
			}
		}
		else if (row.GetFlag() == "SrcBlendAlpha")
		{
			const std::string& value = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal;
			if (value == "Zero")						flagVal = BlendStateRow::Zero;
			else if (value == "One")					flagVal = BlendStateRow::One;
			else if (value == "SrcColor")				flagVal = BlendStateRow::SrcColor;
			else if (value == "OneMinus")				flagVal = BlendStateRow::OneMinusSrcColor;
			else if (value == "DstColor")				flagVal = BlendStateRow::DstColor;
			else if (value == "OneMinusDstColor")		flagVal = BlendStateRow::OneMinusDstColor;
			else if (value == "SrcAlpha")				flagVal = BlendStateRow::SrcAlpha;
			else if (value == "OneMinusSrcAlpha")		flagVal = BlendStateRow::OneMinusSrcAlpha;
			else if (value == "DstAlpha")				flagVal = BlendStateRow::DstAlpha;
			else if (value == "OneMinusDstAlpha")		flagVal = BlendStateRow::OneMinusDstAlpha;
			else if (value == "SrcAlphaSaturate")		flagVal = BlendStateRow::SrcAlphaSaturate;
			else if (value == "ConstantColor")			flagVal = BlendStateRow::ConstantColor;
			else if (value == "OneMinusConstantColor")	flagVal = BlendStateRow::OneMinusConstantColor;
			else if (value == "ConstantAlpha")			flagVal = BlendStateRow::ConstantAlpha;
			else if (value == "OneMinusConstantAlpha")	flagVal = BlendStateRow::OneMinusConstantAlpha;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), value };
				this->invalidValues.push_back(foo);
				return;
			}

			int renderTarget = row.GetRenderTarget()->EvalInt(typeChecker);
			if (renderTarget > MaxNumRenderTargets)
			{
				std::string msg = AnyFX::Format("Blend index '%d' must be lower than %d (maximum amount of render targets) in '%s', %s\n", renderTarget, MaxNumRenderTargets, this->name.c_str(), this->ErrorSuffix().c_str());
				typeChecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				this->blendEnumFlags[renderTarget][BlendStateRow::SrcBlendAlpha] = flagVal;
			}
		}
		else if (row.GetFlag() == "DstBlendAlpha")
		{
			const std::string& value = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal;
			if (value == "Zero")						flagVal = BlendStateRow::Zero;
			else if (value == "One")					flagVal = BlendStateRow::One;
			else if (value == "SrcColor")				flagVal = BlendStateRow::SrcColor;
			else if (value == "OneMinus")				flagVal = BlendStateRow::OneMinusSrcColor;
			else if (value == "DstColor")				flagVal = BlendStateRow::DstColor;
			else if (value == "OneMinusDstColor")		flagVal = BlendStateRow::OneMinusDstColor;
			else if (value == "SrcAlpha")				flagVal = BlendStateRow::SrcAlpha;
			else if (value == "OneMinusSrcAlpha")		flagVal = BlendStateRow::OneMinusSrcAlpha;
			else if (value == "DstAlpha")				flagVal = BlendStateRow::DstAlpha;
			else if (value == "OneMinusDstAlpha")		flagVal = BlendStateRow::OneMinusDstAlpha;
			else if (value == "SrcAlphaSaturate")		flagVal = BlendStateRow::SrcAlphaSaturate;
			else if (value == "ConstantColor")			flagVal = BlendStateRow::ConstantColor;
			else if (value == "OneMinusConstantColor")	flagVal = BlendStateRow::OneMinusConstantColor;
			else if (value == "ConstantAlpha")			flagVal = BlendStateRow::ConstantAlpha;
			else if (value == "OneMinusConstantAlpha")	flagVal = BlendStateRow::OneMinusConstantAlpha;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), value };
				this->invalidValues.push_back(foo);
				return;
			}

			int renderTarget = row.GetRenderTarget()->EvalInt(typeChecker);
			if (renderTarget > MaxNumRenderTargets)
			{
				std::string msg = AnyFX::Format("Blend index '%d' must be lower than %d (maximum amount of render targets) in '%s', %s\n", renderTarget, MaxNumRenderTargets, this->name.c_str(), this->ErrorSuffix().c_str());
				typeChecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				this->blendEnumFlags[renderTarget][BlendStateRow::DstBlendAlpha] = flagVal;
			}
		}
		else if (row.GetFlag() == "BlendOp")
		{
			const std::string& value = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal;
			if (value == "Add")						flagVal = BlendStateRow::Add;
			else if (value == "Sub")				flagVal = BlendStateRow::Sub;
			else if (value == "InvSub")				flagVal = BlendStateRow::InvSub;
			else if (value == "Min")				flagVal = BlendStateRow::Min;
			else if (value == "Max")				flagVal = BlendStateRow::Max;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), value };
				this->invalidValues.push_back(foo);
				return;
			}

			int renderTarget = row.GetRenderTarget()->EvalInt(typeChecker);
			if (renderTarget > MaxNumRenderTargets)
			{
				std::string msg = AnyFX::Format("Blend index '%d' must be lower than %d (maximum amount of render targets) in '%s', %s\n", renderTarget, MaxNumRenderTargets, this->name.c_str(), this->ErrorSuffix().c_str());
				typeChecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				this->blendEnumFlags[renderTarget][BlendStateRow::BlendOp] = flagVal;
			}
		}
		else if (row.GetFlag() == "BlendOpAlpha")
		{
			const std::string& value = row.GetExpression()->EvalString(typeChecker);
			unsigned flagVal;
			if (value == "Add")						flagVal = BlendStateRow::Add;
			else if (value == "Sub")				flagVal = BlendStateRow::Sub;
			else if (value == "InvSub")				flagVal = BlendStateRow::InvSub;
			else if (value == "Min")				flagVal = BlendStateRow::Min;
			else if (value == "Max")				flagVal = BlendStateRow::Max;
			else
			{
				InvalidValueContainer foo = { row.GetFlag(), value };
				this->invalidValues.push_back(foo);
				return;
			}

			int renderTarget = row.GetRenderTarget()->EvalInt(typeChecker);
			if (renderTarget > MaxNumRenderTargets)
			{
				std::string msg = AnyFX::Format("Blend index '%d' must be lower than %d (maximum amount of render targets) in '%s', %s\n", renderTarget, MaxNumRenderTargets, this->name.c_str(), this->ErrorSuffix().c_str());
				typeChecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				this->blendEnumFlags[renderTarget][BlendStateRow::BlendOpAlpha] = flagVal;
			}
		}
		else if (row.GetFlag() == "BlendEnabled")
		{
			int renderTarget = row.GetRenderTarget()->EvalInt(typeChecker);
			if (renderTarget > MaxNumRenderTargets)
			{
				std::string msg = AnyFX::Format("Blend index '%d' must be lower than %d (maximum amount of render targets) in '%s', %s\n", renderTarget, MaxNumRenderTargets, this->name.c_str(), this->ErrorSuffix().c_str());
				typeChecker.Error(msg, this->GetFile(), this->GetLine());
			}
			else
			{
				this->blendBoolFlags[renderTarget][BlendStateRow::BlendEnabled] = row.GetExpression()->EvalBool(typeChecker);
			}
		}
		else
			this->invalidExpressionFlags.push_back(row.GetFlag());

		delete row.GetExpression();
	}
	this->blendStateRows.clear();
}

} // namespace AnyFX