/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     DOUBLE = 260,
     CHAR = 261,
     VOID = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     RETURN = 267,
     PLUS = 268,
     MINUS = 269,
     MUL = 270,
     DIV = 271,
     ASSIGN = 272,
     EQ = 273,
     NEQ = 274,
     LT = 275,
     GT = 276,
     LE = 277,
     GE = 278,
     LPAREN = 279,
     RPAREN = 280,
     LBRACE = 281,
     RBRACE = 282,
     SEMICOLON = 283,
     COMMA = 284,
     IDENTIFIER = 285,
     INT_CONST = 286,
     FLOAT_CONST = 287,
     LOWER_THAN_ELSE = 288
   };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define DOUBLE 260
#define CHAR 261
#define VOID 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define FOR 266
#define RETURN 267
#define PLUS 268
#define MINUS 269
#define MUL 270
#define DIV 271
#define ASSIGN 272
#define EQ 273
#define NEQ 274
#define LT 275
#define GT 276
#define LE 277
#define GE 278
#define LPAREN 279
#define RPAREN 280
#define LBRACE 281
#define RBRACE 282
#define SEMICOLON 283
#define COMMA 284
#define IDENTIFIER 285
#define INT_CONST 286
#define FLOAT_CONST 287
#define LOWER_THAN_ELSE 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "parser.y"
{
    int ival;
    float fval;
    char* sval;
}
/* Line 1529 of yacc.c.  */
#line 121 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

