
#include "symtab.h"

char* copyStrDynamic(const char *strOrg) 
{
	char* strDst = NULL;
	
	strDst = (char*) malloc(strlen(strOrg) + 1);
	
	if (strDst != NULL) {
		strcpy(strDst, strOrg);
	} else {
		printf("Error: Dynamically allocating memory.\n");
		exit(0);
	}
	
	return strDst;
}

StInfoVar* insertVar(StListVar *list, const char *nam, StValue stValue, int isPublic)
{
	StNodeVar *newNode = NULL;
	StInfoVar *infoVar = NULL;

	newNode = (StNodeVar*) malloc(sizeof(StNodeVar));

	if(newNode != NULL) {
		(newNode->info).name = copyStrDynamic(nam);
		(newNode->info).value = stValue;
		(newNode->info).isPublic = isPublic;

		newNode->next = NULL;

		if(list->first == NULL) {
			list->first = newNode;
		} else {
			(list->last)->next = newNode;
		}
		list->last = newNode;
		
		infoVar = &(newNode->info);
	}
	
	return infoVar;
}

StInfoVar* findVar(StListVar *list, const char *nam)
{
	StInfoVar *findId = NULL;
	StNodeVar *auxNode = list->first;
	
	while((auxNode != NULL) && (!findId)) {
		if(!strcmp((auxNode->info).name, nam)) {
			findId = &(auxNode->info);
		}
		auxNode = (auxNode)->next;
	}
	
	return(findId);
}

void clearVar(StListVar *list)
{
	StNodeVar *auxNode = list->first, *oldNode;

	while(auxNode != NULL) {
		oldNode = auxNode;
		auxNode = auxNode->next;
		
		free((oldNode->info).name);
		free(oldNode);
	}
	list->first = NULL;
	list->last = NULL;
}

void printVar(StListVar *list, const char *sep)
{
	StNodeVar *auxNode = list->first;

	if (auxNode != NULL) {
		printf("\n%sSymbol table (Variables):\n", sep);
		printf("%s---------------------------------------------------------------------------------\n", sep);
		printf("%s%-20s %-20s %10s %10s %10s\n", sep, "Name", "Datatype", "Mod.", "Is Init", "Init Val.");
		printf("%s----------------------------------------------------------------------------------\n", sep);
	}

	while (auxNode != NULL) {
		printf("%s%-20s ", sep, (auxNode->info).name);
		
		printf("%-20d ", (auxNode->info).value.type);
		
		printf("%10d ", (auxNode->info).isPublic);
		printf("%10d ", (auxNode->info).value.isInitial);
		printf("%10.2f ", ((auxNode->info).value).valVar);
		
		printf("\n");
		auxNode = auxNode->next;
	}
}

StValue convertToStValue(double valVar, int isInitial, int type)
{
	StValue value;

	value.valVar = valVar;
	value.isInitial = isInitial;
	value.type = type;
	
	return(value);
}


StInfoFunc* insertFunc(StListFunc *list, const char *nam, int isPublic, int typeRet)
{
	StNodeFunc *newNode = NULL;
	StInfoFunc *infoFunc = NULL;

	newNode = (StNodeFunc*)malloc(sizeof(StNodeFunc));

	if(newNode != NULL) {
		(newNode->info).name = copyStrDynamic(nam);
		(newNode->info).typeRet = typeRet;

		(newNode->info).isPublic = isPublic;
		((newNode->info).listVars).first = NULL;
		((newNode->info).listVars).last = NULL;
		newNode->next = NULL;

		if(list->first == NULL) {
			list->first = newNode;
		} else {
			(list->last)->next = newNode;
		}
		list->last = newNode;
		
		infoFunc = &(newNode->info);
	}
	
	return infoFunc;
}

