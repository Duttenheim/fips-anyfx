
    #include <string>
    #include <vector>
    #include "anyfxtoken.h"


// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AnyFXLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, SC = 16, CO = 17, COL = 18, LP = 19, RP = 20, LB = 21, RB = 22, 
    LL = 23, RR = 24, DOT = 25, NOT = 26, EQ = 27, QO = 28, QU = 29, AND = 30, 
    ANDSET = 31, OR = 32, ORSET = 33, XOR = 34, XORSET = 35, CONNJUGATE = 36, 
    Q = 37, NU = 38, FORWARDSLASH = 39, LESS = 40, LESSEQ = 41, GREATER = 42, 
    GREATEREQ = 43, LOGICEQ = 44, NOTEQ = 45, LOGICAND = 46, LOGICOR = 47, 
    MOD = 48, UNDERSC = 49, ADD_OP = 50, SUB_OP = 51, DIV_OP = 52, MUL_OP = 53, 
    INTEGERLITERAL = 54, COMMENT = 55, ML_COMMENT = 56, FLOATLITERAL = 57, 
    EXPONENT = 58, DOUBLELITERAL = 59, HEX = 60, IDENTIFIER = 61, WS = 62
  };

  AnyFXLexer(antlr4::CharStream *input);
  ~AnyFXLexer();


  #include <iostream>

  misc::Interval interval;
  std::string currentFile;
  int currentLine = 0;

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

