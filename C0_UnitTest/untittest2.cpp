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
			Assert::AreEqual(ADR(0) == Global, true);
			Assert::AreEqual(ADR(1) == Global, true);
			Assert::AreEqual(ADR(2) == Global, true);
			Assert::AreEqual(ADR(3) == Global, true);
			Assert::AreEqual(ADR(4) == Global, true);
			Assert::AreEqual(ADR(5) == Global, true);
			locateAdr();
			Assert::AreEqual(ADR(0) == 0, true);
			Assert::AreEqual(ADR(1) == 44, true);
			Assert::AreEqual(ADR(2) == 4, true);
			enterFunc(5);
			insertIdent("var1", INTS, OVAR);
			insertIdent("var2", CHARS, OARRAY, 21);
			insertIdent("var3", INTS, OVAR);
			Assert::AreEqual(ADR(6) == 0, true);
			Assert::AreEqual(ADR(7) == 0, true);
			Assert::AreEqual(ADR(8) == 0, true);
			locateAdr();
			Assert::AreEqual(ADR(6) == 0, true);
			Assert::AreEqual(ADR(7) == 8, true);
			Assert::AreEqual(ADR(8) == 4, true);
			Assert::AreEqual(FUNCSIZE(5) == 32, true);
			
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
			emit(QLABEL, l);
			emit(QPLUS, 1, 0, 2);
			emit(QEQU, 1, 2);
			emit(QBNZ, l);
		}

		TEST_METHOD(TEST_MIPSOUT)
		{
			char * buffer[3];
			buffer[1] = "test/test_100.txt";
			init(2, buffer);
			int ch=insertIdent("ch", CHARS, OVAR);
			int it=insertIdent("it", INTS, OVAR);
			int car=insertIdent("car", CHARS, OARRAY, 3);
			int ch2=insertIdent("ch2", CHARS, OCONST, 'a');
			int mainfunc = insertFunc(NOTYPS, 0, NULL);
			int main=insertIdent("main", NOTYPS, OFUNC,mainfunc);
			int str=insertString("HelloWorld");
			int lhead = genLabel(LFUNC, "main");
			int ltail = genLabel(LFUNCEND, "main");
			emit(QLABEL, lhead);
			emit(QVAR, ch);
			emit(QVAR, it);
			emit(QARRAY, car);
			emit(QCONST, ch2);
			emit(QFUNCDECL, main);
			emit(QPLUS, ch, it, ch2);
			emit(QEQU, ch, ch2);
			emit(QRET);
			emit(QLABEL, ltail);
			enterFunc(main);
		//	outputLabel(lhead, true);
			objFunc();
			//outputLabel(ltail, true);

		}
	};
}