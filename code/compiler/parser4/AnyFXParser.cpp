

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


#include "AnyFXListener.h"

#include "AnyFXParser.h"


using namespace antlrcpp;
using namespace antlr4;

AnyFXParser::AnyFXParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AnyFXParser::~AnyFXParser() {
  delete _interpreter;
}

std::string AnyFXParser::getGrammarFileName() const {
  return "AnyFX.g4";
}

const std::vector<std::string>& AnyFXParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AnyFXParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StringContext ------------------------------------------------------------------

AnyFXParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::StringContext::getRuleIndex() const {
  return AnyFXParser::RuleString;
}

void AnyFXParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void AnyFXParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

AnyFXParser::StringContext* AnyFXParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 0, AnyFXParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(114);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::QO: {
        enterOuterAlt(_localctx, 1);
        setState(96);
        match(AnyFXParser::QO);
        setState(101);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__2)
          | (1ULL << AnyFXParser::T__3)
          | (1ULL << AnyFXParser::T__4)
          | (1ULL << AnyFXParser::T__5)
          | (1ULL << AnyFXParser::T__6)
          | (1ULL << AnyFXParser::T__7)
          | (1ULL << AnyFXParser::T__8)
          | (1ULL << AnyFXParser::T__9)
          | (1ULL << AnyFXParser::T__10)
          | (1ULL << AnyFXParser::T__11)
          | (1ULL << AnyFXParser::T__12)
          | (1ULL << AnyFXParser::T__13)
          | (1ULL << AnyFXParser::T__14)
          | (1ULL << AnyFXParser::T__15)
          | (1ULL << AnyFXParser::T__16)
          | (1ULL << AnyFXParser::T__17)
          | (1ULL << AnyFXParser::T__18)
          | (1ULL << AnyFXParser::T__19)
          | (1ULL << AnyFXParser::T__20)
          | (1ULL << AnyFXParser::T__21)
          | (1ULL << AnyFXParser::T__22)
          | (1ULL << AnyFXParser::T__23)
          | (1ULL << AnyFXParser::T__24)
          | (1ULL << AnyFXParser::T__25)
          | (1ULL << AnyFXParser::T__26)
          | (1ULL << AnyFXParser::T__27)
          | (1ULL << AnyFXParser::T__28)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::SC)
          | (1ULL << AnyFXParser::CO)
          | (1ULL << AnyFXParser::COL)
          | (1ULL << AnyFXParser::LP)
          | (1ULL << AnyFXParser::RP)
          | (1ULL << AnyFXParser::LB)
          | (1ULL << AnyFXParser::RB)
          | (1ULL << AnyFXParser::LL)
          | (1ULL << AnyFXParser::RR)
          | (1ULL << AnyFXParser::DOT)
          | (1ULL << AnyFXParser::NOT)
          | (1ULL << AnyFXParser::EQ)
          | (1ULL << AnyFXParser::QU)
          | (1ULL << AnyFXParser::AND)
          | (1ULL << AnyFXParser::ANDSET)
          | (1ULL << AnyFXParser::OR)
          | (1ULL << AnyFXParser::ORSET)
          | (1ULL << AnyFXParser::XOR)
          | (1ULL << AnyFXParser::XORSET)
          | (1ULL << AnyFXParser::CONNJUGATE)
          | (1ULL << AnyFXParser::Q)
          | (1ULL << AnyFXParser::NU)
          | (1ULL << AnyFXParser::FORWARDSLASH)
          | (1ULL << AnyFXParser::LESS)
          | (1ULL << AnyFXParser::LESSEQ)
          | (1ULL << AnyFXParser::GREATER)
          | (1ULL << AnyFXParser::GREATEREQ)
          | (1ULL << AnyFXParser::LOGICEQ)
          | (1ULL << AnyFXParser::NOTEQ)
          | (1ULL << AnyFXParser::LOGICAND)
          | (1ULL << AnyFXParser::LOGICOR))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
          | (1ULL << (AnyFXParser::SOBAKA - 64))
          | (1ULL << (AnyFXParser::ADD_OP - 64))
          | (1ULL << (AnyFXParser::SUB_OP - 64))
          | (1ULL << (AnyFXParser::DIV_OP - 64))
          | (1ULL << (AnyFXParser::MUL_OP - 64))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 64))
          | (1ULL << (AnyFXParser::COMMENT - 64))
          | (1ULL << (AnyFXParser::ML_COMMENT - 64))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 64))
          | (1ULL << (AnyFXParser::EXPONENT - 64))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 64))
          | (1ULL << (AnyFXParser::HEX - 64))
          | (1ULL << (AnyFXParser::IDENTIFIER - 64))
          | (1ULL << (AnyFXParser::WS - 64)))) != 0)) {
          setState(97);
          dynamic_cast<StringContext *>(_localctx)->data = _input->LT(1);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::QO)) {
            dynamic_cast<StringContext *>(_localctx)->data = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
           _localctx->val.append((dynamic_cast<StringContext *>(_localctx)->data != nullptr ? dynamic_cast<StringContext *>(_localctx)->data->getText() : "")); 
          setState(103);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(104);
        match(AnyFXParser::QO);
        break;
      }

      case AnyFXParser::Q: {
        enterOuterAlt(_localctx, 2);
        setState(105);
        match(AnyFXParser::Q);
        setState(110);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__2)
          | (1ULL << AnyFXParser::T__3)
          | (1ULL << AnyFXParser::T__4)
          | (1ULL << AnyFXParser::T__5)
          | (1ULL << AnyFXParser::T__6)
          | (1ULL << AnyFXParser::T__7)
          | (1ULL << AnyFXParser::T__8)
          | (1ULL << AnyFXParser::T__9)
          | (1ULL << AnyFXParser::T__10)
          | (1ULL << AnyFXParser::T__11)
          | (1ULL << AnyFXParser::T__12)
          | (1ULL << AnyFXParser::T__13)
          | (1ULL << AnyFXParser::T__14)
          | (1ULL << AnyFXParser::T__15)
          | (1ULL << AnyFXParser::T__16)
          | (1ULL << AnyFXParser::T__17)
          | (1ULL << AnyFXParser::T__18)
          | (1ULL << AnyFXParser::T__19)
          | (1ULL << AnyFXParser::T__20)
          | (1ULL << AnyFXParser::T__21)
          | (1ULL << AnyFXParser::T__22)
          | (1ULL << AnyFXParser::T__23)
          | (1ULL << AnyFXParser::T__24)
          | (1ULL << AnyFXParser::T__25)
          | (1ULL << AnyFXParser::T__26)
          | (1ULL << AnyFXParser::T__27)
          | (1ULL << AnyFXParser::T__28)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::SC)
          | (1ULL << AnyFXParser::CO)
          | (1ULL << AnyFXParser::COL)
          | (1ULL << AnyFXParser::LP)
          | (1ULL << AnyFXParser::RP)
          | (1ULL << AnyFXParser::LB)
          | (1ULL << AnyFXParser::RB)
          | (1ULL << AnyFXParser::LL)
          | (1ULL << AnyFXParser::RR)
          | (1ULL << AnyFXParser::DOT)
          | (1ULL << AnyFXParser::NOT)
          | (1ULL << AnyFXParser::EQ)
          | (1ULL << AnyFXParser::QO)
          | (1ULL << AnyFXParser::QU)
          | (1ULL << AnyFXParser::AND)
          | (1ULL << AnyFXParser::ANDSET)
          | (1ULL << AnyFXParser::OR)
          | (1ULL << AnyFXParser::ORSET)
          | (1ULL << AnyFXParser::XOR)
          | (1ULL << AnyFXParser::XORSET)
          | (1ULL << AnyFXParser::CONNJUGATE)
          | (1ULL << AnyFXParser::NU)
          | (1ULL << AnyFXParser::FORWARDSLASH)
          | (1ULL << AnyFXParser::LESS)
          | (1ULL << AnyFXParser::LESSEQ)
          | (1ULL << AnyFXParser::GREATER)
          | (1ULL << AnyFXParser::GREATEREQ)
          | (1ULL << AnyFXParser::LOGICEQ)
          | (1ULL << AnyFXParser::NOTEQ)
          | (1ULL << AnyFXParser::LOGICAND)
          | (1ULL << AnyFXParser::LOGICOR))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
          | (1ULL << (AnyFXParser::SOBAKA - 64))
          | (1ULL << (AnyFXParser::ADD_OP - 64))
          | (1ULL << (AnyFXParser::SUB_OP - 64))
          | (1ULL << (AnyFXParser::DIV_OP - 64))
          | (1ULL << (AnyFXParser::MUL_OP - 64))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 64))
          | (1ULL << (AnyFXParser::COMMENT - 64))
          | (1ULL << (AnyFXParser::ML_COMMENT - 64))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 64))
          | (1ULL << (AnyFXParser::EXPONENT - 64))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 64))
          | (1ULL << (AnyFXParser::HEX - 64))
          | (1ULL << (AnyFXParser::IDENTIFIER - 64))
          | (1ULL << (AnyFXParser::WS - 64)))) != 0)) {
          setState(106);
          dynamic_cast<StringContext *>(_localctx)->data = _input->LT(1);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::Q)) {
            dynamic_cast<StringContext *>(_localctx)->data = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
           _localctx->val.append((dynamic_cast<StringContext *>(_localctx)->data != nullptr ? dynamic_cast<StringContext *>(_localctx)->data->getText() : "")); 
          setState(112);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(113);
        match(AnyFXParser::Q);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

AnyFXParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::BooleanContext::getRuleIndex() const {
  return AnyFXParser::RuleBoolean;
}

void AnyFXParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void AnyFXParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}

AnyFXParser::BooleanContext* AnyFXParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 2, AnyFXParser::RuleBoolean);

          dynamic_cast<BooleanContext *>(_localctx)->val =  false;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(116);
        match(AnyFXParser::T__0);
         dynamic_cast<BooleanContext *>(_localctx)->val =  true; 
        break;
      }

      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(118);
        match(AnyFXParser::T__1);
         dynamic_cast<BooleanContext *>(_localctx)->val =  false; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreprocessContext ------------------------------------------------------------------

AnyFXParser::PreprocessContext::PreprocessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::PreprocessContext::EOF() {
  return getToken(AnyFXParser::EOF, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::PreprocessContext::INTEGERLITERAL() {
  return getTokens(AnyFXParser::INTEGERLITERAL);
}

tree::TerminalNode* AnyFXParser::PreprocessContext::INTEGERLITERAL(size_t i) {
  return getToken(AnyFXParser::INTEGERLITERAL, i);
}

std::vector<AnyFXParser::StringContext *> AnyFXParser::PreprocessContext::string() {
  return getRuleContexts<AnyFXParser::StringContext>();
}

AnyFXParser::StringContext* AnyFXParser::PreprocessContext::string(size_t i) {
  return getRuleContext<AnyFXParser::StringContext>(i);
}


size_t AnyFXParser::PreprocessContext::getRuleIndex() const {
  return AnyFXParser::RulePreprocess;
}

void AnyFXParser::PreprocessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreprocess(this);
}

void AnyFXParser::PreprocessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreprocess(this);
}

AnyFXParser::PreprocessContext* AnyFXParser::preprocess() {
  PreprocessContext *_localctx = _tracker.createInstance<PreprocessContext>(_ctx, getState());
  enterRule(_localctx, 4, AnyFXParser::RulePreprocess);

          Token* start = nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(129);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
           start = _input->LT(1); 
          setState(123);
          match(AnyFXParser::T__2);
          setState(124);
          dynamic_cast<PreprocessContext *>(_localctx)->line = match(AnyFXParser::INTEGERLITERAL);
          setState(125);
          dynamic_cast<PreprocessContext *>(_localctx)->path = string();
           lines.push_back(std::make_tuple(atoi((dynamic_cast<PreprocessContext *>(_localctx)->line != nullptr ? dynamic_cast<PreprocessContext *>(_localctx)->line->getText() : "").c_str()), _input->LT(-1)->getLine(), start->getStartIndex(), _input->LT(1)->getStartIndex(), (dynamic_cast<PreprocessContext *>(_localctx)->path != nullptr ? _input->getText(dynamic_cast<PreprocessContext *>(_localctx)->path->start, dynamic_cast<PreprocessContext *>(_localctx)->path->stop) : nullptr))); 
          break;
        }

        case 2: {
          setState(128);
          matchWildcard();
          break;
        }

        } 
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(134);
    match(AnyFXParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntryContext ------------------------------------------------------------------

AnyFXParser::EntryContext::EntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::EffectContext* AnyFXParser::EntryContext::effect() {
  return getRuleContext<AnyFXParser::EffectContext>(0);
}

tree::TerminalNode* AnyFXParser::EntryContext::EOF() {
  return getToken(AnyFXParser::EOF, 0);
}


size_t AnyFXParser::EntryContext::getRuleIndex() const {
  return AnyFXParser::RuleEntry;
}

void AnyFXParser::EntryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntry(this);
}

void AnyFXParser::EntryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntry(this);
}

AnyFXParser::EntryContext* AnyFXParser::entry() {
  EntryContext *_localctx = _tracker.createInstance<EntryContext>(_ctx, getState());
  enterRule(_localctx, 6, AnyFXParser::RuleEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    dynamic_cast<EntryContext *>(_localctx)->effectContext = effect();

            dynamic_cast<EntryContext *>(_localctx)->returnEffect =  dynamic_cast<EntryContext *>(_localctx)->effectContext->eff;
        
    setState(138);
    match(AnyFXParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EffectContext ------------------------------------------------------------------

AnyFXParser::EffectContext::EffectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::AliasContext *> AnyFXParser::EffectContext::alias() {
  return getRuleContexts<AnyFXParser::AliasContext>();
}

AnyFXParser::AliasContext* AnyFXParser::EffectContext::alias(size_t i) {
  return getRuleContext<AnyFXParser::AliasContext>(i);
}

std::vector<AnyFXParser::FunctionDeclarationContext *> AnyFXParser::EffectContext::functionDeclaration() {
  return getRuleContexts<AnyFXParser::FunctionDeclarationContext>();
}

AnyFXParser::FunctionDeclarationContext* AnyFXParser::EffectContext::functionDeclaration(size_t i) {
  return getRuleContext<AnyFXParser::FunctionDeclarationContext>(i);
}

std::vector<AnyFXParser::FunctionContext *> AnyFXParser::EffectContext::function() {
  return getRuleContexts<AnyFXParser::FunctionContext>();
}

AnyFXParser::FunctionContext* AnyFXParser::EffectContext::function(size_t i) {
  return getRuleContext<AnyFXParser::FunctionContext>(i);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::EffectContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::EffectContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}

std::vector<AnyFXParser::StructureContext *> AnyFXParser::EffectContext::structure() {
  return getRuleContexts<AnyFXParser::StructureContext>();
}

AnyFXParser::StructureContext* AnyFXParser::EffectContext::structure(size_t i) {
  return getRuleContext<AnyFXParser::StructureContext>(i);
}

std::vector<AnyFXParser::StateContext *> AnyFXParser::EffectContext::state() {
  return getRuleContexts<AnyFXParser::StateContext>();
}

AnyFXParser::StateContext* AnyFXParser::EffectContext::state(size_t i) {
  return getRuleContext<AnyFXParser::StateContext>(i);
}

std::vector<AnyFXParser::ProgramContext *> AnyFXParser::EffectContext::program() {
  return getRuleContexts<AnyFXParser::ProgramContext>();
}

AnyFXParser::ProgramContext* AnyFXParser::EffectContext::program(size_t i) {
  return getRuleContext<AnyFXParser::ProgramContext>(i);
}


size_t AnyFXParser::EffectContext::getRuleIndex() const {
  return AnyFXParser::RuleEffect;
}

void AnyFXParser::EffectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEffect(this);
}

void AnyFXParser::EffectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEffect(this);
}

AnyFXParser::EffectContext* AnyFXParser::effect() {
  EffectContext *_localctx = _tracker.createInstance<EffectContext>(_ctx, getState());
  enterRule(_localctx, 8, AnyFXParser::RuleEffect);

          dynamic_cast<EffectContext *>(_localctx)->eff =  new Effect();
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(169);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(167);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(140);
          dynamic_cast<EffectContext *>(_localctx)->aliasContext = alias();
          setState(141);
          match(AnyFXParser::SC);
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->aliasContext->sym); 
          break;
        }

        case 2: {
          setState(144);
          dynamic_cast<EffectContext *>(_localctx)->functionDeclarationContext = functionDeclaration();
          setState(145);
          match(AnyFXParser::SC);
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->functionDeclarationContext->sym); 
          break;
        }

        case 3: {
          setState(148);
          dynamic_cast<EffectContext *>(_localctx)->functionContext = function();
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->functionContext->sym); 
          break;
        }

        case 4: {
          setState(151);
          dynamic_cast<EffectContext *>(_localctx)->variableContext = variable();
          setState(152);
          match(AnyFXParser::SC);
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->variableContext->sym); 
          break;
        }

        case 5: {
          setState(155);
          dynamic_cast<EffectContext *>(_localctx)->structureContext = structure();
          setState(156);
          match(AnyFXParser::SC);
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->structureContext->sym); 
          break;
        }

        case 6: {
          setState(159);
          dynamic_cast<EffectContext *>(_localctx)->stateContext = state();
          setState(160);
          match(AnyFXParser::SC);
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->stateContext->sym); 
          break;
        }

        case 7: {
          setState(163);
          dynamic_cast<EffectContext *>(_localctx)->programContext = program();
          setState(164);
          match(AnyFXParser::SC);
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->programContext->sym); 
          break;
        }

        } 
      }
      setState(171);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasContext ------------------------------------------------------------------

AnyFXParser::AliasContext::AliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::AliasContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::AliasContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}


size_t AnyFXParser::AliasContext::getRuleIndex() const {
  return AnyFXParser::RuleAlias;
}

void AnyFXParser::AliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlias(this);
}

void AnyFXParser::AliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlias(this);
}

AnyFXParser::AliasContext* AnyFXParser::alias() {
  AliasContext *_localctx = _tracker.createInstance<AliasContext>(_ctx, getState());
  enterRule(_localctx, 10, AnyFXParser::RuleAlias);

          dynamic_cast<AliasContext *>(_localctx)->sym =  nullptr;
          std::string name;
          std::string type;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(AnyFXParser::T__3);
    setState(173);
    dynamic_cast<AliasContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
    setState(174);
    match(AnyFXParser::T__4);
    setState(175);
    dynamic_cast<AliasContext *>(_localctx)->type = match(AnyFXParser::IDENTIFIER);
     name = (dynamic_cast<AliasContext *>(_localctx)->name != nullptr ? dynamic_cast<AliasContext *>(_localctx)->name->getText() : ""); type = (dynamic_cast<AliasContext *>(_localctx)->type != nullptr ? dynamic_cast<AliasContext *>(_localctx)->type->getText() : ""); 

            dynamic_cast<AliasContext *>(_localctx)->sym =  new Alias();
            _localctx->sym->name = name;
            _localctx->sym->type = type;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

AnyFXParser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::AnnotationContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::ExpressionContext* AnyFXParser::AnnotationContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::AnnotationContext::getRuleIndex() const {
  return AnyFXParser::RuleAnnotation;
}

void AnyFXParser::AnnotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotation(this);
}

void AnyFXParser::AnnotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotation(this);
}

AnyFXParser::AnnotationContext* AnyFXParser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 12, AnyFXParser::RuleAnnotation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    match(AnyFXParser::SOBAKA);

    setState(180);
    dynamic_cast<AnnotationContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
    setState(181);
    match(AnyFXParser::LP);
    setState(182);
    dynamic_cast<AnnotationContext *>(_localctx)->value = expression();
    setState(183);
    match(AnyFXParser::RP);
     _localctx->annot.name = (dynamic_cast<AnnotationContext *>(_localctx)->name != nullptr ? dynamic_cast<AnnotationContext *>(_localctx)->name->getText() : ""); _localctx->annot.value = dynamic_cast<AnnotationContext *>(_localctx)->value->tree; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeContext ------------------------------------------------------------------

AnyFXParser::AttributeContext::AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::AttributeContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::AttributeContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}


size_t AnyFXParser::AttributeContext::getRuleIndex() const {
  return AnyFXParser::RuleAttribute;
}

void AnyFXParser::AttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute(this);
}

void AnyFXParser::AttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute(this);
}

