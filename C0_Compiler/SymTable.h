#pragma once
#include "Lexeme.h"
#include "Syntax.h"
#define EXIST(arg) arg!=NotExist
#define NEXT(arg) symTable[arg]._next
#define ISGLOBAL(arg) symTable[arg]._adr==Global
#define ADR(arg) symTable[arg]._adr
#define OBJ(arg) symTable[arg]._obj
#define TYP(arg) symTable[arg]._type
#define ISVAR(arg) OBJ(arg)==OVAR
#define ISARRAY(arg) OBJ(arg)==OARRAY
#define ISCONST(arg) OBJ(arg)==OCONST
#define ISINT(arg) symTable[arg]._type==INTS
#define ISCHAR(arg) symTable[arg]._type==CHARS
const unsigned int maxStrLength = 100;
const unsigned int symTableSize=800;
const unsigned int constTableSize = 800;
const unsigned int strTableSize = 400;
const unsigned int funcTableSize = 400;
const unsigned int maxLabelStrLen = 100;
const unsigned int maxLabelNum = 800;
const unsigned int maxParmNum = 12;
const unsigned int IntSize = 4;
const unsigned int CharSize = 1;
const int NotFound = -1;
const int NotExist = -1;
const int SearchAll = -1;
const int Global = -1;
extern unsigned int funcRef;
extern unsigned int linkHead;
extern const unsigned int linkGlobal;
struct symTableEntry
{
	char _name[tokenStrLen];
	IdenType _type;
	IdenObj _obj;
	unsigned int _next;
	int _ref;//维数 表引用 
	unsigned int _adr;//地址分配

};
struct strTableEntry
{
	char _buffer[maxStrLength];
	char _adr[tokenStrLen];
};
struct funcTableEntry
{
	IdenType _ret;
	int _paraNum;
	IdenType _param[maxParmNum];
	int _size;
};
enum lableType
{
	LFUNC, LFUNCEND, LIF, LWHILE, LSWITCH, LCASE, L
};
extern symTableEntry symTable[strTableSize];
extern funcTableEntry funcTable[funcTableSize];
//extern conTableEntry conTable[constTableSize];
extern strTableEntry strTable[strTableSize];
extern char labelTable[maxLabelNum][maxLabelStrLen];
void cleanup();
void link(int entry);
void unlink();
void unlinkAll();
void enterFunc(unsigned int ref);
void leaveFunc();
void locateAdr();
int countSize(int iden);
int insertIdent(char *name, IdenType type, IdenObj obj, int ref = 0);
int lookupIdent(char *name,int scope);
int lookupIdent(char *name);
int lookupStr(char *str);
void modifyIdent(int ident, IdenType type, IdenObj obj, int ref=0);
int insertString(char *str);
int insertFunc(IdenType ret,int paranum,IdenType paramtype[]);
//int insertReal(int val);
int genTemp(IdenType it,bool isConst=false,int val=0);
int genLabel(lableType lt, char*name = 0);