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
unsigned int funcRef=NotExist;
unsigned int curLevPos=0;
unsigned int curSym=0;
unsigned int curStr = 0;
unsigned int curCon = 0;
unsigned int curFunc = 0;
unsigned int labelID = 0;
unsigned int caseID = 0;
unsigned int tempCounter = 0;
unsigned int labelCounter = 0;
unsigned const int linkGlobal = 0;
unsigned int linkHead = NotExist;
unsigned int linkTail = NotExist;
unsigned int linkBak = NotExist;
char labelTable[maxLabelNum][maxLabelStrLen];
void locateAdr();
int countSize(int iden);
void cleanup()
{
	linkTail = NotExist;
	linkHead = NotExist;
	curFunc = 0;
	curSym = 0;
	curStr = 0;
}
int genTemp(IdenType it, bool isConst, int val)
{
	char tempName[tokenStrLen];
	sprintf(tempName, "$tmp%d", tempCounter++);

	IdenObj io = OVAR;
	if (isConst)
	{
		io = OCONST;
	}
	return insertIdent(tempName, it, io, val);
}
void enterFunc(unsigned int ref)
{
	funcRef = ref;
	linkHead = NotExist;
	linkBak = linkTail;
	linkTail = NotExist;
	tempCounter = 0;
}
void leaveFunc()
{
	funcRef = NotExist;
	unlinkAll();
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
void unlink()
{
	if (linkHead == NotExist)return;
	int entry = curSym - 1;
	if (linkHead == entry)
	{
		linkHead = NotExist;
		linkTail = NotExist;
		curSym--;
	}
	else
	{
		linkTail--;
		curSym--;
		symTable[curSym]._next = NotExist;
	}
}
void unlinkAll()
{
	while (linkTail != NotExist)
	{
		unlink();
	}
}
int insertIdent(char *name, IdenType type, IdenObj obj,int ref)
{
	if (curSym == symTableSize)
	{
		error(ERR_TAB_FLOW);
		return  NotExist;
	}
	if (NotFound == lookupIdent(name,linkHead))
	{
		link(curSym);
		strcpy(symTable[curSym]._name,name);
		symTable[curSym]._obj = obj;
		symTable[curSym]._type = type;
		symTable[curSym]._ref = ref;
		if (funcRef == NotExist)
		{
			symTable[curSym]._adr = Global;
		}
		return curSym++;
	}
	error(ERR_IDEN_DECLARED);
	return NotExist;
}
void modifyIdent(int iden, IdenType type, IdenObj obj, int ref)
{
	symTable[iden]._type = type;
	symTable[iden]._obj = obj;
	symTable[iden]._ref = ref;
}
int insertString(char *str)
{
	int r=lookupStr(str);
	if (r == NotFound)
	{
		r = curStr;
		strcpy(strTable[curStr]._buffer,str);
		sprintf(strTable[curStr]._adr, "Str_%d", curStr);
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
	while (i != NotExist&&i<curSym)
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
	if (id == NotFound)id = lookupIdent(name, linkGlobal);
	return id;
}
void locateAdr()
{
	int entry = linkHead;
	int adr=0,size=0;
	while (entry != NotExist)
	{
		if (symTable[entry]._type == INTS) {
			symTable[entry]._adr = adr;
			adr += countSize(entry);
		}
		entry = symTable[entry]._next;
	}
	entry=linkHead;
	while (entry != NotExist)
	{
		if (symTable[entry]._type == CHARS) {
			symTable[entry]._adr = adr;
			adr += countSize(entry);
		}
		entry = symTable[entry]._next;
	}
	adr += (4 - adr % 4);//round up
	if(funcRef!=NotExist)
		FUNCSIZE(funcRef) = adr;
}
int countSize(int iden)
{
	int tsize;
	if (symTable[iden]._type == INTS)
	{
		tsize = IntSize;
	}
	else if (symTable[iden]._type == CHARS)
	{
		tsize = CharSize;
	}
	if (symTable[iden]._obj == OVAR)
	{
		return tsize;
	}
	else if (symTable[iden]._obj == OCONST)
	{
		return 0;
	}
	else if (symTable[iden]._obj == OARRAY)
	{
		return tsize*symTable[iden]._ref;
	}
	else if (symTable[iden]._obj == OFUNC)
	{
		return 0;
	}
	return 0;
}
int genLabel(lableType lt, char *name)
{
	switch (lt)
	{
	case LIF:
		sprintf(labelTable[labelCounter], "if_%d", ++labelID);
		break;
	case LWHILE:
		sprintf(labelTable[labelCounter], "do_%d", ++labelID);
		break;
	case LSWITCH:
		sprintf(labelTable[labelCounter], "switch_%d", ++labelID);
		caseID = 0;
		break;
	case LCASE:
		sprintf(labelTable[labelCounter], "case_%d_%d", labelID, ++caseID);
		break;
	case LFUNC:
		sprintf(labelTable[labelCounter], name);
		break;
	case LFUNCEND:
		sprintf(labelTable[labelCounter], name);
		strcat(labelTable[labelCounter], "_end");
		break;
	case L:
		sprintf(labelTable[labelCounter], name);
		break;
	}
	return labelCounter++;
}
int findLabel(char * name)
{
	int i = 0;
	for (; i < labelCounter; i++)
	{
		if (strcmp(name, labelTable[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}