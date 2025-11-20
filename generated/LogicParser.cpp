
// Generated from grammar/Logic.g4 by ANTLR 4.13.2


#include "LogicListener.h"
#include "LogicVisitor.h"

#include "LogicParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LogicParserStaticData final {
  LogicParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LogicParserStaticData(const LogicParserStaticData&) = delete;
  LogicParserStaticData(LogicParserStaticData&&) = delete;
  LogicParserStaticData& operator=(const LogicParserStaticData&) = delete;
  LogicParserStaticData& operator=(LogicParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag logicParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LogicParserStaticData> logicParserStaticData = nullptr;

void logicParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (logicParserStaticData != nullptr) {
    return;
  }
#else
  assert(logicParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LogicParserStaticData>(
    std::vector<std::string>{
      "expr", "iffExpr", "impliesExpr", "orExpr", "andExpr", "atom"
    },
    std::vector<std::string>{
      "", "'\\u2228'", "'\\u2227'", "'\\u00AC'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "VARIABLE", "NOT", "AND", "OR", "IMPLIES", 
      "IFF", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,56,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,1,
  	1,1,1,1,5,1,18,8,1,10,1,12,1,21,9,1,1,2,1,2,1,2,5,2,26,8,2,10,2,12,2,
  	29,9,2,1,3,1,3,1,3,5,3,34,8,3,10,3,12,3,37,9,3,1,4,1,4,1,4,5,4,42,8,4,
  	10,4,12,4,45,9,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,54,8,5,1,5,0,0,6,0,2,
  	4,6,8,10,0,3,2,0,1,1,9,9,2,0,2,2,8,8,2,0,3,3,7,7,55,0,12,1,0,0,0,2,14,
  	1,0,0,0,4,22,1,0,0,0,6,30,1,0,0,0,8,38,1,0,0,0,10,53,1,0,0,0,12,13,3,
  	2,1,0,13,1,1,0,0,0,14,19,3,4,2,0,15,16,5,11,0,0,16,18,3,4,2,0,17,15,1,
  	0,0,0,18,21,1,0,0,0,19,17,1,0,0,0,19,20,1,0,0,0,20,3,1,0,0,0,21,19,1,
  	0,0,0,22,27,3,6,3,0,23,24,5,10,0,0,24,26,3,6,3,0,25,23,1,0,0,0,26,29,
  	1,0,0,0,27,25,1,0,0,0,27,28,1,0,0,0,28,5,1,0,0,0,29,27,1,0,0,0,30,35,
  	3,8,4,0,31,32,7,0,0,0,32,34,3,8,4,0,33,31,1,0,0,0,34,37,1,0,0,0,35,33,
  	1,0,0,0,35,36,1,0,0,0,36,7,1,0,0,0,37,35,1,0,0,0,38,43,3,10,5,0,39,40,
  	7,1,0,0,40,42,3,10,5,0,41,39,1,0,0,0,42,45,1,0,0,0,43,41,1,0,0,0,43,44,
  	1,0,0,0,44,9,1,0,0,0,45,43,1,0,0,0,46,54,5,6,0,0,47,48,7,2,0,0,48,54,
  	3,10,5,0,49,50,5,4,0,0,50,51,3,0,0,0,51,52,5,5,0,0,52,54,1,0,0,0,53,46,
  	1,0,0,0,53,47,1,0,0,0,53,49,1,0,0,0,54,11,1,0,0,0,5,19,27,35,43,53
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  logicParserStaticData = std::move(staticData);
}

}

LogicParser::LogicParser(TokenStream *input) : LogicParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LogicParser::LogicParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LogicParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *logicParserStaticData->atn, logicParserStaticData->decisionToDFA, logicParserStaticData->sharedContextCache, options);
}

LogicParser::~LogicParser() {
  delete _interpreter;
}

const atn::ATN& LogicParser::getATN() const {
  return *logicParserStaticData->atn;
}

std::string LogicParser::getGrammarFileName() const {
  return "Logic.g4";
}

const std::vector<std::string>& LogicParser::getRuleNames() const {
  return logicParserStaticData->ruleNames;
}