AnyFXParser::AttributeContext* AnyFXParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 14, AnyFXParser::RuleAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(186);
      dynamic_cast<AttributeContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
      setState(187);
      match(AnyFXParser::LP);
      setState(188);
      dynamic_cast<AttributeContext *>(_localctx)->expressionContext = expression();
      setState(189);
      match(AnyFXParser::RP);
       _localctx->attr.name = (dynamic_cast<AttributeContext *>(_localctx)->name != nullptr ? dynamic_cast<AttributeContext *>(_localctx)->name->getText() : ""); _localctx->attr.expression = dynamic_cast<AttributeContext *>(_localctx)->expressionContext->tree; 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(192);
      dynamic_cast<AttributeContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       _localctx->attr.name = (dynamic_cast<AttributeContext *>(_localctx)->name != nullptr ? dynamic_cast<AttributeContext *>(_localctx)->name->getText() : ""); _localctx->attr.expression = nullptr; 
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

AnyFXParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::VariableContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::AnnotationContext *> AnyFXParser::VariableContext::annotation() {
  return getRuleContexts<AnyFXParser::AnnotationContext>();
}

AnyFXParser::AnnotationContext* AnyFXParser::VariableContext::annotation(size_t i) {
  return getRuleContext<AnyFXParser::AnnotationContext>(i);
}

std::vector<AnyFXParser::AttributeContext *> AnyFXParser::VariableContext::attribute() {
  return getRuleContexts<AnyFXParser::AttributeContext>();
}

AnyFXParser::AttributeContext* AnyFXParser::VariableContext::attribute(size_t i) {
  return getRuleContext<AnyFXParser::AttributeContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::VariableContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::VariableContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::VariableContext::getRuleIndex() const {
  return AnyFXParser::RuleVariable;
}

void AnyFXParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void AnyFXParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

AnyFXParser::VariableContext* AnyFXParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 16, AnyFXParser::RuleVariable);

          dynamic_cast<VariableContext *>(_localctx)->sym =  nullptr;
          Symbol::Location location;
          std::vector<Annotation> annotations;
          std::vector<Attribute> attributes;
          std::vector<std::vector<Expression*>> initializers;
          std::vector<std::string> initializerTypes;
          Expression* arraySizeExpression = nullptr;
          bool isArray = false;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(201);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::SOBAKA) {
      setState(196);
      dynamic_cast<VariableContext *>(_localctx)->annotationContext = annotation();
       annotations.push_back(dynamic_cast<VariableContext *>(_localctx)->annotationContext->annot); 
      setState(203);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(209);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(204);
        dynamic_cast<VariableContext *>(_localctx)->attributeContext = attribute();
         attributes.push_back(dynamic_cast<VariableContext *>(_localctx)->attributeContext->attr);  
      }
      setState(211);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(212);
    dynamic_cast<VariableContext *>(_localctx)->type = match(AnyFXParser::IDENTIFIER);
    setState(213);
    dynamic_cast<VariableContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(223);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(215);
      match(AnyFXParser::LL);
      setState(219);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
        | (1ULL << AnyFXParser::T__1)
        | (1ULL << AnyFXParser::T__29)
        | (1ULL << AnyFXParser::T__30)
        | (1ULL << AnyFXParser::LP)
        | (1ULL << AnyFXParser::NOT)
        | (1ULL << AnyFXParser::QO)
        | (1ULL << AnyFXParser::CONNJUGATE)
        | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
        | (1ULL << (AnyFXParser::SUB_OP - 67))
        | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
        | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
        | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
        | (1ULL << (AnyFXParser::HEX - 67))
        | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
        setState(216);
        dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
         arraySizeExpression = dynamic_cast<VariableContext *>(_localctx)->expressionContext->tree; 
      }
      setState(221);
      match(AnyFXParser::RR);
       isArray = true; 
    }
    setState(305);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(225);
      match(AnyFXParser::EQ);
      setState(226);
      match(AnyFXParser::LB);
      setState(227);
      dynamic_cast<VariableContext *>(_localctx)->initType0 = match(AnyFXParser::IDENTIFIER);
       
                      initializerTypes.push_back((dynamic_cast<VariableContext *>(_localctx)->initType0 != nullptr ? dynamic_cast<VariableContext *>(_localctx)->initType0->getText() : "")); 
                      std::vector<Expression*> values0;
                  
      setState(229);
      match(AnyFXParser::LP);

      setState(230);
      dynamic_cast<VariableContext *>(_localctx)->value0 = dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
       values0.push_back(dynamic_cast<VariableContext *>(_localctx)->value0->tree); 
      setState(238);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(232);
        match(AnyFXParser::CO);
        setState(233);
        dynamic_cast<VariableContext *>(_localctx)->valuen = dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
         values0.push_back(dynamic_cast<VariableContext *>(_localctx)->valuen->tree); 
        setState(240);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(241);
      match(AnyFXParser::RP);

                      initializers.push_back(values0);
                  
      setState(263);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(243);
        match(AnyFXParser::CO);
        setState(244);
        dynamic_cast<VariableContext *>(_localctx)->initType1 = match(AnyFXParser::IDENTIFIER);
         
                            initializerTypes.push_back((dynamic_cast<VariableContext *>(_localctx)->initType1 != nullptr ? dynamic_cast<VariableContext *>(_localctx)->initType1->getText() : ""));
                            std::vector<Expression*> values1;
                        
        setState(246);
        match(AnyFXParser::LP);

        setState(247);
        dynamic_cast<VariableContext *>(_localctx)->value1 = dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
         values1.push_back(dynamic_cast<VariableContext *>(_localctx)->value1->tree); 
        setState(255);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AnyFXParser::CO) {
          setState(249);
          match(AnyFXParser::CO);
          setState(250);
          dynamic_cast<VariableContext *>(_localctx)->valuen = dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
           values1.push_back(dynamic_cast<VariableContext *>(_localctx)->valuen->tree); 
          setState(257);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(258);
        match(AnyFXParser::RP);

                            initializers.push_back(values1);
                        
        setState(265);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(266);
      match(AnyFXParser::RB);
      break;
    }

    case 2: {
      setState(268);
      match(AnyFXParser::EQ);
      setState(269);
      match(AnyFXParser::LB);
       
                      initializerTypes.push_back(""); 
                      std::vector<Expression*> values0;
                  
      setState(271);
      match(AnyFXParser::LB);
      setState(275); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(272);
        dynamic_cast<VariableContext *>(_localctx)->value0 = dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
         values0.push_back(dynamic_cast<VariableContext *>(_localctx)->value0->tree); 
        setState(277); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
        | (1ULL << AnyFXParser::T__1)
        | (1ULL << AnyFXParser::T__29)
        | (1ULL << AnyFXParser::T__30)
        | (1ULL << AnyFXParser::LP)
        | (1ULL << AnyFXParser::NOT)
        | (1ULL << AnyFXParser::QO)
        | (1ULL << AnyFXParser::CONNJUGATE)
        | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
        | (1ULL << (AnyFXParser::SUB_OP - 67))
        | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
        | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
        | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
        | (1ULL << (AnyFXParser::HEX - 67))
        | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0));
      setState(279);
      match(AnyFXParser::RB);

                      initializers.push_back(values0);
                  
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(281);
        match(AnyFXParser::CO);
         
                            initializerTypes.push_back("");
                            std::vector<Expression*> values1;
                        
        setState(283);
        match(AnyFXParser::LB);
        setState(287); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(284);
          dynamic_cast<VariableContext *>(_localctx)->value1 = dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
           values1.push_back(dynamic_cast<VariableContext *>(_localctx)->value1->tree); 
          setState(289); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::LP)
          | (1ULL << AnyFXParser::NOT)
          | (1ULL << AnyFXParser::QO)
          | (1ULL << AnyFXParser::CONNJUGATE)
          | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
          | (1ULL << (AnyFXParser::SUB_OP - 67))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
          | (1ULL << (AnyFXParser::HEX - 67))
          | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0));
        setState(291);
        match(AnyFXParser::RB);

                            initializers.push_back(values1);
                        
        setState(298);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(299);
      match(AnyFXParser::RB);
      break;
    }

    case 3: {
      setState(301);
      match(AnyFXParser::EQ);
      setState(302);
      dynamic_cast<VariableContext *>(_localctx)->value = dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
       std::vector<Expression*> expressions { dynamic_cast<VariableContext *>(_localctx)->value->tree }; initializers.push_back(expressions); initializerTypes.push_back(""); 
      break;
    }

    }
     
            dynamic_cast<VariableContext *>(_localctx)->sym =  new Variable(); 
            _localctx->sym->type = (dynamic_cast<VariableContext *>(_localctx)->type != nullptr ? dynamic_cast<VariableContext *>(_localctx)->type->getText() : ""); 
            _localctx->sym->name = (dynamic_cast<VariableContext *>(_localctx)->name != nullptr ? dynamic_cast<VariableContext *>(_localctx)->name->getText() : ""); 
            _localctx->sym->location = location; 
            _localctx->sym->annotations = annotations; 
            _localctx->sym->initializers = initializers;
            _localctx->sym->initializerTypes = initializerTypes;
            _localctx->sym->attributes = attributes;
            _localctx->sym->arraySizeExpression = arraySizeExpression;
            _localctx->sym->isArray = isArray;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureDeclarationContext ------------------------------------------------------------------

AnyFXParser::StructureDeclarationContext::StructureDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::StructureDeclarationContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::AnnotationContext *> AnyFXParser::StructureDeclarationContext::annotation() {
  return getRuleContexts<AnyFXParser::AnnotationContext>();
}

AnyFXParser::AnnotationContext* AnyFXParser::StructureDeclarationContext::annotation(size_t i) {
  return getRuleContext<AnyFXParser::AnnotationContext>(i);
}

std::vector<AnyFXParser::AttributeContext *> AnyFXParser::StructureDeclarationContext::attribute() {
  return getRuleContexts<AnyFXParser::AttributeContext>();
}

AnyFXParser::AttributeContext* AnyFXParser::StructureDeclarationContext::attribute(size_t i) {
  return getRuleContext<AnyFXParser::AttributeContext>(i);
}


size_t AnyFXParser::StructureDeclarationContext::getRuleIndex() const {
  return AnyFXParser::RuleStructureDeclaration;
}

void AnyFXParser::StructureDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructureDeclaration(this);
}

void AnyFXParser::StructureDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructureDeclaration(this);
}

AnyFXParser::StructureDeclarationContext* AnyFXParser::structureDeclaration() {
  StructureDeclarationContext *_localctx = _tracker.createInstance<StructureDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 18, AnyFXParser::RuleStructureDeclaration);

          dynamic_cast<StructureDeclarationContext *>(_localctx)->sym =  nullptr;
          std::vector<Annotation> annotations;
          std::vector<Attribute> attributes;
          Symbol::Location location;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::SOBAKA) {
      setState(309);
      dynamic_cast<StructureDeclarationContext *>(_localctx)->annotationContext = annotation();
       annotations.push_back(dynamic_cast<StructureDeclarationContext *>(_localctx)->annotationContext->annot); 
      setState(316);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(317);
    match(AnyFXParser::T__5);
    setState(323);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(318);
        dynamic_cast<StructureDeclarationContext *>(_localctx)->attributeContext = attribute();
         attributes.push_back(dynamic_cast<StructureDeclarationContext *>(_localctx)->attributeContext->attr);  
      }
      setState(325);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
    setState(326);
    dynamic_cast<StructureDeclarationContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     
            dynamic_cast<StructureDeclarationContext *>(_localctx)->sym =  new Structure(); location = SetupFile(); 
            _localctx->sym->name = (dynamic_cast<StructureDeclarationContext *>(_localctx)->name != nullptr ? dynamic_cast<StructureDeclarationContext *>(_localctx)->name->getText() : ""); 
            _localctx->sym->annotations = annotations;
            _localctx->sym->attributes = attributes;
            _localctx->sym->location = location; 
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureContext ------------------------------------------------------------------

AnyFXParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::StructureDeclarationContext* AnyFXParser::StructureContext::structureDeclaration() {
  return getRuleContext<AnyFXParser::StructureDeclarationContext>(0);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::StructureContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::StructureContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}

tree::TerminalNode* AnyFXParser::StructureContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::ExpressionContext* AnyFXParser::StructureContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::StructureContext::getRuleIndex() const {
  return AnyFXParser::RuleStructure;
}

void AnyFXParser::StructureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure(this);
}

void AnyFXParser::StructureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure(this);
}

AnyFXParser::StructureContext* AnyFXParser::structure() {
  StructureContext *_localctx = _tracker.createInstance<StructureContext>(_ctx, getState());
  enterRule(_localctx, 20, AnyFXParser::RuleStructure);

          dynamic_cast<StructureContext *>(_localctx)->sym =  nullptr;
          std::vector<Variable*> variables;
          bool isArray;
          Expression* arraySizeExpression = nullptr;
          std::string instanceName;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    dynamic_cast<StructureContext *>(_localctx)->structureDeclarationContext = structureDeclaration();
     dynamic_cast<StructureContext *>(_localctx)->sym =  dynamic_cast<StructureContext *>(_localctx)->structureDeclarationContext->sym; 
    setState(331);
    match(AnyFXParser::LB);
    setState(338);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::SOBAKA

    || _la == AnyFXParser::IDENTIFIER) {
      setState(332);
      dynamic_cast<StructureContext *>(_localctx)->variableContext = variable();
       variables.push_back(dynamic_cast<StructureContext *>(_localctx)->variableContext->sym); 
      setState(334);
      match(AnyFXParser::SC);
      setState(340);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(341);
    match(AnyFXParser::RB);
    setState(354);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::IDENTIFIER) {
      setState(342);
      dynamic_cast<StructureContext *>(_localctx)->instanceName = match(AnyFXParser::IDENTIFIER);
       instanceName = (dynamic_cast<StructureContext *>(_localctx)->instanceName != nullptr ? dynamic_cast<StructureContext *>(_localctx)->instanceName->getText() : ""); 
      setState(352);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AnyFXParser::LL) {
        setState(344);
        match(AnyFXParser::LL);
        setState(348);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::LP)
          | (1ULL << AnyFXParser::NOT)
          | (1ULL << AnyFXParser::QO)
          | (1ULL << AnyFXParser::CONNJUGATE)
          | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
          | (1ULL << (AnyFXParser::SUB_OP - 67))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
          | (1ULL << (AnyFXParser::HEX - 67))
          | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
          setState(345);
          dynamic_cast<StructureContext *>(_localctx)->expressionContext = expression();
           arraySizeExpression = dynamic_cast<StructureContext *>(_localctx)->expressionContext->tree; 
        }
        setState(350);
        match(AnyFXParser::RR);
         isArray = true; 
      }
    }
     
            _localctx->sym->members = variables; 
            _localctx->sym->instanceName = instanceName;
            _localctx->sym->isArray = isArray;
            _localctx->sym->arraySizeExpression = arraySizeExpression;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

AnyFXParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::FunctionDeclarationContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::FunctionDeclarationContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::AttributeContext *> AnyFXParser::FunctionDeclarationContext::attribute() {
  return getRuleContexts<AnyFXParser::AttributeContext>();
}

AnyFXParser::AttributeContext* AnyFXParser::FunctionDeclarationContext::attribute(size_t i) {
  return getRuleContext<AnyFXParser::AttributeContext>(i);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::FunctionDeclarationContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::FunctionDeclarationContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}


size_t AnyFXParser::FunctionDeclarationContext::getRuleIndex() const {
  return AnyFXParser::RuleFunctionDeclaration;
}

void AnyFXParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void AnyFXParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}

AnyFXParser::FunctionDeclarationContext* AnyFXParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, AnyFXParser::RuleFunctionDeclaration);

          dynamic_cast<FunctionDeclarationContext *>(_localctx)->sym =  nullptr;
          std::vector<Variable*> variables;
          std::vector<Attribute> attributes;
          Symbol::Location location;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(363);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(358);
        dynamic_cast<FunctionDeclarationContext *>(_localctx)->attributeContext = attribute();
         attributes.push_back(dynamic_cast<FunctionDeclarationContext *>(_localctx)->attributeContext->attr);  
      }
      setState(365);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
    setState(366);
    dynamic_cast<FunctionDeclarationContext *>(_localctx)->returnType = match(AnyFXParser::IDENTIFIER);
    setState(367);
    dynamic_cast<FunctionDeclarationContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(369);
    match(AnyFXParser::LP);
    setState(381);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::SOBAKA

    || _la == AnyFXParser::IDENTIFIER) {
      setState(370);
      dynamic_cast<FunctionDeclarationContext *>(_localctx)->arg0 = variable();
       variables.push_back(dynamic_cast<FunctionDeclarationContext *>(_localctx)->arg0->sym); 
      setState(378);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(372);
        match(AnyFXParser::CO);
        setState(373);
        dynamic_cast<FunctionDeclarationContext *>(_localctx)->argn = variable();
         variables.push_back(dynamic_cast<FunctionDeclarationContext *>(_localctx)->argn->sym); 
        setState(380);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(383);
    match(AnyFXParser::RP);

            dynamic_cast<FunctionDeclarationContext *>(_localctx)->sym =  new Function(); 
            _localctx->sym->hasBody = false;
            _localctx->sym->location = location;
            _localctx->sym->returnType = (dynamic_cast<FunctionDeclarationContext *>(_localctx)->returnType != nullptr ? dynamic_cast<FunctionDeclarationContext *>(_localctx)->returnType->getText() : ""); 
            _localctx->sym->name = (dynamic_cast<FunctionDeclarationContext *>(_localctx)->name != nullptr ? dynamic_cast<FunctionDeclarationContext *>(_localctx)->name->getText() : ""); 
            _localctx->sym->parameters = variables; 
            _localctx->sym->attributes = attributes; 
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeblockContext ------------------------------------------------------------------

AnyFXParser::CodeblockContext::CodeblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::CodeblockContext *> AnyFXParser::CodeblockContext::codeblock() {
  return getRuleContexts<AnyFXParser::CodeblockContext>();
}

AnyFXParser::CodeblockContext* AnyFXParser::CodeblockContext::codeblock(size_t i) {
  return getRuleContext<AnyFXParser::CodeblockContext>(i);
}


size_t AnyFXParser::CodeblockContext::getRuleIndex() const {
  return AnyFXParser::RuleCodeblock;
}

void AnyFXParser::CodeblockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeblock(this);
}

void AnyFXParser::CodeblockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeblock(this);
}

