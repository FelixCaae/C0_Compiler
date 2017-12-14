#include "stdafx.h"
#include <exception>
#include "CppUnitTest.h"
#include "direct.h"
#include "../LexicalAnalyzer/Lexeme.h"
#include "../LexicalAnalyzer/IO.h"
#include "../LexicalAnalyzer/Error.h"
#include "../LexicalAnalyzer/Syntax.h"
#include "../LexicalAnalyzer/Symtable.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace C0_UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		char *buffer[2];
		TEST_METHOD_INITIALIZE(INI)
		{
			
		}
		TEST_METHOD_CLEANUP(CLE)
		{
			cleanup();
		}
		TEST_METHOD(TestMethod1)
		{
			buffer[1] = "test/test_100.txt";///"test/test_100.txt";
			syntaxAnalyze(2, buffer);
		}
		TEST_METHOD(TestMethod2)
		{
			buffer[1] = "test/test_add.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod3)
		{
			buffer[1] = "test/test_alpha.txt";
			try {
				syntaxAnalyze(2, (char**)buffer);
			}
			catch (char*b)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(TestMethod4)
		{
			buffer[1] = "test/test_colors.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod5)
		{
			buffer[1] = "test/test_equalsplit.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod6)
		{
			buffer[1] = "test/test_expression.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod7)
		{
			buffer[1] = "test/test_hw.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod8)
		{
			buffer[1] = "test/test_switch.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod9)
		{
			buffer[1] = "test/test_olympic.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod10)
		{
			buffer[1] = "test/test_op.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod11)
		{
			buffer[1] = "test/test_square.txt";
			try{
			syntaxAnalyze(2, (char**)buffer);
			}
			catch(...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(TestMethod12)
		{
			buffer[1] = "test/test_TAJ.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod13)
		{
			buffer[1] = "test/test_transprint.txt";
			syntaxAnalyze(2, (char**)buffer);
		}
		TEST_METHOD(TestMethod14)
		{
			try {
				buffer[1] = "test/wtest_jerry.txt";
				syntaxAnalyze(2, (char**)buffer);
				Assert::Fail();
			}
			catch(...)
			{ }
		}
	};
}