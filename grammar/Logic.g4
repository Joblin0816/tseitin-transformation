grammar Logic;

expr: iffExpr;

iffExpr: impliesExpr (IFF impliesExpr)*;
impliesExpr: orExpr (IMPLIES orExpr)*;
orExpr: andExpr ((OR | '∨') andExpr)*;
andExpr: atom ((AND | '∧') atom)*;
atom
    : VARIABLE
    | (NOT | '¬') atom
    | '(' expr ')'
    ;

VARIABLE: [a-zA-Z]+;

NOT: 'NOT' | '¬';
AND: 'AND' | '∧';
OR: 'OR' | '∨';
IMPLIES: 'IMPLIES' | '→';
IFF: 'IFF' | '↔';

WS: [ \t\r\n]+ -> skip;