StInfoFunc* findFunc(StListFunc *list, const char *nam)
{
	StInfoFunc *findId = NULL;
	StNodeFunc *auxNode = list->first;
	
	while((auxNode != NULL) && (!findId)) {
		if(!strcmp((auxNode->info).name, nam)) {
			findId = &(auxNode->info);
		}
		auxNode = (auxNode)->next;
	}
	
	return(findId);
}

void clearFunc(StListFunc *list)
{
	StNodeFunc *auxNode = list->first, *oldNode;

	while(auxNode != NULL) {
		oldNode = auxNode;
		auxNode = auxNode->next;
		free((oldNode->info).name);
		clearVar(&((oldNode->info).listVars));
		free(oldNode);
	}
	list->first = NULL;
	list->last = NULL;
}

void printFunc(StListFunc *list, const char *sep)
{
	StNodeFunc *auxNode = list->first;

	if (auxNode != NULL) {
		printf("\n%sSymbol table (Functions):\n", sep);
		printf("%s---------------------------------------------------------------------------------\n", sep);
		printf("%s%-20s %-20s %10s\n", sep, "Name", "Datatype", "Mod.");
		printf("%s---------------------------------------------------------------------------------\n", sep);
	}

	while(auxNode != NULL) {
		printf("%s%-20s ", sep, (auxNode->info).name);
		printf("%-20d ", (auxNode->info).typeRet);

		printf("%10d ", (auxNode->info).isPublic);
		
		printf("\n");
		printVar(&((auxNode->info).listVars), "\t\t");
		printf("\n");

		auxNode = auxNode->next;
	}
}

StInfoClass* insertClass(StListClass *list, const char *nam)
{
	StNodeClass *newNode = NULL;
	StInfoClass *infoClass = NULL;

	newNode = (StNodeClass*)malloc(sizeof(StNodeClass));

	if(newNode != NULL) {
		(newNode->info).name = copyStrDynamic(nam);
		
		((newNode->info).listVars).first = NULL;
		((newNode->info).listVars).last = NULL;
		((newNode->info).listFuncs).first = NULL;
		((newNode->info).listFuncs).last = NULL;
		newNode->next = NULL;

		if(list->first == NULL) {
			list->first = newNode;
		} else {
			(list->last)->next = newNode;
		}
		list->last = newNode;

		infoClass = &(newNode->info);
		(list->numClass)++;
	}

	return infoClass;
}

StInfoClass* findClass(StListClass *list, const char *nam)
{
	StInfoClass *findId = NULL;
	StNodeClass *auxNode = list->first;
	
	while((auxNode != NULL) && (!findId)) {
		if(!strcmp((auxNode->info).name, nam)) {
			findId = &(auxNode->info);
		}
		auxNode = (auxNode)->next;
	}
	
	return(findId);
}

StInfoClass* findClassPos(StListClass *list, int pos)
{
	StInfoClass *findId = NULL;
	StNodeClass *auxNode = list->first;

	if((pos >= 1) && (pos <= (list->numClass)))
	{
		while(pos > 1)
		{
			auxNode = auxNode->next;
			pos--;
		}
		findId = &(auxNode->info);
	}
	
	return(findId);
}

int findPosClass(StListClass *list, const char *nam)
{
	int pos = 0, index = 1;
	StNodeClass *auxNode = list->first;
	
	while((auxNode != NULL) && (pos == 0)) {
		if(!strcmp((auxNode->info).name, nam)) {
			pos = index;
		}
		auxNode = (auxNode)->next;
		index++;
	}
	
	return(pos);
}

void clearClass(StListClass *list)
{
	StNodeClass *auxNode = list->first, *oldNode;

	while(auxNode != NULL) {
		oldNode = auxNode;
		auxNode = auxNode->next;
		free((oldNode->info).name);
		clearVar(&((oldNode->info).listVars));
		clearFunc(&((oldNode->info).listFuncs));
		free(oldNode);
	}
	list->first = NULL;
	list->last = NULL;
}

