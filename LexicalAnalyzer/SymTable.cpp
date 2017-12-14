#include <cstring>
#include <stdio.h>
#include "stdafx.h"
#include "SymTable.h"
#include "Error.h"
#include <string.h>
symTableEntry symTable[strTableSize];
//conTableEntry conTable[constTableSize];
funcTableEntry funcTable[funcTableSize];
strTableEntry strTable[strTableSize];
unsigned int curLevPos=0;
unsigned int curSym=0;
unsigned int curStr = 0;
unsigned int curCon = 0;
unsigned int curFunc = 0;
unsigned const int linkGlobal = 0;
unsigned int linkHead = NotExist;
unsigned int linkTail = NotExist;
unsigned int linkBak = NotExist;
unsigned int tempCounter = 0;
void enterFunc()
{
	linkHead = NotExist;
	linkBak = linkTail;
	linkTail = NotExist;
	tempCounter = 0;
}
void leaveFunc()
{
	linkHead = linkGlobal;
	linkTail = linkBak;
}
void link(int entry)
{
	if (linkHead == NotExist)
	{
		linkHead=entry;
	}
	if (linkTail != NotExist) {
		symTable[linkTail]._next = entry;
		linkTail = entry;
	}
	symTable[entry]._next = NotExist;
	linkTail = entry;
}
void cleanup()
{
	linkTail = NotExist;
	linkHead = NotExist;
	curFunc = 0;
	curSym = 0;
	curStr = 0;
}
int lookupStr(char*str);
int insertIdent(char *name, IdenType type, IdenObj obj,int ref)
{
	int r;
	if (curSym == symTableSize)
	{
		error(ERR_TAB_FLOW);
		r = NotExist;
	}
	if (NotFound == lookupIdent(name,linkHead))
	{
		strcpy(symTable[curSym]._name,name);
		symTable[curSym]._obj = obj;
		symTable[curSym]._type = type;
		symTable[curSym]._ref = ref;
		link(curSym);
		if (curSym != 0)
		{
			symTable[curSym]._adr = symTable[curSym - 1]._adr+1;
		}
		r = curSym;
		curSym++;
	}
	else
	{
		r = NotExist;
		error(ERR_IDEN_DECLARED);
	}
	return r;
}
int insertString(char *str)
{
	int r=lookupStr(str);
	if (r == NotFound)
	{
		r = curStr;
		strcpy(strTable[curStr]._buffer,str);
		curStr += 1;
	}
	return r;
}
int insertFunc(IdenType ret, int paranum, IdenType paramtype[])
{
	funcTable[curFunc]._paraNum = paranum;
	funcTable[curFunc]._ret = ret;
	for (int i = 0; i < paranum; i++)
	{
		funcTable[curFunc]._param[i] = paramtype[i];
	}
	return curFunc++;
}
int lookupStr(char *str)
{
	for (int i = 0; i < curStr; i++)
	{
		if (strcmp(str, strTable[i]._buffer) == 0)
		{
			return i;
		}
	}
	return NotFound;
}
int lookupIdent(char *name,int scope)
{

	int i = scope;
	while (i != NotExist)
	{
		if (strcmp(symTable[i]._name, name) == 0)
		{
			return i;
		}
		i = symTable[i]._next;
	}
	return NotFound;
}
int lookupIdent(char *name)
{
	int id = lookupIdent(name, linkHead);
	if (id == NotExist)id = lookupIdent(name, linkGlobal);
	return id;
}
int genTemp(IdenType it,bool isConst,int val)
{
	char tempName[tokenStrLen];
	do{
		sprintf(tempName, "tmp%d", tempCounter++);
	} while (lookupIdent(tempName) != NotExist);
	IdenObj io=OVAR;
	if (isConst)
	{
		io = OCONST;
	}
	return insertIdent(tempName, it, io,val);
}