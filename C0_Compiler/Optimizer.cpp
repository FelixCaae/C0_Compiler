#include "Optimizer.h"
#include <map>
using namespace std;
CNode cnodeBuff[cnodeBuffSize];
BNode bnodeBuff[bnodeBuffSize];
map<int, int> varNodeMap;
int cnodePos = 0;
int bnodePos = 0;
void initBlock(int i)
{
	bnodeBuff[i].inEnd = 0;
	bnodeBuff[i].outEnd = 0;
}
void connect(int blockHead, int blockTail)
{
	int i;
	bnodeBuff[blockHead].out[bnodeBuff[blockHead].outEnd++] = blockTail;
	bnodeBuff[blockTail].in[bnodeBuff[blockTail].inEnd++] = blockHead;
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
void flowGraphBuild(qCType* qCode,int linesTotal)
{
	int index[100];
	map<int, int> labelBlockMap;
	int left, right;
	left = 0;
	//First loop:build blocks and basic connection
	for (int i = 0; i < linesTotal; i++)
	{
		if (qCode[i*codeSize] == QBNZ || qCode[i*codeSize] == QBZ)
		{
			setBlock(bnodePos, left, i);
			initBlock(bnodePos+1);
			connect(bnodePos, bnodePos + 1);
			left = i + 1;
			bnodePos++;
		}
		else if (qCode[i] == QLABEL)
		{
			labelBlockMap.insert(pair<int,int>(qCode[i*codeSize + 1], bnodePos));
			setBlock(bnodePos, left, i-1);
			initBlock(bnodePos+1);
			connect(bnodePos, bnodePos + 1);
			left = i;
			bnodePos++;
		}
	}
	//set final block and end block
	setBlock(bnodePos,left, linesTotal);
	initBlock(bnodePos+1);
	connect(bnodePos, bnodePos+1);
	//Second loop:build connection based on labels
	for (int i = 0; i < linesTotal; i++)
	{
		if (qCode[i*codeSize] == QBNZ || qCode[i*codeSize] == QBZ || qCode[i*codeSize] == QGOTO)
		{
			int label = qCode[i*codeSize + 1];
			int bCur = lineMapBlock(i);
			connect(bCur,labelBlockMap[label]);
		}
	}
}
void flowGraphExtract()
{
	for (int i = 0; i < bnodePos; i++)
	{
		dagBuild(bnodeBuff[i].lineStart, bnodeBuff[i].lineEnd);
		dagExtract(bnodeBuff[i].lineStart);
	}
	merge();
}
int leafNodeSelect(int val)
{
	for (int i = 0; i < cnodePos; i++)
	{
		if (cnodeBuff[i].mark == val)
		{
			return i;
		}
	}
	cnodePos++;
	cnodeBuff[cnodePos].mark = val;
	varNodeMap[val] = cnodePos;
	return cnodePos;
}
int midNodeSelect(int op,int res, int lchild, int rchild)
{
	for (int i = 0; i < cnodePos; i++)
	{
		if (cnodeBuff[i].mark == op && cnodeBuff[i].lchild == lchild && cnodeBuff[i].rchild == rchild)
		{
			return i;
		}
	}
	cnodePos++;
	cnodeBuff[cnodePos].mark = op;
	cnodeBuff[cnodePos].lchild = lchild;
	cnodeBuff[cnodePos].rchild = rchild;
	cnodeBuff[lchild].parents.push_back(cnodePos);
	cnodeBuff[rchild].parents.push_back(cnodePos);
	varNodeMap[res] = cnodePos;
	return cnodePos;
}
void dagBuild(int start, int end)
{
	int i = 0;
	int mid=0, lchild=0, rchild=0;
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
		lchild=leafNodeSelect(OP1(i));
		rchild = leafNodeSelect(OP2(i));
		midNodeSelect(-OP(i), RES(i), lchild, rchild);
		break;
		case QASSIGN:
			lchild = leafNodeSelect(OP1(i));
			midNodeSelect(-OP(i), RES(i),lchild, 0);
			break;
		case QREAD:
			midNodeSelect(-OP(i), RES(i), -OP(i), 0);
			break;
		case QPRINT:
			midNodeSelect(-OP(i), RES(i), -OP(i), 0);
			break;
		case QPUSH:
			midNodeSelect(-QPLUS,STACK,STACK,RES(i));
			break;
		case QCALL:
			midNodeSelect(-QMINUS, STACK, STACK, RES(i));
		default:
			continue;
		}
	}
}
bool testOpt(int node, vector<int>& midNodeQueue)
{
	bool select = true;
	for (int j = 0; j < cnodeBuff[node].parents.size(); j++)
	{
		if (midNodeQueue.end() == find(midNodeQueue.begin(), midNodeQueue.end(), cnodeBuff[node].parents[j]))
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
	if (vars.size() == 1)return vars[0];
	else if(vars.size()>1)
	{

	}
	return -1;
}
int nodeToCode(int node, int line)
{
	qCType qc = (qCType)-OP(node);
	switch (qc)
	{
		switch (qc)
		{
		case QPLUS:
		case QMINUS:
		case QSTAR:
		case QDIV:
		case QARR:
		case QARL:
			lchild = leafNodeSelect(OP1(i));
			rchild = leafNodeSelect(OP2(i));
			midNodeSelect(-OP(i), RES(i), lchild, rchild);
			break;
		case QASSIGN:
			lchild = leafNodeSelect(OP1(i));
			midNodeSelect(-OP(i), RES(i), lchild, 0);
			break;
		case QREAD:
			midNodeSelect(-OP(i), RES(i), -OP(i), 0);
			break;
		case QPRINT:
			midNodeSelect(-OP(i), RES(i), -OP(i), 0);
		case QPUSH:
			midNodeSelect();
		default:
			continue;
		}
	}
	return 1;
}
int dagExtract(int start)
{
	//1.reserve labels
	while (OP(start) == QLABEL) { start++; }
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