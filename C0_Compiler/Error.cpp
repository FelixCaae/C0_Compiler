#include"stdafx.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Error.h"
#include "Lexeme.h"
#include "Syntax.h"
#include "SymTable.h"
#include <exception>
#include "IO.h"
using namespace std;
extern char tokenbak[tokenStrLen];
vector<string> msgStack;
int hasError = 0;
void error(int err,int detail)
{
	hasError = hasError+1;
//	char errHead[20];
//	char errTail[20];
//	char errBody[80];
	switch (err) {
	

	case ERR_ARRAY_FLOW:
	{
		sprintf(buffer, "*****Error%d: Array size can`t be %d line:%d col:%d\n", err, detail,lineCounter,columnCounter);
		break;
	}
	case ERR_ARGSTACK_FLOW:
	{
		sprintf(buffer, "*****Error%d:Argstack overflow line:%d col:%d\n", err,lineCounter,columnCounter);
	}
	case ERR_CHAR:
	{
		lextype = ERROR;
		switch (detail)
		{
		case 0:
			sprintf(buffer, "*****Error%d-0:Not legal charachter found line:%d col:%d\n",err,lineCounter,columnCounter);	
			break;
		case 1:
			sprintf(buffer, "*****Error%d-1:Can`t find matched single quote line:%d col:%d\n", err,lineCounter,columnCounter);
			break;
		case 2:
			sprintf(buffer, "*****Error%d-2:More than one charachter is found line:%d col:%d\n", err,lineCounter,columnCounter);
			break;
		}
		break;
	}
	case ERR_STR:
	{
		lextype = ERROR;
		switch (detail)
		{
		case 0:
			sprintf(buffer, "*****Error%d-0:Not legal ascii-charachter found line:%d col:%d\n", err,lineCounter,columnCounter);
			break;
		case 1:
			sprintf(buffer, "*****Error%d-1:Can`t find matched double quote line:%d col:%d\n", err,lineCounter,columnCounter);
			break;
		}
		break;
	}
	case ERR_CONST:
	{
		sprintf(buffer, "*****Error%d: Can`t assign to a const identifier:%s line:%d col:%d\n", err,NAME(detail),lineCounter);
		break;
	}
	case ERR_CASE_MATCH:
	{
		sprintf(buffer, "*****Error%d: Case constant`s type doesn`t match switch expression line:%d col:%d\n", err,lineCounter);
		break;
	}
	case ERR_DIV_ZERO:
	{
		sprintf(buffer, "*****Error%d:Div zero error", err);
		break;
	}
	case ERR_FILE:
	{
		sprintf(buffer, "*****Error%d: File error!", err);
		throw "Source file can`t open";
		break;
	}
	case ERR_INSTR_NOT_DEFINE:
	{
		sprintf(buffer, "*****Error%d:Instruction %d not defined", err, detail);
		break;
	}
	case ERR_IDEN_DECLARED:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s can`t be declared twice line:%d col:%d\n", err, tokenbak,lineCounter,columnCounter);
		break;
	}
	case ERR_IDEN_NOT_DECLARED:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s is not declared line:%d col:%d\n", err, tokenbak,lineCounter,columnCounter);
		break;
	}
	case ERR_INTOCHAR:
	{
		sprintf(buffer, "*****Error%d: Can`t turn an int-type into char-type line:%d col:%d\n", err, lineCounter,columnCounter);
		break;
	}
	case ERR_LEX_UNEX:
	{
		lextype = ERROR;
		sprintf(buffer, "*****Error%d:Unexpected character: '%c' line:%d col:%d\n", err, chr,lineCounter,columnCounter);
		break;
	}
	case ERR_LEADZERO:
	{
		lextype = ERROR;
		sprintf(buffer, "*****Error%d:Numbers can`t have leading zeroes '%s' line:%d col:%d\n", err, token,lineCounter,columnCounter);
		break;
	}
	case ERR_LEX_EX:
	{
		lextype = ERROR;
		sprintf(buffer, "*****Error%d:Expected character: '%c' but found '%c' line:%d col:%d\n", err, detail, chr,lineCounter,columnCounter);
		break;
	}
	case ERR_PARAMNUM_LESS:
	{
		sprintf(buffer, "*****Error%d: Parmeters` number is not enough(%d more is needed line:%d col:%d\n", err, detail,lineCounter,columnCounter);
		break;
	}
	case ERR_PARAMNUM_MORE:
	{
		sprintf(buffer, "*****Error%d: Parmeters` number is too much(reduce %d line:%d col:%d\n", err, detail,lineCounter,columnCounter);
		break;
	}
	case ERR_PARAMTYPE_NOT_MATCH:
	{
		sprintf(buffer, "*****Error%d: Parmeter(%d) type not matched  line:%d col:%d\n", err,detail,lineCounter);
		break;
	}
	case ERR_PARAM_FLOW:
	{
		sprintf(buffer, "*****Error%d:Functon:%s has too many arguments(more than %d)  line:%d col:%d\n", err, NAME(detail), maxParmNum,lineCounter,columnCounter);
	}
	case ERR_QCODE_NOT_DEFINE:
	{
		sprintf(buffer, "*****Error%d:QCode %d not defined", err, detail);
	}
	case ERR_REQUIRE_ARRAY:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be an array line:%d col:%d\n", err, NAME(detail),lineCounter,columnCounter);
		break;
	}
	case ERR_REQUIRE_FUNC:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be an function line:%d col:%d\n", err, NAME(detail),lineCounter,columnCounter);
		break;
	}
	case ERR_REQUIRE_RET:
	{
		sprintf(buffer, "*****Error%d: Function:%s doesn`t has a return value line:%d col:%d\n", err, NAME(detail),lineCounter,columnCounter);
		break;
	}
	case ERR_REQUIRE_VAR:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be a variable line:%d col:%d\n", err, NAME(detail),lineCounter,columnCounter);
		break;
	}
	case ERR_SYNTAX:
	{
		sprintf(buffer, "*****Error%d: Should be %s but found %s line:%d col:%d\n", err, lexClassName[detail - 1], lexClassName[lextype - 1],lineCounter,columnCounter);
		break; }
	case ERR_SYM_RETRACT:
	{
		sprintf(buffer, "*****Error%d: Can`t retract sym\n", err);
		break;
	}
	case ERR_TOKEN_FLOW:
	{
		sprintf(buffer, "*****Error%d:Word is too long!", err);
		break; }
	default:
	{
		sprintf(buffer, "****Error%d: Error not defined. line:%d col:%d\n", err,lineCounter,columnCounter);
	}
	}
	//output(buffer,outErr,true);
	msgStack.push_back(string(buffer));
}
void printErrInfo()
{
	vector<string>::iterator it;
	for (it = msgStack.begin(); it != msgStack.end(); it++)
	{
		output(it->c_str(), outErr, true);
	}
	string total = "Total errors:"+to_string(hasError)+"\n";
	output(total.c_str(), outErr, true);
}
