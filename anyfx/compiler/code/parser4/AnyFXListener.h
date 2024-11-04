
// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "AnyFXParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AnyFXParser.
 */
class  AnyFXListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterString(AnyFXParser::StringContext *ctx) = 0;
  virtual void exitString(AnyFXParser::StringContext *ctx) = 0;

  virtual void enterBoolean(AnyFXParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(AnyFXParser::BooleanContext *ctx) = 0;

  virtual void enterPreprocess(AnyFXParser::PreprocessContext *ctx) = 0;
  virtual void exitPreprocess(AnyFXParser::PreprocessContext *ctx) = 0;

  virtual void enterEntry(AnyFXParser::EntryContext *ctx) = 0;
  virtual void exitEntry(AnyFXParser::EntryContext *ctx) = 0;

  virtual void enterEffect(AnyFXParser::EffectContext *ctx) = 0;
  virtual void exitEffect(AnyFXParser::EffectContext *ctx) = 0;

  virtual void enterType(AnyFXParser::TypeContext *ctx) = 0;
  virtual void exitType(AnyFXParser::TypeContext *ctx) = 0;

  virtual void enterQualifierExpression(AnyFXParser::QualifierExpressionContext *ctx) = 0;
  virtual void exitQualifierExpression(AnyFXParser::QualifierExpressionContext *ctx) = 0;

  virtual void enterStructure(AnyFXParser::StructureContext *ctx) = 0;
  virtual void exitStructure(AnyFXParser::StructureContext *ctx) = 0;

  virtual void enterVarblock(AnyFXParser::VarblockContext *ctx) = 0;
  virtual void exitVarblock(AnyFXParser::VarblockContext *ctx) = 0;

  virtual void enterVarbuffer(AnyFXParser::VarbufferContext *ctx) = 0;
  virtual void exitVarbuffer(AnyFXParser::VarbufferContext *ctx) = 0;

  virtual void enterSubroutine(AnyFXParser::SubroutineContext *ctx) = 0;
  virtual void exitSubroutine(AnyFXParser::SubroutineContext *ctx) = 0;

  virtual void enterValueList(AnyFXParser::ValueListContext *ctx) = 0;
  virtual void exitValueList(AnyFXParser::ValueListContext *ctx) = 0;

  virtual void enterValueSingleList(AnyFXParser::ValueSingleListContext *ctx) = 0;
  virtual void exitValueSingleList(AnyFXParser::ValueSingleListContext *ctx) = 0;

  virtual void enterVariable(AnyFXParser::VariableContext *ctx) = 0;
  virtual void exitVariable(AnyFXParser::VariableContext *ctx) = 0;

  virtual void enterParameter(AnyFXParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(AnyFXParser::ParameterContext *ctx) = 0;

  virtual void enterParameterList(AnyFXParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(AnyFXParser::ParameterListContext *ctx) = 0;

  virtual void enterFunctionAttribute(AnyFXParser::FunctionAttributeContext *ctx) = 0;
  virtual void exitFunctionAttribute(AnyFXParser::FunctionAttributeContext *ctx) = 0;

  virtual void enterCodeBlock(AnyFXParser::CodeBlockContext *ctx) = 0;
  virtual void exitCodeBlock(AnyFXParser::CodeBlockContext *ctx) = 0;

  virtual void enterFunction(AnyFXParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(AnyFXParser::FunctionContext *ctx) = 0;

  virtual void enterBlendStateRow(AnyFXParser::BlendStateRowContext *ctx) = 0;
  virtual void exitBlendStateRow(AnyFXParser::BlendStateRowContext *ctx) = 0;

  virtual void enterRenderStateRow(AnyFXParser::RenderStateRowContext *ctx) = 0;
  virtual void exitRenderStateRow(AnyFXParser::RenderStateRowContext *ctx) = 0;

  virtual void enterRenderState(AnyFXParser::RenderStateContext *ctx) = 0;
  virtual void exitRenderState(AnyFXParser::RenderStateContext *ctx) = 0;

  virtual void enterSampler(AnyFXParser::SamplerContext *ctx) = 0;
  virtual void exitSampler(AnyFXParser::SamplerContext *ctx) = 0;

  virtual void enterSamplerTextureList(AnyFXParser::SamplerTextureListContext *ctx) = 0;
  virtual void exitSamplerTextureList(AnyFXParser::SamplerTextureListContext *ctx) = 0;

  virtual void enterSamplerRow(AnyFXParser::SamplerRowContext *ctx) = 0;
  virtual void exitSamplerRow(AnyFXParser::SamplerRowContext *ctx) = 0;

  virtual void enterProgramRow(AnyFXParser::ProgramRowContext *ctx) = 0;
  virtual void exitProgramRow(AnyFXParser::ProgramRowContext *ctx) = 0;

  virtual void enterAnnotation(AnyFXParser::AnnotationContext *ctx) = 0;
  virtual void exitAnnotation(AnyFXParser::AnnotationContext *ctx) = 0;

  virtual void enterProgram(AnyFXParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(AnyFXParser::ProgramContext *ctx) = 0;

  virtual void enterExpression(AnyFXParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(AnyFXParser::ExpressionContext *ctx) = 0;

  virtual void enterBinaryexp7(AnyFXParser::Binaryexp7Context *ctx) = 0;
  virtual void exitBinaryexp7(AnyFXParser::Binaryexp7Context *ctx) = 0;

  virtual void enterBinaryexp6(AnyFXParser::Binaryexp6Context *ctx) = 0;
  virtual void exitBinaryexp6(AnyFXParser::Binaryexp6Context *ctx) = 0;

  virtual void enterBinaryexp5(AnyFXParser::Binaryexp5Context *ctx) = 0;
  virtual void exitBinaryexp5(AnyFXParser::Binaryexp5Context *ctx) = 0;

  virtual void enterBinaryexp4(AnyFXParser::Binaryexp4Context *ctx) = 0;
  virtual void exitBinaryexp4(AnyFXParser::Binaryexp4Context *ctx) = 0;

  virtual void enterBinaryexp3(AnyFXParser::Binaryexp3Context *ctx) = 0;
  virtual void exitBinaryexp3(AnyFXParser::Binaryexp3Context *ctx) = 0;

  virtual void enterBinaryexp2(AnyFXParser::Binaryexp2Context *ctx) = 0;
  virtual void exitBinaryexp2(AnyFXParser::Binaryexp2Context *ctx) = 0;

  virtual void enterBinaryexp1(AnyFXParser::Binaryexp1Context *ctx) = 0;
  virtual void exitBinaryexp1(AnyFXParser::Binaryexp1Context *ctx) = 0;

  virtual void enterBinaryexpatom(AnyFXParser::BinaryexpatomContext *ctx) = 0;
  virtual void exitBinaryexpatom(AnyFXParser::BinaryexpatomContext *ctx) = 0;

  virtual void enterParantexpression(AnyFXParser::ParantexpressionContext *ctx) = 0;
  virtual void exitParantexpression(AnyFXParser::ParantexpressionContext *ctx) = 0;


};

