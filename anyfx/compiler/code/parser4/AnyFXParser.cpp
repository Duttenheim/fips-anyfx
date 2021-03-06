

// include std container
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <stack>
#include <tuple>

#include "anyfxtoken.h"
#include "v3/ast/annotations.h"
#include "v3/ast/attributable.h"
#include "v3/ast/blendstate.h"
#include "v3/ast/compoundresource.h"
#include "v3/ast/effect.h"
#include "v3/ast/function.h"
#include "v3/ast/program.h"
#include "v3/ast/renderstate.h"
#include "v3/ast/state.h"
#include "v3/ast/structure.h"
#include "v3/ast/resource.h"
#include "v3/ast/symbol.h"
#include "v3/ast/typedresource.h"
#include "v3/ast/variable.h"
#include "expressions/expression.h"
#include "expressions/binaryexpression.h"
#include "expressions/unaryexpression.h"
#include "expressions/intexpression.h"
#include "expressions/boolexpression.h"
#include "expressions/floatexpression.h"
#include "expressions/stringexpression.h"
#include "expressions/symbolexpression.h"

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
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::QO: {
        enterOuterAlt(_localctx, 1);
        setState(48);
        match(AnyFXParser::QO);
        setState(53);
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
          | (1ULL << AnyFXParser::LOGICOR)
          | (1ULL << AnyFXParser::MOD)
          | (1ULL << AnyFXParser::UNDERSC)
          | (1ULL << AnyFXParser::SOBAKA)
          | (1ULL << AnyFXParser::ADD_OP)
          | (1ULL << AnyFXParser::SUB_OP)
          | (1ULL << AnyFXParser::DIV_OP)
          | (1ULL << AnyFXParser::MUL_OP)
          | (1ULL << AnyFXParser::INTEGERLITERAL)
          | (1ULL << AnyFXParser::COMMENT)
          | (1ULL << AnyFXParser::ML_COMMENT)
          | (1ULL << AnyFXParser::FLOATLITERAL)
          | (1ULL << AnyFXParser::EXPONENT)
          | (1ULL << AnyFXParser::DOUBLELITERAL)
          | (1ULL << AnyFXParser::HEX)
          | (1ULL << AnyFXParser::IDENTIFIER)
          | (1ULL << AnyFXParser::WS))) != 0)) {
          setState(49);
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
          setState(55);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(56);
        match(AnyFXParser::QO);
        break;
      }

      case AnyFXParser::Q: {
        enterOuterAlt(_localctx, 2);
        setState(57);
        match(AnyFXParser::Q);
        setState(62);
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
          | (1ULL << AnyFXParser::LOGICOR)
          | (1ULL << AnyFXParser::MOD)
          | (1ULL << AnyFXParser::UNDERSC)
          | (1ULL << AnyFXParser::SOBAKA)
          | (1ULL << AnyFXParser::ADD_OP)
          | (1ULL << AnyFXParser::SUB_OP)
          | (1ULL << AnyFXParser::DIV_OP)
          | (1ULL << AnyFXParser::MUL_OP)
          | (1ULL << AnyFXParser::INTEGERLITERAL)
          | (1ULL << AnyFXParser::COMMENT)
          | (1ULL << AnyFXParser::ML_COMMENT)
          | (1ULL << AnyFXParser::FLOATLITERAL)
          | (1ULL << AnyFXParser::EXPONENT)
          | (1ULL << AnyFXParser::DOUBLELITERAL)
          | (1ULL << AnyFXParser::HEX)
          | (1ULL << AnyFXParser::IDENTIFIER)
          | (1ULL << AnyFXParser::WS))) != 0)) {
          setState(58);
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
          setState(64);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(65);
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
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(68);
        match(AnyFXParser::T__0);
         dynamic_cast<BooleanContext *>(_localctx)->val =  true; 
        break;
      }

      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(70);
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
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(81);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
           start = _input->LT(1); 
          setState(75);
          match(AnyFXParser::T__2);
          setState(76);
          dynamic_cast<PreprocessContext *>(_localctx)->line = match(AnyFXParser::INTEGERLITERAL);
          setState(77);
          dynamic_cast<PreprocessContext *>(_localctx)->path = string();
           lines.push_back(std::make_tuple(atoi((dynamic_cast<PreprocessContext *>(_localctx)->line != nullptr ? dynamic_cast<PreprocessContext *>(_localctx)->line->getText() : "").c_str()), _input->LT(-1)->getLine(), start->getStartIndex(), _input->LT(1)->getStartIndex(), (dynamic_cast<PreprocessContext *>(_localctx)->path != nullptr ? _input->getText(dynamic_cast<PreprocessContext *>(_localctx)->path->start, dynamic_cast<PreprocessContext *>(_localctx)->path->stop) : nullptr))); 
          break;
        }

        case 2: {
          setState(80);
          matchWildcard();
          break;
        }

        } 
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(86);
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
    setState(88);
    dynamic_cast<EntryContext *>(_localctx)->effectContext = effect();

            dynamic_cast<EntryContext *>(_localctx)->returnEffect =  dynamic_cast<EntryContext *>(_localctx)->effectContext->eff;
        
    setState(90);
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

std::vector<AnyFXParser::Compound_resourceContext *> AnyFXParser::EffectContext::compound_resource() {
  return getRuleContexts<AnyFXParser::Compound_resourceContext>();
}

AnyFXParser::Compound_resourceContext* AnyFXParser::EffectContext::compound_resource(size_t i) {
  return getRuleContext<AnyFXParser::Compound_resourceContext>(i);
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
    setState(112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(110);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(92);
          dynamic_cast<EffectContext *>(_localctx)->functionContext = function();
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->functionContext->sym); 
          break;
        }

        case 2: {
          setState(95);
          dynamic_cast<EffectContext *>(_localctx)->variableContext = variable();
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->variableContext->sym); 
          break;
        }

        case 3: {
          setState(98);
          dynamic_cast<EffectContext *>(_localctx)->compound_resourceContext = compound_resource();
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->compound_resourceContext->sym); 
          break;
        }

        case 4: {
          setState(101);
          dynamic_cast<EffectContext *>(_localctx)->structureContext = structure();
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->structureContext->sym); 
          break;
        }

        case 5: {
          setState(104);
          dynamic_cast<EffectContext *>(_localctx)->stateContext = state();
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->stateContext->sym); 
          break;
        }

        case 6: {
          setState(107);
          dynamic_cast<EffectContext *>(_localctx)->programContext = program();
           _localctx->eff->symbols.push_back(dynamic_cast<EffectContext *>(_localctx)->programContext->sym); 
          break;
        }

        } 
      }
      setState(114);
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

//----------------- AnnotationsContext ------------------------------------------------------------------

AnyFXParser::AnnotationsContext::AnnotationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::AnnotationsContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::AnnotationsContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::AnnotationsContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::AnnotationsContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::AnnotationsContext::getRuleIndex() const {
  return AnyFXParser::RuleAnnotations;
}

void AnyFXParser::AnnotationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotations(this);
}

void AnyFXParser::AnnotationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotations(this);
}

