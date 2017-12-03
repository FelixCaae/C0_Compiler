#pragma once

const unsigned int tokenStrLen = 100;
const unsigned int lexNameLen=20;
const unsigned int sepNum = 17;
const unsigned int blankNum = 4;
const unsigned int resrvNum = 13;
const unsigned int maxRetractNum = 5;
extern char chr;
extern char token[tokenStrLen];
extern int lineCounter, columnCounter;
extern int tokenidx ;
extern int nodesNum ;
const char sepSet[] = { '=','{','}',',',';',':','(',')','[',']','+','-',
'*','/','>','<','!'
};
const char blankSet[] = { ' ','\n','\t','\0'};
const char resrvWrdsSet[][lexNameLen] = { "int","char","void","const","if","do","while","switch",
"case","return","printf","scanf","main"
};
const char lexClassName[][lexNameLen] =
{
	"INT","IDEN","CHR","STR","ASSIGN","LCURB","RCURB","COMMA","SEMI","COLON","LPAR","RPAR","LBRAK","RBRAK","PLUS","MINUS",
	"STAR","DIV","GT","LS","GTEQU","LSEQU","EQU","NEQU",
	"INTYP","CHARTYP","NOTYP","CONSTYP","IFSY","DOSY","WHILESY","SWITCHSY","CASESY",
	"RETURNSY","PRINTFUNC","SCANFUNC","MAINFUNC"
};
enum lexClass
{
	INT=1, IDEN, CHR, STR, ASSIGN, LCURB, RCURB, COMMA, SEMI, COLON, LPAR, RPAR, LBRAK, RBRAK, PLUS, MINUS,
	STAR, DIV, GT, LS, GTEQU, LSEQU, EQU, NEQU,
	INTYP, CHARTYP, NOTYP, CONSTYP, IFSY, DOSY, WHILESY, SWITCHSY, CASESY,
	RETURNSY, PRINTFUNC, SCANFUNC, MAINFUNC,
	ERROR,END,RELATION//
};
extern lexClass lextype;
unsigned int catToNum();
void catToString(char*);
void readSym();
void retractSym(int num=1);