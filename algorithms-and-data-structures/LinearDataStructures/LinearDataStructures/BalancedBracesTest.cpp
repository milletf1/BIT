#include "StdAfx.h"
#include "BalancedBracesTest.h"

BalancedBracesTest::BalancedBracesTest(void)
{}
/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class will return false when 
 *				  given a string with an unclosed bracket.
 *********************************************************************************/
bool BalancedBracesTest::unclosedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{";
	bool expected = false;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.  
 *
 * Postcondition: Determines if the balanced braces class will return false when
 *				  the first curly brace in a given string is a closing bracket.
 *********************************************************************************/
bool BalancedBracesTest::startOpenBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "}";
	bool expected = false;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.  
 *
 * Postcondition: Determines if the balanced braces class will return true when 
 *				  given an empty string.
 *********************************************************************************/
bool BalancedBracesTest::emptyStringTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "";
	bool expected = true;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class will return true when 
 *				  given balanced braces.
 *********************************************************************************/
bool BalancedBracesTest::closedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{}";
	bool expected = true;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class will return true when
 *				  given a string that contains balanced braces that contain other
 *				  chars.
 *********************************************************************************/
bool BalancedBracesTest::charWithinClosedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{ }";
	bool expected = true;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}
/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.  
 *
 * Postcondition: Determines if the balanced braces class will return true when
 *				  given a string that contains balanced braces that are surrounded
 *				  by other chars.
 *********************************************************************************/
bool BalancedBracesTest::charOutsideClosedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = " {} ";
	bool expected = true;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class will return true when 
 *                balanced braces  are surrounded by balanced braces.
 *********************************************************************************/
bool BalancedBracesTest::closedBraceInsideClosedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{{}}";
	bool expected = true;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.  
 *
 * Postcondition: Determines if the balanced braces class will return true when 
 *				  given a string that contains multiple instances of balanced braces.
 ************************************************************************************/
bool BalancedBracesTest::closedBraceBesideClosedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{}{}";
	bool expected = true;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class will return false when
 *			      given an unclosed brace before closed braces.
 *********************************************************************************/
bool BalancedBracesTest::unclosedBraceBeforeClosedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{{}";
	bool expected = false;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class will return false when
 *			      given an unclosed brace after closed braces.
 *********************************************************************************/
bool BalancedBracesTest::closedBraceBeforeUnclosedBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{}{";
	bool expected = false;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class will return false when
 *			      given a closing brace after closed braces.
 *********************************************************************************/
bool BalancedBracesTest::closedBraceBeforeOpenBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "{}}";
	bool expected = false;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 

}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the balanced braces class can handle chars other than
 *				  braces.  
 ************************************************************************************/
bool BalancedBracesTest::allCharsNoBraceTest()
{
	BalancedBraces^ bb = gcnew BalancedBraces();
	String^ s = "`~1234567890-=!@#$%^&*()_+qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM[]\\|;':\",./<>?";
	bool expected = true;
	bool actual;

	actual = bb->isBalanced(s);

	return expected == actual; 
}

/**************************************************************************************
 * Precondition:  
 *
 * Postcondition: Runs every test in this class.  Returns a string containing the name
 *				  of the class being tested, each test name and whether if it passed,
 *                and the total number of tests completed that passed.
 *************************************************************************************/
String^ BalancedBracesTest::performTest()
{
	String^ s = "\r\n\r\nBalancedBraces Test\r\n\r\n";
	int passedTests = 0;
	bool testingBool;

	//Perform all of the tests in this class	
	testingBool =  unclosedBraceTest();
	s += Convert::ToString(testingBool) + " unclosedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  startOpenBraceTest();
	s += Convert::ToString(testingBool) + " startOpenBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  emptyStringTest();
	s += Convert::ToString(testingBool) + " emptyStringTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  closedBraceTest();
	s += Convert::ToString(testingBool) + " closedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  charWithinClosedBraceTest();
	s += Convert::ToString(testingBool) + " charWithinClosedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  charOutsideClosedBraceTest();
	s += Convert::ToString(testingBool) + " charOutsideClosedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  closedBraceInsideClosedBraceTest();
	s += Convert::ToString(testingBool) + " closedBraceInsideClosedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  closedBraceBesideClosedBraceTest();
	s += Convert::ToString(testingBool) + " closedBraceBesideClosedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  unclosedBraceBeforeClosedBraceTest();
	s += Convert::ToString(testingBool) + " unclosedBraceBeforeClosedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  closedBraceBeforeUnclosedBraceTest();
	s += Convert::ToString(testingBool) + " closedBraceBeforeUnclosedBraceTest\r\n";
	if(testingBool) passedTests++;
	
	testingBool =  closedBraceBeforeOpenBraceTest();
	s += Convert::ToString(testingBool) + " closedBraceBeforeOpenBraceTest\r\n";
	if(testingBool) passedTests++;
		
	testingBool =  allCharsNoBraceTest();
	s += Convert::ToString(testingBool) + " allCharsNoBraceTest\r\n";
	if(testingBool) passedTests++;

	s += Convert::ToString(passedTests) + "/" + UNITS + " tests passed";
	return s;
}