const dfa::Vocabulary& LogicParser::getVocabulary() const {
  return logicParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LogicParser::getSerializedATN() const {
  return logicParserStaticData->serializedATN;
}


//----------------- ExprContext ------------------------------------------------------------------

LogicParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LogicParser::IffExprContext* LogicParser::ExprContext::iffExpr() {
  return getRuleContext<LogicParser::IffExprContext>(0);
}


size_t LogicParser::ExprContext::getRuleIndex() const {
  return LogicParser::RuleExpr;
}

void LogicParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void LogicParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any LogicParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LogicVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

LogicParser::ExprContext* LogicParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 0, LogicParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    iffExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IffExprContext ------------------------------------------------------------------

LogicParser::IffExprContext::IffExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LogicParser::ImpliesExprContext *> LogicParser::IffExprContext::impliesExpr() {
  return getRuleContexts<LogicParser::ImpliesExprContext>();
}

LogicParser::ImpliesExprContext* LogicParser::IffExprContext::impliesExpr(size_t i) {
  return getRuleContext<LogicParser::ImpliesExprContext>(i);
}

std::vector<tree::TerminalNode *> LogicParser::IffExprContext::IFF() {
  return getTokens(LogicParser::IFF);
}

tree::TerminalNode* LogicParser::IffExprContext::IFF(size_t i) {
  return getToken(LogicParser::IFF, i);
}


size_t LogicParser::IffExprContext::getRuleIndex() const {
  return LogicParser::RuleIffExpr;
}

void LogicParser::IffExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIffExpr(this);
}

void LogicParser::IffExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIffExpr(this);
}


std::any LogicParser::IffExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LogicVisitor*>(visitor))
    return parserVisitor->visitIffExpr(this);
  else
    return visitor->visitChildren(this);
}

LogicParser::IffExprContext* LogicParser::iffExpr() {
  IffExprContext *_localctx = _tracker.createInstance<IffExprContext>(_ctx, getState());
  enterRule(_localctx, 2, LogicParser::RuleIffExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    impliesExpr();
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LogicParser::IFF) {
      setState(15);
      match(LogicParser::IFF);
      setState(16);
      impliesExpr();
      setState(21);
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

//----------------- ImpliesExprContext ------------------------------------------------------------------

LogicParser::ImpliesExprContext::ImpliesExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LogicParser::OrExprContext *> LogicParser::ImpliesExprContext::orExpr() {
  return getRuleContexts<LogicParser::OrExprContext>();
}

LogicParser::OrExprContext* LogicParser::ImpliesExprContext::orExpr(size_t i) {
  return getRuleContext<LogicParser::OrExprContext>(i);
}

std::vector<tree::TerminalNode *> LogicParser::ImpliesExprContext::IMPLIES() {
  return getTokens(LogicParser::IMPLIES);
}

tree::TerminalNode* LogicParser::ImpliesExprContext::IMPLIES(size_t i) {
  return getToken(LogicParser::IMPLIES, i);
}


size_t LogicParser::ImpliesExprContext::getRuleIndex() const {
  return LogicParser::RuleImpliesExpr;
}

void LogicParser::ImpliesExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImpliesExpr(this);
}

void LogicParser::ImpliesExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImpliesExpr(this);
}


std::any LogicParser::ImpliesExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LogicVisitor*>(visitor))
    return parserVisitor->visitImpliesExpr(this);
  else
    return visitor->visitChildren(this);
}

LogicParser::ImpliesExprContext* LogicParser::impliesExpr() {
  ImpliesExprContext *_localctx = _tracker.createInstance<ImpliesExprContext>(_ctx, getState());
  enterRule(_localctx, 4, LogicParser::RuleImpliesExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    orExpr();
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LogicParser::IMPLIES) {
      setState(23);
      match(LogicParser::IMPLIES);
      setState(24);
      orExpr();
      setState(29);
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

//----------------- OrExprContext ------------------------------------------------------------------

LogicParser::OrExprContext::OrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LogicParser::AndExprContext *> LogicParser::OrExprContext::andExpr() {
  return getRuleContexts<LogicParser::AndExprContext>();
}

LogicParser::AndExprContext* LogicParser::OrExprContext::andExpr(size_t i) {
  return getRuleContext<LogicParser::AndExprContext>(i);
}

std::vector<tree::TerminalNode *> LogicParser::OrExprContext::OR() {
  return getTokens(LogicParser::OR);
}

tree::TerminalNode* LogicParser::OrExprContext::OR(size_t i) {
  return getToken(LogicParser::OR, i);
}


size_t LogicParser::OrExprContext::getRuleIndex() const {
  return LogicParser::RuleOrExpr;
}

void LogicParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}

void LogicParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}


