

// include std container
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <stack>
#include <tuple>
extern std::vector<std::string> uncaughtPreprocessorDirectives;

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

std::vector<tree::TerminalNode *> AnyFXParser::StringContext::QO() {
  return getTokens(AnyFXParser::QO);
}

tree::TerminalNode* AnyFXParser::StringContext::QO(size_t i) {
  return getToken(AnyFXParser::QO, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::StringContext::Q() {
  return getTokens(AnyFXParser::Q);
}

tree::TerminalNode* AnyFXParser::StringContext::Q(size_t i) {
  return getToken(AnyFXParser::Q, i);
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
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::QO: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        match(AnyFXParser::QO);
        setState(89);
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
          | (1ULL << AnyFXParser::T__31)
          | (1ULL << AnyFXParser::T__32)
          | (1ULL << AnyFXParser::T__33)
          | (1ULL << AnyFXParser::T__34)
          | (1ULL << AnyFXParser::T__35)
          | (1ULL << AnyFXParser::T__36)
          | (1ULL << AnyFXParser::T__37)
          | (1ULL << AnyFXParser::T__38)
          | (1ULL << AnyFXParser::T__39)
          | (1ULL << AnyFXParser::T__40)
          | (1ULL << AnyFXParser::T__41)
          | (1ULL << AnyFXParser::T__42)
          | (1ULL << AnyFXParser::T__43)
          | (1ULL << AnyFXParser::T__44)
          | (1ULL << AnyFXParser::T__45)
          | (1ULL << AnyFXParser::T__46)
          | (1ULL << AnyFXParser::T__47)
          | (1ULL << AnyFXParser::T__48)
          | (1ULL << AnyFXParser::T__49)
          | (1ULL << AnyFXParser::T__50)
          | (1ULL << AnyFXParser::T__51)
          | (1ULL << AnyFXParser::T__52)
          | (1ULL << AnyFXParser::T__53)
          | (1ULL << AnyFXParser::T__54)
          | (1ULL << AnyFXParser::T__55)
          | (1ULL << AnyFXParser::T__56)
          | (1ULL << AnyFXParser::T__57)
          | (1ULL << AnyFXParser::T__58)
          | (1ULL << AnyFXParser::T__59)
          | (1ULL << AnyFXParser::T__60)
          | (1ULL << AnyFXParser::T__61)
          | (1ULL << AnyFXParser::T__62))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::T__63 - 64))
          | (1ULL << (AnyFXParser::T__64 - 64))
          | (1ULL << (AnyFXParser::T__65 - 64))
          | (1ULL << (AnyFXParser::T__66 - 64))
          | (1ULL << (AnyFXParser::T__67 - 64))
          | (1ULL << (AnyFXParser::T__68 - 64))
          | (1ULL << (AnyFXParser::SC - 64))
          | (1ULL << (AnyFXParser::CO - 64))
          | (1ULL << (AnyFXParser::COL - 64))
          | (1ULL << (AnyFXParser::LP - 64))
          | (1ULL << (AnyFXParser::RP - 64))
          | (1ULL << (AnyFXParser::LB - 64))
          | (1ULL << (AnyFXParser::RB - 64))
          | (1ULL << (AnyFXParser::LL - 64))
          | (1ULL << (AnyFXParser::RR - 64))
          | (1ULL << (AnyFXParser::DOT - 64))
          | (1ULL << (AnyFXParser::NOT - 64))
          | (1ULL << (AnyFXParser::EQ - 64))
          | (1ULL << (AnyFXParser::QU - 64))
          | (1ULL << (AnyFXParser::AND - 64))
          | (1ULL << (AnyFXParser::OR - 64))
          | (1ULL << (AnyFXParser::Q - 64))
          | (1ULL << (AnyFXParser::NU - 64))
          | (1ULL << (AnyFXParser::FORWARDSLASH - 64))
          | (1ULL << (AnyFXParser::LESS - 64))
          | (1ULL << (AnyFXParser::LESSEQ - 64))
          | (1ULL << (AnyFXParser::GREATER - 64))
          | (1ULL << (AnyFXParser::GREATEREQ - 64))
          | (1ULL << (AnyFXParser::LOGICEQ - 64))
          | (1ULL << (AnyFXParser::NOTEQ - 64))
          | (1ULL << (AnyFXParser::LOGICAND - 64))
          | (1ULL << (AnyFXParser::LOGICOR - 64))
          | (1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
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
          setState(85);
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
          setState(91);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(92);
        match(AnyFXParser::QO);
        break;
      }

      case AnyFXParser::Q: {
        enterOuterAlt(_localctx, 2);
        setState(93);
        match(AnyFXParser::Q);
        setState(98);
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
          | (1ULL << AnyFXParser::T__31)
          | (1ULL << AnyFXParser::T__32)
          | (1ULL << AnyFXParser::T__33)
          | (1ULL << AnyFXParser::T__34)
          | (1ULL << AnyFXParser::T__35)
          | (1ULL << AnyFXParser::T__36)
          | (1ULL << AnyFXParser::T__37)
          | (1ULL << AnyFXParser::T__38)
          | (1ULL << AnyFXParser::T__39)
          | (1ULL << AnyFXParser::T__40)
          | (1ULL << AnyFXParser::T__41)
          | (1ULL << AnyFXParser::T__42)
          | (1ULL << AnyFXParser::T__43)
          | (1ULL << AnyFXParser::T__44)
          | (1ULL << AnyFXParser::T__45)
          | (1ULL << AnyFXParser::T__46)
          | (1ULL << AnyFXParser::T__47)
          | (1ULL << AnyFXParser::T__48)
          | (1ULL << AnyFXParser::T__49)
          | (1ULL << AnyFXParser::T__50)
          | (1ULL << AnyFXParser::T__51)
          | (1ULL << AnyFXParser::T__52)
          | (1ULL << AnyFXParser::T__53)
          | (1ULL << AnyFXParser::T__54)
          | (1ULL << AnyFXParser::T__55)
          | (1ULL << AnyFXParser::T__56)
          | (1ULL << AnyFXParser::T__57)
          | (1ULL << AnyFXParser::T__58)
          | (1ULL << AnyFXParser::T__59)
          | (1ULL << AnyFXParser::T__60)
          | (1ULL << AnyFXParser::T__61)
          | (1ULL << AnyFXParser::T__62))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::T__63 - 64))
          | (1ULL << (AnyFXParser::T__64 - 64))
          | (1ULL << (AnyFXParser::T__65 - 64))
          | (1ULL << (AnyFXParser::T__66 - 64))
          | (1ULL << (AnyFXParser::T__67 - 64))
          | (1ULL << (AnyFXParser::T__68 - 64))
          | (1ULL << (AnyFXParser::SC - 64))
          | (1ULL << (AnyFXParser::CO - 64))
          | (1ULL << (AnyFXParser::COL - 64))
          | (1ULL << (AnyFXParser::LP - 64))
          | (1ULL << (AnyFXParser::RP - 64))
          | (1ULL << (AnyFXParser::LB - 64))
          | (1ULL << (AnyFXParser::RB - 64))
          | (1ULL << (AnyFXParser::LL - 64))
          | (1ULL << (AnyFXParser::RR - 64))
          | (1ULL << (AnyFXParser::DOT - 64))
          | (1ULL << (AnyFXParser::NOT - 64))
          | (1ULL << (AnyFXParser::EQ - 64))
          | (1ULL << (AnyFXParser::QO - 64))
          | (1ULL << (AnyFXParser::QU - 64))
          | (1ULL << (AnyFXParser::AND - 64))
          | (1ULL << (AnyFXParser::OR - 64))
          | (1ULL << (AnyFXParser::NU - 64))
          | (1ULL << (AnyFXParser::FORWARDSLASH - 64))
          | (1ULL << (AnyFXParser::LESS - 64))
          | (1ULL << (AnyFXParser::LESSEQ - 64))
          | (1ULL << (AnyFXParser::GREATER - 64))
          | (1ULL << (AnyFXParser::GREATEREQ - 64))
          | (1ULL << (AnyFXParser::LOGICEQ - 64))
          | (1ULL << (AnyFXParser::NOTEQ - 64))
          | (1ULL << (AnyFXParser::LOGICAND - 64))
          | (1ULL << (AnyFXParser::LOGICOR - 64))
          | (1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
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
          setState(94);
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
          setState(100);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(101);
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
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        match(AnyFXParser::T__0);
         dynamic_cast<BooleanContext *>(_localctx)->val =  true; 
        break;
      }

      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(106);
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
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(117);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
           start = _input->LT(1); 
          setState(111);
          match(AnyFXParser::T__2);
          setState(112);
          dynamic_cast<PreprocessContext *>(_localctx)->line = match(AnyFXParser::INTEGERLITERAL);
          setState(113);
          dynamic_cast<PreprocessContext *>(_localctx)->path = string();
           lines.push_back(std::make_tuple(atoi((dynamic_cast<PreprocessContext *>(_localctx)->line != nullptr ? dynamic_cast<PreprocessContext *>(_localctx)->line->getText() : "").c_str()) - (int)start->getLine() - 1, _input->LT(-1)->getLine(), start->getStartIndex(), _input->LT(1)->getStartIndex(), (dynamic_cast<PreprocessContext *>(_localctx)->path != nullptr ? _input->getText(dynamic_cast<PreprocessContext *>(_localctx)->path->start, dynamic_cast<PreprocessContext *>(_localctx)->path->stop) : nullptr))); 
          break;
        }

        case 2: {
          setState(116);
          matchWildcard();
          break;
        }

        } 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(122);
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
    setState(124);
    dynamic_cast<EntryContext *>(_localctx)->effectContext = effect();

    		dynamic_cast<EntryContext *>(_localctx)->effectContext->eff.SetPreprocessorPassthrough(uncaughtPreprocessorDirectives);
    		uncaughtPreprocessorDirectives.clear();
    		dynamic_cast<EntryContext *>(_localctx)->returnEffect =  dynamic_cast<EntryContext *>(_localctx)->effectContext->eff;
    	
    setState(126);
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

std::vector<AnyFXParser::ConstantContext *> AnyFXParser::EffectContext::constant() {
  return getRuleContexts<AnyFXParser::ConstantContext>();
}

AnyFXParser::ConstantContext* AnyFXParser::EffectContext::constant(size_t i) {
  return getRuleContext<AnyFXParser::ConstantContext>(i);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::EffectContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::EffectContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}

std::vector<AnyFXParser::RenderStateContext *> AnyFXParser::EffectContext::renderState() {
  return getRuleContexts<AnyFXParser::RenderStateContext>();
}

AnyFXParser::RenderStateContext* AnyFXParser::EffectContext::renderState(size_t i) {
  return getRuleContext<AnyFXParser::RenderStateContext>(i);
}

std::vector<AnyFXParser::FunctionContext *> AnyFXParser::EffectContext::function() {
  return getRuleContexts<AnyFXParser::FunctionContext>();
}

AnyFXParser::FunctionContext* AnyFXParser::EffectContext::function(size_t i) {
  return getRuleContext<AnyFXParser::FunctionContext>(i);
}

std::vector<AnyFXParser::ProgramContext *> AnyFXParser::EffectContext::program() {
  return getRuleContexts<AnyFXParser::ProgramContext>();
}

AnyFXParser::ProgramContext* AnyFXParser::EffectContext::program(size_t i) {
  return getRuleContext<AnyFXParser::ProgramContext>(i);
}

std::vector<AnyFXParser::StructureContext *> AnyFXParser::EffectContext::structure() {
  return getRuleContexts<AnyFXParser::StructureContext>();
}

AnyFXParser::StructureContext* AnyFXParser::EffectContext::structure(size_t i) {
  return getRuleContext<AnyFXParser::StructureContext>(i);
}

std::vector<AnyFXParser::VarblockContext *> AnyFXParser::EffectContext::varblock() {
  return getRuleContexts<AnyFXParser::VarblockContext>();
}

AnyFXParser::VarblockContext* AnyFXParser::EffectContext::varblock(size_t i) {
  return getRuleContext<AnyFXParser::VarblockContext>(i);
}

std::vector<AnyFXParser::VarbufferContext *> AnyFXParser::EffectContext::varbuffer() {
  return getRuleContexts<AnyFXParser::VarbufferContext>();
}

AnyFXParser::VarbufferContext* AnyFXParser::EffectContext::varbuffer(size_t i) {
  return getRuleContext<AnyFXParser::VarbufferContext>(i);
}

std::vector<AnyFXParser::SubroutineContext *> AnyFXParser::EffectContext::subroutine() {
  return getRuleContexts<AnyFXParser::SubroutineContext>();
}

AnyFXParser::SubroutineContext* AnyFXParser::EffectContext::subroutine(size_t i) {
  return getRuleContext<AnyFXParser::SubroutineContext>(i);
}

std::vector<AnyFXParser::SamplerContext *> AnyFXParser::EffectContext::sampler() {
  return getRuleContexts<AnyFXParser::SamplerContext>();
}

AnyFXParser::SamplerContext* AnyFXParser::EffectContext::sampler(size_t i) {
  return getRuleContext<AnyFXParser::SamplerContext>(i);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(158);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(128);
          dynamic_cast<EffectContext *>(_localctx)->constantContext = constant();
           _localctx->eff.AddConstant(dynamic_cast<EffectContext *>(_localctx)->constantContext->cons);
          break;
        }

        case 2: {
          setState(131);
          dynamic_cast<EffectContext *>(_localctx)->variableContext = variable();
           _localctx->eff.AddVariable(dynamic_cast<EffectContext *>(_localctx)->variableContext->var); 
          break;
        }

        case 3: {
          setState(134);
          dynamic_cast<EffectContext *>(_localctx)->renderStateContext = renderState();
           _localctx->eff.AddRenderState(dynamic_cast<EffectContext *>(_localctx)->renderStateContext->state); 
          break;
        }

        case 4: {
          setState(137);
          dynamic_cast<EffectContext *>(_localctx)->functionContext = function();
           _localctx->eff.AddFunction(dynamic_cast<EffectContext *>(_localctx)->functionContext->func); 
          break;
        }

        case 5: {
          setState(140);
          dynamic_cast<EffectContext *>(_localctx)->programContext = program();
           _localctx->eff.AddProgram(dynamic_cast<EffectContext *>(_localctx)->programContext->prog); 
          break;
        }

        case 6: {
          setState(143);
          dynamic_cast<EffectContext *>(_localctx)->structureContext = structure();
           _localctx->eff.AddStructure(dynamic_cast<EffectContext *>(_localctx)->structureContext->struc); 
          break;
        }

        case 7: {
          setState(146);
          dynamic_cast<EffectContext *>(_localctx)->varblockContext = varblock();
           _localctx->eff.AddVarBlock(dynamic_cast<EffectContext *>(_localctx)->varblockContext->block); 
          break;
        }

        case 8: {
          setState(149);
          dynamic_cast<EffectContext *>(_localctx)->varbufferContext = varbuffer();
           _localctx->eff.AddVarBuffer(dynamic_cast<EffectContext *>(_localctx)->varbufferContext->buffer); 
          break;
        }

        case 9: {
          setState(152);
          dynamic_cast<EffectContext *>(_localctx)->subroutineContext = subroutine();
           _localctx->eff.AddSubroutine(dynamic_cast<EffectContext *>(_localctx)->subroutineContext->subrout); 
          break;
        }

        case 10: {
          setState(155);
          dynamic_cast<EffectContext *>(_localctx)->samplerContext = sampler();
           _localctx->eff.AddSampler(dynamic_cast<EffectContext *>(_localctx)->samplerContext->samp); 
          break;
        }

        } 
      }
      setState(162);
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

//----------------- QualifierContext ------------------------------------------------------------------

AnyFXParser::QualifierContext::QualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::QualifierContext::getRuleIndex() const {
  return AnyFXParser::RuleQualifier;
}

void AnyFXParser::QualifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifier(this);
}

void AnyFXParser::QualifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifier(this);
}

AnyFXParser::QualifierContext* AnyFXParser::qualifier() {
  QualifierContext *_localctx = _tracker.createInstance<QualifierContext>(_ctx, getState());
  enterRule(_localctx, 10, AnyFXParser::RuleQualifier);

  	Token* startToken = _input->LT(1);

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   _ctx->stop = _input->LT(-1);

    	dynamic_cast<QualifierContext *>(_localctx)->str =  startToken->getText();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifierValuedContext ------------------------------------------------------------------

AnyFXParser::QualifierValuedContext::QualifierValuedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::QualifierValuedContext::getRuleIndex() const {
  return AnyFXParser::RuleQualifierValued;
}

void AnyFXParser::QualifierValuedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifierValued(this);
}

void AnyFXParser::QualifierValuedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifierValued(this);
}

