#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Error.h"
#include "Lexeme.h"
void error(int err,int lex)
{
	//printf("Error happended!");
	if (err == 0)
	{
		printf("File error!");
	}
	else if (err == 1)
	{
		printf("Word is too long!");
	}
	else if (err == 2)
	{
		printf("Error in parsing ident: %s", token);
	}
	else if (err == 3)
	{
		printf("Error in parsing number: %s", token);
	}
	else if (err == 4)
	{
		printf("Error in parsing char: %s", token);
	}
	else if (err == 5)
	{
		printf("Error in parsing string: %s", token);
	}
	else if (err == 6)
	{
		printf("Error in parsing seperator: %s", token);
	}
	else if (err == 7)
	{
		printf("Unexpected character: '%c'", chr);
	}
	else if (err == 8)
	{
		printf("Argument error");
	}
	else if (err == 9)
	{
		printf("Error9:(%d,%d)next sym shouldbe£º%s", lineCounter, columnCounter, lexClassName[lex]);
	}
	exit(1);
}