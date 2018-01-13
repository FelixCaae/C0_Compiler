#include "stdafx.h"
#include <map>
#include "Optimizer.h"

using namespace std;
CNode cnodeBuff[cnodeBuffSize];
BNode bnodeBuff[bnodeBuffSize];
map<int, int> varNodeMap;
vector<int> tailCodes;
int cnodePos = 0;
int bnodePos = 0;
void initCNode(int cnode)
{
	LCHILDC(cnode)= NotExist;
	RCHILDC(cnode) = NotExist;
}
bool isLeaf(int cnode)
{
	if (LCHILDC(cnode) == NotExist&&RCHILDC(cnode) == NotExist)return true;
	return false;
}
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
		else if (OPT(i) == QRETX || OPT(i) == QGOTO)
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
	for (int i = 0; i < bnodePos; i++)
	{
		dagBuild(bnodeBuff[i].lineStart, bnodeBuff[i].lineEnd);
		bnodeBuff[i].lineEnd=dagExtract(bnodeBuff[i].lineStart);
	}
	merge();
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
	cnodePos++;
	MARK(cnodePos) = val;
	varNodeMap[val] = cnodePos;
	return cnodePos;
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
	cnodePos++;
	cnodeBuff[cnodePos].mark = op;
	cnodeBuff[cnodePos].lchild = lchild;
	cnodeBuff[cnodePos].rchild = rchild;
	cnodeBuff[lchild].parents.push_back(cnodePos);
	cnodeBuff[rchild].parents.push_back(cnodePos);
	return cnodePos;
}
int buildNodes(int opt, int opd1, int opd2, int opd3)
{
	int mid = 0, lchild = 0, rchild = 0;
	lchild = leafNodeSelect(opd2);
	rchild = leafNodeSelect(opd3);
	mid = midNodeSelect(opt, opd2, opd3);
	varNodeMap[opd1] = mid;
	return mid;
}
void dagBuild(int start, int end)
{
	tailCodes.clear();
	int i = 0;
	for (i = start; i < end; i++)
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
			int lchild = leafNodeSelect(OPD2(i));
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
			tailCodes.push_back(i);
		case QREAD:
			varNodeMap[OPD1(i)]= buildNodes(OPT(i), INPUT, INPUT, INPUT);
			break;
		case QPRINT:
			buildNodes(OPT(i), OUTPUT, OPD1(i), OUTPUT);
			break;
		case QPUSH:
			buildNodes(OPT(i), ARGSTACK, OPD1(i),ARGSTACK);
			break;
		case QCALL:
			int mid=buildNodes(OPT(i),ARGSTACK, OPD1(i),ARGSTACK);
			if (OPT(i + 1) == QRET)
			{
				varNodeMap[OPD1(i + 1)] = mid;
			}
		default:
			continue;
		}
	}
}
bool testOpt(int node, vector<int>& midNodeQueue)
{
	bool select = true;
	if (isLeaf(node))
	{
		return false;
	}
	for (int j = 0; j < cnodeBuff[node].parents.size(); j++)
	{
		if (midNodeQueue.end() != find(midNodeQueue.begin(), midNodeQueue.end(), cnodeBuff[node].parents[j]))
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
	qCType qc = (qCType)OPT(node);
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
				OPT(line + 1) = QRET;
				OPD1(line + 1) = ret;
				total += 1;
			}
			break;
	}
	return total;
}
int dagExtract(int start)
{
	//1.reserve labels
	while (OPT(start) == QLABEL) { start++; }
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
	vector<int>::iterator it=midNodeQueue.end();
	for (; it != midNodeQueue.begin(); it--)
	{
		int mid = *it;
		//find all related vars
		start+=nodeToCode(mid,start);
	}
	return start;
}
void codeCopy(int lineSrc, int lineDst)
{
	for (int i = 0; i < 4; i++)
	{
		qCode[lineDst + i] = qCode[lineSrc + i];
	}
}
void merge()
{
	int  dst = bnodeBuff[0].lineEnd+1;
	for (int i = 1; i < cnodePos; i++)
	{
		int src = bnodeBuff[i].lineStart;
		for (int j =0; j <=bnodeBuff[i].lineEnd- bnodeBuff[i].lineStart; j++)
		{
			codeCopy(src+j,dst+j);
		}
	}
}
void optimize()
{
	flowGraphBuild();
	flowGraphExtract();
}