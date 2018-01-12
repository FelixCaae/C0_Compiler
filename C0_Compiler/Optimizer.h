#pragma once
#include <Vector>
#include "SymTable.h"
#include "CodeGen.h"
#define OP(i) qCode[i*codeSize]
#define RES(i) qCode[i*codeSize+1]
#define OP1(i) qCode[i*codeSize+2]
#define OP2(i) qCode[i*codeSize+3]
const unsigned int cnodeBuffSize = 500;
const unsigned int bnodeBuffSize = 500;
const unsigned int outSetSize = 5;
const unsigned int inSetSize = 50;
const int END = -1;//end of set
const int STACK = -1;
const int INPUT = -2;
const int OUTPUT = -3;
struct CNode
{
	std::vector<int> parents;
	int lchild;
	int rchild;
	int parentEnd;
	int mark;
};
struct BNode
{
	int lineStart;
	int lineEnd;
	int out[outSetSize];
	int in[inSetSize];
	int inEnd;
	int outEnd;
};
extern int qCode[maxQCodeSize * 4];
extern CNode cnodeBuff[cnodeBuffSize];
extern BNode bnodeBuff[bnodeBuffSize];
void flowGraphBuild(int lineTotal);
void flowGraphExtract();
void dagBuild(int start,int end);
int dagExtract(int start);
void merge();
void optimize();//global optimize 
