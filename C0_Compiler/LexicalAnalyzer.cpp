// LexicalAnalyzer.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <stdio.h>
#include <exception>
#include <cstring>
#include "IO.h"
#include "Lexeme.h"
#include "Error.h"
using namespace std;

char chr=0;
char token[tokenStrLen];
int lineCounter = 1, columnCounter = 0;
int tokenidx = 0;
int nodesNum = 0;
lexClass lextype;
void newNode();
void initNode(lexNode*p);
void openNode(lexNode*p);
void replaceTailNode();
bool belong(char chr, const char set[], int size);
int findReserveWord();
int findSeperator();
void readChar();
void retractChar();
void clearToken();
bool isInputEnd();
bool isBlank();
bool isNumber();
bool isSeperator();
bool isSingleQuote();
bool isDoubleQuote();
bool isAlpha();
bool isChar();
bool isAsciiChar();
void skipBlank();
void scannIDEN();
void scannCHR();
void scannSTR();
void scannSEP();
void scannINT();
void scann();
void readSym();
void retractSym(int num);
struct lexNode
{
	lexClass _lextype;
	char _token[lexNameLen];
	int _lc;
	int _cc;
	lexNode* _next;
	lexNode* _back;
} *currentNode = NULL;
void initNode(lexNode*p)
{
	p->_lextype = lextype;
	p->_lc = lineCounter;
	p->_cc = columnCounter;
	strcpy(p->_token, token);
	p->_next = NULL;
	p->_back = NULL;
}
void openNode(lexNode*p)
{
	lextype = p->_lextype;
	strcpy(token, p->_token);
	lineCounter = p->_lc;
	columnCounter = p->_cc;
}
void newNode()
{
	lexNode* pN = new lexNode();
	initNode(pN);
	if (currentNode == NULL)
	{
		currentNode = pN;
	}
	else
	{
		pN->_back = currentNode;
		currentNode->_next=pN;
		currentNode = pN;
	}
	nodesNum += 1;
}
void replaceTailNode()
{
	lexNode* p = currentNode;
	while (p->_back != NULL)
	{
		p = p->_back;
	}
	p->_next->_back = NULL;
	initNode(p);
	currentNode->_next = p;
	p->_back = currentNode;
	currentNode = p;
}
bool belong(char chr,const char set[],int size)
{
    for (int i = 0; i < size; i++)
    {
        if (chr == set[i])
        {
            return true;
        }
    }
    return false;
}
int findReserveWord()
{
    for (int i = 0; i < resrvNum; i++)
    {
        if (strcmp(token, resrvWrdsSet[i]) == 0)
        {
            return  i + 1;
        }
    }
    return 0;
}
int findSeperator()
{
    for (int i = 0; i < sepNum; i++)
    {
        if (chr == sepSet[i])
        {
            return i + 1;
        }
    }
    return 0;
}
void readChar()
{
    chr = fgetc(inFile);
	if (chr == '\n')
	{
		lineCounter += 1;
		columnCounter = 0;
	}
	if (tokenidx == tokenStrLen)error(ERR_TOKEN_FLOW);
    token[tokenidx++] = chr;
    token[tokenidx] = '\0';
}
void retractChar()
{

    fseek(inFile, -2, SEEK_CUR);
    chr = fgetc(inFile);
    tokenidx--;
    token[tokenidx] = '\0';
}
void clearToken()
{
    tokenidx = 0;
    token[tokenidx] = '\0';
}
bool isInputEnd()
{
    return chr == EOF;
}
bool isBlank()
{
    return belong(chr, blankSet, blankNum);
}
bool isNumber()
{
    return chr <= '9' && chr >= '0';
}
bool isSeperator()
{
    return belong(chr, sepSet, sepNum);
}
bool isSingleQuote()
{
    return chr == '\'';
}
bool isDoubleQuote()
{
    return chr == '\"';
}
bool isAlpha()
{
    return chr == '_' || (chr >= 'a'&&chr <= 'z') || (chr >= 'A'&&chr <= 'Z');
}
bool isChar()
{
    return isAlpha()||isNumber()|| chr == '+' || chr == '-' || chr == '*' || chr == '/';
}
bool isAsciiChar()
{
    return chr == 32 || chr == 33 || (chr >= 35 && chr <= 126);
}


