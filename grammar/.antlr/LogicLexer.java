// Generated from c:/Joblin/Demo/grammar/Logic.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class LogicLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, VARIABLE=6, NOT=7, AND=8, OR=9, 
		IMPLIES=10, IFF=11, WS=12;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "VARIABLE", "NOT", "AND", "OR", 
			"IMPLIES", "IFF", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'\\u2228'", "'\\u2227'", "'\\u00AC'", "'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, "VARIABLE", "NOT", "AND", "OR", "IMPLIES", 
			"IFF", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public LogicLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Logic.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\fP\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005"+
		"\u0004\u0005%\b\u0005\u000b\u0005\f\u0005&\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0003\u0006-\b\u0006\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0003\u00073\b\u0007\u0001\b\u0001\b\u0001\b\u0003"+
		"\b8\b\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0003\tB\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0003\nH\b\n\u0001\u000b"+
		"\u0004\u000bK\b\u000b\u000b\u000b\f\u000bL\u0001\u000b\u0001\u000b\u0000"+
		"\u0000\f\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b"+
		"\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0001\u0000"+
		"\u0002\u0002\u0000AZaz\u0003\u0000\t\n\r\r  V\u0000\u0001\u0001\u0000"+
		"\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001\u0000"+
		"\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000"+
		"\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000"+
		"\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000"+
		"\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000"+
		"\u0000\u0017\u0001\u0000\u0000\u0000\u0001\u0019\u0001\u0000\u0000\u0000"+
		"\u0003\u001b\u0001\u0000\u0000\u0000\u0005\u001d\u0001\u0000\u0000\u0000"+
		"\u0007\u001f\u0001\u0000\u0000\u0000\t!\u0001\u0000\u0000\u0000\u000b"+
		"$\u0001\u0000\u0000\u0000\r,\u0001\u0000\u0000\u0000\u000f2\u0001\u0000"+
		"\u0000\u0000\u00117\u0001\u0000\u0000\u0000\u0013A\u0001\u0000\u0000\u0000"+
		"\u0015G\u0001\u0000\u0000\u0000\u0017J\u0001\u0000\u0000\u0000\u0019\u001a"+
		"\u0005\u2228\u0000\u0000\u001a\u0002\u0001\u0000\u0000\u0000\u001b\u001c"+
		"\u0005\u2227\u0000\u0000\u001c\u0004\u0001\u0000\u0000\u0000\u001d\u001e"+
		"\u0005\u00ac\u0000\u0000\u001e\u0006\u0001\u0000\u0000\u0000\u001f \u0005"+
		"(\u0000\u0000 \b\u0001\u0000\u0000\u0000!\"\u0005)\u0000\u0000\"\n\u0001"+
		"\u0000\u0000\u0000#%\u0007\u0000\u0000\u0000$#\u0001\u0000\u0000\u0000"+
		"%&\u0001\u0000\u0000\u0000&$\u0001\u0000\u0000\u0000&\'\u0001\u0000\u0000"+
		"\u0000\'\f\u0001\u0000\u0000\u0000()\u0005N\u0000\u0000)*\u0005O\u0000"+
		"\u0000*-\u0005T\u0000\u0000+-\u0005\u00ac\u0000\u0000,(\u0001\u0000\u0000"+
		"\u0000,+\u0001\u0000\u0000\u0000-\u000e\u0001\u0000\u0000\u0000./\u0005"+
		"A\u0000\u0000/0\u0005N\u0000\u000003\u0005D\u0000\u000013\u0005\u2227"+
		"\u0000\u00002.\u0001\u0000\u0000\u000021\u0001\u0000\u0000\u00003\u0010"+
		"\u0001\u0000\u0000\u000045\u0005O\u0000\u000058\u0005R\u0000\u000068\u0005"+
		"\u2228\u0000\u000074\u0001\u0000\u0000\u000076\u0001\u0000\u0000\u0000"+
		"8\u0012\u0001\u0000\u0000\u00009:\u0005I\u0000\u0000:;\u0005M\u0000\u0000"+
		";<\u0005P\u0000\u0000<=\u0005L\u0000\u0000=>\u0005I\u0000\u0000>?\u0005"+
		"E\u0000\u0000?B\u0005S\u0000\u0000@B\u0005\u2192\u0000\u0000A9\u0001\u0000"+
		"\u0000\u0000A@\u0001\u0000\u0000\u0000B\u0014\u0001\u0000\u0000\u0000"+
		"CD\u0005I\u0000\u0000DE\u0005F\u0000\u0000EH\u0005F\u0000\u0000FH\u0005"+
		"\u2194\u0000\u0000GC\u0001\u0000\u0000\u0000GF\u0001\u0000\u0000\u0000"+
		"H\u0016\u0001\u0000\u0000\u0000IK\u0007\u0001\u0000\u0000JI\u0001\u0000"+
		"\u0000\u0000KL\u0001\u0000\u0000\u0000LJ\u0001\u0000\u0000\u0000LM\u0001"+
		"\u0000\u0000\u0000MN\u0001\u0000\u0000\u0000NO\u0006\u000b\u0000\u0000"+
		"O\u0018\u0001\u0000\u0000\u0000\b\u0000&,27AGL\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}