AnyFXParser::AnnotationsContext* AnyFXParser::annotations() {
  AnnotationsContext *_localctx = _tracker.createInstance<AnnotationsContext>(_ctx, getState());
  enterRule(_localctx, 10, AnyFXParser::RuleAnnotations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(AnyFXParser::LL);

    setState(116);
    dynamic_cast<AnnotationsContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
    setState(117);
    match(AnyFXParser::EQ);
    setState(118);
    dynamic_cast<AnnotationsContext *>(_localctx)->value = expression();
    setState(119);
    match(AnyFXParser::SC);
     _localctx->annot.entries.push_back({(dynamic_cast<AnnotationsContext *>(_localctx)->name != nullptr ? dynamic_cast<AnnotationsContext *>(_localctx)->name->getText() : ""), dynamic_cast<AnnotationsContext *>(_localctx)->value->tree}); 
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::CO) {
      setState(122);
      match(AnyFXParser::CO);
      setState(123);
      dynamic_cast<AnnotationsContext *>(_localctx)->name2 = match(AnyFXParser::IDENTIFIER);
      setState(124);
      match(AnyFXParser::EQ);
      setState(125);
      dynamic_cast<AnnotationsContext *>(_localctx)->value2 = expression();
      setState(126);
      match(AnyFXParser::SC);
       _localctx->annot.entries.push_back({(dynamic_cast<AnnotationsContext *>(_localctx)->name2 != nullptr ? dynamic_cast<AnnotationsContext *>(_localctx)->name2->getText() : ""), dynamic_cast<AnnotationsContext *>(_localctx)->value2->tree}); 
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(134);
    match(AnyFXParser::RR);
   
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
  enterRule(_localctx, 12, AnyFXParser::RuleAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(136);
      dynamic_cast<AttributeContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
      setState(137);
      match(AnyFXParser::LP);
      setState(138);
      dynamic_cast<AttributeContext *>(_localctx)->expressionContext = expression();
      setState(139);
      match(AnyFXParser::RP);
       _localctx->attr.name = (dynamic_cast<AttributeContext *>(_localctx)->name != nullptr ? dynamic_cast<AttributeContext *>(_localctx)->name->getText() : ""); _localctx->attr.expression = dynamic_cast<AttributeContext *>(_localctx)->expressionContext->tree; 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(142);
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

//----------------- Compound_resourceContext ------------------------------------------------------------------

AnyFXParser::Compound_resourceContext::Compound_resourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::Compound_resourceContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::Compound_resourceContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::AttributeContext *> AnyFXParser::Compound_resourceContext::attribute() {
  return getRuleContexts<AnyFXParser::AttributeContext>();
}

AnyFXParser::AttributeContext* AnyFXParser::Compound_resourceContext::attribute(size_t i) {
  return getRuleContext<AnyFXParser::AttributeContext>(i);
}

AnyFXParser::AnnotationsContext* AnyFXParser::Compound_resourceContext::annotations() {
  return getRuleContext<AnyFXParser::AnnotationsContext>(0);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::Compound_resourceContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::Compound_resourceContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}

AnyFXParser::ExpressionContext* AnyFXParser::Compound_resourceContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::Compound_resourceContext::getRuleIndex() const {
  return AnyFXParser::RuleCompound_resource;
}

void AnyFXParser::Compound_resourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_resource(this);
}

void AnyFXParser::Compound_resourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_resource(this);
}

AnyFXParser::Compound_resourceContext* AnyFXParser::compound_resource() {
  Compound_resourceContext *_localctx = _tracker.createInstance<Compound_resourceContext>(_ctx, getState());
  enterRule(_localctx, 14, AnyFXParser::RuleCompound_resource);

          dynamic_cast<Compound_resourceContext *>(_localctx)->sym =  new CompoundResource();
          Symbol::Location location;
          Annotations annot;
          std::vector<Attribute> attributes;
          std::vector<Variable*> variables;
          std::string instanceName;
          Expression* arraySizeExpression = nullptr;
          bool isArray = false;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(146);
      dynamic_cast<Compound_resourceContext *>(_localctx)->attributeContext = attribute();
       attributes.push_back(dynamic_cast<Compound_resourceContext *>(_localctx)->attributeContext->attr); 
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(154);
    dynamic_cast<Compound_resourceContext *>(_localctx)->type = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == AnyFXParser::T__3

    || _la == AnyFXParser::T__4)) {
      dynamic_cast<Compound_resourceContext *>(_localctx)->type = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(155);
    dynamic_cast<Compound_resourceContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(157);
      dynamic_cast<Compound_resourceContext *>(_localctx)->annotationsContext = annotations();
       annot = dynamic_cast<Compound_resourceContext *>(_localctx)->annotationsContext->annot; 
    }
    setState(162);
    match(AnyFXParser::LB);
    setState(166); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(163);
      dynamic_cast<Compound_resourceContext *>(_localctx)->variableContext = variable();
       variables.push_back(dynamic_cast<Compound_resourceContext *>(_localctx)->variableContext->sym); 
      setState(168); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AnyFXParser::IDENTIFIER);
    setState(170);
    match(AnyFXParser::RB);
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::IDENTIFIER) {
      setState(171);
      dynamic_cast<Compound_resourceContext *>(_localctx)->instanceName = match(AnyFXParser::IDENTIFIER);
       instanceName = (dynamic_cast<Compound_resourceContext *>(_localctx)->instanceName != nullptr ? dynamic_cast<Compound_resourceContext *>(_localctx)->instanceName->getText() : ""); 
      setState(181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AnyFXParser::LL) {
        setState(173);
        match(AnyFXParser::LL);
        setState(177);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::LP)
          | (1ULL << AnyFXParser::NOT)
          | (1ULL << AnyFXParser::QO)
          | (1ULL << AnyFXParser::Q)
          | (1ULL << AnyFXParser::SUB_OP)
          | (1ULL << AnyFXParser::INTEGERLITERAL)
          | (1ULL << AnyFXParser::FLOATLITERAL)
          | (1ULL << AnyFXParser::DOUBLELITERAL)
          | (1ULL << AnyFXParser::HEX)
          | (1ULL << AnyFXParser::IDENTIFIER))) != 0)) {
          setState(174);
          dynamic_cast<Compound_resourceContext *>(_localctx)->expressionContext = expression();
           arraySizeExpression = dynamic_cast<Compound_resourceContext *>(_localctx)->expressionContext->tree; 
        }
        setState(179);
        match(AnyFXParser::RR);
         isArray = true; 
      }
    }
    setState(185);
    match(AnyFXParser::SC);

            dynamic_cast<Compound_resourceContext *>(_localctx)->sym =  new CompoundResource();
            _localctx->sym->location = location;
            _localctx->sym->name = (dynamic_cast<Compound_resourceContext *>(_localctx)->name != nullptr ? dynamic_cast<Compound_resourceContext *>(_localctx)->name->getText() : ""); 
            _localctx->sym->type = (dynamic_cast<Compound_resourceContext *>(_localctx)->type != nullptr ? dynamic_cast<Compound_resourceContext *>(_localctx)->type->getText() : "");
            _localctx->sym->annotations = annot;
            _localctx->sym->variables = variables;
            _localctx->sym->instanceName = instanceName;
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

std::vector<AnyFXParser::AttributeContext *> AnyFXParser::VariableContext::attribute() {
  return getRuleContexts<AnyFXParser::AttributeContext>();
}

AnyFXParser::AttributeContext* AnyFXParser::VariableContext::attribute(size_t i) {
  return getRuleContext<AnyFXParser::AttributeContext>(i);
}

AnyFXParser::AnnotationsContext* AnyFXParser::VariableContext::annotations() {
  return getRuleContext<AnyFXParser::AnnotationsContext>(0);
}

