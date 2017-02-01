#include "StdAfx.h"
#include "PalindromeTest.h"

PalindromeTest::PalindromeTest(void)
{}

/**************************************************************************************
 * Precondition:  
 *
 * Postcondition: Runs every test in this class.  Returns a string containing the name
 *				  of the class being tested, each test name and whether it passed, and 
 *                the total number of tests completed that passed.
 *************************************************************************************/
String^ PalindromeTest::performTest()
{
	String^ s = "\r\n\r\nPalindrome Test\r\n\r\n";
	int passedTests = 0;
	bool testingBool;

	//Perform all of the tests in this class	
	testingBool =  emptyStringTest();
	s += Convert::ToString(testingBool) + " emptyStringTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  evenUnbalancedTest();
	s += Convert::ToString(testingBool) + " evenUnbalancedTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  evenBalancedTest();
	s += Convert::ToString(testingBool) + " evenBalancedTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  oddUnbalancedTest();
	s += Convert::ToString(testingBool) + " oddUnbalancedTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  oddBalancedTest();
	s += Convert::ToString(testingBool) + " oddBalancedTest\r\n";
	if(testingBool) passedTests++;
	s += Convert::ToString(passedTests) + "/" + UNITS + " tests passed";
	return s;
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the palindrome class will return true when given an
 *				  empty string.  
 ************************************************************************************/
bool PalindromeTest::emptyStringTest()
{ 
	Palindrome^ p = gcnew Palindrome();
	bool expected = true;
	bool actual;

	actual = p->evaluate("");

	return expected == actual; 
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the palindrome class will return false when given a
 *                unbalanced string with an even number of chars.  
 ************************************************************************************/
bool PalindromeTest::evenUnbalancedTest()
{ 
	Palindrome^ p = gcnew Palindrome();
	bool expected = false;
	bool actual;

	actual = p->evaluate("abccbb");

	return expected == actual; 
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the palindrome class will return true when given a 
 *                balanced string with an even number of chars.  
 ************************************************************************************/
bool PalindromeTest::evenBalancedTest()
{ 
	Palindrome^ p = gcnew Palindrome();
	bool expected = true;
	bool actual;

	actual = p->evaluate("abccba");

	return expected == actual; 
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the palindrome class will return false when given an 
 *				  unbalanced string with an uneven number of chars.  
 ************************************************************************************/
bool PalindromeTest::oddUnbalancedTest()
{ 
	Palindrome^ p = gcnew Palindrome();
	bool expected = false;
	bool actual;

	actual = p->evaluate("abcaa");

	return expected == actual;
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the palindrome class will return true when given a
 *                balanced string with an uneven number of chars.  
 ************************************************************************************/
bool PalindromeTest::oddBalancedTest()
{ 
	Palindrome^ p = gcnew Palindrome();
	bool expected = true;
	bool actual;

	actual = p->evaluate("abcba");

	return expected == actual;
}