void printClass(StListClass *list)
{
	StNodeClass *auxNode = list->first;

	if (auxNode != NULL) {
		printf("\nSymbol table (Classes):\n");
		printf("------------------------\n");
		printf("%-20s\n", "Name");
		printf("------------------------\n");
	}

	while(auxNode != NULL) {
		printf("%-20s\n", (auxNode->info).name);

		printVar(&((auxNode->info).listVars), "\t");
		printFunc(&((auxNode->info).listFuncs), "\t");
		printf("\n");

		auxNode = auxNode->next;
	}
}




void checkDuplicateVar(StSymbolTable *symTab, char *varName, int line)
{
	StInfoClass *ptrClass = symTab->ptrClass;
	StListFunc *listFunc = NULL;
	StInfoFunc *ptrFunc = symTab->ptrFunc;
	StListVar *listVars = NULL;
	
	if (ptrFunc != NULL) {
		listVars = &(ptrFunc->listVars);

		if (findVar(listVars, varName) != NULL) {
			printf("Duplicate Identifier: %s on line %d\n", varName, line);
		
			endProgram(symTab);
		}
	} else {
		listFunc = &(ptrClass->listFuncs);
		listVars = &(ptrClass->listVars);

		if ((findVar(listVars, varName) != NULL) || (findFunc(listFunc, varName) != NULL)) {
			printf("Duplicate Identifier: %s on line %d\n", varName, line);
			
			endProgram(symTab);
		}
	}
}

StInfoVar* assignVar(StSymbolTable *symTab, char *varName, int modifier, StValue stValue)
{
	StInfoClass *ptrClass = symTab->ptrClass;
	StInfoFunc *ptrFunc = symTab->ptrFunc;
	StListVar *listVars;

	if (ptrFunc != NULL) {
		listVars = &(ptrFunc->listVars);
		modifier = 0;
	} else {
		listVars = &(ptrClass->listVars);
	}
	
	return (insertVar(listVars, varName, stValue, modifier));
}

void checkInsertFunc(StSymbolTable *symTab, char *funcName, int isPublic, int typeRet, int line)
{
	StInfoClass *ptrClass = symTab->ptrClass;
	StListFunc *listFunc = &(ptrClass->listFuncs);
	StListVar *listVars = &(ptrClass->listVars);

	if ((findVar(listVars, funcName) != NULL) || (findFunc(listFunc, funcName) != NULL)) {
		printf("Duplicate Identifier: %s on line %d\n", funcName, line);
		
		endProgram(symTab);
	} else {
		//ptrFunc = insertFunc(listFunc, funcName);
		symTab->ptrFunc = insertFunc(listFunc, funcName, isPublic, typeRet);
	}
}

void resetFunc(StSymbolTable *symTab) 
{
	if (symTab->ptrFunc != NULL) {
	/*	(symTab->ptrFunc)->number = contParams;*/
		(symTab->ptrFunc) = NULL;
	}
}

void checkInsertClass(StSymbolTable *symTab, char *className, int line)
{
	//StInfoClass *ptrClass = NULL;
	StListClass *listClass = &(symTab->listClass);

	if (findClass(listClass, className) != NULL) {
		printf("Duplicate Class: %s on line %d\n", className, line);
		
		endProgram(symTab);
	} else {
		//ptrClass = insertClass(listClass, className);
		symTab->ptrClass = insertClass(listClass, className);
	}
}

StInfoClass* checkUndeclaredObj(StSymbolTable *symTab, char *objName, int line)
{
	StListClass *listClass = &(symTab->listClass);
	StInfoClass* ptrClass = NULL;
	StInfoFunc *ptrFunc = symTab->ptrFunc;
	StListVar *listVars;
	StInfoVar* ptrVar = NULL;
	int type = 0;
	
	if (ptrFunc != NULL) {
		listVars = &(ptrFunc->listVars);
		ptrVar = findVar(listVars, objName);

		if (ptrVar == NULL) {
			printf("Undeclared Object: %s on line %d\n", objName, line);
		
			endProgram(symTab);
		} else {
			type = (ptrVar->value).type;
			ptrClass = findClassPos(listClass, type);
			
			if (ptrClass == NULL) {
				printf("Undeclared Class from object: %s on line %d\n", objName, line);
				
				endProgram(symTab);
			}
		}
	}
	
	return ptrClass;
}