AnyFXParser::ExpressionContext* AnyFXParser::VariableContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
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
          std::vector<Attribute> attributes;
          Annotations annot;
          Expression* arraySizeExpression = nullptr;
          bool isArray = false;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(193);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(188);
        dynamic_cast<VariableContext *>(_localctx)->attributeContext = attribute();
         attributes.push_back(dynamic_cast<VariableContext *>(_localctx)->attributeContext->attr);  
      }
      setState(195);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(196);
    dynamic_cast<VariableContext *>(_localctx)->type = match(AnyFXParser::IDENTIFIER);
    setState(197);
    dynamic_cast<VariableContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(202);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(199);
      dynamic_cast<VariableContext *>(_localctx)->annotationsContext = annotations();
       annot = dynamic_cast<VariableContext *>(_localctx)->annotationsContext->annot; 
      break;
    }

    }
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(204);
      match(AnyFXParser::LL);
      setState(208);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
        | (1ULL << AnyFXParser::T__1)
        | (1ULL << AnyFXParser::LP)
        | (1ULL << AnyFXParser::NOT)
        | (1ULL << AnyFXParser::QO)
        | (1ULL << AnyFXParser::Q)
        | (1ULL << AnyFXParser::SUB_OP)
        | (1ULL << AnyFXParser::INTEGERLITERAL)
        | (1ULL << AnyFXParser::FLOATLITERAL)
        | (1ULL << AnyFXParser::DOUBLELITERAL)
        | (1ULL << AnyFXParser::HEX)
        | (1ULL << AnyFXParser::IDENTIFIER))) != 0)) {
        setState(205);
        dynamic_cast<VariableContext *>(_localctx)->expressionContext = expression();
         arraySizeExpression = dynamic_cast<VariableContext *>(_localctx)->expressionContext->tree; 
      }
      setState(210);
      match(AnyFXParser::RR);
       isArray = true; 
    }
    setState(214);
    match(AnyFXParser::SC);
     
            dynamic_cast<VariableContext *>(_localctx)->sym =  new Variable(); 
            _localctx->sym->type = (dynamic_cast<VariableContext *>(_localctx)->type != nullptr ? dynamic_cast<VariableContext *>(_localctx)->type->getText() : ""); 
            _localctx->sym->name = (dynamic_cast<VariableContext *>(_localctx)->name != nullptr ? dynamic_cast<VariableContext *>(_localctx)->name->getText() : ""); 
            _localctx->sym->location = location; 
            _localctx->sym->annotations = annot; 
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

//----------------- StructureContext ------------------------------------------------------------------

AnyFXParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::StructureContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::StructureContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::StructureContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
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
  enterRule(_localctx, 18, AnyFXParser::RuleStructure);

          dynamic_cast<StructureContext *>(_localctx)->sym =  nullptr;
          std::vector<Variable*> variables;
          Symbol::Location location;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(AnyFXParser::T__5);
    setState(218);
    dynamic_cast<StructureContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     dynamic_cast<StructureContext *>(_localctx)->sym =  new Structure(); location = SetupFile(); 
    setState(220);
    match(AnyFXParser::LB);
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(221);
      dynamic_cast<StructureContext *>(_localctx)->variableContext = variable();
       variables.push_back(dynamic_cast<StructureContext *>(_localctx)->variableContext->sym); 
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(229);
    match(AnyFXParser::RB);
    setState(230);
    match(AnyFXParser::SC);
     
            dynamic_cast<StructureContext *>(_localctx)->sym =  new Structure(); 
            _localctx->sym->name = (dynamic_cast<StructureContext *>(_localctx)->name != nullptr ? dynamic_cast<StructureContext *>(_localctx)->name->getText() : ""); 
            _localctx->sym->location = location; 
            _localctx->sym->variables = variables; 
        
   
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
  enterRule(_localctx, 20, AnyFXParser::RuleCodeblock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::LB: {
        enterOuterAlt(_localctx, 1);
        setState(233);
        match(AnyFXParser::LB);
        setState(237);
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
          | (1ULL << AnyFXParser::LOGICOR)
          | (1ULL << AnyFXParser::MOD)
          | (1ULL << AnyFXParser::UNDERSC)
          | (1ULL << AnyFXParser::SOBAKA)
          | (1ULL << AnyFXParser::ADD_OP)
          | (1ULL << AnyFXParser::SUB_OP)
          | (1ULL << AnyFXParser::DIV_OP)
          | (1ULL << AnyFXParser::MUL_OP)
          | (1ULL << AnyFXParser::INTEGERLITERAL)
          | (1ULL << AnyFXParser::COMMENT)
          | (1ULL << AnyFXParser::ML_COMMENT)
          | (1ULL << AnyFXParser::FLOATLITERAL)
          | (1ULL << AnyFXParser::EXPONENT)
          | (1ULL << AnyFXParser::DOUBLELITERAL)
          | (1ULL << AnyFXParser::HEX)
          | (1ULL << AnyFXParser::IDENTIFIER)
          | (1ULL << AnyFXParser::WS))) != 0)) {
          setState(234);
          codeblock();
          setState(239);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(240);
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
        setState(241);
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

AnyFXParser::CodeblockContext* AnyFXParser::FunctionContext::codeblock() {
  return getRuleContext<AnyFXParser::CodeblockContext>(0);
}

std::vector<tree::TerminalNode *> AnyFXParser::FunctionContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::FunctionContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::AttributeContext *> AnyFXParser::FunctionContext::attribute() {
  return getRuleContexts<AnyFXParser::AttributeContext>();
}

AnyFXParser::AttributeContext* AnyFXParser::FunctionContext::attribute(size_t i) {
  return getRuleContext<AnyFXParser::AttributeContext>(i);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::FunctionContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::FunctionContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
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
  enterRule(_localctx, 22, AnyFXParser::RuleFunction);

          dynamic_cast<FunctionContext *>(_localctx)->sym =  nullptr;
          Token* startToken = nullptr;
          Token* endToken = nullptr;
          Symbol::Location location;
          std::vector<Variable*> variables;
          std::vector<Attribute> attributes;
          std::string body;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(249);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(244);
        dynamic_cast<FunctionContext *>(_localctx)->attributeContext = attribute();
         attributes.push_back(dynamic_cast<FunctionContext *>(_localctx)->attributeContext->attr);  
      }
      setState(251);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(252);
    dynamic_cast<FunctionContext *>(_localctx)->returnType = match(AnyFXParser::IDENTIFIER);
    setState(253);
    dynamic_cast<FunctionContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(255);
    match(AnyFXParser::LP);
    setState(267);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::IDENTIFIER) {
      setState(256);
      dynamic_cast<FunctionContext *>(_localctx)->arg0 = variable();
       variables.push_back(dynamic_cast<FunctionContext *>(_localctx)->arg0->sym); 
      setState(264);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(258);
        match(AnyFXParser::CO);
        setState(259);
        dynamic_cast<FunctionContext *>(_localctx)->argn = variable();
         variables.push_back(dynamic_cast<FunctionContext *>(_localctx)->argn->sym); 
        setState(266);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(269);
    match(AnyFXParser::RP);

            startToken = _input->LT(2);
        
    setState(271);
    codeblock();

            endToken = _input->LT(-2);

            // extract code from between tokens
            antlr4::misc::Interval interval;
            interval.a = startToken->getTokenIndex();
            interval.b = endToken->getTokenIndex();
            body = _input->getText(interval);

        
     
            dynamic_cast<FunctionContext *>(_localctx)->sym =  new Function(); 
            _localctx->sym->returnType = (dynamic_cast<FunctionContext *>(_localctx)->returnType != nullptr ? dynamic_cast<FunctionContext *>(_localctx)->returnType->getText() : ""); 
            _localctx->sym->name = (dynamic_cast<FunctionContext *>(_localctx)->name != nullptr ? dynamic_cast<FunctionContext *>(_localctx)->name->getText() : ""); 
            _localctx->sym->location = location; 
            _localctx->sym->parameters = variables; 
            _localctx->sym->attributes = attributes; 
            _localctx->sym->code = body; 
        
   
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

std::vector<tree::TerminalNode *> AnyFXParser::ProgramContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::ProgramContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

AnyFXParser::AnnotationsContext* AnyFXParser::ProgramContext::annotations() {
  return getRuleContext<AnyFXParser::AnnotationsContext>(0);
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
  enterRule(_localctx, 24, AnyFXParser::RuleProgram);

          dynamic_cast<ProgramContext *>(_localctx)->sym =  nullptr;
          Symbol::Location location;
          std::vector<Program::SubroutineMapping> subroutines;
          std::vector<Program::Entry> entries;
          Annotations annot;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    match(AnyFXParser::T__6);
    setState(276);
    dynamic_cast<ProgramContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(278);
      dynamic_cast<ProgramContext *>(_localctx)->annotationsContext = annotations();
       annot = dynamic_cast<ProgramContext *>(_localctx)->annotationsContext->annot; 
    }
    setState(283);
    match(AnyFXParser::LB);
    setState(303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(284);
      dynamic_cast<ProgramContext *>(_localctx)->id = match(AnyFXParser::IDENTIFIER);
      setState(285);
      match(AnyFXParser::EQ);
      setState(286);
      dynamic_cast<ProgramContext *>(_localctx)->value = match(AnyFXParser::IDENTIFIER);
       subroutines.clear(); 
      setState(288);
      match(AnyFXParser::LP);
      setState(295);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(289);
        dynamic_cast<ProgramContext *>(_localctx)->func = match(AnyFXParser::IDENTIFIER);
        setState(290);
        match(AnyFXParser::EQ);
        setState(291);
        dynamic_cast<ProgramContext *>(_localctx)->subroutine = match(AnyFXParser::IDENTIFIER);
         subroutines.push_back({(dynamic_cast<ProgramContext *>(_localctx)->func != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->func->getText() : ""), (dynamic_cast<ProgramContext *>(_localctx)->subroutine != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->subroutine->getText() : "")}); 
        setState(297);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(298);
      match(AnyFXParser::RP);
      setState(299);
      match(AnyFXParser::SC);
       entries.push_back({(dynamic_cast<ProgramContext *>(_localctx)->id != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->id->getText() : ""), (dynamic_cast<ProgramContext *>(_localctx)->value != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->value->getText() : ""), subroutines}); 
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(306);
    match(AnyFXParser::RB);
    setState(307);
    match(AnyFXParser::SC);
     
            dynamic_cast<ProgramContext *>(_localctx)->sym =  new Program();
            _localctx->sym->location = location;
            _localctx->sym->name = (dynamic_cast<ProgramContext *>(_localctx)->name != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->name->getText() : "");
            _localctx->sym->annotations = annot;
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

std::vector<tree::TerminalNode *> AnyFXParser::StateContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::StateContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
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
  enterRule(_localctx, 26, AnyFXParser::RuleState);

          Expression* arrayExpression = nullptr;
          Symbol::Location location;
          std::vector<State::Entry> entries;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__7: {
        setState(310);
        match(AnyFXParser::T__7);
         dynamic_cast<StateContext *>(_localctx)->sym =  new BlendState(); 
        break;
      }

      case AnyFXParser::T__8: {
        setState(312);
        match(AnyFXParser::T__8);
         dynamic_cast<StateContext *>(_localctx)->sym =  new RenderState(); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(316);
    dynamic_cast<StateContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     location = SetupFile(); 
    setState(318);
    match(AnyFXParser::LB);

    setState(319);
    dynamic_cast<StateContext *>(_localctx)->id = match(AnyFXParser::IDENTIFIER);
     arrayExpression = nullptr; 
    setState(326);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(321);
      match(AnyFXParser::LL);
      setState(322);
      dynamic_cast<StateContext *>(_localctx)->index = expression();
       arrayExpression = dynamic_cast<StateContext *>(_localctx)->index->tree; 
      setState(324);
      match(AnyFXParser::RR);
    }
    setState(328);
    dynamic_cast<StateContext *>(_localctx)->value = expression();
     entries.push_back({(dynamic_cast<StateContext *>(_localctx)->id != nullptr ? dynamic_cast<StateContext *>(_localctx)->id->getText() : ""), dynamic_cast<StateContext *>(_localctx)->value->tree, arrayExpression}); 
    setState(331);
    match(AnyFXParser::SC);
    setState(332);
    match(AnyFXParser::RB);
    setState(333);
    match(AnyFXParser::SC);

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

//----------------- ExpressionContext ------------------------------------------------------------------

AnyFXParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::Binaryexp7Context* AnyFXParser::ExpressionContext::binaryexp7() {
  return getRuleContext<AnyFXParser::Binaryexp7Context>(0);
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
  enterRule(_localctx, 28, AnyFXParser::RuleExpression);

          dynamic_cast<ExpressionContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    dynamic_cast<ExpressionContext *>(_localctx)->binaryexp7Context = binaryexp7();
     dynamic_cast<ExpressionContext *>(_localctx)->tree =  dynamic_cast<ExpressionContext *>(_localctx)->binaryexp7Context->tree; 
   
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
  enterRule(_localctx, 30, AnyFXParser::RuleBinaryexp7);

          Expression* prev = nullptr;
          dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    dynamic_cast<Binaryexp7Context *>(_localctx)->e1 = binaryexp6();
     dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  dynamic_cast<Binaryexp7Context *>(_localctx)->e1->tree;	_localctx->tree->location = SetupFile(); 
    setState(347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICOR) {
      setState(341);
      match(AnyFXParser::LOGICOR);
      setState(342);
      dynamic_cast<Binaryexp7Context *>(_localctx)->e2 = binaryexp6();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression("||", prev, dynamic_cast<Binaryexp7Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression("||", dynamic_cast<Binaryexp7Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp7Context *>(_localctx)->e2->tree);
                              }

                              lhs->location = SetupFile();
                              prev = lhs;
                              dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  lhs;
                          
      setState(349);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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
  enterRule(_localctx, 32, AnyFXParser::RuleBinaryexp6);

          Expression* prev = nullptr;
          dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    dynamic_cast<Binaryexp6Context *>(_localctx)->e1 = binaryexp5();
     dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  dynamic_cast<Binaryexp6Context *>(_localctx)->e1->tree;	_localctx->tree->location = SetupFile(); 
    setState(358);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICAND) {
      setState(352);
      match(AnyFXParser::LOGICAND);
      setState(353);
      dynamic_cast<Binaryexp6Context *>(_localctx)->e2 = binaryexp5();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression("&&", prev, dynamic_cast<Binaryexp6Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression("&&", dynamic_cast<Binaryexp6Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp6Context *>(_localctx)->e2->tree);
                              }

                              lhs->location = SetupFile();
                              prev = lhs;
                              dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  lhs;
                          
      setState(360);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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
  enterRule(_localctx, 34, AnyFXParser::RuleBinaryexp5);

          Expression* prev = nullptr;
          dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    dynamic_cast<Binaryexp5Context *>(_localctx)->e1 = binaryexp4();
     dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  dynamic_cast<Binaryexp5Context *>(_localctx)->e1->tree;	_localctx->tree->location = SetupFile(); 
    setState(369);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICEQ

    || _la == AnyFXParser::NOTEQ) {
      setState(363);
      dynamic_cast<Binaryexp5Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::LOGICEQ

      || _la == AnyFXParser::NOTEQ)) {
        dynamic_cast<Binaryexp5Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(364);
      dynamic_cast<Binaryexp5Context *>(_localctx)->e2 = binaryexp4();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp5Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp5Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp5Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp5Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp5Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp5Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp5Context *>(_localctx)->e2->tree);
                              }

                              lhs->location = SetupFile();
                              prev = lhs;
                              dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  lhs;
                          
      setState(371);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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
  enterRule(_localctx, 36, AnyFXParser::RuleBinaryexp4);

          Expression* prev = nullptr;
          dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    dynamic_cast<Binaryexp4Context *>(_localctx)->e1 = binaryexp3();
     dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  dynamic_cast<Binaryexp4Context *>(_localctx)->e1->tree;	_localctx->tree->location = SetupFile(); 
    setState(380);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::LESS)
      | (1ULL << AnyFXParser::LESSEQ)
      | (1ULL << AnyFXParser::GREATER)
      | (1ULL << AnyFXParser::GREATEREQ))) != 0)) {
      setState(374);
      dynamic_cast<Binaryexp4Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::LESS)
        | (1ULL << AnyFXParser::LESSEQ)
        | (1ULL << AnyFXParser::GREATER)
        | (1ULL << AnyFXParser::GREATEREQ))) != 0))) {
        dynamic_cast<Binaryexp4Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(375);
      dynamic_cast<Binaryexp4Context *>(_localctx)->e2 = binaryexp3();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp4Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp4Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp4Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp4Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp4Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp4Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp4Context *>(_localctx)->e2->tree);
                              }

                              lhs->location = SetupFile();
                              prev = lhs;
                              dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  lhs;
                          
      setState(382);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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
  enterRule(_localctx, 38, AnyFXParser::RuleBinaryexp3);

          Expression* prev = nullptr;
          dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    dynamic_cast<Binaryexp3Context *>(_localctx)->e1 = binaryexp2();
     dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  dynamic_cast<Binaryexp3Context *>(_localctx)->e1->tree; _localctx->tree->location = SetupFile(); 
    setState(391);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::ADD_OP

    || _la == AnyFXParser::SUB_OP) {
      setState(385);
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
      setState(386);
      dynamic_cast<Binaryexp3Context *>(_localctx)->e2 = binaryexp2();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp3Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp3Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp3Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp3Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp3Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp3Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp3Context *>(_localctx)->e2->tree);
                              }

                              lhs->location = SetupFile();
                              prev = lhs;
                              dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  lhs;
                          
      setState(393);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp2Context::MUL_OP() {
  return getTokens(AnyFXParser::MUL_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp2Context::MUL_OP(size_t i) {
  return getToken(AnyFXParser::MUL_OP, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp2Context::DIV_OP() {
  return getTokens(AnyFXParser::DIV_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp2Context::DIV_OP(size_t i) {
  return getToken(AnyFXParser::DIV_OP, i);
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
  enterRule(_localctx, 40, AnyFXParser::RuleBinaryexp2);

          Expression* prev = nullptr;
          dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    dynamic_cast<Binaryexp2Context *>(_localctx)->e1 = binaryexp1();
     dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  dynamic_cast<Binaryexp2Context *>(_localctx)->e1->tree; _localctx->tree->location = SetupFile(); 
    setState(402);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::DIV_OP

    || _la == AnyFXParser::MUL_OP) {
      setState(396);
      dynamic_cast<Binaryexp2Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::DIV_OP

      || _la == AnyFXParser::MUL_OP)) {
        dynamic_cast<Binaryexp2Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(397);
      dynamic_cast<Binaryexp2Context *>(_localctx)->e2 = binaryexp1();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp2Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp2Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp2Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp2Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp2Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp2Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp2Context *>(_localctx)->e2->tree);
                              }

                              lhs->location = SetupFile();
                              prev = lhs;
                              dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  lhs;
                          
      setState(404);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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

AnyFXParser::BinaryexpatomContext* AnyFXParser::Binaryexp1Context::binaryexpatom() {
  return getRuleContext<AnyFXParser::BinaryexpatomContext>(0);
}

tree::TerminalNode* AnyFXParser::Binaryexp1Context::SUB_OP() {
  return getToken(AnyFXParser::SUB_OP, 0);
}

tree::TerminalNode* AnyFXParser::Binaryexp1Context::NOT() {
  return getToken(AnyFXParser::NOT, 0);
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
  enterRule(_localctx, 42, AnyFXParser::RuleBinaryexp1);

          char operat = 0;
          dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  nullptr;
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::NOT

    || _la == AnyFXParser::SUB_OP) {
      setState(405);
      dynamic_cast<Binaryexp1Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::NOT

      || _la == AnyFXParser::SUB_OP)) {
        dynamic_cast<Binaryexp1Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(408);
    dynamic_cast<Binaryexp1Context *>(_localctx)->e1 = binaryexpatom();

                            Expression* rhs = dynamic_cast<Binaryexp1Context *>(_localctx)->e1->tree;

                            if (dynamic_cast<Binaryexp1Context *>(_localctx)->op != 0)
                            {
                                operat = (dynamic_cast<Binaryexp1Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp1Context *>(_localctx)->op->getText() : "").c_str()[0];
                                rhs = new UnaryExpression(operat, rhs);
                            }

                            rhs->location = SetupFile();
                            dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  rhs;

                        
   
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

AnyFXParser::ParantexpressionContext* AnyFXParser::BinaryexpatomContext::parantexpression() {
  return getRuleContext<AnyFXParser::ParantexpressionContext>(0);
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
  enterRule(_localctx, 44, AnyFXParser::RuleBinaryexpatom);

          dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(430);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::INTEGERLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(411);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken = match(AnyFXParser::INTEGERLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(atoi((dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken->getText() : "").c_str())); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::FLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(413);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken = match(AnyFXParser::FLOATLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken->getText() : "").c_str())); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::DOUBLELITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(415);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken = match(AnyFXParser::DOUBLELITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken->getText() : "").c_str())); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::HEX: {
        enterOuterAlt(_localctx, 4);
        setState(417);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken = match(AnyFXParser::HEX);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(strtoul((dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken->getText() : "").c_str(), nullptr, 16)); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::QO:
      case AnyFXParser::Q: {
        enterOuterAlt(_localctx, 5);
        setState(419);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->stringContext = string();
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new StringExpression(dynamic_cast<BinaryexpatomContext *>(_localctx)->stringContext->val); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 6);
        setState(422);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new SymbolExpression((dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken->getText() : "")); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::T__0:
      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 7);
        setState(424);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext = boolean();
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new BoolExpression(dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext->val); _localctx->tree->location = SetupFile(); 
        break;
      }

      case AnyFXParser::LP: {
        enterOuterAlt(_localctx, 8);
        setState(427);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->parantexpressionContext = parantexpression();
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  dynamic_cast<BinaryexpatomContext *>(_localctx)->parantexpressionContext->tree; 
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

//----------------- ParantexpressionContext ------------------------------------------------------------------

AnyFXParser::ParantexpressionContext::ParantexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ParantexpressionContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ParantexpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleParantexpression;
}

void AnyFXParser::ParantexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParantexpression(this);
}

