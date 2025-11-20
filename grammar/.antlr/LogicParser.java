// Generated from c:/Joblin/Demo/grammar/Logic.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class LogicParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, VARIABLE=6, NOT=7, AND=8, OR=9, 
		IMPLIES=10, IFF=11, WS=12;
	public static final int
		RULE_expr = 0, RULE_iffExpr = 1, RULE_impliesExpr = 2, RULE_orExpr = 3, 
		RULE_andExpr = 4, RULE_atom = 5;
	private static String[] makeRuleNames() {
		return new String[] {
			"expr", "iffExpr", "impliesExpr", "orExpr", "andExpr", "atom"
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

	@Override
	public String getGrammarFileName() { return "Logic.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public LogicParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExprContext extends ParserRuleContext {
		public IffExprContext iffExpr() {
			return getRuleContext(IffExprContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(12);
			iffExpr();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IffExprContext extends ParserRuleContext {
		public List<ImpliesExprContext> impliesExpr() {
			return getRuleContexts(ImpliesExprContext.class);
		}
		public ImpliesExprContext impliesExpr(int i) {
			return getRuleContext(ImpliesExprContext.class,i);
		}
		public List<TerminalNode> IFF() { return getTokens(LogicParser.IFF); }
		public TerminalNode IFF(int i) {
			return getToken(LogicParser.IFF, i);
		}
		public IffExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_iffExpr; }
	}

	public final IffExprContext iffExpr() throws RecognitionException {
		IffExprContext _localctx = new IffExprContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_iffExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(14);
			impliesExpr();
			setState(19);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==IFF) {
				{
				{
				setState(15);
				match(IFF);
				setState(16);
				impliesExpr();
				}
				}
				setState(21);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ImpliesExprContext extends ParserRuleContext {
		public List<OrExprContext> orExpr() {
			return getRuleContexts(OrExprContext.class);
		}
		public OrExprContext orExpr(int i) {
			return getRuleContext(OrExprContext.class,i);
		}
		public List<TerminalNode> IMPLIES() { return getTokens(LogicParser.IMPLIES); }
		public TerminalNode IMPLIES(int i) {
			return getToken(LogicParser.IMPLIES, i);
		}
		public ImpliesExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_impliesExpr; }
	}

	public final ImpliesExprContext impliesExpr() throws RecognitionException {
		ImpliesExprContext _localctx = new ImpliesExprContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_impliesExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(22);
			orExpr();
			setState(27);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==IMPLIES) {
				{
				{
				setState(23);
				match(IMPLIES);
				setState(24);
				orExpr();
				}
				}
				setState(29);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class OrExprContext extends ParserRuleContext {
		public List<AndExprContext> andExpr() {
			return getRuleContexts(AndExprContext.class);
		}
		public AndExprContext andExpr(int i) {
			return getRuleContext(AndExprContext.class,i);
		}
		public List<TerminalNode> OR() { return getTokens(LogicParser.OR); }
		public TerminalNode OR(int i) {
			return getToken(LogicParser.OR, i);
		}
		public OrExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_orExpr; }
	}

	public final OrExprContext orExpr() throws RecognitionException {
		OrExprContext _localctx = new OrExprContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_orExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(30);
			andExpr();
			setState(35);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0 || _la==OR) {
				{
				{
				setState(31);
				_la = _input.LA(1);
				if ( !(_la==T__0 || _la==OR) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(32);
				andExpr();
				}
				}
				setState(37);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AndExprContext extends ParserRuleContext {
		public List<AtomContext> atom() {
			return getRuleContexts(AtomContext.class);
		}
		public AtomContext atom(int i) {
			return getRuleContext(AtomContext.class,i);
		}
		public List<TerminalNode> AND() { return getTokens(LogicParser.AND); }
		public TerminalNode AND(int i) {
			return getToken(LogicParser.AND, i);
		}
		public AndExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_andExpr; }
	}

	public final AndExprContext andExpr() throws RecognitionException {
		AndExprContext _localctx = new AndExprContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_andExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(38);
			atom();
			setState(43);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__1 || _la==AND) {
				{
				{
				setState(39);
				_la = _input.LA(1);
				if ( !(_la==T__1 || _la==AND) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(40);
				atom();
				}
				}
				setState(45);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AtomContext extends ParserRuleContext {
		public TerminalNode VARIABLE() { return getToken(LogicParser.VARIABLE, 0); }
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public TerminalNode NOT() { return getToken(LogicParser.NOT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_atom; }
	}

	public final AtomContext atom() throws RecognitionException {
		AtomContext _localctx = new AtomContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_atom);
		int _la;
		try {
			setState(53);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VARIABLE:
				enterOuterAlt(_localctx, 1);
				{
				setState(46);
				match(VARIABLE);
				}
				break;
			case T__2:
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(47);
				_la = _input.LA(1);
				if ( !(_la==T__2 || _la==NOT) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(48);
				atom();
				}
				break;
			case T__3:
				enterOuterAlt(_localctx, 3);
				{
				setState(49);
				match(T__3);
				setState(50);
				expr();
				setState(51);
				match(T__4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\f8\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0005\u0001\u0012\b\u0001\n\u0001\f\u0001\u0015\t\u0001\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0005\u0002\u001a\b\u0002\n\u0002\f\u0002\u001d"+
		"\t\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0005\u0003\"\b\u0003\n\u0003"+
		"\f\u0003%\t\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0005\u0004*\b\u0004"+
		"\n\u0004\f\u0004-\t\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u00056\b\u0005\u0001\u0005"+
		"\u0000\u0000\u0006\u0000\u0002\u0004\u0006\b\n\u0000\u0003\u0002\u0000"+
		"\u0001\u0001\t\t\u0002\u0000\u0002\u0002\b\b\u0002\u0000\u0003\u0003\u0007"+
		"\u00077\u0000\f\u0001\u0000\u0000\u0000\u0002\u000e\u0001\u0000\u0000"+
		"\u0000\u0004\u0016\u0001\u0000\u0000\u0000\u0006\u001e\u0001\u0000\u0000"+
		"\u0000\b&\u0001\u0000\u0000\u0000\n5\u0001\u0000\u0000\u0000\f\r\u0003"+
		"\u0002\u0001\u0000\r\u0001\u0001\u0000\u0000\u0000\u000e\u0013\u0003\u0004"+
		"\u0002\u0000\u000f\u0010\u0005\u000b\u0000\u0000\u0010\u0012\u0003\u0004"+
		"\u0002\u0000\u0011\u000f\u0001\u0000\u0000\u0000\u0012\u0015\u0001\u0000"+
		"\u0000\u0000\u0013\u0011\u0001\u0000\u0000\u0000\u0013\u0014\u0001\u0000"+
		"\u0000\u0000\u0014\u0003\u0001\u0000\u0000\u0000\u0015\u0013\u0001\u0000"+
		"\u0000\u0000\u0016\u001b\u0003\u0006\u0003\u0000\u0017\u0018\u0005\n\u0000"+
		"\u0000\u0018\u001a\u0003\u0006\u0003\u0000\u0019\u0017\u0001\u0000\u0000"+
		"\u0000\u001a\u001d\u0001\u0000\u0000\u0000\u001b\u0019\u0001\u0000\u0000"+
		"\u0000\u001b\u001c\u0001\u0000\u0000\u0000\u001c\u0005\u0001\u0000\u0000"+
		"\u0000\u001d\u001b\u0001\u0000\u0000\u0000\u001e#\u0003\b\u0004\u0000"+
		"\u001f \u0007\u0000\u0000\u0000 \"\u0003\b\u0004\u0000!\u001f\u0001\u0000"+
		"\u0000\u0000\"%\u0001\u0000\u0000\u0000#!\u0001\u0000\u0000\u0000#$\u0001"+
		"\u0000\u0000\u0000$\u0007\u0001\u0000\u0000\u0000%#\u0001\u0000\u0000"+
		"\u0000&+\u0003\n\u0005\u0000\'(\u0007\u0001\u0000\u0000(*\u0003\n\u0005"+
		"\u0000)\'\u0001\u0000\u0000\u0000*-\u0001\u0000\u0000\u0000+)\u0001\u0000"+
		"\u0000\u0000+,\u0001\u0000\u0000\u0000,\t\u0001\u0000\u0000\u0000-+\u0001"+
		"\u0000\u0000\u0000.6\u0005\u0006\u0000\u0000/0\u0007\u0002\u0000\u0000"+
		"06\u0003\n\u0005\u000012\u0005\u0004\u0000\u000023\u0003\u0000\u0000\u0000"+
		"34\u0005\u0005\u0000\u000046\u0001\u0000\u0000\u00005.\u0001\u0000\u0000"+
		"\u00005/\u0001\u0000\u0000\u000051\u0001\u0000\u0000\u00006\u000b\u0001"+
		"\u0000\u0000\u0000\u0005\u0013\u001b#+5";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}