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
     TOK_PRIVATE = 258,
     TOK_PUBLIC = 259,
     TOK_MEMBER = 260,
     TOK_CLASS_NAME = 261,
     TOK_ADD = 262,
     TOK_SUB = 263,
     TOK_TIMES = 264,
     TOK_DIVIDE = 265,
     TOK_LESS = 266,
     TOK_GREATER = 267,
     TOK_EQUAL = 268,
     TOK_NOTEQUAL = 269,
     TOK_AND = 270,
     TOK_OR = 271,
     TOK_BOOLEAN = 272,
     TOK_CHAR = 273,
     TOK_DOUBLE = 274,
     TOK_INT = 275,
     TOK_STRING = 276,
     TOK_VOID = 277,
     TOK_CHAR_LITERAL = 278,
     TOK_BOOL_LITERAL = 279,
     TOK_INT_LITERAL = 280,
     TOK_DOUBLE_LITERAL = 281,
     TOK_STRING_LITERAL = 282,
     TOK_LBRA = 283,
     TOK_RBRA = 284,
     TOK_LPAR = 285,
     TOK_RPAR = 286,
     TOK_SEMI = 287,
     TOK_COMMA = 288,
     TOK_COLON = 289,
     TOK_ASIG = 290,
     TOK_DOT = 291,
     TOK_BREAK = 292,
     TOK_CASE = 293,
     TOK_CLASS = 294,
     TOK_DEFAULT = 295,
     TOK_DO = 296,
     TOK_ELSE = 297,
     TOK_FOR = 298,
     TOK_IF = 299,
     TOK_NEW = 300,
     TOK_OUT = 301,
     TOK_PRINT = 302,
     TOK_RETURN = 303,
     TOK_SWITCH = 304,
     TOK_WHILE = 305,
     TOK_ERROR = 306
   };
#endif
/* Tokens.  */
#define TOK_PRIVATE 258
#define TOK_PUBLIC 259
#define TOK_MEMBER 260
#define TOK_CLASS_NAME 261
#define TOK_ADD 262
#define TOK_SUB 263
#define TOK_TIMES 264
#define TOK_DIVIDE 265
#define TOK_LESS 266
#define TOK_GREATER 267
#define TOK_EQUAL 268
#define TOK_NOTEQUAL 269
#define TOK_AND 270
#define TOK_OR 271
#define TOK_BOOLEAN 272
#define TOK_CHAR 273
#define TOK_DOUBLE 274
#define TOK_INT 275
#define TOK_STRING 276
#define TOK_VOID 277
#define TOK_CHAR_LITERAL 278
#define TOK_BOOL_LITERAL 279
#define TOK_INT_LITERAL 280
#define TOK_DOUBLE_LITERAL 281
#define TOK_STRING_LITERAL 282
#define TOK_LBRA 283
#define TOK_RBRA 284
#define TOK_LPAR 285
#define TOK_RPAR 286
#define TOK_SEMI 287
#define TOK_COMMA 288
#define TOK_COLON 289
#define TOK_ASIG 290
#define TOK_DOT 291
#define TOK_BREAK 292
#define TOK_CASE 293
#define TOK_CLASS 294
#define TOK_DEFAULT 295
#define TOK_DO 296
#define TOK_ELSE 297
#define TOK_FOR 298
#define TOK_IF 299
#define TOK_NEW 300
#define TOK_OUT 301
#define TOK_PRINT 302
#define TOK_RETURN 303
#define TOK_SWITCH 304
#define TOK_WHILE 305
#define TOK_ERROR 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "fictionalOOPLang.y"
{
	char* text;
	Operators oper;
	int typ;
	StValue value;
	StInfoVar *info;
}
/* Line 1529 of yacc.c.  */
#line 159 "fictionalOOPLang.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