void AnyFXParser::ParantexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParantexpression(this);
}

AnyFXParser::ParantexpressionContext* AnyFXParser::parantexpression() {
  ParantexpressionContext *_localctx = _tracker.createInstance<ParantexpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, AnyFXParser::RuleParantexpression);

          dynamic_cast<ParantexpressionContext *>(_localctx)->tree =  nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(AnyFXParser::LP);
    setState(433);
    dynamic_cast<ParantexpressionContext *>(_localctx)->expressionContext = expression();
    setState(434);
    match(AnyFXParser::RP);
     dynamic_cast<ParantexpressionContext *>(_localctx)->tree =  dynamic_cast<ParantexpressionContext *>(_localctx)->expressionContext->tree; 
   
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
  "string", "boolean", "preprocess", "entry", "effect", "annotations", "attribute", 
  "compound_resource", "variable", "structure", "codeblock", "function", 
  "program", "state", "expression", "binaryexp7", "binaryexp6", "binaryexp5", 
  "binaryexp4", "binaryexp3", "binaryexp2", "binaryexp1", "binaryexpatom", 
  "parantexpression"
};

std::vector<std::string> AnyFXParser::_literalNames = {
  "", "'true'", "'false'", "'#line'", "'buffer'", "'constant'", "'struct'", 
  "'program'", "'blend_state'", "'render_state'", "';'", "','", "':'", "'('", 
  "')'", "'{'", "'}'", "'['", "']'", "'.'", "'!'", "'='", "'\"'", "'?'", 
  "'&'", "'&='", "'|'", "'|='", "'^'", "'^='", "'~'", "'''", "'#'", "'\\'", 
  "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", "'%'", "'_'", 
  "'@'", "'+'", "'-'", "'/'", "'*'"
};