StInfoVar* checkUndeclaredVar(StSymbolTable *symTab, char *varName, char *objName, int line)
{
	StInfoClass* ptrClass = NULL;
	StInfoFunc* ptrFunc = symTab->ptrFunc;
	StListVar *listVars;
	StInfoVar* ptrVar = NULL;
	
	if (objName != NULL) {
		ptrClass = checkUndeclaredObj(symTab, objName, line);
		
		if (ptrClass != NULL) {
			listVars = &(ptrClass->listVars);

			if (listVars != NULL) {
				ptrVar = findVar(listVars, varName);

				if (ptrVar == NULL) {
					printf("Undeclared Variable: %s from class: %s on line %d\n", varName, ptrClass->name, line);
					
					endProgram(symTab);
				} else {
					if ((ptrClass != (symTab->ptrClass)) && (!(ptrVar->isPublic))) {
						printf("Variable: %s, from class: %s is Private on line %d\n", varName, ptrClass->name, line);
						
						endProgram(symTab);
					}
				}
			}
		}
	} else {
		ptrFunc = symTab->ptrFunc;

		if (ptrFunc != NULL) {
			listVars = &(ptrFunc->listVars);
			ptrVar = findVar(listVars, varName);

			if (ptrVar == NULL) {
				ptrClass = symTab->ptrClass;
				listVars = &(ptrClass->listVars);
				ptrVar = findVar(listVars, varName);
				
				if (ptrVar == NULL) {
					printf("Undeclared Variable: %s on line %d\n", varName, line);
					
					endProgram(symTab);
				}
			}
		}
	}
	
	return ptrVar;
}

int checkUndeclaredFunc(StSymbolTable *symTab, char *funcName, char *objName, int line)
{
	StInfoClass* ptrClass;
	StListFunc *listFunc;
	StInfoFunc* ptrFunc = NULL;
	
	if (objName != NULL) {
		ptrClass = checkUndeclaredObj(symTab, objName, line);
		
		if (ptrClass != NULL) {
			listFunc = &(ptrClass->listFuncs);
			ptrFunc = findFunc(listFunc, funcName);

			if (ptrFunc == NULL) {
				printf("Undeclared Function: %s from class: %s on line %d\n", funcName, ptrClass->name, line);
				
				endProgram(symTab);
			} else {
				if ((ptrClass != (symTab->ptrClass)) && (!(ptrFunc->isPublic))) {
					printf("Function: %s, from class: %s is Private on line %d\n", funcName, ptrClass->name, line);
					
					endProgram(symTab);
				}
			}
		}
	} else {
		ptrClass = symTab->ptrClass;
		listFunc = &(ptrClass->listFuncs);
		ptrFunc = findFunc(listFunc, funcName);

		if (ptrFunc == NULL) {
			printf("Undeclared Function: %s on line %d\n", funcName, line);
			
			endProgram(symTab);
		}
	}
	
	if (ptrFunc == NULL) {
		return MISMATCH;
	}
	
	return ptrFunc->typeRet;
}

int checkUndeclaredClass(StSymbolTable *symTab, char *className, int line)
{
	StListClass *listClass = &(symTab->listClass);
	int pos = findPosClass(listClass, className);

	if (pos == 0) {
		printf("Undeclared Class: %s on line %d\n", className, line);
		
		endProgram(symTab);
	}
	
	return pos;
}

void endProgram(StSymbolTable *symTab)
{
	(symTab->numbErrors)++;
	
	
	clearClass(&(symTab->listClass));
	exit(0);
}

