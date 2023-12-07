

// include std container
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <stack>
#include <tuple>

#include "anyfxtoken.h"
#include "../../code/qualifierexpression.h"
#include "../../code/compileable.h"
#include "../../code/effect.h"
#include "../../code/header.h"
#include "../../code/datatype.h"
#include "../../code/parameter.h"
#include "../../code/annotation.h"
#include "../../code/programrow.h"
#include "../../code/program.h"
#include "../../code/samplertexturelist.h"
#include "../../code/samplerrow.h"
#include "../../code/sampler.h"
#include "../../code/structure.h"
#include "../../code/constant.h"
#include "../../code/blendstaterow.h"
#include "../../code/renderstaterow.h"
#include "../../code/renderstate.h"
#include "../../code/function.h"
#include "../../code/valuelist.h"
#include "../../code/functionattribute.h"
#include "../../code/variable.h"
#include "../../code/varblock.h"
#include "../../code/varbuffer.h"
#include "../../code/subroutine.h"
#include "../../code/preprocessor.h"
#include "../../code/expressions/expression.h"
#include "../../code/expressions/binaryexpression.h"
#include "../../code/expressions/unaryexpression.h"
#include "../../code/expressions/intexpression.h"
#include "../../code/expressions/boolexpression.h"
#include "../../code/expressions/floatexpression.h"
#include "../../code/expressions/symbolexpression.h"
using namespace AnyFX;



// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AnyFXListener.h"


