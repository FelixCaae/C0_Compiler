#include "stdafx.h"
#include "Optimizer.h"
#include "IO.h"

using namespace std;
CNode cnodeBuff[cnodeBuffSize];
BNode bnodeBuff[bnodeBuffSize];
map<int, int> varNodeMap;
vector<int> headCodes;
vector<int> tailCodes;
int cnodePos = 0;
int bnodePos = 0;
void connect(int blockHead, int blockTail);
void setBlock(int i, int left, int right);
int lineMapBlock(int line);
void initCNode(int cnode);
bool isLeaf(int cnode);
void connectLeft(int parent, int child);
void connectRight(int parent, int child);
void clear();
void connect(int blockHead, int blockTail)
{
	OUTSET(blockHead).push_back(blockTail);
	INSET(blockTail).push_back(blockHead);
}
void setBlock(int i, int left, int right)
{
	bnodeBuff[i].lineStart = left;
	bnodeBuff[i].lineEnd = right;
}
int lineMapBlock(int line)
{
	for (int i = 0; i < bnodePos; i++)
	{
		if (bnodeBuff[i].lineStart <= line && bnodeBuff[i].lineEnd >= line)
		{
			return i;
		}
	}
	return NotFound;
}
void flowGraphBuild()
{
	map<int, int> labelBlockMap;
	int left;
	left = 0;
	//First loop:build blocks and basic connection
	for (int i = 0; i < line; i++)
	{
		if (qCode[i*codeSize] == QBNZ || qCode[i*codeSize] == QBZ)
		{
			setBlock(bnodePos, left, i);
			connect(bnodePos, bnodePos + 1);
			left = i + 1;
			bnodePos++;
		}
		else if (OPT(i) == QLABEL)
		{
			labelBlockMap[OPD1(i)] = bnodePos+1;
			setBlock(bnodePos, left, i - 1);
			connect(bnodePos, bnodePos + 1);
			left = i;
			bnodePos++;
		}
		else if (OPT(i) == QRET || OPT(i) == QGOTO)
		{
			setBlock(bnodePos, left, i);
			left = i + 1;
			bnodePos++;
		}
	}
	//compelete final block 
	setBlock(bnodePos,left, line);
	//set and connect to end block
	setBlock(bnodePos+1, NotExist, NotExist);
	connect(bnodePos, bnodePos+1);
	bnodePos++;
	//Second loop:build connection based on labels
	for (int i = 0; i < line; i++)
	{
		if (qCode[i*codeSize] == QBNZ || qCode[i*codeSize] == QBZ || qCode[i*codeSize] == QGOTO)
		{
			int label = OPD1(i);
			int bCur = lineMapBlock(i);
			connect(bCur,labelBlockMap[label]);
		}
		else if (OPT(i) == QRETX)
		{
			int bCur = lineMapBlock(i);
			connect(bCur, bnodePos);//connect to end block
		}
	}
}
void flowGraphExtract()
{
	for (int blk = 0; blk < bnodePos; blk++)
	{
		dagBuild(LSTART(blk),LEND(blk));
		bnodeBuff[blk].lineEnd=dagExtract(bnodeBuff[blk].lineStart);
		clear();
	}
	merge();

}
void initCNode(int cnode)
{
	LCHILDC(cnode) = NotExist;
	RCHILDC(cnode) = NotExist;
}
bool isLeaf(int cnode)
{
	if (LCHILDC(cnode) == NotExist&&RCHILDC(cnode) == NotExist)return true;
	return false;
}
void connectLeft(int parent, int child)
{
	cnodeBuff[child].parents.push_back(parent);
	cnodeBuff[parent].lchild = child;
}
void connectRight(int parent, int child)
{
	cnodeBuff[child].parents.push_back(parent);
	cnodeBuff[parent].rchild = child;
}
void clear()
{
	while(cnodePos!=0)
	{
		initCNode(cnodePos - 1);
	}
	varNodeMap.clear();
}
int leafNodeSelect(int val)
{
	map<int, int>::iterator result;
	result = varNodeMap.find(val);
	//1.search the var-node map first 
	if (result != varNodeMap.end())
	{
		return result->second;
	}
	//2.If not found, build it into the tree
	/*for (int i = 0; i < cnodePos; i++)
	{
		if (cnodeBuff[i].mark == val)
		{
			return i;
		}
	}*/
	initCNode(cnodePos);
	MARK(cnodePos) = val;
	varNodeMap[val] = cnodePos;
	return cnodePos++;
}
int midNodeSelect(int op,int lchild, int rchild)
{
	//1.Search the tree for a node that has wanted mark,lchild and rchild
	for (int i = 0; i < cnodePos; i++)
	{
		if (cnodeBuff[i].mark == op && cnodeBuff[i].lchild == lchild && cnodeBuff[i].rchild == rchild)
		{
			return i;
		}
	}
	//2.If not found ,build it into the tree again
	initCNode(cnodePos);
	MARK(cnodePos) = op;
	connectLeft(cnodePos, lchild);
	connectRight(cnodePos, rchild);
	//printf("midnode:%d op:%d\n", cnodePos, op);
	return cnodePos++;
}
int buildNodes(int opt, int opd1, int opd2, int opd3)
{
	int mid = 0, lchild = 0, rchild = 0;
	lchild = leafNodeSelect(opd2);
	rchild = leafNodeSelect(opd3);
	mid = midNodeSelect(opt, lchild, rchild);
	varNodeMap[opd1] = mid;
	return mid;
}
void dagBuild(int start, int end)
{
	headCodes.clear();
	tailCodes.clear();
	int lchild=0,i;
	for (i = start; i <= end; i++)
	{
		switch (qCode[i*codeSize])
		{
		case QPLUS:
		case QMINUS:
		case QSTAR:
		case QDIV:
		case QARR:
		case QARL:
			buildNodes(OPT(i), OPD1(i), OPD2(i), OPD3(i));
			break;
		case QASSIGN:
			lchild = leafNodeSelect(OPD2(i));
			varNodeMap[OPD1(i)] = lchild;
			break;
		case QBNZ:
		case QBZ:
		case QEQU:
		case QNEQU:
		case QGT:
		case QGTEQU:
		case QLS:
		case QLSEQU:
		case QRET:
			tailCodes.push_back(i);
			break;
		case QLABEL:
			headCodes.push_back(i);
		case QREAD:
			varNodeMap[OPD1(i)]= buildNodes(OPT(i), INPUT, INPUT, INPUT);
			break;
		case QPRINT:
			buildNodes(OPT(i), OUTPUT, OPD1(i), OUTPUT);
			break;
		case QPUSH:
			buildNodes(OPT(i), ARGSTACK, OPD1(i),ARGSTACK);
			break;
		case QCALL: {
			int mid = buildNodes(OPT(i), ARGSTACK, OPD1(i), ARGSTACK);
			if (OPT(i + 1) == QRETX)
			{
				varNodeMap[OPD1(i + 1)] = mid;
			}
			break;
		}
		default:
			continue;
		}
	}
}
bool testOpt(int node, vector<int>& midNodeQueue)
{
	bool select = true;
	if (isLeaf(node)||
		FIND(midNodeQueue,node)!=midNodeQueue.end())
	{
		return false;
	}
	for (int j = 0; j < cnodeBuff[node].parents.size(); j++)
	{
		if (midNodeQueue.end() == FIND(midNodeQueue,cnodeBuff[node].parents[j]))
		{
			select = false;
		}
	}
	return select;
}
int findOptNode(vector<int>& midNodeQueue)
{
	int i;
	for (i = 0; i < cnodePos; i++)
	{
		if (testOpt(i,midNodeQueue))
		{
			break;
		}
	}
	return i;
}
void getVarsByNode(int node,vector<int>& vars)
{
	map<int, int>::iterator it;
	vars.clear();
	for (it = varNodeMap.begin(); it != varNodeMap.end(); it++)
	{
		if ((*it).second == node)
		{
			vars.push_back(it->first);
		}
	}
}
int selectVarAsStore(vector<int>& vars)
{
	vector<int>::iterator it;
	for (it = vars.begin(); it != vars.end(); it++)
	{
		if (*it >= 0)
		{
			return *it;
		}
	}
	return NotFound;
}
int nodeToCode(int node, int line)
{
	int total;
	vector<int> vars;
	qCType qc = (qCType)MARK(node);
	OPT(line) = qc;
	total = 1;
	switch (qc)
	{
		case QPLUS:
		case QMINUS:
		case QSTAR:
		case QDIV:
		case QARR:
		case QARL:
			getVarsByNode(node, vars); 
			OPD1(line) = selectVarAsStore(vars);
			getVarsByNode(LCHILDC(node), vars);
			OPD2(line) = selectVarAsStore(vars);
			getVarsByNode(RCHILDC(node), vars);
			OPD3(line) = selectVarAsStore(vars);
			break;
		case QREAD:
			getVarsByNode(node, vars);
			OPD1(line) = selectVarAsStore(vars);
			break;
		case QPRINT:
		case QPUSH:
			getVarsByNode(LCHILDC(node),vars);
			OPD1(line) = selectVarAsStore(vars);
			break;
		case QCALL:
			getVarsByNode(LCHILDC(node), vars);
			OPD1(line) = selectVarAsStore(vars);
			getVarsByNode(node, vars);
			int ret = selectVarAsStore(vars);
			if (ret != NotFound)
			{
				OPT(line + 1) = QRETX;
				OPD1(line + 1) = ret;
				total += 1;
			}
			break;
	}
	for (int i = 0; i < total; i++)
	{
		int t1 = OPT(line + i);;
		outputQCode(line+i);
	}
	return total;
}
void codeCopy(int lineSrc, int lineDst)
{
	OPT(lineDst) = OPT(lineSrc);
	OPD1(lineDst) = OPD1(lineSrc);
	OPD2(lineDst) = OPD2(lineSrc);
	OPD3(lineDst) = OPD3(lineSrc);
}
int dagExtract(int start)
{
	//1.reserve labels :abandoned
	//2.generate mid node queue
	vector<int> midNodeQueue;
	int nextNode;
	while (true)
	{
		nextNode = findOptNode(midNodeQueue);

		if (nextNode == cnodePos)//all mid nodes are in the queue
		{
			break;
		}
		midNodeQueue.push_back(nextNode);
	}
	//3.extract codes in a reversed order with the queue
	vector<int>::reverse_iterator it=midNodeQueue.rbegin();
	for (int i = 0; i < headCodes.size(); i++)
	{
		codeCopy(headCodes[i], start++);
	}
	for (; it != midNodeQueue.rend(); it++)
	{
		int mid = *it;
		//find all related vars
		start+=nodeToCode(mid,start);
	}
	for (int i = 0; i < tailCodes.size(); i++)
	{
		codeCopy(tailCodes[i], start++);
	}
	cnodePos = 0;
	return start-1;
}
void merge()
{
	int  dstln =LEND(0)+1;
	for (int blk = 1; blk < bnodePos; blk++)
	{
		int srcln = LSTART(blk);
		while(srcln<=LEND(blk))
		{
			codeCopy(srcln ++, dstln ++);
		}
	}
	for (int i = LSTART(0); i <= LEND(bnodePos - 1); i++)
	{
		outputQCode(i);
	}
}
void optimize()
{
	flowGraphBuild();
	flowGraphExtract();
}