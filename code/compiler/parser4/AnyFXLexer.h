
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
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, SC = 32, 
    CO = 33, COL = 34, LP = 35, RP = 36, LB = 37, RB = 38, LL = 39, RR = 40, 
    DOT = 41, NOT = 42, EQ = 43, QO = 44, QU = 45, AND = 46, ANDSET = 47, 
    OR = 48, ORSET = 49, XOR = 50, XORSET = 51, CONNJUGATE = 52, Q = 53, 
    NU = 54, FORWARDSLASH = 55, LESS = 56, LESSEQ = 57, GREATER = 58, GREATEREQ = 59, 
    LOGICEQ = 60, NOTEQ = 61, LOGICAND = 62, LOGICOR = 63, MOD = 64, UNDERSC = 65, 
    SOBAKA = 66, ADD_OP = 67, SUB_OP = 68, DIV_OP = 69, MUL_OP = 70, INTEGERLITERAL = 71, 
    COMMENT = 72, ML_COMMENT = 73, FLOATLITERAL = 74, EXPONENT = 75, DOUBLELITERAL = 76, 
    HEX = 77, IDENTIFIER = 78, WS = 79
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