std::any LogicParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LogicVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}

LogicParser::OrExprContext* LogicParser::orExpr() {
  OrExprContext *_localctx = _tracker.createInstance<OrExprContext>(_ctx, getState());
  enterRule(_localctx, 6, LogicParser::RuleOrExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    andExpr();
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LogicParser::T__0

    || _la == LogicParser::OR) {
      setState(31);
      _la = _input->LA(1);
      if (!(_la == LogicParser::T__0

      || _la == LogicParser::OR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(32);
      andExpr();
      setState(37);
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

//----------------- AndExprContext ------------------------------------------------------------------

LogicParser::AndExprContext::AndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LogicParser::AtomContext *> LogicParser::AndExprContext::atom() {
  return getRuleContexts<LogicParser::AtomContext>();
}

LogicParser::AtomContext* LogicParser::AndExprContext::atom(size_t i) {
  return getRuleContext<LogicParser::AtomContext>(i);
}

std::vector<tree::TerminalNode *> LogicParser::AndExprContext::AND() {
  return getTokens(LogicParser::AND);
}

tree::TerminalNode* LogicParser::AndExprContext::AND(size_t i) {
  return getToken(LogicParser::AND, i);
}


size_t LogicParser::AndExprContext::getRuleIndex() const {
  return LogicParser::RuleAndExpr;
}

void LogicParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}

void LogicParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}


std::any LogicParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LogicVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

LogicParser::AndExprContext* LogicParser::andExpr() {
  AndExprContext *_localctx = _tracker.createInstance<AndExprContext>(_ctx, getState());
  enterRule(_localctx, 8, LogicParser::RuleAndExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    atom();
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LogicParser::T__1

    || _la == LogicParser::AND) {
      setState(39);
      _la = _input->LA(1);
      if (!(_la == LogicParser::T__1

      || _la == LogicParser::AND)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(40);
      atom();
      setState(45);
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

//----------------- AtomContext ------------------------------------------------------------------

LogicParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LogicParser::AtomContext::VARIABLE() {
  return getToken(LogicParser::VARIABLE, 0);
}

LogicParser::AtomContext* LogicParser::AtomContext::atom() {
  return getRuleContext<LogicParser::AtomContext>(0);
}

tree::TerminalNode* LogicParser::AtomContext::NOT() {
  return getToken(LogicParser::NOT, 0);
}

LogicParser::ExprContext* LogicParser::AtomContext::expr() {
  return getRuleContext<LogicParser::ExprContext>(0);
}


size_t LogicParser::AtomContext::getRuleIndex() const {
  return LogicParser::RuleAtom;
}

void LogicParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void LogicParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}


std::any LogicParser::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LogicVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

LogicParser::AtomContext* LogicParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 10, LogicParser::RuleAtom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LogicParser::VARIABLE: {
        enterOuterAlt(_localctx, 1);
        setState(46);
        match(LogicParser::VARIABLE);
        break;
      }

      case LogicParser::T__2:
      case LogicParser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(47);
        _la = _input->LA(1);
        if (!(_la == LogicParser::T__2

        || _la == LogicParser::NOT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(48);
        atom();
        break;
      }

      case LogicParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(49);
        match(LogicParser::T__3);
        setState(50);
        expr();
        setState(51);
        match(LogicParser::T__4);
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

void LogicParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  logicParserInitialize();
#else
  ::antlr4::internal::call_once(logicParserOnceFlag, logicParserInitialize);
#endif
}
