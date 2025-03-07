
%{
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

%}

%union {
	char* text;
	Operators oper;
	int typ;
	StValue value;
	StInfoVar *info;
}

/* declare tokens */

%token <text> TOK_PRIVATE TOK_PUBLIC TOK_MEMBER TOK_CLASS_NAME
%token <oper> TOK_ADD TOK_SUB TOK_TIMES TOK_DIVIDE TOK_LESS TOK_GREATER TOK_EQUAL TOK_NOTEQUAL TOK_AND TOK_OR
%token <typ> TOK_BOOLEAN TOK_CHAR TOK_DOUBLE TOK_INT TOK_STRING TOK_VOID
%token <value> TOK_CHAR_LITERAL TOK_BOOL_LITERAL TOK_INT_LITERAL TOK_DOUBLE_LITERAL TOK_STRING_LITERAL

%token TOK_LBRA TOK_RBRA TOK_LPAR TOK_RPAR TOK_SEMI TOK_COMMA TOK_COLON TOK_ASIG TOK_DOT
%token TOK_BREAK TOK_CASE TOK_CLASS TOK_DEFAULT TOK_DO TOK_ELSE TOK_FOR TOK_IF
%token TOK_NEW TOK_OUT TOK_PRINT TOK_RETURN TOK_SWITCH TOK_WHILE
%token TOK_ERROR

%type <text> Modifier InitVariable Identifier InitClass
%type <typ> DataType UseFunction MethodCall UseClass NewObject
%type <value> Condition Logical Relation Expression Term Minus Primary
%type <info> UseVariable

%start Input

%%

Input : /* Empty */
      | Classes { correctProgram(&symTab); }
      | error { incorrectProgram(&symTab, yylineno); }
;

Classes : Classes Class
        | Class
;

Class : TOK_PUBLIC TOK_CLASS InitClass TOK_LBRA OptionalMethods TOK_RBRA { symTab.ptrClass = NULL; }
      | error TOK_RBRA { yyerrok; incorrectProgram(&symTab, yylineno); }
;

OptionalMethods : /* Empty */
                | Variables
                | Methods
                | Variables Methods
;

Variables : Variables Variable
          | Variable
;

Variable : OptionalModifier DataType MultipleVariables TOK_SEMI
         | error TOK_SEMI { yyerrok; incorrectProgram(&symTab, yylineno); }
;

OptionalModifier : /* Empty */ { modifier = 1; }
                 | Modifier { modifier = !strcmp($1, "public");  }
;

Modifier : TOK_PUBLIC
         | TOK_PRIVATE
;

DataType : TOK_INT { dataTyp = $1; }
         | TOK_CHAR { dataTyp = $1; }
         | TOK_DOUBLE { dataTyp = $1; }
         | TOK_BOOLEAN { dataTyp = $1; }
         | TOK_STRING { dataTyp = $1; }
;

VoidType : TOK_VOID { dataTyp = $1; }
;

MultipleVariables : MultipleVariables TOK_COMMA SimpleVariable
                  | SimpleVariable
                  | error TOK_COMMA SimpleVariable { yyerrok; incorrectProgram(&symTab, yylineno); }
;

SimpleVariable : InitVariable { assignVar(&symTab, $1, modifier, convertToStValue(0, 0, dataTyp)); }
               | InitVariable TOK_ASIG Expression { StInfoVar* ptrVar = assignVar(&symTab, $1, modifier, convertToStValue(0, 0, dataTyp)); showMessVariable(&symTab, ptrVar, $3, yylineno); }
;

Methods : Methods Method
        | Method
;

Method : OptionalModifier DataType InitFunction TOK_LPAR OptionalParameters TOK_RPAR TOK_LBRA OptionalVariables Commands TOK_RBRA { resetFunc(&symTab); }
       | OptionalModifier VoidType InitFunction TOK_LPAR OptionalParameters TOK_RPAR TOK_LBRA OptionalVariables Commands TOK_RBRA { resetFunc(&symTab); }
       | error TOK_RBRA { yyerrok; incorrectProgram(&symTab, yylineno); }
;

OptionalParameters : /* Empty */ 
                   | Parameters 
;

Parameters : Parameters TOK_COMMA Parameter
           | Parameter 
;

Parameter : DataType InitVariable { assignVar(&symTab, $2, 0, convertToStValue(0, 1, $1)); }
;

OptionalVariables : /* Empty */
                  | VariablesFunct
;

VariablesFunct : VariablesFunct VariableFunct
               | VariableFunct
;

VariableFunct : OptionalModifier DataType MultipleVariables TOK_SEMI
;

Commands : Commands Command
         | Command
;

Command : Assignment TOK_SEMI
        | UseClass InitVariable TOK_ASIG NewObject TOK_SEMI { assignVar(&symTab, $2, 0, convertToStValue(0, 1, $1)); }
        | DoLoop
        | ForLoop
        | IfControl
        | SwitchControl
        | OutPrint
        | ReturnVal
        | TOK_BREAK TOK_SEMI
        | MethodCall TOK_SEMI
        | error TOK_SEMI { yyerrok; incorrectProgram(&symTab, yylineno); }
        | error TOK_RBRA { yyerrok; incorrectProgram(&symTab, yylineno); }
;

Assignment : UseVariable TOK_ASIG Expression { showMessVariable(&symTab, $1, $3, yylineno); }
        | error TOK_ASIG Expression { yyerrok; incorrectProgram(&symTab, yylineno); }
