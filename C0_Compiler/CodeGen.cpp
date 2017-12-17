#include "stdafx.h"
#include <cstring>
#include <string>
#include <stdio.h>
#include "error.h"
#include"CodeGen.h"
#include"IO.h"
#include "SymTable.h"
#define REG(arg) regName[arg]
extern const unsigned int IntSize, CharSize;
using namespace std;
//unsigned int qcPos;
unsigned int labelCounter=0;
unsigned int labelID = 0;
unsigned int caseID=0;
unsigned int line=0;
char labelTable[maxLabelNum][maxLabelStrLen];
int labelLine[maxLabelNum];
int qCode[maxQCodeSize * 4];

int genLabel(lableType lt,char *name)
{
	switch (lt)
	{
	case LIF:
		sprintf(labelTable[labelCounter],"if_%d",++labelID);
		break;
	case LWHILE:
		sprintf(labelTable[labelCounter], "do_%d", ++labelID);
		break;
	case LSWITCH:
		sprintf(labelTable[labelCounter], "switch_%d", ++labelID);
		caseID = 0;
		break;
	case LCASE:
		sprintf(labelTable[labelCounter], "case_%d_%d",labelID,++caseID);
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
void setLabel(int label,int pos)
{
	if (pos ==LPHEAD)
	{
		labelLine[label] = 0;
	}
	else if(pos==LPCUR)
	{
		labelLine[label] = line;
	}
	else if (pos == LPNULL)
	{
		labelLine[label] = -1;
	}
	outputLabel(label);
}
void clearQCode()
{
	labelCounter = 0;
	line = 0;
}
void emit(qCType qc,int arg1,int arg2,int arg3)
{
	outputQCode(qc, arg1, arg2, arg3);
	qCode[line*4] = qc;
	qCode[line * 4 + 1] = arg1;
	qCode[line * 4 + 2] = arg2;
	qCode[line * 4 + 3] = arg3;
	//qcPos += 4;
	line += 1;
}
void emitObj(const char* code)
{
	sprintf(buffer, code);
	outputOCode();
}
void emitObj(tCType tc, int r1, int r2, int r3)
{
	switch (tc)
	{
	case TADD:
		sprintf(buffer, "add %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TADDI:
		sprintf(buffer, "addi %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TSUB:
		sprintf(buffer, "sub %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSUBI:
		sprintf(buffer, "subi %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TMULT:
		sprintf(buffer, "mul %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TDIV:
		sprintf(buffer, "div %s,%s,%s", REG(r1), REG(r2), REG(r3));
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
			sprintf(buffer, "%s :.data %d", NAME(r1), countSize(r1));
		}
		break;
	case TASCIIZ:
		sprintf(buffer, "%s :.asciiz \"%s\"", STRNAME(r1), STR(r1));
		break;
	case TLA:
		if (r3 == LAIDEN)
		{
			sprintf(buffer, "la %s,%s", REG(r1), NAME(r2));
		}
		else if(r3==LASTR)
		{
			sprintf(buffer, "la %s,%s", REG(r1), STRNAME(r2));
		}
		break;
	case TLI:
		sprintf(buffer, "li %s,%d", REG(r1), r2);
		break;
	case TLW:
		sprintf(buffer, "lw %s,%d(%s)", REG(r1), r3,REG(r2));
		break;
	case TLB:
		sprintf(buffer, "lb %s,%d(%s)",REG(r1), r3, REG(r2));
		break;
	case TSW:
		sprintf(buffer, "sw %s,%d(%s)", REG(r1), r3, REG(r2));
		break;
	case TSB:
		sprintf(buffer, "sb %s,%d(%s)", REG(r1), r3, REG(r2));
		break;
	case TBEQ:
		sprintf(buffer, "beq %s,%s,%s",REG(r1),REG(r2),LABEL(r3));
		break;
	case TBNE:
		sprintf(buffer, "bne %s,%s,%s", REG(r1), REG(r2), LABEL(r3));
		break;
	case TJAL:
		sprintf(buffer, "jal %s",NAME(r1));
		break;
	case TJUMP:
		sprintf(buffer, "j %s", LABEL(r1));
		break;
	case TJR:
		sprintf(buffer, "jr %s",REG(ra));
		break;
	case TSEQ:
		sprintf(buffer, "seq %s,%s,%s", REG(r1),REG(r2),REG(r3));
		break;
	case TSNE:
		sprintf(buffer, "sne %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSGT:
		sprintf(buffer, "sgt %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSGE:
		sprintf(buffer, "sge %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSLT:
		sprintf(buffer, "slt %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSLE:
		sprintf(buffer, "sle %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSYSCALL:
		sprintf(buffer, "syscall");
		break;
	default:
		error(ERR_INSTR_NOT_DEFINE);
	}
	outputOCode();
}
void objEntry()
{
	emitObj("j main");
}
void objFunc(bool hasHead)
{
	int lhead=genLabel(LFUNC,symTable[funcRef]._name);
	int ltail = genLabel(LFUNCEND, symTable[funcRef]._name);
	setLabel(lhead, LPHEAD);
	setLabel(ltail, LPCUR);
	if (hasHead)
	{
		objBody(ltail);
		objFuncTail();
	}
	else
	{
		objBody(ltail);
	}
}
void objFuncHead()
{
	int offset = 4;

	funcTableEntry entry = funcTable[symTable[funcRef]._ref];
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
	emitObj(TSW, ra, sp, RAADR+entry._size);
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
void objBody(int ltail)
{
	int lc = 0,lbc=0;
	qCType qt;
	int arg1, arg2, arg3;
	while (lc != line)
	{
		qt = (qCType)qCode[lc * 4];
		arg1 = qCode[lc * 4 + 1];
		arg2 = qCode[lc * 4 + 2];
		arg3 = qCode[lc * 4 + 3];
		objLabel(lc);
		lc++;
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
			break;
		case QDIV:
			objArthOp(TDIV, arg1, arg2, arg3);
			break;
		case QGOTO:
			emitObj(TJUMP, arg1);
			break;
		case QMINUS:
			objArthOp(TSUB,arg1,arg2,arg3);
			break;
		case QPLUS:
			objArthOp(TADD, arg1, arg2, arg3);
			break;
		case QPRINT:
			objWrite(arg1, arg2);
			break;
		case QREAD:
			objRead(arg1);
			break;
		case QRET:
			if (arg1 != NotExist)
			{
				objLoad(v0, arg1);
			}
			emitObj(TJUMP,ltail);
			break;
		case QRETX:
			objSave(v0, t0, arg1);
			break;
		case QSTAR:
			objArthOp(TMULT, arg1, arg2, arg3);
			break;
		case QGT:
			objCondition(TSGT, arg1, arg2);
			break;
		case QLS:
			objCondition(TSLT, arg1, arg2);
			break;
		case QGTEQU:
			objCondition(TSGE, arg1, arg2);
			break;
		case QLSEQU:
			objCondition(TSLE, arg1, arg2);
			break;
		case QEQU:
			objCondition(TSEQ, arg1, arg2);
			break;
		case QNEQU:
			objCondition(TSNE, arg1, arg2);
			break;
		case QFUNCDECL:
			if (strcmp(NAME(arg1), "main") != 0)
			{
				objFuncHead();
			}
			break;
		case QPUSH:
		case QPARA:
		case QVAR:
		case QARRAY:
		case QCONST:
			break;
		default:
			error(ERR_QCODE_NOT_DEFINE);
			break;
		}
	}
	objLabel(lc);
	clearQCode();
}
void objLabel(int lc)
{
	for (int i = 0; i < labelCounter; i++)
	{
		if (labelLine[i] == lc)
		{
			outputLabel(i,true);
		}

	}
}
void objLoad(int reg, int iden,int offset)
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
void objSave(int val,int adr,int iden,int offset)
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
			emitObj(TSB, val, adr, 0);
		}
	}
}
void objArthOp(tCType tc, int iden1, int iden2, int iden3)
{
	objLoad(t0, iden2);
	objLoad(t1, iden3);
	emitObj(tc, t0, t0, t1);
	objSave(t0, t1, iden1);
}
void objCondition(tCType tc,int iden1,int iden2)
{
	objLoad(t0, iden1);
	objLoad(t1, iden2);
	emitObj(tc, condR, t0, t1);
}
void objRead(int iden)
{
	if (symTable[iden]._type == INTS)
	{
		emitObj(TLI, v0, MIPS_READ_INT);
	}
	else if (symTable[iden]._type == CHARS)
	{
		emitObj(TLI, v0, MIPS_READ_CHAR);
	}
	emitObj(TSYSCALL);
	objSave(v0, t0, iden);
}
void objWrite(int  pf,int iden)
{
	if (pf == FSTRING)
	{
		emitObj(TLI, v0, MIPS_PRINT_STR);
		emitObj(TLA, a0, iden, LASTR);
	}
	else if (pf == FEXPRESSION)
	{
		objLoad(a0, iden);
		if (symTable[iden]._type == CHARS)
		{
			emitObj(TLI, v0, MIPS_PRINT_CHAR);
		}
		else if(symTable[iden]._type ==INTS)
		{
			emitObj(TLI, v0, MIPS_PRINT_INT);
		}
	}
	emitObj(TSYSCALL);
	emitObj(TLI, v0, MIPS_PRINT_CHAR);
	emitObj(TLI, a0, '\n');
	emitObj(TSYSCALL);
}
void objFuncTail()
{
	int offset = 4;
	funcTableEntry entry = funcTable[symTable[funcRef]._ref];
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
	emitObj(TDATA,NotExist);
	while (EXIST(entry))
	{
		if (ISGLOBAL(entry) &&
			(ISVAR(entry) ||ISARRAY(entry)))
		{
			emitObj(TDATA, entry);
		}
		entry = NEXT(entry);
	}
	entry = 0;
	while (entry < curStr)
	{
		emitObj(TASCIIZ, entry);
		entry++;
	}
}