StValue evaluateArithmetic(StValue left, Operators operator_, StValue right)
{
	StValue result = convertToStValue(0, 0, MISMATCH);

	if (((left.type == INT_TYPE) || (left.type == DOUBLE_TYPE)) && (left.isInitial) &&
		((right.type == INT_TYPE) || (right.type == DOUBLE_TYPE)) && (right.isInitial))
	{
		switch (operator_) {
			case ADD:
				result.valVar = left.valVar + right.valVar;
				result.isInitial = 1;
				break;
			case SUB:
				result.valVar = left.valVar - right.valVar;
				result.isInitial = 1;
				break;
			case TIMES:
				result.valVar = left.valVar * right.valVar;
				result.isInitial = 1;
				break;
			case DIVIDE:
				if (right.valVar != 0) {
					result.valVar = left.valVar / right.valVar;
					result.isInitial = 1;
				}
				break;
		}
		
		if (result.isInitial) {
			if ((left.type == DOUBLE_TYPE) || (right.type == DOUBLE_TYPE)) {
				result.type = DOUBLE_TYPE;
			} else {
				result.type = INT_TYPE;
			}
		}
	}

	return result;
}

StValue evaluateRelational(StValue left, Operators operator_, StValue right)
{
	StValue result = convertToStValue(0, 0, MISMATCH);
	
	if (((left.type == INT_TYPE) || (left.type == DOUBLE_TYPE)) && (left.isInitial) &&
		((right.type == INT_TYPE) || (right.type == DOUBLE_TYPE)) && (right.isInitial))
	{
		switch (operator_) {
			case LESS:
				result.valVar = left.valVar < right.valVar;
				break;
			case GREATER:
				result.valVar = left.valVar > right.valVar;
				break;
			case EQUAL:
				result.valVar = left.valVar == right.valVar;
				break;
			case NOTEQUAL:
				result.valVar = left.valVar != right.valVar;
				break;
		}
		result.isInitial = 1;
		result.type = BOOL_TYPE;
	}

	return result;
}

StValue evaluateLogical(StValue left, Operators operator_, StValue right)
{
	StValue result = convertToStValue(0, 0, MISMATCH);
	
	result.isInitial = 0;
	result.valVar = 0;
	if ((left.type == BOOL_TYPE) && (left.isInitial) &&
		(right.type == BOOL_TYPE) && (right.isInitial))
	{
		switch (operator_) {
			case AND:
				result.valVar = left.valVar && right.valVar;
				break;
			case OR:
				result.valVar = left.valVar || right.valVar;
				break;
		}
		result.isInitial = 1;
		result.type = BOOL_TYPE;
	}

	return result;
}

StValue getStValueFromStInfoVar(StInfoVar* ptrVar)
{
	if (ptrVar == NULL) {
		return convertToStValue(0, 0, MISMATCH);
	}
	
	return ptrVar->value;
}

void showMessVariable(StSymbolTable *symTab, StInfoVar *ptrVar, StValue value_, int line)
{
	//printf("-ptrVar is NULL: %d on line %d ", (ptrVar == NULL), line);
	if (ptrVar != NULL) {
		//printf("-Variable: %s ", ptrVar->name);
		//printf("-Expression = <valVar: %.2f, isInitial: %d, type: %s>\n", value_.valVar, value_.isInitial, value_.type);
		
		if ((value_.type == MISMATCH) || (!value_.isInitial)) {
			printf("Could not obtain the result of the arithmetic operation on line %d\n", line);
				
			endProgram(symTab);
		} else if (((value_.type == INT_TYPE) || (value_.type == DOUBLE_TYPE)) && (value_.isInitial)) {
			printf("  Variable: %s, Assigned value: ", ptrVar->name);
			
			if (value_.type == INT_TYPE) {
				printf("%d", (int)value_.valVar);
			} else {
				printf("%.2f", value_.valVar);
			}
			
			printf("\n");
		}
		
		ptrVar->value = value_;
	}
	//printf("\n");
}
