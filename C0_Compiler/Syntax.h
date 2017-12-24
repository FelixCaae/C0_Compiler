#pragma once
#include "Lexeme.h"
const bool RETRACT = true;
const bool NORMAL = false;
enum syntaxClass {
	SINT=1, SIDEN, SCHAR, SSTR, SSEP, SKEY, TYPE,INTEGER,SRELATION,
	COMPOUNDSTAT,CONSTGRUP,CONSTDECL,
	VARGRUP,VARDECL,FUNCDECL,FUNCHEAD,PARAMLIST,
	STATS,STAT,ASSIGNSTAT,FUNCALLSTAT,TERM,
	EXPRESSION,FACTOR,CONDITION,CONDSTAT,LOOPSTAT,
	ARGLIST,SWITCHSTAT,SWITCHTAB,SUBSWITCHSTAT,CONSTANT,
	READSTAT,WRITESTAT,RETURNSTAT,PROGRAM,
	SRETRACT,SERROR,SEND
};
enum IdenType
{
	INTS,CHARS,NOTYPS
};
enum IdenObj
{
	OVAR=1,OCONST,OARRAY,OFUNC
};
const lexClass skipSet1[]={SEMI};
const lexClass funcHead[] = { RCURB };
const int terminalSet[] =  { SIDEN,SINT,SCHAR,SSTR,SSEP,SKEY };
syntaxClass lexToSyntax();
void matchTest();
void syntaxAnalyze(int argc, char**argv);
extern int slevel;