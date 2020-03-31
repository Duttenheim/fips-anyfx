#pragma once
//------------------------------------------------------------------------------
/**
    @class DrawState
    
    A draw state encapsulates an entire GPU state to be applied before rendering.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "renderstaterow.h"
#include "blendstaterow.h"
#include "symbol.h"
#include "annotation.h"
namespace AnyFX
{

class RenderState : public Symbol
{
public:

	/// constructor
	RenderState();
	/// destructor
	virtual ~RenderState();

	/// set annotation
	void SetAnnotation(const Annotation& annotation);

	/// consumes a draw state row
	void ConsumeRenderRow(const RenderStateRow& row);
	/// consumes a blend state row
	void ConsumeBlendRow(const BlendStateRow& row);

	/// type checks render state
	void TypeCheck(TypeChecker& typechecker);
	/// compiles render state
	void Compile(BinWriter& writer);

	/// currently the upper limit of render targets is 8
	static const int MaxNumRenderTargets = 8;

private:

	/// go through render state and blend state rows and evaluate
	void EvaluateEntries(TypeChecker& typechecker);

	struct InvalidValueContainer
	{
		std::string flag;
		std::string value;
	};

	std::vector<RenderStateRow> renderStateRows;
	std::vector<BlendStateRow> blendStateRows;

	std::vector<std::string> invalidExpressionFlags;
	std::vector<std::string> invalidStringFlags;
	std::vector<InvalidValueContainer> invalidValues;

	int blendEnumFlags[MaxNumRenderTargets][BlendStateRow::NumEnumFlags];
	bool blendBoolFlags[MaxNumRenderTargets][BlendStateRow::NumBoolFlags];

	int drawIntFlags[RenderStateRow::NumIntFlags];
	unsigned drawUintFlags[RenderStateRow::NumUintFlags];
	bool drawBoolFlags[RenderStateRow::NumBoolFlags];
	float drawFloatFlags[RenderStateRow::NumFloatFlags];

	int drawEnumFlags[RenderStateRow::NumEnumFlags];
	

	bool hasAnnotation;
	Annotation annotation;
}; 

} // namespace AnyFX
//------------------------------------------------------------------------------