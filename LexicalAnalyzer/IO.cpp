#include"stdafx.h"
#include <stdio.h>
#include "IO.h"
#include "Error.h"
#include "Lexeme.h"
using namespace std;
bool toConsole = true;
FILE* inFile = NULL;
FILE* outFile = NULL;
void outputLexeme()
{
	printf("%d\t%s\t%s\trow:%d\tcolmn:%d\n", lextype, lexClassName[lextype - 1], token,lineCounter,columnCounter);
	if (!toConsole)
	{
		fprintf(outFile, "%d\t%s\t%s\trow:%d\tcolmn:%d\n", lextype, lexClassName[lextype - 1], token, lineCounter, columnCounter);
	}
}
void init(int argc, char ** argv)
{
	if (argc != 2 && argc != 3)
	{
		error(8);
	}
	FILE* f = NULL;
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		error(0);
	}
	inFile = f;
	if (argc == 3)
	{
		f = fopen(argv[2], "w+");
		if (f == NULL)
		{
			error(0);
		}
		outFile = f;
		toConsole = false;
	}
}
void close()
{
	fclose(inFile);
	if (!toConsole)fclose(outFile);
}