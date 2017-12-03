#pragma once
extern FILE * inFile;
extern FILE * outFile;
extern bool toConsole;
void outputLexeme();
void outputSyntax();
void init(int argc,char**argv);
void close();