%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "symboltable.h"

extern int yylex();
extern int yylineno;

void yyerror(const char *s);

int function_count = 0;

extern ProgramNode* root;
extern SymbolTable globalSymbolTable;
FunctionNode* currentFunction = nullptr;
%}

%union {
    int ival;
    float fval;
    char* sval;
}

%token INT FLOAT DOUBLE CHAR VOID
%token IF ELSE WHILE FOR RETURN

%token PLUS MINUS MUL DIV
%token ASSIGN

%token EQ NEQ LT GT LE GE

%token LPAREN RPAREN
%token LBRACE RBRACE

%token SEMICOLON COMMA

%token <sval> IDENTIFIER
%token <ival> INT_CONST
%token <fval> FLOAT_CONST

%type <sval> type
%type <sval> expression

%right ASSIGN
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left MUL DIV

%%

program
    : function_list
    ;

function_list
    : function
    | function_list function
    ;

function
    : type IDENTIFIER
      {
          currentFunction =
              new FunctionNode($1, $2);

          root->addFunction(
              currentFunction
          );

          globalSymbolTable.insert(
              $2,
              $1,
              "global"
          );
      }
      LPAREN parameter_list RPAREN
      LBRACE statement_list RBRACE
      {
          function_count++;

          currentFunction = nullptr;
      }
    ;

type
    : INT      { $$ = strdup("int"); }
    | FLOAT    { $$ = strdup("float"); }
    | DOUBLE   { $$ = strdup("double"); }
    | CHAR     { $$ = strdup("char"); }
    | VOID     { $$ = strdup("void"); }
    ;

parameter_list
    :
    | parameters
    ;

parameters
    : parameter
    | parameters COMMA parameter
    ;

parameter
    : type IDENTIFIER
      {
          if(currentFunction)
          {
              currentFunction->addParameter(
                  new ParameterNode(
                      $1,
                      $2
                  )
              );

              globalSymbolTable.addParameter(
                  currentFunction->functionName,
                  $1
              );
          }
      }
    ;

statement_list
    :
    | statement_list statement
    ;

statement
    : declaration
    | assignment
    | return_stmt
    | function_call
    | compound_stmt
    | if_stmt
    | while_stmt
    | for_stmt
    ;

compound_stmt
    : LBRACE statement_list RBRACE
    ;

if_stmt
    : IF LPAREN expression RPAREN statement
      %prec LOWER_THAN_ELSE
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      string("if(") +
                      string($3) +
                      ")"
                  )
              );
          }
      }

    | IF LPAREN expression RPAREN statement
      ELSE statement
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      string("if(") +
                      string($3) +
                      ") else"
                  )
              );
          }
      }
    ;

while_stmt
    : WHILE LPAREN expression RPAREN statement
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      string("while(") +
                      string($3) +
                      ")"
                  )
              );
          }
      }
    ;

for_stmt
    : FOR LPAREN expression SEMICOLON
            expression SEMICOLON
            expression RPAREN
            statement
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      "for(...)"
                  )
              );
          }
      }
    ;

declaration
    : type IDENTIFIER SEMICOLON
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      string($1) +
                      " " +
                      string($2) +
                      ";"
                  )
              );
          }
      }

    | type IDENTIFIER ASSIGN expression SEMICOLON
  {
      if(currentFunction)
      {
          currentFunction->addStatement(
              new StatementNode(
                  string($1) +
                  " " +
                  string($2) +
                  " = " +
                  string($4) +
                  ";"
              )
          );
      }
  }
    ;

assignment
    : IDENTIFIER ASSIGN expression SEMICOLON
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      string($1) +
                      " = " +
                      string($3) +
                      ";"
                  )
              );
          }
      }
    ;

return_stmt
    : RETURN expression SEMICOLON
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      string("return ") +
                      string($2) +
                      ";"
                  )
              );
          }
      }

    | RETURN SEMICOLON
  {
      if(currentFunction)
      {
          currentFunction->addStatement(
              new StatementNode(
                  "return;"
              )
          );
      }
  }
    ;

function_call
    : IDENTIFIER LPAREN argument_list RPAREN SEMICOLON
      {
          if(currentFunction)
          {
              currentFunction->addStatement(
                  new StatementNode(
                      string($1) + "(...);"
                  )
              );
          }
      }
    ;

argument_list
    :
    | arguments
    ;

arguments
    : expression
    | arguments COMMA expression
    ;

expression
    : IDENTIFIER
      {
          $$ = strdup($1);
      }

      | IDENTIFIER LPAREN argument_list RPAREN
{
    string temp =
        string($1) + "(...)";

    $$ = strdup(temp.c_str());
}

    | INT_CONST
      {
          char buffer[32];
          sprintf(buffer, "%d", $1);
          $$ = strdup(buffer);
      }

      | IDENTIFIER ASSIGN expression
{
    string temp =
        string($1) + " = " + string($3);

    $$ = strdup(temp.c_str());
}

    | FLOAT_CONST
      {
          char buffer[32];
          sprintf(buffer, "%f", $1);
          $$ = strdup(buffer);
      }

    | expression PLUS expression
      {
          string temp =
              string($1) + " + " + string($3);

          $$ = strdup(temp.c_str());
      }

    | expression MINUS expression
      {
          string temp =
              string($1) + " - " + string($3);

          $$ = strdup(temp.c_str());
      }

    | expression MUL expression
      {
          string temp =
              string($1) + " * " + string($3);

          $$ = strdup(temp.c_str());
      }

    | expression DIV expression
      {
          string temp =
              string($1) + " / " + string($3);

          $$ = strdup(temp.c_str());
      }

    | LPAREN expression RPAREN
      {
          $$ = $2;
      }

      | expression LT expression
{
    string temp =
        string($1) + " < " + string($3);

    $$ = strdup(temp.c_str());
}

| expression GT expression
{
    string temp =
        string($1) + " > " + string($3);

    $$ = strdup(temp.c_str());
}

| expression LE expression
{
    string temp =
        string($1) + " <= " + string($3);

    $$ = strdup(temp.c_str());
}

| expression GE expression
{
    string temp =
        string($1) + " >= " + string($3);

    $$ = strdup(temp.c_str());
}

| expression EQ expression
{
    string temp =
        string($1) + " == " + string($3);

    $$ = strdup(temp.c_str());
}

| expression NEQ expression
{
    string temp =
        string($1) + " != " + string($3);

    $$ = strdup(temp.c_str());
}
    ;

%%

void yyerror(const char *s)
{
    fprintf(stderr,
            "Parser Error: %s at line %d\n",
            s,
            yylineno);
}

int main()
{
    root = new ProgramNode();

    printf("Starting Parsing...\n");

    yyparse();

    printf("\nParsing Successful\n");

root->print();

globalSymbolTable.print();

printf("\nTotal Functions Found: %d\n",
       function_count);

delete root;

return 0;
}