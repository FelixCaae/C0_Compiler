#pragma once
#include "Lexeme.h"
#include "Syntax.h"
const unsigned int maxStrLength = 100;
const unsigned int symTableSize=800;
const unsigned int constTableSize = 800;
const unsigned int strTableSize = 400;
const unsigned int funcTableSize = 400;
const unsigned int maxParmNum = 20;
const int NotFound = -1;
const int NotExist = -1;
const int SearchAll = -1;
extern unsigned int linkHead;
extern const unsigned int linkGlobal;
struct symTableEntry
{
	char _name[tokenStrLen];
	IdenType _type;
	IdenObj _obj;
	unsigned int _next;
	unsigned int _ref;//维数 表引用 
	unsigned int _adr;//地址分配

};
struct strTableEntry
{
	char _buffer[maxStrLength];
};
struct funcTableEntry
{
	IdenType _ret;
	int _paraNum;
	IdenType _param[maxParmNum];
};
extern symTableEntry symTable[strTableSize];
extern funcTableEntry funcTable[funcTableSize];
//extern conTableEntry conTable[constTableSize];
extern strTableEntry strTable[strTableSize];
int insertIdent(char *name, IdenType type, IdenObj obj, int ref = 0);
int lookupIdent(char *name,int scope);
int lookupIdent(char *name);
int insertString(char *str);
int insertFunc(IdenType ret,int paranum,IdenType paramtype[]);
//int insertReal(int val);
void cleanup();
void enterFunc();
void leaveFunc();
int genTemp(IdenType it,bool isConst=false,int val=0);