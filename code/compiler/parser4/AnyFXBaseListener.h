

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

  virtual void enterAlias(AnyFXParser::AliasContext * /*ctx*/) override { }
  virtual void exitAlias(AnyFXParser::AliasContext * /*ctx*/) override { }

  virtual void enterAnnotation(AnyFXParser::AnnotationContext * /*ctx*/) override { }
  virtual void exitAnnotation(AnyFXParser::AnnotationContext * /*ctx*/) override { }

  virtual void enterAttribute(AnyFXParser::AttributeContext * /*ctx*/) override { }
  virtual void exitAttribute(AnyFXParser::AttributeContext * /*ctx*/) override { }

  virtual void enterVariable(AnyFXParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(AnyFXParser::VariableContext * /*ctx*/) override { }

  virtual void enterStructureDeclaration(AnyFXParser::StructureDeclarationContext * /*ctx*/) override { }
  virtual void exitStructureDeclaration(AnyFXParser::StructureDeclarationContext * /*ctx*/) override { }

  virtual void enterStructure(AnyFXParser::StructureContext * /*ctx*/) override { }
  virtual void exitStructure(AnyFXParser::StructureContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(AnyFXParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(AnyFXParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterCodeblock(AnyFXParser::CodeblockContext * /*ctx*/) override { }
  virtual void exitCodeblock(AnyFXParser::CodeblockContext * /*ctx*/) override { }

  virtual void enterFunction(AnyFXParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(AnyFXParser::FunctionContext * /*ctx*/) override { }

  virtual void enterProgram(AnyFXParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(AnyFXParser::ProgramContext * /*ctx*/) override { }

  virtual void enterState(AnyFXParser::StateContext * /*ctx*/) override { }
  virtual void exitState(AnyFXParser::StateContext * /*ctx*/) override { }

  virtual void enterDeclaration(AnyFXParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(AnyFXParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterStatement(AnyFXParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(AnyFXParser::StatementContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(AnyFXParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(AnyFXParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterDeclarationStatement(AnyFXParser::DeclarationStatementContext * /*ctx*/) override { }
  virtual void exitDeclarationStatement(AnyFXParser::DeclarationStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(AnyFXParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(AnyFXParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(AnyFXParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(AnyFXParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterForRangeStatement(AnyFXParser::ForRangeStatementContext * /*ctx*/) override { }
  virtual void exitForRangeStatement(AnyFXParser::ForRangeStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(AnyFXParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(AnyFXParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterScopeStatement(AnyFXParser::ScopeStatementContext * /*ctx*/) override { }
  virtual void exitScopeStatement(AnyFXParser::ScopeStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(AnyFXParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(AnyFXParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterContinueStatement(AnyFXParser::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(AnyFXParser::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(AnyFXParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(AnyFXParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(AnyFXParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(AnyFXParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterExpression(AnyFXParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(AnyFXParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterBinaryexp12(AnyFXParser::Binaryexp12Context * /*ctx*/) override { }
  virtual void exitBinaryexp12(AnyFXParser::Binaryexp12Context * /*ctx*/) override { }

  virtual void enterBinaryexp11(AnyFXParser::Binaryexp11Context * /*ctx*/) override { }
  virtual void exitBinaryexp11(AnyFXParser::Binaryexp11Context * /*ctx*/) override { }

  virtual void enterBinaryexp10(AnyFXParser::Binaryexp10Context * /*ctx*/) override { }
  virtual void exitBinaryexp10(AnyFXParser::Binaryexp10Context * /*ctx*/) override { }

  virtual void enterBinaryexp9(AnyFXParser::Binaryexp9Context * /*ctx*/) override { }
  virtual void exitBinaryexp9(AnyFXParser::Binaryexp9Context * /*ctx*/) override { }

  virtual void enterBinaryexp8(AnyFXParser::Binaryexp8Context * /*ctx*/) override { }
  virtual void exitBinaryexp8(AnyFXParser::Binaryexp8Context * /*ctx*/) override { }

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

  virtual void enterBinaryexp0(AnyFXParser::Binaryexp0Context * /*ctx*/) override { }
  virtual void exitBinaryexp0(AnyFXParser::Binaryexp0Context * /*ctx*/) override { }

  virtual void enterBinaryexpatom(AnyFXParser::BinaryexpatomContext * /*ctx*/) override { }
  virtual void exitBinaryexpatom(AnyFXParser::BinaryexpatomContext * /*ctx*/) override { }

  virtual void enterParantExpression(AnyFXParser::ParantExpressionContext * /*ctx*/) override { }
  virtual void exitParantExpression(AnyFXParser::ParantExpressionContext * /*ctx*/) override { }

  virtual void enterCallExpression(AnyFXParser::CallExpressionContext * /*ctx*/) override { }
  virtual void exitCallExpression(AnyFXParser::CallExpressionContext * /*ctx*/) override { }

  virtual void enterAccessExpression(AnyFXParser::AccessExpressionContext * /*ctx*/) override { }
  virtual void exitAccessExpression(AnyFXParser::AccessExpressionContext * /*ctx*/) override { }

  virtual void enterArrayIndexExpression(AnyFXParser::ArrayIndexExpressionContext * /*ctx*/) override { }
  virtual void exitArrayIndexExpression(AnyFXParser::ArrayIndexExpressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

