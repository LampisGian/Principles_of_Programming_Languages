
%option noyywrap

%option yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symtab.h"

#include "fictionalOOPLang.tab.h"

%}
%x SINGLELINE MULTILINE
%{

%}

 /* Definition of names. */

white       [ \t\n\r]+
integer     [0-9]+
exponent    [eE][+-]?{integer}
real        {integer}?("."{integer})?{exponent}?"d"
character   \'([^'\\]|\\['"?\\abfnrtv0])\'
string      \"(\\.|[^\"])*\"
class       [A-Z][a-zA-Z0-9_]*
member      [a-zA-Z_][a-zA-Z0-9_]*
bool        ("true"|"false")

%%
 
<INITIAL>"//"         { BEGIN(SINGLELINE); }
<SINGLELINE>.*        { /* Nothing to do */ }
<SINGLELINE><<EOF>>   { yyterminate(); }
<SINGLELINE>"\n"      { BEGIN(INITIAL); }
 
<INITIAL>"/*"         { BEGIN(MULTILINE); }
<MULTILINE>(.|\n)     { /* Nothing to do */ }
<MULTILINE><<EOF>>    { yyterminate(); }
<MULTILINE>"*/"       { BEGIN(INITIAL); }

{white}     { }

"{"    { return TOK_LBRA; }
"}"    { return TOK_RBRA; }
"("    { return TOK_LPAR; }
")"    { return TOK_RPAR; }
";"    { return TOK_SEMI; }
","    { return TOK_COMMA; }
":"    { return TOK_COLON; }
"="    { return TOK_ASIG; }
"."    { return TOK_DOT; }
"+"    { yylval.oper = ADD; return TOK_ADD; }
"-"    { yylval.oper = SUB; return TOK_SUB; }
"*"    { yylval.oper = TIMES; return TOK_TIMES; }
"/"    { yylval.oper = DIVIDE; return TOK_DIVIDE; }
"<"    { yylval.oper = LESS; return TOK_LESS; }
">"    { yylval.oper = GREATER; return TOK_GREATER; }
"=="   { yylval.oper = EQUAL; return TOK_EQUAL; }
"!="   { yylval.oper = NOTEQUAL; return TOK_NOTEQUAL; }
"&&"   { yylval.oper = AND; return TOK_AND; }
"||"   { yylval.oper = OR; return TOK_OR; }

"break"      { return TOK_BREAK; }
"boolean"    { yylval.typ = BOOL_TYPE; return TOK_BOOLEAN; }
"case"       { return TOK_CASE; }
"char"       { yylval.typ = CHAR_TYPE; return TOK_CHAR; }
"class"      { return TOK_CLASS; }
"default"    { return TOK_DEFAULT; }
"do"         { return TOK_DO; }
"double"     { yylval.typ = DOUBLE_TYPE; return TOK_DOUBLE; }
"else"       { return TOK_ELSE; }
"for"        { return TOK_FOR; }
"if"         { return TOK_IF; }
"int"        { yylval.typ = INT_TYPE; return TOK_INT; }
"new"        { return TOK_NEW; }
"out"        { return TOK_OUT; }
"print"      { return TOK_PRINT; }
"println"    { return TOK_PRINT; }
"private"    { yylval.text = copyStrDynamic(yytext); return TOK_PRIVATE; }
"public"     { yylval.text = copyStrDynamic(yytext); return TOK_PUBLIC; }
"return"     { return TOK_RETURN; }
"String"     { yylval.typ = STRING_TYPE; return TOK_STRING; }
"switch"     { return TOK_SWITCH; }
"void"       { yylval.typ = VOID_TYPE; return TOK_VOID; }
"while"      { return TOK_WHILE; }

{bool}         { yylval.value = convertToStValue(!strcmp(yytext, "true"), 1, BOOL_TYPE); return TOK_BOOL_LITERAL; }
{class}        { yylval.text = copyStrDynamic(yytext); return TOK_CLASS_NAME; }
{member}       { yylval.text = copyStrDynamic(yytext); return TOK_MEMBER; }
{character}    { yylval.value = convertToStValue(0, 1, CHAR_TYPE); return TOK_CHAR_LITERAL; }
{integer}      { yylval.value = convertToStValue(atoi(yytext), 1, INT_TYPE); return TOK_INT_LITERAL; }
{real}         { yylval.value = convertToStValue(atof(yytext), 1, DOUBLE_TYPE); return TOK_DOUBLE_LITERAL; }
{string}       { yylval.value = convertToStValue(0, 1, STRING_TYPE); return TOK_STRING_LITERAL; }

.           { return TOK_ERROR; }

%%