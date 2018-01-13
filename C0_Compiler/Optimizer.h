#pragma once
#include <vector>
#include "SymTable.h"
#include "CodeGen.h"
#define LCHILDC(node) cnodeBuff[node].lchild
#define RCHILDC(node) cnodeBuff[node].rchild
#define PARENTC (node) cnodeBuff[node].parents
#define MARK(node) cnodeBuff[node].mark
#define INSET(node) bnodeBuff[node].inSet
#define OUTSET(node) bnodeBuff[node].outSet
#define GENSET(node) bnodeBuff[node].genSet
#define KILLSET(node) bnodeBuff[node].killSet
#define USESET(node) bnodeBuff[node].useSet
#define DEFSET(node) bnodeBuff[node].defSet
using namespace std;
const unsigned int cnodeBuffSize = 500;
const unsigned int bnodeBuffSize = 500;
const int specOPTSize = 10;
enum specOPT {INPUT,OUTPUT,ARGSTACK} ;
struct CNode
{
	std::vector<int> parents;
	int lchild;
	int rchild;
	int mark;
};
struct BNode
{
	int lineStart;
	int lineEnd;
	vector<int> inSet;
	vector<int> outSet;
	vector<int> genSet;
	vector<int> killSet;
	vector<int> useSet;
	vector<int> defSet;
};
extern CNode cnodeBuff[cnodeBuffSize];
extern BNode bnodeBuff[bnodeBuffSize];
void flowGraphBuild();
void flowGraphExtract();
void dagBuild(int start,int end);
int dagExtract(int start);
void merge();
void optimize();//global optimize 
