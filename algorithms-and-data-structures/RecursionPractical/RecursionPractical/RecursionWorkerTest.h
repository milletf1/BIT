#pragma once
#include "RecursionWorker.h"
#define POWER_OF_THREE_TESTS 5

ref class RecursionWorkerTest
{
private:
	bool testPowerOfThreeWhenCorrect();
	bool testPowerOfThreeWhenWrong();
	bool testPowerOfThreeWhenDivisibleByThree();
	bool testPowerOfThreeBaseCaseCorrect();
	bool testPowerOfThreeBaseCaseWrong();
public:
	RecursionWorkerTest();

	String^ runTests();
};
