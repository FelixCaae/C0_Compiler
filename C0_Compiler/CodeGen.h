#pragma once
const unsigned int maxQCodeSize=5000;
const unsigned int maxLabelStrLen = 15;
const unsigned int maxLabelNum = 800;
const unsigned int RAADR = 8* 4;
const unsigned int ReserveSize = 9 * IntSize;//s0-s8 ra
extern char labelTable[maxLabelNum][maxLabelStrLen];
extern int labelLine[maxLabelNum];
enum qCType {
	QFUNCDECL=1, QPARA, QPUSH,QPRINT,QREAD,QCALL,QRETX,QRET, QVAR, QCONST, QARRAY,QASSIGN, QPLUS, QMINUS,
	QSTAR, QDIV, QEQU, QNEQU, QGT, QLS, QGTEQU, QLSEQU, QARL, QARR, QGOTO, QBZ, QBNZ
};
enum printFormat
{
	FSTRING,FEXPRESSION
};
enum returnFormat
{
	RNOVAL, RVAL
};
enum tCType {
	TDATA,TASCIIZ,TLA,TADD,TADDI,TSUB,TSUBI,TDIV,TDIVI,TMULT,TMULTI,
	TLW,TLB,TLI,TSW,TSB,
	TSLL,TSLR,
	TJUMP,TJAL,TJR,TBNE,TBEQ,
};
enum reg
{
	_0,at,v0,v1, a0,a1,a2,a3,t0,t1,t2,t3,t4,t5,t6,t7,s0,s1,s2,s3,s4,s5,s6,s7,t8,t9, k0, k1,gp,sp,fp,ra
};
enum lableType
{
	LFUNC,LIF,LWHILE,LSWITCH,LCASE,L
};
extern char labelTable[maxLabelNum][maxLabelStrLen];
extern int labelLine[maxLabelNum];
int genLabel(lableType lt,char*name=0);
int findLabel(char*name);
void setLabel(int label);
void emit(qCType q, int arg1 = 0, int arg2 = 0, int arg3 = 0);
void emitObj(tCType t, int arg1 = 0, int arg2=0,int arg3=0);
void emitObj(char* chr);
void clearQCode();
void objFuncHead();
void objFuncTail();
void objSave(int val, int adr, int iden, int offset = _0);
void objLoad(int reg, int iden, int offset = _0);
void objBody();
void objGloblData();
