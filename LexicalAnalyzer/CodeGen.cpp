#include "stdafx.h"
#include"CodeGen.h"
#include"IO.h"
#include <cstring>
#include <stdio.h>
unsigned int qcPos;
unsigned int labelCounter=0;
unsigned int caseCounter=0;
unsigned int line=0;
char labelTable[maxLabelNum][maxLabelStrLen];
int labelLine[maxLabelNum];
int qCode[maxQCodeSize * 4];
int genLabel(lableType lt,char *name)
{
	switch (lt)
	{
	case LIF:
		sprintf(labelTable[labelCounter],"if_%d",labelCounter);
		break;
	case LWHILE:
		sprintf(labelTable[labelCounter], "do_%d", labelCounter);
		break;
	case LSWITCH:
		sprintf(labelTable[labelCounter], "switch_%d", labelCounter);
		caseCounter = 0;
		break;
	case LCASE:
		sprintf(labelTable[labelCounter], "case_%d_%d", caseCounter,labelCounter);
		break;
	case LFUNC:
	//	strcat(labelTable[labelCounter], "\");
		sprintf(labelTable[labelCounter], name);
		break;
	case L:
		sprintf(labelTable[labelCounter], name);
		break;
	}
	return labelCounter++;
}
int findLabel(char * name)
{
	int i = 0;
	for (; i < labelCounter; i++)
	{
		if (strcmp(name, labelTable[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}
void setLabel(int label)
{
	labelLine[label] = line;
	outputLabel(label);
}
void emit(qCType qc,int arg1,int arg2,int arg3)
{
	outputQCode(qc, arg1, arg2, arg3);
	qCode[qcPos] = qc;
	qCode[qcPos + 1] = arg1;
	qCode[qcPos + 2] = arg2;
	qCode[qcPos + 3] = arg3;
	qcPos += 4;
	line += 1;
}