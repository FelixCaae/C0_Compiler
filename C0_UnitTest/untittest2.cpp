#include "stdafx.h"
#include "CppUnitTest.h"
#include "../C0_Compiler/SymTable.h"
#include "../C0_Compiler/CodeGen.h"
#include "../C0_Compiler/IO.h"
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
			enterFunc(0);
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
		TEST_METHOD(TEST_SYMTABLE_UNLINK)
		{
			insertIdent("var1", INTS, OVAR);
			unlink();
			Assert::AreEqual(lookupIdent("var1"), NotFound);
			insertIdent("var1", INTS, OVAR);
			insertIdent("var2", INTS, OVAR);
			insertIdent("var3", INTS, OVAR);
			unlinkAll();
			Assert::AreEqual(lookupIdent("var1"),NotFound);
			Assert::AreEqual(lookupIdent("var2"), NotFound);
			Assert::AreEqual(lookupIdent("var3"), NotFound);
			insertIdent("var1", INTS, OVAR);
			enterFunc(0);
			insertIdent("var1", INTS, OVAR);
			genTemp(INTS);
			genTemp(INTS);
			genTemp(INTS);
			unlinkAll();
			Assert::AreEqual(lookupIdent("var1", linkHead),NotFound);
			leaveFunc();
			Assert::AreNotEqual(lookupIdent("var1", linkHead), NotFound);
			unlink();
			Assert::AreEqual(lookupIdent("var1", linkHead), NotFound);
		}
		TEST_METHOD(TEST_SYMTABLE_LOC_ADR)
		{
			insertIdent("var1", INTS, OVAR);
			insertIdent("var2", CHARS, OVAR);
			insertIdent("ar1", INTS, OARRAY, 10);
			insertIdent("c1", INTS, OCONST, 10);
			insertIdent("func1", INTS, OFUNC);
			insertIdent("func2", INTS, OFUNC);
			locateAdr();
			Assert::AreEqual(symTable[4]._adr == 45, true);
			enterFunc(0);
			insertIdent("var1", INTS, OVAR);
			insertIdent("var2", CHARS, OARRAY, 20);
			insertIdent("var3", INTS, OVAR);
			locateAdr();
			int iden = lookupIdent("var3");
			Assert::AreEqual(symTable[iden]._adr ==24,true);
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