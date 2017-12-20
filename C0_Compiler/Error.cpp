#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Error.h"
#include "Lexeme.h"
#include "Syntax.h"
#include <exception>
#include "IO.h"
extern char tokenbak[tokenStrLen];
void skip()
{

	do {
		readSym();
	}
	while (lextype != SEMI);
}
void error(int err,int detail)
{
	//printf("Error happended!");
	char buffer[100];
	switch (err) {
	case ERR_FILE:
	{
		sprintf(buffer, "*****Error%d: File error!",err);
		break;
	}
	case ERR_TOKEN_FLOW:
	{
		sprintf(buffer, "Error%d:Word is too long!",err);
		break; }
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
	case ERR_LEX:
	{
		sprintf(buffer, "Error%d:Unexpected character: '%c' line:%d\n",err,detail,lineCounter);
		break; }
	case ERR_SYNTAX:
	{
		sprintf(buffer, "*****Error%d: Should be %s but found %s line:%d\n",err, lexClassName[detail - 1], lexClassName[lextype - 1], lineCounter);
		break; }
	case ERR_SYM_RETRACT:
	{
		sprintf(buffer, "*****Error%d: Can`t retract sym\n",err);
		break; }
	case ERR_ARRAY_FLOW:
	{
		sprintf(buffer, "*****Error%d: Array size can`t be %d line:%d\n", err, detail,lineCounter);
		break; }
	case ERR_CONST:
	{
		sprintf(buffer, "*****Error%d: Can`t assign to a const identifier:%s line:%d\n", err,token,lineCounter);
		break;
	}
	case ERR_CASE_MATCH:
	{
		sprintf(buffer, "*****Error%d: Case constant`s type doesn`t match switch expression line:%d\n", err,lineCounter);
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
		sprintf(buffer, "*****Error%d: Parmeter:%s type is not matched line:%d\n", err, token, lineCounter);
		break;
	}
	case ERR_REQUIRE_ARRAY:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be an array line:%d\n", err, token, lineCounter);
		break;
	}
	case ERR_REQUIRE_FUNC:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be an function line:%d\n", err, token, lineCounter);
		break;
	}
	case ERR_REQUIRE_RET:
	{
		sprintf(buffer, "*****Error%d: Function:%s doesn`t has a return value line:%d\n", err, token, lineCounter);
		break;
	}
	case ERR_REQUIRE_VAR:
	{
		sprintf(buffer, "*****Error%d: Identifier:%s should be a variable line:%d\n", err, token, lineCounter);
		break;
	}
	case ERR_DIV_ZERO:
	{
		sprintf(buffer, "*****Error%d:Div zero error", err);
		break;
	}
	case ERR_INSTR_NOT_DEFINE:
	{
		sprintf(buffer, "*****Error%d:Instruction %d not defined", err, detail);
		break;
	}
	case ERR_QCODE_NOT_DEFINE:
	{
		sprintf(buffer, "*****Error%d:QCode %d not defined", err, detail);
	}
	default:
	{
		sprintf(buffer, "****Error%d: Error not defined. line:%d\n", err, lineCounter);
	}
	}
	/*
	case 11:
	{
		sprintf(buffer, "*****Error11: Should be %s but found %s at line:%d\n", syntaxClassName[STAT - 1], lexClassName[lextype - 1], lineCounter);
		break; }
	case 12:
	{
		sprintf(buffer, "*****Error12: Should be %s  but found %s at line:%d\n", syntaxClassName[FACTOR - 1], lexClassName[lextype - 1], lineCounter);
		break; }
	case 13:
	{
		sprintf(buffer, "*****Error13: Should be %s but found %s at line:%d\n", syntaxClassName[RELATION - 1], lexClassName[lextype - 1], lineCounter);
		break; }
	case 14:
	{
		sprintf(buffer, "*****Error14: Should be %s but found %s at line:%d\n", "ASSIGNSTAT or FUNCALLSTAT ", lexClassName[lextype - 1], lineCounter);
		break; }
	case 15:
	{
		sprintf(buffer, "*****Error15: Should be %s but found %s at line:%d\n", syntaxClassName[CONDITION - 1], lexClassName[lextype - 1], lineCounter);
		break; }
	}
	*/
	output(buffer,outErr,true);
	close();
	throw buffer;
}
void error(int err)
{
	error(err, 0);
}