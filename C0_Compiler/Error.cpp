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
void skip(lexClass lexSet[],int num)
{
	bool found = false;
	while (true)
	{
		for (int i = 0; i < num; i++)
		{
			if (lexSet[i] == lextype)
			{
				found = true;
				break;
			}
		}
		if (found)break;
		readSym();
	}
}
void error(int err,int detail)
{
	hasError = hasError+1;
//	char errHead[20];
//	char errTail[20];
//	char errBody[80];
	switch (err) {
	

	case ERR_ARRAY_FLOW:
	{
		sprintf(buffer, "*****Error%d: Array size can`t be %d line:%d\n", err, detail, lineCounter);
		break; }
	case ERR_ARGSTACK_FLOW:
	{
		sprintf(buffer, "*****Error%d:Argstack overflow line:%d", err,lineCounter);
	}
/*	case 2:
	{
		sprintf(buffer, "Error2:in parsing ident: %s", token);
		break; }
	case 3:
	{
		sprintf(buffer, "Error3:in parsing number: %s", token);
		break; }
	case 4:
	{
		sprintf(buffer, "Error in parsing char: %s", token);
		break; }
	case 5:
	{
		sprintf(buffer, "Error in parsing string: %s", token);
		break; }
	case 6:
	{
		sprintf(buffer, "Error in parsing seperator: %s", token);
		break; }*/
	case ERR_CHAR:
	{
		lextype = ERROR;
		switch (detail)
		{
		case 0:
			sprintf(buffer, "*****Error%d:Not legal charachter found line:%d\n",err,lineCounter);	
			break;
		case 1:
			sprintf(buffer, "*****Error%d:Can`t find matched single quote line:%d\n", err, lineCounter);
			break;
		case 2:
			sprintf(buffer, "*****Error%d:More than one charachter is found line:%d\n", err, lineCounter);
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
			sprintf(buffer, "*****Error%d:Not legal ascii-charachter found line:%d\n", err, lineCounter);
			break;
		case 1:
			sprintf(buffer, "*****Error%d:Can`t find matched double quote line:%d\n", err, lineCounter);
			break;
		}
		break;
	}
	case ERR_CONST:
	{
		sprintf(buffer, "*****Error%d: Can`t assign to a const identifier:%s line:%d\n", err,NAME(detail),lineCounter);
		break;
	}
	case ERR_CASE_MATCH:
	{
		sprintf(buffer, "*****Error%d: Case constant`s type doesn`t match switch expression line:%d\n", err,lineCounter);
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
		sprintf(buffer, "*****Error%d: Identifier:%s can`t be declared twice line:%d\n", err, tokenbak, lineCounter);
		break;
	}
	case ERR_IDEN_NOT_DECLARED:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s is not declared line:%d\n", err, tokenbak, lineCounter);
		break;
	}
	case ERR_INTOCHAR:
	{
		sprintf(buffer, "*****Error%d: Can`t turn an int-type into char-type line:%d\n", err,  lineCounter);
		break;
	}
	case ERR_LEX_UNEX:
	{
		lextype = ERROR;
		sprintf(buffer, "*****Error%d:Unexpected character: '%c' line:%d\n", err, chr, lineCounter);
		break;
	}
	case ERR_LEADZERO:
	{
		lextype = ERROR;
		sprintf(buffer, "*****Error%d:Numbers can`t have leading zeroes '%s' line:%d\n", err, token, lineCounter);
		break;
	}
	case ERR_LEX_EX:
	{
		lextype = ERROR;
		sprintf(buffer, "*****Error%d:Expected character: '%c' but found '%c' line:%d\n", err, detail, chr, lineCounter);
		break;
	}
	case ERR_PARAMNUM_LESS:
	{
		sprintf(buffer, "*****Error%d: Parmeters` number is not enough(%d more is needed line:%d\n", err, detail, lineCounter);
		break;
	}
	case ERR_PARAMNUM_MORE:
	{
		sprintf(buffer, "*****Error%d: Parmeters` number is too much(reduce %d line:%d\n", err, detail, lineCounter);
		break;
	}
	case ERR_PARAMTYPE_NOT_MATCH:
	{
		sprintf(buffer, "*****Error%d: Parmeter(%d) type not matched  line:%d\n", err,detail,lineCounter);
		break;
	}
	case ERR_PARAM_FLOW:
	{
		sprintf(buffer, "*****Error%d:Functon:%s has too many arguments(more than %d)  line:%d\n", err, NAME(detail), maxParmNum, lineCounter);
	}
	case ERR_QCODE_NOT_DEFINE:
	{
		sprintf(buffer, "*****Error%d:QCode %d not defined", err, detail);
	}
	case ERR_REQUIRE_ARRAY:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be an array line:%d\n", err, NAME(detail), lineCounter);
		break;
	}
	case ERR_REQUIRE_FUNC:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be an function line:%d\n", err, NAME(detail), lineCounter);
		break;
	}
	case ERR_REQUIRE_RET:
	{
		sprintf(buffer, "*****Error%d: Function:%s doesn`t has a return value line:%d\n", err, NAME(detail), lineCounter);
		break;
	}
	case ERR_REQUIRE_VAR:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be a variable line:%d\n", err, NAME(detail), lineCounter);
		break;
	}
	case ERR_SYNTAX:
	{
		sprintf(buffer, "*****Error%d: Should be %s but found %s line:%d\n", err, lexClassName[detail - 1], lexClassName[lextype - 1], lineCounter);
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
		sprintf(buffer, "****Error%d: Error not defined. line:%d\n", err, lineCounter);
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