;

DoLoop : TOK_DO CommandBlock TOK_WHILE TOK_LPAR Condition TOK_RPAR TOK_SEMI
;

ForLoop : TOK_FOR TOK_LPAR Assignment TOK_SEMI Condition TOK_SEMI Assignment TOK_RPAR CommandBlock
;

IfControl : TOK_IF TOK_LPAR Condition TOK_RPAR CommandBlock OptionalElseifs
;

SwitchControl : TOK_SWITCH TOK_LPAR Expression TOK_RPAR TOK_LBRA Cases TOK_RBRA
              | TOK_SWITCH TOK_LPAR Expression TOK_RPAR TOK_LBRA Cases TOK_DEFAULT TOK_COLON Commands TOK_RBRA
;

OutPrint : TOK_OUT TOK_DOT TOK_PRINT TOK_LPAR TOK_STRING_LITERAL TOK_RPAR TOK_SEMI
         | TOK_OUT TOK_DOT TOK_PRINT TOK_LPAR TOK_STRING_LITERAL UseVariables TOK_RPAR TOK_SEMI
;

ReturnVal : TOK_RETURN TOK_SEMI
          | TOK_RETURN Expression TOK_SEMI
;

CommandBlock : TOK_LBRA Commands TOK_RBRA
             | error TOK_RBRA { yyerrok; incorrectProgram(&symTab, yylineno); }
;

OptionalElseifs : /* Empty */
                | ElseIfs
                | Else
                | ElseIfs Else
;

ElseIfs : ElseIfs ElseIf
        | ElseIf
;

ElseIf : TOK_ELSE TOK_IF TOK_LPAR Condition TOK_RPAR CommandBlock
;

Else : TOK_ELSE CommandBlock
;

Cases : Cases Case
      | Case
;

Case : TOK_CASE Expression TOK_COLON Commands
;

UseVariables : UseVariables TOK_COMMA UseVariable 
             | TOK_COMMA UseVariable 
             | error TOK_COMMA UseVariable { yyerrok; incorrectProgram(&symTab, yylineno); }
;

NewObject : TOK_NEW UseClass TOK_LPAR TOK_RPAR { $$ = $2; }
;

MethodCall : UseFunction TOK_LPAR OptionalArguments TOK_RPAR
           | error TOK_RPAR { yyerrok; incorrectProgram(&symTab, yylineno); }
;

OptionalArguments : /* Empty */
                  | Arguments
;

Arguments : Arguments TOK_COMMA Expression
          | Expression
;

Condition : Condition TOK_OR Logical { $$ = evaluateLogical($1, $2, $3); }
          | Logical
;

Logical : Logical TOK_AND Relation { $$ = evaluateLogical($1, $2, $3); }
        | Relation
;

Relation : TOK_LPAR Condition TOK_RPAR { $$ = $2; }
         | Expression TOK_LESS Expression { $$ = evaluateRelational($1, $2, $3); }
         | Expression TOK_GREATER Expression { $$ = evaluateRelational($1, $2, $3); }
         | Expression TOK_EQUAL Expression { $$ = evaluateRelational($1, $2, $3); }
         | Expression TOK_NOTEQUAL Expression { $$ = evaluateRelational($1, $2, $3); }
;

Expression : Expression TOK_ADD Term { $$ = evaluateArithmetic($1, $2, $3); }
           | Expression TOK_SUB Term { $$ = evaluateArithmetic($1, $2, $3); }
           | Term
;

Term : Term TOK_TIMES Minus { $$ = evaluateArithmetic($1, $2, $3); }
     | Term TOK_DIVIDE Minus { $$ = evaluateArithmetic($1, $2, $3); }
     | Minus
;

Minus : TOK_SUB Primary { $$ = evaluateArithmetic(convertToStValue(0, 1, INT_TYPE), $1, $2); }
      | Primary
;

Primary : TOK_LPAR Expression TOK_RPAR { $$ = $2; }
        | TOK_CHAR_LITERAL
        | TOK_BOOL_LITERAL
        | TOK_INT_LITERAL
        | TOK_DOUBLE_LITERAL
        | TOK_STRING_LITERAL
        | UseVariable { $$ = getStValueFromStInfoVar($1); }
        | MethodCall { $$ = convertToStValue(0, 1, $1); }
        | NewObject { $$ = convertToStValue(0, 1, $1); }
;

InitVariable : Identifier { checkDuplicateVar(&symTab, $1, yylineno); }
;

InitFunction : Identifier { checkInsertFunc(&symTab, $1,modifier, dataTyp, yylineno); }
;

InitClass : TOK_CLASS_NAME { checkInsertClass(&symTab, $1, yylineno); }
;

UseVariable : Identifier { $$ = checkUndeclaredVar(&symTab, $1, NULL, yylineno); }
            | Identifier TOK_DOT Identifier { $$ = checkUndeclaredVar(&symTab, $3, $1, yylineno); }
;

UseFunction : Identifier { $$ = checkUndeclaredFunc(&symTab, $1, NULL, yylineno); }
            | Identifier TOK_DOT Identifier { $$ = checkUndeclaredFunc(&symTab, $3, $1, yylineno); }
;

UseClass : TOK_CLASS_NAME { $$ = checkUndeclaredClass(&symTab, $1, yylineno); }
;

Identifier : TOK_MEMBER
           | TOK_CLASS_NAME
;

%%

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