AnyFXParser::CodeblockContext* AnyFXParser::codeblock() {
  CodeblockContext *_localctx = _tracker.createInstance<CodeblockContext>(_ctx, getState());
  enterRule(_localctx, 24, AnyFXParser::RuleCodeblock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(395);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::LB: {
        enterOuterAlt(_localctx, 1);
        setState(386);
        match(AnyFXParser::LB);
        setState(390);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__2)
          | (1ULL << AnyFXParser::T__3)
          | (1ULL << AnyFXParser::T__4)
          | (1ULL << AnyFXParser::T__5)
          | (1ULL << AnyFXParser::T__6)
          | (1ULL << AnyFXParser::T__7)
          | (1ULL << AnyFXParser::T__8)
          | (1ULL << AnyFXParser::T__9)
          | (1ULL << AnyFXParser::T__10)
          | (1ULL << AnyFXParser::T__11)
          | (1ULL << AnyFXParser::T__12)
          | (1ULL << AnyFXParser::T__13)
          | (1ULL << AnyFXParser::T__14)
          | (1ULL << AnyFXParser::T__15)
          | (1ULL << AnyFXParser::T__16)
          | (1ULL << AnyFXParser::T__17)
          | (1ULL << AnyFXParser::T__18)
          | (1ULL << AnyFXParser::T__19)
          | (1ULL << AnyFXParser::T__20)
          | (1ULL << AnyFXParser::T__21)
          | (1ULL << AnyFXParser::T__22)
          | (1ULL << AnyFXParser::T__23)
          | (1ULL << AnyFXParser::T__24)
          | (1ULL << AnyFXParser::T__25)
          | (1ULL << AnyFXParser::T__26)
          | (1ULL << AnyFXParser::T__27)
          | (1ULL << AnyFXParser::T__28)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::SC)
          | (1ULL << AnyFXParser::CO)
          | (1ULL << AnyFXParser::COL)
          | (1ULL << AnyFXParser::LP)
          | (1ULL << AnyFXParser::RP)
          | (1ULL << AnyFXParser::LB)
          | (1ULL << AnyFXParser::LL)
          | (1ULL << AnyFXParser::RR)
          | (1ULL << AnyFXParser::DOT)
          | (1ULL << AnyFXParser::NOT)
          | (1ULL << AnyFXParser::EQ)
          | (1ULL << AnyFXParser::QO)
          | (1ULL << AnyFXParser::QU)
          | (1ULL << AnyFXParser::AND)
          | (1ULL << AnyFXParser::ANDSET)
          | (1ULL << AnyFXParser::OR)
          | (1ULL << AnyFXParser::ORSET)
          | (1ULL << AnyFXParser::XOR)
          | (1ULL << AnyFXParser::XORSET)
          | (1ULL << AnyFXParser::CONNJUGATE)
          | (1ULL << AnyFXParser::Q)
          | (1ULL << AnyFXParser::NU)
          | (1ULL << AnyFXParser::FORWARDSLASH)
          | (1ULL << AnyFXParser::LESS)
          | (1ULL << AnyFXParser::LESSEQ)
          | (1ULL << AnyFXParser::GREATER)
          | (1ULL << AnyFXParser::GREATEREQ)
          | (1ULL << AnyFXParser::LOGICEQ)
          | (1ULL << AnyFXParser::NOTEQ)
          | (1ULL << AnyFXParser::LOGICAND)
          | (1ULL << AnyFXParser::LOGICOR))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
          | (1ULL << (AnyFXParser::SOBAKA - 64))
          | (1ULL << (AnyFXParser::ADD_OP - 64))
          | (1ULL << (AnyFXParser::SUB_OP - 64))
          | (1ULL << (AnyFXParser::DIV_OP - 64))
          | (1ULL << (AnyFXParser::MUL_OP - 64))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 64))
          | (1ULL << (AnyFXParser::COMMENT - 64))
          | (1ULL << (AnyFXParser::ML_COMMENT - 64))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 64))
          | (1ULL << (AnyFXParser::EXPONENT - 64))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 64))
          | (1ULL << (AnyFXParser::HEX - 64))
          | (1ULL << (AnyFXParser::IDENTIFIER - 64))
          | (1ULL << (AnyFXParser::WS - 64)))) != 0)) {
          setState(387);
          codeblock();
          setState(392);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(393);
        match(AnyFXParser::RB);
        break;
      }

      case AnyFXParser::T__0:
      case AnyFXParser::T__1:
      case AnyFXParser::T__2:
      case AnyFXParser::T__3:
      case AnyFXParser::T__4:
      case AnyFXParser::T__5:
      case AnyFXParser::T__6:
      case AnyFXParser::T__7:
      case AnyFXParser::T__8:
      case AnyFXParser::T__9:
      case AnyFXParser::T__10:
      case AnyFXParser::T__11:
      case AnyFXParser::T__12:
      case AnyFXParser::T__13:
      case AnyFXParser::T__14:
      case AnyFXParser::T__15:
      case AnyFXParser::T__16:
      case AnyFXParser::T__17:
      case AnyFXParser::T__18:
      case AnyFXParser::T__19:
      case AnyFXParser::T__20:
      case AnyFXParser::T__21:
      case AnyFXParser::T__22:
      case AnyFXParser::T__23:
      case AnyFXParser::T__24:
      case AnyFXParser::T__25:
      case AnyFXParser::T__26:
      case AnyFXParser::T__27:
      case AnyFXParser::T__28:
      case AnyFXParser::T__29:
      case AnyFXParser::T__30:
      case AnyFXParser::SC:
      case AnyFXParser::CO:
      case AnyFXParser::COL:
      case AnyFXParser::LP:
      case AnyFXParser::RP:
      case AnyFXParser::LL:
      case AnyFXParser::RR:
      case AnyFXParser::DOT:
      case AnyFXParser::NOT:
      case AnyFXParser::EQ:
      case AnyFXParser::QO:
      case AnyFXParser::QU:
      case AnyFXParser::AND:
      case AnyFXParser::ANDSET:
      case AnyFXParser::OR:
      case AnyFXParser::ORSET:
      case AnyFXParser::XOR:
      case AnyFXParser::XORSET:
      case AnyFXParser::CONNJUGATE:
      case AnyFXParser::Q:
      case AnyFXParser::NU:
      case AnyFXParser::FORWARDSLASH:
      case AnyFXParser::LESS:
      case AnyFXParser::LESSEQ:
      case AnyFXParser::GREATER:
      case AnyFXParser::GREATEREQ:
      case AnyFXParser::LOGICEQ:
      case AnyFXParser::NOTEQ:
      case AnyFXParser::LOGICAND:
      case AnyFXParser::LOGICOR:
      case AnyFXParser::MOD:
      case AnyFXParser::UNDERSC:
      case AnyFXParser::SOBAKA:
      case AnyFXParser::ADD_OP:
      case AnyFXParser::SUB_OP:
      case AnyFXParser::DIV_OP:
      case AnyFXParser::MUL_OP:
      case AnyFXParser::INTEGERLITERAL:
      case AnyFXParser::COMMENT:
      case AnyFXParser::ML_COMMENT:
      case AnyFXParser::FLOATLITERAL:
      case AnyFXParser::EXPONENT:
      case AnyFXParser::DOUBLELITERAL:
      case AnyFXParser::HEX:
      case AnyFXParser::IDENTIFIER:
      case AnyFXParser::WS: {
        enterOuterAlt(_localctx, 2);
        setState(394);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::LB

        || _la == AnyFXParser::RB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AnyFXParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::FunctionDeclarationContext* AnyFXParser::FunctionContext::functionDeclaration() {
  return getRuleContext<AnyFXParser::FunctionDeclarationContext>(0);
}

AnyFXParser::ScopeStatementContext* AnyFXParser::FunctionContext::scopeStatement() {
  return getRuleContext<AnyFXParser::ScopeStatementContext>(0);
}


size_t AnyFXParser::FunctionContext::getRuleIndex() const {
  return AnyFXParser::RuleFunction;
}

void AnyFXParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void AnyFXParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

AnyFXParser::FunctionContext* AnyFXParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 26, AnyFXParser::RuleFunction);

          dynamic_cast<FunctionContext *>(_localctx)->sym =  nullptr;
          Token* startToken = nullptr;
          Token* endToken = nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    dynamic_cast<FunctionContext *>(_localctx)->functionDeclarationContext = functionDeclaration();
     dynamic_cast<FunctionContext *>(_localctx)->sym =  dynamic_cast<FunctionContext *>(_localctx)->functionDeclarationContext->sym; 

            startToken = _input->LT(2);
        
    setState(400);
    dynamic_cast<FunctionContext *>(_localctx)->scopeStatementContext = scopeStatement();

            endToken = _input->LT(-2);

            // extract code from between tokens
            antlr4::misc::Interval interval;
            interval.a = startToken->getTokenIndex();
            interval.b = endToken->getTokenIndex();
            _localctx->sym->body = _input->getText(interval);
            _localctx->sym->hasBody = true;
            _localctx->sym->ast = dynamic_cast<FunctionContext *>(_localctx)->scopeStatementContext->tree;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

AnyFXParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::ProgramContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::AnnotationContext *> AnyFXParser::ProgramContext::annotation() {
  return getRuleContexts<AnyFXParser::AnnotationContext>();
}

AnyFXParser::AnnotationContext* AnyFXParser::ProgramContext::annotation(size_t i) {
  return getRuleContext<AnyFXParser::AnnotationContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::ProgramContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::ProgramContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::ProgramContext::getRuleIndex() const {
  return AnyFXParser::RuleProgram;
}

void AnyFXParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AnyFXParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

AnyFXParser::ProgramContext* AnyFXParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 28, AnyFXParser::RuleProgram);

          dynamic_cast<ProgramContext *>(_localctx)->sym =  nullptr;
          Symbol::Location location;
          std::vector<Program::SubroutineMapping> subroutines;
          std::vector<Expression*> entries;
          std::vector<Annotation> annotations;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::SOBAKA) {
      setState(403);
      dynamic_cast<ProgramContext *>(_localctx)->annotationContext = annotation();
       annotations.push_back(dynamic_cast<ProgramContext *>(_localctx)->annotationContext->annot); 
      setState(410);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(411);
    match(AnyFXParser::T__6);
    setState(412);
    dynamic_cast<ProgramContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(414);
    match(AnyFXParser::LB);
    setState(421);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
      | (1ULL << AnyFXParser::T__1)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::LP)
      | (1ULL << AnyFXParser::NOT)
      | (1ULL << AnyFXParser::QO)
      | (1ULL << AnyFXParser::CONNJUGATE)
      | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
      | (1ULL << (AnyFXParser::SUB_OP - 67))
      | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
      | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
      | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
      | (1ULL << (AnyFXParser::HEX - 67))
      | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
      setState(415);
      dynamic_cast<ProgramContext *>(_localctx)->assignment = expression();
       entries.push_back(dynamic_cast<ProgramContext *>(_localctx)->assignment->tree); 
      setState(417);
      match(AnyFXParser::SC);
      setState(423);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(424);
    match(AnyFXParser::RB);
     
            dynamic_cast<ProgramContext *>(_localctx)->sym =  new Program();
            _localctx->sym->location = location;
            _localctx->sym->name = (dynamic_cast<ProgramContext *>(_localctx)->name != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->name->getText() : "");
            _localctx->sym->annotations = annotations;
            _localctx->sym->entries = entries;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateContext ------------------------------------------------------------------

AnyFXParser::StateContext::StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::StateContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::StateContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::StateContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::StateContext::getRuleIndex() const {
  return AnyFXParser::RuleState;
}

void AnyFXParser::StateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterState(this);
}

void AnyFXParser::StateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitState(this);
}

AnyFXParser::StateContext* AnyFXParser::state() {
  StateContext *_localctx = _tracker.createInstance<StateContext>(_ctx, getState());
  enterRule(_localctx, 30, AnyFXParser::RuleState);

          Expression* arrayExpression = nullptr;
          Symbol::Location location;
          std::vector<Expression*> entries;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__7: {
        setState(427);
        match(AnyFXParser::T__7);
         dynamic_cast<StateContext *>(_localctx)->sym =  new SamplerState(); 
        break;
      }

      case AnyFXParser::T__8: {
        setState(429);
        match(AnyFXParser::T__8);
         dynamic_cast<StateContext *>(_localctx)->sym =  new RenderState(); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(433);
    dynamic_cast<StateContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(435);
    match(AnyFXParser::LB);
    setState(442);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
      | (1ULL << AnyFXParser::T__1)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::LP)
      | (1ULL << AnyFXParser::NOT)
      | (1ULL << AnyFXParser::QO)
      | (1ULL << AnyFXParser::CONNJUGATE)
      | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
      | (1ULL << (AnyFXParser::SUB_OP - 67))
      | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
      | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
      | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
      | (1ULL << (AnyFXParser::HEX - 67))
      | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
      setState(436);
      dynamic_cast<StateContext *>(_localctx)->assign = expression();
       entries.push_back(dynamic_cast<StateContext *>(_localctx)->assign->tree); 
      setState(438);
      match(AnyFXParser::SC);
      setState(444);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(445);
    match(AnyFXParser::RB);

            _localctx->sym->name = (dynamic_cast<StateContext *>(_localctx)->name != nullptr ? dynamic_cast<StateContext *>(_localctx)->name->getText() : "");
            _localctx->sym->location = location;
            _localctx->sym->entries = entries;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

AnyFXParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::VariableContext* AnyFXParser::DeclarationContext::variable() {
  return getRuleContext<AnyFXParser::VariableContext>(0);
}


size_t AnyFXParser::DeclarationContext::getRuleIndex() const {
  return AnyFXParser::RuleDeclaration;
}

void AnyFXParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void AnyFXParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

AnyFXParser::DeclarationContext* AnyFXParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 32, AnyFXParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(448);
    dynamic_cast<DeclarationContext *>(_localctx)->variableContext = variable();
     dynamic_cast<DeclarationContext *>(_localctx)->sym =  dynamic_cast<DeclarationContext *>(_localctx)->variableContext->sym; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AnyFXParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::DeclarationStatementContext* AnyFXParser::StatementContext::declarationStatement() {
  return getRuleContext<AnyFXParser::DeclarationStatementContext>(0);
}

AnyFXParser::IfStatementContext* AnyFXParser::StatementContext::ifStatement() {
  return getRuleContext<AnyFXParser::IfStatementContext>(0);
}

AnyFXParser::ScopeStatementContext* AnyFXParser::StatementContext::scopeStatement() {
  return getRuleContext<AnyFXParser::ScopeStatementContext>(0);
}

AnyFXParser::ForStatementContext* AnyFXParser::StatementContext::forStatement() {
  return getRuleContext<AnyFXParser::ForStatementContext>(0);
}

AnyFXParser::WhileStatementContext* AnyFXParser::StatementContext::whileStatement() {
  return getRuleContext<AnyFXParser::WhileStatementContext>(0);
}

AnyFXParser::ReturnStatementContext* AnyFXParser::StatementContext::returnStatement() {
  return getRuleContext<AnyFXParser::ReturnStatementContext>(0);
}

AnyFXParser::ContinueStatementContext* AnyFXParser::StatementContext::continueStatement() {
  return getRuleContext<AnyFXParser::ContinueStatementContext>(0);
}

AnyFXParser::BreakStatementContext* AnyFXParser::StatementContext::breakStatement() {
  return getRuleContext<AnyFXParser::BreakStatementContext>(0);
}

AnyFXParser::ExpressionStatementContext* AnyFXParser::StatementContext::expressionStatement() {
  return getRuleContext<AnyFXParser::ExpressionStatementContext>(0);
}


size_t AnyFXParser::StatementContext::getRuleIndex() const {
  return AnyFXParser::RuleStatement;
}

void AnyFXParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void AnyFXParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

AnyFXParser::StatementContext* AnyFXParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 34, AnyFXParser::RuleStatement);

          dynamic_cast<StatementContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(480);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(451);
      dynamic_cast<StatementContext *>(_localctx)->declarationStatementContext = declarationStatement();
      setState(452);
      match(AnyFXParser::SC);
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->declarationStatementContext->tree; 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(455);
      dynamic_cast<StatementContext *>(_localctx)->ifStatementContext = ifStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->ifStatementContext->tree; 
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(458);
      dynamic_cast<StatementContext *>(_localctx)->scopeStatementContext = scopeStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->scopeStatementContext->tree; 
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(461);
      dynamic_cast<StatementContext *>(_localctx)->forStatementContext = forStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->forStatementContext->tree; 
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(464);
      dynamic_cast<StatementContext *>(_localctx)->whileStatementContext = whileStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->whileStatementContext->tree; 
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(467);
      dynamic_cast<StatementContext *>(_localctx)->returnStatementContext = returnStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->returnStatementContext->tree; 
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(470);
      dynamic_cast<StatementContext *>(_localctx)->continueStatementContext = continueStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->continueStatementContext->tree; 
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(473);
      dynamic_cast<StatementContext *>(_localctx)->breakStatementContext = breakStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->breakStatementContext->tree; 
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(476);
      dynamic_cast<StatementContext *>(_localctx)->expressionStatementContext = expressionStatement();
       dynamic_cast<StatementContext *>(_localctx)->tree =  dynamic_cast<StatementContext *>(_localctx)->expressionStatementContext->tree; 
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(479);
      match(AnyFXParser::SC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

AnyFXParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ExpressionStatementContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ExpressionStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleExpressionStatement;
}

void AnyFXParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void AnyFXParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}

AnyFXParser::ExpressionStatementContext* AnyFXParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, AnyFXParser::RuleExpressionStatement);

          dynamic_cast<ExpressionStatementContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    dynamic_cast<ExpressionStatementContext *>(_localctx)->expressionContext = expression();
    setState(483);
    match(AnyFXParser::SC);

            dynamic_cast<ExpressionStatementContext *>(_localctx)->tree =  new ExpressionStatement(dynamic_cast<ExpressionStatementContext *>(_localctx)->expressionContext->tree);
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationStatementContext ------------------------------------------------------------------

AnyFXParser::DeclarationStatementContext::DeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::DeclarationStatementContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::DeclarationStatementContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::DeclarationStatementContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::DeclarationStatementContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::DeclarationStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleDeclarationStatement;
}

void AnyFXParser::DeclarationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationStatement(this);
}

void AnyFXParser::DeclarationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationStatement(this);
}

AnyFXParser::DeclarationStatementContext* AnyFXParser::declarationStatement() {
  DeclarationStatementContext *_localctx = _tracker.createInstance<DeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, AnyFXParser::RuleDeclarationStatement);

          dynamic_cast<DeclarationStatementContext *>(_localctx)->tree =  nullptr;
          std::vector<std::string> qualifiers;
          std::vector<Expression*> arrayExpressions;
          Expression* initializer = nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    dynamic_cast<DeclarationStatementContext *>(_localctx)->qualifier = match(AnyFXParser::IDENTIFIER);
     qualifiers.push_back((dynamic_cast<DeclarationStatementContext *>(_localctx)->qualifier != nullptr ? dynamic_cast<DeclarationStatementContext *>(_localctx)->qualifier->getText() : "")); 
    setState(489);
    dynamic_cast<DeclarationStatementContext *>(_localctx)->type = match(AnyFXParser::IDENTIFIER);
    setState(490);
    dynamic_cast<DeclarationStatementContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
    setState(498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LL) {
      setState(491);
      match(AnyFXParser::LL);
      setState(492);
      dynamic_cast<DeclarationStatementContext *>(_localctx)->arraySize = dynamic_cast<DeclarationStatementContext *>(_localctx)->expressionContext = expression();
      setState(493);
      match(AnyFXParser::RR);
       arrayExpressions.push_back(dynamic_cast<DeclarationStatementContext *>(_localctx)->arraySize->tree); 
      setState(500);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(505);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::EQ) {
      setState(501);
      match(AnyFXParser::EQ);
      setState(502);
      dynamic_cast<DeclarationStatementContext *>(_localctx)->expressionContext = expression();
       initializer = dynamic_cast<DeclarationStatementContext *>(_localctx)->expressionContext->tree; 
    }

            dynamic_cast<DeclarationStatementContext *>(_localctx)->tree =  new DeclarationStatement((dynamic_cast<DeclarationStatementContext *>(_localctx)->type != nullptr ? dynamic_cast<DeclarationStatementContext *>(_localctx)->type->getText() : ""), (dynamic_cast<DeclarationStatementContext *>(_localctx)->name != nullptr ? dynamic_cast<DeclarationStatementContext *>(_localctx)->name->getText() : ""), qualifiers, initializer);
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

AnyFXParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::IfStatementContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

std::vector<AnyFXParser::StatementContext *> AnyFXParser::IfStatementContext::statement() {
  return getRuleContexts<AnyFXParser::StatementContext>();
}

AnyFXParser::StatementContext* AnyFXParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<AnyFXParser::StatementContext>(i);
}


size_t AnyFXParser::IfStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleIfStatement;
}

void AnyFXParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void AnyFXParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

AnyFXParser::IfStatementContext* AnyFXParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, AnyFXParser::RuleIfStatement);

          dynamic_cast<IfStatementContext *>(_localctx)->tree =  nullptr;
          Expression* condition = nullptr;
          Statement* ifBody = nullptr;
          Statement* elseBody = nullptr;
          Symbol::Location location;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    match(AnyFXParser::T__9);
     location = SetupFile(); 
    setState(511);
    match(AnyFXParser::LP);
    setState(512);
    dynamic_cast<IfStatementContext *>(_localctx)->condition = expression();
     condition = dynamic_cast<IfStatementContext *>(_localctx)->condition->tree; 
    setState(514);
    match(AnyFXParser::RP);
    setState(515);
    dynamic_cast<IfStatementContext *>(_localctx)->ifBody = statement();
     ifBody = dynamic_cast<IfStatementContext *>(_localctx)->ifBody->tree; 
    setState(521);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(517);
      match(AnyFXParser::T__10);
      setState(518);
      dynamic_cast<IfStatementContext *>(_localctx)->elseBody = statement();
       elseBody = dynamic_cast<IfStatementContext *>(_localctx)->elseBody->tree; 
      break;
    }

    }

            dynamic_cast<IfStatementContext *>(_localctx)->tree =  new IfStatement(condition, ifBody, elseBody);
            _localctx->tree->location = location;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

AnyFXParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::StatementContext* AnyFXParser::ForStatementContext::statement() {
  return getRuleContext<AnyFXParser::StatementContext>(0);
}

std::vector<AnyFXParser::DeclarationContext *> AnyFXParser::ForStatementContext::declaration() {
  return getRuleContexts<AnyFXParser::DeclarationContext>();
}

AnyFXParser::DeclarationContext* AnyFXParser::ForStatementContext::declaration(size_t i) {
  return getRuleContext<AnyFXParser::DeclarationContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::ForStatementContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::ForStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleForStatement;
}

void AnyFXParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void AnyFXParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

AnyFXParser::ForStatementContext* AnyFXParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, AnyFXParser::RuleForStatement);

          dynamic_cast<ForStatementContext *>(_localctx)->tree =  nullptr;
          std::vector<Symbol*> declarations;
          Expression* conditionExpression = nullptr;
          std::vector<Expression*> expressions;
          Statement* contents = nullptr;
          Symbol::Location location;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(525);
    match(AnyFXParser::T__11);
     location = SetupFile(); 
    setState(527);
    match(AnyFXParser::LP);
    setState(539);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::SOBAKA

    || _la == AnyFXParser::IDENTIFIER) {
      setState(528);
      dynamic_cast<ForStatementContext *>(_localctx)->declare0 = declaration();
       declarations.push_back(dynamic_cast<ForStatementContext *>(_localctx)->declare0->sym); 
      setState(536);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(530);
        match(AnyFXParser::CO);
        setState(531);
        dynamic_cast<ForStatementContext *>(_localctx)->declaren = declaration();
         declarations.push_back(dynamic_cast<ForStatementContext *>(_localctx)->declaren->sym); 
        setState(538);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(541);
    match(AnyFXParser::SC);
    setState(545);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
      | (1ULL << AnyFXParser::T__1)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::LP)
      | (1ULL << AnyFXParser::NOT)
      | (1ULL << AnyFXParser::QO)
      | (1ULL << AnyFXParser::CONNJUGATE)
      | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
      | (1ULL << (AnyFXParser::SUB_OP - 67))
      | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
      | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
      | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
      | (1ULL << (AnyFXParser::HEX - 67))
      | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
      setState(542);
      dynamic_cast<ForStatementContext *>(_localctx)->condition = expression();
       conditionExpression = dynamic_cast<ForStatementContext *>(_localctx)->condition->tree; 
    }
    setState(547);
    match(AnyFXParser::SC);
    setState(559);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
      | (1ULL << AnyFXParser::T__1)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::LP)
      | (1ULL << AnyFXParser::NOT)
      | (1ULL << AnyFXParser::QO)
      | (1ULL << AnyFXParser::CONNJUGATE)
      | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
      | (1ULL << (AnyFXParser::SUB_OP - 67))
      | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
      | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
      | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
      | (1ULL << (AnyFXParser::HEX - 67))
      | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
      setState(548);
      dynamic_cast<ForStatementContext *>(_localctx)->expression0 = expression();
       expressions.push_back(dynamic_cast<ForStatementContext *>(_localctx)->expression0->tree); 
      setState(556);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(550);
        match(AnyFXParser::CO);
        setState(551);
        dynamic_cast<ForStatementContext *>(_localctx)->expressionn = expression();
         expressions.push_back(dynamic_cast<ForStatementContext *>(_localctx)->expressionn->tree); 
        setState(558);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(561);
    match(AnyFXParser::RP);
    setState(562);
    dynamic_cast<ForStatementContext *>(_localctx)->content = statement();
     contents = dynamic_cast<ForStatementContext *>(_localctx)->content->tree; 

            dynamic_cast<ForStatementContext *>(_localctx)->tree =  new ForStatement(declarations, conditionExpression, expressions, contents);
            _localctx->tree->location = location;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForRangeStatementContext ------------------------------------------------------------------

AnyFXParser::ForRangeStatementContext::ForRangeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::ForRangeStatementContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::ForRangeStatementContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

AnyFXParser::StatementContext* AnyFXParser::ForRangeStatementContext::statement() {
  return getRuleContext<AnyFXParser::StatementContext>(0);
}


size_t AnyFXParser::ForRangeStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleForRangeStatement;
}

void AnyFXParser::ForRangeStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForRangeStatement(this);
}

void AnyFXParser::ForRangeStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForRangeStatement(this);
}

AnyFXParser::ForRangeStatementContext* AnyFXParser::forRangeStatement() {
  ForRangeStatementContext *_localctx = _tracker.createInstance<ForRangeStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, AnyFXParser::RuleForRangeStatement);

          dynamic_cast<ForRangeStatementContext *>(_localctx)->tree =  nullptr;
          Statement* contents = nullptr;
          Symbol::Location location;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(566);
    match(AnyFXParser::T__11);
     location = SetupFile(); 
    setState(568);
    match(AnyFXParser::LP);
    setState(569);
    dynamic_cast<ForRangeStatementContext *>(_localctx)->iterator = match(AnyFXParser::IDENTIFIER);
    setState(570);
    match(AnyFXParser::COL);
    setState(571);
    dynamic_cast<ForRangeStatementContext *>(_localctx)->start = match(AnyFXParser::IDENTIFIER);
    setState(572);
    match(AnyFXParser::DOT);
    setState(573);
    match(AnyFXParser::DOT);
    setState(574);
    dynamic_cast<ForRangeStatementContext *>(_localctx)->end = match(AnyFXParser::IDENTIFIER);
    setState(575);
    match(AnyFXParser::RP);
    setState(576);
    dynamic_cast<ForRangeStatementContext *>(_localctx)->content = statement();
     contents = dynamic_cast<ForRangeStatementContext *>(_localctx)->content->tree; 


        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

AnyFXParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::WhileStatementContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

AnyFXParser::StatementContext* AnyFXParser::WhileStatementContext::statement() {
  return getRuleContext<AnyFXParser::StatementContext>(0);
}


size_t AnyFXParser::WhileStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleWhileStatement;
}

void AnyFXParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void AnyFXParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}

AnyFXParser::WhileStatementContext* AnyFXParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 46, AnyFXParser::RuleWhileStatement);

          dynamic_cast<WhileStatementContext *>(_localctx)->tree =  nullptr;
          Expression* conditionExpression = nullptr;
          Statement* contents = nullptr;
          bool isDoWhile = false;
          Symbol::Location location;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(600);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__12: {
        enterOuterAlt(_localctx, 1);
        setState(580);
        match(AnyFXParser::T__12);
         location = SetupFile(); 
        setState(582);
        match(AnyFXParser::LP);
        setState(583);
        dynamic_cast<WhileStatementContext *>(_localctx)->condition = expression();
         conditionExpression = dynamic_cast<WhileStatementContext *>(_localctx)->condition->tree; 
        setState(585);
        match(AnyFXParser::RP);
        setState(586);
        dynamic_cast<WhileStatementContext *>(_localctx)->content = statement();
         contents = dynamic_cast<WhileStatementContext *>(_localctx)->content->tree; 
        break;
      }

      case AnyFXParser::T__13: {
        enterOuterAlt(_localctx, 2);
        setState(589);
        match(AnyFXParser::T__13);
         location = SetupFile(); 
        setState(591);
        dynamic_cast<WhileStatementContext *>(_localctx)->content = statement();
         contents = dynamic_cast<WhileStatementContext *>(_localctx)->content->tree; isDoWhile = true; 
        setState(593);
        match(AnyFXParser::T__12);
        setState(594);
        match(AnyFXParser::LP);
        setState(595);
        dynamic_cast<WhileStatementContext *>(_localctx)->condition = expression();
         conditionExpression = dynamic_cast<WhileStatementContext *>(_localctx)->condition->tree; 
        setState(597);
        match(AnyFXParser::RP);

                dynamic_cast<WhileStatementContext *>(_localctx)->tree =  new WhileStatement(conditionExpression, contents, isDoWhile);
                _localctx->tree->location = location;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeStatementContext ------------------------------------------------------------------

AnyFXParser::ScopeStatementContext::ScopeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::StatementContext *> AnyFXParser::ScopeStatementContext::statement() {
  return getRuleContexts<AnyFXParser::StatementContext>();
}

AnyFXParser::StatementContext* AnyFXParser::ScopeStatementContext::statement(size_t i) {
  return getRuleContext<AnyFXParser::StatementContext>(i);
}

std::vector<AnyFXParser::DeclarationContext *> AnyFXParser::ScopeStatementContext::declaration() {
  return getRuleContexts<AnyFXParser::DeclarationContext>();
}

AnyFXParser::DeclarationContext* AnyFXParser::ScopeStatementContext::declaration(size_t i) {
  return getRuleContext<AnyFXParser::DeclarationContext>(i);
}


size_t AnyFXParser::ScopeStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleScopeStatement;
}

void AnyFXParser::ScopeStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScopeStatement(this);
}

void AnyFXParser::ScopeStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScopeStatement(this);
}

AnyFXParser::ScopeStatementContext* AnyFXParser::scopeStatement() {
  ScopeStatementContext *_localctx = _tracker.createInstance<ScopeStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, AnyFXParser::RuleScopeStatement);

          dynamic_cast<ScopeStatementContext *>(_localctx)->tree =  nullptr;
          std::vector<Symbol*> contents;
          Symbol::Location location;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    match(AnyFXParser::LB);
     location = SetupFile(); 
    setState(612);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
      | (1ULL << AnyFXParser::T__1)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::SC)
      | (1ULL << AnyFXParser::LP)
      | (1ULL << AnyFXParser::LB)
      | (1ULL << AnyFXParser::NOT)
      | (1ULL << AnyFXParser::QO)
      | (1ULL << AnyFXParser::CONNJUGATE)
      | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (AnyFXParser::SOBAKA - 66))
      | (1ULL << (AnyFXParser::ADD_OP - 66))
      | (1ULL << (AnyFXParser::SUB_OP - 66))
      | (1ULL << (AnyFXParser::INTEGERLITERAL - 66))
      | (1ULL << (AnyFXParser::FLOATLITERAL - 66))
      | (1ULL << (AnyFXParser::DOUBLELITERAL - 66))
      | (1ULL << (AnyFXParser::HEX - 66))
      | (1ULL << (AnyFXParser::IDENTIFIER - 66)))) != 0)) {
      setState(610);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
      case 1: {
        setState(604);
        dynamic_cast<ScopeStatementContext *>(_localctx)->content = statement();
         contents.push_back(dynamic_cast<ScopeStatementContext *>(_localctx)->content->tree); 
        break;
      }

      case 2: {
        setState(607);
        dynamic_cast<ScopeStatementContext *>(_localctx)->declare = declaration();
         contents.push_back(dynamic_cast<ScopeStatementContext *>(_localctx)->declare->sym); 
        break;
      }

      }
      setState(614);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(615);
    match(AnyFXParser::RB);

            dynamic_cast<ScopeStatementContext *>(_localctx)->tree =  new ScopeStatement(contents);
            _localctx->tree->location = location;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

AnyFXParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ReturnStatementContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ReturnStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleReturnStatement;
}

void AnyFXParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void AnyFXParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

AnyFXParser::ReturnStatementContext* AnyFXParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, AnyFXParser::RuleReturnStatement);

          dynamic_cast<ReturnStatementContext *>(_localctx)->tree =  nullptr;
          Expression* returnValue = nullptr;
          Symbol::Location location;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(618);
    match(AnyFXParser::T__14);
     location = SetupFile(); 
    setState(623);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
      | (1ULL << AnyFXParser::T__1)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::LP)
      | (1ULL << AnyFXParser::NOT)
      | (1ULL << AnyFXParser::QO)
      | (1ULL << AnyFXParser::CONNJUGATE)
      | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
      | (1ULL << (AnyFXParser::SUB_OP - 67))
      | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
      | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
      | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
      | (1ULL << (AnyFXParser::HEX - 67))
      | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
      setState(620);
      dynamic_cast<ReturnStatementContext *>(_localctx)->value = expression();
       returnValue = dynamic_cast<ReturnStatementContext *>(_localctx)->value->tree; 
    }
    setState(625);
    match(AnyFXParser::SC);

            dynamic_cast<ReturnStatementContext *>(_localctx)->tree =  new ReturnStatement(returnValue);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

AnyFXParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::ContinueStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleContinueStatement;
}

void AnyFXParser::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void AnyFXParser::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}

AnyFXParser::ContinueStatementContext* AnyFXParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, AnyFXParser::RuleContinueStatement);

          dynamic_cast<ContinueStatementContext *>(_localctx)->tree =  nullptr;
          Symbol::Location location;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    match(AnyFXParser::T__15);
     location = SetupFile(); 
    setState(630);
    match(AnyFXParser::SC);

            dynamic_cast<ContinueStatementContext *>(_localctx)->tree =  new ContinueStatement();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStatementContext ------------------------------------------------------------------

AnyFXParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::SwitchStatementContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> AnyFXParser::SwitchStatementContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::SwitchStatementContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::StatementContext *> AnyFXParser::SwitchStatementContext::statement() {
  return getRuleContexts<AnyFXParser::StatementContext>();
}

AnyFXParser::StatementContext* AnyFXParser::SwitchStatementContext::statement(size_t i) {
  return getRuleContext<AnyFXParser::StatementContext>(i);
}


size_t AnyFXParser::SwitchStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleSwitchStatement;
}

void AnyFXParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void AnyFXParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

AnyFXParser::SwitchStatementContext* AnyFXParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, AnyFXParser::RuleSwitchStatement);

          dynamic_cast<SwitchStatementContext *>(_localctx)->tree =  nullptr;
          Expression* switchExpression;
          std::vector<std::string> caseValues;
          std::vector<Statement*> caseStatements;
          Symbol::Location location;
          Statement* defaultStatement = nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(633);
    match(AnyFXParser::T__16);
     location = SetupFile(); 
    setState(635);
    match(AnyFXParser::LP);
    setState(636);
    dynamic_cast<SwitchStatementContext *>(_localctx)->expressionContext = expression();
    setState(637);
    match(AnyFXParser::RP);
     switchExpression = dynamic_cast<SwitchStatementContext *>(_localctx)->expressionContext->tree; 
    setState(639);
    match(AnyFXParser::LB);
    setState(648);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::T__17) {
      setState(640);
      match(AnyFXParser::T__17);
      setState(641);
      dynamic_cast<SwitchStatementContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
      setState(642);
      match(AnyFXParser::COL);
      setState(643);
      dynamic_cast<SwitchStatementContext *>(_localctx)->statementContext = statement();
       
                      caseValues.push_back((dynamic_cast<SwitchStatementContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<SwitchStatementContext *>(_localctx)->identifierToken->getText() : "")); 
                      caseStatements.push_back(dynamic_cast<SwitchStatementContext *>(_localctx)->statementContext->tree);
                  
      setState(650);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(656);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::T__18) {
      setState(651);
      match(AnyFXParser::T__18);
      setState(652);
      match(AnyFXParser::COL);
      setState(653);
      dynamic_cast<SwitchStatementContext *>(_localctx)->statementContext = statement();

                      defaultStatement = dynamic_cast<SwitchStatementContext *>(_localctx)->statementContext->tree;
                  
    }
    setState(658);
    match(AnyFXParser::RB);

            dynamic_cast<SwitchStatementContext *>(_localctx)->tree =  new SwitchStatement(switchExpression, caseValues, caseStatements);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

AnyFXParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::BreakStatementContext::getRuleIndex() const {
  return AnyFXParser::RuleBreakStatement;
}

void AnyFXParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void AnyFXParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

AnyFXParser::BreakStatementContext* AnyFXParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, AnyFXParser::RuleBreakStatement);

          dynamic_cast<BreakStatementContext *>(_localctx)->tree =  nullptr;
          Symbol::Location location;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(661);
    match(AnyFXParser::T__19);
    setState(662);
    match(AnyFXParser::SC);

            dynamic_cast<BreakStatementContext *>(_localctx)->tree =  new BreakStatement();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

AnyFXParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::Binaryexp12Context* AnyFXParser::ExpressionContext::binaryexp12() {
  return getRuleContext<AnyFXParser::Binaryexp12Context>(0);
}


size_t AnyFXParser::ExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleExpression;
}

void AnyFXParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void AnyFXParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

AnyFXParser::ExpressionContext* AnyFXParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 58, AnyFXParser::RuleExpression);

          dynamic_cast<ExpressionContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(665);
    dynamic_cast<ExpressionContext *>(_localctx)->binaryexp12Context = binaryexp12();
     dynamic_cast<ExpressionContext *>(_localctx)->tree =  dynamic_cast<ExpressionContext *>(_localctx)->binaryexp12Context->tree; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp12Context ------------------------------------------------------------------

AnyFXParser::Binaryexp12Context::Binaryexp12Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp11Context *> AnyFXParser::Binaryexp12Context::binaryexp11() {
  return getRuleContexts<AnyFXParser::Binaryexp11Context>();
}

AnyFXParser::Binaryexp11Context* AnyFXParser::Binaryexp12Context::binaryexp11(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp11Context>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::Binaryexp12Context::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::Binaryexp12Context::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::Binaryexp12Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp12;
}

void AnyFXParser::Binaryexp12Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp12(this);
}

void AnyFXParser::Binaryexp12Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp12(this);
}

AnyFXParser::Binaryexp12Context* AnyFXParser::binaryexp12() {
  Binaryexp12Context *_localctx = _tracker.createInstance<Binaryexp12Context>(_ctx, getState());
  enterRule(_localctx, 60, AnyFXParser::RuleBinaryexp12);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp12Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(668);
    dynamic_cast<Binaryexp12Context *>(_localctx)->e1 = binaryexp11();
     dynamic_cast<Binaryexp12Context *>(_localctx)->tree =  dynamic_cast<Binaryexp12Context *>(_localctx)->e1->tree; 
    setState(683);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(681);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case AnyFXParser::T__20:
          case AnyFXParser::T__21:
          case AnyFXParser::T__22:
          case AnyFXParser::T__23:
          case AnyFXParser::T__24:
          case AnyFXParser::T__25:
          case AnyFXParser::T__26:
          case AnyFXParser::EQ:
          case AnyFXParser::ANDSET:
          case AnyFXParser::ORSET:
          case AnyFXParser::XORSET: {
            setState(670);
            dynamic_cast<Binaryexp12Context *>(_localctx)->op = _input->LT(1);
            _la = _input->LA(1);
            if (!((((_la & ~ 0x3fULL) == 0) &&
              ((1ULL << _la) & ((1ULL << AnyFXParser::T__20)
              | (1ULL << AnyFXParser::T__21)
              | (1ULL << AnyFXParser::T__22)
              | (1ULL << AnyFXParser::T__23)
              | (1ULL << AnyFXParser::T__24)
              | (1ULL << AnyFXParser::T__25)
              | (1ULL << AnyFXParser::T__26)
              | (1ULL << AnyFXParser::EQ)
              | (1ULL << AnyFXParser::ANDSET)
              | (1ULL << AnyFXParser::ORSET)
              | (1ULL << AnyFXParser::XORSET))) != 0))) {
              dynamic_cast<Binaryexp12Context *>(_localctx)->op = _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
             ops.push_back(StringToFourCC((dynamic_cast<Binaryexp12Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp12Context *>(_localctx)->op->getText() : ""))); 
            setState(672);
            dynamic_cast<Binaryexp12Context *>(_localctx)->e2 = binaryexp11();
             exprs.push_back(dynamic_cast<Binaryexp12Context *>(_localctx)->e2->tree); 
            break;
          }

          case AnyFXParser::QU: {
            setState(675);
            match(AnyFXParser::QU);
            setState(676);
            dynamic_cast<Binaryexp12Context *>(_localctx)->ifBody = expression();
            setState(677);
            match(AnyFXParser::COL);
            setState(678);
            dynamic_cast<Binaryexp12Context *>(_localctx)->elseBody = expression();
             
                        exprs.push_back(new TernaryExpression(dynamic_cast<Binaryexp12Context *>(_localctx)->ifBody->tree, dynamic_cast<Binaryexp12Context *>(_localctx)->elseBody->tree));
                        ops.push_back(StringToFourCC("?:"));
                    
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(685);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp12Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp12Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp11Context ------------------------------------------------------------------

AnyFXParser::Binaryexp11Context::Binaryexp11Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp10Context *> AnyFXParser::Binaryexp11Context::binaryexp10() {
  return getRuleContexts<AnyFXParser::Binaryexp10Context>();
}

AnyFXParser::Binaryexp10Context* AnyFXParser::Binaryexp11Context::binaryexp10(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp10Context>(i);
}


size_t AnyFXParser::Binaryexp11Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp11;
}

void AnyFXParser::Binaryexp11Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp11(this);
}

void AnyFXParser::Binaryexp11Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp11(this);
}

