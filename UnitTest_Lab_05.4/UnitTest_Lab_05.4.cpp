#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05.4/Lab_05.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
    TEST_CLASS(UnitTest54)
    {
    public:

        // N = 19 -> у сумі лише один доданок: sqrt(sin^2 19 + cos^2 1)
        TEST_METHOD(TestOneTerm)
        {
            double expected = sqrt(sin(19.0) * sin(19.0) + cos(1.0) * cos(1.0));
            Assert::AreEqual(expected, S0(19));
            Assert::AreEqual(expected, S1(19, 19, 0));
            Assert::AreEqual(expected, S3(19, 19));
        }

        // N = 20 > 19 -> сума порожня, дорівнює 0
        TEST_METHOD(TestEmpty)
        {
            Assert::AreEqual(0.0, S0(20));
            Assert::AreEqual(0.0, S2(20, 20, 0));
            Assert::AreEqual(0.0, S4(20, 20));
        }

        // усі 5 способів дають однаковий результат
        TEST_METHOD(TestAllEqual)
        {
            int N = 5;
            double s0 = S0(N);
            Assert::AreEqual(s0, S1(N, 19, 0));
            Assert::AreEqual(s0, S2(N, N, 0));
            Assert::AreEqual(s0, S3(N, 19));
            Assert::AreEqual(s0, S4(N, N));
        }
    };
}
