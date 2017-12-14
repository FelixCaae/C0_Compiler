#include "stdafx.h"
#include "CppUnitTest.h"
#include "../LexicalAnalyzer/SymTable.h"
#include "../LexicalAnalyzer/CodeGen.h"
#include "../LexicalAnalyzer/IO.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace C0_UnitTest
{

	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD_CLEANUP(CLE)
		{
			cleanup();
		}
		TEST_METHOD(TEST_SYMTABLE)
		{
			insertIdent("ch",CHARS,OVAR);
			insertIdent("it", INTS, OVAR);
			insertIdent("car", CHARS, OARRAY,3);
			insertIdent("ch2", CHARS, OCONST, 'a');
			insertIdent("main", NOTYPS, OFUNC);
			insertString("HelloWorld");
			Assert::AreEqual(0,lookupIdent("ch",linkHead));
			Assert::AreEqual(1, lookupIdent("it", linkHead));
			Assert::AreEqual(2, lookupIdent("car", linkHead));
			Assert::AreEqual(4, lookupIdent("main", linkHead));
			Assert::AreEqual(3, lookupIdent("ch2", linkHead));
		}
		TEST_METHOD(TEST_SYMTABLE_FUNC)
		{
			insertIdent("gl", CHARS, OVAR);
			Assert::AreNotEqual(lookupIdent("gl",linkHead), NotFound);
			Assert::AreNotEqual(lookupIdent("gl", linkGlobal), NotFound);
			insertIdent("func1", INTS, OFUNC);
			enterFunc();
			insertIdent("lc", CHARS, OVAR);
			Assert::AreNotEqual(lookupIdent("gl",linkGlobal), NotFound);
			Assert::AreEqual(lookupIdent("gl",linkHead), NotFound);
			Assert::AreNotEqual(lookupIdent("lc", linkHead), NotFound);
			leaveFunc();
			Assert::AreEqual(lookupIdent("lc", linkHead), NotFound);
			Assert::AreEqual(lookupIdent("lc", linkGlobal), NotFound);
			Assert::AreNotEqual(lookupIdent("gl", linkHead), NotFound);
			Assert::AreNotEqual(lookupIdent("gl", linkGlobal), NotFound);
		}
		TEST_METHOD(TEST_QCODEOUT)
		{
			char * buffer[3];
			buffer[1] = "test/test_100.txt";
			init(2, buffer);
			insertIdent("ch", CHARS, OVAR);
			insertIdent("it", INTS, OVAR);
			insertIdent("car", CHARS, OARRAY, 3);
			insertIdent("ch2", CHARS, OCONST, 'a');
			insertIdent("main", NOTYPS, OFUNC);
			insertString("HelloWorld");
			emit(QVAR, 0);
			emit(QVAR, 1);
			emit(QARRAY, 2);
			emit(QCONST, 3);
			emit(QFUNCDECL,4);
			int l=genLabel(LIF);
			setLabel(l);
			emit(QPLUS, 1, 0, 2);
			emit(QEQU, 1, 2);
			emit(QBNZ, l);
		}
	};
}