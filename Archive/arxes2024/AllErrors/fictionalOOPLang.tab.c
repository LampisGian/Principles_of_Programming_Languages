/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "fictionalOOPLang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symtab.h"

extern FILE *yyin;
extern int yylineno;
extern char* yytext;
int yylex();
void yyerror(const char* message);

StSymbolTable symTab = {{NULL, NULL, 0}, NULL, NULL};
Datatype dataTyp;
int modifier;
int numbErrors = 0;

void correctProgram(StSymbolTable *symTab);
void incorrectProgram(StSymbolTable *symTab, int line);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 229 "fictionalOOPLang.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 242 "fictionalOOPLang.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNRULES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    20,    23,
      24,    26,    28,    31,    34,    36,    41,    44,    45,    47,
      49,    51,    53,    55,    57,    59,    61,    63,    67,    69,
      73,    75,    79,    82,    84,    95,   106,   109,   110,   112,
     116,   118,   121,   122,   124,   127,   129,   134,   137,   139,
     142,   148,   150,   152,   154,   156,   158,   160,   163,   166,
     169,   172,   176,   180,   188,   198,   205,   213,   224,   232,
     241,   244,   248,   252,   255,   256,   258,   260,   263,   266,
     268,   275,   278,   281,   283,   288,   292,   295,   299,   304,
     309,   312,   313,   315,   319,   321,   325,   327,   331,   333,
     337,   341,   345,   349,   353,   357,   361,   363,   367,   371,
     373,   376,   378,   382,   384,   386,   388,   390,   392,   394,
     396,   398,   400,   402,   404,   406,   410,   412,   416,   418,
     420
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    -1,    54,    -1,     1,    -1,    54,    55,
      -1,    55,    -1,     4,    39,   103,    28,    56,    29,    -1,
       1,    29,    -1,    -1,    57,    -1,    65,    -1,    57,    65,
      -1,    57,    58,    -1,    58,    -1,    59,    61,    63,    32,
      -1,     1,    32,    -1,    -1,    60,    -1,     4,    -1,     3,
      -1,    20,    -1,    18,    -1,    19,    -1,    17,    -1,    21,
      -1,    22,    -1,    63,    33,    64,    -1,    64,    -1,     1,
      33,    64,    -1,   101,    -1,   101,    35,    97,    -1,    65,
      66,    -1,    66,    -1,    59,    61,   102,    30,    67,    31,
      28,    70,    73,    29,    -1,    59,    62,   102,    30,    67,
      31,    28,    70,    73,    29,    -1,     1,    29,    -1,    -1,
      68,    -1,    68,    33,    69,    -1,    69,    -1,    61,   101,
      -1,    -1,    71,    -1,    71,    72,    -1,    72,    -1,    59,
      61,    63,    32,    -1,    73,    74,    -1,    74,    -1,    75,
      32,    -1,   106,   101,    35,    90,    32,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      37,    32,    -1,    91,    32,    -1,     1,    32,    -1,     1,
      29,    -1,   104,    35,    97,    -1,     1,    35,    97,    -1,
      41,    82,    50,    30,    94,    31,    32,    -1,    43,    30,
      75,    32,    94,    32,    75,    31,    82,    -1,    44,    30,
      94,    31,    82,    83,    -1,    49,    30,    97,    31,    28,
      87,    29,    -1,    49,    30,    97,    31,    28,    87,    40,
      34,    73,    29,    -1,    46,    36,    47,    30,    27,    31,
      32,    -1,    46,    36,    47,    30,    27,    89,    31,    32,
      -1,    48,    32,    -1,    48,    97,    32,    -1,    28,    73,
      29,    -1,     1,    29,    -1,    -1,    84,    -1,    86,    -1,
      84,    86,    -1,    84,    85,    -1,    85,    -1,    42,    44,
      30,    94,    31,    82,    -1,    42,    82,    -1,    87,    88,
      -1,    88,    -1,    38,    97,    34,    73,    -1,    89,    33,
     104,    -1,    33,   104,    -1,     1,    33,   104,    -1,    45,
     106,    30,    31,    -1,   105,    30,    92,    31,    -1,     1,
      31,    -1,    -1,    93,    -1,    93,    33,    97,    -1,    97,
      -1,    94,    16,    95,    -1,    95,    -1,    95,    15,    96,
      -1,    96,    -1,    30,    94,    31,    -1,    97,    11,    97,
      -1,    97,    12,    97,    -1,    97,    13,    97,    -1,    97,
      14,    97,    -1,    97,     7,    98,    -1,    97,     8,    98,
      -1,    98,    -1,    98,     9,    99,    -1,    98,    10,    99,
      -1,    99,    -1,     8,   100,    -1,   100,    -1,    30,    97,
      31,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,   104,    -1,    91,    -1,    90,    -1,   107,    -1,
     107,    -1,     6,    -1,   107,    -1,   107,    36,   107,    -1,
     107,    -1,   107,    36,   107,    -1,     6,    -1,     5,    -1,
       6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    55,    56,    59,    60,    63,    64,    67,
      68,    69,    70,    73,    74,    77,    78,    81,    82,    85,
      86,    89,    90,    91,    92,    93,    96,    99,   100,   101,
     104,   105,   108,   109,   112,   113,   114,   117,   118,   121,
     122,   125,   128,   129,   132,   133,   136,   139,   140,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   157,   158,   161,   164,   167,   170,   171,   174,   175,
     178,   179,   182,   183,   186,   187,   188,   189,   192,   193,
     196,   199,   202,   203,   206,   209,   210,   211,   214,   217,
     218,   221,   222,   225,   226,   229,   230,   233,   234,   237,
     238,   239,   240,   241,   244,   245,   246,   249,   250,   251,
     254,   255,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   269,   272,   275,   278,   279,   282,   283,   286,   289,
     290
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PRIVATE", "TOK_PUBLIC",
  "TOK_MEMBER", "TOK_CLASS_NAME", "TOK_ADD", "TOK_SUB", "TOK_TIMES",
  "TOK_DIVIDE", "TOK_LESS", "TOK_GREATER", "TOK_EQUAL", "TOK_NOTEQUAL",
  "TOK_AND", "TOK_OR", "TOK_BOOLEAN", "TOK_CHAR", "TOK_DOUBLE", "TOK_INT",
  "TOK_STRING", "TOK_VOID", "TOK_CHAR_LITERAL", "TOK_BOOL_LITERAL",
  "TOK_INT_LITERAL", "TOK_DOUBLE_LITERAL", "TOK_STRING_LITERAL",
  "TOK_LBRA", "TOK_RBRA", "TOK_LPAR", "TOK_RPAR", "TOK_SEMI", "TOK_COMMA",
  "TOK_COLON", "TOK_ASIG", "TOK_DOT", "TOK_BREAK", "TOK_CASE", "TOK_CLASS",
  "TOK_DEFAULT", "TOK_DO", "TOK_ELSE", "TOK_FOR", "TOK_IF", "TOK_NEW",
  "TOK_OUT", "TOK_PRINT", "TOK_RETURN", "TOK_SWITCH", "TOK_WHILE",
  "TOK_ERROR", "$accept", "Input", "Classes", "Class", "OptionalMethods",
  "Variables", "Variable", "OptionalModifier", "Modifier", "DataType",
  "VoidType", "MultipleVariables", "SimpleVariable", "Methods", "Method",
  "OptionalParameters", "Parameters", "Parameter", "OptionalVariables",
  "VariablesFunct", "VariableFunct", "Commands", "Command", "Assignment",
  "DoLoop", "ForLoop", "IfControl", "SwitchControl", "OutPrint",
  "ReturnVal", "CommandBlock", "OptionalElseifs", "ElseIfs", "ElseIf",
  "Else", "Cases", "Case", "UseVariables", "NewObject", "MethodCall",
  "OptionalArguments", "Arguments", "Condition", "Logical", "Relation",
  "Expression", "Term", "Minus", "Primary", "InitVariable", "InitFunction",
  "InitClass", "UseVariable", "UseFunction", "UseClass", "Identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    62,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    68,
      68,    69,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    86,    87,    87,    88,    89,    89,    89,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    97,    97,    97,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   102,   103,   104,   104,   105,   105,   106,   107,
     107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     6,     2,     0,
       1,     1,     2,     2,     1,     4,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     2,     1,    10,    10,     2,     0,     1,     3,
       1,     2,     0,     1,     2,     1,     4,     2,     1,     2,
       5,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     3,     7,     9,     6,     7,    10,     7,     8,
       2,     3,     3,     2,     0,     1,     1,     2,     2,     1,
       6,     2,     2,     1,     4,     3,     2,     3,     4,     4,
       2,     0,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     6,     8,     0,     1,     0,
       5,   123,     0,     0,     0,    20,    19,     0,     0,    14,
       0,    18,     0,    33,    36,    16,     7,    13,     0,    24,
      22,    23,    21,    25,    26,     0,     0,     0,     0,    32,
       0,   129,   130,     0,    28,    30,     0,   121,     0,   122,
       0,     0,    15,     0,     0,    37,    37,    29,   121,    27,
       0,     0,   113,   114,   115,   116,   117,     0,     0,   120,
     119,    31,   106,   109,   111,   118,     0,   124,     0,     0,
      38,    40,     0,    90,   110,     0,   128,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,   112,     0,
     104,   105,   107,   108,     0,    92,    94,   125,    42,    39,
      42,    88,    89,     0,     0,     0,    43,    45,     0,    93,
       0,     0,   130,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    51,    52,    53,    54,    55,    56,     0,
       0,     0,    44,     0,     0,    60,    59,     0,    57,     0,
       0,     0,     0,     0,     0,    70,     0,     0,    34,    47,
      49,    58,     0,     0,    35,    46,    62,    73,     0,     0,
       0,     0,   124,     0,     0,    96,    98,     0,     0,    71,
       0,    61,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,    99,    95,    74,    97,   100,   101,   102,   103,
       0,     0,    50,     0,     0,     0,    65,    75,    79,    76,
       0,     0,     0,     0,     0,     0,    83,    63,     0,     0,
      81,    78,    77,     0,    68,    86,     0,     0,     0,    66,
       0,    82,     0,     0,    87,    69,    85,     0,     0,    64,
       0,     0,     0,     0,    67,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    17,    18,    19,   114,    21,    78,
      36,    43,    44,    22,    23,    79,    80,    81,   115,   116,
     117,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     151,   216,   217,   218,   219,   225,   226,   223,    69,    70,
     104,   105,   174,   175,   176,   177,    72,    73,    74,    45,
      46,    12,    75,    76,   141,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -183
