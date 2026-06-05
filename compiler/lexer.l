%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
%}

%option noyywrap
%option yylineno

DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+
FLOATNUM    {DIGIT}+"."{DIGIT}+

%%

"int"               { return INT; }
"float"             { return FLOAT; }
"double"            { return DOUBLE; }
"char"              { return CHAR; }
"void"              { return VOID; }

"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"for"               { return FOR; }
"return"            { return RETURN; }

"=="                { return EQ; }
"!="                { return NEQ; }
"<="                { return LE; }
">="                { return GE; }

"="                 { return ASSIGN; }
"<"                 { return LT; }
">"                 { return GT; }

"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"/"                 { return DIV; }

";"                 { return SEMICOLON; }
","                 { return COMMA; }

"("                 { return LPAREN; }
")"                 { return RPAREN; }

"{"                 { return LBRACE; }
"}"                 { return RBRACE; }

{FLOATNUM}          {
                        yylval.fval = atof(yytext);
                        return FLOAT_CONST;
                    }

{NUMBER}            {
                        yylval.ival = atoi(yytext);
                        return INT_CONST;
                    }

{ID}                {
                        yylval.sval = strdup(yytext);
                        return IDENTIFIER;
                    }


"//".*                       { /* ignore single-line comments */ }

[ \t\r\n]+                   { /* ignore whitespace */ }

. {
    printf("Unknown character '%s' at line %d\n",
           yytext,
           yylineno);
}

%%