AnyFXParser::QualifierValuedContext* AnyFXParser::qualifierValued() {
  QualifierValuedContext *_localctx = _tracker.createInstance<QualifierValuedContext>(_ctx, getState());
  enterRule(_localctx, 12, AnyFXParser::RuleQualifierValued);

  	Token* startToken = _input->LT(1);

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    _la = _input->LA(1);
    if (!(_la == AnyFXParser::T__54

    || _la == AnyFXParser::T__55)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   _ctx->stop = _input->LT(-1);

    	dynamic_cast<QualifierValuedContext *>(_localctx)->str =  startToken->getText();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AnyFXParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::TypeContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}


size_t AnyFXParser::TypeContext::getRuleIndex() const {
  return AnyFXParser::RuleType;
}

void AnyFXParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void AnyFXParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

AnyFXParser::TypeContext* AnyFXParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, AnyFXParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    dynamic_cast<TypeContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);

    		std::string typeString((dynamic_cast<TypeContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<TypeContext *>(_localctx)->identifierToken->getText() : ""));
    		if (typeString == "float") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Float); }
    		else if (typeString == "int") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Integer); }
    		else if (typeString == "bool") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Bool); }
    		else if (typeString == "uint") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::UInteger); }
    		else if (typeString == "short") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Short); }
    		else if (typeString == "string") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::String); }
    		else if (typeString == "void") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Void); }
    		else if (typeString == "textureHandle") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::TextureHandle); }
    		else if (typeString == "imageHandle") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::ImageHandle); }
    		else if (typeString == "samplerHandle") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::SamplerHandle); }
    		else if (typeString == "inputAttachment") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachment); }
    		else if (typeString == "inputAttachmentMS") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentMS); }
    		else if (typeString == "inputAttachmentInteger") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentInteger); }
    		else if (typeString == "inputAttachmentIntegerMS") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentIntegerMS); }
    		else if (typeString == "inputAttachmentUInteger") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentUInteger); }
    		else if (typeString == "inputAttachmentUIntegerMS") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentUIntegerMS); }

    		// HLSL types
    		else if (typeString == "float2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Float2); }
    		else if (typeString == "float3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Float3); }
    		else if (typeString == "float4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Float4); }
    		else if (typeString == "int2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Integer2); }
    		else if (typeString == "int3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Integer3); }
    		else if (typeString == "int4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Integer4); }
    		else if (typeString == "uint2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::UInteger2); }
    		else if (typeString == "uint3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::UInteger3); }
    		else if (typeString == "uint4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::UInteger4); }
    		else if (typeString == "short2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Short2); }
    		else if (typeString == "short3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Short3); }
    		else if (typeString == "short4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Short4); }
    		else if (typeString == "bool2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Bool2); }
    		else if (typeString == "bool3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Bool3); }
    		else if (typeString == "bool4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Bool4); }
    		else if (typeString == "float2x2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix2x2); }
    		else if (typeString == "float2x3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix2x3); }
    		else if (typeString == "float2x4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix2x4); }
    		else if (typeString == "float3x2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix3x2); }
    		else if (typeString == "float3x3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix3x3); }
    		else if (typeString == "float3x4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix3x4); }
    		else if (typeString == "float4x2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix4x2); }
    		else if (typeString == "float4x3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix4x3); }
    		else if (typeString == "float4x4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix4x4); }
    		else if (typeString == "Texture1D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler1D); }
    		else if (typeString == "Texture1DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler1DArray); }
    		else if (typeString == "Texture2D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2D); }
    		else if (typeString == "Texture2DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2DArray); }
    		else if (typeString == "Texture2DMS") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2DMS); }
    		else if (typeString == "Texture2DMSArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2DMSArray); }
    		else if (typeString == "Texture3D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler3D); }
    		else if (typeString == "TextureCube") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::SamplerCube); }
    		else if (typeString == "TextureCubeArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::SamplerCubeArray); }
    		else if (typeString == "RWTexture1D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image1D); }
    		else if (typeString == "RWTexture1DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image1DArray); }
    		else if (typeString == "RWTexture2D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2D); }
    		else if (typeString == "RWTexture2DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2DArray); }
    		else if (typeString == "RWTexture2DMS") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2DMS); }
    		else if (typeString == "RWTexture2DMSArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2DMSArray); }
    		else if (typeString == "RWTexture3D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image3D); }
    		else if (typeString == "RWTextureCube") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::ImageCube); }
    		else if (typeString == "RWTextureCubeArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::ImageCubeArray); }

    		// GLSL types
    		else if (typeString == "vec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Float2); }
    		else if (typeString == "vec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Float3); }
    		else if (typeString == "vec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Float4); }
    		else if (typeString == "ivec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Integer2); }
    		else if (typeString == "ivec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Integer3); }
    		else if (typeString == "ivec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Integer4); }
    		else if (typeString == "uvec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::UInteger2); }
    		else if (typeString == "uvec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::UInteger3); }
    		else if (typeString == "uvec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::UInteger4); }
    		else if (typeString == "svec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Short2); }
    		else if (typeString == "svec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Short3); }
    		else if (typeString == "svec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Short4); }
    		else if (typeString == "bvec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Bool2); }
    		else if (typeString == "bvec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Bool3); }
    		else if (typeString == "bvec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Bool4); }
    		else if (typeString == "mat2x2" || typeString == "mat2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix2x2); }
    		else if (typeString == "mat2x3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix2x3); }
    		else if (typeString == "mat2x4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix2x4); }
    		else if (typeString == "mat3x2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix3x2); }
    		else if (typeString == "mat3x3" || typeString == "mat3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix3x3); }
    		else if (typeString == "mat3x4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix3x4); }
    		else if (typeString == "mat4x2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix4x2); }
    		else if (typeString == "mat4x3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix4x3); }
    		else if (typeString == "mat4x4" || typeString == "mat4" ) { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix4x4); }
    		else if (typeString == "sampler1D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler1D); }
    		else if (typeString == "sampler1DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler1DArray); }
    		else if (typeString == "sampler2D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2D); }
    		else if (typeString == "sampler2DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2DArray); }
    		else if (typeString == "sampler2DMS") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2DMS); }
    		else if (typeString == "sampler2DMSArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2DMSArray); }
    		else if (typeString == "sampler3D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler3D); }
    		else if (typeString == "samplerCube") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::SamplerCube); }
    		else if (typeString == "samplerCubeArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::SamplerCubeArray); }
    		else if (typeString == "image1D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image1D); }
    		else if (typeString == "image1DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image1DArray); }
    		else if (typeString == "image2D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2D); }
    		else if (typeString == "image2DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2DArray); }
    		else if (typeString == "image2DMS") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2DMS); }
    		else if (typeString == "image2DMSArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2DMSArray); }
    		else if (typeString == "image3D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image3D); }
    		else if (typeString == "imageCube") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::ImageCube); }
    		else if (typeString == "imageCubeArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::ImageCubeArray); }
    		else if (typeString == "texture1D") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture1D); }
    		else if (typeString == "texture1DArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture1DArray); }
    		else if (typeString == "texture2D") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2D); }
    		else if (typeString == "texture2DArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2DArray); }
    		else if (typeString == "texture2DMS") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2DMS); }
    		else if (typeString == "texture2DMSArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2DMSArray); }
    		else if (typeString == "texture3D") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture3D); }
    		else if (typeString == "textureCube") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::TextureCube); }
    		else if (typeString == "textureCubeArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::TextureCubeArray); }
    		else if (typeString == "atomic_uint") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::AtomicCounter); }

    		// user defined type detected
    		else { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::UserType); _localctx->ty.SetName(typeString); }
    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifierExpressionContext ------------------------------------------------------------------

AnyFXParser::QualifierExpressionContext::QualifierExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ParantexpressionContext* AnyFXParser::QualifierExpressionContext::parantexpression() {
  return getRuleContext<AnyFXParser::ParantexpressionContext>(0);
}

AnyFXParser::QualifierValuedContext* AnyFXParser::QualifierExpressionContext::qualifierValued() {
  return getRuleContext<AnyFXParser::QualifierValuedContext>(0);
}


size_t AnyFXParser::QualifierExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleQualifierExpression;
}

void AnyFXParser::QualifierExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifierExpression(this);
}

void AnyFXParser::QualifierExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifierExpression(this);
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::qualifierExpression() {
  QualifierExpressionContext *_localctx = _tracker.createInstance<QualifierExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, AnyFXParser::RuleQualifierExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    dynamic_cast<QualifierExpressionContext *>(_localctx)->base = qualifierValued();
    setState(171);
    dynamic_cast<QualifierExpressionContext *>(_localctx)->parantexpressionContext = parantexpression();
     _localctx->q.name = dynamic_cast<QualifierExpressionContext *>(_localctx)->base->str; _localctx->q.expr = dynamic_cast<QualifierExpressionContext *>(_localctx)->parantexpressionContext->tree; 
   
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

tree::TerminalNode* AnyFXParser::StructureContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::StructureContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::StructureContext::SC() {
  return getTokens(AnyFXParser::SC);
}

tree::TerminalNode* AnyFXParser::StructureContext::SC(size_t i) {
  return getToken(AnyFXParser::SC, i);
}

std::vector<AnyFXParser::ParameterContext *> AnyFXParser::StructureContext::parameter() {
  return getRuleContexts<AnyFXParser::ParameterContext>();
}

AnyFXParser::ParameterContext* AnyFXParser::StructureContext::parameter(size_t i) {
  return getRuleContext<AnyFXParser::ParameterContext>(i);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(AnyFXParser::T__56);
    setState(175);
    dynamic_cast<StructureContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->struc, _input); 
    setState(177);
    match(AnyFXParser::LB);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53))) != 0) || _la == AnyFXParser::LL

    || _la == AnyFXParser::IDENTIFIER) {
      setState(178);
      dynamic_cast<StructureContext *>(_localctx)->parameterContext = parameter();
      setState(179);
      match(AnyFXParser::SC);
       _localctx->struc.AddParameter(dynamic_cast<StructureContext *>(_localctx)->parameterContext->param); 
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(187);
    match(AnyFXParser::RB);
    setState(188);
    match(AnyFXParser::SC);
     _localctx->struc.SetName((dynamic_cast<StructureContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<StructureContext *>(_localctx)->identifierToken->getText() : ""));  
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarblockContext ------------------------------------------------------------------

AnyFXParser::VarblockContext::VarblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::VarblockContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::VarblockContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

tree::TerminalNode* AnyFXParser::VarblockContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

tree::TerminalNode* AnyFXParser::VarblockContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::VarblockContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::VarblockContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::VarblockContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::VarblockContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

AnyFXParser::AnnotationContext* AnyFXParser::VarblockContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::VarblockContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::VarblockContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}


size_t AnyFXParser::VarblockContext::getRuleIndex() const {
  return AnyFXParser::RuleVarblock;
}

void AnyFXParser::VarblockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarblock(this);
}

void AnyFXParser::VarblockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarblock(this);
}

AnyFXParser::VarblockContext* AnyFXParser::varblock() {
  VarblockContext *_localctx = _tracker.createInstance<VarblockContext>(_ctx, getState());
  enterRule(_localctx, 20, AnyFXParser::RuleVarblock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55))) != 0)) {
      setState(197);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
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
        case AnyFXParser::T__31:
        case AnyFXParser::T__32:
        case AnyFXParser::T__33:
        case AnyFXParser::T__34:
        case AnyFXParser::T__35:
        case AnyFXParser::T__36:
        case AnyFXParser::T__37:
        case AnyFXParser::T__38:
        case AnyFXParser::T__39:
        case AnyFXParser::T__40:
        case AnyFXParser::T__41:
        case AnyFXParser::T__42:
        case AnyFXParser::T__43:
        case AnyFXParser::T__44:
        case AnyFXParser::T__45:
        case AnyFXParser::T__46:
        case AnyFXParser::T__47:
        case AnyFXParser::T__48:
        case AnyFXParser::T__49:
        case AnyFXParser::T__50:
        case AnyFXParser::T__51:
        case AnyFXParser::T__52:
        case AnyFXParser::T__53: {
          setState(191);
          dynamic_cast<VarblockContext *>(_localctx)->qualifierContext = qualifier();
           _localctx->block.AddQualifier(dynamic_cast<VarblockContext *>(_localctx)->qualifierContext->str); 
          break;
        }

        case AnyFXParser::T__54:
        case AnyFXParser::T__55: {
          setState(194);
          dynamic_cast<VarblockContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->block.AddQualifierExpression(dynamic_cast<VarblockContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(202);
    match(AnyFXParser::T__57);
    setState(203);
    dynamic_cast<VarblockContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->block, _input); _localctx->block.SetName((dynamic_cast<VarblockContext *>(_localctx)->name != nullptr ? dynamic_cast<VarblockContext *>(_localctx)->name->getText() : "")); 
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(205);
      dynamic_cast<VarblockContext *>(_localctx)->annotationContext = annotation();
       _localctx->block.SetAnnotation(dynamic_cast<VarblockContext *>(_localctx)->annotationContext->annot); 
    }
    setState(210);
    match(AnyFXParser::LB);
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55))) != 0) || _la == AnyFXParser::IDENTIFIER) {
      setState(211);
      dynamic_cast<VarblockContext *>(_localctx)->variableContext = variable();
       _localctx->block.AddVariable(dynamic_cast<VarblockContext *>(_localctx)->variableContext->var); 
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(219);
    match(AnyFXParser::RB);
    setState(220);
    match(AnyFXParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarbufferContext ------------------------------------------------------------------

AnyFXParser::VarbufferContext::VarbufferContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::VarbufferContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::VarbufferContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::VarbufferContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::VarbufferContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::VarbufferContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

AnyFXParser::AnnotationContext* AnyFXParser::VarbufferContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::VarbufferContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::VarbufferContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}


size_t AnyFXParser::VarbufferContext::getRuleIndex() const {
  return AnyFXParser::RuleVarbuffer;
}

void AnyFXParser::VarbufferContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarbuffer(this);
}

void AnyFXParser::VarbufferContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarbuffer(this);
}

AnyFXParser::VarbufferContext* AnyFXParser::varbuffer() {
  VarbufferContext *_localctx = _tracker.createInstance<VarbufferContext>(_ctx, getState());
  enterRule(_localctx, 22, AnyFXParser::RuleVarbuffer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55))) != 0)) {
      setState(228);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
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
        case AnyFXParser::T__31:
        case AnyFXParser::T__32:
        case AnyFXParser::T__33:
        case AnyFXParser::T__34:
        case AnyFXParser::T__35:
        case AnyFXParser::T__36:
        case AnyFXParser::T__37:
        case AnyFXParser::T__38:
        case AnyFXParser::T__39:
        case AnyFXParser::T__40:
        case AnyFXParser::T__41:
        case AnyFXParser::T__42:
        case AnyFXParser::T__43:
        case AnyFXParser::T__44:
        case AnyFXParser::T__45:
        case AnyFXParser::T__46:
        case AnyFXParser::T__47:
        case AnyFXParser::T__48:
        case AnyFXParser::T__49:
        case AnyFXParser::T__50:
        case AnyFXParser::T__51:
        case AnyFXParser::T__52:
        case AnyFXParser::T__53: {
          setState(222);
          dynamic_cast<VarbufferContext *>(_localctx)->qualifierContext = qualifier();
           _localctx->buffer.AddQualifier(dynamic_cast<VarbufferContext *>(_localctx)->qualifierContext->str); 
          break;
        }

        case AnyFXParser::T__54:
        case AnyFXParser::T__55: {
          setState(225);
          dynamic_cast<VarbufferContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->buffer.AddQualifierExpression(dynamic_cast<VarbufferContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(AnyFXParser::T__58);
    setState(234);
    dynamic_cast<VarbufferContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->buffer, _input); _localctx->buffer.SetName((dynamic_cast<VarbufferContext *>(_localctx)->name != nullptr ? dynamic_cast<VarbufferContext *>(_localctx)->name->getText() : "")); 
    setState(239);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(236);
      dynamic_cast<VarbufferContext *>(_localctx)->annotationContext = annotation();
       _localctx->buffer.SetAnnotation(dynamic_cast<VarbufferContext *>(_localctx)->annotationContext->annot); 
    }
    setState(241);
    match(AnyFXParser::LB);
    setState(247);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55))) != 0) || _la == AnyFXParser::IDENTIFIER) {
      setState(242);
      dynamic_cast<VarbufferContext *>(_localctx)->variableContext = variable();
      _localctx->buffer.AddVariable(dynamic_cast<VarbufferContext *>(_localctx)->variableContext->var); 
      setState(249);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
    match(AnyFXParser::RB);
    setState(251);
    match(AnyFXParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineContext ------------------------------------------------------------------

AnyFXParser::SubroutineContext::SubroutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::SubroutineContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

AnyFXParser::ParameterListContext* AnyFXParser::SubroutineContext::parameterList() {
  return getRuleContext<AnyFXParser::ParameterListContext>(0);
}

tree::TerminalNode* AnyFXParser::SubroutineContext::RP() {
  return getToken(AnyFXParser::RP, 0);
}

tree::TerminalNode* AnyFXParser::SubroutineContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

AnyFXParser::TypeContext* AnyFXParser::SubroutineContext::type() {
  return getRuleContext<AnyFXParser::TypeContext>(0);
}

tree::TerminalNode* AnyFXParser::SubroutineContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::FunctionContext* AnyFXParser::SubroutineContext::function() {
  return getRuleContext<AnyFXParser::FunctionContext>(0);
}


size_t AnyFXParser::SubroutineContext::getRuleIndex() const {
  return AnyFXParser::RuleSubroutine;
}

void AnyFXParser::SubroutineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubroutine(this);
}

void AnyFXParser::SubroutineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubroutine(this);
}

AnyFXParser::SubroutineContext* AnyFXParser::subroutine() {
  SubroutineContext *_localctx = _tracker.createInstance<SubroutineContext>(_ctx, getState());
  enterRule(_localctx, 24, AnyFXParser::RuleSubroutine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__59: {
        enterOuterAlt(_localctx, 1);
        setState(253);
        match(AnyFXParser::T__59);
        setState(254);
        dynamic_cast<SubroutineContext *>(_localctx)->retval = type();
        setState(255);
        dynamic_cast<SubroutineContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
         SetupFile(&_localctx->subrout, _input); 
        setState(257);
        match(AnyFXParser::LP);
        setState(258);
        dynamic_cast<SubroutineContext *>(_localctx)->parameterListContext = parameterList();
        setState(259);
        match(AnyFXParser::RP);
        setState(260);
        match(AnyFXParser::SC);

        		_localctx->subrout.SetSubroutineType(Subroutine::Signature);
        		_localctx->subrout.SetName((dynamic_cast<SubroutineContext *>(_localctx)->name != nullptr ? dynamic_cast<SubroutineContext *>(_localctx)->name->getText() : ""));
        		_localctx->subrout.SetParameters(dynamic_cast<SubroutineContext *>(_localctx)->parameterListContext->parameters);
        		_localctx->subrout.SetReturnType(dynamic_cast<SubroutineContext *>(_localctx)->retval->ty);
        	
        break;
      }

      case AnyFXParser::T__60: {
        enterOuterAlt(_localctx, 2);
        setState(263);
        match(AnyFXParser::T__60);
        setState(264);
        match(AnyFXParser::LP);
        setState(265);
        dynamic_cast<SubroutineContext *>(_localctx)->signature = match(AnyFXParser::IDENTIFIER);
        setState(266);
        match(AnyFXParser::RP);
         SetupFile(&_localctx->subrout, _input); 
        setState(268);
        dynamic_cast<SubroutineContext *>(_localctx)->functionContext = function();

        		_localctx->subrout.SetName(dynamic_cast<SubroutineContext *>(_localctx)->functionContext->func.GetName());
        		_localctx->subrout.SetSubroutineType(Subroutine::Implementation);
        		_localctx->subrout.SetSignature((dynamic_cast<SubroutineContext *>(_localctx)->signature != nullptr ? dynamic_cast<SubroutineContext *>(_localctx)->signature->getText() : ""));
        		_localctx->subrout.SetFunction(dynamic_cast<SubroutineContext *>(_localctx)->functionContext->func);
        	
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

//----------------- ValueListContext ------------------------------------------------------------------

AnyFXParser::ValueListContext::ValueListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::ValueListContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::ValueListContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ValueListContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::ValueListContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
}


size_t AnyFXParser::ValueListContext::getRuleIndex() const {
  return AnyFXParser::RuleValueList;
}

void AnyFXParser::ValueListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValueList(this);
}

void AnyFXParser::ValueListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValueList(this);
}

AnyFXParser::ValueListContext* AnyFXParser::valueList() {
  ValueListContext *_localctx = _tracker.createInstance<ValueListContext>(_ctx, getState());
  enterRule(_localctx, 26, AnyFXParser::RuleValueList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    dynamic_cast<ValueListContext *>(_localctx)->first = expression();
     _localctx->valList.AddValue(dynamic_cast<ValueListContext *>(_localctx)->first->tree); 
    setState(281);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::CO) {
      setState(275);
      match(AnyFXParser::CO);
      setState(276);
      dynamic_cast<ValueListContext *>(_localctx)->rest = expression();
       _localctx->valList.AddValue(dynamic_cast<ValueListContext *>(_localctx)->rest->tree); 
      setState(283);
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

//----------------- ValueSingleListContext ------------------------------------------------------------------

AnyFXParser::ValueSingleListContext::ValueSingleListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ValueSingleListContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ValueSingleListContext::getRuleIndex() const {
  return AnyFXParser::RuleValueSingleList;
}

void AnyFXParser::ValueSingleListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValueSingleList(this);
}

void AnyFXParser::ValueSingleListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValueSingleList(this);
}

AnyFXParser::ValueSingleListContext* AnyFXParser::valueSingleList() {
  ValueSingleListContext *_localctx = _tracker.createInstance<ValueSingleListContext>(_ctx, getState());
  enterRule(_localctx, 28, AnyFXParser::RuleValueSingleList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    dynamic_cast<ValueSingleListContext *>(_localctx)->expressionContext = expression();
     _localctx->valList.AddValue(dynamic_cast<ValueSingleListContext *>(_localctx)->expressionContext->tree); 
   
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

tree::TerminalNode* AnyFXParser::VariableContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::VariableContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::VariableContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

tree::TerminalNode* AnyFXParser::VariableContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::VariableContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::VariableContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::VariableContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::VariableContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

tree::TerminalNode* AnyFXParser::VariableContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::VariableContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

tree::TerminalNode* AnyFXParser::VariableContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

tree::TerminalNode* AnyFXParser::VariableContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::LP() {
  return getTokens(AnyFXParser::LP);
}

tree::TerminalNode* AnyFXParser::VariableContext::LP(size_t i) {
  return getToken(AnyFXParser::LP, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::RP() {
  return getTokens(AnyFXParser::RP);
}

tree::TerminalNode* AnyFXParser::VariableContext::RP(size_t i) {
  return getToken(AnyFXParser::RP, i);
}

tree::TerminalNode* AnyFXParser::VariableContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

AnyFXParser::AnnotationContext* AnyFXParser::VariableContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::ValueListContext *> AnyFXParser::VariableContext::valueList() {
  return getRuleContexts<AnyFXParser::ValueListContext>();
}

AnyFXParser::ValueListContext* AnyFXParser::VariableContext::valueList(size_t i) {
  return getRuleContext<AnyFXParser::ValueListContext>(i);
}

AnyFXParser::ExpressionContext* AnyFXParser::VariableContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

AnyFXParser::ValueSingleListContext* AnyFXParser::VariableContext::valueSingleList() {
  return getRuleContext<AnyFXParser::ValueSingleListContext>(0);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::VariableContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
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
  enterRule(_localctx, 30, AnyFXParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55))) != 0)) {
      setState(293);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
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
        case AnyFXParser::T__31:
        case AnyFXParser::T__32:
        case AnyFXParser::T__33:
        case AnyFXParser::T__34:
        case AnyFXParser::T__35:
        case AnyFXParser::T__36:
        case AnyFXParser::T__37:
        case AnyFXParser::T__38:
        case AnyFXParser::T__39:
        case AnyFXParser::T__40:
        case AnyFXParser::T__41:
        case AnyFXParser::T__42:
        case AnyFXParser::T__43:
        case AnyFXParser::T__44:
        case AnyFXParser::T__45:
        case AnyFXParser::T__46:
        case AnyFXParser::T__47:
        case AnyFXParser::T__48:
        case AnyFXParser::T__49:
        case AnyFXParser::T__50:
        case AnyFXParser::T__51:
        case AnyFXParser::T__52:
        case AnyFXParser::T__53: {
          setState(287);
          dynamic_cast<VariableContext *>(_localctx)->qualifierContext = qualifier();
           _localctx->var.AddQualifier(dynamic_cast<VariableContext *>(_localctx)->qualifierContext->str); 
          break;
        }

        case AnyFXParser::T__54:
        case AnyFXParser::T__55: {
          setState(290);
          dynamic_cast<VariableContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->var.AddQualifierExpression(dynamic_cast<VariableContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(298);
    dynamic_cast<VariableContext *>(_localctx)->declType = type();
    setState(299);
    dynamic_cast<VariableContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     _localctx->var.SetDataType(dynamic_cast<VariableContext *>(_localctx)->declType->ty); _localctx->var.SetName((dynamic_cast<VariableContext *>(_localctx)->name != nullptr ? dynamic_cast<VariableContext *>(_localctx)->name->getText() : "")); SetupFile(&_localctx->var, _input); 
    setState(388);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(301);
      match(AnyFXParser::LL);
      setState(302);
      match(AnyFXParser::RR);
      setState(303);
      match(AnyFXParser::EQ);
       _localctx->var.SetArrayType(Variable::TypedArray); 
      setState(305);
      match(AnyFXParser::LB);
      setState(306);
      dynamic_cast<VariableContext *>(_localctx)->fstType = type();
      setState(307);
      match(AnyFXParser::LP);
      setState(308);
      dynamic_cast<VariableContext *>(_localctx)->fstValue = valueList();
      setState(309);
      match(AnyFXParser::RP);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->fstType->ty, dynamic_cast<VariableContext *>(_localctx)->fstValue->valList); 
      setState(320);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(311);
        match(AnyFXParser::CO);
        setState(312);
        dynamic_cast<VariableContext *>(_localctx)->cntType = type();
        setState(313);
        match(AnyFXParser::LP);
        setState(314);
        dynamic_cast<VariableContext *>(_localctx)->cntValue = valueList();
        setState(315);
        match(AnyFXParser::RP);
         _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->cntType->ty, dynamic_cast<VariableContext *>(_localctx)->cntValue->valList); 
        setState(322);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(323);
      match(AnyFXParser::RB);
      break;
    }

    case 2: {
      setState(325);
      match(AnyFXParser::LL);
      setState(326);
      match(AnyFXParser::RR);
      setState(327);
      match(AnyFXParser::EQ);
       _localctx->var.SetArrayType(Variable::SimpleArray); 
      setState(329);
      match(AnyFXParser::LB);
      setState(330);
      dynamic_cast<VariableContext *>(_localctx)->valList = valueList();
      setState(331);
      match(AnyFXParser::RB);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->valList->valList); 
      break;
    }

    case 3: {
      setState(334);
      match(AnyFXParser::LL);
      setState(335);
      dynamic_cast<VariableContext *>(_localctx)->asize0 = expression();
      setState(336);
      match(AnyFXParser::RR);
       _localctx->var.SetSizeExpression(dynamic_cast<VariableContext *>(_localctx)->asize0->tree); 
      break;
    }

    case 4: {
      setState(339);
      match(AnyFXParser::LL);
      setState(340);
      dynamic_cast<VariableContext *>(_localctx)->asize1 = expression();
      setState(341);
      match(AnyFXParser::RR);
       _localctx->var.SetSizeExpression(dynamic_cast<VariableContext *>(_localctx)->asize1->tree); _localctx->var.SetArrayType(Variable::TypedArray); 
      setState(343);
      match(AnyFXParser::EQ);
      setState(344);
      match(AnyFXParser::LB);
      setState(345);
      dynamic_cast<VariableContext *>(_localctx)->fstType = type();
      setState(346);
      match(AnyFXParser::LP);
      setState(347);
      dynamic_cast<VariableContext *>(_localctx)->fstValue = valueList();
      setState(348);
      match(AnyFXParser::RP);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->fstType->ty, dynamic_cast<VariableContext *>(_localctx)->fstValue->valList); 
      setState(359);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(350);
        match(AnyFXParser::CO);
        setState(351);
        dynamic_cast<VariableContext *>(_localctx)->cntType = type();
        setState(352);
        match(AnyFXParser::LP);
        setState(353);
        dynamic_cast<VariableContext *>(_localctx)->cntValue = valueList();
        setState(354);
        match(AnyFXParser::RP);
         _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->cntType->ty, dynamic_cast<VariableContext *>(_localctx)->cntValue->valList); 
        setState(361);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(362);
      match(AnyFXParser::RB);
      break;
    }

    case 5: {
      setState(364);
      match(AnyFXParser::LL);
      setState(365);
      dynamic_cast<VariableContext *>(_localctx)->asize2 = expression();
      setState(366);
      match(AnyFXParser::RR);
       _localctx->var.SetSizeExpression(dynamic_cast<VariableContext *>(_localctx)->asize2->tree); _localctx->var.SetArrayType(Variable::SimpleArray); 
      setState(368);
      match(AnyFXParser::EQ);
      setState(369);
      match(AnyFXParser::LB);
      setState(370);
      dynamic_cast<VariableContext *>(_localctx)->valList = valueList();
      setState(371);
      match(AnyFXParser::RB);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->valList->valList); 
      break;
    }

    case 6: {
      setState(374);
      match(AnyFXParser::LL);
      setState(375);
      match(AnyFXParser::RR);
       _localctx->var.SetArrayType(Variable::UnsizedArray); 
      break;
    }

    case 7: {
      setState(377);
      match(AnyFXParser::EQ);
      setState(378);
      dynamic_cast<VariableContext *>(_localctx)->defType = type();
      setState(379);
      match(AnyFXParser::LP);
      setState(380);
      dynamic_cast<VariableContext *>(_localctx)->list2 = valueList();
      setState(381);
      match(AnyFXParser::RP);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->defType->ty, dynamic_cast<VariableContext *>(_localctx)->list2->valList); 
      break;
    }

    case 8: {
      setState(384);
      match(AnyFXParser::EQ);
      setState(385);
      dynamic_cast<VariableContext *>(_localctx)->list3 = valueSingleList();
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->list3->valList); 
      break;
    }

    }
    setState(393);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(390);
      dynamic_cast<VariableContext *>(_localctx)->annotationContext = annotation();
       _localctx->var.SetAnnotation(dynamic_cast<VariableContext *>(_localctx)->annotationContext->annot); 
    }
    setState(395);
    match(AnyFXParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

AnyFXParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::ConstantContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::ConstantContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::ConstantContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

tree::TerminalNode* AnyFXParser::ConstantContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::ConstantContext::LP() {
  return getTokens(AnyFXParser::LP);
}

tree::TerminalNode* AnyFXParser::ConstantContext::LP(size_t i) {
  return getToken(AnyFXParser::LP, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ConstantContext::RP() {
  return getTokens(AnyFXParser::RP);
}

tree::TerminalNode* AnyFXParser::ConstantContext::RP(size_t i) {
  return getToken(AnyFXParser::RP, i);
}

tree::TerminalNode* AnyFXParser::ConstantContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

tree::TerminalNode* AnyFXParser::ConstantContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::ConstantContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

tree::TerminalNode* AnyFXParser::ConstantContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::ConstantContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

std::vector<AnyFXParser::ValueListContext *> AnyFXParser::ConstantContext::valueList() {
  return getRuleContexts<AnyFXParser::ValueListContext>();
}

AnyFXParser::ValueListContext* AnyFXParser::ConstantContext::valueList(size_t i) {
  return getRuleContext<AnyFXParser::ValueListContext>(i);
}

AnyFXParser::ValueSingleListContext* AnyFXParser::ConstantContext::valueSingleList() {
  return getRuleContext<AnyFXParser::ValueSingleListContext>(0);
}

AnyFXParser::ExpressionContext* AnyFXParser::ConstantContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> AnyFXParser::ConstantContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::ConstantContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
}


size_t AnyFXParser::ConstantContext::getRuleIndex() const {
  return AnyFXParser::RuleConstant;
}

void AnyFXParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void AnyFXParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

AnyFXParser::ConstantContext* AnyFXParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 32, AnyFXParser::RuleConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(AnyFXParser::T__3);
    setState(398);
    dynamic_cast<ConstantContext *>(_localctx)->declType = type();
    setState(399);
    dynamic_cast<ConstantContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     _localctx->cons.SetDataType(dynamic_cast<ConstantContext *>(_localctx)->declType->ty); _localctx->cons.SetName((dynamic_cast<ConstantContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ConstantContext *>(_localctx)->identifierToken->getText() : "")); SetupFile(&_localctx->cons, _input); 
    setState(486);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(401);
      match(AnyFXParser::EQ);
      setState(402);
      dynamic_cast<ConstantContext *>(_localctx)->defType = type();
      setState(403);
      match(AnyFXParser::LP);
      setState(404);
      dynamic_cast<ConstantContext *>(_localctx)->sinVal1 = valueList();
      setState(405);
      match(AnyFXParser::RP);
      setState(406);
      match(AnyFXParser::SC);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->defType->ty, dynamic_cast<ConstantContext *>(_localctx)->sinVal1->valList); 
      break;
    }

    case 2: {
      setState(409);
      match(AnyFXParser::EQ);
      setState(410);
      dynamic_cast<ConstantContext *>(_localctx)->sinVal2 = valueSingleList();
      setState(411);
      match(AnyFXParser::SC);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->sinVal2->valList); 
      break;
    }

    case 3: {
      setState(414);
      match(AnyFXParser::LL);
      setState(415);
      match(AnyFXParser::RR);
      setState(416);
      match(AnyFXParser::EQ);
       _localctx->cons.SetArrayType(Constant::TypedArray); 
      setState(418);
      match(AnyFXParser::LB);
      setState(419);
      dynamic_cast<ConstantContext *>(_localctx)->fstType = type();
      setState(420);
      match(AnyFXParser::LP);
      setState(421);
      dynamic_cast<ConstantContext *>(_localctx)->fstValue = valueList();
      setState(422);
      match(AnyFXParser::RP);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->fstType->ty, dynamic_cast<ConstantContext *>(_localctx)->fstValue->valList); 
      setState(433);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(424);
        match(AnyFXParser::CO);
        setState(425);
        dynamic_cast<ConstantContext *>(_localctx)->cntType = type();
        setState(426);
        match(AnyFXParser::LP);
        setState(427);
        dynamic_cast<ConstantContext *>(_localctx)->cntValue = valueList();
        setState(428);
        match(AnyFXParser::RP);
         _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->cntType->ty, dynamic_cast<ConstantContext *>(_localctx)->cntValue->valList); 
        setState(435);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(436);
      match(AnyFXParser::RB);
      setState(437);
      match(AnyFXParser::SC);
      break;
    }

    case 4: {
      setState(439);
      match(AnyFXParser::LL);
      setState(440);
      match(AnyFXParser::RR);
      setState(441);
      match(AnyFXParser::EQ);
       _localctx->cons.SetArrayType(Constant::SimpleArray); 
      setState(443);
      match(AnyFXParser::LB);
      setState(444);
      dynamic_cast<ConstantContext *>(_localctx)->valList = valueList();
      setState(445);
      match(AnyFXParser::RB);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->valList->valList); 
      setState(447);
      match(AnyFXParser::SC);
      break;
    }

    case 5: {
      setState(449);
      match(AnyFXParser::LL);
      setState(450);
      dynamic_cast<ConstantContext *>(_localctx)->asize1 = expression();
      setState(451);
      match(AnyFXParser::RR);
       _localctx->cons.SetSizeExpression(dynamic_cast<ConstantContext *>(_localctx)->asize1->tree); _localctx->cons.SetArrayType(Constant::TypedArray); 
      setState(453);
      match(AnyFXParser::EQ);
      setState(454);
      match(AnyFXParser::LB);
      setState(455);
      dynamic_cast<ConstantContext *>(_localctx)->fstType = type();
      setState(456);
      match(AnyFXParser::LP);
      setState(457);
      dynamic_cast<ConstantContext *>(_localctx)->fstValue = valueList();
      setState(458);
      match(AnyFXParser::RP);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->fstType->ty, dynamic_cast<ConstantContext *>(_localctx)->fstValue->valList); 
      setState(469);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(460);
        match(AnyFXParser::CO);
        setState(461);
        dynamic_cast<ConstantContext *>(_localctx)->cntType = type();
        setState(462);
        match(AnyFXParser::LP);
        setState(463);
        dynamic_cast<ConstantContext *>(_localctx)->cntValue = valueList();
        setState(464);
        match(AnyFXParser::RP);
         _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->cntType->ty, dynamic_cast<ConstantContext *>(_localctx)->cntValue->valList); 
        setState(471);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(472);
      match(AnyFXParser::RB);
      setState(473);
      match(AnyFXParser::SC);
      break;
    }

    case 6: {
      setState(475);
      match(AnyFXParser::LL);
      setState(476);
      dynamic_cast<ConstantContext *>(_localctx)->asize2 = expression();
      setState(477);
      match(AnyFXParser::RR);
       _localctx->cons.SetSizeExpression(dynamic_cast<ConstantContext *>(_localctx)->asize2->tree); _localctx->cons.SetArrayType(Constant::SimpleArray); 
      setState(479);
      match(AnyFXParser::EQ);
      setState(480);
      match(AnyFXParser::LB);
      setState(481);
      dynamic_cast<ConstantContext *>(_localctx)->valList = valueList();
      setState(482);
      match(AnyFXParser::RB);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->valList->valList); 
      setState(484);
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

//----------------- ParameterAttributeContext ------------------------------------------------------------------

AnyFXParser::ParameterAttributeContext::ParameterAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::ParameterAttributeContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::ParameterAttributeContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

tree::TerminalNode* AnyFXParser::ParameterAttributeContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}


size_t AnyFXParser::ParameterAttributeContext::getRuleIndex() const {
  return AnyFXParser::RuleParameterAttribute;
}

void AnyFXParser::ParameterAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterAttribute(this);
}

void AnyFXParser::ParameterAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterAttribute(this);
}

AnyFXParser::ParameterAttributeContext* AnyFXParser::parameterAttribute() {
  ParameterAttributeContext *_localctx = _tracker.createInstance<ParameterAttributeContext>(_ctx, getState());
  enterRule(_localctx, 34, AnyFXParser::RuleParameterAttribute);

  			dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::NoAttribute;
  		

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    match(AnyFXParser::LL);
    setState(489);
    dynamic_cast<ParameterAttributeContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
    setState(490);
    match(AnyFXParser::RR);

    			std::string identifierString((dynamic_cast<ParameterAttributeContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ParameterAttributeContext *>(_localctx)->identifierToken->getText() : ""));

    			if (identifierString == "drawinstanceID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::DrawInstance; }
    			else if (identifierString == "vertexID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Vertex; }
    			else if (identifierString == "primitiveID") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Primitive; }
    			else if (identifierString == "invocationID") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Invocation; }
    			else if (identifierString == "viewportID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Viewport; }
    			else if (identifierString == "rendertargetID") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Rendertarget; }
    			else if (identifierString == "innertessellation") 				{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::InnerTessellation; }
    			else if (identifierString == "outertessellation") 				{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::OuterTessellation; }
    			else if (identifierString == "position") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Position; }
    			else if (identifierString == "pointsize") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::PointSize; }
    			else if (identifierString == "clipdistance") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::ClipDistance; }
    			else if (identifierString == "frontface") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::FrontFace; }
    			else if (identifierString == "coordinate") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Coordinate; }
    			else if (identifierString == "depth")							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Depth; }
    			else if (identifierString == "color0") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color0; }
    			else if (identifierString == "color1") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color1; }
    			else if (identifierString == "color2") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color2; }
    			else if (identifierString == "color3") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color3; }
    			else if (identifierString == "color4") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color4; }
    			else if (identifierString == "color5") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color5; }
    			else if (identifierString == "color6") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color6; }
    			else if (identifierString == "color7") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color7; }
    			else if (identifierString == "workgroupID")						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::WorkGroup; }
    			else if (identifierString == "numgroups")						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::NumGroups; }
    			else if (identifierString == "localID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::LocalID; }
    			else if (identifierString == "localindex") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::LocalIndex; }
    			else if (identifierString == "globalID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::GlobalID; }
    			else 															{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::InvalidAttribute; }
    		
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

AnyFXParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::TypeContext* AnyFXParser::ParameterContext::type() {
  return getRuleContext<AnyFXParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::ParameterContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::LL() {
  return getTokens(AnyFXParser::LL);
}

tree::TerminalNode* AnyFXParser::ParameterContext::LL(size_t i) {
  return getToken(AnyFXParser::LL, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::RR() {
  return getTokens(AnyFXParser::RR);
}

tree::TerminalNode* AnyFXParser::ParameterContext::RR(size_t i) {
  return getToken(AnyFXParser::RR, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::EQ() {
  return getTokens(AnyFXParser::EQ);
}

tree::TerminalNode* AnyFXParser::ParameterContext::EQ(size_t i) {
  return getToken(AnyFXParser::EQ, i);
}

tree::TerminalNode* AnyFXParser::ParameterContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

tree::TerminalNode* AnyFXParser::ParameterContext::CO() {
  return getToken(AnyFXParser::CO, 0);
}

tree::TerminalNode* AnyFXParser::ParameterContext::RP() {
  return getToken(AnyFXParser::RP, 0);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::ParameterContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::ParameterContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::ParameterContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::ParameterContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::ParameterContext::getRuleIndex() const {
  return AnyFXParser::RuleParameter;
}

void AnyFXParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void AnyFXParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

AnyFXParser::ParameterContext* AnyFXParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 36, AnyFXParser::RuleParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(493);
      match(AnyFXParser::LL);
      setState(494);
      dynamic_cast<ParameterContext *>(_localctx)->attr = match(AnyFXParser::IDENTIFIER);
      setState(495);
      match(AnyFXParser::RR);

      			_localctx->param.SetAttribute((dynamic_cast<ParameterContext *>(_localctx)->attr != nullptr ? dynamic_cast<ParameterContext *>(_localctx)->attr->getText() : ""));
      		
      break;
    }

    }
    setState(510);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(499);
      match(AnyFXParser::LL);
      setState(500);
      match(AnyFXParser::T__61);
      setState(501);
      match(AnyFXParser::EQ);
      setState(502);
      match(AnyFXParser::LP);
      setState(503);
      dynamic_cast<ParameterContext *>(_localctx)->feedbackBuffer = expression();
      setState(504);
      match(AnyFXParser::CO);
      setState(505);
      dynamic_cast<ParameterContext *>(_localctx)->feedbackOffset = expression();
      setState(506);
      match(AnyFXParser::RP);
      setState(507);
      match(AnyFXParser::RR);

      			_localctx->param.SetFeedbackBufferExpression(dynamic_cast<ParameterContext *>(_localctx)->feedbackBuffer->tree);
      			_localctx->param.SetFeedbackOffsetExpression(dynamic_cast<ParameterContext *>(_localctx)->feedbackOffset->tree);
      		
      break;
    }

    }
    setState(519);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(512);
      match(AnyFXParser::LL);
      setState(513);
      match(AnyFXParser::T__62);
      setState(514);
      match(AnyFXParser::EQ);
      setState(515);
      dynamic_cast<ParameterContext *>(_localctx)->slotExpression = expression();
      setState(516);
      match(AnyFXParser::RR);

      			_localctx->param.SetSlotExpression(dynamic_cast<ParameterContext *>(_localctx)->slotExpression->tree);
      		
    }
    setState(526);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53))) != 0)) {
      setState(521);
      dynamic_cast<ParameterContext *>(_localctx)->qualifierContext = qualifier();

      			_localctx->param.AddQualifier(dynamic_cast<ParameterContext *>(_localctx)->qualifierContext->str);
      		
      setState(528);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(529);
    dynamic_cast<ParameterContext *>(_localctx)->typeContext = type();
    setState(530);
    dynamic_cast<ParameterContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     _localctx->param.SetDataType(dynamic_cast<ParameterContext *>(_localctx)->typeContext->ty); _localctx->param.SetName((dynamic_cast<ParameterContext *>(_localctx)->name != nullptr ? dynamic_cast<ParameterContext *>(_localctx)->name->getText() : "")); SetupFile(&_localctx->param, _input); 
    setState(540);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(532);
      match(AnyFXParser::LL);
      setState(536);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AnyFXParser::T__0

      || _la == AnyFXParser::T__1 || ((((_la - 73) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 73)) & ((1ULL << (AnyFXParser::LP - 73))
        | (1ULL << (AnyFXParser::NOT - 73))
        | (1ULL << (AnyFXParser::SUB_OP - 73))
        | (1ULL << (AnyFXParser::INTEGERLITERAL - 73))
        | (1ULL << (AnyFXParser::FLOATLITERAL - 73))
        | (1ULL << (AnyFXParser::DOUBLELITERAL - 73))
        | (1ULL << (AnyFXParser::HEX - 73))
        | (1ULL << (AnyFXParser::IDENTIFIER - 73)))) != 0)) {
        setState(533);
        dynamic_cast<ParameterContext *>(_localctx)->size = expression();
         _localctx->param.SetSizeExpression(dynamic_cast<ParameterContext *>(_localctx)->size->tree); 
      }
      setState(538);
      match(AnyFXParser::RR);
       _localctx->param.ForceArrayFlag(); 
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

AnyFXParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::ParameterContext *> AnyFXParser::ParameterListContext::parameter() {
  return getRuleContexts<AnyFXParser::ParameterContext>();
}

AnyFXParser::ParameterContext* AnyFXParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<AnyFXParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterListContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::ParameterListContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
}


size_t AnyFXParser::ParameterListContext::getRuleIndex() const {
  return AnyFXParser::RuleParameterList;
}

void AnyFXParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void AnyFXParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}

AnyFXParser::ParameterListContext* AnyFXParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 38, AnyFXParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53))) != 0) || _la == AnyFXParser::LL

    || _la == AnyFXParser::IDENTIFIER) {
      setState(542);
      dynamic_cast<ParameterListContext *>(_localctx)->firstParam = parameter();
       _localctx->parameters.push_back(dynamic_cast<ParameterListContext *>(_localctx)->firstParam->param); 
      setState(550);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(544);
        match(AnyFXParser::CO);
        setState(545);
        dynamic_cast<ParameterListContext *>(_localctx)->followParam = parameter();
         _localctx->parameters.push_back(dynamic_cast<ParameterListContext *>(_localctx)->followParam->param); 
        setState(552);
        _errHandler->sync(this);
        _la = _input->LA(1);
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

//----------------- FunctionAttributeContext ------------------------------------------------------------------

AnyFXParser::FunctionAttributeContext::FunctionAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

AnyFXParser::ExpressionContext* AnyFXParser::FunctionAttributeContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> AnyFXParser::FunctionAttributeContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}


