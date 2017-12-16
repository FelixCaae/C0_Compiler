#include "stdafx.h"
#include"CodeGen.h"
#include"IO.h"
#include "SymTable.h"
#include <cstring>
#include <string>
#include <stdio.h>
#define REG(arg) regName[arg]
using namespace std;
extern const unsigned int IntSize, CharSize;
extern unsigned int curStr;
unsigned int qcPos;
unsigned int labelCounter=0;
unsigned int caseCounter=0;
unsigned int line=0;
char labelTable[maxLabelNum][maxLabelStrLen];
int labelLine[maxLabelNum];
int qCode[maxQCodeSize * 4];

int genLabel(lableType lt,char *name)
{
	switch (lt)
	{
	case LIF:
		sprintf(labelTable[labelCounter],"if_%d",labelCounter);
		break;
	case LWHILE:
		sprintf(labelTable[labelCounter], "do_%d", labelCounter);
		break;
	case LSWITCH:
		sprintf(labelTable[labelCounter], "switch_%d", labelCounter);
		caseCounter = 0;
		break;
	case LCASE:
		sprintf(labelTable[labelCounter], "case_%d_%d", caseCounter,labelCounter);
		break;
	case LFUNC:
	//	strcat(labelTable[labelCounter], "\");
		sprintf(labelTable[labelCounter], name);
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
void setLabel(int label)
{
	labelLine[label] = line;
	outputLabel(label);
}
void clearLabel()
{

}
void clearQCode()
{
	line = 0;
}
void emit(qCType qc,int arg1,int arg2,int arg3)
{
	outputQCode(qc, arg1, arg2, arg3);
	qCode[qcPos] = qc;
	qCode[qcPos + 1] = arg1;
	qCode[qcPos + 2] = arg2;
	qCode[qcPos + 3] = arg3;
	qcPos += 4;
	line += 1;
}
void emitObj(tCType tc, int r1, int r2, int r3)
{
	switch (tc)
	{
	case TADD:
		sprintf(buffer,"add %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TADDI:
		sprintf(buffer,"addi %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TSUB:
		sprintf(buffer,"sub %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSUBI:
		sprintf(buffer,"subi %s,%s,%d", REG(r1), REG(r2), REG(r3));
		break;
	case TMULT:
		sprintf(buffer,"mul %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TDIV:
		sprintf(buffer,"div %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TMULTI:
		sprintf(buffer, "mul %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TDIVI:
		sprintf(buffer, "div %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TSLL:
		sprintf(buffer, "sll %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TSLR:
		sprintf(buffer, "slr %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TDATA:
		if (r1 == NotExist)
		{
			sprintf(buffer, ".data");
		}
		else
		{
			sprintf(buffer, "%s .data %d", NAME(r1), countSize(r1));
		}
		break;
	case TASCIIZ:
		sprintf(buffer, "%s .asciiz \"%s\"", STRNAME(r1), STR(r1));
		break;
	case TLA:
		sprintf(buffer, "la %s,%s", REG(r1), NAME(r2));
		break;
	case TLI:
		sprintf(buffer, "li %s,%d", REG(r1), r2);
		break;
	case TBEQ:
		sprintf(buffer, "beq %s,%s,%s",REG(r1),REG(r2),LABEL(r3));
		break;
	case TBNE:
		sprintf(buffer, "bne %s,%s,%s", REG(r1), REG(r2), LABEL(r3));
		break;
	case TJAL:
		sprintf(buffer, "jal %s",LABEL(r3));
		break;
	}
}
const char* genStrName(int str)
{
	const char* name= ("str_" + to_string(str)).c_str();
}
void resetObj()
{

}
void objFuncHead()
{
	int offset = 4;
	funcTableEntry entry = funcTable[funcRef];
	int paraNum = entry._paraNum;
	IdenType *para = entry._param;
	if (paraNum > 4)
	{
		int extraPara = linkHead+4;
		for (int i = 0; i < paraNum - 4; i++)
		{
			emitObj(TLW, t0 + i, sp, (i + 1)*-4);
		}
	}
	emitObj(TSUBI, sp, sp, entry._size+ReserveSize);
	for (int i = 0; i < 8; i++)
	{
		emitObj(TSW, s0+i, sp, offset*i+entry._size);
	}
	emitObj(TSW, ra, sp, RAADR);
	for (int i = 0; i < paraNum; i++)
	{
		if (i < 4)
		{
			emitObj(TSW, a0 + i, sp, symTable[linkHead + i]._adr);
		}
		else if(i<12)
		{ 
			emitObj(TSW, t0 + i, sp, symTable[linkHead + i]._adr);
		}
		else
		{
			throw "too many arguments";
		}
	}
}
void objBody()
{
	int lc = 0;
	qCType qt;
	int arg1, arg2, arg3;
	while (lc != line)
	{
		qt = (qCType)qCode[lc * 4];
		arg1 = qCode[lc * 4 + 1];
		arg2 = qCode[lc * 4 + 2];
		arg3 = qCode[lc * 4 + 3];
		switch (qt)
		{
		case QARL:
			objLoad(t0, arg3); //load val
			objLoad(t1, arg2);//load offset
			objSave(t0, t2, arg1, t1);
			break;
		case QARR:
			objLoad(t1, arg3);//load offset
			objLoad(t0, arg2, t1);//load val
			objSave(t0, t1, arg1);
			break;
		case QASSIGN:
			objLoad(t0, arg2);
			objSave(t0,t1,arg1);
			break;
		case QBNZ:
			emitObj(TBEQ, _0, v1, arg1);
			break;
		case QBZ:
			emitObj(TBNE, _0, v1, arg1);
			break;
		case QCALL:
			emitObj(TJAL, arg1);
		}
	}
}
void objLoad(int reg, int iden,int offset=_0)
{
	symTableEntry entry = symTable[iden];
	if (entry._obj == OCONST)
	{
		emitObj(TLI, reg, entry._ref);
	}
	else {
		if (entry._adr == Global)
		{
			emitObj(TLA, reg, iden);
		}
		else
		{
			emitObj(TADDI, reg, sp, entry._adr);
		}
	     if (entry._obj == OARRAY)
		{
			if (entry._type == INTS)
			{
				emitObj(TSLL, offset, offset, 2);
			}
			else
			{
				emitObj(TSLL, offset, offset,0);
			}
			emitObj(TADD, reg, reg, offset);
		}
		 if (entry._type == INTS)
		 {
			 emitObj(TLW, reg, reg, 0);
		 }
		 else if (entry._type == CHARS)
		 {
			 emitObj(TLB, reg, reg, 0);
		 }
	}
}
void objSave(int val,int adr,int iden,int offset=_0)
{
	symTableEntry entry = symTable[iden];
	if (entry._obj == OCONST)
	{
		//error(ERR_STORE_CONST);
	}
	else {
		if (entry._adr == Global)
		{
			emitObj(TLA, adr, iden);
		}
		else
		{
			emitObj(TADDI, adr, sp, entry._adr);
		}
		if (entry._obj == OARRAY)
		{
			if (entry._type == INTS)
			{
				emitObj(TSLL, offset, offset, 2);
			}
			else
			{
				emitObj(TSLL, offset, offset, 0);
			}
			emitObj(TADD, adr, adr, offset);
		}
		if (entry._type == INTS)
		{
			emitObj(TSW, val, adr, 0);
		}
		else if (entry._type == CHARS)
		{
			emitObj(TLB, val, adr, 0);
		}
	}
}
void objLoadAr(reg r, int ar, int sub)
{

}
void objLoadStr(int reg, int str)
{

}
void objFuncTail()
{
	int offset = 4;
	funcTableEntry entry = funcTable[funcRef];
	for (int i = 0; i < 8; i++)
	{
		emitObj(TLW, s0 + i, sp, i * offset+entry._size);
	}
	emitObj(TLW, ra, sp,RAADR+entry._size);
	emitObj(TADDI, sp, sp, entry._size + ReserveSize);
	emitObj(TJR);
}
void objGloblData()
{
	int entry = linkGlobal;
	emitObj(TDATA);
	while (symTable[entry]._adr==Global)
	{
		emitObj(TDATA, entry);
		entry++;
	}
	entry = 0;
	while (entry < curStr)
	{
		emitObj(TASCIIZ, entry);
	}
}