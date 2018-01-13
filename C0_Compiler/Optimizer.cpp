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
void fgClear();
int lineMapBlock(int line);
void initCNode(int cnode);
bool isLeaf(int cnode);
void connectLeft(int parent, int child);
void connectRight(int parent, int child);
void dagClear();
void defReachingAnalysis();
void activeVarAnalysis();
void flowGraphBuild();
void flowGraphExtract();
void dagBuild(int start, int end);
int dagExtract(int start);
void connect(int blockHead, int blockTail)
{
	OUTSET(blockHead).insert(blockTail);
	INSET(blockTail).insert(blockHead);
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
void fgClear()
{
	while (bnodePos > 0)
	{
		bnodePos = bnodePos - 1;
		LSTART(bnodePos) = 0;
		LEND(bnodePos) = 0;
		INSET(bnodePos).clear();
		OUTSET(bnodePos).clear();
	}
}
bool isDefPoint(int line)
{
	switch (OPT(line))
	{
	case QASSIGN:
	case QPLUS:
	case QMINUS:
	case QSTAR:
	case QDIV:
	case QARL:
	case QARR:
	case QREAD:
	case QRETX:
		return true;
		break;
	default:
		return false;
	}
}
bool isUsePoint(int line)
{
	switch (OPT(line))
	{

	case QARR:
	case QPRINT:
	case QPUSH:
		return true;
		break;
	default:
		return false;
	}
}
int codeType(int line)
{
	switch (OPT(line))
	{
	case QASSIGN:
		return udAssign;
	case QPLUS:
	case QMINUS:
	case QSTAR:
	case QDIV:
	case QARL:
	case QARR:
		return udPlus;
	case QREAD:
	case QRETX:
		return udRead;
	case QPRINT:
	case QPUSH:
		return udPrint;
	default:
		return udDefault;
	}
}
/*
void addDefPoint(int var, int line)
{
	if (FIND(defPntsMap, var) == defPntsMap.end())
	{
		//..
	}
	defPntsMap[var].insert(line);
}*/
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
			if (i < left)continue;
			setBlock(bnodePos, left, i);
			connect(bnodePos, bnodePos + 1);
			left = i + 1;
			bnodePos++;
		}
		else if (OPT(i) == QLABEL)
		{
			if (i-1 < left)continue;
			labelBlockMap[OPD1(i)] = bnodePos+1;
			setBlock(bnodePos, left, i - 1);
			connect(bnodePos, bnodePos + 1);
			left = i;
			bnodePos++;
		}
		else if (OPT(i) == QRET || OPT(i) == QGOTO)
		{
			if (i < left)continue;
			setBlock(bnodePos, left, i);
			left = i + 1;
			bnodePos++;
		}
	}
	//compelete final block 
	if (left <= line-1)
	{
		setBlock(bnodePos++, left, line - 1);
	}
	//set and connect to end block
	setBlock(bnodePos, NotExist, NotExist);
	connect(bnodePos-1, bnodePos);
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
			connect(bCur, bnodePos-1);//connect to end block
		}
	}
}
void flowGraphExtract()
{
	int startPos = 0;
	for (int blk = 0; blk < bnodePos-1; blk++)
	{
		dagBuild(LSTART(blk),LEND(blk));
		LSTART(blk)=startPos;
		LEND(blk)=dagExtract(startPos);
		startPos = LEND(blk) + 1;
	}
	line = startPos;
	printf("Dag:\n");
	for (int ln = 0; ln <= LEND(bnodePos - 2); ln++)
	{
		outputQCode(ln);
	}

}
void initCNode(int cnode)
{
	LCHILDC(cnode) = NotExist;
	RCHILDC(cnode) = NotExist;
	MARK(cnode) = 0;
	PARENTSC(cnode).clear();
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
void dagClear()
{
	headCodes.clear();
	tailCodes.clear();
	while(cnodePos>0)
	{
		initCNode(cnodePos - 1);
		cnodePos = cnodePos - 1;
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
	printf("add leafnode:%d ident:%d\n",cnodePos,val);
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
	printf("add midnode:%d op:%d\n", cnodePos, op);
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
	dagClear();//
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
		case QFUNCDECL:
			headCodes.push_back(i);
			break;
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
bool isSpecialOPD(int val)
{
	if (val >= specOpdIndex && val < specOpdIndex + specOpdSize)
	{
		return true;
	}
	return false;
}
int selectVar(int node)
{
	map<int, int>::iterator it;
	for (it = varNodeMap.begin(); it != varNodeMap.end(); it++)
	{
		if (it->second == node && !isSpecialOPD(it->first))
		{
			return it->first;
		}
	}
	return NOTFOUND;
}
int selectComputVar(int node)
{
	map<int, int>::iterator it;
	for (it = varNodeMap.begin(); it != varNodeMap.end(); it++)
	{
		if (it->second==node && !isSpecialOPD(it->first))
		{
			return it->first;
		}
	}
	{
		vector<int>::iterator it;
		for (it = PARENTSC(node).begin(); it != PARENTSC(node).end(); it++)
		{
			int r = selectComputVar(*it);
			if (r != NotFound)return r;
		}
	}
	return NOTFOUND;
}
int selectDisplayVar(int node)
{
	int r=selectComputVar(node);
	if (r == NOTFOUND)
	{
		r = genTemp(INTS);
		return r;
	}
}
void getVarsByNode(int node,vector<int>& vars)
{
	map<int, int>::iterator it;
	vars.clear();
	for (it = varNodeMap.begin(); it != varNodeMap.end(); it++)
	{
		if (it->second == node && it->first>=0)
		{
			vars.push_back(it->first);
		}
	}
	if (vars.size() == 0)
	{
		vector<int>::iterator it;
		for (it = PARENTSC(node).begin(); it != PARENTSC(node).end(); it++)
		{
			getVarsByNode(*it, vars);
			if (vars.size() != 0)
			{
				break;
			}
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
			OPD1(line) = selectComputVar(node);
			OPD2(line) = selectComputVar(LCHILDC(node));
			OPD3(line) = selectComputVar(RCHILDC(node));
			break;
		case QREAD:
			OPD1(line) = selectComputVar(node);
			break;
		case QPRINT:
		case QPUSH:
			OPD1(line) =selectDisplayVar(LCHILDC(node));
			break;
		case QCALL:
			OPD1(line) = selectComputVar(LCHILDC(node));
			int ret = selectVar(node);
			if (ret != NOTFOUND)
			{
				OPT(line + 1) = QRETX;
				OPD1(line + 1) = ret;
				total += 1;
			}
			break;
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
void debugShowSet(set<int> st,int mode=0)
{
	set<int>::iterator it;
	for (it = st.begin(); it != st.end(); it++)
	{
		if (mode == 0)
		{
			printf("%d ", *it);
		}
		else
		{
			printf("%s ", OP(*it));
		}
	}
}
void defReachingAnalysis()
{
	//<debug>
	printf("\nReaching definition analysis\n");
	//</debug>
	bool debug = true;
	map<int, set<int>> defPntsMap;
	for (int ln = 0; ln < line; ln++)
	{
		if (isDefPoint(ln))
		{
			//<debug>
			printf("def point:%d\n", ln);
			outputQCode(ln);
			//</debug>
			defPntsMap[OPD1(ln)].insert(ln);
		}
	}
	set<int> temp,tempKill;
	for (int blk = 0; blk < bnodePos-1 ; blk++)
	{
		for (int ln = LSTART(blk); ln <= LEND(blk); ln++)
		{
			if (isDefPoint(ln))
			{
				temp.clear();
				tempKill.clear();
				temp.insert(ln);
				DIFF(defPntsMap[OPD1(ln)], temp, tempKill);
				UNION(tempKill, KILLSET(blk), KILLSET(blk));
				DIFF(GENSET(blk), tempKill, GENSET(blk));
				UNION(GENSET(blk), temp, GENSET(blk));
			}
		}
	}
	//<debug>
	for (int blk = 0; blk < bnodePos-1; blk++)
	{
		printf("\nblk-%d gen:",blk);
		debugShowSet(GENSET(blk));
		printf("\nblk-%d kill:",blk);
		debugShowSet(KILLSET(blk));
	}
	//</debug>
	bool isContinue=true;
	set<int> tempOut,test;
	while (isContinue)
	{
		isContinue = false;
		for (int blk=0;blk<bnodePos;blk++)
		{
			tempOut.clear();
			test.clear();
			DIFF(DEFINSET(blk), KILLSET(blk), tempOut);
			UNION(tempOut, GENSET(blk), tempOut);
			DIFF(tempOut,DEFOUTSET(blk), test);
			DEFOUTSET(blk) = tempOut;
			if (test.size() != 0)
			{
				int nxtBlk;
				set<int>::iterator it;
				for (it=OUTSET(blk).begin();it!=OUTSET(blk).end(); it++)
				{
					nxtBlk = *it;
					UNION(DEFINSET(nxtBlk), DEFOUTSET(blk), DEFINSET(nxtBlk));
					//DEFINSET(nxtBlk) = DEFOUTSET(blk);
				}
				isContinue = true;
			}
		}
	}
	//<debug>
	for (int blk = 0; blk < bnodePos; blk++)
	{
		printf("\nblk-%d  in:",blk);
		debugShowSet(DEFINSET(blk));
		printf("\nblk-%d  out:",blk);
		debugShowSet(DEFOUTSET(blk));
	}
	//</debug>
}
void addActUse(int block, int iden)
{
	if (!FOUND(DEFSET(block), iden)&&!ISCONST(iden))
	{
		USESET(block).insert(iden);
	}
}
void addActDef(int block, int iden)
{
	if (!FOUND(USESET(block), iden))
	{
		DEFSET(block).insert(iden);
	}
}
void activeVarAnalysis()
{
	bool debug = true;
	//<debug>
	printf("\nActive var analysis\n");
	//</debug>
	set<int> temp, tempKill;
	for (int blk = 0; blk < bnodePos - 1; blk++)
	{
		for (int ln = LSTART(blk); ln <= LEND(blk); ln++)
		{
			temp.clear();
			switch (codeType(ln))
			{
			case udAssign:
				addActUse(blk,OPD2(ln));
				addActDef(blk,OPD1(ln));
				break;
			case udPlus:
				addActUse(blk, OPD3(ln));
				addActUse(blk, OPD2(ln));
				addActDef(blk, OPD1(ln));
				break;
			case udRead:
				addActDef(blk, OPD1(ln));
				break;
			case udPrint:
				addActUse(blk, OPD1(ln));
				break;
			default:
				continue;
			}
		}
	}
	//<debug>
	for (int blk = 0; blk < bnodePos - 1; blk++)
	{
		printf("\nblk-%d def:", blk);
		debugShowSet(DEFSET(blk),1);
		printf("\nblk-%d use:", blk);
		debugShowSet(USESET(blk),1);
	}
	//</debug>
	bool isContinue = true;
	set<int> tempIn, test;
	while (isContinue)
	{
		isContinue = false;
		for (int blk = bnodePos-1; blk>=0; blk--)
		{
			int nxtBlk;
			set<int>::iterator it;
			for (it = OUTSET(blk).begin(); it != OUTSET(blk).end(); it++)
			{
				nxtBlk = *it;
				UNION(ACTINSET(nxtBlk), ACTOUTSET(blk), ACTOUTSET(blk));
				//DEFINSET(nxtBlk) = DEFOUTSET(blk);
			}
			tempIn.clear();
			test.clear();
			DIFF(ACTOUTSET(blk), DEFSET(blk), tempIn);
			UNION(tempIn, USESET(blk), tempIn);
			DIFF(tempIn, ACTINSET(blk), test);
			ACTINSET(blk)=tempIn;
			if (test.size() != 0)
			{
				isContinue = true;
			}
		}
	}
	//<debug>
	for (int blk = 0; blk < bnodePos; blk++)
	{
		printf("\nblk-%d  in:", blk);
		debugShowSet(ACTINSET(blk),1);
		printf("\nblk-%d  out:", blk);
		debugShowSet(ACTOUTSET(blk),1);
	}
	//</debug>
}
void optimize()
{
	fgClear();
	flowGraphBuild();
	defReachingAnalysis();
	activeVarAnalysis();
	flowGraphExtract();
}