/**
 * This class provides an empty implementation of AnyFXListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AnyFXBaseListener : public AnyFXListener {
public:

  virtual void enterString(AnyFXParser::StringContext * /*ctx*/) override { }
  virtual void exitString(AnyFXParser::StringContext * /*ctx*/) override { }

  virtual void enterBoolean(AnyFXParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(AnyFXParser::BooleanContext * /*ctx*/) override { }

  virtual void enterPreprocess(AnyFXParser::PreprocessContext * /*ctx*/) override { }
  virtual void exitPreprocess(AnyFXParser::PreprocessContext * /*ctx*/) override { }

  virtual void enterEntry(AnyFXParser::EntryContext * /*ctx*/) override { }
  virtual void exitEntry(AnyFXParser::EntryContext * /*ctx*/) override { }

  virtual void enterEffect(AnyFXParser::EffectContext * /*ctx*/) override { }
  virtual void exitEffect(AnyFXParser::EffectContext * /*ctx*/) override { }

  virtual void enterQualifier(AnyFXParser::QualifierContext * /*ctx*/) override { }
  virtual void exitQualifier(AnyFXParser::QualifierContext * /*ctx*/) override { }

  virtual void enterQualifierValued(AnyFXParser::QualifierValuedContext * /*ctx*/) override { }
  virtual void exitQualifierValued(AnyFXParser::QualifierValuedContext * /*ctx*/) override { }

  virtual void enterType(AnyFXParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(AnyFXParser::TypeContext * /*ctx*/) override { }

  virtual void enterQualifierExpression(AnyFXParser::QualifierExpressionContext * /*ctx*/) override { }
  virtual void exitQualifierExpression(AnyFXParser::QualifierExpressionContext * /*ctx*/) override { }

  virtual void enterStructure(AnyFXParser::StructureContext * /*ctx*/) override { }
  virtual void exitStructure(AnyFXParser::StructureContext * /*ctx*/) override { }

  virtual void enterVarblock(AnyFXParser::VarblockContext * /*ctx*/) override { }
  virtual void exitVarblock(AnyFXParser::VarblockContext * /*ctx*/) override { }

  virtual void enterVarbuffer(AnyFXParser::VarbufferContext * /*ctx*/) override { }
  virtual void exitVarbuffer(AnyFXParser::VarbufferContext * /*ctx*/) override { }

  virtual void enterSubroutine(AnyFXParser::SubroutineContext * /*ctx*/) override { }
  virtual void exitSubroutine(AnyFXParser::SubroutineContext * /*ctx*/) override { }

  virtual void enterValueList(AnyFXParser::ValueListContext * /*ctx*/) override { }
  virtual void exitValueList(AnyFXParser::ValueListContext * /*ctx*/) override { }

  virtual void enterValueSingleList(AnyFXParser::ValueSingleListContext * /*ctx*/) override { }
  virtual void exitValueSingleList(AnyFXParser::ValueSingleListContext * /*ctx*/) override { }

  virtual void enterVariable(AnyFXParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(AnyFXParser::VariableContext * /*ctx*/) override { }

  virtual void enterConstant(AnyFXParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(AnyFXParser::ConstantContext * /*ctx*/) override { }

  virtual void enterParameter(AnyFXParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(AnyFXParser::ParameterContext * /*ctx*/) override { }

  virtual void enterParameterList(AnyFXParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(AnyFXParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterFunctionAttribute(AnyFXParser::FunctionAttributeContext * /*ctx*/) override { }
  virtual void exitFunctionAttribute(AnyFXParser::FunctionAttributeContext * /*ctx*/) override { }

  virtual void enterCodeBlock(AnyFXParser::CodeBlockContext * /*ctx*/) override { }
  virtual void exitCodeBlock(AnyFXParser::CodeBlockContext * /*ctx*/) override { }

  virtual void enterFunction(AnyFXParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(AnyFXParser::FunctionContext * /*ctx*/) override { }

  virtual void enterBlendStateRow(AnyFXParser::BlendStateRowContext * /*ctx*/) override { }
  virtual void exitBlendStateRow(AnyFXParser::BlendStateRowContext * /*ctx*/) override { }

  virtual void enterRenderStateRow(AnyFXParser::RenderStateRowContext * /*ctx*/) override { }
  virtual void exitRenderStateRow(AnyFXParser::RenderStateRowContext * /*ctx*/) override { }

  virtual void enterRenderState(AnyFXParser::RenderStateContext * /*ctx*/) override { }
  virtual void exitRenderState(AnyFXParser::RenderStateContext * /*ctx*/) override { }

  virtual void enterSampler(AnyFXParser::SamplerContext * /*ctx*/) override { }
  virtual void exitSampler(AnyFXParser::SamplerContext * /*ctx*/) override { }

  virtual void enterSamplerTextureList(AnyFXParser::SamplerTextureListContext * /*ctx*/) override { }
  virtual void exitSamplerTextureList(AnyFXParser::SamplerTextureListContext * /*ctx*/) override { }

  virtual void enterSamplerRow(AnyFXParser::SamplerRowContext * /*ctx*/) override { }
  virtual void exitSamplerRow(AnyFXParser::SamplerRowContext * /*ctx*/) override { }

  virtual void enterProgramRow(AnyFXParser::ProgramRowContext * /*ctx*/) override { }
  virtual void exitProgramRow(AnyFXParser::ProgramRowContext * /*ctx*/) override { }

  virtual void enterAnnotation(AnyFXParser::AnnotationContext * /*ctx*/) override { }
  virtual void exitAnnotation(AnyFXParser::AnnotationContext * /*ctx*/) override { }

  virtual void enterProgram(AnyFXParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(AnyFXParser::ProgramContext * /*ctx*/) override { }

  virtual void enterExpression(AnyFXParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(AnyFXParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterBinaryexp7(AnyFXParser::Binaryexp7Context * /*ctx*/) override { }
  virtual void exitBinaryexp7(AnyFXParser::Binaryexp7Context * /*ctx*/) override { }

  virtual void enterBinaryexp6(AnyFXParser::Binaryexp6Context * /*ctx*/) override { }
  virtual void exitBinaryexp6(AnyFXParser::Binaryexp6Context * /*ctx*/) override { }

  virtual void enterBinaryexp5(AnyFXParser::Binaryexp5Context * /*ctx*/) override { }
  virtual void exitBinaryexp5(AnyFXParser::Binaryexp5Context * /*ctx*/) override { }

  virtual void enterBinaryexp4(AnyFXParser::Binaryexp4Context * /*ctx*/) override { }
  virtual void exitBinaryexp4(AnyFXParser::Binaryexp4Context * /*ctx*/) override { }

  virtual void enterBinaryexp3(AnyFXParser::Binaryexp3Context * /*ctx*/) override { }
  virtual void exitBinaryexp3(AnyFXParser::Binaryexp3Context * /*ctx*/) override { }

  virtual void enterBinaryexp2(AnyFXParser::Binaryexp2Context * /*ctx*/) override { }
  virtual void exitBinaryexp2(AnyFXParser::Binaryexp2Context * /*ctx*/) override { }

  virtual void enterBinaryexp1(AnyFXParser::Binaryexp1Context * /*ctx*/) override { }
  virtual void exitBinaryexp1(AnyFXParser::Binaryexp1Context * /*ctx*/) override { }

  virtual void enterBinaryexpatom(AnyFXParser::BinaryexpatomContext * /*ctx*/) override { }
  virtual void exitBinaryexpatom(AnyFXParser::BinaryexpatomContext * /*ctx*/) override { }

  virtual void enterParantexpression(AnyFXParser::ParantexpressionContext * /*ctx*/) override { }
  virtual void exitParantexpression(AnyFXParser::ParantexpressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