AnyFXParser::Binaryexp11Context* AnyFXParser::binaryexp11() {
  Binaryexp11Context *_localctx = _tracker.createInstance<Binaryexp11Context>(_ctx, getState());
  enterRule(_localctx, 62, AnyFXParser::RuleBinaryexp11);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp11Context *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(688);
    dynamic_cast<Binaryexp11Context *>(_localctx)->e1 = binaryexp10();
     dynamic_cast<Binaryexp11Context *>(_localctx)->tree =  dynamic_cast<Binaryexp11Context *>(_localctx)->e1->tree; 
    setState(696);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(690);
        match(AnyFXParser::LOGICOR);
        setState(691);
        dynamic_cast<Binaryexp11Context *>(_localctx)->e2 = binaryexp10();

                    ops.push_back(StringToFourCC("||"));
                    exprs.push_back(dynamic_cast<Binaryexp11Context *>(_localctx)->e2->tree);
                 
      }
      setState(698);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp11Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp11Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp10Context ------------------------------------------------------------------

AnyFXParser::Binaryexp10Context::Binaryexp10Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp9Context *> AnyFXParser::Binaryexp10Context::binaryexp9() {
  return getRuleContexts<AnyFXParser::Binaryexp9Context>();
}

AnyFXParser::Binaryexp9Context* AnyFXParser::Binaryexp10Context::binaryexp9(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp9Context>(i);
}


size_t AnyFXParser::Binaryexp10Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp10;
}

void AnyFXParser::Binaryexp10Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp10(this);
}

void AnyFXParser::Binaryexp10Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp10(this);
}

AnyFXParser::Binaryexp10Context* AnyFXParser::binaryexp10() {
  Binaryexp10Context *_localctx = _tracker.createInstance<Binaryexp10Context>(_ctx, getState());
  enterRule(_localctx, 64, AnyFXParser::RuleBinaryexp10);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp10Context *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(701);
    dynamic_cast<Binaryexp10Context *>(_localctx)->e1 = binaryexp9();
     dynamic_cast<Binaryexp10Context *>(_localctx)->tree =  dynamic_cast<Binaryexp10Context *>(_localctx)->e1->tree; 
    setState(709);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(703);
        match(AnyFXParser::LOGICAND);
        setState(704);
        dynamic_cast<Binaryexp10Context *>(_localctx)->e2 = binaryexp9();

                    ops.push_back(StringToFourCC("&&"));
                    exprs.push_back(dynamic_cast<Binaryexp10Context *>(_localctx)->e2->tree);
                 
      }
      setState(711);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp10Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp10Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp9Context ------------------------------------------------------------------

AnyFXParser::Binaryexp9Context::Binaryexp9Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp8Context *> AnyFXParser::Binaryexp9Context::binaryexp8() {
  return getRuleContexts<AnyFXParser::Binaryexp8Context>();
}

AnyFXParser::Binaryexp8Context* AnyFXParser::Binaryexp9Context::binaryexp8(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp8Context>(i);
}


size_t AnyFXParser::Binaryexp9Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp9;
}

void AnyFXParser::Binaryexp9Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp9(this);
}

void AnyFXParser::Binaryexp9Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp9(this);
}

AnyFXParser::Binaryexp9Context* AnyFXParser::binaryexp9() {
  Binaryexp9Context *_localctx = _tracker.createInstance<Binaryexp9Context>(_ctx, getState());
  enterRule(_localctx, 66, AnyFXParser::RuleBinaryexp9);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp9Context *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(714);
    dynamic_cast<Binaryexp9Context *>(_localctx)->e1 = binaryexp8();
     dynamic_cast<Binaryexp9Context *>(_localctx)->tree =  dynamic_cast<Binaryexp9Context *>(_localctx)->e1->tree; 
    setState(722);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(716);
        match(AnyFXParser::OR);
        setState(717);
        dynamic_cast<Binaryexp9Context *>(_localctx)->e2 = binaryexp8();

                    ops.push_back(StringToFourCC("|"));
                    exprs.push_back(dynamic_cast<Binaryexp9Context *>(_localctx)->e2->tree);
                 
      }
      setState(724);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp9Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp9Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp8Context ------------------------------------------------------------------

AnyFXParser::Binaryexp8Context::Binaryexp8Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp7Context *> AnyFXParser::Binaryexp8Context::binaryexp7() {
  return getRuleContexts<AnyFXParser::Binaryexp7Context>();
}

AnyFXParser::Binaryexp7Context* AnyFXParser::Binaryexp8Context::binaryexp7(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp7Context>(i);
}


size_t AnyFXParser::Binaryexp8Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp8;
}

void AnyFXParser::Binaryexp8Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp8(this);
}

void AnyFXParser::Binaryexp8Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp8(this);
}

AnyFXParser::Binaryexp8Context* AnyFXParser::binaryexp8() {
  Binaryexp8Context *_localctx = _tracker.createInstance<Binaryexp8Context>(_ctx, getState());
  enterRule(_localctx, 68, AnyFXParser::RuleBinaryexp8);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp8Context *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(727);
    dynamic_cast<Binaryexp8Context *>(_localctx)->e1 = binaryexp7();
     dynamic_cast<Binaryexp8Context *>(_localctx)->tree =  dynamic_cast<Binaryexp8Context *>(_localctx)->e1->tree; 
    setState(735);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(729);
        match(AnyFXParser::XOR);
        setState(730);
        dynamic_cast<Binaryexp8Context *>(_localctx)->e2 = binaryexp7();

                    ops.push_back(StringToFourCC("^"));
                    exprs.push_back(dynamic_cast<Binaryexp8Context *>(_localctx)->e2->tree);
                 
      }
      setState(737);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp8Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp8Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp7Context ------------------------------------------------------------------

AnyFXParser::Binaryexp7Context::Binaryexp7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp6Context *> AnyFXParser::Binaryexp7Context::binaryexp6() {
  return getRuleContexts<AnyFXParser::Binaryexp6Context>();
}

AnyFXParser::Binaryexp6Context* AnyFXParser::Binaryexp7Context::binaryexp6(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp6Context>(i);
}


size_t AnyFXParser::Binaryexp7Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp7;
}

void AnyFXParser::Binaryexp7Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp7(this);
}

void AnyFXParser::Binaryexp7Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp7(this);
}

AnyFXParser::Binaryexp7Context* AnyFXParser::binaryexp7() {
  Binaryexp7Context *_localctx = _tracker.createInstance<Binaryexp7Context>(_ctx, getState());
  enterRule(_localctx, 70, AnyFXParser::RuleBinaryexp7);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(740);
    dynamic_cast<Binaryexp7Context *>(_localctx)->e1 = binaryexp6();
     dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  dynamic_cast<Binaryexp7Context *>(_localctx)->e1->tree;	
    setState(748);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(742);
        match(AnyFXParser::AND);
        setState(743);
        dynamic_cast<Binaryexp7Context *>(_localctx)->e2 = binaryexp6();

                    ops.push_back(StringToFourCC("&"));
                    exprs.push_back(dynamic_cast<Binaryexp7Context *>(_localctx)->e2->tree);
                 
      }
      setState(750);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp7Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp6Context ------------------------------------------------------------------

AnyFXParser::Binaryexp6Context::Binaryexp6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp5Context *> AnyFXParser::Binaryexp6Context::binaryexp5() {
  return getRuleContexts<AnyFXParser::Binaryexp5Context>();
}

AnyFXParser::Binaryexp5Context* AnyFXParser::Binaryexp6Context::binaryexp5(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp5Context>(i);
}


size_t AnyFXParser::Binaryexp6Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp6;
}

void AnyFXParser::Binaryexp6Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp6(this);
}

void AnyFXParser::Binaryexp6Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp6(this);
}

AnyFXParser::Binaryexp6Context* AnyFXParser::binaryexp6() {
  Binaryexp6Context *_localctx = _tracker.createInstance<Binaryexp6Context>(_ctx, getState());
  enterRule(_localctx, 72, AnyFXParser::RuleBinaryexp6);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(753);
    dynamic_cast<Binaryexp6Context *>(_localctx)->e1 = binaryexp5();
     dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  dynamic_cast<Binaryexp6Context *>(_localctx)->e1->tree; 
    setState(761);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(755);
        dynamic_cast<Binaryexp6Context *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == AnyFXParser::LOGICEQ

        || _la == AnyFXParser::NOTEQ)) {
          dynamic_cast<Binaryexp6Context *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(756);
        dynamic_cast<Binaryexp6Context *>(_localctx)->e2 = binaryexp5();

                    ops.push_back(StringToFourCC((dynamic_cast<Binaryexp6Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp6Context *>(_localctx)->op->getText() : "")));
                    exprs.push_back(dynamic_cast<Binaryexp6Context *>(_localctx)->e2->tree);
                 
      }
      setState(763);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp6Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp5Context ------------------------------------------------------------------

AnyFXParser::Binaryexp5Context::Binaryexp5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp4Context *> AnyFXParser::Binaryexp5Context::binaryexp4() {
  return getRuleContexts<AnyFXParser::Binaryexp4Context>();
}

AnyFXParser::Binaryexp4Context* AnyFXParser::Binaryexp5Context::binaryexp4(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp4Context>(i);
}


size_t AnyFXParser::Binaryexp5Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp5;
}

void AnyFXParser::Binaryexp5Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp5(this);
}

void AnyFXParser::Binaryexp5Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp5(this);
}

AnyFXParser::Binaryexp5Context* AnyFXParser::binaryexp5() {
  Binaryexp5Context *_localctx = _tracker.createInstance<Binaryexp5Context>(_ctx, getState());
  enterRule(_localctx, 74, AnyFXParser::RuleBinaryexp5);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(766);
    dynamic_cast<Binaryexp5Context *>(_localctx)->e1 = binaryexp4();
     dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  dynamic_cast<Binaryexp5Context *>(_localctx)->e1->tree;	
    setState(774);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(768);
        dynamic_cast<Binaryexp5Context *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::LESS)
          | (1ULL << AnyFXParser::LESSEQ)
          | (1ULL << AnyFXParser::GREATER)
          | (1ULL << AnyFXParser::GREATEREQ))) != 0))) {
          dynamic_cast<Binaryexp5Context *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(769);
        dynamic_cast<Binaryexp5Context *>(_localctx)->e2 = binaryexp4();

                    ops.push_back(StringToFourCC((dynamic_cast<Binaryexp5Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp5Context *>(_localctx)->op->getText() : "")));
                    exprs.push_back(dynamic_cast<Binaryexp5Context *>(_localctx)->e2->tree);
                 
      }
      setState(776);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp5Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp4Context ------------------------------------------------------------------

AnyFXParser::Binaryexp4Context::Binaryexp4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp3Context *> AnyFXParser::Binaryexp4Context::binaryexp3() {
  return getRuleContexts<AnyFXParser::Binaryexp3Context>();
}

AnyFXParser::Binaryexp3Context* AnyFXParser::Binaryexp4Context::binaryexp3(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp3Context>(i);
}


size_t AnyFXParser::Binaryexp4Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp4;
}

void AnyFXParser::Binaryexp4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp4(this);
}

void AnyFXParser::Binaryexp4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp4(this);
}

AnyFXParser::Binaryexp4Context* AnyFXParser::binaryexp4() {
  Binaryexp4Context *_localctx = _tracker.createInstance<Binaryexp4Context>(_ctx, getState());
  enterRule(_localctx, 76, AnyFXParser::RuleBinaryexp4);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(779);
    dynamic_cast<Binaryexp4Context *>(_localctx)->e1 = binaryexp3();
     dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  dynamic_cast<Binaryexp4Context *>(_localctx)->e1->tree;	
    setState(787);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(781);
        dynamic_cast<Binaryexp4Context *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == AnyFXParser::T__27

        || _la == AnyFXParser::T__28)) {
          dynamic_cast<Binaryexp4Context *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(782);
        dynamic_cast<Binaryexp4Context *>(_localctx)->e2 = binaryexp3();

                    ops.push_back(StringToFourCC((dynamic_cast<Binaryexp4Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp4Context *>(_localctx)->op->getText() : "")));
                    exprs.push_back(dynamic_cast<Binaryexp4Context *>(_localctx)->e2->tree);
                 
      }
      setState(789);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp4Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp3Context ------------------------------------------------------------------

AnyFXParser::Binaryexp3Context::Binaryexp3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp2Context *> AnyFXParser::Binaryexp3Context::binaryexp2() {
  return getRuleContexts<AnyFXParser::Binaryexp2Context>();
}

AnyFXParser::Binaryexp2Context* AnyFXParser::Binaryexp3Context::binaryexp2(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp2Context>(i);
}


size_t AnyFXParser::Binaryexp3Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp3;
}

void AnyFXParser::Binaryexp3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp3(this);
}

void AnyFXParser::Binaryexp3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp3(this);
}

AnyFXParser::Binaryexp3Context* AnyFXParser::binaryexp3() {
  Binaryexp3Context *_localctx = _tracker.createInstance<Binaryexp3Context>(_ctx, getState());
  enterRule(_localctx, 78, AnyFXParser::RuleBinaryexp3);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(792);
    dynamic_cast<Binaryexp3Context *>(_localctx)->e1 = binaryexp2();
     dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  dynamic_cast<Binaryexp3Context *>(_localctx)->e1->tree; 
    setState(800);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(794);
        dynamic_cast<Binaryexp3Context *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == AnyFXParser::ADD_OP

        || _la == AnyFXParser::SUB_OP)) {
          dynamic_cast<Binaryexp3Context *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(795);
        dynamic_cast<Binaryexp3Context *>(_localctx)->e2 = binaryexp2();

                    ops.push_back(StringToFourCC((dynamic_cast<Binaryexp3Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp3Context *>(_localctx)->op->getText() : "")));
                    exprs.push_back(dynamic_cast<Binaryexp3Context *>(_localctx)->e2->tree);
                 
      }
      setState(802);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp3Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp2Context ------------------------------------------------------------------

AnyFXParser::Binaryexp2Context::Binaryexp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp1Context *> AnyFXParser::Binaryexp2Context::binaryexp1() {
  return getRuleContexts<AnyFXParser::Binaryexp1Context>();
}

AnyFXParser::Binaryexp1Context* AnyFXParser::Binaryexp2Context::binaryexp1(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp1Context>(i);
}


size_t AnyFXParser::Binaryexp2Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp2;
}

void AnyFXParser::Binaryexp2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp2(this);
}

void AnyFXParser::Binaryexp2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp2(this);
}

AnyFXParser::Binaryexp2Context* AnyFXParser::binaryexp2() {
  Binaryexp2Context *_localctx = _tracker.createInstance<Binaryexp2Context>(_ctx, getState());
  enterRule(_localctx, 80, AnyFXParser::RuleBinaryexp2);

          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
          dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(805);
    dynamic_cast<Binaryexp2Context *>(_localctx)->e1 = binaryexp1();
     dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  dynamic_cast<Binaryexp2Context *>(_localctx)->e1->tree; 
    setState(813);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(807);
        dynamic_cast<Binaryexp2Context *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::DIV_OP - 64))
          | (1ULL << (AnyFXParser::MUL_OP - 64)))) != 0))) {
          dynamic_cast<Binaryexp2Context *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(808);
        dynamic_cast<Binaryexp2Context *>(_localctx)->e2 = binaryexp1();

                    ops.push_back(StringToFourCC((dynamic_cast<Binaryexp2Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp2Context *>(_localctx)->op->getText() : "")));
                    exprs.push_back(dynamic_cast<Binaryexp2Context *>(_localctx)->e2->tree);
                 
      }
      setState(815);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }

            Expression* lhs = dynamic_cast<Binaryexp2Context *>(_localctx)->e1->tree;
            
            int i;
            for ( i = 0; i < exprs.size(); i++)
            {
                lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
            }

            dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  lhs;
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp1Context ------------------------------------------------------------------

AnyFXParser::Binaryexp1Context::Binaryexp1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::Binaryexp0Context* AnyFXParser::Binaryexp1Context::binaryexp0() {
  return getRuleContext<AnyFXParser::Binaryexp0Context>(0);
}


size_t AnyFXParser::Binaryexp1Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp1;
}

void AnyFXParser::Binaryexp1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp1(this);
}

void AnyFXParser::Binaryexp1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp1(this);
}

AnyFXParser::Binaryexp1Context* AnyFXParser::binaryexp1() {
  Binaryexp1Context *_localctx = _tracker.createInstance<Binaryexp1Context>(_ctx, getState());
  enterRule(_localctx, 82, AnyFXParser::RuleBinaryexp1);

          dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(819);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 30) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 30)) & ((1ULL << (AnyFXParser::T__29 - 30))
      | (1ULL << (AnyFXParser::T__30 - 30))
      | (1ULL << (AnyFXParser::NOT - 30))
      | (1ULL << (AnyFXParser::CONNJUGATE - 30))
      | (1ULL << (AnyFXParser::ADD_OP - 30))
      | (1ULL << (AnyFXParser::SUB_OP - 30)))) != 0)) {
      setState(818);
      dynamic_cast<Binaryexp1Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 30) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 30)) & ((1ULL << (AnyFXParser::T__29 - 30))
        | (1ULL << (AnyFXParser::T__30 - 30))
        | (1ULL << (AnyFXParser::NOT - 30))
        | (1ULL << (AnyFXParser::CONNJUGATE - 30))
        | (1ULL << (AnyFXParser::ADD_OP - 30))
        | (1ULL << (AnyFXParser::SUB_OP - 30)))) != 0))) {
        dynamic_cast<Binaryexp1Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(821);
    dynamic_cast<Binaryexp1Context *>(_localctx)->e1 = binaryexp0();

            dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  dynamic_cast<Binaryexp1Context *>(_localctx)->e1->tree;
            if (dynamic_cast<Binaryexp1Context *>(_localctx)->op != nullptr)
            {
                uint32_t op = StringToFourCC((dynamic_cast<Binaryexp1Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp1Context *>(_localctx)->op->getText() : ""));
                dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  new UnaryExpression(op, 0x0, dynamic_cast<Binaryexp1Context *>(_localctx)->e1->tree);
            }

            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp0Context ------------------------------------------------------------------

AnyFXParser::Binaryexp0Context::Binaryexp0Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::BinaryexpatomContext* AnyFXParser::Binaryexp0Context::binaryexpatom() {
  return getRuleContext<AnyFXParser::BinaryexpatomContext>(0);
}

std::vector<AnyFXParser::CallExpressionContext *> AnyFXParser::Binaryexp0Context::callExpression() {
  return getRuleContexts<AnyFXParser::CallExpressionContext>();
}

AnyFXParser::CallExpressionContext* AnyFXParser::Binaryexp0Context::callExpression(size_t i) {
  return getRuleContext<AnyFXParser::CallExpressionContext>(i);
}

std::vector<AnyFXParser::AccessExpressionContext *> AnyFXParser::Binaryexp0Context::accessExpression() {
  return getRuleContexts<AnyFXParser::AccessExpressionContext>();
}

AnyFXParser::AccessExpressionContext* AnyFXParser::Binaryexp0Context::accessExpression(size_t i) {
  return getRuleContext<AnyFXParser::AccessExpressionContext>(i);
}

std::vector<AnyFXParser::ArrayIndexExpressionContext *> AnyFXParser::Binaryexp0Context::arrayIndexExpression() {
  return getRuleContexts<AnyFXParser::ArrayIndexExpressionContext>();
}

AnyFXParser::ArrayIndexExpressionContext* AnyFXParser::Binaryexp0Context::arrayIndexExpression(size_t i) {
  return getRuleContext<AnyFXParser::ArrayIndexExpressionContext>(i);
}


size_t AnyFXParser::Binaryexp0Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp0;
}

void AnyFXParser::Binaryexp0Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp0(this);
}

void AnyFXParser::Binaryexp0Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp0(this);
}

