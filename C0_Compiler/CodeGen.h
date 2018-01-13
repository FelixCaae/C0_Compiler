#pragma once
#define OPT(i) qCode[(i)*codeSize]
#define OPD1(i) qCode[(i)*codeSize+1]
#define OPD2(i) qCode[(i)*codeSize+2]
#define OPD3(i) qCode[(i)*codeSize+3]
const unsigned int maxQCodeSize=5000;
const unsigned int codeSize = 4;
const unsigned int LAIDEN = 0;
const unsigned int LASTR = 1;
const unsigned int MIPS_PRINT_CHAR = 11;
const unsigned int MIPS_PRINT_INT = 1;
const unsigned int MIPS_PRINT_STR = 4;
const unsigned int MIPS_READ_INT = 5;
const unsigned int MIPS_READ_CHAR = 12;
const unsigned int ReserveSize = 36;//s0-s7 ra
const unsigned int RAADR = 32;
//extern char labelTable[maxLabelNum][maxLabelStrLen];
extern unsigned int curStr;
enum qCType {
	QFUNCDECL=1, QPARA, QPUSH,QPRINT,QREAD,QCALL,QRETX,QRET, QVAR, QCONST, QARRAY,QASSIGN, QPLUS, QMINUS,
	QSTAR, QDIV, QEQU, QNEQU, QGT, QLS, QGTEQU, QLSEQU, QARL, QARR, QGOTO, QBZ, QBNZ,QLABEL
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
	TDATA,TASCIIZ,TWORD,TBYT,TSPACE,
	TLA,TADD,TADDI,TSUB,TSUBI,TDIV,TDIVI,TMULT,TMULTI,
	TLW,TLB,TLI,TSW,TSB,
	TSLL,TSLR,
	TSLT,TSLE,TSEQ,TSGT,TSGE,TSNE,
	TJUMP,TJAL,TJR,TBNE,TBEQ,
	TSYSCALL,TLABEL
};
enum reg
{
	_0,at,v0,v1, a0,a1,a2,a3,t0,t1,t2,t3,t4,t5,t6,t7,s0,s1,s2,s3,s4,s5,s6,s7,t8,t9, k0, k1,gp,sp,fp,ra
};
extern int qCode[maxQCodeSize * 4];
extern unsigned int line;
const unsigned int condR = v1;
void emit(qCType q, int arg1 = 0, int arg2 = 0, int arg3 = 0);
void emitObj(tCType t, int arg1 = 0, int arg2=0,int arg3=0);
void emitObj(char* chr);
void clearQCode();
void objEntry();
void objFunc(bool main = false);
void objFuncHead(bool main);
void objFuncTail(bool main);
void objLine(int lc, int ltail);
void objSave(int val, int adr, int iden, int offset = _0);
void objLoad(int reg, int iden, int offset = _0);
void objPush(int iden);
void objCall(int func);
void objCondition(tCType tc,int iden1,int iden2);
void objArthOp(tCType tc, int iden1, int iden2, int iden3);
void objRead(int iden);
void objWrite(int pf,int iden);
void objGloblData();
