#include "pch.h"
#include "CppUnitTest.h"
#include "../DSP_Lab_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 4;
			n = factorial(n);
			Assert::AreEqual(n, 24);
		}
	};
}
