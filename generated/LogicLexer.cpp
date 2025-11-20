
// Generated from grammar/Logic.g4 by ANTLR 4.13.2


#include "LogicLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LogicLexerStaticData final {
  LogicLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LogicLexerStaticData(const LogicLexerStaticData&) = delete;
  LogicLexerStaticData(LogicLexerStaticData&&) = delete;
  LogicLexerStaticData& operator=(const LogicLexerStaticData&) = delete;
  LogicLexerStaticData& operator=(LogicLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag logiclexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LogicLexerStaticData> logiclexerLexerStaticData = nullptr;

void logiclexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (logiclexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(logiclexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LogicLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "VARIABLE", "NOT", "AND", 
      "OR", "IMPLIES", "IFF", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,12,80,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,4,5,37,8,5,11,5,12,5,38,1,6,1,6,1,6,1,6,3,6,45,8,
  	6,1,7,1,7,1,7,1,7,3,7,51,8,7,1,8,1,8,1,8,3,8,56,8,8,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,3,9,66,8,9,1,10,1,10,1,10,1,10,3,10,72,8,10,1,11,4,11,75,
  	8,11,11,11,12,11,76,1,11,1,11,0,0,12,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,
  	8,17,9,19,10,21,11,23,12,1,0,2,2,0,65,90,97,122,3,0,9,10,13,13,32,32,
  	86,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,
  	0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,
  	0,0,23,1,0,0,0,1,25,1,0,0,0,3,27,1,0,0,0,5,29,1,0,0,0,7,31,1,0,0,0,9,
  	33,1,0,0,0,11,36,1,0,0,0,13,44,1,0,0,0,15,50,1,0,0,0,17,55,1,0,0,0,19,
  	65,1,0,0,0,21,71,1,0,0,0,23,74,1,0,0,0,25,26,5,8744,0,0,26,2,1,0,0,0,
  	27,28,5,8743,0,0,28,4,1,0,0,0,29,30,5,172,0,0,30,6,1,0,0,0,31,32,5,40,
  	0,0,32,8,1,0,0,0,33,34,5,41,0,0,34,10,1,0,0,0,35,37,7,0,0,0,36,35,1,0,
  	0,0,37,38,1,0,0,0,38,36,1,0,0,0,38,39,1,0,0,0,39,12,1,0,0,0,40,41,5,78,
  	0,0,41,42,5,79,0,0,42,45,5,84,0,0,43,45,5,172,0,0,44,40,1,0,0,0,44,43,
  	1,0,0,0,45,14,1,0,0,0,46,47,5,65,0,0,47,48,5,78,0,0,48,51,5,68,0,0,49,
  	51,5,8743,0,0,50,46,1,0,0,0,50,49,1,0,0,0,51,16,1,0,0,0,52,53,5,79,0,
  	0,53,56,5,82,0,0,54,56,5,8744,0,0,55,52,1,0,0,0,55,54,1,0,0,0,56,18,1,
  	0,0,0,57,58,5,73,0,0,58,59,5,77,0,0,59,60,5,80,0,0,60,61,5,76,0,0,61,
  	62,5,73,0,0,62,63,5,69,0,0,63,66,5,83,0,0,64,66,5,8594,0,0,65,57,1,0,
  	0,0,65,64,1,0,0,0,66,20,1,0,0,0,67,68,5,73,0,0,68,69,5,70,0,0,69,72,5,
  	70,0,0,70,72,5,8596,0,0,71,67,1,0,0,0,71,70,1,0,0,0,72,22,1,0,0,0,73,
  	75,7,1,0,0,74,73,1,0,0,0,75,76,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,
  	78,1,0,0,0,78,79,6,11,0,0,79,24,1,0,0,0,8,0,38,44,50,55,65,71,76,1,6,
  	0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  logiclexerLexerStaticData = std::move(staticData);
}

}

LogicLexer::LogicLexer(CharStream *input) : Lexer(input) {
  LogicLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *logiclexerLexerStaticData->atn, logiclexerLexerStaticData->decisionToDFA, logiclexerLexerStaticData->sharedContextCache);
}

LogicLexer::~LogicLexer() {
  delete _interpreter;
}

std::string LogicLexer::getGrammarFileName() const {
  return "Logic.g4";
}

const std::vector<std::string>& LogicLexer::getRuleNames() const {
  return logiclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& LogicLexer::getChannelNames() const {
  return logiclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& LogicLexer::getModeNames() const {
  return logiclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& LogicLexer::getVocabulary() const {
  return logiclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LogicLexer::getSerializedATN() const {
  return logiclexerLexerStaticData->serializedATN;
}

const atn::ATN& LogicLexer::getATN() const {
  return *logiclexerLexerStaticData->atn;
}




void LogicLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  logiclexerLexerInitialize();
#else
  ::antlr4::internal::call_once(logiclexerLexerOnceFlag, logiclexerLexerInitialize);
#endif
}
