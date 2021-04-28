

// include std container
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <stack>
#include <tuple>

#include "anyfxtoken.h"
#include "ast/alias.h"
#include "ast/annotation.h"
#include "ast/effect.h"
#include "ast/function.h"
#include "ast/program.h"
#include "ast/renderstate.h"
#include "ast/samplerstate.h"
#include "ast/state.h"
#include "ast/structure.h"
#include "ast/symbol.h"
#include "ast/variable.h"
#include "ast/statements/breakstatement.h"
#include "ast/statements/continuestatement.h"
#include "ast/statements/declarationstatement.h"
#include "ast/statements/expressionstatement.h"
#include "ast/statements/forstatement.h"
#include "ast/statements/ifstatement.h"
#include "ast/statements/returnstatement.h"
#include "ast/statements/scopestatement.h"
#include "ast/statements/statement.h"
#include "ast/statements/switchstatement.h"
#include "ast/statements/whilestatement.h"
#include "ast/expressions/accessexpression.h"
#include "ast/expressions/accessexpression.h"
#include "ast/expressions/arrayindexexpression.h"
#include "ast/expressions/binaryexpression.h"
#include "ast/expressions/boolexpression.h"
#include "ast/expressions/callexpression.h"
#include "ast/expressions/expression.h"
#include "ast/expressions/floatexpression.h"
#include "ast/expressions/intexpression.h"
#include "ast/expressions/stringexpression.h"
#include "ast/expressions/symbolexpression.h"
#include "ast/expressions/ternaryexpression.h"
#include "ast/expressions/unaryexpression.h"

using namespace AnyFX;



// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.7.1

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

  virtual void enterAlias(AnyFXParser::AliasContext *ctx) = 0;
  virtual void exitAlias(AnyFXParser::AliasContext *ctx) = 0;

  virtual void enterAnnotation(AnyFXParser::AnnotationContext *ctx) = 0;
  virtual void exitAnnotation(AnyFXParser::AnnotationContext *ctx) = 0;

  virtual void enterAttribute(AnyFXParser::AttributeContext *ctx) = 0;
  virtual void exitAttribute(AnyFXParser::AttributeContext *ctx) = 0;

  virtual void enterVariable(AnyFXParser::VariableContext *ctx) = 0;
  virtual void exitVariable(AnyFXParser::VariableContext *ctx) = 0;

  virtual void enterStructureDeclaration(AnyFXParser::StructureDeclarationContext *ctx) = 0;
  virtual void exitStructureDeclaration(AnyFXParser::StructureDeclarationContext *ctx) = 0;

  virtual void enterStructure(AnyFXParser::StructureContext *ctx) = 0;
  virtual void exitStructure(AnyFXParser::StructureContext *ctx) = 0;

  virtual void enterFunctionDeclaration(AnyFXParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(AnyFXParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterCodeblock(AnyFXParser::CodeblockContext *ctx) = 0;
  virtual void exitCodeblock(AnyFXParser::CodeblockContext *ctx) = 0;

  virtual void enterFunction(AnyFXParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(AnyFXParser::FunctionContext *ctx) = 0;

  virtual void enterProgram(AnyFXParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(AnyFXParser::ProgramContext *ctx) = 0;

  virtual void enterState(AnyFXParser::StateContext *ctx) = 0;
  virtual void exitState(AnyFXParser::StateContext *ctx) = 0;

  virtual void enterDeclaration(AnyFXParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(AnyFXParser::DeclarationContext *ctx) = 0;

  virtual void enterStatement(AnyFXParser::StatementContext *ctx) = 0;
  virtual void exitStatement(AnyFXParser::StatementContext *ctx) = 0;

  virtual void enterExpressionStatement(AnyFXParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(AnyFXParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterDeclarationStatement(AnyFXParser::DeclarationStatementContext *ctx) = 0;
  virtual void exitDeclarationStatement(AnyFXParser::DeclarationStatementContext *ctx) = 0;

  virtual void enterIfStatement(AnyFXParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(AnyFXParser::IfStatementContext *ctx) = 0;

  virtual void enterForStatement(AnyFXParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(AnyFXParser::ForStatementContext *ctx) = 0;

  virtual void enterForRangeStatement(AnyFXParser::ForRangeStatementContext *ctx) = 0;
  virtual void exitForRangeStatement(AnyFXParser::ForRangeStatementContext *ctx) = 0;

  virtual void enterWhileStatement(AnyFXParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(AnyFXParser::WhileStatementContext *ctx) = 0;

  virtual void enterScopeStatement(AnyFXParser::ScopeStatementContext *ctx) = 0;
  virtual void exitScopeStatement(AnyFXParser::ScopeStatementContext *ctx) = 0;

  virtual void enterReturnStatement(AnyFXParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(AnyFXParser::ReturnStatementContext *ctx) = 0;

  virtual void enterContinueStatement(AnyFXParser::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(AnyFXParser::ContinueStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(AnyFXParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(AnyFXParser::SwitchStatementContext *ctx) = 0;

  virtual void enterBreakStatement(AnyFXParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(AnyFXParser::BreakStatementContext *ctx) = 0;

  virtual void enterExpression(AnyFXParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(AnyFXParser::ExpressionContext *ctx) = 0;

  virtual void enterBinaryexp12(AnyFXParser::Binaryexp12Context *ctx) = 0;
  virtual void exitBinaryexp12(AnyFXParser::Binaryexp12Context *ctx) = 0;

  virtual void enterBinaryexp11(AnyFXParser::Binaryexp11Context *ctx) = 0;
  virtual void exitBinaryexp11(AnyFXParser::Binaryexp11Context *ctx) = 0;

  virtual void enterBinaryexp10(AnyFXParser::Binaryexp10Context *ctx) = 0;
  virtual void exitBinaryexp10(AnyFXParser::Binaryexp10Context *ctx) = 0;

  virtual void enterBinaryexp9(AnyFXParser::Binaryexp9Context *ctx) = 0;
  virtual void exitBinaryexp9(AnyFXParser::Binaryexp9Context *ctx) = 0;

  virtual void enterBinaryexp8(AnyFXParser::Binaryexp8Context *ctx) = 0;
  virtual void exitBinaryexp8(AnyFXParser::Binaryexp8Context *ctx) = 0;

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

  virtual void enterBinaryexp0(AnyFXParser::Binaryexp0Context *ctx) = 0;
  virtual void exitBinaryexp0(AnyFXParser::Binaryexp0Context *ctx) = 0;

  virtual void enterBinaryexpatom(AnyFXParser::BinaryexpatomContext *ctx) = 0;
  virtual void exitBinaryexpatom(AnyFXParser::BinaryexpatomContext *ctx) = 0;

  virtual void enterParantExpression(AnyFXParser::ParantExpressionContext *ctx) = 0;
  virtual void exitParantExpression(AnyFXParser::ParantExpressionContext *ctx) = 0;

  virtual void enterCallExpression(AnyFXParser::CallExpressionContext *ctx) = 0;
  virtual void exitCallExpression(AnyFXParser::CallExpressionContext *ctx) = 0;

  virtual void enterAccessExpression(AnyFXParser::AccessExpressionContext *ctx) = 0;
  virtual void exitAccessExpression(AnyFXParser::AccessExpressionContext *ctx) = 0;

  virtual void enterArrayIndexExpression(AnyFXParser::ArrayIndexExpressionContext *ctx) = 0;
  virtual void exitArrayIndexExpression(AnyFXParser::ArrayIndexExpressionContext *ctx) = 0;


};

