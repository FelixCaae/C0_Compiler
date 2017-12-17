#pragma once
#include "Syntax.h"
#include "CodeGen.h"
#include "stdio.h"
#include <string>
#define NAME(arg) symTable[arg]._name
#define STRNAME(arg) strTable[arg]._adr
#define TYPE(arg) typeName[symTable[arg]._type]
#define REF(arg) symTable[arg]._ref
#define LABEL(arg) labelTable[arg]
#define OP(arg) (symTable[arg]._obj==OCONST?to_string(symTable[arg]._ref).c_str():NAME(arg))
#define STR(arg) strTable[arg]._buffer
#define REG(arg) regName[arg]
extern FILE * inFile;
extern FILE * outLex;
extern FILE * outSyntax;
extern FILE * outQCode;
extern FILE * outTCode;
extern FILE * outErr;
extern bool toConsole;
extern char buffer[];
const  bool bOutSyntax = false;
const bool bOutQcode = true;
const bool bOutLex = false;
const bool bOutTCode = true;
const unsigned int maxOutputLength = 88;
const char * const syntaxClassName[] = {
	"unsignedInt","identifier", "char", "string","seperator","keyword",
	"type","integer","relationOp","compoundStatement", "constDeclGroup", "constDecl",
	"varDeclGroup", "varDecl", "funcDecl","funcHead", "paramList",
	"statements", "statement", "assignStat", "funCallStat", "term",
	"expression", "factor", "condition", "constant", "loopStat",
	"argumentList", "switchStat", "switchTable", "subSwitchStat", "constant",
	"readStat", "writeStat", "returnStat","program",
	"retract","error","end"
};
const char * const lexClassName[] =
{
	"INT","IDEN","CHR","STR","ASSIGN","LCURB","RCURB","COMMA","SEMI","COLON","LPAR","RPAR","LBRAK","RBRAK","PLUS","MINUS",
	"STAR","DIV","GT","LS","GTEQU","LSEQU","EQU","NEQU",
	"INTYP","CHARTYP","NOTYP","CONSTYP","IFSY","DOSY","WHILESY","SWITCHSY","CASESY",
	"RETURNSY","PRINTFUNC","SCANFUNC","MAINFUNC","INVALIDSYM","ENDOFINPUT"
};
const char *const typeName[] =
{
	"int","char","void"
};
const char *const tCodeName[] =
{
	"add","addi","sub","subi","div","mult","lw","sw","jump","jal","bne","beq"
};
const char *const regName[] =
{
	"$0","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1",
	"$s2","$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"
};

void outputLexeme();
void outputSyntax(syntaxClass sc, bool isHead = true);
void outputTerminalS(syntaxClass sc);
void outputQCode(qCType qc, int arg1, int arg2, int arg3);
void outputOCode();
void output(char*ch,FILE* outFile,bool toConsole=false);
void init(int argc, char**argv);
void close();
