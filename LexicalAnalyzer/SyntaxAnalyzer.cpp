#include"stdafx.h"
#include <stdio.h>
#include "Syntax.h"
#include "Lexeme.h"
#include "Error.h"
#include "IO.h"
//recursively called function]
void parseProgram();
void parseIden();
void parseInt();
void parseChar();
void parseSubscript();
void parseRelation();
void parseCompoundStat();
void parseConstGrup();
void parseConstDecl();
bool parseVarGrup();
bool parseVarDecl();
void parseFuncDecl();
void parseParamList();
void parseStatements();
void parseStat();
void parseCompoundStat();
void parseAFHead();
void parseAssignStat();
void parseFuncCallStat();
void parseTerm();
void parseExpression();
void parseFactor();
void parseCondition();
void parseConditionStat();
void parseLoopStat();
void parseArgList();
void parseSwitchStat();
void parseSwitchTab();
void parseSubSwitchStat();
void parseConstant();
void parseReadStat();
void parseWriteStat();
void parseReturnStat();
bool funcFound=false;
bool mainFound = false;
bool couldBe(lexClass lc)
{
	if (lextype == lc)
	{
		readSym();
		return true;
	}
	return false;
}
int couldBe2(lexClass lc1, lexClass lc2)
{
	if (lextype == lc1)
	{
		readSym();
		return 1;
	}
	if (lextype == lc2)
	{
		readSym();
		return 2;
	}
	return 0;
}
void shouldBe(lexClass lc)
{
	if (lextype != lc)
	{
		error(9,lc);
	}
	readSym();
}
int shouldBe2(lexClass lc1,lexClass lc2)
{
	if (lextype != lc1&&lextype != lc2)
	{
		error(9,lc1);
	}
	readSym();
	if (lextype == lc1)return 1;
	else return 2;
}
void parseIden()
{
	shouldBe(IDEN);
	printf("This is an identifier");
}
void parseChar()
{
	shouldBe(CHR);
	printf("This is a char");
}
void parseInt()
{
	couldBe2(PLUS, MINUS);
	shouldBe(INT);
	printf("This is an integer");
}
void parseTypeIden()
{
	int r=shouldBe2(INTYP, CHARTYP);
}
void parseSubscript()
{
	shouldBe(LBRAK);
	shouldBe(INT);
	shouldBe(RBRAK);
}
void parseRelation()
{
	switch (lextype)
	{
	case LS:
	case GT:
	case GTEQU:
	case LSEQU:
	case EQU:
	case NEQU:
		readSym();
	default:
		error(13);
	}
}
void parseConstDecl()
{
	if (lextype != INTYP && lextype != CHARTYP)error(9);
	lexClass varType = lextype;
	while (true)
	{
		readSym();
		parseIden();
		shouldBe(ASSIGN);
		if(varType==INTYP)
		{
			parseInt();
		}
		else if (varType == CHARTYP)
		{
			parseChar();
		}
		if (lextype == COMMA)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	printf("This is a const declaration");
}
bool parseVarDecl()
{
	if (lextype != INTYP && lextype != CHARTYP)error(9);
	while (true)
	{
		readSym();
		parseIden();
		if (lextype == LBRAK)
		{
			parseSubscript();
		}
		else if (lextype == COMMA)
		{
			continue;
		}
		else if (lextype == LPAR)
		{
			retractSym(2);
			return RETRACT;
		}
		else
		{
			break;
		}
	}
	printf("This is a variable declaration");
	return NORMAL;
}
void parseConstGrup()
{
	//we can make sure that this is a const group by const symbol
	//this function exit with reading one more symbol
	//assume that the first sym is const,otherwise this function won`t be called.
	do
	{
		shouldBe(CONSTYP);
		parseConstDecl();
		shouldBe(SEMI);
	} while (lextype == CONSTYP);
	printf("This is a const declaration group");
}
bool parseVarGrup()
{
	bool r;
	do
	{
		r=parseVarDecl();
		if (r == RETRACT)
		{
			return RETRACT;
		}
		shouldBe(SEMI);
	} while (lextype == INT || lextype == CHARTYP);
	return NORMAL;
	printf("This is a variable declaration group");
}
void parseFuncDecl()
{
	if (couldBe(NOTYP))
	{
		if (couldBe(MAINFUNC))
		{
			mainFound = true;
			shouldBe(LPAR);
			shouldBe(RPAR);
		}
	}
	else {
		parseTypeIden();
		parseIden();
		parseParamList();
	}
	shouldBe(LCURB);
	parseCompoundStat();
	shouldBe(RCURB);
	
}
void parseParamList()
{
	shouldBe(LPAR);
	int r;
	if (!couldBe(RPAR)){
		while (true)
		{
			parseTypeIden();
			parseIden();
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
	}
}
void parseCompoundStat()
{
	if (lextype == CONSTYP)
	{
		parseConstGrup();
	}
	if (lextype == INTYP || lextype == CHARTYP)
	{
		parseVarGrup();
	}
	parseStatements();
}
void parseStatements()
{
	while(lextype != RCURB)
	{
		parseStat();
	}
}
void parseStat()
{

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
		readSym();
		parseStatements();
		shouldBe(RCURB);
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
	default:
		error(11);
	}
}
void parseExpression()
{
	couldBe2(MINUS, PLUS);
	do{
		parseTerm();
	} while (couldBe2(MINUS, PLUS)!=0);
	printf("This is an expression.");
}
void parseTerm()
{
	do {
		parseFactor();
	} while (couldBe2(STAR, DIV) != 0);
	printf("This is a term.");
}
void parseFactor()
{
	switch (lextype)
	{
	case IDEN:
		parseIden();
		if (lextype == LBRAK)
		{
			parseSubscript();
		}
		else if (lextype == LPAR)
		{
			parseArgList();
		}
		else
		{
			;
		}
		break;
	case LPAR:
		readSym();
		parseExpression();
		shouldBe(RPAR);
		break;
	case INT:
		parseInt();
		break;
	case CHR:
		parseChar();
		break;
	default:
		error(11);
	}
	printf("This is a factor.");
}
void parseConditionStat()
{
	shouldBe(IFSY);
	shouldBe(LPAR);
	parseCondition();
	shouldBe(RPAR);
	parseStatements();
	printf("This is a condition statement.");
}
void parseCondition()
{
	parseExpression();
	switch(lextype) {
	case LS:
	case LSEQU:
	case EQU:
	case NEQU:
	case GT:
	case GTEQU:
		break;
	default:
		error(14);
	}
	readSym();
	parseExpression();
	printf("This is a condition.");
}
void parseLoopStat()
{
	shouldBe(DOSY);
	shouldBe(LCURB);
	parseStatements();
	shouldBe(RCURB);
	shouldBe(WHILESY);
	shouldBe(LPAR);
	parseCondition();
	shouldBe(RPAR);
}
void parseSwitchStat()
{
	shouldBe(SWITCHSY);
	shouldBe(LPAR);
	parseExpression();
	shouldBe(RPAR);
	shouldBe(LCURB);
	parseSwitchTab();
	shouldBe(RCURB);
	printf("This is a switch statement.");
}
void parseSwitchTab()
{
	do
	{
		parseSubSwitchStat();
	} while (lextype == CASESY);
}
void parseSubSwitchStat()
{
	shouldBe(CASESY);
	parseConstant();
	shouldBe(COLON);
	parseStat();
}
void parseConstant()
{
	if (couldBe(CHR))
	{
		parseChar();
	}
	else
	{
		parseInt();
	}
}
void parseAFHead()
{
	parseIden();
	switch (lextype)
		{
		case ASSIGN:
			parseAssignStat();
			break;
		case LBRAK:
			parseSubscript();
			parseAssignStat();
			break;
		case LPAR:
			parseFuncCallStat();
			break;
		default:
			error(13);
	}
}
void parseAssignStat()
{
	shouldBe(ASSIGN);
	parseExpression();
}
void parseFuncCallStat()
{
	shouldBe(LPAR);
	parseArgList();
	shouldBe(RPAR);
	printf("This is a funcall statement.");
}
void parseArgList()
{
	do {
		parseExpression();
	} while (couldBe(COMMA));

}
void parseWriteStat()
{
	shouldBe(PRINTFUNC);
	shouldBe(LPAR);
	if (couldBe(STR))
	{
		if (couldBe(COMMA))
		{
			parseExpression();
		}
	}
	else
	{
		parseExpression();
	}
	shouldBe(RPAR);
}
void parseReadStat()
{
	shouldBe(SCANFUNC);
	shouldBe(LPAR);
	do
	{
		parseIden();
	} while (couldBe(COMMA));
	shouldBe(RPAR);
}
void parseReturnStat()
{
	shouldBe(RETURNSY);
	if (couldBe(LPAR))
	{
		parseExpression();
		shouldBe(RPAR);
	}
}
void enterVarDecl()
{
	/*
	while (true) {
		if (isTypIden())
		{
			parseDeclHead();
			if (lextype == LPAR)
			{
				readSym();
				parseParamList();
				if (lextype != RPAR)error(17);
				parseComplexStat();
				enterFuncDecl = true;
				printf("This is a variable declaration group");
				printf("This is a returnable function");
			}
			else if (lextype == LBRAK || lextyp == COMMA || lextyp == SEMI)
			{
				parseVarDeclBody();
				printf("This is a variable declaration");
			}
			else
			{
				error(18);
			}
			if (enterFuncDecl)break;
		}
	}
	*/
}
void enterFuncDecl()
{

	/*
	if(lextype==NOTYP)
	bool endProgram = false;
	while (true) {
		if (isTypIden())
		{
			parseDeclHead();
			parseParamList();
			parseComplexStat();
			printf("This is a returnable function");
		}
		else if (lextype == NOTYP)
		{
			readSym();
			if (lextype == IDEN)
			{
				readSym();
				parseParamList();
				parseComplexStat();
				printf("This is a returnable function");
			}
			else if (lextype == MAINFUNC)
			{
				readSym();
				parseParamList();
				parseComplexStat();
				printf("This is main function");
			}
			else
			{
				error();
			}
		}
		else
		{
			error(19);
		}
		if (endProgram)
		{
			break;
		}
	}*/
}
void parseProgram()
{
	if (lextype == CONSTYP)parseConstGrup();
	parseVarGrup();
	while (!mainFound) {
		parseFuncDecl();
	}
	shouldBe(END);
}
bool SyntaxAnalyze(int argc, char** argv)
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
	buffer[1] = "test/test_100.txt";
	SyntaxAnalyze(2, buffer);
	//parse();
}