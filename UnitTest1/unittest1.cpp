#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\user\Documents\OOP_test\OOP_test\OOP_test.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 5;
			Assert::AreEqual(5, n);
			
		}

	};
}