void scannIDEN()
{
    lextype = IDEN;
	char* p= token;
    while (!isBlank()&&!isInputEnd()&&!isSeperator())
    {
        if (!isAlpha() && !isNumber())
        {
            error(ERR_LEX_UNEX,chr);
			skip(blankSet, blankNum);
			return;
        }
        readChar();
		if (*p >= 'A'&&*p <= 'Z')
		{
			*p |= 0x60;
		}
		p++;
    }
    retractChar();
    int r = findReserveWord();
    if (r != 0)
    {
        lextype = (lexClass)(NEQU + r);
    }
}

void scannCHR()
{
    lextype = CHR;
	const char endChar[] = { '\n','\'' };
    readChar();
    if (!isChar())
    {
        error(ERR_LEX_UNEX);
		return;
    }
    readChar();
    if (!isSingleQuote())
    {
        error(ERR_LEX_UNEX);
		skip(endChar, 2);
    }
}
void scannSTR()
{
    lextype = STR;
	const char endStr[] = { '\n','\"' };
    readChar();
    while (!isDoubleQuote())
    {
        if (!isAsciiChar())
        {
            error(ERR_LEX_UNEX);
			skip(endStr, 2);
        }
        readChar();
    }
}
void scannSEP()
{
    if (chr == '>')
    {
        readChar();
        if (chr == '=')
        {
            lextype = GTEQU;
        }
        else
        {
            retractChar();
            lextype = GT;
        }
    }
    else if (chr == '<')
    {
        readChar();
        if (chr == '=')
        {
            lextype = LSEQU;
        }
        //	printf("found an equatation");
        /*if (chr == '=')
        {
        	lextype == LSEQU;
        }*/
        else
        {
            retractChar();
            lextype = LS;
        }
    }
    else if (chr == '!')
    {
        readChar();
        if (chr != '=')
        {
            error(ERR_LEX_EX,'=');
        }
        else
        {
            lextype = NEQU;
        }
    }
	else if (chr == '\\')
	{
		const char cmntLine[] = { '\n' };
		const char cmntBlock[] = { '*' };
		readChar();
		if (chr == '\\')
		{
			skip(cmntLine, 1);
			scann();
		}
		else if(chr=='*' )
		{
			do {
				skip(cmntBlock, 1);
				readChar();
			}while (chr != '\\' && !isInputEnd());
			scann();
		}
		else 
		{
			error(ERR_LEX_UNEX, '\\');
		}
	}
    else if (chr == '=')
    {
        readChar();
        if (chr != '=')
        {
            retractChar();
            lextype = ASSIGN;
        }
        else
        {
            lextype = EQU;
        }
    }
    else
    {
        int r = findSeperator();
        if (r == 0)
        {
            error(ERR_LEX_UNEX);
        }
        lextype = (lexClass)(STR + r);
    }

}
void scannINT()
{
	lextype = INT;
	while (!isBlank() && !isInputEnd() && !isSeperator())
	{
		if (!isNumber())
		{
			error(ERR_LEX_UNEX);
			skip(blankSet, blankNum);
		}
		readChar();
	}
	retractChar();
}
void skipBlank()
{
	while (true)
	{
		readChar();
		if (!isBlank())
			break;
		else
			clearToken();
	}

}
void scann()
{
	clearToken();
	skipBlank();
    if (isAlpha())
    {
        scannIDEN();
    }
    else if (isNumber())
    {
        scannINT();
    }
    else if (isSingleQuote())
    {
        scannCHR();
    }
    else if (isDoubleQuote())
    {
        scannSTR();
    }
    else if (isSeperator())
    {
        scannSEP();
    }
	else if (isInputEnd())
	{
		lextype = END;
	}
    else
    {
        error(ERR_LEX_UNEX);
    }
	outputLexeme();
}
void readSym()
{
	if (currentNode != NULL &&currentNode->_next!=NULL)
	{
		currentNode = currentNode->_next;
		openNode(currentNode);
	}
	else {
		scann();
		columnCounter += 1;
		if (nodesNum < maxRetractNum)
		{
			newNode();
		}
		else
		{
			replaceTailNode();
		}
	}
}
void retractSym(int num)
{
	while (num-- > 0) {
		if (currentNode == NULL || currentNode->_back == NULL)
		{
			error(ERR_LEX_UNEX);
		}
		else
		{
			currentNode = currentNode->_back;
			openNode(currentNode);
		}
	}
}

