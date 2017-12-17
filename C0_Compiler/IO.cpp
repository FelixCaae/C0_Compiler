#include"stdafx.h"
#include "direct.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include "IO.h"
#include "Error.h"
#include "Lexeme.h"
#include "SymTable.h"
#include "CodeGen.h"
using namespace std;
using namespace std;
bool toConsole = true;
FILE * inFile=NULL;
FILE * outLex=NULL;
FILE * outSyntax=NULL;
FILE * outQCode=NULL;
FILE * outTCode = NULL;
FILE * outErr=NULL;
char buffer[maxOutputLength];

void output(char *ch,FILE* outFile,bool toConsole)
{
	if(toConsole)
	{ 
		printf(ch);
	}
	if (outFile)
	{
		fprintf(outFile, ch);
	}
}
void outputLexeme()
{
	sprintf(buffer, "%d\t%s\t%s\trow:%d\tcolmn:%d\n", lextype, lexClassName[lextype - 1], token, lineCounter, columnCounter);
	output(buffer, outLex,bOutLex);
}
void blank()
{
	for (int i = 0; i < 2 * (slevel - 1);i++)
	{
		output(" ", outSyntax,bOutSyntax);
	}
}
void outputTerminalS(syntaxClass sc)
{
		blank();
		sprintf(buffer, "<%s> %s <\\%s>\n", syntaxClassName[sc - 1], token, syntaxClassName[sc - 1]);
		output(buffer, outSyntax,bOutSyntax);
}
void outputSyntax(syntaxClass sc,bool isHead)
{ 
		char* hformat = "<%s>\n";
		char* tformat = "<\\%s>\n";
		if (isHead)
		{
			slevel += 1;
			blank();
			sprintf(buffer, hformat, syntaxClassName[sc - 1]);
			output(buffer, outSyntax, bOutSyntax);
		}
		else
		{
			blank();
			slevel -= 1;
			sprintf(buffer, tformat, syntaxClassName[sc - 1]);
			output(buffer, outSyntax, bOutSyntax);
		}
}
void outputQCode(qCType qc, int arg1, int arg2, int arg3)
{
	char numbuff1[20],numbuff2[20];
	char* str;
	if (qc != QLABEL)
	{
		buffer[0] = '\t';
		str = buffer + 1;
	}
	else
	{
		str = buffer;
	}
	switch (qc)
	{
	case QVAR:
		sprintf(str, "var %s %s", TYPE(arg1),NAME(arg1));
		break;
	case QCONST:
		sprintf(str, "const %s %s = %d", TYPE(arg1), NAME(arg1),REF(arg1));
		break;
	case QARRAY:
		sprintf(str, "array %s %s[%d]", TYPE(arg1), NAME(arg2), REF(arg1));
		break;
	case QFUNCDECL:
		sprintf(str, "%s %s()", typeName[symTable[arg1]._type], symTable[arg1]._name);
		break;
	case QPARA:
		sprintf(str, "para %s %s", typeName[symTable[arg1]._type], symTable[arg1]._name);
		break;
	case QPRINT:
		if (arg1 == FSTRING) {
			sprintf(str, "print \"%s\"",STR(arg2));
		}
		else if (arg1 == FEXPRESSION)
		{
			string a;
			sprintf(str, "print %s", OP(arg2));
		}
		break;
	case QREAD:
		sprintf(str, "read %s", NAME(arg1));
		break;
	case QRET:
		if (arg1 !=NotExist)
		{
			sprintf(str, "ret %s", OP(arg1));
		}
		else
		{
			sprintf(str, "ret");
		}
		break;
	case QPLUS:
		sprintf(str, "%s = %s + %s", NAME(arg1), OP(arg2), OP(arg3));
		break;
	case QMINUS:
		sprintf(str, "%s = %s - %s", NAME(arg1), OP(arg2), OP(arg3));
		break;
	case QSTAR:
		sprintf(str,"%s = %s * %s", NAME(arg1), OP(arg2), OP(arg3));
		break;
	case QDIV:
		sprintf(str, "%s = %s / %s", NAME(arg1), OP(arg2), OP(arg3));
		break;
	case QASSIGN:
		sprintf(str, "%s = %s ", NAME(arg1), OP(arg2));
		break;
	case QPUSH:
		sprintf(str, "push %s", OP(arg1));
		break;
	case QCALL:
		sprintf(str, "call %s",NAME(arg1));
		break;
	case QRETX:
		sprintf(str, "%s = RET", NAME(arg1));
		break;
	case QARR:
		sprintf(str, "%s = %s[%s]", NAME(arg1), NAME(arg2), OP(arg3));
		break;
	case QARL:
		sprintf(str, "%s[%s] = %s", NAME(arg1), OP(arg2), NAME(arg3));
		break;
	case QBZ:
		sprintf(str, "BZ %s", LABEL(arg1));
		break;
	case QBNZ:
		sprintf(str, "BNZ %s", LABEL(arg1));
		break;
	case QGOTO:
		sprintf(str, "GOTO %s", LABEL(arg1));
		break;
	case QLABEL:
		sprintf(str, "%s:", LABEL(arg1));
		break;
	case QGT:
		sprintf(str, "%s > %s", OP(arg1),OP(arg2));
		break;
	case QGTEQU:
		sprintf(str, "%s >= %s", OP(arg1), OP(arg2));
		break;
	case QLS:
		sprintf(str, "%s < %s", OP(arg1), OP(arg2));
		break;
	case QLSEQU:
		sprintf(str, "%s <= %s", OP(arg1), OP(arg2));
		break;
	case QEQU:
		sprintf(str, "%s == %s", OP(arg1), OP(arg2));
		break;
	case QNEQU:
		sprintf(str, "%s != %s", OP(arg1), OP(arg2));
		break;
	default:
		break;
	}
	strcat(str, "\n");
	output(buffer,outQCode,bOutQcode);
}
void outputOCode()
{
	strcat(buffer, "\n");
	//output("\t", outTCode, true);
	output(buffer, outTCode, bOutTCode);
}
char * getFileName(char *arg)
{
	char* cur=arg,*lastSplit = arg;
	while (*cur != '\0')
	{
		if (*cur == '/')
		{
			lastSplit = cur+1;
		}
		cur++;
	}
	return lastSplit;
}
void init(int argc, char ** argv)
{
	if (argc != 2 )
	{
		error(ERR_INPUT_ARGUMENT_NUM);
	}
	FILE* f = NULL;
	char* c = argv[1];
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		error(ERR_FILE);
	}
	inFile = f;
	char name[100];
	char rawname[100];
	_mkdir("result");
	strcpy(rawname, getFileName(argv[1]));
	strcpy(name, "result/lex_");
	strcat(name, rawname);
	f = fopen(name, "w+");
	if (f == NULL)
	{
		error(ERR_FILE);
	}
	outLex = f;
	strcpy(name, "result/syntax_");
	strcat(name, rawname);
	f = fopen(name, "w+");
	if (f == NULL)
	{
		error(ERR_FILE);
	}
	outSyntax = f;
	strcpy(name, "result/err_");
	strcat(name, rawname);
	f = fopen(name, "w+");
	if (f == NULL)
	{
		error(ERR_FILE);
	}
	outErr = f;
	strcpy(name, "result/quat_");
	strcat(name, rawname);
	f = fopen(name, "w+");
	if (f == NULL)
	{
		error(ERR_FILE);
	}
	outQCode = f;
	strcpy(name, "result/mips_");
	strcat(name, rawname);
	f = fopen(name, "w+");
	if (f == NULL)
	{
		error(ERR_FILE);
	}
	outTCode = f;
}
void close()
{
	if(inFile)fclose(inFile);
	if (outLex)fclose(outLex);
	if (outSyntax)fclose(outSyntax);
	if (outErr)fclose(outErr);
	if (outQCode)fclose(outQCode);
	if (outTCode)fclose(outTCode);
}