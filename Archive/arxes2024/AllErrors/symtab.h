

#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {VOID_TYPE=-6, STRING_TYPE, CHAR_TYPE, BOOL_TYPE, DOUBLE_TYPE, INT_TYPE, MISMATCH} Datatype;

typedef enum {ADD, SUB, TIMES, DIVIDE, LESS, GREATER, EQUAL, NOTEQUAL, AND, OR} Operators;

typedef struct StValue { /* Struct for StValue */
	double valVar; /* Double or Int */
	int isInitial; /* Is Initialized? */
	int type; /* Datatype */
} StValue;

typedef struct StInfoVar { /* Struct for StInfoVar */
	char *name; /* Name */
	StValue value; /* Value */
	int isPublic; /* Is Public? */
} StInfoVar;

typedef struct StNodeVar { /* Struct for StNodeVar */
	StInfoVar info; /* Unique info*/
	struct StNodeVar *next; /* Next StNodeVar */
} StNodeVar;

typedef struct StListVar { /* Struct for StListVar */
	struct StNodeVar *first;
	struct StNodeVar *last;
} StListVar;



typedef struct StInfoFunc { /* Struct for StInfoFunc */
	char *name; /* Name */
	int typeRet; /* Datatype */
	int isPublic; /* Is Public ? */
	StListVar listVars;
} StInfoFunc;

typedef struct StNodeFunc { /* Struct for StNodeFunc */
	StInfoFunc info; /* Unique info*/
	struct StNodeFunc *next; /* Next StNodeFunc */
} StNodeFunc;

typedef struct StListFunc { /* Struct for StListFunc */
	struct StNodeFunc *first;
	struct StNodeFunc *last;
} StListFunc;



typedef struct StInfoClass { /* Struct for StInfoClass */
	char *name; /* Name */
	StListVar listVars;
	StListFunc listFuncs;
} StInfoClass;

typedef struct StNodeClass { /* Struct for StNodeClass */
	StInfoClass info; /* Unique info*/
	struct StNodeClass *next; /* Next StNodeClass */
} StNodeClass;

typedef struct StListClass { /* Struct for StListClass */
	struct StNodeClass *first;
	struct StNodeClass *last;
	int numClass;
} StListClass;


typedef struct StSymbolTable { /* Struct for StSymbolTable */
	StListClass listClass;
	StInfoClass *ptrClass;
	StInfoFunc *ptrFunc;
	int numbErrors;
} StSymbolTable;


char* copyStrDynamic(const char *strOrg);

StInfoVar* insertVar(StListVar *list, const char *nam, StValue stValue, int isPublic);
StInfoVar* findVar(StListVar *list, const char *nam);
void clearVar(StListVar *list);
void printVar(StListVar *list, const char *sep);
StValue convertToStValue(double valVar, int isInitial, int type);

StInfoFunc* insertFunc(StListFunc *list, const char *nam, int isPublic, int typeRet);
StInfoFunc* findFunc(StListFunc *list, const char *nam);
void clearFunc(StListFunc *list);
void printFunc(StListFunc *list, const char *sep);

StInfoClass* insertClass(StListClass *list, const char *nam);
StInfoClass* findClass(StListClass *list, const char *nam);
StInfoClass* findClassPos(StListClass *list, int pos);
int findPosClass(StListClass *list, const char *nam);
void clearClass(StListClass *list);
void printClass(StListClass *list);


void checkDuplicateVar(StSymbolTable *symTab, char *varName, int line);
StInfoVar* assignVar(StSymbolTable *symTab, char *varName, int modifier, StValue stValue);
void checkInsertFunc(StSymbolTable *symTab, char *funcName, int isPublic, int typeRet, int line);
void resetFunc(StSymbolTable *symTab);
void checkInsertClass(StSymbolTable *symTab, char *className, int line);
StInfoClass* checkUndeclaredObj(StSymbolTable *symTab, char *objName, int line);
StInfoVar* checkUndeclaredVar(StSymbolTable *symTab, char *varName, char *objName, int line);
int checkUndeclaredFunc(StSymbolTable *symTab, char *funcName, char *objName, int line);
int checkUndeclaredClass(StSymbolTable *symTab, char *className, int line);
void endProgram(StSymbolTable *symTab);

StValue evaluateArithmetic(StValue left, Operators operator_, StValue right);
StValue evaluateRelational(StValue left, Operators operator_, StValue right);
StValue evaluateLogical(StValue left, Operators operator_, StValue right);
StValue getStValueFromStInfoVar(StInfoVar* ptrVar);
void showMessVariable(StSymbolTable *symTab, StInfoVar *ptrVar, StValue value_, int line);

#endif // !SYMTAB_H