std::vector<std::string> AnyFXParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "SC", "CO", "COL", "LP", "RP", 
  "LB", "RB", "LL", "RR", "DOT", "NOT", "EQ", "QO", "QU", "AND", "ANDSET", 
  "OR", "ORSET", "XOR", "XORSET", "CONNJUGATE", "Q", "NU", "FORWARDSLASH", 
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
    0x3, 0x3b, 0x1b8, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
    0x36, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x39, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x42, 
    0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x45, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x4b, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x54, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x57, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 
    0x71, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x74, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x84, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0x87, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x93, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x98, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x9b, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa3, 0xa, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0xa9, 0xa, 0x9, 0xd, 0x9, 0xe, 
    0x9, 0xaa, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0xb4, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xb8, 
    0xa, 0x9, 0x5, 0x9, 0xba, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xc2, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
    0xc5, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0xcd, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0xd3, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd7, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xe3, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0xe6, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0xee, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xf1, 0xb, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xf5, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x7, 0xd, 0xfa, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xfd, 0xb, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x109, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0x10c, 0xb, 0xd, 0x5, 0xd, 0x10e, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x11c, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x7, 0xe, 0x128, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x12b, 0xb, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x130, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x133, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x13d, 0xa, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x149, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x15c, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x15f, 
    0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x7, 0x12, 0x167, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x16a, 0xb, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x172, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x175, 0xb, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 
    0x14, 0x17d, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x180, 0xb, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
    0x188, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x18b, 0xb, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x193, 
    0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x196, 0xb, 0x16, 0x3, 0x17, 0x5, 0x17, 
    0x199, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x1b1, 0xa, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x4, 
    0x55, 0x72, 0x2, 0x1a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x2, 0xb, 0x3, 0x2, 0x18, 0x18, 0x3, 0x2, 0x21, 0x21, 
    0x3, 0x2, 0x6, 0x7, 0x3, 0x2, 0x11, 0x12, 0x3, 0x2, 0x28, 0x29, 0x3, 
    0x2, 0x24, 0x27, 0x3, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x31, 0x32, 0x4, 0x2, 
    0x16, 0x16, 0x30, 0x30, 0x2, 0x1d0, 0x2, 0x44, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x55, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x72, 0x3, 0x2, 0x2, 0x2, 0xc, 0x75, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x92, 0x3, 0x2, 0x2, 0x2, 0x10, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x14, 0xdb, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x18, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x152, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x155, 0x3, 0x2, 0x2, 0x2, 0x22, 0x160, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x176, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x181, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x18c, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x198, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1b0, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x32, 0x37, 0x7, 0x18, 0x2, 0x2, 0x33, 
    0x34, 0xa, 0x2, 0x2, 0x2, 0x34, 0x36, 0x8, 0x2, 0x1, 0x2, 0x35, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x45, 0x7, 0x18, 0x2, 
    0x2, 0x3b, 0x40, 0x7, 0x21, 0x2, 0x2, 0x3c, 0x3d, 0xa, 0x3, 0x2, 0x2, 
    0x3d, 0x3f, 0x8, 0x2, 0x1, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x45, 0x7, 0x21, 0x2, 0x2, 0x44, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x47, 0x7, 0x3, 0x2, 0x2, 0x47, 0x4b, 0x8, 0x3, 0x1, 0x2, 
    0x48, 0x49, 0x7, 0x4, 0x2, 0x2, 0x49, 0x4b, 0x8, 0x3, 0x1, 0x2, 0x4a, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x8, 0x4, 0x1, 0x2, 0x4d, 0x4e, 0x7, 
    0x5, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x33, 0x2, 0x2, 0x4f, 0x50, 0x5, 0x2, 
    0x2, 0x2, 0x50, 0x51, 0x8, 0x4, 0x1, 0x2, 0x51, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x54, 0xb, 0x2, 0x2, 0x2, 0x53, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 
    0x2, 0x2, 0x3, 0x59, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0xa, 
    0x6, 0x2, 0x5b, 0x5c, 0x8, 0x5, 0x1, 0x2, 0x5c, 0x5d, 0x7, 0x2, 0x2, 
    0x3, 0x5d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x5, 0x18, 0xd, 0x2, 
    0x5f, 0x60, 0x8, 0x6, 0x1, 0x2, 0x60, 0x71, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x62, 0x5, 0x12, 0xa, 0x2, 0x62, 0x63, 0x8, 0x6, 0x1, 0x2, 0x63, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x5, 0x10, 0x9, 0x2, 0x65, 0x66, 0x8, 
    0x6, 0x1, 0x2, 0x66, 0x71, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x5, 0x14, 
    0xb, 0x2, 0x68, 0x69, 0x8, 0x6, 0x1, 0x2, 0x69, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x6b, 0x5, 0x1c, 0xf, 0x2, 0x6b, 0x6c, 0x8, 0x6, 0x1, 0x2, 
    0x6c, 0x71, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x1a, 0xe, 0x2, 0x6e, 
    0x6f, 0x8, 0x6, 0x1, 0x2, 0x6f, 0x71, 0x3, 0x2, 0x2, 0x2, 0x70, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x61, 0x3, 0x2, 0x2, 0x2, 0x70, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x67, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x73, 0xb, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x76, 0x7, 0x13, 0x2, 0x2, 0x76, 0x77, 0x7, 0x3a, 0x2, 0x2, 0x77, 0x78, 
    0x7, 0x17, 0x2, 0x2, 0x78, 0x79, 0x5, 0x1e, 0x10, 0x2, 0x79, 0x7a, 0x7, 
    0xc, 0x2, 0x2, 0x7a, 0x7b, 0x8, 0x7, 0x1, 0x2, 0x7b, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x7c, 0x7d, 0x7, 0xd, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x3a, 0x2, 
    0x2, 0x7e, 0x7f, 0x7, 0x17, 0x2, 0x2, 0x7f, 0x80, 0x5, 0x1e, 0x10, 0x2, 
    0x80, 0x81, 0x7, 0xc, 0x2, 0x2, 0x81, 0x82, 0x8, 0x7, 0x1, 0x2, 0x82, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x83, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x88, 0x89, 0x7, 0x14, 0x2, 0x2, 0x89, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x8b, 0x7, 0x3a, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0xf, 0x2, 0x2, 
    0x8c, 0x8d, 0x5, 0x1e, 0x10, 0x2, 0x8d, 0x8e, 0x7, 0x10, 0x2, 0x2, 0x8e, 
    0x8f, 0x8, 0x8, 0x1, 0x2, 0x8f, 0x93, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 
    0x7, 0x3a, 0x2, 0x2, 0x91, 0x93, 0x8, 0x8, 0x1, 0x2, 0x92, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x93, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x95, 0x5, 0xe, 0x8, 0x2, 0x95, 0x96, 0x8, 0x9, 0x1, 
    0x2, 0x96, 0x98, 0x3, 0x2, 0x2, 0x2, 0x97, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x9, 0x4, 0x2, 0x2, 0x9d, 0x9e, 0x7, 
    0x3a, 0x2, 0x2, 0x9e, 0xa2, 0x8, 0x9, 0x1, 0x2, 0x9f, 0xa0, 0x5, 0xc, 
    0x7, 0x2, 0xa0, 0xa1, 0x8, 0x9, 0x1, 0x2, 0xa1, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa2, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa8, 0x7, 0x11, 0x2, 0x2, 0xa5, 
    0xa6, 0x5, 0x12, 0xa, 0x2, 0xa6, 0xa7, 0x8, 0x9, 0x1, 0x2, 0xa7, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0xa8, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xb9, 0x7, 0x12, 0x2, 
    0x2, 0xad, 0xae, 0x7, 0x3a, 0x2, 0x2, 0xae, 0xb7, 0x8, 0x9, 0x1, 0x2, 
    0xaf, 0xb3, 0x7, 0x13, 0x2, 0x2, 0xb0, 0xb1, 0x5, 0x1e, 0x10, 0x2, 0xb1, 
    0xb2, 0x8, 0x9, 0x1, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x14, 0x2, 0x2, 0xb6, 0xb8, 0x8, 0x9, 
    0x1, 0x2, 0xb7, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbc, 0x7, 0xc, 0x2, 0x2, 0xbc, 0xbd, 0x8, 0x9, 0x1, 0x2, 0xbd, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0xe, 0x8, 0x2, 0xbf, 0xc0, 0x8, 
    0xa, 0x1, 0x2, 0xc0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc6, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x3a, 0x2, 0x2, 0xc7, 
    0xc8, 0x7, 0x3a, 0x2, 0x2, 0xc8, 0xcc, 0x8, 0xa, 0x1, 0x2, 0xc9, 0xca, 
    0x5, 0xc, 0x7, 0x2, 0xca, 0xcb, 0x8, 0xa, 0x1, 0x2, 0xcb, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd2, 0x7, 0x13, 0x2, 
    0x2, 0xcf, 0xd0, 0x5, 0x1e, 0x10, 0x2, 0xd0, 0xd1, 0x8, 0xa, 0x1, 0x2, 
    0xd1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 
    0x7, 0x14, 0x2, 0x2, 0xd5, 0xd7, 0x8, 0xa, 0x1, 0x2, 0xd6, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xd8, 0xd9, 0x7, 0xc, 0x2, 0x2, 0xd9, 0xda, 0x8, 0xa, 0x1, 
    0x2, 0xda, 0x13, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x8, 0x2, 0x2, 
    0xdc, 0xdd, 0x7, 0x3a, 0x2, 0x2, 0xdd, 0xde, 0x8, 0xb, 0x1, 0x2, 0xde, 
    0xe4, 0x7, 0x11, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x12, 0xa, 0x2, 0xe0, 0xe1, 
    0x8, 0xb, 0x1, 0x2, 0xe1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x12, 0x2, 0x2, 
    0xe8, 0xe9, 0x7, 0xc, 0x2, 0x2, 0xe9, 0xea, 0x8, 0xb, 0x1, 0x2, 0xea, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xef, 0x7, 0x11, 0x2, 0x2, 0xec, 0xee, 
    0x5, 0x16, 0xc, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf5, 0x7, 0x12, 0x2, 0x2, 0xf3, 0xf5, 0xa, 0x5, 0x2, 0x2, 
    0xf4, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0xe, 0x8, 0x2, 0xf7, 0xf8, 
    0x8, 0xd, 0x1, 0x2, 0xf8, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xf6, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 
    0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x3a, 0x2, 0x2, 
    0xff, 0x100, 0x7, 0x3a, 0x2, 0x2, 0x100, 0x101, 0x8, 0xd, 0x1, 0x2, 
    0x101, 0x10d, 0x7, 0xf, 0x2, 0x2, 0x102, 0x103, 0x5, 0x12, 0xa, 0x2, 
    0x103, 0x10a, 0x8, 0xd, 0x1, 0x2, 0x104, 0x105, 0x7, 0xd, 0x2, 0x2, 
    0x105, 0x106, 0x5, 0x12, 0xa, 0x2, 0x106, 0x107, 0x8, 0xd, 0x1, 0x2, 
    0x107, 0x109, 0x3, 0x2, 0x2, 0x2, 0x108, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x109, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10e, 0x3, 0x2, 0x2, 0x2, 
    0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x110, 0x7, 0x10, 0x2, 0x2, 0x110, 0x111, 0x8, 0xd, 0x1, 0x2, 
    0x111, 0x112, 0x5, 0x16, 0xc, 0x2, 0x112, 0x113, 0x8, 0xd, 0x1, 0x2, 
    0x113, 0x114, 0x8, 0xd, 0x1, 0x2, 0x114, 0x19, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x116, 0x7, 0x9, 0x2, 0x2, 0x116, 0x117, 0x7, 0x3a, 0x2, 0x2, 0x117, 
    0x11b, 0x8, 0xe, 0x1, 0x2, 0x118, 0x119, 0x5, 0xc, 0x7, 0x2, 0x119, 
    0x11a, 0x8, 0xe, 0x1, 0x2, 0x11a, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 
    0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x131, 0x7, 0x11, 0x2, 0x2, 0x11e, 
    0x11f, 0x7, 0x3a, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x17, 0x2, 0x2, 0x120, 
    0x121, 0x7, 0x3a, 0x2, 0x2, 0x121, 0x122, 0x8, 0xe, 0x1, 0x2, 0x122, 
    0x129, 0x7, 0xf, 0x2, 0x2, 0x123, 0x124, 0x7, 0x3a, 0x2, 0x2, 0x124, 
    0x125, 0x7, 0x17, 0x2, 0x2, 0x125, 0x126, 0x7, 0x3a, 0x2, 0x2, 0x126, 
    0x128, 0x8, 0xe, 0x1, 0x2, 0x127, 0x123, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 
    0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12b, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x10, 0x2, 0x2, 0x12d, 
    0x12e, 0x7, 0xc, 0x2, 0x2, 0x12e, 0x130, 0x8, 0xe, 0x1, 0x2, 0x12f, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 0x3, 0x2, 0x2, 0x2, 0x131, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 
    0x135, 0x7, 0x12, 0x2, 0x2, 0x135, 0x136, 0x7, 0xc, 0x2, 0x2, 0x136, 
    0x137, 0x8, 0xe, 0x1, 0x2, 0x137, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
    0x7, 0xa, 0x2, 0x2, 0x139, 0x13d, 0x8, 0xf, 0x1, 0x2, 0x13a, 0x13b, 
    0x7, 0xb, 0x2, 0x2, 0x13b, 0x13d, 0x8, 0xf, 0x1, 0x2, 0x13c, 0x138, 
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 
    0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x3a, 0x2, 0x2, 0x13f, 0x140, 
    0x8, 0xf, 0x1, 0x2, 0x140, 0x141, 0x7, 0x11, 0x2, 0x2, 0x141, 0x142, 
    0x7, 0x3a, 0x2, 0x2, 0x142, 0x148, 0x8, 0xf, 0x1, 0x2, 0x143, 0x144, 
    0x7, 0x13, 0x2, 0x2, 0x144, 0x145, 0x5, 0x1e, 0x10, 0x2, 0x145, 0x146, 
    0x8, 0xf, 0x1, 0x2, 0x146, 0x147, 0x7, 0x14, 0x2, 0x2, 0x147, 0x149, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x143, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 
    0x5, 0x1e, 0x10, 0x2, 0x14b, 0x14c, 0x8, 0xf, 0x1, 0x2, 0x14c, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x7, 0xc, 0x2, 0x2, 0x14e, 0x14f, 
    0x7, 0x12, 0x2, 0x2, 0x14f, 0x150, 0x7, 0xc, 0x2, 0x2, 0x150, 0x151, 
    0x8, 0xf, 0x1, 0x2, 0x151, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x5, 
    0x20, 0x11, 0x2, 0x153, 0x154, 0x8, 0x10, 0x1, 0x2, 0x154, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x156, 0x5, 0x22, 0x12, 0x2, 0x156, 0x15d, 0x8, 
    0x11, 0x1, 0x2, 0x157, 0x158, 0x7, 0x2b, 0x2, 0x2, 0x158, 0x159, 0x5, 
    0x22, 0x12, 0x2, 0x159, 0x15a, 0x8, 0x11, 0x1, 0x2, 0x15a, 0x15c, 0x3, 
    0x2, 0x2, 0x2, 0x15b, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15f, 0x3, 
    0x2, 0x2, 0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 
    0x2, 0x2, 0x2, 0x15e, 0x21, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x161, 0x5, 0x24, 0x13, 0x2, 0x161, 0x168, 0x8, 0x12, 
    0x1, 0x2, 0x162, 0x163, 0x7, 0x2a, 0x2, 0x2, 0x163, 0x164, 0x5, 0x24, 
    0x13, 0x2, 0x164, 0x165, 0x8, 0x12, 0x1, 0x2, 0x165, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x162, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 
    0x2, 0x2, 0x169, 0x23, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 
    0x2, 0x16b, 0x16c, 0x5, 0x26, 0x14, 0x2, 0x16c, 0x173, 0x8, 0x13, 0x1, 
    0x2, 0x16d, 0x16e, 0x9, 0x6, 0x2, 0x2, 0x16e, 0x16f, 0x5, 0x26, 0x14, 
    0x2, 0x16f, 0x170, 0x8, 0x13, 0x1, 0x2, 0x170, 0x172, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x172, 0x175, 0x3, 0x2, 0x2, 
    0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x25, 0x3, 0x2, 0x2, 0x2, 0x175, 0x173, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x177, 0x5, 0x28, 0x15, 0x2, 0x177, 0x17e, 0x8, 0x14, 0x1, 0x2, 
    0x178, 0x179, 0x9, 0x7, 0x2, 0x2, 0x179, 0x17a, 0x5, 0x28, 0x15, 0x2, 
    0x17a, 0x17b, 0x8, 0x14, 0x1, 0x2, 0x17b, 0x17d, 0x3, 0x2, 0x2, 0x2, 
    0x17c, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x180, 0x3, 0x2, 0x2, 0x2, 
    0x17e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 0x2, 
    0x17f, 0x27, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x181, 
    0x182, 0x5, 0x2a, 0x16, 0x2, 0x182, 0x189, 0x8, 0x15, 0x1, 0x2, 0x183, 
    0x184, 0x9, 0x8, 0x2, 0x2, 0x184, 0x185, 0x5, 0x2a, 0x16, 0x2, 0x185, 
    0x186, 0x8, 0x15, 0x1, 0x2, 0x186, 0x188, 0x3, 0x2, 0x2, 0x2, 0x187, 
    0x183, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 
    0x5, 0x2c, 0x17, 0x2, 0x18d, 0x194, 0x8, 0x16, 0x1, 0x2, 0x18e, 0x18f, 
    0x9, 0x9, 0x2, 0x2, 0x18f, 0x190, 0x5, 0x2c, 0x17, 0x2, 0x190, 0x191, 
    0x8, 0x16, 0x1, 0x2, 0x191, 0x193, 0x3, 0x2, 0x2, 0x2, 0x192, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x193, 0x196, 0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 
    0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x199, 0x9, 
    0xa, 0x2, 0x2, 0x198, 0x197, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x3, 
    0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x5, 
    0x2e, 0x18, 0x2, 0x19b, 0x19c, 0x8, 0x17, 0x1, 0x2, 0x19c, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x19e, 0x7, 0x33, 0x2, 0x2, 0x19e, 0x1b1, 0x8, 
    0x18, 0x1, 0x2, 0x19f, 0x1a0, 0x7, 0x36, 0x2, 0x2, 0x1a0, 0x1b1, 0x8, 
    0x18, 0x1, 0x2, 0x1a1, 0x1a2, 0x7, 0x38, 0x2, 0x2, 0x1a2, 0x1b1, 0x8, 
    0x18, 0x1, 0x2, 0x1a3, 0x1a4, 0x7, 0x39, 0x2, 0x2, 0x1a4, 0x1b1, 0x8, 
    0x18, 0x1, 0x2, 0x1a5, 0x1a6, 0x5, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x8, 
    0x18, 0x1, 0x2, 0x1a7, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 
    0x3a, 0x2, 0x2, 0x1a9, 0x1b1, 0x8, 0x18, 0x1, 0x2, 0x1aa, 0x1ab, 0x5, 
    0x4, 0x3, 0x2, 0x1ab, 0x1ac, 0x8, 0x18, 0x1, 0x2, 0x1ac, 0x1b1, 0x3, 
    0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x5, 0x30, 0x19, 0x2, 0x1ae, 0x1af, 0x8, 
    0x18, 0x1, 0x2, 0x1af, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x19d, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1a1, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1a5, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1aa, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0xf, 0x2, 0x2, 0x1b3, 0x1b4, 0x5, 0x1e, 
    0x10, 0x2, 0x1b4, 0x1b5, 0x7, 0x10, 0x2, 0x2, 0x1b5, 0x1b6, 0x8, 0x19, 
    0x1, 0x2, 0x1b6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x29, 0x37, 0x40, 0x44, 0x4a, 
    0x53, 0x55, 0x70, 0x72, 0x85, 0x92, 0x99, 0xa2, 0xaa, 0xb3, 0xb7, 0xb9, 
    0xc3, 0xcc, 0xd2, 0xd6, 0xe4, 0xef, 0xf4, 0xfb, 0x10a, 0x10d, 0x11b, 
    0x129, 0x131, 0x13c, 0x148, 0x15d, 0x168, 0x173, 0x17e, 0x189, 0x194, 
    0x198, 0x1b0, 
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