static const yytype_int16 yypact[] =
{
     261,    -2,    -7,    36,   281,  -183,  -183,    43,  -183,    -2,
    -183,  -183,    44,   349,    82,  -183,  -183,    62,   355,  -183,
     372,  -183,   378,  -183,  -183,  -183,  -183,  -183,   384,  -183,
    -183,  -183,  -183,  -183,  -183,    68,    56,   102,   372,  -183,
      53,  -183,  -183,    89,  -183,    42,   120,   131,   136,  -183,
      56,    56,  -183,    56,   310,   225,   225,  -183,  -183,  -183,
      85,    75,  -183,  -183,  -183,  -183,  -183,   310,   133,  -183,
    -183,   165,   175,  -183,  -183,  -183,   147,    99,    56,   150,
     153,  -183,   159,  -183,  -183,    48,  -183,   166,   310,   310,
     310,   310,   269,    56,  -183,   181,   225,   189,  -183,   188,
     175,   175,  -183,  -183,   191,   194,   165,   200,   405,  -183,
     405,  -183,  -183,   310,   225,    46,   405,  -183,    46,   165,
      68,   105,   198,   218,    20,   227,   233,   232,   278,   243,
     164,  -183,   244,  -183,  -183,  -183,  -183,  -183,  -183,   246,
     245,    56,  -183,   177,   201,  -183,  -183,   310,  -183,   258,
      46,   238,   170,   319,   242,  -183,    21,   310,  -183,  -183,
    -183,  -183,   310,   255,  -183,  -183,   165,  -183,   210,   267,
     256,   266,   270,   319,    14,   292,  -183,   403,   279,  -183,
      57,   165,   268,  -183,   319,   319,    56,    77,   224,   319,
      20,   319,   310,   310,   310,   310,   285,   289,   287,    87,
      -6,  -183,  -183,   292,   280,  -183,   165,   165,   165,   165,
       8,   283,  -183,   294,   170,    10,  -183,   280,  -183,  -183,
     295,   297,    56,   115,   310,    86,  -183,  -183,   299,   301,
    -183,  -183,  -183,    56,  -183,  -183,   300,    56,     6,  -183,
     304,  -183,    20,   319,  -183,  -183,  -183,    46,    46,  -183,
      94,   151,   223,    20,  -183,  -183
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,   335,  -183,  -183,   323,    91,  -183,   -18,
    -183,   228,   109,   329,   119,   298,  -183,   264,   241,  -183,
     247,  -115,  -124,  -147,  -183,  -183,  -183,  -183,  -183,  -183,
    -182,  -183,  -183,   140,   144,  -183,   137,  -183,   183,   -93,
    -183,  -183,  -161,   197,   192,   -50,   152,   158,   351,   -71,
     344,  -183,   -84,  -183,   350,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -129
static const yytype_int16 yytable[] =
{
      47,    49,    35,   143,    71,   171,   159,    94,   204,   220,
     189,   149,   187,    88,    89,    49,    58,    85,    58,   159,
      50,   149,   139,   199,   200,   139,   214,     6,    88,    89,
     189,   140,     7,   230,   140,   168,     8,   139,   150,   221,
     247,   222,   106,    58,   159,   190,   140,   121,   150,    11,
     139,    41,   122,   179,   229,    88,    89,   139,   107,   140,
     249,    41,    42,   119,    88,    89,   140,   228,   140,    40,
     163,   255,    13,    41,    42,   139,    60,    54,   156,    98,
      41,    42,   250,   123,   140,    58,    51,   124,   197,   125,
     126,    26,   127,   189,   128,   129,   120,   166,    62,    63,
      64,    65,    66,   189,    20,    67,    58,   180,   202,    20,
     189,    24,   181,    38,    25,   239,    83,   172,   213,    38,
      68,    52,    53,   188,   224,   253,   240,   159,   159,  -126,
     140,    24,   251,   252,   145,    93,    83,   146,   235,    86,
     147,    39,   206,   207,   208,   209,   236,    39,   237,   244,
      55,   201,   121,   246,   139,   139,    41,   122,   139,   139,
      57,  -122,    59,   140,   140,   121,    56,   140,   140,    41,
     122,   170,    88,    89,   238,    41,    42,    92,   121,   172,
     -84,    95,    41,   122,    90,    91,    96,   172,   123,   -84,
      97,   -84,   124,   158,   125,   126,    99,   127,   172,   128,
     129,   123,   172,  -128,  -128,   124,   164,   125,   126,   108,
     127,   121,   128,   129,   123,    41,   122,   110,   124,   111,
     125,   126,   112,   127,   121,   128,   129,   113,    41,   122,
    -127,    88,    89,   165,    53,   192,   193,   194,   195,   183,
     100,   101,    29,    30,    31,    32,    33,   123,   102,   103,
     148,   124,   254,   125,   126,    98,   127,   152,   128,   129,
     123,    -2,     1,   153,   124,     2,   125,   126,   154,   127,
      60,   128,   129,   157,    41,    42,   160,    61,   161,    60,
     162,    -3,     9,    41,    42,     2,    61,   167,   169,   178,
     182,   147,    62,    63,    64,    65,    66,   184,   185,    67,
     -91,    62,    63,    64,    65,    66,   186,   191,    67,   196,
     155,    60,   210,    68,    68,    41,    42,   211,    61,   212,
      60,   224,   215,    68,    41,    42,   227,    61,   233,   234,
     242,   243,   245,    62,    63,    64,    65,    66,   248,    10,
      67,    27,    62,    63,    64,    65,    66,    28,   144,   173,
      14,   118,    15,    16,    82,    68,    14,   231,    15,    16,
     109,   232,   241,   142,    68,   198,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,    -9,    37,
      48,    15,    16,   205,   -10,    37,   203,    15,    16,    29,
      30,    31,    32,    33,    34,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -11,    15,    16,
      88,    89,    84,   -12,   192,   193,   194,   195,    87,     0,
       0,     0,   -17,   -17,   -17,   -17,   -17
};

static const yytype_int16 yycheck[] =
{
      35,    36,    20,   118,    54,   152,   130,    78,   190,     1,
      16,     1,   173,     7,     8,    50,    51,    67,    53,   143,
      38,     1,   115,   184,   185,   118,    32,    29,     7,     8,
      16,   115,    39,   215,   118,   150,     0,   130,    28,    31,
      34,    33,    92,    78,   168,    31,   130,     1,    28,     6,
     143,     5,     6,    32,    44,     7,     8,   150,    93,   143,
     242,     5,     6,   113,     7,     8,   150,   214,   152,     1,
     141,   253,    28,     5,     6,   168,     1,    35,   128,    31,
       5,     6,   243,    37,   168,   120,    33,    41,    31,    43,
      44,    29,    46,    16,    48,    49,   114,   147,    23,    24,
      25,    26,    27,    16,    13,    30,   141,   157,    31,    18,
      16,    29,   162,    22,    32,    29,    31,   152,    31,    28,
      45,    32,    33,   173,    38,    31,    40,   251,   252,    30,
     214,    29,   247,   248,    29,    36,    31,    32,   222,     6,
      35,    22,   192,   193,   194,   195,    31,    28,    33,   233,
      30,   186,     1,   237,   247,   248,     5,     6,   251,   252,
      51,    30,    53,   247,   248,     1,    30,   251,   252,     5,
       6,     1,     7,     8,   224,     5,     6,    30,     1,   214,
      29,    31,     5,     6,     9,    10,    33,   222,    37,    38,
      31,    40,    41,    29,    43,    44,    30,    46,   233,    48,
      49,    37,   237,     5,     6,    41,    29,    43,    44,    28,
      46,     1,    48,    49,    37,     5,     6,    28,    41,    31,
      43,    44,    31,    46,     1,    48,    49,    33,     5,     6,
      30,     7,     8,    32,    33,    11,    12,    13,    14,    29,
      88,    89,    17,    18,    19,    20,    21,    37,    90,    91,
      32,    41,    29,    43,    44,    31,    46,    30,    48,    49,
      37,     0,     1,    30,    41,     4,    43,    44,    36,    46,
       1,    48,    49,    30,     5,     6,    32,     8,    32,     1,
      35,     0,     1,     5,     6,     4,     8,    29,    50,    47,
      35,    35,    23,    24,    25,    26,    27,    30,    32,    30,
      31,    23,    24,    25,    26,    27,    36,    15,    30,    30,
      32,     1,    27,    45,    45,     5,     6,    28,     8,    32,
       1,    38,    42,    45,     5,     6,    32,     8,    33,    32,
      31,    30,    32,    23,    24,    25,    26,    27,    34,     4,
      30,    18,    23,    24,    25,    26,    27,    18,   120,    30,
       1,   110,     3,     4,    56,    45,     1,   217,     3,     4,
      96,   217,   225,   116,    45,   182,    17,    18,    19,    20,
      21,    22,    17,    18,    19,    20,    21,    22,    29,     1,
      36,     3,     4,   191,    29,     1,   189,     3,     4,    17,
      18,    19,    20,    21,    22,    17,    18,    19,    20,    21,
      22,    17,    18,    19,    20,    21,    22,    29,     3,     4,
       7,     8,    61,    29,    11,    12,    13,    14,    68,    -1,
      -1,    -1,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,    53,    54,    55,    29,    39,     0,     1,
      55,     6,   103,    28,     1,     3,     4,    56,    57,    58,
      59,    60,    65,    66,    29,    32,    29,    58,    65,    17,
      18,    19,    20,    21,    22,    61,    62,     1,    59,    66,
       1,     5,     6,    63,    64,   101,   102,   107,   102,   107,
      61,    33,    32,    33,    35,    30,    30,    64,   107,    64,
       1,     8,    23,    24,    25,    26,    27,    30,    45,    90,
      91,    97,    98,    99,   100,   104,   105,   107,    61,    67,
      68,    69,    67,    31,   100,    97,     6,   106,     7,     8,
       9,    10,    30,    36,   101,    31,    33,    31,    31,    30,
      98,    98,    99,    99,    92,    93,    97,   107,    28,    69,
      28,    31,    31,    33,    59,    70,    71,    72,    70,    97,
      61,     1,     6,    37,    41,    43,    44,    46,    48,    49,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    91,
     104,   106,    72,    73,    63,    29,    32,    35,    32,     1,
      28,    82,    30,    30,    36,    32,    97,    30,    29,    74,
      32,    32,    35,   101,    29,    32,    97,    29,    73,    50,
       1,    75,   107,    30,    94,    95,    96,    97,    47,    32,
      97,    97,    35,    29,    30,    32,    36,    94,    97,    16,
      31,    15,    11,    12,    13,    14,    30,    31,    90,    94,
      94,   107,    31,    95,    82,    96,    97,    97,    97,    97,
      27,    28,    32,    31,    32,    42,    83,    84,    85,    86,
       1,    31,    33,    89,    38,    87,    88,    32,    75,    44,
      82,    85,    86,    33,    32,   104,    31,    33,    97,    29,
      40,    88,    31,    30,   104,    32,   104,    34,    34,    82,
      94,    73,    73,    31,    29,    82
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 55 "fictionalOOPLang.y"
    { correctProgram(&symTab); ;}
    break;

  case 4:
#line 56 "fictionalOOPLang.y"
    { incorrectProgram(&symTab, yylineno); ;}
    break;

  case 7:
#line 63 "fictionalOOPLang.y"
    { symTab.ptrClass = NULL; ;}
    break;

  case 8:
#line 64 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 16:
#line 78 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 17:
#line 81 "fictionalOOPLang.y"
    { modifier = 1; ;}
    break;

  case 18:
#line 82 "fictionalOOPLang.y"
    { modifier = !strcmp((yyvsp[(1) - (1)].text), "public");  ;}
    break;

  case 21:
#line 89 "fictionalOOPLang.y"
    { dataTyp = (yyvsp[(1) - (1)].typ); ;}
    break;

  case 22:
#line 90 "fictionalOOPLang.y"
    { dataTyp = (yyvsp[(1) - (1)].typ); ;}
    break;

  case 23:
#line 91 "fictionalOOPLang.y"
    { dataTyp = (yyvsp[(1) - (1)].typ); ;}
    break;

  case 24:
#line 92 "fictionalOOPLang.y"
    { dataTyp = (yyvsp[(1) - (1)].typ); ;}
    break;

  case 25:
#line 93 "fictionalOOPLang.y"
    { dataTyp = (yyvsp[(1) - (1)].typ); ;}
    break;

  case 26:
#line 96 "fictionalOOPLang.y"
    { dataTyp = (yyvsp[(1) - (1)].typ); ;}
    break;

  case 29:
#line 101 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 30:
#line 104 "fictionalOOPLang.y"
    { assignVar(&symTab, (yyvsp[(1) - (1)].text), modifier, convertToStValue(0, 0, dataTyp)); ;}
    break;

  case 31:
#line 105 "fictionalOOPLang.y"
    { StInfoVar* ptrVar = assignVar(&symTab, (yyvsp[(1) - (3)].text), modifier, convertToStValue(0, 0, dataTyp)); showMessVariable(&symTab, ptrVar, (yyvsp[(3) - (3)].value), yylineno); ;}
    break;

  case 34:
#line 112 "fictionalOOPLang.y"
    { resetFunc(&symTab); ;}
    break;

  case 35:
#line 113 "fictionalOOPLang.y"
    { resetFunc(&symTab); ;}
    break;

  case 36:
#line 114 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 41:
#line 125 "fictionalOOPLang.y"
    { assignVar(&symTab, (yyvsp[(2) - (2)].text), 0, convertToStValue(0, 1, (yyvsp[(1) - (2)].typ))); ;}
    break;

  case 50:
#line 144 "fictionalOOPLang.y"
    { assignVar(&symTab, (yyvsp[(2) - (5)].text), 0, convertToStValue(0, 1, (yyvsp[(1) - (5)].typ))); ;}
    break;

  case 59:
#line 153 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 60:
#line 154 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 61:
#line 157 "fictionalOOPLang.y"
    { showMessVariable(&symTab, (yyvsp[(1) - (3)].info), (yyvsp[(3) - (3)].value), yylineno); ;}
    break;

  case 62:
#line 158 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 73:
#line 183 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 87:
#line 211 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 88:
#line 214 "fictionalOOPLang.y"
    { (yyval.typ) = (yyvsp[(2) - (4)].typ); ;}
    break;

  case 90:
#line 218 "fictionalOOPLang.y"
    { yyerrok; incorrectProgram(&symTab, yylineno); ;}
    break;

  case 95:
#line 229 "fictionalOOPLang.y"
    { (yyval.value) = evaluateLogical((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 97:
#line 233 "fictionalOOPLang.y"
    { (yyval.value) = evaluateLogical((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 99:
#line 237 "fictionalOOPLang.y"
    { (yyval.value) = (yyvsp[(2) - (3)].value); ;}
    break;

  case 100:
#line 238 "fictionalOOPLang.y"
    { (yyval.value) = evaluateRelational((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 101:
#line 239 "fictionalOOPLang.y"
    { (yyval.value) = evaluateRelational((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 102:
#line 240 "fictionalOOPLang.y"
    { (yyval.value) = evaluateRelational((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 103:
#line 241 "fictionalOOPLang.y"
    { (yyval.value) = evaluateRelational((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 104:
#line 244 "fictionalOOPLang.y"
    { (yyval.value) = evaluateArithmetic((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 105:
#line 245 "fictionalOOPLang.y"
    { (yyval.value) = evaluateArithmetic((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 107:
#line 249 "fictionalOOPLang.y"
    { (yyval.value) = evaluateArithmetic((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 108:
#line 250 "fictionalOOPLang.y"
    { (yyval.value) = evaluateArithmetic((yyvsp[(1) - (3)].value), (yyvsp[(2) - (3)].oper), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 110:
#line 254 "fictionalOOPLang.y"
    { (yyval.value) = evaluateArithmetic(convertToStValue(0, 1, INT_TYPE), (yyvsp[(1) - (2)].oper), (yyvsp[(2) - (2)].value)); ;}
    break;

  case 112:
#line 258 "fictionalOOPLang.y"
    { (yyval.value) = (yyvsp[(2) - (3)].value); ;}
    break;

  case 118:
#line 264 "fictionalOOPLang.y"
    { (yyval.value) = getStValueFromStInfoVar((yyvsp[(1) - (1)].info)); ;}
    break;

  case 119:
#line 265 "fictionalOOPLang.y"
    { (yyval.value) = convertToStValue(0, 1, (yyvsp[(1) - (1)].typ)); ;}
    break;

  case 120:
#line 266 "fictionalOOPLang.y"
    { (yyval.value) = convertToStValue(0, 1, (yyvsp[(1) - (1)].typ)); ;}
    break;

  case 121:
#line 269 "fictionalOOPLang.y"
    { checkDuplicateVar(&symTab, (yyvsp[(1) - (1)].text), yylineno); ;}
    break;

  case 122:
#line 272 "fictionalOOPLang.y"
    { checkInsertFunc(&symTab, (yyvsp[(1) - (1)].text),modifier, dataTyp, yylineno); ;}
    break;

  case 123:
#line 275 "fictionalOOPLang.y"
    { checkInsertClass(&symTab, (yyvsp[(1) - (1)].text), yylineno); ;}
    break;

  case 124:
#line 278 "fictionalOOPLang.y"
    { (yyval.info) = checkUndeclaredVar(&symTab, (yyvsp[(1) - (1)].text), NULL, yylineno); ;}
    break;

  case 125:
#line 279 "fictionalOOPLang.y"
    { (yyval.info) = checkUndeclaredVar(&symTab, (yyvsp[(3) - (3)].text), (yyvsp[(1) - (3)].text), yylineno); ;}
    break;

  case 126:
#line 282 "fictionalOOPLang.y"
    { (yyval.typ) = checkUndeclaredFunc(&symTab, (yyvsp[(1) - (1)].text), NULL, yylineno); ;}
    break;

  case 127:
#line 283 "fictionalOOPLang.y"
    { (yyval.typ) = checkUndeclaredFunc(&symTab, (yyvsp[(3) - (3)].text), (yyvsp[(1) - (3)].text), yylineno); ;}
    break;

  case 128:
#line 286 "fictionalOOPLang.y"
    { (yyval.typ) = checkUndeclaredClass(&symTab, (yyvsp[(1) - (1)].text), yylineno); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1978 "fictionalOOPLang.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 293 "fictionalOOPLang.y"


void yyerror(const char *s) {
	/* Commented out because we use our own error handler. */
	
	//printf("\tError in: %s on line %d.\n", s, yylineno);
	//printf("Error: Input cannot be parsed on line %d.\n", yylineno);
	//printf("%d: %s at '%s'\n", yylineno, s, yytext);
}

void correctProgram(StSymbolTable *symTab)
{
	if ((symTab->numbErrors) == 0) {
		printf("The program is syntactically CORRECT\n");
	}

	/*printf("START---\n");
	printClass(&(symTab->listClass));
	printf("END---\n");*/

	endProgram(symTab);
}

void incorrectProgram(StSymbolTable *symTab, int line)
{
	printf("Error: Input CANNOT BE PARSED on line %d.\n", line);

	endProgram(symTab);
}

int main(int argc, char *argv[]) {

	if (argc >= 2) {
		yyin = fopen(argv[1], "r");
		if (yyin == NULL) {
			yyin = stdin;
			printf("Error: Opening file %s\n", argv[1]);
		} else {
			yyparse();
		  
			if (yyin != NULL) {
				fclose(yyin);
			}
		}		
	} else {
		printf("Error: Missing parameter\n");
	}

	return 0;
}


