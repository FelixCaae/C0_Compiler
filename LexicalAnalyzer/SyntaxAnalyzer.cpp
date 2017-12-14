#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Syntax.h"
#include "Lexeme.h"
#include "Error.h"
#include "IO.h"
#include "SymTable.h"
//recursively called function]
void parseProgram();
void parseIden(char *val);
void parseInt(int *val);
void parseChar(int *val);
void parseStr(int*val);
void parseSubscript(bool isUnsigned,int *val);
void parseRelation(lexClass* relation);
void parseConstGrup();
void parseConstDecl();
bool parseVarGrup();
bool parseVarDecl();
void parseFuncDecl();
void parseParamList(IdenType paramType[], int* paramNum);
void parseStatements();
void parseStat();
void parseCompoundStat();
void parseAFHead();
void parseAssignStat(char * name);
void parseFuncCallStat(char* name);
void parseArgList(IdenType pt[], int);
void parseExpression(int *r);
void parseTerm(int*r);
void parseFactor(int *r);
void parseCondition();
void parseConditionStat();
void parseLoopStat();
void parseSwitchStat();
void parseSwitchTab(int val, int label);
void parseSubSwitchStat(int val, int label);
void parseConstant(int *val);
void parseReadStat();
void parseWriteStat();
void parseReturnStat();
bool funcFound=false;
bool mainFound = false;
int slevel = 0;
char tokenbak[tokenStrLen];
syntaxClass lexToSyntax()
{
	if (findReserveWord() != 0)return SKEY;
	if (findSeperator() != 0)return SSEP;
	if (lextype >= 1 && lextype <= 4)return (syntaxClass)lextype;
	if (lextype == END)return SEND;
	return SERROR;
}
bool couldBe(lexClass lc)
{
	if (lextype == lc)
	{
		outputTerminalS(lexToSyntax());
		readSym();
		return true;
	}
	return false;
}
int couldBe2(lexClass lc1, lexClass lc2)
{
	strcpy(tokenbak, token);
	if (lextype == lc1)
	{
		outputTerminalS(lexToSyntax());
		readSym();
		return 1;
	}
	if (lextype == lc2)
	{
		outputTerminalS(lexToSyntax());
		readSym();
		return 2;
	}
	return 0;
}
void shouldBe(lexClass lc)
{
	strcpy(tokenbak, token);
	if (lextype != lc)
	{
		error(ERR_SYNTAX,lc);
	}
	outputTerminalS(lexToSyntax());
	readSym();
}
int shouldBe2(lexClass lc1,lexClass lc2)
{
	strcpy(tokenbak, token);
	int r=0;
	if (lextype != lc1&&lextype != lc2)
	{
		error(ERR_SYNTAX,lc1);
	}
	if (lextype == lc1)r=1;
	else r=2;
	outputTerminalS(lexToSyntax());
	readSym();
	return r;
}
void shouldNotExist(char * name)
{
	if(lookupIdent(name, linkHead)!=NotExist)
	{
		error(ERR_IDEN_DECLARED);
	}
}
int shouldExist(char *name)
{
	int r;
	if ((r = lookupIdent(name)) == NotExist)
	{
		error(ERR_IDEN_NOT_DECLARED);
	}
	return r;
}
void parseIden(char * val)
{
	strcpy(val, token);
	shouldBe(IDEN);
}
void parseChar(int *val)
{
	strcpy(tokenbak, token);
	shouldBe(CHR);
	*val = tokenbak[1];
}
void parseStr(int *val)
{
	strcpy(tokenbak, token);
	shouldBe(STR);
	strcpy(tokenbak, tokenbak + 1);
	tokenbak[strlen(tokenbak) - 1] = '\0';
	*val = insertString(tokenbak);
}
void parseInt(int *r)//out:integer
{
	bool neg = false;
	if(couldBe2(PLUS, MINUS)==2)
	{
		neg = true;
	}
	strcpy(tokenbak, token);
	shouldBe(INT);
	*r = atoi(tokenbak);
	if (neg)
	{
		*r = -*r;
	}
}
void parseTypeIden(IdenType *it)//out:semantic type
{
	outputSyntax(TYPE);
	int r=shouldBe2(INTYP, CHARTYP);
	if (r == 1) {
		*it = INTS;
	}
	else if (r == 2) {
		*it = CHARS;
	}
	outputSyntax(TYPE,false);
}
void parseSubscript(bool isUnsigned,int* r)//out:integer
{
	shouldBe(LBRAK);
	if (isUnsigned)
	{
		//replace with parseUnsignedInt();
		parseInt(r);
		if (*r <= 0)
		{
			error(ERR_ARRAY_FLOW);
		}
	}
	else
	{
		parseExpression(r);
	}
	shouldBe(RBRAK);
}
void parseRelation(lexClass* lex)//out:
{
	outputSyntax(SIDEN);
	switch (lextype)
	{
	case LS:
	case GT:
	case GTEQU:
	case LSEQU:
	case EQU:
	case NEQU:
		*lex = lextype;
		outputTerminalS(lexToSyntax());
		readSym();
		break;
	default:
		error(ERR_SYNTAX, RELATION);
	}
	outputSyntax(SIDEN,false);
}
void parseConstDecl()
{
	outputSyntax(CONSTDECL);
	char idenName[tokenStrLen];
	IdenType varType;
	int val;
	parseTypeIden(&varType);
	while (true)
	{
		parseIden(idenName);
		shouldNotExist(idenName);
		shouldBe(ASSIGN);
		if(varType==INTS)
		{
			parseInt(&val);
		}
		else if (varType == CHARS)
		{
			parseChar(&val);
		}
		insertIdent(idenName, varType, OCONST, val);
		if (couldBe(COMMA))
		{
			continue;
		}
		else
		{
			break;
		}
	}
	outputSyntax(CONSTDECL,false);
}
bool parseVarDecl()
{
	outputSyntax(VARDECL);
	IdenType it;
	char idenName[tokenStrLen];
	int dimension;
	parseTypeIden(&it);
	while (true)
	{
		parseIden(idenName);
		shouldNotExist(idenName);
		if (lextype == LBRAK)
		{
			parseSubscript(true,&dimension);
			insertIdent(idenName, it, OARRAY, dimension);
		}
		else if (lextype == LPAR)
		{
			retractSym(2);
			outputSyntax(SRETRACT, false);
			return RETRACT;
		}
		else
		{
			insertIdent(idenName, it, OVAR);
		}

		if (couldBe(COMMA))
		{

			continue;
		}
		else
		{
			break;
		}
	}
	outputSyntax(VARDECL,false);
	return NORMAL;
}
void parseConstGrup()
{
	//we can make sure that this is a const group by const symbol
	//this function exit with reading one more symbol
	//assume that the first sym is const,otherwise this function won`t be called.
	outputSyntax(CONSTGRUP);
	do
	{
		shouldBe(CONSTYP);
		parseConstDecl();
		shouldBe(SEMI);
	} while (lextype == CONSTYP);
	outputSyntax(CONSTGRUP,false);
}
bool parseVarGrup()
{
	outputSyntax(VARGRUP);
	bool r;
	do
	{
		r=parseVarDecl();
		if (r == RETRACT)
		{
			outputSyntax(VARGRUP, false);
			return RETRACT;
		}
		shouldBe(SEMI);
	} while (lextype==INTYP||lextype==CHARTYP);
	outputSyntax(VARGRUP,false);
	return NORMAL;
}
void parseFuncDecl()
{
	outputSyntax(FUNCDECL);
	IdenType it;
	char funcName[tokenStrLen];
	IdenType paramType[maxParmNum];
	int paramNum=0;
	if (couldBe(NOTYP))
	{
		it = NOTYPS;
	}
	else {
		parseTypeIden(&it);
	}
	if (couldBe(MAINFUNC))
	{
		//setLabel(findLabel("main"));
		strcpy(funcName, "main");
		if (it != NOTYPS)
		{
			error(ERR_MAIN_RET_TYPE);
		}
		mainFound = true;
	}
	else
	{
		parseIden(funcName);
	}
	int id = insertIdent(funcName, it, OFUNC, 0);
	emit(QFUNCDECL, id);
	parseParamList(paramType, &paramNum);
	if (mainFound && paramNum)
	{
		error(ERR_MAIN_PARAM);
	}
	int func = insertFunc(it, paramNum, paramType);
	symTable[id]._ref = func;
	shouldBe(LCURB);
	enterFunc();
	parseCompoundStat();
	leaveFunc();
	shouldBe(RCURB);
	outputSyntax(FUNCDECL,false);
}
void parseParamList(IdenType paramType[],int* paramNum)
{
	outputSyntax(PARAMLIST);
	int paramCounter=0;
	IdenType it;
	char idenName[tokenStrLen];
	shouldBe(LPAR);
		while (!couldBe(RPAR))
		{
			parseTypeIden(&it);
			parseIden(idenName);
			paramType[paramCounter++] = it;
			int r=insertIdent(idenName, it, OVAR);
			emit(QPARA,r);
			r = shouldBe2(COMMA, RPAR);
			if (r == 1)
			{
				continue;
			}
			else if (r == 2)
			{
				break;
			}
		}
	*paramNum = paramCounter;
	outputSyntax(PARAMLIST,false);
}
void parseCompoundStat()
{
	outputSyntax(COMPOUNDSTAT);
	if (lextype == CONSTYP)
	{
		parseConstGrup();
	}
	if (lextype == INTYP || lextype == CHARTYP)
	{
		parseVarGrup();
	}
	parseStatements();
	outputSyntax(COMPOUNDSTAT,false);
}
void parseStatements()
{
	outputSyntax(STATS);
	while(lextype != RCURB)
	{
		parseStat();
	}
	outputSyntax(STATS,false);
}
void parseStat()
{
	outputSyntax(STAT);
	switch (lextype)
	{
	case	IDEN:
		parseAFHead();
		shouldBe(SEMI);
		break;
	case	IFSY:
		parseConditionStat();
		break;
	case    DOSY:
		parseLoopStat();
		break;
	case	SWITCHSY:
		parseSwitchStat();
		break;
	case	LCURB:
		outputTerminalS(lexToSyntax());
		readSym();
		parseStatements();
		shouldBe(RCURB);
		break;
	case	SEMI:
		shouldBe(SEMI);
		break;
	case	PRINTFUNC:
		parseWriteStat();
		shouldBe(SEMI);
		break;
	case	SCANFUNC:
		parseReadStat();
		shouldBe(SEMI);
		break;
	case  RETURNSY:
		parseReturnStat();
		shouldBe(SEMI);
		break;
	default:
		error(ERR_SYNTAX,STAT);
	}
	outputSyntax(STAT,false);
}
void parseExpression(int *r)
{
	outputSyntax(EXPRESSION);
	int first,second,store;
	int neg;
	int val1, val2, vresult;
	bool tmpFlag=true;
	neg=couldBe2(MINUS, PLUS);
	parseTerm(&first);
	if (neg == 2)
	{
		int zero = genTemp(INTS,true,0);
		emit(QMINUS,first,zero,first);
	}
	while ((neg = couldBe2(MINUS, PLUS)) != 0) {
		parseTerm(&second);
		if (tmpFlag)
		{
			store = genTemp(INTS, false);
		}
		val1 = symTable[first]._ref;
		val2 = symTable[second]._ref;
		if (neg == 1)
		{
			emit(QMINUS, store, first, second);
			vresult = val1 - val2;
		}
		else if (neg == 2)
		{
			emit(QPLUS, store, first, second);
			vresult = val1 - val2;
		}
		if (symTable[first]._obj == OCONST&& symTable[second]._obj == OCONST)
		{
			symTable[store]._obj = OCONST;
			symTable[store]._ref = vresult;
		}
		first = store;
	}
	*r = first;
	outputSyntax(EXPRESSION,false);
}
void parseTerm(int *r)
{
	outputSyntax(TERM);
	int op=0;
	int first,second,store;
	int val1, val2, vresult;
	bool tmpFlag = true;
	parseFactor(&first);
	val1 = symTable[first]._ref;
	while ((op = couldBe2(STAR, DIV)) != 0) {
		parseFactor(&second);
		val2 = symTable[second]._ref;
		if (tmpFlag)
		{
			store = genTemp(INTS, false);
		}
		if(op==1)
		{
			vresult = val1*val2;
			emit(QSTAR, store, first, second);
		}
		else if(op==2)
		{
			if (val2 != 0) {
				vresult = val1 / val2;
			}
			emit(QDIV, store,first,second);
		}
		first = store;
		val1 = symTable[first]._ref;
	} 
	*r = first;
	outputSyntax(TERM,false);
}
void parseFactor(int *r)
{
	outputSyntax(FACTOR);
	switch (lextype)
	{
	case IDEN: {
		char idenName[tokenStrLen];
		parseIden(idenName);
		int ident = lookupIdent(idenName);
		IdenType it = symTable[ident]._type;
		if (symTable[ident]._type == NOTYPS)
		{
			error(ERR_REQUIRE_RET);
		}

		if (lextype == LBRAK)
		{
			int sub;
			parseSubscript(false, &sub);
			int tmp= genTemp(it);
			emit(QARR, tmp, ident, sub);
			*r = tmp;
		}
		else if (lextype == LPAR)
		{
			parseFuncCallStat(idenName);
			int tmp = genTemp(it);
			emit(QRETX, tmp);
			*r = tmp;
		}
		else
		{
			*r = ident;
		}
		break;
	}
	case LPAR:{
		outputTerminalS(lexToSyntax());
		readSym();
		parseExpression(r);
		shouldBe(RPAR);
		break;
	}
	case PLUS:
	case MINUS:
	case INT: {
		int val;
		parseInt(&val);
		*r = genTemp(INTS,true,val);
		break;
	}
	case CHR: {
		int val;
		parseChar(&val);
		*r = genTemp(CHARS,true,val);
		break;
	}
	default:
		error(ERR_SYNTAX,FACTOR);
	}
	outputSyntax(FACTOR,false);
}
void parseConditionStat()
{
	outputSyntax(CONDSTAT);
	shouldBe(IFSY);
	shouldBe(LPAR);
	int label = genLabel(LIF);
	parseCondition();
	emit(QBNZ, label);
	shouldBe(RPAR);
	parseStat();
	setLabel(label);
	outputSyntax(CONDSTAT,false);
}
void parseCondition()
{
	outputSyntax(CONDITION);
	lexClass lex;
	qCType r;
	int operand1, operand2;
	parseExpression(&operand1);
	if (lextype == RPAR)
	{
		emit(QNEQU, operand1, genTemp(INTS, true, 0));
	}
	else
	{
		parseRelation(&lex);
		parseExpression(&operand2);
		switch (lex)
		{
		case LS:
			r = QLS; break;
		case LSEQU:
			r = QLSEQU; break;
		case EQU:
			r = QEQU; break;
		case NEQU:
			r = QNEQU; break;
		case GT:
			r = QGT; break;
		case GTEQU:
			r = QGTEQU; break;
		}
		emit(r, operand1, operand2);
	}
	outputSyntax(CONDITION,false);
}
void parseLoopStat()
{
	outputSyntax(LOOPSTAT);
	int label = genLabel(LWHILE);
	shouldBe(DOSY);
	setLabel(label);
	parseStat();
	shouldBe(WHILESY);
	shouldBe(LPAR);
	parseCondition();
	emit(QBZ, label);
	shouldBe(RPAR);
	outputSyntax(LOOPSTAT,false);
}
void parseSwitchStat()
{
	outputSyntax(SWITCHSTAT);
	shouldBe(SWITCHSY);
	shouldBe(LPAR);
	int label = genLabel(LSWITCH);
	int val;
	parseExpression(&val);
	shouldBe(RPAR);
	shouldBe(LCURB);
	parseSwitchTab(val,label);
	shouldBe(RCURB);
	outputSyntax(SWITCHSTAT,false);
}
void parseSwitchTab(int val,int switchend)
{
	outputSyntax(SWITCHTAB);
	do
	{
		parseSubSwitchStat(val,switchend);
	} while (lextype == CASESY);
	outputSyntax(SWITCHTAB,false);
}
void parseSubSwitchStat(int val, int switchend)
{
	outputSyntax(SUBSWITCHSTAT);
	int con,casend;
	IdenType it,it2;//TODO:case 
	casend = genLabel(LCASE);
	shouldBe(CASESY);
	parseConstant(&con);
	it = symTable[val]._type;
	it2 = symTable[con]._type;
	if (it != it2)
	{
		error(ERR_CASE_MATCH);
	}
	shouldBe(COLON);
	emit(QEQU, con, val);
	emit(QBNZ, switchend);
	parseStat();
	setLabel(casend);
	outputSyntax(SUBSWITCHSTAT,false);
}
void parseConstant(int *r)
{
	outputSyntax(CONSTANT);
	int val;
	if (lextype==CHR)
	{
		parseChar(&val);
		*r = genTemp(CHARS, true, val);
	}
	else
	{
		parseInt(&val);
		*r = genTemp(INTS, true, val);
	}
	outputSyntax(CONSTANT,false);
}
void parseAFHead()
{
	char idenName[tokenStrLen];
	parseIden(idenName);
	if (lextype == LPAR)
	{
		parseFuncCallStat(idenName);
	}
	else
	{
		parseAssignStat(idenName);
	}
}
void parseAssignStat(char *name)
{
	outputSyntax(ASSIGNSTAT);
	bool isAR = false;
	int sub;
	int store,val;
	IdenType storeIt,valIt;
	int r=lookupIdent(name);
	storeIt=symTable[r]._type;
	if (symTable[r]._obj == OCONST)
	{
		error(ERR_CONST);
	}
	if(lextype==LBRAK)
	{
		if (symTable[r]._obj != OARRAY)
		{
			error(ERR_REQUIRE_ARRAY);
		}
		isAR = true;
		parseSubscript(false, &sub);
	}
	shouldBe(ASSIGN);
	parseExpression(&val);
	valIt = symTable[val]._type;
	if (valIt == INTS && storeIt == CHARS)
	{
		error(ERR_INTOCHAR);
	}
	//do some type-transform or send warning if an int-type value is assigned to a char var
	//be careful with the range a char-type var can hold
	if (isAR)
	{
		emit(QARL, r, sub, val);
	}
	else
	{
		emit(QASSIGN, r, val);
	}
	outputSyntax(ASSIGNSTAT,false);
}
void parseFuncCallStat(char *name)
{
	outputSyntax(FUNCALLSTAT);
	int ident=lookupIdent(name);
	int ref = symTable[ident]._ref;
	if (symTable[ident]._obj != OFUNC)
	{
		error(ERR_REQUIRE_FUNC);
	}
	shouldBe(LPAR);
	parseArgList( funcTable[ref]._param, funcTable[ref]._paraNum);
	emit(QCALL,ident);
	shouldBe(RPAR);
	outputSyntax(FUNCALLSTAT,false);
}
void parseArgList(IdenType paramType[], int paramNum)
{
	outputSyntax(ARGLIST);
	int acParamNum=0;
	int param;
	IdenType it;
	if (lextype != RPAR)
	{
	do {
		parseExpression(&param);
		it = symTable[param]._type;
		if (acParamNum<paramNum&&paramType[acParamNum] != it)
		{
			error(ERR_PARAMTYPE_NOT_MATCH);
		}
		else
		{
			emit(QPUSH, param);
		}
		acParamNum += 1;
	} while (couldBe(COMMA));
	}
	if (acParamNum < paramNum)
	{
		error(ERR_PARAMNUM_LESS,paramNum-acParamNum);
	}
	if (acParamNum > paramNum)
	{
		error(ERR_PARAMNUM_MORE,acParamNum-paramNum+1);
	}
	outputSyntax(ARGLIST,false);
}
void parseReturnStat()
{
	outputSyntax(RETURNSTAT);
	shouldBe(RETURNSY);
	if (couldBe(LPAR))
	{
		int val;
		parseExpression(&val);
		emit(QRET, RVAL, val);
		shouldBe(RPAR);
	}
	else
	{
		emit(QRET, RNOVAL);
	}
	outputSyntax(RETURNSTAT, false);
}
void parseWriteStat()
{
	outputSyntax(WRITESTAT);
	shouldBe(PRINTFUNC);
	shouldBe(LPAR);
	int str,exp;
	IdenType it;
	if (lextype==STR)
	{
		parseStr(&str);
		emit(QPRINT, FSTRING, str);
		if (couldBe(COMMA))
		{
			parseExpression(&exp);
			emit(QPRINT, FEXPRESSION, exp);
		}
	}
	else
	{
		parseExpression(&exp);
		emit(QPRINT, FEXPRESSION, exp);
	}
	shouldBe(RPAR);
	outputSyntax(WRITESTAT,false);
}
void parseReadStat()
{
	outputSyntax(READSTAT);
	shouldBe(SCANFUNC);
	shouldBe(LPAR);
	char idenName[tokenStrLen];
	int iden;
	do
	{
		parseIden(idenName);
		iden=lookupIdent(idenName);
		if (symTable[iden]._obj !=OVAR)
		{
			error(ERR_REQUIRE_VAR);
		}
		emit(QREAD, iden);
	} while (couldBe(COMMA));
	shouldBe(RPAR);
	outputSyntax(READSTAT,false);
}

void parseProgram()
{
	outputSyntax(PROGRAM);
	if (lextype==CONSTYP)parseConstGrup();
	if(lextype==INTYP||lextype==CHARTYP)parseVarGrup();
	while (!mainFound) {
		parseFuncDecl();
	}
	outputSyntax(PROGRAM, false);
	shouldBe(END);
}
bool syntaxAnalyze(int argc, char** argv)
{

	init(argc, argv);
	readSym();
	parseProgram();
	close();
	return true;
}
int main(int argc, char**argv)
{
	char *buffer[2];
	buffer[1] = "test/test_equalsplit.txt";
	if (syntaxAnalyze(2, (char**)buffer))
	{
		printf("Success!");
	}
	getchar();
	//parse();
}