AnyFXParser::Binaryexp0Context* AnyFXParser::binaryexp0() {
  Binaryexp0Context *_localctx = _tracker.createInstance<Binaryexp0Context>(_ctx, getState());
  enterRule(_localctx, 84, AnyFXParser::RuleBinaryexp0);

          dynamic_cast<Binaryexp0Context *>(_localctx)->tree =  nullptr;
          std::vector<Expression*> exprs;
          std::vector<uint32_t> ops;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(847);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(824);
      dynamic_cast<Binaryexp0Context *>(_localctx)->e1 = binaryexpatom();
      setState(826);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
      case 1: {
        setState(825);
        dynamic_cast<Binaryexp0Context *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == AnyFXParser::T__29

        || _la == AnyFXParser::T__30)) {
          dynamic_cast<Binaryexp0Context *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      }

              dynamic_cast<Binaryexp0Context *>(_localctx)->tree =  dynamic_cast<Binaryexp0Context *>(_localctx)->e1->tree;
              if (dynamic_cast<Binaryexp0Context *>(_localctx)->op != nullptr)
              {
                  uint32_t op = StringToFourCC((dynamic_cast<Binaryexp0Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp0Context *>(_localctx)->op->getText() : ""));
                  dynamic_cast<Binaryexp0Context *>(_localctx)->tree =  new UnaryExpression(0x0, op, dynamic_cast<Binaryexp0Context *>(_localctx)->e1->tree);
              }

              _localctx->tree->location = SetupFile();
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(830);
      dynamic_cast<Binaryexp0Context *>(_localctx)->e1 = binaryexpatom();
      setState(842);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(840);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AnyFXParser::LP: {
              setState(831);
              dynamic_cast<Binaryexp0Context *>(_localctx)->callExpressionContext = callExpression();
               ops.push_back(StringToFourCC("()")); exprs.push_back(dynamic_cast<Binaryexp0Context *>(_localctx)->callExpressionContext->tree); 
              break;
            }

            case AnyFXParser::DOT: {
              setState(834);
              dynamic_cast<Binaryexp0Context *>(_localctx)->accessExpressionContext = accessExpression();
               ops.push_back(StringToFourCC(".")); exprs.push_back(dynamic_cast<Binaryexp0Context *>(_localctx)->accessExpressionContext->tree); 
              break;
            }

            case AnyFXParser::LL: {
              setState(837);
              dynamic_cast<Binaryexp0Context *>(_localctx)->arrayIndexExpressionContext = arrayIndexExpression();
               ops.push_back(StringToFourCC("[]")); exprs.push_back(dynamic_cast<Binaryexp0Context *>(_localctx)->arrayIndexExpressionContext->tree); 
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(844);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }

              Expression* lhs = dynamic_cast<Binaryexp0Context *>(_localctx)->e1->tree;
              
              int i;
              for ( i = 0; i < exprs.size(); i++)
              {
                  lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
              }

              dynamic_cast<Binaryexp0Context *>(_localctx)->tree =  lhs;
              _localctx->tree->location = SetupFile();
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryexpatomContext ------------------------------------------------------------------

AnyFXParser::BinaryexpatomContext::BinaryexpatomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::INTEGERLITERAL() {
  return getToken(AnyFXParser::INTEGERLITERAL, 0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::FLOATLITERAL() {
  return getToken(AnyFXParser::FLOATLITERAL, 0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::DOUBLELITERAL() {
  return getToken(AnyFXParser::DOUBLELITERAL, 0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::HEX() {
  return getToken(AnyFXParser::HEX, 0);
}

AnyFXParser::StringContext* AnyFXParser::BinaryexpatomContext::string() {
  return getRuleContext<AnyFXParser::StringContext>(0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::BooleanContext* AnyFXParser::BinaryexpatomContext::boolean() {
  return getRuleContext<AnyFXParser::BooleanContext>(0);
}

AnyFXParser::ParantExpressionContext* AnyFXParser::BinaryexpatomContext::parantExpression() {
  return getRuleContext<AnyFXParser::ParantExpressionContext>(0);
}


size_t AnyFXParser::BinaryexpatomContext::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexpatom;
}

void AnyFXParser::BinaryexpatomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexpatom(this);
}

void AnyFXParser::BinaryexpatomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexpatom(this);
}

AnyFXParser::BinaryexpatomContext* AnyFXParser::binaryexpatom() {
  BinaryexpatomContext *_localctx = _tracker.createInstance<BinaryexpatomContext>(_ctx, getState());
  enterRule(_localctx, 86, AnyFXParser::RuleBinaryexpatom);

          dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(868);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::INTEGERLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(849);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken = match(AnyFXParser::INTEGERLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(atoi((dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken->getText() : "").c_str())); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::FLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(851);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken = match(AnyFXParser::FLOATLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken->getText() : "").c_str())); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::DOUBLELITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(853);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken = match(AnyFXParser::DOUBLELITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken->getText() : "").c_str())); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::HEX: {
        enterOuterAlt(_localctx, 4);
        setState(855);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken = match(AnyFXParser::HEX);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(strtoul((dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken->getText() : "").c_str(), nullptr, 16)); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::QO:
      case AnyFXParser::Q: {
        enterOuterAlt(_localctx, 5);
        setState(857);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->stringContext = string();
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new StringExpression(dynamic_cast<BinaryexpatomContext *>(_localctx)->stringContext->val); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 6);
        setState(860);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new SymbolExpression((dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken->getText() : "")); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::T__0:
      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 7);
        setState(862);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext = boolean();
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new BoolExpression(dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext->val); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::LP: {
        enterOuterAlt(_localctx, 8);
        setState(865);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->parantExpressionContext = parantExpression();
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  dynamic_cast<BinaryexpatomContext *>(_localctx)->parantExpressionContext->tree; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParantExpressionContext ------------------------------------------------------------------

AnyFXParser::ParantExpressionContext::ParantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ParantExpressionContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ParantExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleParantExpression;
}

void AnyFXParser::ParantExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParantExpression(this);
}

void AnyFXParser::ParantExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParantExpression(this);
}

AnyFXParser::ParantExpressionContext* AnyFXParser::parantExpression() {
  ParantExpressionContext *_localctx = _tracker.createInstance<ParantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 88, AnyFXParser::RuleParantExpression);

          dynamic_cast<ParantExpressionContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(870);
    match(AnyFXParser::LP);
    setState(871);
    dynamic_cast<ParantExpressionContext *>(_localctx)->expressionContext = expression();
    setState(872);
    match(AnyFXParser::RP);
     dynamic_cast<ParantExpressionContext *>(_localctx)->tree =  dynamic_cast<ParantExpressionContext *>(_localctx)->expressionContext->tree; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallExpressionContext ------------------------------------------------------------------

AnyFXParser::CallExpressionContext::CallExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::CallExpressionContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::CallExpressionContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::CallExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleCallExpression;
}

void AnyFXParser::CallExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExpression(this);
}

void AnyFXParser::CallExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExpression(this);
}

AnyFXParser::CallExpressionContext* AnyFXParser::callExpression() {
  CallExpressionContext *_localctx = _tracker.createInstance<CallExpressionContext>(_ctx, getState());
  enterRule(_localctx, 90, AnyFXParser::RuleCallExpression);

          dynamic_cast<CallExpressionContext *>(_localctx)->tree =  nullptr;
          std::vector<Expression*> args;
          Symbol::Location location;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(875);
    match(AnyFXParser::LP);
     location = SetupFile(); 
    setState(888);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
      | (1ULL << AnyFXParser::T__1)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::LP)
      | (1ULL << AnyFXParser::NOT)
      | (1ULL << AnyFXParser::QO)
      | (1ULL << AnyFXParser::CONNJUGATE)
      | (1ULL << AnyFXParser::Q))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::ADD_OP - 67))
      | (1ULL << (AnyFXParser::SUB_OP - 67))
      | (1ULL << (AnyFXParser::INTEGERLITERAL - 67))
      | (1ULL << (AnyFXParser::FLOATLITERAL - 67))
      | (1ULL << (AnyFXParser::DOUBLELITERAL - 67))
      | (1ULL << (AnyFXParser::HEX - 67))
      | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
      setState(877);
      dynamic_cast<CallExpressionContext *>(_localctx)->arg0 = expression();
      args.push_back(dynamic_cast<CallExpressionContext *>(_localctx)->arg0->tree); 
      setState(885);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(879);
        match(AnyFXParser::CO);
        setState(880);
        dynamic_cast<CallExpressionContext *>(_localctx)->argn = expression();
         args.push_back(dynamic_cast<CallExpressionContext *>(_localctx)->argn->tree); 
        setState(887);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(890);
    match(AnyFXParser::RP);

            dynamic_cast<CallExpressionContext *>(_localctx)->tree =  new CallExpression(args);
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessExpressionContext ------------------------------------------------------------------

AnyFXParser::AccessExpressionContext::AccessExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::AccessExpressionContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::AccessExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleAccessExpression;
}

void AnyFXParser::AccessExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessExpression(this);
}

void AnyFXParser::AccessExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessExpression(this);
}

AnyFXParser::AccessExpressionContext* AnyFXParser::accessExpression() {
  AccessExpressionContext *_localctx = _tracker.createInstance<AccessExpressionContext>(_ctx, getState());
  enterRule(_localctx, 92, AnyFXParser::RuleAccessExpression);

          dynamic_cast<AccessExpressionContext *>(_localctx)->tree =  nullptr;
          Symbol::Location location;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(893);
    match(AnyFXParser::DOT);
    setState(894);
    dynamic_cast<AccessExpressionContext *>(_localctx)->expressionContext = expression();

            dynamic_cast<AccessExpressionContext *>(_localctx)->tree =  new AccessExpression(dynamic_cast<AccessExpressionContext *>(_localctx)->expressionContext->tree);
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayIndexExpressionContext ------------------------------------------------------------------

AnyFXParser::ArrayIndexExpressionContext::ArrayIndexExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ArrayIndexExpressionContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ArrayIndexExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleArrayIndexExpression;
}

void AnyFXParser::ArrayIndexExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayIndexExpression(this);
}

void AnyFXParser::ArrayIndexExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayIndexExpression(this);
}

AnyFXParser::ArrayIndexExpressionContext* AnyFXParser::arrayIndexExpression() {
  ArrayIndexExpressionContext *_localctx = _tracker.createInstance<ArrayIndexExpressionContext>(_ctx, getState());
  enterRule(_localctx, 94, AnyFXParser::RuleArrayIndexExpression);

          dynamic_cast<ArrayIndexExpressionContext *>(_localctx)->tree =  nullptr;
          Symbol::Location location;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(897);
    match(AnyFXParser::LL);
    setState(898);
    dynamic_cast<ArrayIndexExpressionContext *>(_localctx)->expressionContext = expression();
     location = SetupFile(); 
    setState(900);
    match(AnyFXParser::RR);

            dynamic_cast<ArrayIndexExpressionContext *>(_localctx)->tree =  new ArrayIndexExpression(dynamic_cast<ArrayIndexExpressionContext *>(_localctx)->expressionContext->tree);
            _localctx->tree->location = SetupFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> AnyFXParser::_decisionToDFA;
atn::PredictionContextCache AnyFXParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AnyFXParser::_atn;
std::vector<uint16_t> AnyFXParser::_serializedATN;

std::vector<std::string> AnyFXParser::_ruleNames = {
  "string", "boolean", "preprocess", "entry", "effect", "alias", "annotation", 
  "attribute", "variable", "structureDeclaration", "structure", "functionDeclaration", 
  "codeblock", "function", "program", "state", "declaration", "statement", 
  "expressionStatement", "declarationStatement", "ifStatement", "forStatement", 
  "forRangeStatement", "whileStatement", "scopeStatement", "returnStatement", 
  "continueStatement", "switchStatement", "breakStatement", "expression", 
  "binaryexp12", "binaryexp11", "binaryexp10", "binaryexp9", "binaryexp8", 
  "binaryexp7", "binaryexp6", "binaryexp5", "binaryexp4", "binaryexp3", 
  "binaryexp2", "binaryexp1", "binaryexp0", "binaryexpatom", "parantExpression", 
  "callExpression", "accessExpression", "arrayIndexExpression"
};

std::vector<std::string> AnyFXParser::_literalNames = {
  "", "'true'", "'false'", "'#line'", "'alias'", "'as'", "'struct'", "'program'", 
  "'sampler_state'", "'render_state'", "'if'", "'else'", "'for'", "'while'", 
  "'do'", "'return'", "'continue'", "'switch'", "'case'", "'default'", "'break'", 
  "'+='", "'-='", "'*='", "'/='", "'%='", "'<<='", "'>>='", "'<<'", "'>>'", 
  "'++'", "'--'", "';'", "','", "':'", "'('", "')'", "'{'", "'}'", "'['", 
  "']'", "'.'", "'!'", "'='", "'\"'", "'?'", "'&'", "'&='", "'|'", "'|='", 
  "'^'", "'^='", "'~'", "'''", "'#'", "'\\'", "'<'", "'<='", "'>'", "'>='", 
  "'=='", "'!='", "'&&'", "'||'", "'%'", "'_'", "'@'", "'+'", "'-'", "'/'", 
  "'*'"
};

std::vector<std::string> AnyFXParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "SC", "CO", "COL", 
  "LP", "RP", "LB", "RB", "LL", "RR", "DOT", "NOT", "EQ", "QO", "QU", "AND", 
  "ANDSET", "OR", "ORSET", "XOR", "XORSET", "CONNJUGATE", "Q", "NU", "FORWARDSLASH", 
  "LESS", "LESSEQ", "GREATER", "GREATEREQ", "LOGICEQ", "NOTEQ", "LOGICAND", 
  "LOGICOR", "MOD", "UNDERSC", "SOBAKA", "ADD_OP", "SUB_OP", "DIV_OP", "MUL_OP", 
  "INTEGERLITERAL", "COMMENT", "ML_COMMENT", "FLOATLITERAL", "EXPONENT", 
  "DOUBLELITERAL", "HEX", "IDENTIFIER", "WS"
};

dfa::Vocabulary AnyFXParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AnyFXParser::_tokenNames;

AnyFXParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x51, 0x38a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x66, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x69, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x6f, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x72, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x75, 0xa, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x7b, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x84, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x87, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xaa, 0xa, 0x6, 0xc, 0x6, 
    0xe, 0x6, 0xad, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xc5, 0xa, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xca, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xcd, 
    0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xd2, 0xa, 0xa, 0xc, 
    0xa, 0xe, 0xa, 0xd5, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xde, 0xa, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0xe2, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0xef, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xf2, 0xb, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x100, 0xa, 0xa, 0xc, 
    0xa, 0xe, 0xa, 0x103, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0x108, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x10b, 0xb, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x6, 0xa, 0x116, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x117, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x6, 0xa, 0x122, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x123, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0x129, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x12c, 
    0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0x134, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0x13b, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x13e, 0xb, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x144, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0x147, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 
    0x153, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x156, 0xb, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x15f, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x163, 0xa, 0xc, 0x5, 0xc, 0x165, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x16c, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x16f, 0xb, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0x17b, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x17e, 
    0xb, 0xd, 0x5, 0xd, 0x180, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x7, 0xe, 0x187, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x18a, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x18e, 0xa, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x7, 0x10, 0x199, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x19c, 0xb, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1a6, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0x1a9, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x1b2, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x1bb, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1be, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x5, 0x13, 0x1e3, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x1f3, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x1f6, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x1fc, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0x20c, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 
    0x17, 0x219, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x21c, 0xb, 0x17, 0x5, 
    0x17, 0x21e, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0x224, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x22d, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x230, 0xb, 0x17, 0x5, 0x17, 0x232, 0xa, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0x25b, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x265, 0xa, 0x1a, 0xc, 0x1a, 
    0xe, 0x1a, 0x268, 0xb, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x272, 0xa, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x289, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 
    0x28c, 0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x5, 0x1d, 0x293, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 
    0x20, 0x2ac, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x2af, 0xb, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x7, 0x21, 0x2b9, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x2bc, 
    0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x2c6, 0xa, 0x22, 0xc, 0x22, 
    0xe, 0x22, 0x2c9, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x2d3, 0xa, 0x23, 
    0xc, 0x23, 0xe, 0x23, 0x2d6, 0xb, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x2e0, 
    0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x2e3, 0xb, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 
    0x25, 0x2ed, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x2f0, 0xb, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x7, 0x26, 0x2fa, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x2fd, 
    0xb, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x307, 0xa, 0x27, 0xc, 0x27, 
    0xe, 0x27, 0x30a, 0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x314, 0xa, 0x28, 
    0xc, 0x28, 0xe, 0x28, 0x317, 0xb, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x321, 
    0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x324, 0xb, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 
    0x2a, 0x32e, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x331, 0xb, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x5, 0x2b, 0x336, 0xa, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x33d, 0xa, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 
    0x34b, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x34e, 0xb, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x5, 0x2c, 0x352, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x367, 0xa, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 
    0x376, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x379, 0xb, 0x2f, 0x5, 0x2f, 
    0x37b, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x4, 0x85, 0xab, 0x2, 0x32, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x2, 0xd, 0x3, 
    0x2, 0x2e, 0x2e, 0x3, 0x2, 0x37, 0x37, 0x3, 0x2, 0x27, 0x28, 0x7, 0x2, 
    0x17, 0x1d, 0x2d, 0x2d, 0x31, 0x31, 0x33, 0x33, 0x35, 0x35, 0x3, 0x2, 
    0x3e, 0x3f, 0x3, 0x2, 0x3a, 0x3d, 0x3, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x45, 
    0x46, 0x4, 0x2, 0x42, 0x42, 0x47, 0x48, 0x6, 0x2, 0x20, 0x21, 0x2c, 
    0x2c, 0x36, 0x36, 0x45, 0x46, 0x3, 0x2, 0x20, 0x21, 0x2, 0x3b5, 0x2, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x4, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x8a, 0x3, 0x2, 0x2, 0x2, 0xa, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xae, 0x3, 0x2, 0x2, 0x2, 0xe, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x12, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x16d, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x18f, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1b1, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1e2, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1e8, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x238, 0x3, 0x2, 0x2, 0x2, 0x30, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x32, 0x25c, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x276, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x297, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x29e, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x42, 0x2bf, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x46, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x2e6, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x300, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x31a, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x327, 0x3, 0x2, 0x2, 0x2, 0x54, 0x335, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x351, 0x3, 0x2, 0x2, 0x2, 0x58, 0x366, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x368, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x36d, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x60, 0x383, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x67, 0x7, 0x2e, 0x2, 0x2, 0x63, 0x64, 0xa, 0x2, 0x2, 0x2, 0x64, 0x66, 
    0x8, 0x2, 0x1, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x75, 0x7, 0x2e, 0x2, 0x2, 0x6b, 0x70, 0x7, 0x37, 0x2, 0x2, 
    0x6c, 0x6d, 0xa, 0x3, 0x2, 0x2, 0x6d, 0x6f, 0x8, 0x2, 0x1, 0x2, 0x6e, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x7, 0x37, 
    0x2, 0x2, 0x74, 0x62, 0x3, 0x2, 0x2, 0x2, 0x74, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x3, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x3, 0x2, 0x2, 
    0x77, 0x7b, 0x8, 0x3, 0x1, 0x2, 0x78, 0x79, 0x7, 0x4, 0x2, 0x2, 0x79, 
    0x7b, 0x8, 0x3, 0x1, 0x2, 0x7a, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x8, 
    0x4, 0x1, 0x2, 0x7d, 0x7e, 0x7, 0x5, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x49, 
    0x2, 0x2, 0x7f, 0x80, 0x5, 0x2, 0x2, 0x2, 0x80, 0x81, 0x8, 0x4, 0x1, 
    0x2, 0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 0xb, 0x2, 0x2, 0x2, 
    0x83, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x2, 0x2, 0x3, 0x89, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x8b, 0x5, 0xa, 0x6, 0x2, 0x8b, 0x8c, 0x8, 0x5, 0x1, 
    0x2, 0x8c, 0x8d, 0x7, 0x2, 0x2, 0x3, 0x8d, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8f, 0x5, 0xc, 0x7, 0x2, 0x8f, 0x90, 0x7, 0x22, 0x2, 0x2, 0x90, 
    0x91, 0x8, 0x6, 0x1, 0x2, 0x91, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 
    0x5, 0x18, 0xd, 0x2, 0x93, 0x94, 0x7, 0x22, 0x2, 0x2, 0x94, 0x95, 0x8, 
    0x6, 0x1, 0x2, 0x95, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x5, 0x1c, 
    0xf, 0x2, 0x97, 0x98, 0x8, 0x6, 0x1, 0x2, 0x98, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x9a, 0x5, 0x12, 0xa, 0x2, 0x9a, 0x9b, 0x7, 0x22, 0x2, 0x2, 
    0x9b, 0x9c, 0x8, 0x6, 0x1, 0x2, 0x9c, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9e, 0x5, 0x16, 0xc, 0x2, 0x9e, 0x9f, 0x7, 0x22, 0x2, 0x2, 0x9f, 0xa0, 
    0x8, 0x6, 0x1, 0x2, 0xa0, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 
    0x20, 0x11, 0x2, 0xa2, 0xa3, 0x7, 0x22, 0x2, 0x2, 0xa3, 0xa4, 0x8, 0x6, 
    0x1, 0x2, 0xa4, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x1e, 0x10, 
    0x2, 0xa6, 0xa7, 0x7, 0x22, 0x2, 0x2, 0xa7, 0xa8, 0x8, 0x6, 0x1, 0x2, 
    0xa8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xa9, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x96, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xb, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xaf, 0x7, 0x6, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x50, 0x2, 0x2, 0xb0, 
    0xb1, 0x7, 0x7, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x50, 0x2, 0x2, 0xb2, 0xb3, 
    0x8, 0x7, 0x1, 0x2, 0xb3, 0xb4, 0x8, 0x7, 0x1, 0x2, 0xb4, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x44, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x50, 
    0x2, 0x2, 0xb7, 0xb8, 0x7, 0x25, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x3c, 0x1f, 
    0x2, 0xb9, 0xba, 0x7, 0x26, 0x2, 0x2, 0xba, 0xbb, 0x8, 0x8, 0x1, 0x2, 
    0xbb, 0xf, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x50, 0x2, 0x2, 0xbd, 
    0xbe, 0x7, 0x25, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x3c, 0x1f, 0x2, 0xbf, 0xc0, 
    0x7, 0x26, 0x2, 0x2, 0xc0, 0xc1, 0x8, 0x9, 0x1, 0x2, 0xc1, 0xc5, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x50, 0x2, 0x2, 0xc3, 0xc5, 0x8, 0x9, 
    0x1, 0x2, 0xc4, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xc5, 0x11, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0xe, 0x8, 0x2, 
    0xc7, 0xc8, 0x8, 0xa, 0x1, 0x2, 0xc8, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x10, 
    0x9, 0x2, 0xcf, 0xd0, 0x8, 0xa, 0x1, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd1, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 
    0x7, 0x50, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x50, 0x2, 0x2, 0xd8, 0xe1, 0x8, 
    0xa, 0x1, 0x2, 0xd9, 0xdd, 0x7, 0x29, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x3c, 
    0x1f, 0x2, 0xdb, 0xdc, 0x8, 0xa, 0x1, 0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x2a, 0x2, 0x2, 0xe0, 
    0xe2, 0x8, 0xa, 0x1, 0x2, 0xe1, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0x133, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 
    0x2d, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x27, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x50, 
    0x2, 0x2, 0xe6, 0xe7, 0x8, 0xa, 0x1, 0x2, 0xe7, 0xe8, 0x7, 0x25, 0x2, 
    0x2, 0xe8, 0xe9, 0x5, 0x3c, 0x1f, 0x2, 0xe9, 0xf0, 0x8, 0xa, 0x1, 0x2, 
    0xea, 0xeb, 0x7, 0x23, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x3c, 0x1f, 0x2, 0xec, 
    0xed, 0x8, 0xa, 0x1, 0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xea, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf3, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x26, 0x2, 
    0x2, 0xf4, 0x109, 0x8, 0xa, 0x1, 0x2, 0xf5, 0xf6, 0x7, 0x23, 0x2, 0x2, 
    0xf6, 0xf7, 0x7, 0x50, 0x2, 0x2, 0xf7, 0xf8, 0x8, 0xa, 0x1, 0x2, 0xf8, 
    0xf9, 0x7, 0x25, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x3c, 0x1f, 0x2, 0xfa, 0x101, 
    0x8, 0xa, 0x1, 0x2, 0xfb, 0xfc, 0x7, 0x23, 0x2, 0x2, 0xfc, 0xfd, 0x5, 
    0x3c, 0x1f, 0x2, 0xfd, 0xfe, 0x8, 0xa, 0x1, 0x2, 0xfe, 0x100, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x105, 0x7, 0x26, 0x2, 0x2, 0x105, 0x106, 0x8, 0xa, 0x1, 0x2, 
    0x106, 0x108, 0x3, 0x2, 0x2, 0x2, 0x107, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x108, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 
    0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x28, 0x2, 0x2, 0x10d, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x2d, 0x2, 0x2, 0x10f, 
    0x110, 0x7, 0x27, 0x2, 0x2, 0x110, 0x111, 0x8, 0xa, 0x1, 0x2, 0x111, 
    0x115, 0x7, 0x27, 0x2, 0x2, 0x112, 0x113, 0x5, 0x3c, 0x1f, 0x2, 0x113, 
    0x114, 0x8, 0xa, 0x1, 0x2, 0x114, 0x116, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x28, 0x2, 0x2, 0x11a, 
    0x12a, 0x8, 0xa, 0x1, 0x2, 0x11b, 0x11c, 0x7, 0x23, 0x2, 0x2, 0x11c, 
    0x11d, 0x8, 0xa, 0x1, 0x2, 0x11d, 0x121, 0x7, 0x27, 0x2, 0x2, 0x11e, 
    0x11f, 0x5, 0x3c, 0x1f, 0x2, 0x11f, 0x120, 0x8, 0xa, 0x1, 0x2, 0x120, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x122, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 
    0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 
    0x126, 0x7, 0x28, 0x2, 0x2, 0x126, 0x127, 0x8, 0xa, 0x1, 0x2, 0x127, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x128, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x129, 
    0x12c, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12c, 
    0x12a, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x7, 0x28, 0x2, 0x2, 0x12e, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x7, 0x2d, 0x2, 0x2, 0x130, 
    0x131, 0x5, 0x3c, 0x1f, 0x2, 0x131, 0x132, 0x8, 0xa, 0x1, 0x2, 0x132, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x133, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x133, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x133, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 
    0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 
    0x8, 0xa, 0x1, 0x2, 0x136, 0x13, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x5, 
    0xe, 0x8, 0x2, 0x138, 0x139, 0x8, 0xb, 0x1, 0x2, 0x139, 0x13b, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13e, 0x3, 
    0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 
    0x2, 0x2, 0x2, 0x13d, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x13f, 0x145, 0x7, 0x8, 0x2, 0x2, 0x140, 0x141, 0x5, 
    0x10, 0x9, 0x2, 0x141, 0x142, 0x8, 0xb, 0x1, 0x2, 0x142, 0x144, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x140, 0x3, 0x2, 0x2, 0x2, 0x144, 0x147, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x146, 0x148, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 
    0x2, 0x2, 0x2, 0x148, 0x149, 0x7, 0x50, 0x2, 0x2, 0x149, 0x14a, 0x8, 
    0xb, 0x1, 0x2, 0x14a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x5, 0x14, 
    0xb, 0x2, 0x14c, 0x14d, 0x8, 0xc, 0x1, 0x2, 0x14d, 0x154, 0x7, 0x27, 
    0x2, 0x2, 0x14e, 0x14f, 0x5, 0x12, 0xa, 0x2, 0x14f, 0x150, 0x8, 0xc, 
    0x1, 0x2, 0x150, 0x151, 0x7, 0x22, 0x2, 0x2, 0x151, 0x153, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x153, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 
    0x2, 0x2, 0x155, 0x157, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x164, 0x7, 0x28, 0x2, 0x2, 0x158, 0x159, 0x7, 0x50, 
    0x2, 0x2, 0x159, 0x162, 0x8, 0xc, 0x1, 0x2, 0x15a, 0x15e, 0x7, 0x29, 
    0x2, 0x2, 0x15b, 0x15c, 0x5, 0x3c, 0x1f, 0x2, 0x15c, 0x15d, 0x8, 0xc, 
    0x1, 0x2, 0x15d, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x161, 0x7, 0x2a, 0x2, 0x2, 0x161, 0x163, 0x8, 0xc, 
    0x1, 0x2, 0x162, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x165, 0x3, 0x2, 0x2, 0x2, 0x164, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x167, 0x8, 0xc, 0x1, 0x2, 0x167, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x168, 0x169, 0x5, 0x10, 0x9, 0x2, 0x169, 0x16a, 0x8, 0xd, 0x1, 
    0x2, 0x16a, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x168, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 
    0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x170, 0x3, 0x2, 0x2, 
    0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x7, 0x50, 0x2, 
    0x2, 0x171, 0x172, 0x7, 0x50, 0x2, 0x2, 0x172, 0x173, 0x8, 0xd, 0x1, 
    0x2, 0x173, 0x17f, 0x7, 0x25, 0x2, 0x2, 0x174, 0x175, 0x5, 0x12, 0xa, 
    0x2, 0x175, 0x17c, 0x8, 0xd, 0x1, 0x2, 0x176, 0x177, 0x7, 0x23, 0x2, 
    0x2, 0x177, 0x178, 0x5, 0x12, 0xa, 0x2, 0x178, 0x179, 0x8, 0xd, 0x1, 
    0x2, 0x179, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x17b, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 
    0x2, 0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x180, 0x3, 0x2, 0x2, 
    0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x3, 0x2, 0x2, 
    0x2, 0x181, 0x182, 0x7, 0x26, 0x2, 0x2, 0x182, 0x183, 0x8, 0xd, 0x1, 
    0x2, 0x183, 0x19, 0x3, 0x2, 0x2, 0x2, 0x184, 0x188, 0x7, 0x27, 0x2, 
    0x2, 0x185, 0x187, 0x5, 0x1a, 0xe, 0x2, 0x186, 0x185, 0x3, 0x2, 0x2, 
    0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18e, 0x7, 0x28, 0x2, 
    0x2, 0x18c, 0x18e, 0xa, 0x4, 0x2, 0x2, 0x18d, 0x184, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x18f, 0x190, 0x5, 0x18, 0xd, 0x2, 0x190, 0x191, 0x8, 0xf, 0x1, 0x2, 
    0x191, 0x192, 0x8, 0xf, 0x1, 0x2, 0x192, 0x193, 0x5, 0x32, 0x1a, 0x2, 
    0x193, 0x194, 0x8, 0xf, 0x1, 0x2, 0x194, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x195, 
    0x196, 0x5, 0xe, 0x8, 0x2, 0x196, 0x197, 0x8, 0x10, 0x1, 0x2, 0x197, 
    0x199, 0x3, 0x2, 0x2, 0x2, 0x198, 0x195, 0x3, 0x2, 0x2, 0x2, 0x199, 
    0x19c, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x19a, 
    0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19c, 
    0x19a, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x7, 0x9, 0x2, 0x2, 0x19e, 
    0x19f, 0x7, 0x50, 0x2, 0x2, 0x19f, 0x1a0, 0x8, 0x10, 0x1, 0x2, 0x1a0, 
    0x1a7, 0x7, 0x27, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x3c, 0x1f, 0x2, 0x1a2, 
    0x1a3, 0x8, 0x10, 0x1, 0x2, 0x1a3, 0x1a4, 0x7, 0x22, 0x2, 0x2, 0x1a4, 
    0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a6, 
    0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
    0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
    0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x7, 0x28, 0x2, 0x2, 0x1ab, 
    0x1ac, 0x8, 0x10, 0x1, 0x2, 0x1ac, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1ad, 
    0x1ae, 0x7, 0xa, 0x2, 0x2, 0x1ae, 0x1b2, 0x8, 0x11, 0x1, 0x2, 0x1af, 
    0x1b0, 0x7, 0xb, 0x2, 0x2, 0x1b0, 0x1b2, 0x8, 0x11, 0x1, 0x2, 0x1b1, 
    0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 
    0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x7, 0x50, 0x2, 0x2, 0x1b4, 
    0x1b5, 0x8, 0x11, 0x1, 0x2, 0x1b5, 0x1bc, 0x7, 0x27, 0x2, 0x2, 0x1b6, 
    0x1b7, 0x5, 0x3c, 0x1f, 0x2, 0x1b7, 0x1b8, 0x8, 0x11, 0x1, 0x2, 0x1b8, 
    0x1b9, 0x7, 0x22, 0x2, 0x2, 0x1b9, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1ba, 
    0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1bc, 
    0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
    0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bf, 
    0x1c0, 0x7, 0x28, 0x2, 0x2, 0x1c0, 0x1c1, 0x8, 0x11, 0x1, 0x2, 0x1c1, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x5, 0x12, 0xa, 0x2, 0x1c3, 
    0x1c4, 0x8, 0x12, 0x1, 0x2, 0x1c4, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1c6, 0x5, 0x28, 0x15, 0x2, 0x1c6, 0x1c7, 0x7, 0x22, 0x2, 0x2, 0x1c7, 
    0x1c8, 0x8, 0x13, 0x1, 0x2, 0x1c8, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
    0x1ca, 0x5, 0x2a, 0x16, 0x2, 0x1ca, 0x1cb, 0x8, 0x13, 0x1, 0x2, 0x1cb, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0x32, 0x1a, 0x2, 0x1cd, 
    0x1ce, 0x8, 0x13, 0x1, 0x2, 0x1ce, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
    0x1d0, 0x5, 0x2c, 0x17, 0x2, 0x1d0, 0x1d1, 0x8, 0x13, 0x1, 0x2, 0x1d1, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x5, 0x30, 0x19, 0x2, 0x1d3, 
    0x1d4, 0x8, 0x13, 0x1, 0x2, 0x1d4, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
    0x1d6, 0x5, 0x34, 0x1b, 0x2, 0x1d6, 0x1d7, 0x8, 0x13, 0x1, 0x2, 0x1d7, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x5, 0x36, 0x1c, 0x2, 0x1d9, 
    0x1da, 0x8, 0x13, 0x1, 0x2, 0x1da, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1db, 
    0x1dc, 0x5, 0x3a, 0x1e, 0x2, 0x1dc, 0x1dd, 0x8, 0x13, 0x1, 0x2, 0x1dd, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x5, 0x26, 0x14, 0x2, 0x1df, 
    0x1e0, 0x8, 0x13, 0x1, 0x2, 0x1e0, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
    0x1e3, 0x7, 0x22, 0x2, 0x2, 0x1e2, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1db, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 
    0x5, 0x3c, 0x1f, 0x2, 0x1e5, 0x1e6, 0x7, 0x22, 0x2, 0x2, 0x1e6, 0x1e7, 
    0x8, 0x14, 0x1, 0x2, 0x1e7, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 
    0x7, 0x50, 0x2, 0x2, 0x1e9, 0x1ea, 0x8, 0x15, 0x1, 0x2, 0x1ea, 0x1eb, 
    0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x50, 0x2, 0x2, 0x1ec, 0x1f4, 
    0x7, 0x50, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x29, 0x2, 0x2, 0x1ee, 0x1ef, 
    0x5, 0x3c, 0x1f, 0x2, 0x1ef, 0x1f0, 0x7, 0x2a, 0x2, 0x2, 0x1f0, 0x1f1, 
    0x8, 0x15, 0x1, 0x2, 0x1f1, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ed, 
    0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 
    0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1fb, 
    0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 
    0x7, 0x2d, 0x2, 0x2, 0x1f8, 0x1f9, 0x5, 0x3c, 0x1f, 0x2, 0x1f9, 0x1fa, 
    0x8, 0x15, 0x1, 0x2, 0x1fa, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1f7, 
    0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 
    0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x8, 0x15, 0x1, 0x2, 0x1fe, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x7, 0xc, 0x2, 0x2, 0x200, 0x201, 
    0x8, 0x16, 0x1, 0x2, 0x201, 0x202, 0x7, 0x25, 0x2, 0x2, 0x202, 0x203, 
    0x5, 0x3c, 0x1f, 0x2, 0x203, 0x204, 0x8, 0x16, 0x1, 0x2, 0x204, 0x205, 
    0x7, 0x26, 0x2, 0x2, 0x205, 0x206, 0x5, 0x24, 0x13, 0x2, 0x206, 0x20b, 
    0x8, 0x16, 0x1, 0x2, 0x207, 0x208, 0x7, 0xd, 0x2, 0x2, 0x208, 0x209, 
    0x5, 0x24, 0x13, 0x2, 0x209, 0x20a, 0x8, 0x16, 0x1, 0x2, 0x20a, 0x20c, 
    0x3, 0x2, 0x2, 0x2, 0x20b, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 
    0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 
    0x8, 0x16, 0x1, 0x2, 0x20e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x210, 
    0x7, 0xe, 0x2, 0x2, 0x210, 0x211, 0x8, 0x17, 0x1, 0x2, 0x211, 0x21d, 
    0x7, 0x25, 0x2, 0x2, 0x212, 0x213, 0x5, 0x22, 0x12, 0x2, 0x213, 0x21a, 
    0x8, 0x17, 0x1, 0x2, 0x214, 0x215, 0x7, 0x23, 0x2, 0x2, 0x215, 0x216, 
    0x5, 0x22, 0x12, 0x2, 0x216, 0x217, 0x8, 0x17, 0x1, 0x2, 0x217, 0x219, 
    0x3, 0x2, 0x2, 0x2, 0x218, 0x214, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21c, 
    0x3, 0x2, 0x2, 0x2, 0x21a, 0x218, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 
    0x3, 0x2, 0x2, 0x2, 0x21b, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21a, 
    0x3, 0x2, 0x2, 0x2, 0x21d, 0x212, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 
    0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x223, 
    0x7, 0x22, 0x2, 0x2, 0x220, 0x221, 0x5, 0x3c, 0x1f, 0x2, 0x221, 0x222, 
    0x8, 0x17, 0x1, 0x2, 0x222, 0x224, 0x3, 0x2, 0x2, 0x2, 0x223, 0x220, 
    0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 
    0x3, 0x2, 0x2, 0x2, 0x225, 0x231, 0x7, 0x22, 0x2, 0x2, 0x226, 0x227, 
    0x5, 0x3c, 0x1f, 0x2, 0x227, 0x22e, 0x8, 0x17, 0x1, 0x2, 0x228, 0x229, 
    0x7, 0x23, 0x2, 0x2, 0x229, 0x22a, 0x5, 0x3c, 0x1f, 0x2, 0x22a, 0x22b, 
    0x8, 0x17, 0x1, 0x2, 0x22b, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x228, 
    0x3, 0x2, 0x2, 0x2, 0x22d, 0x230, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22c, 
    0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x232, 
    0x3, 0x2, 0x2, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x231, 0x226, 
    0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 
    0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x7, 0x26, 0x2, 0x2, 0x234, 0x235, 
    0x5, 0x24, 0x13, 0x2, 0x235, 0x236, 0x8, 0x17, 0x1, 0x2, 0x236, 0x237, 
    0x8, 0x17, 0x1, 0x2, 0x237, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 
    0x7, 0xe, 0x2, 0x2, 0x239, 0x23a, 0x8, 0x18, 0x1, 0x2, 0x23a, 0x23b, 
    0x7, 0x25, 0x2, 0x2, 0x23b, 0x23c, 0x7, 0x50, 0x2, 0x2, 0x23c, 0x23d, 
    0x7, 0x24, 0x2, 0x2, 0x23d, 0x23e, 0x7, 0x50, 0x2, 0x2, 0x23e, 0x23f, 
    0x7, 0x2b, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x2b, 0x2, 0x2, 0x240, 0x241, 
    0x7, 0x50, 0x2, 0x2, 0x241, 0x242, 0x7, 0x26, 0x2, 0x2, 0x242, 0x243, 
    0x5, 0x24, 0x13, 0x2, 0x243, 0x244, 0x8, 0x18, 0x1, 0x2, 0x244, 0x245, 
    0x8, 0x18, 0x1, 0x2, 0x245, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 
    0x7, 0xf, 0x2, 0x2, 0x247, 0x248, 0x8, 0x19, 0x1, 0x2, 0x248, 0x249, 
    0x7, 0x25, 0x2, 0x2, 0x249, 0x24a, 0x5, 0x3c, 0x1f, 0x2, 0x24a, 0x24b, 
    0x8, 0x19, 0x1, 0x2, 0x24b, 0x24c, 0x7, 0x26, 0x2, 0x2, 0x24c, 0x24d, 
    0x5, 0x24, 0x13, 0x2, 0x24d, 0x24e, 0x8, 0x19, 0x1, 0x2, 0x24e, 0x25b, 
    0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x10, 0x2, 0x2, 0x250, 0x251, 
    0x8, 0x19, 0x1, 0x2, 0x251, 0x252, 0x5, 0x24, 0x13, 0x2, 0x252, 0x253, 
    0x8, 0x19, 0x1, 0x2, 0x253, 0x254, 0x7, 0xf, 0x2, 0x2, 0x254, 0x255, 
    0x7, 0x25, 0x2, 0x2, 0x255, 0x256, 0x5, 0x3c, 0x1f, 0x2, 0x256, 0x257, 
    0x8, 0x19, 0x1, 0x2, 0x257, 0x258, 0x7, 0x26, 0x2, 0x2, 0x258, 0x259, 
    0x8, 0x19, 0x1, 0x2, 0x259, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x246, 
    0x3, 0x2, 0x2, 0x2, 0x25a, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x25c, 0x25d, 0x7, 0x27, 0x2, 0x2, 0x25d, 0x266, 0x8, 
    0x1a, 0x1, 0x2, 0x25e, 0x25f, 0x5, 0x24, 0x13, 0x2, 0x25f, 0x260, 0x8, 
    0x1a, 0x1, 0x2, 0x260, 0x265, 0x3, 0x2, 0x2, 0x2, 0x261, 0x262, 0x5, 
    0x22, 0x12, 0x2, 0x262, 0x263, 0x8, 0x1a, 0x1, 0x2, 0x263, 0x265, 0x3, 
    0x2, 0x2, 0x2, 0x264, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x264, 0x261, 0x3, 
    0x2, 0x2, 0x2, 0x265, 0x268, 0x3, 0x2, 0x2, 0x2, 0x266, 0x264, 0x3, 
    0x2, 0x2, 0x2, 0x266, 0x267, 0x3, 0x2, 0x2, 0x2, 0x267, 0x269, 0x3, 
    0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x7, 
    0x28, 0x2, 0x2, 0x26a, 0x26b, 0x8, 0x1a, 0x1, 0x2, 0x26b, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x26c, 0x26d, 0x7, 0x11, 0x2, 0x2, 0x26d, 0x271, 0x8, 
    0x1b, 0x1, 0x2, 0x26e, 0x26f, 0x5, 0x3c, 0x1f, 0x2, 0x26f, 0x270, 0x8, 
    0x1b, 0x1, 0x2, 0x270, 0x272, 0x3, 0x2, 0x2, 0x2, 0x271, 0x26e, 0x3, 
    0x2, 0x2, 0x2, 0x271, 0x272, 0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 
    0x2, 0x2, 0x2, 0x273, 0x274, 0x7, 0x22, 0x2, 0x2, 0x274, 0x275, 0x8, 
    0x1b, 0x1, 0x2, 0x275, 0x35, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x7, 
    0x12, 0x2, 0x2, 0x277, 0x278, 0x8, 0x1c, 0x1, 0x2, 0x278, 0x279, 0x7, 
    0x22, 0x2, 0x2, 0x279, 0x27a, 0x8, 0x1c, 0x1, 0x2, 0x27a, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x27b, 0x27c, 0x7, 0x13, 0x2, 0x2, 0x27c, 0x27d, 0x8, 
    0x1d, 0x1, 0x2, 0x27d, 0x27e, 0x7, 0x25, 0x2, 0x2, 0x27e, 0x27f, 0x5, 
    0x3c, 0x1f, 0x2, 0x27f, 0x280, 0x7, 0x26, 0x2, 0x2, 0x280, 0x281, 0x8, 
    0x1d, 0x1, 0x2, 0x281, 0x28a, 0x7, 0x27, 0x2, 0x2, 0x282, 0x283, 0x7, 
    0x14, 0x2, 0x2, 0x283, 0x284, 0x7, 0x50, 0x2, 0x2, 0x284, 0x285, 0x7, 
    0x24, 0x2, 0x2, 0x285, 0x286, 0x5, 0x24, 0x13, 0x2, 0x286, 0x287, 0x8, 
    0x1d, 0x1, 0x2, 0x287, 0x289, 0x3, 0x2, 0x2, 0x2, 0x288, 0x282, 0x3, 
    0x2, 0x2, 0x2, 0x289, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x288, 0x3, 
    0x2, 0x2, 0x2, 0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x292, 0x3, 
    0x2, 0x2, 0x2, 0x28c, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x7, 
    0x15, 0x2, 0x2, 0x28e, 0x28f, 0x7, 0x24, 0x2, 0x2, 0x28f, 0x290, 0x5, 
    0x24, 0x13, 0x2, 0x290, 0x291, 0x8, 0x1d, 0x1, 0x2, 0x291, 0x293, 0x3, 
    0x2, 0x2, 0x2, 0x292, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 0x3, 
    0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x7, 
    0x28, 0x2, 0x2, 0x295, 0x296, 0x8, 0x1d, 0x1, 0x2, 0x296, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x297, 0x298, 0x7, 0x16, 0x2, 0x2, 0x298, 0x299, 0x7, 
    0x22, 0x2, 0x2, 0x299, 0x29a, 0x8, 0x1e, 0x1, 0x2, 0x29a, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x29b, 0x29c, 0x5, 0x3e, 0x20, 0x2, 0x29c, 0x29d, 0x8, 
    0x1f, 0x1, 0x2, 0x29d, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29f, 0x5, 
    0x40, 0x21, 0x2, 0x29f, 0x2ad, 0x8, 0x20, 0x1, 0x2, 0x2a0, 0x2a1, 0x9, 
    0x5, 0x2, 0x2, 0x2a1, 0x2a2, 0x8, 0x20, 0x1, 0x2, 0x2a2, 0x2a3, 0x5, 
    0x40, 0x21, 0x2, 0x2a3, 0x2a4, 0x8, 0x20, 0x1, 0x2, 0x2a4, 0x2ac, 0x3, 
    0x2, 0x2, 0x2, 0x2a5, 0x2a6, 0x7, 0x2f, 0x2, 0x2, 0x2a6, 0x2a7, 0x5, 
    0x3c, 0x1f, 0x2, 0x2a7, 0x2a8, 0x7, 0x24, 0x2, 0x2, 0x2a8, 0x2a9, 0x5, 
    0x3c, 0x1f, 0x2, 0x2a9, 0x2aa, 0x8, 0x20, 0x1, 0x2, 0x2aa, 0x2ac, 0x3, 
    0x2, 0x2, 0x2, 0x2ab, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2a5, 0x3, 
    0x2, 0x2, 0x2, 0x2ac, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ab, 0x3, 
    0x2, 0x2, 0x2, 0x2ad, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b0, 0x3, 
    0x2, 0x2, 0x2, 0x2af, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b1, 0x8, 
    0x20, 0x1, 0x2, 0x2b1, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x5, 
    0x42, 0x22, 0x2, 0x2b3, 0x2ba, 0x8, 0x21, 0x1, 0x2, 0x2b4, 0x2b5, 0x7, 
    0x41, 0x2, 0x2, 0x2b5, 0x2b6, 0x5, 0x42, 0x22, 0x2, 0x2b6, 0x2b7, 0x8, 
    0x21, 0x1, 0x2, 0x2b7, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b4, 0x3, 
    0x2, 0x2, 0x2, 0x2b9, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b8, 0x3, 
    0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bd, 0x3, 
    0x2, 0x2, 0x2, 0x2bc, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x8, 
    0x21, 0x1, 0x2, 0x2be, 0x41, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c0, 0x5, 
    0x44, 0x23, 0x2, 0x2c0, 0x2c7, 0x8, 0x22, 0x1, 0x2, 0x2c1, 0x2c2, 0x7, 
    0x40, 0x2, 0x2, 0x2c2, 0x2c3, 0x5, 0x44, 0x23, 0x2, 0x2c3, 0x2c4, 0x8, 
    0x22, 0x1, 0x2, 0x2c4, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c1, 0x3, 
    0x2, 0x2, 0x2, 0x2c6, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 
    0x2, 0x2, 0x2, 0x2c7, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2ca, 0x3, 
    0x2, 0x2, 0x2, 0x2c9, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 0x8, 
    0x22, 0x1, 0x2, 0x2cb, 0x43, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 0x5, 
    0x46, 0x24, 0x2, 0x2cd, 0x2d4, 0x8, 0x23, 0x1, 0x2, 0x2ce, 0x2cf, 0x7, 
    0x32, 0x2, 0x2, 0x2cf, 0x2d0, 0x5, 0x46, 0x24, 0x2, 0x2d0, 0x2d1, 0x8, 
    0x23, 0x1, 0x2, 0x2d1, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2ce, 0x3, 
    0x2, 0x2, 0x2, 0x2d3, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d2, 0x3, 
    0x2, 0x2, 0x2, 0x2d4, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d7, 0x3, 
    0x2, 0x2, 0x2, 0x2d6, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x8, 
    0x23, 0x1, 0x2, 0x2d8, 0x45, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x5, 
    0x48, 0x25, 0x2, 0x2da, 0x2e1, 0x8, 0x24, 0x1, 0x2, 0x2db, 0x2dc, 0x7, 
    0x34, 0x2, 0x2, 0x2dc, 0x2dd, 0x5, 0x48, 0x25, 0x2, 0x2dd, 0x2de, 0x8, 
    0x24, 0x1, 0x2, 0x2de, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2db, 0x3, 
    0x2, 0x2, 0x2, 0x2e0, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2df, 0x3, 
    0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e4, 0x3, 
    0x2, 0x2, 0x2, 0x2e3, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0x8, 
    0x24, 0x1, 0x2, 0x2e5, 0x47, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 0x5, 
    0x4a, 0x26, 0x2, 0x2e7, 0x2ee, 0x8, 0x25, 0x1, 0x2, 0x2e8, 0x2e9, 0x7, 
    0x30, 0x2, 0x2, 0x2e9, 0x2ea, 0x5, 0x4a, 0x26, 0x2, 0x2ea, 0x2eb, 0x8, 
    0x25, 0x1, 0x2, 0x2eb, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2e8, 0x3, 
    0x2, 0x2, 0x2, 0x2ed, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ec, 0x3, 
    0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f1, 0x3, 
    0x2, 0x2, 0x2, 0x2f0, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x8, 
    0x25, 0x1, 0x2, 0x2f2, 0x49, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x5, 
    0x4c, 0x27, 0x2, 0x2f4, 0x2fb, 0x8, 0x26, 0x1, 0x2, 0x2f5, 0x2f6, 0x9, 
    0x6, 0x2, 0x2, 0x2f6, 0x2f7, 0x5, 0x4c, 0x27, 0x2, 0x2f7, 0x2f8, 0x8, 
    0x26, 0x1, 0x2, 0x2f8, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f5, 0x3, 
    0x2, 0x2, 0x2, 0x2fa, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2f9, 0x3, 
    0x2, 0x2, 0x2, 0x2fb, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fe, 0x3, 
    0x2, 0x2, 0x2, 0x2fd, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2ff, 0x8, 
    0x26, 0x1, 0x2, 0x2ff, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x5, 
    0x4e, 0x28, 0x2, 0x301, 0x308, 0x8, 0x27, 0x1, 0x2, 0x302, 0x303, 0x9, 
    0x7, 0x2, 0x2, 0x303, 0x304, 0x5, 0x4e, 0x28, 0x2, 0x304, 0x305, 0x8, 
    0x27, 0x1, 0x2, 0x305, 0x307, 0x3, 0x2, 0x2, 0x2, 0x306, 0x302, 0x3, 
    0x2, 0x2, 0x2, 0x307, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x308, 0x306, 0x3, 
    0x2, 0x2, 0x2, 0x308, 0x309, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30b, 0x3, 
    0x2, 0x2, 0x2, 0x30a, 0x308, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30c, 0x8, 
    0x27, 0x1, 0x2, 0x30c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30e, 0x5, 
    0x50, 0x29, 0x2, 0x30e, 0x315, 0x8, 0x28, 0x1, 0x2, 0x30f, 0x310, 0x9, 
    0x8, 0x2, 0x2, 0x310, 0x311, 0x5, 0x50, 0x29, 0x2, 0x311, 0x312, 0x8, 
    0x28, 0x1, 0x2, 0x312, 0x314, 0x3, 0x2, 0x2, 0x2, 0x313, 0x30f, 0x3, 
    0x2, 0x2, 0x2, 0x314, 0x317, 0x3, 0x2, 0x2, 0x2, 0x315, 0x313, 0x3, 
    0x2, 0x2, 0x2, 0x315, 0x316, 0x3, 0x2, 0x2, 0x2, 0x316, 0x318, 0x3, 
    0x2, 0x2, 0x2, 0x317, 0x315, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 0x8, 
    0x28, 0x1, 0x2, 0x319, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31b, 0x5, 
    0x52, 0x2a, 0x2, 0x31b, 0x322, 0x8, 0x29, 0x1, 0x2, 0x31c, 0x31d, 0x9, 
    0x9, 0x2, 0x2, 0x31d, 0x31e, 0x5, 0x52, 0x2a, 0x2, 0x31e, 0x31f, 0x8, 
    0x29, 0x1, 0x2, 0x31f, 0x321, 0x3, 0x2, 0x2, 0x2, 0x320, 0x31c, 0x3, 
    0x2, 0x2, 0x2, 0x321, 0x324, 0x3, 0x2, 0x2, 0x2, 0x322, 0x320, 0x3, 
    0x2, 0x2, 0x2, 0x322, 0x323, 0x3, 0x2, 0x2, 0x2, 0x323, 0x325, 0x3, 
    0x2, 0x2, 0x2, 0x324, 0x322, 0x3, 0x2, 0x2, 0x2, 0x325, 0x326, 0x8, 
    0x29, 0x1, 0x2, 0x326, 0x51, 0x3, 0x2, 0x2, 0x2, 0x327, 0x328, 0x5, 
    0x54, 0x2b, 0x2, 0x328, 0x32f, 0x8, 0x2a, 0x1, 0x2, 0x329, 0x32a, 0x9, 
    0xa, 0x2, 0x2, 0x32a, 0x32b, 0x5, 0x54, 0x2b, 0x2, 0x32b, 0x32c, 0x8, 
    0x2a, 0x1, 0x2, 0x32c, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x329, 0x3, 
    0x2, 0x2, 0x2, 0x32e, 0x331, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x32d, 0x3, 
    0x2, 0x2, 0x2, 0x32f, 0x330, 0x3, 0x2, 0x2, 0x2, 0x330, 0x332, 0x3, 
    0x2, 0x2, 0x2, 0x331, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x332, 0x333, 0x8, 
    0x2a, 0x1, 0x2, 0x333, 0x53, 0x3, 0x2, 0x2, 0x2, 0x334, 0x336, 0x9, 
    0xb, 0x2, 0x2, 0x335, 0x334, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x3, 
    0x2, 0x2, 0x2, 0x336, 0x337, 0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 0x5, 
    0x56, 0x2c, 0x2, 0x338, 0x339, 0x8, 0x2b, 0x1, 0x2, 0x339, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x33a, 0x33c, 0x5, 0x58, 0x2d, 0x2, 0x33b, 0x33d, 0x9, 
    0xc, 0x2, 0x2, 0x33c, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 0x3, 
    0x2, 0x2, 0x2, 0x33d, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x8, 
    0x2c, 0x1, 0x2, 0x33f, 0x352, 0x3, 0x2, 0x2, 0x2, 0x340, 0x34c, 0x5, 
    0x58, 0x2d, 0x2, 0x341, 0x342, 0x5, 0x5c, 0x2f, 0x2, 0x342, 0x343, 0x8, 
    0x2c, 0x1, 0x2, 0x343, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x344, 0x345, 0x5, 
    0x5e, 0x30, 0x2, 0x345, 0x346, 0x8, 0x2c, 0x1, 0x2, 0x346, 0x34b, 0x3, 
    0x2, 0x2, 0x2, 0x347, 0x348, 0x5, 0x60, 0x31, 0x2, 0x348, 0x349, 0x8, 
    0x2c, 0x1, 0x2, 0x349, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x341, 0x3, 
    0x2, 0x2, 0x2, 0x34a, 0x344, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x347, 0x3, 
    0x2, 0x2, 0x2, 0x34b, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34a, 0x3, 
    0x2, 0x2, 0x2, 0x34c, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34f, 0x3, 
    0x2, 0x2, 0x2, 0x34e, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x8, 
    0x2c, 0x1, 0x2, 0x350, 0x352, 0x3, 0x2, 0x2, 0x2, 0x351, 0x33a, 0x3, 
    0x2, 0x2, 0x2, 0x351, 0x340, 0x3, 0x2, 0x2, 0x2, 0x352, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x353, 0x354, 0x7, 0x49, 0x2, 0x2, 0x354, 0x367, 0x8, 0x2d, 
    0x1, 0x2, 0x355, 0x356, 0x7, 0x4c, 0x2, 0x2, 0x356, 0x367, 0x8, 0x2d, 
    0x1, 0x2, 0x357, 0x358, 0x7, 0x4e, 0x2, 0x2, 0x358, 0x367, 0x8, 0x2d, 
    0x1, 0x2, 0x359, 0x35a, 0x7, 0x4f, 0x2, 0x2, 0x35a, 0x367, 0x8, 0x2d, 
    0x1, 0x2, 0x35b, 0x35c, 0x5, 0x2, 0x2, 0x2, 0x35c, 0x35d, 0x8, 0x2d, 
    0x1, 0x2, 0x35d, 0x367, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 0x7, 0x50, 
    0x2, 0x2, 0x35f, 0x367, 0x8, 0x2d, 0x1, 0x2, 0x360, 0x361, 0x5, 0x4, 
    0x3, 0x2, 0x361, 0x362, 0x8, 0x2d, 0x1, 0x2, 0x362, 0x367, 0x3, 0x2, 
    0x2, 0x2, 0x363, 0x364, 0x5, 0x5a, 0x2e, 0x2, 0x364, 0x365, 0x8, 0x2d, 
    0x1, 0x2, 0x365, 0x367, 0x3, 0x2, 0x2, 0x2, 0x366, 0x353, 0x3, 0x2, 
    0x2, 0x2, 0x366, 0x355, 0x3, 0x2, 0x2, 0x2, 0x366, 0x357, 0x3, 0x2, 
    0x2, 0x2, 0x366, 0x359, 0x3, 0x2, 0x2, 0x2, 0x366, 0x35b, 0x3, 0x2, 
    0x2, 0x2, 0x366, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x366, 0x360, 0x3, 0x2, 
    0x2, 0x2, 0x366, 0x363, 0x3, 0x2, 0x2, 0x2, 0x367, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x368, 0x369, 0x7, 0x25, 0x2, 0x2, 0x369, 0x36a, 0x5, 0x3c, 0x1f, 
    0x2, 0x36a, 0x36b, 0x7, 0x26, 0x2, 0x2, 0x36b, 0x36c, 0x8, 0x2e, 0x1, 
    0x2, 0x36c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36e, 0x7, 0x25, 0x2, 
    0x2, 0x36e, 0x37a, 0x8, 0x2f, 0x1, 0x2, 0x36f, 0x370, 0x5, 0x3c, 0x1f, 
    0x2, 0x370, 0x377, 0x8, 0x2f, 0x1, 0x2, 0x371, 0x372, 0x7, 0x23, 0x2, 
    0x2, 0x372, 0x373, 0x5, 0x3c, 0x1f, 0x2, 0x373, 0x374, 0x8, 0x2f, 0x1, 
    0x2, 0x374, 0x376, 0x3, 0x2, 0x2, 0x2, 0x375, 0x371, 0x3, 0x2, 0x2, 
    0x2, 0x376, 0x379, 0x3, 0x2, 0x2, 0x2, 0x377, 0x375, 0x3, 0x2, 0x2, 
    0x2, 0x377, 0x378, 0x3, 0x2, 0x2, 0x2, 0x378, 0x37b, 0x3, 0x2, 0x2, 
    0x2, 0x379, 0x377, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x36f, 0x3, 0x2, 0x2, 
    0x2, 0x37a, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x37c, 0x3, 0x2, 0x2, 
    0x2, 0x37c, 0x37d, 0x7, 0x26, 0x2, 0x2, 0x37d, 0x37e, 0x8, 0x2f, 0x1, 
    0x2, 0x37e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 0x7, 0x2b, 0x2, 
    0x2, 0x380, 0x381, 0x5, 0x3c, 0x1f, 0x2, 0x381, 0x382, 0x8, 0x30, 0x1, 
    0x2, 0x382, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x383, 0x384, 0x7, 0x29, 0x2, 
    0x2, 0x384, 0x385, 0x5, 0x3c, 0x1f, 0x2, 0x385, 0x386, 0x8, 0x31, 0x1, 
    0x2, 0x386, 0x387, 0x7, 0x2a, 0x2, 0x2, 0x387, 0x388, 0x8, 0x31, 0x1, 
    0x2, 0x388, 0x61, 0x3, 0x2, 0x2, 0x2, 0x48, 0x67, 0x70, 0x74, 0x7a, 
    0x83, 0x85, 0xa9, 0xab, 0xc4, 0xcb, 0xd3, 0xdd, 0xe1, 0xf0, 0x101, 0x109, 
    0x117, 0x123, 0x12a, 0x133, 0x13c, 0x145, 0x154, 0x15e, 0x162, 0x164, 
    0x16d, 0x17c, 0x17f, 0x188, 0x18d, 0x19a, 0x1a7, 0x1b1, 0x1bc, 0x1e2, 
    0x1f4, 0x1fb, 0x20b, 0x21a, 0x21d, 0x223, 0x22e, 0x231, 0x25a, 0x264, 
    0x266, 0x271, 0x28a, 0x292, 0x2ab, 0x2ad, 0x2ba, 0x2c7, 0x2d4, 0x2e1, 
    0x2ee, 0x2fb, 0x308, 0x315, 0x322, 0x32f, 0x335, 0x33c, 0x34a, 0x34c, 
    0x351, 0x366, 0x377, 0x37a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AnyFXParser::Initializer AnyFXParser::_init;