size_t AnyFXParser::FunctionAttributeContext::getRuleIndex() const {
  return AnyFXParser::RuleFunctionAttribute;
}

void AnyFXParser::FunctionAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionAttribute(this);
}

void AnyFXParser::FunctionAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionAttribute(this);
}

AnyFXParser::FunctionAttributeContext* AnyFXParser::functionAttribute() {
  FunctionAttributeContext *_localctx = _tracker.createInstance<FunctionAttributeContext>(_ctx, getState());
  enterRule(_localctx, 40, AnyFXParser::RuleFunctionAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(572);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(555);
      match(AnyFXParser::LL);
      setState(556);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(557);
      match(AnyFXParser::RR);
      setState(558);
      match(AnyFXParser::EQ);
      setState(559);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->expressionContext = expression();

      		std::string identifierString((dynamic_cast<FunctionAttributeContext *>(_localctx)->flag1 != nullptr ? dynamic_cast<FunctionAttributeContext *>(_localctx)->flag1->getText() : ""));

      		_localctx->attribute.SetExpression(identifierString, dynamic_cast<FunctionAttributeContext *>(_localctx)->expressionContext->tree);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(562);
      match(AnyFXParser::LL);
      setState(563);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3 = match(AnyFXParser::IDENTIFIER);
      setState(564);
      match(AnyFXParser::RR);
      setState(565);
      match(AnyFXParser::EQ);
      setState(566);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->data = match(AnyFXParser::IDENTIFIER);

      		std::string identifierString((dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3 != nullptr ? dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3->getText() : ""));
      		std::string dataString((dynamic_cast<FunctionAttributeContext *>(_localctx)->data != nullptr ? dynamic_cast<FunctionAttributeContext *>(_localctx)->data->getText() : ""));

      		_localctx->attribute.SetString(identifierString, dataString);
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(568);
      match(AnyFXParser::LL);
      setState(569);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3 = match(AnyFXParser::IDENTIFIER);
      setState(570);
      match(AnyFXParser::RR);

      		std::string identifierString((dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3 != nullptr ? dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3->getText() : ""));

      		_localctx->attribute.SetBool(identifierString, true);
      	
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

//----------------- CodeBlockContext ------------------------------------------------------------------

AnyFXParser::CodeBlockContext::CodeBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::CodeBlockContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::CodeBlockContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

std::vector<AnyFXParser::CodeBlockContext *> AnyFXParser::CodeBlockContext::codeBlock() {
  return getRuleContexts<AnyFXParser::CodeBlockContext>();
}

AnyFXParser::CodeBlockContext* AnyFXParser::CodeBlockContext::codeBlock(size_t i) {
  return getRuleContext<AnyFXParser::CodeBlockContext>(i);
}


size_t AnyFXParser::CodeBlockContext::getRuleIndex() const {
  return AnyFXParser::RuleCodeBlock;
}

void AnyFXParser::CodeBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeBlock(this);
}

void AnyFXParser::CodeBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeBlock(this);
}

AnyFXParser::CodeBlockContext* AnyFXParser::codeBlock() {
  CodeBlockContext *_localctx = _tracker.createInstance<CodeBlockContext>(_ctx, getState());
  enterRule(_localctx, 42, AnyFXParser::RuleCodeBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(583);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::LB: {
        enterOuterAlt(_localctx, 1);
        setState(574);
        match(AnyFXParser::LB);
        setState(578);
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
          | (1ULL << AnyFXParser::T__31)
          | (1ULL << AnyFXParser::T__32)
          | (1ULL << AnyFXParser::T__33)
          | (1ULL << AnyFXParser::T__34)
          | (1ULL << AnyFXParser::T__35)
          | (1ULL << AnyFXParser::T__36)
          | (1ULL << AnyFXParser::T__37)
          | (1ULL << AnyFXParser::T__38)
          | (1ULL << AnyFXParser::T__39)
          | (1ULL << AnyFXParser::T__40)
          | (1ULL << AnyFXParser::T__41)
          | (1ULL << AnyFXParser::T__42)
          | (1ULL << AnyFXParser::T__43)
          | (1ULL << AnyFXParser::T__44)
          | (1ULL << AnyFXParser::T__45)
          | (1ULL << AnyFXParser::T__46)
          | (1ULL << AnyFXParser::T__47)
          | (1ULL << AnyFXParser::T__48)
          | (1ULL << AnyFXParser::T__49)
          | (1ULL << AnyFXParser::T__50)
          | (1ULL << AnyFXParser::T__51)
          | (1ULL << AnyFXParser::T__52)
          | (1ULL << AnyFXParser::T__53)
          | (1ULL << AnyFXParser::T__54)
          | (1ULL << AnyFXParser::T__55)
          | (1ULL << AnyFXParser::T__56)
          | (1ULL << AnyFXParser::T__57)
          | (1ULL << AnyFXParser::T__58)
          | (1ULL << AnyFXParser::T__59)
          | (1ULL << AnyFXParser::T__60)
          | (1ULL << AnyFXParser::T__61)
          | (1ULL << AnyFXParser::T__62))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::T__63 - 64))
          | (1ULL << (AnyFXParser::T__64 - 64))
          | (1ULL << (AnyFXParser::T__65 - 64))
          | (1ULL << (AnyFXParser::T__66 - 64))
          | (1ULL << (AnyFXParser::T__67 - 64))
          | (1ULL << (AnyFXParser::T__68 - 64))
          | (1ULL << (AnyFXParser::SC - 64))
          | (1ULL << (AnyFXParser::CO - 64))
          | (1ULL << (AnyFXParser::COL - 64))
          | (1ULL << (AnyFXParser::LP - 64))
          | (1ULL << (AnyFXParser::RP - 64))
          | (1ULL << (AnyFXParser::LB - 64))
          | (1ULL << (AnyFXParser::LL - 64))
          | (1ULL << (AnyFXParser::RR - 64))
          | (1ULL << (AnyFXParser::DOT - 64))
          | (1ULL << (AnyFXParser::NOT - 64))
          | (1ULL << (AnyFXParser::EQ - 64))
          | (1ULL << (AnyFXParser::QO - 64))
          | (1ULL << (AnyFXParser::QU - 64))
          | (1ULL << (AnyFXParser::AND - 64))
          | (1ULL << (AnyFXParser::OR - 64))
          | (1ULL << (AnyFXParser::Q - 64))
          | (1ULL << (AnyFXParser::NU - 64))
          | (1ULL << (AnyFXParser::FORWARDSLASH - 64))
          | (1ULL << (AnyFXParser::LESS - 64))
          | (1ULL << (AnyFXParser::LESSEQ - 64))
          | (1ULL << (AnyFXParser::GREATER - 64))
          | (1ULL << (AnyFXParser::GREATEREQ - 64))
          | (1ULL << (AnyFXParser::LOGICEQ - 64))
          | (1ULL << (AnyFXParser::NOTEQ - 64))
          | (1ULL << (AnyFXParser::LOGICAND - 64))
          | (1ULL << (AnyFXParser::LOGICOR - 64))
          | (1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
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
          setState(575);
          codeBlock();
          setState(580);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(581);
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
      case AnyFXParser::T__31:
      case AnyFXParser::T__32:
      case AnyFXParser::T__33:
      case AnyFXParser::T__34:
      case AnyFXParser::T__35:
      case AnyFXParser::T__36:
      case AnyFXParser::T__37:
      case AnyFXParser::T__38:
      case AnyFXParser::T__39:
      case AnyFXParser::T__40:
      case AnyFXParser::T__41:
      case AnyFXParser::T__42:
      case AnyFXParser::T__43:
      case AnyFXParser::T__44:
      case AnyFXParser::T__45:
      case AnyFXParser::T__46:
      case AnyFXParser::T__47:
      case AnyFXParser::T__48:
      case AnyFXParser::T__49:
      case AnyFXParser::T__50:
      case AnyFXParser::T__51:
      case AnyFXParser::T__52:
      case AnyFXParser::T__53:
      case AnyFXParser::T__54:
      case AnyFXParser::T__55:
      case AnyFXParser::T__56:
      case AnyFXParser::T__57:
      case AnyFXParser::T__58:
      case AnyFXParser::T__59:
      case AnyFXParser::T__60:
      case AnyFXParser::T__61:
      case AnyFXParser::T__62:
      case AnyFXParser::T__63:
      case AnyFXParser::T__64:
      case AnyFXParser::T__65:
      case AnyFXParser::T__66:
      case AnyFXParser::T__67:
      case AnyFXParser::T__68:
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
      case AnyFXParser::OR:
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
        setState(582);
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

AnyFXParser::TypeContext* AnyFXParser::FunctionContext::type() {
  return getRuleContext<AnyFXParser::TypeContext>(0);
}

tree::TerminalNode* AnyFXParser::FunctionContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

tree::TerminalNode* AnyFXParser::FunctionContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

AnyFXParser::ParameterListContext* AnyFXParser::FunctionContext::parameterList() {
  return getRuleContext<AnyFXParser::ParameterListContext>(0);
}

tree::TerminalNode* AnyFXParser::FunctionContext::RP() {
  return getToken(AnyFXParser::RP, 0);
}

AnyFXParser::CodeBlockContext* AnyFXParser::FunctionContext::codeBlock() {
  return getRuleContext<AnyFXParser::CodeBlockContext>(0);
}

std::vector<AnyFXParser::FunctionAttributeContext *> AnyFXParser::FunctionContext::functionAttribute() {
  return getRuleContexts<AnyFXParser::FunctionAttributeContext>();
}

AnyFXParser::FunctionAttributeContext* AnyFXParser::FunctionContext::functionAttribute(size_t i) {
  return getRuleContext<AnyFXParser::FunctionAttributeContext>(i);
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
  enterRule(_localctx, 44, AnyFXParser::RuleFunction);

  			Token* lineToken = nullptr;
  			Token* functionToken = nullptr;
  			Token* startToken = nullptr;
  			Token* endToken = nullptr;
  		
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(590);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LL) {
      setState(585);
      dynamic_cast<FunctionContext *>(_localctx)->functionAttributeContext = functionAttribute();
       _localctx->func.ConsumeAttribute(dynamic_cast<FunctionContext *>(_localctx)->functionAttributeContext->attribute); 
      setState(592);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(595);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::T__63) {
      setState(593);
      match(AnyFXParser::T__63);
       _localctx->func.SetShader(true); 
    }
    setState(597);
    dynamic_cast<FunctionContext *>(_localctx)->typeContext = type();
    setState(598);
    dynamic_cast<FunctionContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->func, _input); functionToken = _input->LT(-2); 
    setState(600);
    match(AnyFXParser::LP);
    setState(601);
    dynamic_cast<FunctionContext *>(_localctx)->parameterListContext = parameterList();
    setState(602);
    match(AnyFXParser::RP);

    			// the code block will beafter the next LB
    			startToken = _input->LT(2);

    			UpdateLine(_input, -2);
    			_localctx->func.SetFunctionLine(this->lineOffset);
    			UpdateLine(_input, 2);
    			_localctx->func.SetCodeLine(this->lineOffset);
    		
    setState(604);
    codeBlock();

    			// save last token
    			endToken = _input->LT(-2);

    			// get all text inbetween the two tokens
    			antlr4::misc::Interval interval;
    			interval.a = startToken->getTokenIndex();
    			interval.b = endToken->getTokenIndex();
    			std::string code = _input->getText(interval);

    			// get all text inbetween the two tokens
    			if (code.length() > 0) _localctx->func.SetCode(code);
    		
     _localctx->func.SetName((dynamic_cast<FunctionContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<FunctionContext *>(_localctx)->identifierToken->getText() : "")); _localctx->func.SetReturnType(dynamic_cast<FunctionContext *>(_localctx)->typeContext->ty); _localctx->func.SetParameters(dynamic_cast<FunctionContext *>(_localctx)->parameterListContext->parameters); 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlendStateRowContext ------------------------------------------------------------------

AnyFXParser::BlendStateRowContext::BlendStateRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::BlendStateRowContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::BlendStateRowContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::BlendStateRowContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::BlendStateRowContext::getRuleIndex() const {
  return AnyFXParser::RuleBlendStateRow;
}

void AnyFXParser::BlendStateRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlendStateRow(this);
}

void AnyFXParser::BlendStateRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlendStateRow(this);
}

AnyFXParser::BlendStateRowContext* AnyFXParser::blendStateRow() {
  BlendStateRowContext *_localctx = _tracker.createInstance<BlendStateRowContext>(_ctx, getState());
  enterRule(_localctx, 46, AnyFXParser::RuleBlendStateRow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(626);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(608);
      dynamic_cast<BlendStateRowContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(609);
      match(AnyFXParser::LL);
      setState(610);
      dynamic_cast<BlendStateRowContext *>(_localctx)->index1 = expression();
      setState(611);
      match(AnyFXParser::RR);
      setState(612);
      match(AnyFXParser::EQ);
      setState(613);
      dynamic_cast<BlendStateRowContext *>(_localctx)->blendFlag = match(AnyFXParser::IDENTIFIER);
      setState(614);
      match(AnyFXParser::SC);

      		std::string flag((dynamic_cast<BlendStateRowContext *>(_localctx)->flag1 != nullptr ? dynamic_cast<BlendStateRowContext *>(_localctx)->flag1->getText() : ""));
      		_localctx->row.SetString(dynamic_cast<BlendStateRowContext *>(_localctx)->index1->tree, flag, (dynamic_cast<BlendStateRowContext *>(_localctx)->blendFlag != nullptr ? dynamic_cast<BlendStateRowContext *>(_localctx)->blendFlag->getText() : ""));
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(617);
      dynamic_cast<BlendStateRowContext *>(_localctx)->flag2 = match(AnyFXParser::IDENTIFIER);
      setState(618);
      match(AnyFXParser::LL);
      setState(619);
      dynamic_cast<BlendStateRowContext *>(_localctx)->index2 = expression();
      setState(620);
      match(AnyFXParser::RR);
      setState(621);
      match(AnyFXParser::EQ);
      setState(622);
      dynamic_cast<BlendStateRowContext *>(_localctx)->value = expression();
      setState(623);
      match(AnyFXParser::SC);

      		std::string flag((dynamic_cast<BlendStateRowContext *>(_localctx)->flag2 != nullptr ? dynamic_cast<BlendStateRowContext *>(_localctx)->flag2->getText() : ""));
      		_localctx->row.SetExpression(dynamic_cast<BlendStateRowContext *>(_localctx)->index2->tree, flag, dynamic_cast<BlendStateRowContext *>(_localctx)->value->tree);
      	
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

//----------------- RenderStateRowContext ------------------------------------------------------------------

AnyFXParser::RenderStateRowContext::RenderStateRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::RenderStateRowContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

AnyFXParser::ExpressionContext* AnyFXParser::RenderStateRowContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::RenderStateRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::RenderStateRowContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::RenderStateRowContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}


size_t AnyFXParser::RenderStateRowContext::getRuleIndex() const {
  return AnyFXParser::RuleRenderStateRow;
}

void AnyFXParser::RenderStateRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRenderStateRow(this);
}

void AnyFXParser::RenderStateRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRenderStateRow(this);
}

AnyFXParser::RenderStateRowContext* AnyFXParser::renderStateRow() {
  RenderStateRowContext *_localctx = _tracker.createInstance<RenderStateRowContext>(_ctx, getState());
  enterRule(_localctx, 48, AnyFXParser::RuleRenderStateRow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(639);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(628);
      dynamic_cast<RenderStateRowContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(629);
      match(AnyFXParser::EQ);
      setState(630);
      dynamic_cast<RenderStateRowContext *>(_localctx)->expressionContext = expression();
      setState(631);
      match(AnyFXParser::SC);

      		std::string flag((dynamic_cast<RenderStateRowContext *>(_localctx)->flag1 != nullptr ? dynamic_cast<RenderStateRowContext *>(_localctx)->flag1->getText() : ""));
      		_localctx->row.SetExpression(flag, dynamic_cast<RenderStateRowContext *>(_localctx)->expressionContext->tree);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(634);
      dynamic_cast<RenderStateRowContext *>(_localctx)->flag2 = match(AnyFXParser::IDENTIFIER);
      setState(635);
      match(AnyFXParser::EQ);
      setState(636);
      dynamic_cast<RenderStateRowContext *>(_localctx)->renderStateSetting = match(AnyFXParser::IDENTIFIER);
      setState(637);
      match(AnyFXParser::SC);

      		std::string flag((dynamic_cast<RenderStateRowContext *>(_localctx)->flag2 != nullptr ? dynamic_cast<RenderStateRowContext *>(_localctx)->flag2->getText() : ""));
      		_localctx->row.SetString(flag, (dynamic_cast<RenderStateRowContext *>(_localctx)->renderStateSetting != nullptr ? dynamic_cast<RenderStateRowContext *>(_localctx)->renderStateSetting->getText() : ""));
      	
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

//----------------- RenderStateContext ------------------------------------------------------------------

AnyFXParser::RenderStateContext::RenderStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::RenderStateContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

tree::TerminalNode* AnyFXParser::RenderStateContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

tree::TerminalNode* AnyFXParser::RenderStateContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::RenderStateContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

std::vector<AnyFXParser::RenderStateRowContext *> AnyFXParser::RenderStateContext::renderStateRow() {
  return getRuleContexts<AnyFXParser::RenderStateRowContext>();
}

AnyFXParser::RenderStateRowContext* AnyFXParser::RenderStateContext::renderStateRow(size_t i) {
  return getRuleContext<AnyFXParser::RenderStateRowContext>(i);
}

std::vector<AnyFXParser::BlendStateRowContext *> AnyFXParser::RenderStateContext::blendStateRow() {
  return getRuleContexts<AnyFXParser::BlendStateRowContext>();
}

AnyFXParser::BlendStateRowContext* AnyFXParser::RenderStateContext::blendStateRow(size_t i) {
  return getRuleContext<AnyFXParser::BlendStateRowContext>(i);
}


size_t AnyFXParser::RenderStateContext::getRuleIndex() const {
  return AnyFXParser::RuleRenderState;
}

void AnyFXParser::RenderStateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRenderState(this);
}

void AnyFXParser::RenderStateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRenderState(this);
}

AnyFXParser::RenderStateContext* AnyFXParser::renderState() {
  RenderStateContext *_localctx = _tracker.createInstance<RenderStateContext>(_ctx, getState());
  enterRule(_localctx, 50, AnyFXParser::RuleRenderState);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(664);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(641);
      match(AnyFXParser::T__64);
      setState(642);
      dynamic_cast<RenderStateContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->state, _input); 
      setState(644);
      match(AnyFXParser::SC);
       _localctx->state.SetName((dynamic_cast<RenderStateContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<RenderStateContext *>(_localctx)->identifierToken->getText() : "")); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(646);
      match(AnyFXParser::T__64);
      setState(647);
      dynamic_cast<RenderStateContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->state, _input); 
      setState(649);
      match(AnyFXParser::LB);
       _localctx->state.SetName((dynamic_cast<RenderStateContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<RenderStateContext *>(_localctx)->identifierToken->getText() : "")); 
      setState(659);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(657);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          setState(651);
          dynamic_cast<RenderStateContext *>(_localctx)->renderStateRowContext = renderStateRow();
           _localctx->state.ConsumeRenderRow(dynamic_cast<RenderStateContext *>(_localctx)->renderStateRowContext->row); 
          break;
        }

        case 2: {
          setState(654);
          dynamic_cast<RenderStateContext *>(_localctx)->blendStateRowContext = blendStateRow();
           _localctx->state.ConsumeBlendRow(dynamic_cast<RenderStateContext *>(_localctx)->blendStateRowContext->row); 
          break;
        }

        }
        setState(661);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(662);
      match(AnyFXParser::RB);
      setState(663);
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

//----------------- SamplerContext ------------------------------------------------------------------

AnyFXParser::SamplerContext::SamplerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::SamplerContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

tree::TerminalNode* AnyFXParser::SamplerContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::SamplerContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::SamplerContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::SamplerContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::SamplerContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

tree::TerminalNode* AnyFXParser::SamplerContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::SamplerContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

std::vector<AnyFXParser::SamplerRowContext *> AnyFXParser::SamplerContext::samplerRow() {
  return getRuleContexts<AnyFXParser::SamplerRowContext>();
}

AnyFXParser::SamplerRowContext* AnyFXParser::SamplerContext::samplerRow(size_t i) {
  return getRuleContext<AnyFXParser::SamplerRowContext>(i);
}


size_t AnyFXParser::SamplerContext::getRuleIndex() const {
  return AnyFXParser::RuleSampler;
}

void AnyFXParser::SamplerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSampler(this);
}

void AnyFXParser::SamplerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSampler(this);
}

