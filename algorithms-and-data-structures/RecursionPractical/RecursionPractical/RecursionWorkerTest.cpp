#include "StdAfx.h"
#include "RecursionWorkerTest.h"

RecursionWorkerTest::RecursionWorkerTest()
{}

/*********************************************************************************
 * Precondition:  The user must have called the runTests function.
 *
 * PostCondition: Tests that the powerOfThree(double n) returns true when given a
 *                number that is a perfect power of three.
 ********************************************************************************/
bool RecursionWorkerTest::testPowerOfThreeWhenCorrect()
{ 
	RecursionWorker^ rw = gcnew RecursionWorker();
	double testCase = 81;
	bool expected = true;
    bool actual;
	
	actual = rw->powerOfThree(testCase);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the runTests function.
 *
 * PostCondition: Tests that the powerOfThree(double n) returns false when given a
 *                number that isn't a perfect power of three.
 *********************************************************************************/
bool RecursionWorkerTest::testPowerOfThreeWhenWrong()
{ 
	RecursionWorker^ rw = gcnew RecursionWorker();
	double testCase = 5;
	bool expected = false;
    bool actual;
	
	actual = rw->powerOfThree(testCase);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the runTests function.
 *
 * PostCondition: Tests that the powerOfThree(double n) returns false when given a
 *                number that is divisible by three, but isn't a perfect power of 
 *                three.
 *********************************************************************************/
bool RecursionWorkerTest::testPowerOfThreeWhenDivisibleByThree()
{ 
	RecursionWorker^ rw = gcnew RecursionWorker();
	double testCase = 12;
	bool expected = false;
    bool actual;
	
	actual = rw->powerOfThree(testCase);

	return expected == actual;  
}

/********************************************************************************
 * Precondition:  The user must have called the runTests function.
 *
 * PostCondition: Tests that the powerOfThree(double n) returns true when given a
 *                base case that is a perfect power of three.
 ********************************************************************************/
bool RecursionWorkerTest::testPowerOfThreeBaseCaseCorrect()
{ 
	RecursionWorker^ rw = gcnew RecursionWorker();
	double testCase = 1;
	bool expected = true;
    bool actual;
	
	actual = rw->powerOfThree(testCase);

	return expected == actual; 
}

/*********************************************************************************
 * Precondition:  The user must have called the runTests function.
 *
 * PostCondition: Tests that the powerOfThree(double n) returns false when given a
 *                base case that isn't a perfect power of three.
 *********************************************************************************/
bool RecursionWorkerTest::testPowerOfThreeBaseCaseWrong()
{ 
	RecursionWorker^ rw = gcnew RecursionWorker();
	double testCase = 2;
	bool expected = false;
    bool actual;
	
	actual = rw->powerOfThree(testCase);

	return expected == actual; 
}

/*******************************************************************************
 * Precondition:  This class must have access to the RecursionWorker class.
 *
 * PostCondition: Runs unit tests on the functions in the RecursionWorker class.
 *                Returns the test results as a string.
 ******************************************************************************/
String^ RecursionWorkerTest::runTests()
{
	String^ testResultSummary = "SortWorker Unit tests\r\n\r\n";
	int testPassTally = 0;
	bool testResult;

	testResultSummary += "Testing powerOfThree(double n) function\r\n\r\n";
	
	testResult = testPowerOfThreeWhenCorrect();
	testPassTally += (testResult)? 1 : 0;
	testResultSummary += Convert::ToString(testResult) + " testPowerOfThreeWhenCorrect\r\n";

	testResult = testPowerOfThreeWhenWrong();
	testPassTally += (testResult)? 1 : 0;
	testResultSummary += Convert::ToString(testResult) + " testPowerOfThreeWhenWrong\r\n";

	testResult = testPowerOfThreeWhenDivisibleByThree();
	testPassTally += (testResult)? 1 : 0;
	testResultSummary += Convert::ToString(testResult) + " testPowerOfThreeWhenDivisibleByThree\r\n";

	testResult = testPowerOfThreeBaseCaseCorrect();
	testPassTally += (testResult)? 1 : 0;
	testResultSummary += Convert::ToString(testResult) + " testPowerOfThreeBaseCaseCorrect\r\n";

	testResult = testPowerOfThreeBaseCaseWrong();
	testPassTally += (testResult)? 1 : 0;
	testResultSummary += Convert::ToString(testResult) + " testPowerOfThreeBaseCaseWrong\r\n";

	testResultSummary += "\r\n" + Convert::ToString(testPassTally) + "/" + Convert::ToString(POWER_OF_THREE_TESTS) + " passed.\r\n\r\n";

	return testResultSummary;
}
