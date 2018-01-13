#pragma once
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include "SymTable.h"
#include "CodeGen.h"
#define LCHILDC(node) cnodeBuff[node].lchild
#define RCHILDC(node) cnodeBuff[node].rchild
#define PARENTSC(node) cnodeBuff[node].parents
#define MARK(node) cnodeBuff[node].mark
#define LSTART(node) bnodeBuff[node].lineStart
#define LEND(node) bnodeBuff[node].lineEnd
#define INSET(node) bnodeBuff[node].inSet
#define OUTSET(node) bnodeBuff[node].outSet
#define DEFINSET(node) bnodeBuff[node].defInSet
#define DEFOUTSET(node) bnodeBuff[node].defOutSet
#define ACTINSET(node) bnodeBuff[node].actInSet
#define ACTOUTSET(node) bnodeBuff[node].actOutSet
#define GENSET(node) bnodeBuff[node].genSet
#define KILLSET(node) bnodeBuff[node].killSet
#define USESET(node) bnodeBuff[node].useSet
#define DEFSET(node) bnodeBuff[node].defSet
#define FIND(queue,node) find(queue.begin(),queue.end(),node) 
#define FOUND(queue,node) (FIND(queue,node)!=queue.end())
#define UNION(set1,set2,set3) set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(set3,set3.begin()));
#define DIFF(set1,set2,set3) set_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(set3,set3.begin()));
#define INTERSEC(set1,set2,set3) set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(set3,set3.begin()));
using namespace std;
const unsigned int cnodeBuffSize = 500;
const unsigned int bnodeBuffSize = 500;
const int specOpdIndex = -0x7FFFFFFF;
const int specOpdSize = 3;
enum udType {udAssign,udPlus,udRead,udPrint,udDefault};
enum specOPD {INPUT=specOpdIndex,OUTPUT,ARGSTACK,NOTFOUND} ;
struct CNode
{
	vector<int> parents;
	int lchild;
	int rchild;
	int mark;
};
struct BNode
{
	int lineStart;
	int lineEnd;
	set<int> inSet;
	set<int> outSet;
	set<int> defInSet;
	set<int> defOutSet;
	set<int> actInSet;
	set<int> actOutSet;
	set<int> genSet;
	set<int> killSet;
	set<int> useSet;
	set<int> defSet;
};
extern CNode cnodeBuff[cnodeBuffSize];
extern BNode bnodeBuff[bnodeBuffSize];
void optimize();//global optimize 
