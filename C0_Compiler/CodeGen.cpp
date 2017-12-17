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
unsigned int line=0;
unsigned int paramCounter = 0;
int qCode[maxQCodeSize * 4];


void clearQCode()
{
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
	buffer[0] = '\t';
	switch (tc)
	{
	case TADD:
		sprintf(buffer+1, "add %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TADDI:
		sprintf(buffer+1, "addi %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TSUB:
		sprintf(buffer+1, "sub %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSUBI:
		sprintf(buffer+1, "subi %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TMULT:
		sprintf(buffer+1, "mul %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TDIV:
		sprintf(buffer+1, "div %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TMULTI:
		sprintf(buffer+1, "mul %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TDIVI:
		sprintf(buffer+1, "div %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TSLL:
		sprintf(buffer+1, "sll %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TSLR:
		sprintf(buffer+1, "slr %s,%s,%d", REG(r1), REG(r2), r3);
		break;
	case TDATA:
		sprintf(buffer+1, ".data");
		break;
	case TWORD:
		sprintf(buffer+1, "%s :.word 0", NAME(r1));
		break;
	case TBYT:
		sprintf(buffer+1, "%s :.byte 0", NAME(r1));
		break;
	case TSPACE:
		sprintf(buffer + 1, "%s :.space %d", NAME(r1), r2);
		break;
	case TASCIIZ:
		sprintf(buffer+1, "%s :.asciiz \"%s\"", STRNAME(r1), STR(r1));
		break;
	case TLA:
		if (r3 == LAIDEN)
		{
			sprintf(buffer+1, "la %s,%s", REG(r1), NAME(r2));
		}
		else if(r3==LASTR)
		{
			sprintf(buffer+1, "la %s,%s", REG(r1), STRNAME(r2));
		}
		break;
	case TLI:
		sprintf(buffer+1, "li %s,%d", REG(r1), r2);
		break;
	case TLW:
		sprintf(buffer+1, "lw %s,%d(%s)", REG(r1), r3,REG(r2));
		break;
	case TLB:
		sprintf(buffer+1, "lb %s,%d(%s)",REG(r1), r3, REG(r2));
		break;
	case TSW:
		sprintf(buffer+1, "sw %s,%d(%s)", REG(r1), r3, REG(r2));
		break;
	case TSB:
		sprintf(buffer+1, "sb %s,%d(%s)", REG(r1), r3, REG(r2));
		break;
	case TBEQ:
		sprintf(buffer+1, "beq %s,%s,%s",REG(r1),REG(r2),LABEL(r3));
		break;
	case TBNE:
		sprintf(buffer+1, "bne %s,%s,%s", REG(r1), REG(r2), LABEL(r3));
		break;
	case TJAL:
		sprintf(buffer+1, "jal %s",NAME(r1));
		break;
	case TJUMP:
		sprintf(buffer+1, "j %s", LABEL(r1));
		break;
	case TJR:
		sprintf(buffer+1, "jr %s",REG(ra));
		break;
	case TSEQ:
		sprintf(buffer+1, "seq %s,%s,%s", REG(r1),REG(r2),REG(r3));
		break;
	case TSNE:
		sprintf(buffer+1, "sne %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSGT:
		sprintf(buffer+1, "sgt %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSGE:
		sprintf(buffer+1, "sge %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSLT:
		sprintf(buffer+1, "slt %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSLE:
		sprintf(buffer+1, "sle %s,%s,%s", REG(r1), REG(r2), REG(r3));
		break;
	case TSYSCALL:
		sprintf(buffer+1, "syscall");
		break;
	case TLABEL:
		sprintf(buffer, "%s:", LABEL(r1));
		break;
	default:
		error(ERR_INSTR_NOT_DEFINE);
	}
	outputOCode();
}
void objEntry()
{
	int l=genLabel(L, "main");
	emitObj(TJUMP,l);
}
void objFuncHead(bool main)
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
	if (main)
	{
		return;
	}
	for (int i = 0;i < 0; i++)
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
void objFunc(bool main)
{
	int lhead, ltail, lc;
	lhead = genLabel(LFUNC, symTable[funcRef]._name);
	ltail = genLabel(LFUNCEND, symTable[funcRef]._name);
	lc = 0;
	emitObj(TLABEL, lhead);
	objFuncHead(main);
	while (lc != line)
	{
		objLine(lc,ltail);
		lc++;
	}
	emitObj(TLABEL, ltail);
	objFuncTail(main);
	clearQCode();
}
void objLine(int lc,int ltail)
{
	qCType qt;
	int arg1, arg2, arg3;
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
		objSave(t0, t1, arg1);
		break;
	case QBNZ:
		emitObj(TBEQ, _0, v1, arg1);
		break;
	case QBZ:
		emitObj(TBNE, _0, v1, arg1);
		break;
	case QCALL:
		emitObj(TJAL, arg1);
		paramCounter = 0;
		break;
	case QDIV:
		objArthOp(TDIV, arg1, arg2, arg3);
		break;
	case QGOTO:
		emitObj(TJUMP, arg1);
		break;
	case QLABEL:
		emitObj(TLABEL, arg1);
		break;
	case QMINUS:
		objArthOp(TSUB, arg1, arg2, arg3);
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
		emitObj(TJUMP, ltail);
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
		//objFuncHead(main);
		break;
	case QPUSH:
		if (paramCounter < 4)
		{
			objLoad(a0 + paramCounter, arg1);
		}
		else
		{
			objLoad(t0, arg1);
			emitObj(TSW, t0, sp, -4 * (1 + paramCounter - 4));
		}
		paramCounter++;
		break;
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
void objFuncTail(bool main)
{
	int offset = 4;
	funcTableEntry entry = funcTable[symTable[funcRef]._ref];
	if (!main)
	{
		for (int i = 0; i < 0; i++)
		{
			emitObj(TLW, s0 + i, sp, i * offset + entry._size);
		}
		emitObj(TLW, ra, sp, RAADR + entry._size);
	}
	emitObj(TADDI, sp, sp, entry._size + ReserveSize);
	if (!main) {
		emitObj(TJR);
	}
}
void objGloblData()
{
	emitObj(TDATA,NotExist);
	int entry = linkGlobal;
	while (EXIST(entry))
	{
		if (ISGLOBAL(entry) && ISINT(entry))
		{
			if (ISVAR(entry))
			{
				emitObj(TWORD, entry);
			}
			else if (ISARRAY(entry))
			{
				emitObj(TSPACE, entry, REF(entry)*IntSize);
			}
		}
		entry = NEXT(entry);
	}
	entry = linkGlobal;
	while (EXIST(entry))
	{
		if (ISGLOBAL(entry) && ISCHAR(entry))
		{
			if (ISVAR(entry))
			{
				emitObj(TBYT, entry);
			}
			else if (ISARRAY(entry))
			{
				emitObj(TSPACE, entry, REF(entry)*CharSize);
			}
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