AnyFXParser::SamplerContext* AnyFXParser::sampler() {
  SamplerContext *_localctx = _tracker.createInstance<SamplerContext>(_ctx, getState());
  enterRule(_localctx, 52, AnyFXParser::RuleSampler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(708);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(674);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
        | (1ULL << AnyFXParser::T__31)
        | (1ULL << AnyFXParser::T__32)
        | (1ULL << AnyFXParser::T__33)
        | (1ULL << AnyFXParser::T__34)
        | (1ULL << AnyFXParser::T__35)
        | (1ULL << AnyFXParser::T__36)
        | (1ULL << AnyFXParser::T__37)
        | (1ULL << AnyFXParser::T__38)
        | (1ULL << AnyFXParser::T__39)
        | (1ULL << AnyFXParser::T__40)
        | (1ULL << AnyFXParser::T__41)
        | (1ULL << AnyFXParser::T__42)
        | (1ULL << AnyFXParser::T__43)
        | (1ULL << AnyFXParser::T__44)
        | (1ULL << AnyFXParser::T__45)
        | (1ULL << AnyFXParser::T__46)
        | (1ULL << AnyFXParser::T__47)
        | (1ULL << AnyFXParser::T__48)
        | (1ULL << AnyFXParser::T__49)
        | (1ULL << AnyFXParser::T__50)
        | (1ULL << AnyFXParser::T__51)
        | (1ULL << AnyFXParser::T__52)
        | (1ULL << AnyFXParser::T__53)
        | (1ULL << AnyFXParser::T__54)
        | (1ULL << AnyFXParser::T__55))) != 0)) {
        setState(672);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
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
          case AnyFXParser::T__31:
          case AnyFXParser::T__32:
          case AnyFXParser::T__33:
          case AnyFXParser::T__34:
          case AnyFXParser::T__35:
          case AnyFXParser::T__36:
          case AnyFXParser::T__37:
          case AnyFXParser::T__38:
          case AnyFXParser::T__39:
          case AnyFXParser::T__40:
          case AnyFXParser::T__41:
          case AnyFXParser::T__42:
          case AnyFXParser::T__43:
          case AnyFXParser::T__44:
          case AnyFXParser::T__45:
          case AnyFXParser::T__46:
          case AnyFXParser::T__47:
          case AnyFXParser::T__48:
          case AnyFXParser::T__49:
          case AnyFXParser::T__50:
          case AnyFXParser::T__51:
          case AnyFXParser::T__52:
          case AnyFXParser::T__53: {
            setState(666);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierContext = qualifier();
             _localctx->samp.AddQualifier(dynamic_cast<SamplerContext *>(_localctx)->qualifierContext->str); 
            break;
          }

          case AnyFXParser::T__54:
          case AnyFXParser::T__55: {
            setState(669);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
             _localctx->samp.AddQualifierExpression(dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext->q); 
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(676);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(677);
      match(AnyFXParser::T__65);
      setState(678);
      dynamic_cast<SamplerContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->samp, _input); 
      setState(680);
      match(AnyFXParser::SC);
       _localctx->samp.SetName((dynamic_cast<SamplerContext *>(_localctx)->name != nullptr ? dynamic_cast<SamplerContext *>(_localctx)->name->getText() : "")); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(690);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
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
        | (1ULL << AnyFXParser::T__31)
        | (1ULL << AnyFXParser::T__32)
        | (1ULL << AnyFXParser::T__33)
        | (1ULL << AnyFXParser::T__34)
        | (1ULL << AnyFXParser::T__35)
        | (1ULL << AnyFXParser::T__36)
        | (1ULL << AnyFXParser::T__37)
        | (1ULL << AnyFXParser::T__38)
        | (1ULL << AnyFXParser::T__39)
        | (1ULL << AnyFXParser::T__40)
        | (1ULL << AnyFXParser::T__41)
        | (1ULL << AnyFXParser::T__42)
        | (1ULL << AnyFXParser::T__43)
        | (1ULL << AnyFXParser::T__44)
        | (1ULL << AnyFXParser::T__45)
        | (1ULL << AnyFXParser::T__46)
        | (1ULL << AnyFXParser::T__47)
        | (1ULL << AnyFXParser::T__48)
        | (1ULL << AnyFXParser::T__49)
        | (1ULL << AnyFXParser::T__50)
        | (1ULL << AnyFXParser::T__51)
        | (1ULL << AnyFXParser::T__52)
        | (1ULL << AnyFXParser::T__53)
        | (1ULL << AnyFXParser::T__54)
        | (1ULL << AnyFXParser::T__55))) != 0)) {
        setState(688);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
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
          case AnyFXParser::T__31:
          case AnyFXParser::T__32:
          case AnyFXParser::T__33:
          case AnyFXParser::T__34:
          case AnyFXParser::T__35:
          case AnyFXParser::T__36:
          case AnyFXParser::T__37:
          case AnyFXParser::T__38:
          case AnyFXParser::T__39:
          case AnyFXParser::T__40:
          case AnyFXParser::T__41:
          case AnyFXParser::T__42:
          case AnyFXParser::T__43:
          case AnyFXParser::T__44:
          case AnyFXParser::T__45:
          case AnyFXParser::T__46:
          case AnyFXParser::T__47:
          case AnyFXParser::T__48:
          case AnyFXParser::T__49:
          case AnyFXParser::T__50:
          case AnyFXParser::T__51:
          case AnyFXParser::T__52:
          case AnyFXParser::T__53: {
            setState(682);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierContext = qualifier();
             _localctx->samp.AddQualifier(dynamic_cast<SamplerContext *>(_localctx)->qualifierContext->str); 
            break;
          }

          case AnyFXParser::T__54:
          case AnyFXParser::T__55: {
            setState(685);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
             _localctx->samp.AddQualifierExpression(dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext->q); 
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(692);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(693);
      match(AnyFXParser::T__65);
      setState(694);
      dynamic_cast<SamplerContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->samp, _input); 
       _localctx->samp.SetName((dynamic_cast<SamplerContext *>(_localctx)->name != nullptr ? dynamic_cast<SamplerContext *>(_localctx)->name->getText() : "")); 
      setState(697);
      match(AnyFXParser::LB);
      setState(703);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(698);
        dynamic_cast<SamplerContext *>(_localctx)->samplerRowContext = samplerRow();
         _localctx->samp.ConsumeRow(dynamic_cast<SamplerContext *>(_localctx)->samplerRowContext->row); 
        setState(705);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(706);
      match(AnyFXParser::RB);
      setState(707);
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

//----------------- SamplerTextureListContext ------------------------------------------------------------------

AnyFXParser::SamplerTextureListContext::SamplerTextureListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::SamplerTextureListContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::SamplerTextureListContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::SamplerTextureListContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::SamplerTextureListContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
}


size_t AnyFXParser::SamplerTextureListContext::getRuleIndex() const {
  return AnyFXParser::RuleSamplerTextureList;
}

void AnyFXParser::SamplerTextureListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSamplerTextureList(this);
}

void AnyFXParser::SamplerTextureListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSamplerTextureList(this);
}

AnyFXParser::SamplerTextureListContext* AnyFXParser::samplerTextureList() {
  SamplerTextureListContext *_localctx = _tracker.createInstance<SamplerTextureListContext>(_ctx, getState());
  enterRule(_localctx, 54, AnyFXParser::RuleSamplerTextureList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    dynamic_cast<SamplerTextureListContext *>(_localctx)->firstItem = match(AnyFXParser::IDENTIFIER);
     _localctx->list.AddTexture((dynamic_cast<SamplerTextureListContext *>(_localctx)->firstItem != nullptr ? dynamic_cast<SamplerTextureListContext *>(_localctx)->firstItem->getText() : "")); 
    setState(717);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::CO) {
      setState(712);
      match(AnyFXParser::CO);
      setState(713);
      dynamic_cast<SamplerTextureListContext *>(_localctx)->nextItem = match(AnyFXParser::IDENTIFIER);
       _localctx->list.AddTexture((dynamic_cast<SamplerTextureListContext *>(_localctx)->nextItem != nullptr ? dynamic_cast<SamplerTextureListContext *>(_localctx)->nextItem->getText() : "")); 
      setState(719);
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

//----------------- SamplerRowContext ------------------------------------------------------------------

AnyFXParser::SamplerRowContext::SamplerRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::SamplerRowContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

AnyFXParser::ExpressionContext* AnyFXParser::SamplerRowContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

AnyFXParser::SamplerTextureListContext* AnyFXParser::SamplerRowContext::samplerTextureList() {
  return getRuleContext<AnyFXParser::SamplerTextureListContext>(0);
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}


size_t AnyFXParser::SamplerRowContext::getRuleIndex() const {
  return AnyFXParser::RuleSamplerRow;
}

void AnyFXParser::SamplerRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSamplerRow(this);
}

void AnyFXParser::SamplerRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSamplerRow(this);
}

AnyFXParser::SamplerRowContext* AnyFXParser::samplerRow() {
  SamplerRowContext *_localctx = _tracker.createInstance<SamplerRowContext>(_ctx, getState());
  enterRule(_localctx, 56, AnyFXParser::RuleSamplerRow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(739);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(720);
      dynamic_cast<SamplerRowContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(721);
      match(AnyFXParser::EQ);
      setState(722);
      dynamic_cast<SamplerRowContext *>(_localctx)->samplerMode = match(AnyFXParser::IDENTIFIER);
      setState(723);
      match(AnyFXParser::SC);

      		std::string flag((dynamic_cast<SamplerRowContext *>(_localctx)->flag1 != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->flag1->getText() : ""));
      		_localctx->row.SetString(flag, (dynamic_cast<SamplerRowContext *>(_localctx)->samplerMode != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->samplerMode->getText() : ""));
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(725);
      dynamic_cast<SamplerRowContext *>(_localctx)->flag2 = match(AnyFXParser::IDENTIFIER);
      setState(726);
      match(AnyFXParser::EQ);
      setState(727);
      dynamic_cast<SamplerRowContext *>(_localctx)->expressionContext = expression();
      setState(728);
      match(AnyFXParser::SC);

      		std::string flag((dynamic_cast<SamplerRowContext *>(_localctx)->flag2 != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->flag2->getText() : ""));
      		_localctx->row.SetExpression(flag, dynamic_cast<SamplerRowContext *>(_localctx)->expressionContext->tree);
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(731);
      dynamic_cast<SamplerRowContext *>(_localctx)->flag4 = match(AnyFXParser::IDENTIFIER);
      setState(732);
      match(AnyFXParser::EQ);
      setState(733);
      match(AnyFXParser::LB);
      setState(734);
      dynamic_cast<SamplerRowContext *>(_localctx)->samplerTextureListContext = samplerTextureList();
      setState(735);
      match(AnyFXParser::RB);
      setState(736);
      match(AnyFXParser::SC);

      		std::string flag((dynamic_cast<SamplerRowContext *>(_localctx)->flag4 != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->flag4->getText() : ""));

      		if (flag == "Samplers") _localctx->row.SetTextures(dynamic_cast<SamplerRowContext *>(_localctx)->samplerTextureListContext->list);
      		else					_localctx->row.SetString(flag, "Incorrectly formatted texture list");
      	
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

//----------------- ProgramRowContext ------------------------------------------------------------------

AnyFXParser::ProgramRowContext::ProgramRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::ProgramRowContext::EQ() {
  return getTokens(AnyFXParser::EQ);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::EQ(size_t i) {
  return getToken(AnyFXParser::EQ, i);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::RP() {
  return getToken(AnyFXParser::RP, 0);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::ProgramRowContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ProgramRowContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
}

AnyFXParser::StringContext* AnyFXParser::ProgramRowContext::string() {
  return getRuleContext<AnyFXParser::StringContext>(0);
}


size_t AnyFXParser::ProgramRowContext::getRuleIndex() const {
  return AnyFXParser::RuleProgramRow;
}

void AnyFXParser::ProgramRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgramRow(this);
}

void AnyFXParser::ProgramRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgramRow(this);
}

AnyFXParser::ProgramRowContext* AnyFXParser::programRow() {
  ProgramRowContext *_localctx = _tracker.createInstance<ProgramRowContext>(_ctx, getState());
  enterRule(_localctx, 58, AnyFXParser::RuleProgramRow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(775);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(741);
        dynamic_cast<ProgramRowContext *>(_localctx)->shader = match(AnyFXParser::IDENTIFIER);
        setState(742);
        match(AnyFXParser::EQ);
        setState(743);
        dynamic_cast<ProgramRowContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
        setState(744);
        match(AnyFXParser::LP);
        setState(749);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == AnyFXParser::IDENTIFIER) {
          setState(745);
          dynamic_cast<ProgramRowContext *>(_localctx)->var = match(AnyFXParser::IDENTIFIER);
          setState(746);
          match(AnyFXParser::EQ);
          setState(747);
          dynamic_cast<ProgramRowContext *>(_localctx)->implementation = match(AnyFXParser::IDENTIFIER);
           _localctx->row.SetSubroutineMapping((dynamic_cast<ProgramRowContext *>(_localctx)->var != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->var->getText() : ""), (dynamic_cast<ProgramRowContext *>(_localctx)->implementation != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->implementation->getText() : "")); 
        }
        setState(758);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AnyFXParser::CO) {
          setState(751);
          match(AnyFXParser::CO);
          setState(752);
          dynamic_cast<ProgramRowContext *>(_localctx)->var2 = match(AnyFXParser::IDENTIFIER);
          setState(753);
          match(AnyFXParser::EQ);
          setState(754);
          dynamic_cast<ProgramRowContext *>(_localctx)->implementation2 = match(AnyFXParser::IDENTIFIER);
           _localctx->row.SetSubroutineMapping((dynamic_cast<ProgramRowContext *>(_localctx)->var2 != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->var2->getText() : ""), (dynamic_cast<ProgramRowContext *>(_localctx)->implementation2 != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->implementation2->getText() : "")); 
          setState(760);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(761);
        match(AnyFXParser::RP);
        setState(762);
        match(AnyFXParser::SC);

        		std::string shaderString((dynamic_cast<ProgramRowContext *>(_localctx)->shader != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->shader->getText() : ""));
        		_localctx->row.SetString(shaderString, (dynamic_cast<ProgramRowContext *>(_localctx)->name != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->name->getText() : ""));
        	
        break;
      }

      case AnyFXParser::T__66: {
        enterOuterAlt(_localctx, 2);
        setState(764);
        match(AnyFXParser::T__66);
        setState(765);
        match(AnyFXParser::EQ);
        setState(766);
        dynamic_cast<ProgramRowContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
        setState(767);
        match(AnyFXParser::SC);

        		_localctx->row.SetString("RenderState", (dynamic_cast<ProgramRowContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->identifierToken->getText() : ""));
        	
        break;
      }

      case AnyFXParser::T__67: {
        enterOuterAlt(_localctx, 3);
        setState(769);
        match(AnyFXParser::T__67);
        setState(770);
        match(AnyFXParser::EQ);
        setState(771);
        dynamic_cast<ProgramRowContext *>(_localctx)->stringContext = string();
        setState(772);
        match(AnyFXParser::SC);

        		_localctx->row.SetString("CompileFlags", dynamic_cast<ProgramRowContext *>(_localctx)->stringContext->val.c_str());
        	
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

//----------------- AnnotationContext ------------------------------------------------------------------

AnyFXParser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::AnnotationContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::AnnotationContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::AnnotationContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::AnnotationContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::AnnotationContext::EQ() {
  return getTokens(AnyFXParser::EQ);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::EQ(size_t i) {
  return getToken(AnyFXParser::EQ, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::AnnotationContext::SC() {
  return getTokens(AnyFXParser::SC);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::SC(size_t i) {
  return getToken(AnyFXParser::SC, i);
}

std::vector<AnyFXParser::StringContext *> AnyFXParser::AnnotationContext::string() {
  return getRuleContexts<AnyFXParser::StringContext>();
}

AnyFXParser::StringContext* AnyFXParser::AnnotationContext::string(size_t i) {
  return getRuleContext<AnyFXParser::StringContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::AnnotationContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::AnnotationContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
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
  enterRule(_localctx, 60, AnyFXParser::RuleAnnotation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(777);
    match(AnyFXParser::LL);
    setState(794);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(778);
      dynamic_cast<AnnotationContext *>(_localctx)->typeContext = type();
      setState(779);
      dynamic_cast<AnnotationContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
      setState(780);
      match(AnyFXParser::EQ);
      setState(787);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AnyFXParser::QO:
        case AnyFXParser::Q: {
          setState(781);
          dynamic_cast<AnnotationContext *>(_localctx)->stringContext = string();
           _localctx->annot.AddString(dynamic_cast<AnnotationContext *>(_localctx)->stringContext->val); 
          break;
        }

        case AnyFXParser::T__0:
        case AnyFXParser::T__1:
        case AnyFXParser::LP:
        case AnyFXParser::NOT:
        case AnyFXParser::SUB_OP:
        case AnyFXParser::INTEGERLITERAL:
        case AnyFXParser::FLOATLITERAL:
        case AnyFXParser::DOUBLELITERAL:
        case AnyFXParser::HEX:
        case AnyFXParser::IDENTIFIER: {
          setState(784);
          dynamic_cast<AnnotationContext *>(_localctx)->expressionContext = expression();
           _localctx->annot.AddExpression(dynamic_cast<AnnotationContext *>(_localctx)->expressionContext->tree); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(789);
      match(AnyFXParser::SC);
       _localctx->annot.AddType(dynamic_cast<AnnotationContext *>(_localctx)->typeContext->ty); _localctx->annot.AddName((dynamic_cast<AnnotationContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<AnnotationContext *>(_localctx)->identifierToken->getText() : ""));  
      setState(796);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(797);
    match(AnyFXParser::RR);
     SetupFile(&_localctx->annot, _input); 
   
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

tree::TerminalNode* AnyFXParser::ProgramContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::ProgramContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

tree::TerminalNode* AnyFXParser::ProgramContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

AnyFXParser::AnnotationContext* AnyFXParser::ProgramContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::ProgramRowContext *> AnyFXParser::ProgramContext::programRow() {
  return getRuleContexts<AnyFXParser::ProgramRowContext>();
}

AnyFXParser::ProgramRowContext* AnyFXParser::ProgramContext::programRow(size_t i) {
  return getRuleContext<AnyFXParser::ProgramRowContext>(i);
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
  enterRule(_localctx, 62, AnyFXParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(800);
    match(AnyFXParser::T__68);
    setState(801);
    dynamic_cast<ProgramContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->prog, _input); 
    setState(806);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(803);
      dynamic_cast<ProgramContext *>(_localctx)->annotationContext = annotation();
       _localctx->prog.SetAnnotation(dynamic_cast<ProgramContext *>(_localctx)->annotationContext->annot); 
    }
    setState(808);
    match(AnyFXParser::LB);
     _localctx->prog.SetName((dynamic_cast<ProgramContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->identifierToken->getText() : ""));  
    setState(815);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (AnyFXParser::T__66 - 67))
      | (1ULL << (AnyFXParser::T__67 - 67))
      | (1ULL << (AnyFXParser::IDENTIFIER - 67)))) != 0)) {
      setState(810);
      dynamic_cast<ProgramContext *>(_localctx)->programRowContext = programRow();
       _localctx->prog.ConsumeRow(dynamic_cast<ProgramContext *>(_localctx)->programRowContext->row); 
      setState(817);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(818);
    match(AnyFXParser::RB);
    setState(819);
    match(AnyFXParser::SC);
   
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
  enterRule(_localctx, 64, AnyFXParser::RuleExpression);

  						dynamic_cast<ExpressionContext *>(_localctx)->tree =  nullptr;
  					

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(821);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp7Context::LOGICOR() {
  return getTokens(AnyFXParser::LOGICOR);
}

tree::TerminalNode* AnyFXParser::Binaryexp7Context::LOGICOR(size_t i) {
  return getToken(AnyFXParser::LOGICOR, i);
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
  enterRule(_localctx, 66, AnyFXParser::RuleBinaryexp7);

  						Expression* prev = nullptr;
  						dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  nullptr;
  					
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(824);
    dynamic_cast<Binaryexp7Context *>(_localctx)->e1 = binaryexp6();
     dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  dynamic_cast<Binaryexp7Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
    setState(832);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICOR) {
      setState(826);
      match(AnyFXParser::LOGICOR);
      setState(827);
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

      						SetupFile(lhs, _input);
      						prev = lhs;
      						dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  lhs;
      					
      setState(834);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp6Context::LOGICAND() {
  return getTokens(AnyFXParser::LOGICAND);
}

tree::TerminalNode* AnyFXParser::Binaryexp6Context::LOGICAND(size_t i) {
  return getToken(AnyFXParser::LOGICAND, i);
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
  enterRule(_localctx, 68, AnyFXParser::RuleBinaryexp6);

  						Expression* prev = nullptr;
  						dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  nullptr;
  					
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(835);
    dynamic_cast<Binaryexp6Context *>(_localctx)->e1 = binaryexp5();
     dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  dynamic_cast<Binaryexp6Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
    setState(843);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICAND) {
      setState(837);
      match(AnyFXParser::LOGICAND);
      setState(838);
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

      						SetupFile(lhs, _input);
      						prev = lhs;
      						dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  lhs;
      					
      setState(845);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp5Context::LOGICEQ() {
  return getTokens(AnyFXParser::LOGICEQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp5Context::LOGICEQ(size_t i) {
  return getToken(AnyFXParser::LOGICEQ, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp5Context::NOTEQ() {
  return getTokens(AnyFXParser::NOTEQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp5Context::NOTEQ(size_t i) {
  return getToken(AnyFXParser::NOTEQ, i);
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
  enterRule(_localctx, 70, AnyFXParser::RuleBinaryexp5);

  						Expression* prev = nullptr;
  						dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  nullptr;
  					
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(846);
    dynamic_cast<Binaryexp5Context *>(_localctx)->e1 = binaryexp4();
     dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  dynamic_cast<Binaryexp5Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
    setState(854);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICEQ

    || _la == AnyFXParser::NOTEQ) {
      setState(848);
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
      setState(849);
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

      						SetupFile(lhs, _input);
      						prev = lhs;
      						dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  lhs;
      					
      setState(856);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::LESS() {
  return getTokens(AnyFXParser::LESS);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::LESS(size_t i) {
  return getToken(AnyFXParser::LESS, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::GREATER() {
  return getTokens(AnyFXParser::GREATER);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::GREATER(size_t i) {
  return getToken(AnyFXParser::GREATER, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::LESSEQ() {
  return getTokens(AnyFXParser::LESSEQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::LESSEQ(size_t i) {
  return getToken(AnyFXParser::LESSEQ, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::GREATEREQ() {
  return getTokens(AnyFXParser::GREATEREQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::GREATEREQ(size_t i) {
  return getToken(AnyFXParser::GREATEREQ, i);
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
  enterRule(_localctx, 72, AnyFXParser::RuleBinaryexp4);

  						Expression* prev = nullptr;
  						dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  nullptr;
  					
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(857);
    dynamic_cast<Binaryexp4Context *>(_localctx)->e1 = binaryexp3();
     dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  dynamic_cast<Binaryexp4Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
    setState(865);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 89) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 89)) & ((1ULL << (AnyFXParser::LESS - 89))
      | (1ULL << (AnyFXParser::LESSEQ - 89))
      | (1ULL << (AnyFXParser::GREATER - 89))
      | (1ULL << (AnyFXParser::GREATEREQ - 89)))) != 0)) {
      setState(859);
      dynamic_cast<Binaryexp4Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 89) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 89)) & ((1ULL << (AnyFXParser::LESS - 89))
        | (1ULL << (AnyFXParser::LESSEQ - 89))
        | (1ULL << (AnyFXParser::GREATER - 89))
        | (1ULL << (AnyFXParser::GREATEREQ - 89)))) != 0))) {
        dynamic_cast<Binaryexp4Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(860);
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

      						SetupFile(lhs, _input);
      						prev = lhs;
      						dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  lhs;
      					
      setState(867);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp3Context::ADD_OP() {
  return getTokens(AnyFXParser::ADD_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp3Context::ADD_OP(size_t i) {
  return getToken(AnyFXParser::ADD_OP, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp3Context::SUB_OP() {
  return getTokens(AnyFXParser::SUB_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp3Context::SUB_OP(size_t i) {
  return getToken(AnyFXParser::SUB_OP, i);
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
  enterRule(_localctx, 74, AnyFXParser::RuleBinaryexp3);

  						Expression* prev = nullptr;
  						dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  nullptr;
  					
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(868);
    dynamic_cast<Binaryexp3Context *>(_localctx)->e1 = binaryexp2();
     dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  dynamic_cast<Binaryexp3Context *>(_localctx)->e1->tree; _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
    setState(876);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::ADD_OP

    || _la == AnyFXParser::SUB_OP) {
      setState(870);
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
      setState(871);
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

      						SetupFile(lhs, _input);
      						prev = lhs;
      						dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  lhs;
      					
      setState(878);
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
  enterRule(_localctx, 76, AnyFXParser::RuleBinaryexp2);

  						Expression* prev = nullptr;
  						dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  nullptr;
  					
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(879);
    dynamic_cast<Binaryexp2Context *>(_localctx)->e1 = binaryexp1();
     dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  dynamic_cast<Binaryexp2Context *>(_localctx)->e1->tree; _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
    setState(887);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::DIV_OP

    || _la == AnyFXParser::MUL_OP) {
      setState(881);
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
      setState(882);
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

      						SetupFile(lhs, _input);
      						prev = lhs;
      						dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  lhs;
      					
      setState(889);
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
  enterRule(_localctx, 78, AnyFXParser::RuleBinaryexp1);

  						char operat = 0;
  						dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  nullptr;
  					
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(891);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::NOT

    || _la == AnyFXParser::SUB_OP) {
      setState(890);
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
    setState(893);
    dynamic_cast<Binaryexp1Context *>(_localctx)->e1 = binaryexpatom();

    						Expression* rhs = dynamic_cast<Binaryexp1Context *>(_localctx)->e1->tree;

    						if (dynamic_cast<Binaryexp1Context *>(_localctx)->op != 0)
    						{
    							operat = (dynamic_cast<Binaryexp1Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp1Context *>(_localctx)->op->getText() : "").c_str()[0];
    							rhs = new UnaryExpression(operat, rhs);
    						}

    						SetupFile(rhs, _input);
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
  enterRule(_localctx, 80, AnyFXParser::RuleBinaryexpatom);

  						dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  nullptr;
  					

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(912);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::INTEGERLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(896);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken = match(AnyFXParser::INTEGERLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(atoi((dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        break;
      }

      case AnyFXParser::FLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(898);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken = match(AnyFXParser::FLOATLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        break;
      }

      case AnyFXParser::DOUBLELITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(900);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken = match(AnyFXParser::DOUBLELITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
        break;
      }

      case AnyFXParser::HEX: {
        enterOuterAlt(_localctx, 4);
        setState(902);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken = match(AnyFXParser::HEX);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(strtoul((dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken->getText() : "").c_str(), nullptr, 16)); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
        break;
      }

      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 5);
        setState(904);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new SymbolExpression((dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken->getText() : "")); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
        break;
      }

      case AnyFXParser::T__0:
      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(906);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext = boolean();

        						dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new BoolExpression(dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext->val);
        						SetupFile(_localctx->tree, _input);
        					
        break;
      }

      case AnyFXParser::LP: {
        enterOuterAlt(_localctx, 7);
        setState(909);
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

tree::TerminalNode* AnyFXParser::ParantexpressionContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

AnyFXParser::ExpressionContext* AnyFXParser::ParantexpressionContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::ParantexpressionContext::RP() {
  return getToken(AnyFXParser::RP, 0);
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
  enterRule(_localctx, 82, AnyFXParser::RuleParantexpression);

  						dynamic_cast<ParantexpressionContext *>(_localctx)->tree =  nullptr;
  					

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(914);
    match(AnyFXParser::LP);
    setState(915);
    dynamic_cast<ParantexpressionContext *>(_localctx)->expressionContext = expression();
    setState(916);
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
  "string", "boolean", "preprocess", "entry", "effect", "qualifier", "qualifierValued", 
  "type", "qualifierExpression", "structure", "varblock", "varbuffer", "subroutine", 
  "valueList", "valueSingleList", "variable", "constant", "parameterAttribute", 
  "parameter", "parameterList", "functionAttribute", "codeBlock", "function", 
  "blendStateRow", "renderStateRow", "renderState", "sampler", "samplerTextureList", 
  "samplerRow", "programRow", "annotation", "program", "expression", "binaryexp7", 
  "binaryexp6", "binaryexp5", "binaryexp4", "binaryexp3", "binaryexp2", 
  "binaryexp1", "binaryexpatom", "parantexpression"
};

std::vector<std::string> AnyFXParser::_literalNames = {
  "", "'true'", "'false'", "'#line'", "'const'", "'shared'", "'push'", "'flat'", 
  "'noperspective'", "'patch'", "'in'", "'out'", "'inout'", "'groupshared'", 
  "'rgba32f'", "'rgba16f'", "'rg32f'", "'rg16f'", "'r11g11b10f'", "'r32f'", 
  "'r16f'", "'rgba16'", "'rgba8'", "'rgb10a2'", "'rg16'", "'rg8'", "'r16'", 
  "'r8'", "'rgba16snorm'", "'rgba8snorm'", "'rg16snorm'", "'rg8snorm'", 
  "'r16snorm'", "'r8snorm'", "'rgba32i'", "'rgba16i'", "'rgba8i'", "'rg32i'", 
  "'rg16i'", "'rg8i'", "'r32i'", "'r16i'", "'r8i'", "'rgba32ui'", "'rgba16ui'", 
  "'rgba8ui'", "'rg32ui'", "'rg16ui'", "'rg8ui'", "'r32ui'", "'r16ui'", 
  "'r8ui'", "'read'", "'write'", "'readwrite'", "'group'", "'index'", "'struct'", 
  "'varblock'", "'varbuffer'", "'prototype'", "'subroutine'", "'feedback'", 
  "'slot'", "'shader'", "'state'", "'samplerstate'", "'RenderState'", "'CompileFlags'", 
  "'program'", "';'", "','", "':'", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "'.'", "'!'", "'='", "'\"'", "'?'", "'&'", "'|'", "'''", "'#'", "'\\'", 
  "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", "'%'", "'_'", 
  "'+'", "'-'", "'/'", "'*'"
};

std::vector<std::string> AnyFXParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "SC", 
  "CO", "COL", "LP", "RP", "LB", "RB", "LL", "RR", "DOT", "NOT", "EQ", "QO", 
  "QU", "AND", "OR", "Q", "NU", "FORWARDSLASH", "LESS", "LESSEQ", "GREATER", 
  "GREATEREQ", "LOGICEQ", "NOTEQ", "LOGICAND", "LOGICOR", "MOD", "UNDERSC", 
  "ADD_OP", "SUB_OP", "DIV_OP", "MUL_OP", "INTEGERLITERAL", "COMMENT", "ML_COMMENT", 
  "FLOATLITERAL", "EXPONENT", "DOUBLELITERAL", "HEX", "IDENTIFIER", "WS"
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
    0x3, 0x71, 0x39a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x5a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x5d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x63, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x66, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x69, 
    0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x6f, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x78, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x7b, 0xb, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0xa1, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xa4, 0xb, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xb9, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xbc, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
    0xc, 0xc8, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xcb, 0xb, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd3, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xd9, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0xdc, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xe7, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0xea, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xf2, 0xa, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xf8, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0xfb, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0x112, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x11a, 0xa, 0xf, 0xc, 0xf, 0xe, 
    0xf, 0x11d, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x128, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x12b, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x141, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x144, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 
    0x11, 0x168, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x16b, 0xb, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0x187, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x18c, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x1b2, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x1b5, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x1d6, 0xa, 0x12, 0xc, 0x12, 
    0xe, 0x12, 0x1d9, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1e9, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x1f4, 0xa, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x201, 0xa, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0x20a, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x7, 0x14, 0x20f, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x212, 0xb, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0x21b, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 
    0x21f, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x7, 0x15, 0x227, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x22a, 
    0xb, 0x15, 0x5, 0x15, 0x22c, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x5, 0x16, 0x23f, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 
    0x243, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x246, 0xb, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x24a, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x7, 0x18, 0x24f, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x252, 0xb, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x256, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x275, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x282, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x7, 0x1b, 0x294, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x297, 
    0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x29b, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x2a3, 
    0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x2a6, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x2b3, 0xa, 0x1c, 0xc, 0x1c, 
    0xe, 0x1c, 0x2b6, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x2c0, 0xa, 0x1c, 
    0xc, 0x1c, 0xe, 0x1c, 0x2c3, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 
    0x2c7, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x7, 0x1d, 0x2ce, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x2d1, 0xb, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
    0x1e, 0x2e6, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x2f0, 0xa, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x2f7, 
    0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x2fa, 0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
    0x30a, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x316, 
    0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x31b, 0xa, 0x20, 
    0xc, 0x20, 0xe, 0x20, 0x31e, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 
    0x21, 0x329, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x7, 0x21, 0x330, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x333, 
    0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x7, 0x23, 0x341, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x344, 0xb, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 
    0x24, 0x34c, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x34f, 0xb, 0x24, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 
    0x357, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x35a, 0xb, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x362, 
    0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x365, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x36d, 0xa, 0x27, 
    0xc, 0x27, 0xe, 0x27, 0x370, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x378, 0xa, 0x28, 0xc, 0x28, 
    0xe, 0x28, 0x37b, 0xb, 0x28, 0x3, 0x29, 0x5, 0x29, 0x37e, 0xa, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 
    0x2a, 0x393, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x4, 0x79, 0xa2, 0x2, 0x2c, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x2, 0xc, 0x3, 0x2, 0x54, 0x54, 0x3, 0x2, 0x58, 0x58, 0x3, 
    0x2, 0x6, 0x38, 0x3, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x4d, 0x4e, 0x3, 0x2, 
    0x5f, 0x60, 0x3, 0x2, 0x5b, 0x5e, 0x3, 0x2, 0x65, 0x66, 0x3, 0x2, 0x67, 
    0x68, 0x4, 0x2, 0x52, 0x52, 0x66, 0x66, 0x2, 0x3cf, 0x2, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x7e, 0x3, 0x2, 0x2, 0x2, 0xa, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x10, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xac, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x18, 0xe8, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x111, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x1f3, 0x3, 0x2, 0x2, 0x2, 0x28, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x23e, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x249, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x250, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x274, 0x3, 0x2, 0x2, 0x2, 0x32, 0x281, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x36, 0x2c6, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x2e5, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x309, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x322, 0x3, 0x2, 0x2, 0x2, 0x42, 0x337, 0x3, 0x2, 0x2, 0x2, 0x44, 0x33a, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x345, 0x3, 0x2, 0x2, 0x2, 0x48, 0x350, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x366, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x371, 0x3, 0x2, 0x2, 0x2, 0x50, 0x37d, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x392, 0x3, 0x2, 0x2, 0x2, 0x54, 0x394, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x5b, 0x7, 0x54, 0x2, 0x2, 0x57, 0x58, 0xa, 0x2, 0x2, 0x2, 0x58, 
    0x5a, 0x8, 0x2, 0x1, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x69, 0x7, 0x54, 0x2, 0x2, 0x5f, 0x64, 0x7, 0x58, 0x2, 
    0x2, 0x60, 0x61, 0xa, 0x3, 0x2, 0x2, 0x61, 0x63, 0x8, 0x2, 0x1, 0x2, 
    0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x69, 0x7, 
    0x58, 0x2, 0x2, 0x68, 0x56, 0x3, 0x2, 0x2, 0x2, 0x68, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x3, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x3, 0x2, 
    0x2, 0x6b, 0x6f, 0x8, 0x3, 0x1, 0x2, 0x6c, 0x6d, 0x7, 0x4, 0x2, 0x2, 
    0x6d, 0x6f, 0x8, 0x3, 0x1, 0x2, 0x6e, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 
    0x8, 0x4, 0x1, 0x2, 0x71, 0x72, 0x7, 0x5, 0x2, 0x2, 0x72, 0x73, 0x7, 
    0x69, 0x2, 0x2, 0x73, 0x74, 0x5, 0x2, 0x2, 0x2, 0x74, 0x75, 0x8, 0x4, 
    0x1, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 0xb, 0x2, 0x2, 
    0x2, 0x77, 0x70, 0x3, 0x2, 0x2, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x2, 0x2, 0x3, 0x7d, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0xa, 0x6, 0x2, 0x7f, 0x80, 0x8, 0x5, 
    0x1, 0x2, 0x80, 0x81, 0x7, 0x2, 0x2, 0x3, 0x81, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x83, 0x5, 0x22, 0x12, 0x2, 0x83, 0x84, 0x8, 0x6, 0x1, 0x2, 
    0x84, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x5, 0x20, 0x11, 0x2, 0x86, 
    0x87, 0x8, 0x6, 0x1, 0x2, 0x87, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 
    0x5, 0x34, 0x1b, 0x2, 0x89, 0x8a, 0x8, 0x6, 0x1, 0x2, 0x8a, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x2e, 0x18, 0x2, 0x8c, 0x8d, 0x8, 0x6, 
    0x1, 0x2, 0x8d, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x40, 0x21, 
    0x2, 0x8f, 0x90, 0x8, 0x6, 0x1, 0x2, 0x90, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x92, 0x5, 0x14, 0xb, 0x2, 0x92, 0x93, 0x8, 0x6, 0x1, 0x2, 0x93, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 0x16, 0xc, 0x2, 0x95, 0x96, 
    0x8, 0x6, 0x1, 0x2, 0x96, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x5, 
    0x18, 0xd, 0x2, 0x98, 0x99, 0x8, 0x6, 0x1, 0x2, 0x99, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x9b, 0x5, 0x1a, 0xe, 0x2, 0x9b, 0x9c, 0x8, 0x6, 0x1, 
    0x2, 0x9c, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x36, 0x1c, 0x2, 
    0x9e, 0x9f, 0x8, 0x6, 0x1, 0x2, 0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x85, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0x8b, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x91, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 
    0x9, 0x4, 0x2, 0x2, 0xa6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x9, 
    0x5, 0x2, 0x2, 0xa8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x70, 
    0x2, 0x2, 0xaa, 0xab, 0x8, 0x9, 0x1, 0x2, 0xab, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xad, 0x5, 0xe, 0x8, 0x2, 0xad, 0xae, 0x5, 0x54, 0x2b, 0x2, 
    0xae, 0xaf, 0x8, 0xa, 0x1, 0x2, 0xaf, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xb1, 0x7, 0x3b, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x70, 0x2, 0x2, 0xb2, 0xb3, 
    0x8, 0xb, 0x1, 0x2, 0xb3, 0xba, 0x7, 0x4d, 0x2, 0x2, 0xb4, 0xb5, 0x5, 
    0x26, 0x14, 0x2, 0xb5, 0xb6, 0x7, 0x48, 0x2, 0x2, 0xb6, 0xb7, 0x8, 0xb, 
    0x1, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb4, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x4e, 0x2, 0x2, 0xbe, 0xbf, 
    0x7, 0x48, 0x2, 0x2, 0xbf, 0xc0, 0x8, 0xb, 0x1, 0x2, 0xc0, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0xc, 0x7, 0x2, 0xc2, 0xc3, 0x8, 0xc, 
    0x1, 0x2, 0xc3, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x12, 0xa, 
    0x2, 0xc5, 0xc6, 0x8, 0xc, 0x1, 0x2, 0xc6, 0xc8, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x3c, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x70, 
    0x2, 0x2, 0xce, 0xd2, 0x8, 0xc, 0x1, 0x2, 0xcf, 0xd0, 0x5, 0x3e, 0x20, 
    0x2, 0xd0, 0xd1, 0x8, 0xc, 0x1, 0x2, 0xd1, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xda, 0x7, 0x4d, 0x2, 0x2, 0xd5, 0xd6, 
    0x5, 0x20, 0x11, 0x2, 0xd6, 0xd7, 0x8, 0xc, 0x1, 0x2, 0xd7, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x7, 0x4e, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x48, 0x2, 0x2, 0xdf, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0xc, 0x7, 0x2, 0xe1, 0xe2, 
    0x8, 0xd, 0x1, 0x2, 0xe2, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x5, 
    0x12, 0xa, 0x2, 0xe4, 0xe5, 0x8, 0xd, 0x1, 0x2, 0xe5, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x3d, 0x2, 0x2, 0xec, 0xed, 
    0x7, 0x70, 0x2, 0x2, 0xed, 0xf1, 0x8, 0xd, 0x1, 0x2, 0xee, 0xef, 0x5, 
    0x3e, 0x20, 0x2, 0xef, 0xf0, 0x8, 0xd, 0x1, 0x2, 0xf0, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf9, 0x7, 0x4d, 0x2, 0x2, 
    0xf4, 0xf5, 0x5, 0x20, 0x11, 0x2, 0xf5, 0xf6, 0x8, 0xd, 0x1, 0x2, 0xf6, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xfd, 0x7, 0x4e, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x48, 0x2, 
    0x2, 0xfe, 0x19, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x3e, 0x2, 0x2, 
    0x100, 0x101, 0x5, 0x10, 0x9, 0x2, 0x101, 0x102, 0x7, 0x70, 0x2, 0x2, 
    0x102, 0x103, 0x8, 0xe, 0x1, 0x2, 0x103, 0x104, 0x7, 0x4b, 0x2, 0x2, 
    0x104, 0x105, 0x5, 0x28, 0x15, 0x2, 0x105, 0x106, 0x7, 0x4c, 0x2, 0x2, 
    0x106, 0x107, 0x7, 0x48, 0x2, 0x2, 0x107, 0x108, 0x8, 0xe, 0x1, 0x2, 
    0x108, 0x112, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x3f, 0x2, 0x2, 
    0x10a, 0x10b, 0x7, 0x4b, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x70, 0x2, 0x2, 
    0x10c, 0x10d, 0x7, 0x4c, 0x2, 0x2, 0x10d, 0x10e, 0x8, 0xe, 0x1, 0x2, 
    0x10e, 0x10f, 0x5, 0x2e, 0x18, 0x2, 0x10f, 0x110, 0x8, 0xe, 0x1, 0x2, 
    0x110, 0x112, 0x3, 0x2, 0x2, 0x2, 0x111, 0xff, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x109, 0x3, 0x2, 0x2, 0x2, 0x112, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 
    0x5, 0x42, 0x22, 0x2, 0x114, 0x11b, 0x8, 0xf, 0x1, 0x2, 0x115, 0x116, 
    0x7, 0x49, 0x2, 0x2, 0x116, 0x117, 0x5, 0x42, 0x22, 0x2, 0x117, 0x118, 
    0x8, 0xf, 0x1, 0x2, 0x118, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x119, 0x115, 
    0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x5, 
    0x42, 0x22, 0x2, 0x11f, 0x120, 0x8, 0x10, 0x1, 0x2, 0x120, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x122, 0x5, 0xc, 0x7, 0x2, 0x122, 0x123, 0x8, 
    0x11, 0x1, 0x2, 0x123, 0x128, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x5, 
    0x12, 0xa, 0x2, 0x125, 0x126, 0x8, 0x11, 0x1, 0x2, 0x126, 0x128, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x121, 0x3, 0x2, 0x2, 0x2, 0x127, 0x124, 0x3, 
    0x2, 0x2, 0x2, 0x128, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x5, 
    0x10, 0x9, 0x2, 0x12d, 0x12e, 0x7, 0x70, 0x2, 0x2, 0x12e, 0x186, 0x8, 
    0x11, 0x1, 0x2, 0x12f, 0x130, 0x7, 0x4f, 0x2, 0x2, 0x130, 0x131, 0x7, 
    0x50, 0x2, 0x2, 0x131, 0x132, 0x7, 0x53, 0x2, 0x2, 0x132, 0x133, 0x8, 
    0x11, 0x1, 0x2, 0x133, 0x134, 0x7, 0x4d, 0x2, 0x2, 0x134, 0x135, 0x5, 
    0x10, 0x9, 0x2, 0x135, 0x136, 0x7, 0x4b, 0x2, 0x2, 0x136, 0x137, 0x5, 
    0x1c, 0xf, 0x2, 0x137, 0x138, 0x7, 0x4c, 0x2, 0x2, 0x138, 0x142, 0x8, 
    0x11, 0x1, 0x2, 0x139, 0x13a, 0x7, 0x49, 0x2, 0x2, 0x13a, 0x13b, 0x5, 
    0x10, 0x9, 0x2, 0x13b, 0x13c, 0x7, 0x4b, 0x2, 0x2, 0x13c, 0x13d, 0x5, 
    0x1c, 0xf, 0x2, 0x13d, 0x13e, 0x7, 0x4c, 0x2, 0x2, 0x13e, 0x13f, 0x8, 
    0x11, 0x1, 0x2, 0x13f, 0x141, 0x3, 0x2, 0x2, 0x2, 0x140, 0x139, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x144, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x145, 0x3, 
    0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x7, 
    0x4e, 0x2, 0x2, 0x146, 0x187, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x7, 
    0x4f, 0x2, 0x2, 0x148, 0x149, 0x7, 0x50, 0x2, 0x2, 0x149, 0x14a, 0x7, 
    0x53, 0x2, 0x2, 0x14a, 0x14b, 0x8, 0x11, 0x1, 0x2, 0x14b, 0x14c, 0x7, 
    0x4d, 0x2, 0x2, 0x14c, 0x14d, 0x5, 0x1c, 0xf, 0x2, 0x14d, 0x14e, 0x7, 
    0x4e, 0x2, 0x2, 0x14e, 0x14f, 0x8, 0x11, 0x1, 0x2, 0x14f, 0x187, 0x3, 
    0x2, 0x2, 0x2, 0x150, 0x151, 0x7, 0x4f, 0x2, 0x2, 0x151, 0x152, 0x5, 
    0x42, 0x22, 0x2, 0x152, 0x153, 0x7, 0x50, 0x2, 0x2, 0x153, 0x154, 0x8, 
    0x11, 0x1, 0x2, 0x154, 0x187, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x7, 
    0x4f, 0x2, 0x2, 0x156, 0x157, 0x5, 0x42, 0x22, 0x2, 0x157, 0x158, 0x7, 
    0x50, 0x2, 0x2, 0x158, 0x159, 0x8, 0x11, 0x1, 0x2, 0x159, 0x15a, 0x7, 
    0x53, 0x2, 0x2, 0x15a, 0x15b, 0x7, 0x4d, 0x2, 0x2, 0x15b, 0x15c, 0x5, 
    0x10, 0x9, 0x2, 0x15c, 0x15d, 0x7, 0x4b, 0x2, 0x2, 0x15d, 0x15e, 0x5, 
    0x1c, 0xf, 0x2, 0x15e, 0x15f, 0x7, 0x4c, 0x2, 0x2, 0x15f, 0x169, 0x8, 
    0x11, 0x1, 0x2, 0x160, 0x161, 0x7, 0x49, 0x2, 0x2, 0x161, 0x162, 0x5, 
    0x10, 0x9, 0x2, 0x162, 0x163, 0x7, 0x4b, 0x2, 0x2, 0x163, 0x164, 0x5, 
    0x1c, 0xf, 0x2, 0x164, 0x165, 0x7, 0x4c, 0x2, 0x2, 0x165, 0x166, 0x8, 
    0x11, 0x1, 0x2, 0x166, 0x168, 0x3, 0x2, 0x2, 0x2, 0x167, 0x160, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 
    0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16c, 0x3, 
    0x2, 0x2, 0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x7, 
    0x4e, 0x2, 0x2, 0x16d, 0x187, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x7, 
    0x4f, 0x2, 0x2, 0x16f, 0x170, 0x5, 0x42, 0x22, 0x2, 0x170, 0x171, 0x7, 
    0x50, 0x2, 0x2, 0x171, 0x172, 0x8, 0x11, 0x1, 0x2, 0x172, 0x173, 0x7, 
    0x53, 0x2, 0x2, 0x173, 0x174, 0x7, 0x4d, 0x2, 0x2, 0x174, 0x175, 0x5, 
    0x1c, 0xf, 0x2, 0x175, 0x176, 0x7, 0x4e, 0x2, 0x2, 0x176, 0x177, 0x8, 
    0x11, 0x1, 0x2, 0x177, 0x187, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x7, 
    0x4f, 0x2, 0x2, 0x179, 0x17a, 0x7, 0x50, 0x2, 0x2, 0x17a, 0x187, 0x8, 
    0x11, 0x1, 0x2, 0x17b, 0x17c, 0x7, 0x53, 0x2, 0x2, 0x17c, 0x17d, 0x5, 
    0x10, 0x9, 0x2, 0x17d, 0x17e, 0x7, 0x4b, 0x2, 0x2, 0x17e, 0x17f, 0x5, 
    0x1c, 0xf, 0x2, 0x17f, 0x180, 0x7, 0x4c, 0x2, 0x2, 0x180, 0x181, 0x8, 
    0x11, 0x1, 0x2, 0x181, 0x187, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x7, 
    0x53, 0x2, 0x2, 0x183, 0x184, 0x5, 0x1e, 0x10, 0x2, 0x184, 0x185, 0x8, 
    0x11, 0x1, 0x2, 0x185, 0x187, 0x3, 0x2, 0x2, 0x2, 0x186, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x186, 0x147, 0x3, 0x2, 0x2, 0x2, 0x186, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x186, 0x155, 0x3, 0x2, 0x2, 0x2, 0x186, 0x16e, 0x3, 
    0x2, 0x2, 0x2, 0x186, 0x178, 0x3, 0x2, 0x2, 0x2, 0x186, 0x17b, 0x3, 
    0x2, 0x2, 0x2, 0x186, 0x182, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x3, 
    0x2, 0x2, 0x2, 0x187, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x5, 
    0x3e, 0x20, 0x2, 0x189, 0x18a, 0x8, 0x11, 0x1, 0x2, 0x18a, 0x18c, 0x3, 
    0x2, 0x2, 0x2, 0x18b, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x3, 
    0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x7, 
    0x48, 0x2, 0x2, 0x18e, 0x21, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 
    0x6, 0x2, 0x2, 0x190, 0x191, 0x5, 0x10, 0x9, 0x2, 0x191, 0x192, 0x7, 
    0x70, 0x2, 0x2, 0x192, 0x1e8, 0x8, 0x12, 0x1, 0x2, 0x193, 0x194, 0x7, 
    0x53, 0x2, 0x2, 0x194, 0x195, 0x5, 0x10, 0x9, 0x2, 0x195, 0x196, 0x7, 
    0x4b, 0x2, 0x2, 0x196, 0x197, 0x5, 0x1c, 0xf, 0x2, 0x197, 0x198, 0x7, 
    0x4c, 0x2, 0x2, 0x198, 0x199, 0x7, 0x48, 0x2, 0x2, 0x199, 0x19a, 0x8, 
    0x12, 0x1, 0x2, 0x19a, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 
    0x53, 0x2, 0x2, 0x19c, 0x19d, 0x5, 0x1e, 0x10, 0x2, 0x19d, 0x19e, 0x7, 
    0x48, 0x2, 0x2, 0x19e, 0x19f, 0x8, 0x12, 0x1, 0x2, 0x19f, 0x1e9, 0x3, 
    0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0x4f, 0x2, 0x2, 0x1a1, 0x1a2, 0x7, 
    0x50, 0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x53, 0x2, 0x2, 0x1a3, 0x1a4, 0x8, 
    0x12, 0x1, 0x2, 0x1a4, 0x1a5, 0x7, 0x4d, 0x2, 0x2, 0x1a5, 0x1a6, 0x5, 
    0x10, 0x9, 0x2, 0x1a6, 0x1a7, 0x7, 0x4b, 0x2, 0x2, 0x1a7, 0x1a8, 0x5, 
    0x1c, 0xf, 0x2, 0x1a8, 0x1a9, 0x7, 0x4c, 0x2, 0x2, 0x1a9, 0x1b3, 0x8, 
    0x12, 0x1, 0x2, 0x1aa, 0x1ab, 0x7, 0x49, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 
    0x10, 0x9, 0x2, 0x1ac, 0x1ad, 0x7, 0x4b, 0x2, 0x2, 0x1ad, 0x1ae, 0x5, 
    0x1c, 0xf, 0x2, 0x1ae, 0x1af, 0x7, 0x4c, 0x2, 0x2, 0x1af, 0x1b0, 0x8, 
    0x12, 0x1, 0x2, 0x1b0, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1aa, 0x3, 
    0x2, 0x2, 0x2, 0x1b2, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b6, 0x3, 
    0x2, 0x2, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x7, 
    0x4e, 0x2, 0x2, 0x1b7, 0x1b8, 0x7, 0x48, 0x2, 0x2, 0x1b8, 0x1e9, 0x3, 
    0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x4f, 0x2, 0x2, 0x1ba, 0x1bb, 0x7, 
    0x50, 0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x53, 0x2, 0x2, 0x1bc, 0x1bd, 0x8, 
    0x12, 0x1, 0x2, 0x1bd, 0x1be, 0x7, 0x4d, 0x2, 0x2, 0x1be, 0x1bf, 0x5, 
    0x1c, 0xf, 0x2, 0x1bf, 0x1c0, 0x7, 0x4e, 0x2, 0x2, 0x1c0, 0x1c1, 0x8, 
    0x12, 0x1, 0x2, 0x1c1, 0x1c2, 0x7, 0x48, 0x2, 0x2, 0x1c2, 0x1e9, 0x3, 
    0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x7, 0x4f, 0x2, 0x2, 0x1c4, 0x1c5, 0x5, 
    0x42, 0x22, 0x2, 0x1c5, 0x1c6, 0x7, 0x50, 0x2, 0x2, 0x1c6, 0x1c7, 0x8, 
    0x12, 0x1, 0x2, 0x1c7, 0x1c8, 0x7, 0x53, 0x2, 0x2, 0x1c8, 0x1c9, 0x7, 
    0x4d, 0x2, 0x2, 0x1c9, 0x1ca, 0x5, 0x10, 0x9, 0x2, 0x1ca, 0x1cb, 0x7, 
    0x4b, 0x2, 0x2, 0x1cb, 0x1cc, 0x5, 0x1c, 0xf, 0x2, 0x1cc, 0x1cd, 0x7, 
    0x4c, 0x2, 0x2, 0x1cd, 0x1d7, 0x8, 0x12, 0x1, 0x2, 0x1ce, 0x1cf, 0x7, 
    0x49, 0x2, 0x2, 0x1cf, 0x1d0, 0x5, 0x10, 0x9, 0x2, 0x1d0, 0x1d1, 0x7, 
    0x4b, 0x2, 0x2, 0x1d1, 0x1d2, 0x5, 0x1c, 0xf, 0x2, 0x1d2, 0x1d3, 0x7, 
    0x4c, 0x2, 0x2, 0x1d3, 0x1d4, 0x8, 0x12, 0x1, 0x2, 0x1d4, 0x1d6, 0x3, 
    0x2, 0x2, 0x2, 0x1d5, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d9, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x3, 
    0x2, 0x2, 0x2, 0x1d8, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1d7, 0x3, 
    0x2, 0x2, 0x2, 0x1da, 0x1db, 0x7, 0x4e, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 
    0x48, 0x2, 0x2, 0x1dc, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x7, 
    0x4f, 0x2, 0x2, 0x1de, 0x1df, 0x5, 0x42, 0x22, 0x2, 0x1df, 0x1e0, 0x7, 
    0x50, 0x2, 0x2, 0x1e0, 0x1e1, 0x8, 0x12, 0x1, 0x2, 0x1e1, 0x1e2, 0x7, 
    0x53, 0x2, 0x2, 0x1e2, 0x1e3, 0x7, 0x4d, 0x2, 0x2, 0x1e3, 0x1e4, 0x5, 
    0x1c, 0xf, 0x2, 0x1e4, 0x1e5, 0x7, 0x4e, 0x2, 0x2, 0x1e5, 0x1e6, 0x8, 
    0x12, 0x1, 0x2, 0x1e6, 0x1e7, 0x7, 0x48, 0x2, 0x2, 0x1e7, 0x1e9, 0x3, 
    0x2, 0x2, 0x2, 0x1e8, 0x193, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x19b, 0x3, 
    0x2, 0x2, 0x2, 0x1e8, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1b9, 0x3, 
    0x2, 0x2, 0x2, 0x1e8, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1dd, 0x3, 
    0x2, 0x2, 0x2, 0x1e9, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x7, 0x4f, 
    0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x70, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0x50, 
    0x2, 0x2, 0x1ed, 0x1ee, 0x8, 0x13, 0x1, 0x2, 0x1ee, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x1ef, 0x1f0, 0x7, 0x4f, 0x2, 0x2, 0x1f0, 0x1f1, 0x7, 0x70, 
    0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x50, 0x2, 0x2, 0x1f2, 0x1f4, 0x8, 0x14, 
    0x1, 0x2, 0x1f3, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x3, 0x2, 
    0x2, 0x2, 0x1f4, 0x200, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x7, 0x4f, 
    0x2, 0x2, 0x1f6, 0x1f7, 0x7, 0x40, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x53, 
    0x2, 0x2, 0x1f8, 0x1f9, 0x7, 0x4b, 0x2, 0x2, 0x1f9, 0x1fa, 0x5, 0x42, 
    0x22, 0x2, 0x1fa, 0x1fb, 0x7, 0x49, 0x2, 0x2, 0x1fb, 0x1fc, 0x5, 0x42, 
    0x22, 0x2, 0x1fc, 0x1fd, 0x7, 0x4c, 0x2, 0x2, 0x1fd, 0x1fe, 0x7, 0x50, 
    0x2, 0x2, 0x1fe, 0x1ff, 0x8, 0x14, 0x1, 0x2, 0x1ff, 0x201, 0x3, 0x2, 
    0x2, 0x2, 0x200, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 
    0x2, 0x2, 0x201, 0x209, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x7, 0x4f, 
    0x2, 0x2, 0x203, 0x204, 0x7, 0x41, 0x2, 0x2, 0x204, 0x205, 0x7, 0x53, 
    0x2, 0x2, 0x205, 0x206, 0x5, 0x42, 0x22, 0x2, 0x206, 0x207, 0x7, 0x50, 
    0x2, 0x2, 0x207, 0x208, 0x8, 0x14, 0x1, 0x2, 0x208, 0x20a, 0x3, 0x2, 
    0x2, 0x2, 0x209, 0x202, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 
    0x2, 0x2, 0x20a, 0x210, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 0x5, 0xc, 
    0x7, 0x2, 0x20c, 0x20d, 0x8, 0x14, 0x1, 0x2, 0x20d, 0x20f, 0x3, 0x2, 
    0x2, 0x2, 0x20e, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x212, 0x3, 0x2, 
    0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x3, 0x2, 
    0x2, 0x2, 0x211, 0x213, 0x3, 0x2, 0x2, 0x2, 0x212, 0x210, 0x3, 0x2, 
    0x2, 0x2, 0x213, 0x214, 0x5, 0x10, 0x9, 0x2, 0x214, 0x215, 0x7, 0x70, 
    0x2, 0x2, 0x215, 0x21e, 0x8, 0x14, 0x1, 0x2, 0x216, 0x21a, 0x7, 0x4f, 
    0x2, 0x2, 0x217, 0x218, 0x5, 0x42, 0x22, 0x2, 0x218, 0x219, 0x8, 0x14, 
    0x1, 0x2, 0x219, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x217, 0x3, 0x2, 
    0x2, 0x2, 0x21a, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 0x2, 
    0x2, 0x2, 0x21c, 0x21d, 0x7, 0x50, 0x2, 0x2, 0x21d, 0x21f, 0x8, 0x14, 
    0x1, 0x2, 0x21e, 0x216, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x3, 0x2, 
    0x2, 0x2, 0x21f, 0x27, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x5, 0x26, 
    0x14, 0x2, 0x221, 0x228, 0x8, 0x15, 0x1, 0x2, 0x222, 0x223, 0x7, 0x49, 
    0x2, 0x2, 0x223, 0x224, 0x5, 0x26, 0x14, 0x2, 0x224, 0x225, 0x8, 0x15, 
    0x1, 0x2, 0x225, 0x227, 0x3, 0x2, 0x2, 0x2, 0x226, 0x222, 0x3, 0x2, 
    0x2, 0x2, 0x227, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x228, 0x226, 0x3, 0x2, 
    0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22c, 0x3, 0x2, 
    0x2, 0x2, 0x22a, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x220, 0x3, 0x2, 
    0x2, 0x2, 0x22b, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x22d, 0x22e, 0x7, 0x4f, 0x2, 0x2, 0x22e, 0x22f, 0x7, 0x70, 0x2, 
    0x2, 0x22f, 0x230, 0x7, 0x50, 0x2, 0x2, 0x230, 0x231, 0x7, 0x53, 0x2, 
    0x2, 0x231, 0x232, 0x5, 0x42, 0x22, 0x2, 0x232, 0x233, 0x8, 0x16, 0x1, 
    0x2, 0x233, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x7, 0x4f, 0x2, 
    0x2, 0x235, 0x236, 0x7, 0x70, 0x2, 0x2, 0x236, 0x237, 0x7, 0x50, 0x2, 
    0x2, 0x237, 0x238, 0x7, 0x53, 0x2, 0x2, 0x238, 0x239, 0x7, 0x70, 0x2, 
    0x2, 0x239, 0x23f, 0x8, 0x16, 0x1, 0x2, 0x23a, 0x23b, 0x7, 0x4f, 0x2, 
    0x2, 0x23b, 0x23c, 0x7, 0x70, 0x2, 0x2, 0x23c, 0x23d, 0x7, 0x50, 0x2, 
    0x2, 0x23d, 0x23f, 0x8, 0x16, 0x1, 0x2, 0x23e, 0x22d, 0x3, 0x2, 0x2, 
    0x2, 0x23e, 0x234, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23a, 0x3, 0x2, 0x2, 
    0x2, 0x23f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x240, 0x244, 0x7, 0x4d, 0x2, 
    0x2, 0x241, 0x243, 0x5, 0x2c, 0x17, 0x2, 0x242, 0x241, 0x3, 0x2, 0x2, 
    0x2, 0x243, 0x246, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 
    0x2, 0x244, 0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x247, 0x3, 0x2, 0x2, 
    0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x247, 0x24a, 0x7, 0x4e, 0x2, 
    0x2, 0x248, 0x24a, 0xa, 0x6, 0x2, 0x2, 0x249, 0x240, 0x3, 0x2, 0x2, 
    0x2, 0x249, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x24b, 0x24c, 0x5, 0x2a, 0x16, 0x2, 0x24c, 0x24d, 0x8, 0x18, 0x1, 0x2, 
    0x24d, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24b, 0x3, 0x2, 0x2, 0x2, 
    0x24f, 0x252, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 0x2, 0x2, 0x2, 
    0x250, 0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 0x255, 0x3, 0x2, 0x2, 0x2, 
    0x252, 0x250, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 0x42, 0x2, 0x2, 
    0x254, 0x256, 0x8, 0x18, 0x1, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 
    0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x258, 0x5, 0x10, 0x9, 0x2, 0x258, 0x259, 0x7, 0x70, 0x2, 0x2, 
    0x259, 0x25a, 0x8, 0x18, 0x1, 0x2, 0x25a, 0x25b, 0x7, 0x4b, 0x2, 0x2, 
    0x25b, 0x25c, 0x5, 0x28, 0x15, 0x2, 0x25c, 0x25d, 0x7, 0x4c, 0x2, 0x2, 
    0x25d, 0x25e, 0x8, 0x18, 0x1, 0x2, 0x25e, 0x25f, 0x5, 0x2c, 0x17, 0x2, 
    0x25f, 0x260, 0x8, 0x18, 0x1, 0x2, 0x260, 0x261, 0x8, 0x18, 0x1, 0x2, 
    0x261, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x7, 0x70, 0x2, 0x2, 
    0x263, 0x264, 0x7, 0x4f, 0x2, 0x2, 0x264, 0x265, 0x5, 0x42, 0x22, 0x2, 
    0x265, 0x266, 0x7, 0x50, 0x2, 0x2, 0x266, 0x267, 0x7, 0x53, 0x2, 0x2, 
    0x267, 0x268, 0x7, 0x70, 0x2, 0x2, 0x268, 0x269, 0x7, 0x48, 0x2, 0x2, 
    0x269, 0x26a, 0x8, 0x19, 0x1, 0x2, 0x26a, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x26c, 0x7, 0x70, 0x2, 0x2, 0x26c, 0x26d, 0x7, 0x4f, 0x2, 0x2, 
    0x26d, 0x26e, 0x5, 0x42, 0x22, 0x2, 0x26e, 0x26f, 0x7, 0x50, 0x2, 0x2, 
    0x26f, 0x270, 0x7, 0x53, 0x2, 0x2, 0x270, 0x271, 0x5, 0x42, 0x22, 0x2, 
    0x271, 0x272, 0x7, 0x48, 0x2, 0x2, 0x272, 0x273, 0x8, 0x19, 0x1, 0x2, 
    0x273, 0x275, 0x3, 0x2, 0x2, 0x2, 0x274, 0x262, 0x3, 0x2, 0x2, 0x2, 
    0x274, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x275, 0x31, 0x3, 0x2, 0x2, 0x2, 0x276, 
    0x277, 0x7, 0x70, 0x2, 0x2, 0x277, 0x278, 0x7, 0x53, 0x2, 0x2, 0x278, 
    0x279, 0x5, 0x42, 0x22, 0x2, 0x279, 0x27a, 0x7, 0x48, 0x2, 0x2, 0x27a, 
    0x27b, 0x8, 0x1a, 0x1, 0x2, 0x27b, 0x282, 0x3, 0x2, 0x2, 0x2, 0x27c, 
    0x27d, 0x7, 0x70, 0x2, 0x2, 0x27d, 0x27e, 0x7, 0x53, 0x2, 0x2, 0x27e, 
    0x27f, 0x7, 0x70, 0x2, 0x2, 0x27f, 0x280, 0x7, 0x48, 0x2, 0x2, 0x280, 
    0x282, 0x8, 0x1a, 0x1, 0x2, 0x281, 0x276, 0x3, 0x2, 0x2, 0x2, 0x281, 
    0x27c, 0x3, 0x2, 0x2, 0x2, 0x282, 0x33, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 
    0x7, 0x43, 0x2, 0x2, 0x284, 0x285, 0x7, 0x70, 0x2, 0x2, 0x285, 0x286, 
    0x8, 0x1b, 0x1, 0x2, 0x286, 0x287, 0x7, 0x48, 0x2, 0x2, 0x287, 0x29b, 
    0x8, 0x1b, 0x1, 0x2, 0x288, 0x289, 0x7, 0x43, 0x2, 0x2, 0x289, 0x28a, 
    0x7, 0x70, 0x2, 0x2, 0x28a, 0x28b, 0x8, 0x1b, 0x1, 0x2, 0x28b, 0x28c, 
    0x7, 0x4d, 0x2, 0x2, 0x28c, 0x295, 0x8, 0x1b, 0x1, 0x2, 0x28d, 0x28e, 
    0x5, 0x32, 0x1a, 0x2, 0x28e, 0x28f, 0x8, 0x1b, 0x1, 0x2, 0x28f, 0x294, 
    0x3, 0x2, 0x2, 0x2, 0x290, 0x291, 0x5, 0x30, 0x19, 0x2, 0x291, 0x292, 
    0x8, 0x1b, 0x1, 0x2, 0x292, 0x294, 0x3, 0x2, 0x2, 0x2, 0x293, 0x28d, 
    0x3, 0x2, 0x2, 0x2, 0x293, 0x290, 0x3, 0x2, 0x2, 0x2, 0x294, 0x297, 
    0x3, 0x2, 0x2, 0x2, 0x295, 0x293, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 
    0x3, 0x2, 0x2, 0x2, 0x296, 0x298, 0x3, 0x2, 0x2, 0x2, 0x297, 0x295, 
    0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x7, 0x4e, 0x2, 0x2, 0x299, 0x29b, 
    0x7, 0x48, 0x2, 0x2, 0x29a, 0x283, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x288, 
    0x3, 0x2, 0x2, 0x2, 0x29b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x5, 
    0xc, 0x7, 0x2, 0x29d, 0x29e, 0x8, 0x1c, 0x1, 0x2, 0x29e, 0x2a3, 0x3, 
    0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x5, 0x12, 0xa, 0x2, 0x2a0, 0x2a1, 0x8, 
    0x1c, 0x1, 0x2, 0x2a1, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x29c, 0x3, 
    0x2, 0x2, 0x2, 0x2a2, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a6, 0x3, 
    0x2, 0x2, 0x2, 0x2a4, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 
    0x2, 0x2, 0x2, 0x2a5, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a4, 0x3, 
    0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x7, 0x44, 0x2, 0x2, 0x2a8, 0x2a9, 0x7, 
    0x70, 0x2, 0x2, 0x2a9, 0x2aa, 0x8, 0x1c, 0x1, 0x2, 0x2aa, 0x2ab, 0x7, 
    0x48, 0x2, 0x2, 0x2ab, 0x2c7, 0x8, 0x1c, 0x1, 0x2, 0x2ac, 0x2ad, 0x5, 
    0xc, 0x7, 0x2, 0x2ad, 0x2ae, 0x8, 0x1c, 0x1, 0x2, 0x2ae, 0x2b3, 0x3, 
    0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x5, 0x12, 0xa, 0x2, 0x2b0, 0x2b1, 0x8, 
    0x1c, 0x1, 0x2, 0x2b1, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2ac, 0x3, 
    0x2, 0x2, 0x2, 0x2b2, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b6, 0x3, 
    0x2, 0x2, 0x2, 0x2b4, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x3, 
    0x2, 0x2, 0x2, 0x2b5, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b4, 0x3, 
    0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x7, 0x44, 0x2, 0x2, 0x2b8, 0x2b9, 0x7, 
    0x70, 0x2, 0x2, 0x2b9, 0x2ba, 0x8, 0x1c, 0x1, 0x2, 0x2ba, 0x2bb, 0x8, 
    0x1c, 0x1, 0x2, 0x2bb, 0x2c1, 0x7, 0x4d, 0x2, 0x2, 0x2bc, 0x2bd, 0x5, 
    0x3a, 0x1e, 0x2, 0x2bd, 0x2be, 0x8, 0x1c, 0x1, 0x2, 0x2be, 0x2c0, 0x3, 
    0x2, 0x2, 0x2, 0x2bf, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c3, 0x3, 
    0x2, 0x2, 0x2, 0x2c1, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x3, 
    0x2, 0x2, 0x2, 0x2c2, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c1, 0x3, 
    0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x7, 0x4e, 0x2, 0x2, 0x2c5, 0x2c7, 0x7, 
    0x48, 0x2, 0x2, 0x2c6, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2b4, 0x3, 
    0x2, 0x2, 0x2, 0x2c7, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x7, 0x70, 
    0x2, 0x2, 0x2c9, 0x2cf, 0x8, 0x1d, 0x1, 0x2, 0x2ca, 0x2cb, 0x7, 0x49, 
    0x2, 0x2, 0x2cb, 0x2cc, 0x7, 0x70, 0x2, 0x2, 0x2cc, 0x2ce, 0x8, 0x1d, 
    0x1, 0x2, 0x2cd, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2d1, 0x3, 0x2, 
    0x2, 0x2, 0x2cf, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x3, 0x2, 
    0x2, 0x2, 0x2d0, 0x39, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2cf, 0x3, 0x2, 0x2, 
    0x2, 0x2d2, 0x2d3, 0x7, 0x70, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 0x53, 0x2, 
    0x2, 0x2d4, 0x2d5, 0x7, 0x70, 0x2, 0x2, 0x2d5, 0x2d6, 0x7, 0x48, 0x2, 
    0x2, 0x2d6, 0x2e6, 0x8, 0x1e, 0x1, 0x2, 0x2d7, 0x2d8, 0x7, 0x70, 0x2, 
    0x2, 0x2d8, 0x2d9, 0x7, 0x53, 0x2, 0x2, 0x2d9, 0x2da, 0x5, 0x42, 0x22, 
    0x2, 0x2da, 0x2db, 0x7, 0x48, 0x2, 0x2, 0x2db, 0x2dc, 0x8, 0x1e, 0x1, 
    0x2, 0x2dc, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x7, 0x70, 0x2, 
    0x2, 0x2de, 0x2df, 0x7, 0x53, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 0x4d, 0x2, 
    0x2, 0x2e0, 0x2e1, 0x5, 0x38, 0x1d, 0x2, 0x2e1, 0x2e2, 0x7, 0x4e, 0x2, 
    0x2, 0x2e2, 0x2e3, 0x7, 0x48, 0x2, 0x2, 0x2e3, 0x2e4, 0x8, 0x1e, 0x1, 
    0x2, 0x2e4, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2d2, 0x3, 0x2, 0x2, 
    0x2, 0x2e5, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2dd, 0x3, 0x2, 0x2, 
    0x2, 0x2e6, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 0x7, 0x70, 0x2, 
    0x2, 0x2e8, 0x2e9, 0x7, 0x53, 0x2, 0x2, 0x2e9, 0x2ea, 0x7, 0x70, 0x2, 
    0x2, 0x2ea, 0x2ef, 0x7, 0x4b, 0x2, 0x2, 0x2eb, 0x2ec, 0x7, 0x70, 0x2, 
    0x2, 0x2ec, 0x2ed, 0x7, 0x53, 0x2, 0x2, 0x2ed, 0x2ee, 0x7, 0x70, 0x2, 
    0x2, 0x2ee, 0x2f0, 0x8, 0x1f, 0x1, 0x2, 0x2ef, 0x2eb, 0x3, 0x2, 0x2, 
    0x2, 0x2ef, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f8, 0x3, 0x2, 0x2, 
    0x2, 0x2f1, 0x2f2, 0x7, 0x49, 0x2, 0x2, 0x2f2, 0x2f3, 0x7, 0x70, 0x2, 
    0x2, 0x2f3, 0x2f4, 0x7, 0x53, 0x2, 0x2, 0x2f4, 0x2f5, 0x7, 0x70, 0x2, 
    0x2, 0x2f5, 0x2f7, 0x8, 0x1f, 0x1, 0x2, 0x2f6, 0x2f1, 0x3, 0x2, 0x2, 
    0x2, 0x2f7, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f6, 0x3, 0x2, 0x2, 
    0x2, 0x2f8, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fb, 0x3, 0x2, 0x2, 
    0x2, 0x2fa, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 0x7, 0x4c, 0x2, 
    0x2, 0x2fc, 0x2fd, 0x7, 0x48, 0x2, 0x2, 0x2fd, 0x30a, 0x8, 0x1f, 0x1, 
    0x2, 0x2fe, 0x2ff, 0x7, 0x45, 0x2, 0x2, 0x2ff, 0x300, 0x7, 0x53, 0x2, 
    0x2, 0x300, 0x301, 0x7, 0x70, 0x2, 0x2, 0x301, 0x302, 0x7, 0x48, 0x2, 
    0x2, 0x302, 0x30a, 0x8, 0x1f, 0x1, 0x2, 0x303, 0x304, 0x7, 0x46, 0x2, 
    0x2, 0x304, 0x305, 0x7, 0x53, 0x2, 0x2, 0x305, 0x306, 0x5, 0x2, 0x2, 
    0x2, 0x306, 0x307, 0x7, 0x48, 0x2, 0x2, 0x307, 0x308, 0x8, 0x1f, 0x1, 
    0x2, 0x308, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2e7, 0x3, 0x2, 0x2, 
    0x2, 0x309, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x309, 0x303, 0x3, 0x2, 0x2, 
    0x2, 0x30a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x31c, 0x7, 0x4f, 0x2, 
    0x2, 0x30c, 0x30d, 0x5, 0x10, 0x9, 0x2, 0x30d, 0x30e, 0x7, 0x70, 0x2, 
    0x2, 0x30e, 0x315, 0x7, 0x53, 0x2, 0x2, 0x30f, 0x310, 0x5, 0x2, 0x2, 
    0x2, 0x310, 0x311, 0x8, 0x20, 0x1, 0x2, 0x311, 0x316, 0x3, 0x2, 0x2, 
    0x2, 0x312, 0x313, 0x5, 0x42, 0x22, 0x2, 0x313, 0x314, 0x8, 0x20, 0x1, 
    0x2, 0x314, 0x316, 0x3, 0x2, 0x2, 0x2, 0x315, 0x30f, 0x3, 0x2, 0x2, 
    0x2, 0x315, 0x312, 0x3, 0x2, 0x2, 0x2, 0x316, 0x317, 0x3, 0x2, 0x2, 
    0x2, 0x317, 0x318, 0x7, 0x48, 0x2, 0x2, 0x318, 0x319, 0x8, 0x20, 0x1, 
    0x2, 0x319, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x30c, 0x3, 0x2, 0x2, 
    0x2, 0x31b, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31a, 0x3, 0x2, 0x2, 
    0x2, 0x31c, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31f, 0x3, 0x2, 0x2, 
    0x2, 0x31e, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x320, 0x7, 0x50, 0x2, 
    0x2, 0x320, 0x321, 0x8, 0x20, 0x1, 0x2, 0x321, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x322, 0x323, 0x7, 0x47, 0x2, 0x2, 0x323, 0x324, 0x7, 0x70, 0x2, 
    0x2, 0x324, 0x328, 0x8, 0x21, 0x1, 0x2, 0x325, 0x326, 0x5, 0x3e, 0x20, 
    0x2, 0x326, 0x327, 0x8, 0x21, 0x1, 0x2, 0x327, 0x329, 0x3, 0x2, 0x2, 
    0x2, 0x328, 0x325, 0x3, 0x2, 0x2, 0x2, 0x328, 0x329, 0x3, 0x2, 0x2, 
    0x2, 0x329, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x32b, 0x7, 0x4d, 0x2, 
    0x2, 0x32b, 0x331, 0x8, 0x21, 0x1, 0x2, 0x32c, 0x32d, 0x5, 0x3c, 0x1f, 
    0x2, 0x32d, 0x32e, 0x8, 0x21, 0x1, 0x2, 0x32e, 0x330, 0x3, 0x2, 0x2, 
    0x2, 0x32f, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x330, 0x333, 0x3, 0x2, 0x2, 
    0x2, 0x331, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 
    0x2, 0x332, 0x334, 0x3, 0x2, 0x2, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 
    0x2, 0x334, 0x335, 0x7, 0x4e, 0x2, 0x2, 0x335, 0x336, 0x7, 0x48, 0x2, 
    0x2, 0x336, 0x41, 0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 0x5, 0x44, 0x23, 
    0x2, 0x338, 0x339, 0x8, 0x22, 0x1, 0x2, 0x339, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x33a, 0x33b, 0x5, 0x46, 0x24, 0x2, 0x33b, 0x342, 0x8, 0x23, 0x1, 
    0x2, 0x33c, 0x33d, 0x7, 0x62, 0x2, 0x2, 0x33d, 0x33e, 0x5, 0x46, 0x24, 
    0x2, 0x33e, 0x33f, 0x8, 0x23, 0x1, 0x2, 0x33f, 0x341, 0x3, 0x2, 0x2, 
    0x2, 0x340, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x341, 0x344, 0x3, 0x2, 0x2, 
    0x2, 0x342, 0x340, 0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 0x3, 0x2, 0x2, 
    0x2, 0x343, 0x45, 0x3, 0x2, 0x2, 0x2, 0x344, 0x342, 0x3, 0x2, 0x2, 0x2, 
    0x345, 0x346, 0x5, 0x48, 0x25, 0x2, 0x346, 0x34d, 0x8, 0x24, 0x1, 0x2, 
    0x347, 0x348, 0x7, 0x61, 0x2, 0x2, 0x348, 0x349, 0x5, 0x48, 0x25, 0x2, 
    0x349, 0x34a, 0x8, 0x24, 0x1, 0x2, 0x34a, 0x34c, 0x3, 0x2, 0x2, 0x2, 
    0x34b, 0x347, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34f, 0x3, 0x2, 0x2, 0x2, 
    0x34d, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34e, 0x3, 0x2, 0x2, 0x2, 
    0x34e, 0x47, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x351, 0x5, 0x4a, 0x26, 0x2, 0x351, 0x358, 0x8, 0x25, 0x1, 0x2, 0x352, 
    0x353, 0x9, 0x7, 0x2, 0x2, 0x353, 0x354, 0x5, 0x4a, 0x26, 0x2, 0x354, 
    0x355, 0x8, 0x25, 0x1, 0x2, 0x355, 0x357, 0x3, 0x2, 0x2, 0x2, 0x356, 
    0x352, 0x3, 0x2, 0x2, 0x2, 0x357, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x358, 
    0x356, 0x3, 0x2, 0x2, 0x2, 0x358, 0x359, 0x3, 0x2, 0x2, 0x2, 0x359, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x358, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35c, 
    0x5, 0x4c, 0x27, 0x2, 0x35c, 0x363, 0x8, 0x26, 0x1, 0x2, 0x35d, 0x35e, 
    0x9, 0x8, 0x2, 0x2, 0x35e, 0x35f, 0x5, 0x4c, 0x27, 0x2, 0x35f, 0x360, 
    0x8, 0x26, 0x1, 0x2, 0x360, 0x362, 0x3, 0x2, 0x2, 0x2, 0x361, 0x35d, 
    0x3, 0x2, 0x2, 0x2, 0x362, 0x365, 0x3, 0x2, 0x2, 0x2, 0x363, 0x361, 
    0x3, 0x2, 0x2, 0x2, 0x363, 0x364, 0x3, 0x2, 0x2, 0x2, 0x364, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x365, 0x363, 0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x5, 
    0x4e, 0x28, 0x2, 0x367, 0x36e, 0x8, 0x27, 0x1, 0x2, 0x368, 0x369, 0x9, 
    0x9, 0x2, 0x2, 0x369, 0x36a, 0x5, 0x4e, 0x28, 0x2, 0x36a, 0x36b, 0x8, 
    0x27, 0x1, 0x2, 0x36b, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x368, 0x3, 
    0x2, 0x2, 0x2, 0x36d, 0x370, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36c, 0x3, 
    0x2, 0x2, 0x2, 0x36e, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x370, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x371, 0x372, 0x5, 0x50, 
    0x29, 0x2, 0x372, 0x379, 0x8, 0x28, 0x1, 0x2, 0x373, 0x374, 0x9, 0xa, 
    0x2, 0x2, 0x374, 0x375, 0x5, 0x50, 0x29, 0x2, 0x375, 0x376, 0x8, 0x28, 
    0x1, 0x2, 0x376, 0x378, 0x3, 0x2, 0x2, 0x2, 0x377, 0x373, 0x3, 0x2, 
    0x2, 0x2, 0x378, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x379, 0x377, 0x3, 0x2, 
    0x2, 0x2, 0x379, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x37b, 0x379, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37e, 0x9, 0xb, 0x2, 
    0x2, 0x37d, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 0x3, 0x2, 0x2, 
    0x2, 0x37e, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 0x5, 0x52, 0x2a, 
    0x2, 0x380, 0x381, 0x8, 0x29, 0x1, 0x2, 0x381, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x382, 0x383, 0x7, 0x69, 0x2, 0x2, 0x383, 0x393, 0x8, 0x2a, 0x1, 
    0x2, 0x384, 0x385, 0x7, 0x6c, 0x2, 0x2, 0x385, 0x393, 0x8, 0x2a, 0x1, 
    0x2, 0x386, 0x387, 0x7, 0x6e, 0x2, 0x2, 0x387, 0x393, 0x8, 0x2a, 0x1, 
    0x2, 0x388, 0x389, 0x7, 0x6f, 0x2, 0x2, 0x389, 0x393, 0x8, 0x2a, 0x1, 
    0x2, 0x38a, 0x38b, 0x7, 0x70, 0x2, 0x2, 0x38b, 0x393, 0x8, 0x2a, 0x1, 
    0x2, 0x38c, 0x38d, 0x5, 0x4, 0x3, 0x2, 0x38d, 0x38e, 0x8, 0x2a, 0x1, 
    0x2, 0x38e, 0x393, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x390, 0x5, 0x54, 0x2b, 
    0x2, 0x390, 0x391, 0x8, 0x2a, 0x1, 0x2, 0x391, 0x393, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x382, 0x3, 0x2, 0x2, 0x2, 0x392, 0x384, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x386, 0x3, 0x2, 0x2, 0x2, 0x392, 0x388, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x38a, 0x3, 0x2, 0x2, 0x2, 0x392, 0x38c, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x393, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x394, 0x395, 0x7, 0x4b, 0x2, 0x2, 0x395, 0x396, 0x5, 0x42, 0x22, 0x2, 
    0x396, 0x397, 0x7, 0x4c, 0x2, 0x2, 0x397, 0x398, 0x8, 0x2b, 0x1, 0x2, 
    0x398, 0x55, 0x3, 0x2, 0x2, 0x2, 0x47, 0x5b, 0x64, 0x68, 0x6e, 0x77, 
    0x79, 0xa0, 0xa2, 0xba, 0xc7, 0xc9, 0xd2, 0xda, 0xe6, 0xe8, 0xf1, 0xf9, 
    0x111, 0x11b, 0x127, 0x129, 0x142, 0x169, 0x186, 0x18b, 0x1b3, 0x1d7, 
    0x1e8, 0x1f3, 0x200, 0x209, 0x210, 0x21a, 0x21e, 0x228, 0x22b, 0x23e, 
    0x244, 0x249, 0x250, 0x255, 0x274, 0x281, 0x293, 0x295, 0x29a, 0x2a2, 
    0x2a4, 0x2b2, 0x2b4, 0x2c1, 0x2c6, 0x2cf, 0x2e5, 0x2ef, 0x2f8, 0x309, 
    0x315, 0x31c, 0x328, 0x331, 0x342, 0x34d, 0x358, 0x363, 0x36e, 0x379, 
    0x37d, 0x392, 
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
