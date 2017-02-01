#include "StdAfx.h"
#include "PostFixExpressionParserTest.h"

PostFixExpressionParserTest::PostFixExpressionParserTest()
{}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser class will throw an
 *				  invalid operation exception when it attempts to evaluate an empty 
 *				  string.  Returns true if successful.	
 *********************************************************************************/
bool PostFixExpressionParserTest::emptyStringTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	bool actual = false;
	bool expected = true;

	try
	{
		parser->evaluate(String::Empty);
	}
	catch(InvalidOperationException^ e)
	{
		actual = true;
	}

	return expected == actual; 
}

/***********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser class will return the
 *				  correct answer when give a string that contains no operators and
 *                one integer.  It is expected to return the given int as an answer.
 *				  This function returns true on success.	
 **********************************************************************************/
bool PostFixExpressionParserTest::noOperatorOneIntTest()
{ 
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	int expected = 0;
	int actual;

	actual = parser->evaluate("0");
	
	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser class will throw an
 *				  invalid operation exception when it attempts to evaluate a string 
 *				  containing multipe numbers with an operator.  Returns true if 
 *                successful.	
 *********************************************************************************/
bool PostFixExpressionParserTest::noOperatorManyIntTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	bool actual = false;
	bool expected = true;

	try
	{
		parser->evaluate("1234");
	}
	catch(InvalidOperationException^ e)
	{
		actual = true;
	}

	return expected == actual;
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser class will throw a
 *                null reference exception when given a string that contains only
 *				  one operator.  Returns true if successful.	
 *********************************************************************************/
bool PostFixExpressionParserTest::noIntOneOperatorTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	bool actual = false;
	bool expected = true;

	try
	{
		parser->evaluate("+");
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}

	return expected == actual;
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser returns true when given
 *                a postfix expression to multiply.  Returns true if successful.
 ************************************************************************************/
bool PostFixExpressionParserTest::multiplicationTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	int expected = 6;
	int actual;

	actual = parser->evaluate("23*");
	
	return expected == actual;
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser returns true when given
 *                a postfix expression to add.  Returns true if successful.
 ************************************************************************************/
bool PostFixExpressionParserTest::additionTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	int expected = 5;
	int actual;

	actual = parser->evaluate("23+");
	
	return expected == actual;
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser returns true when given
 *                a postfix expression with multiplication and addition.  Returns true 
 *				  if successful.
 ************************************************************************************/
bool PostFixExpressionParserTest::manyOperatorTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	int expected = 14;
	int actual;

	actual = parser->evaluate("234*+");
	
	return expected == actual; 
}

/**********************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser returns an invalid 
 *				  operation exception when there are two or more int's left on the 
 *                stack when the postfix expression has been calculated.  Returns
 *                true if successful.
 **********************************************************************************/
bool PostFixExpressionParserTest::threeIntOneOperatorTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	bool actual = false;
	bool expected = true;

	try
	{
		parser->evaluate("1234+");
	}
	catch(InvalidOperationException^ e)
	{
		actual = true;
	}

	return expected == actual; 
}

/*************************************************************************************
 * Precondition:  The user must have called the performTest function in this class.
 *
 * Postcondition: Determines if the postfix expression parser returns a null reference
 *                exception when given a string that contains one int and one operator.  
 *				  Returns true if successful.	
 *************************************************************************************/
bool PostFixExpressionParserTest::oneIntOneOperatorTest()
{
	PostfixExpressionParser^ parser = gcnew PostfixExpressionParser();
	bool actual = false;
	bool expected = true;

	try
	{
		parser->evaluate("1+");
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}

	return expected == actual; 
}

/**************************************************************************************
 * Precondition:  
 *
 * Postcondition: Runs every test in this class.  Returns a string containing the name
 *				  of the class being tested, each test name and whether if it passed,
 *                and the total number of tests completed that passed.
 ************************************************************************************/
String^ PostFixExpressionParserTest::performTest()
{
	String^ s = "\r\n\r\nPostfixExpressionParser Test\r\n\r\n";
	int passedTests = 0;
	bool testingBool;

	//Perform all of the tests in this class	
	testingBool =  emptyStringTest();
	s += Convert::ToString(testingBool) + " emptyStringTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  noOperatorOneIntTest();
	s += Convert::ToString(testingBool) + " noOperatorOneIntTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  noOperatorManyIntTest();
	s += Convert::ToString(testingBool) + " noOperatorManyIntTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  noIntOneOperatorTest();
	s += Convert::ToString(testingBool) + " noIntOneOperatorTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  multiplicationTest();
	s += Convert::ToString(testingBool) + " multiplicationTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  additionTest();
	s += Convert::ToString(testingBool) + " additionTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  manyOperatorTest();
	s += Convert::ToString(testingBool) + " manyOperatorTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  threeIntOneOperatorTest();
	s += Convert::ToString(testingBool) + " threeIntOneOperatorTest\r\n";
	if(testingBool) passedTests++;

	testingBool =  oneIntOneOperatorTest();
	s += Convert::ToString(testingBool) + " oneIntOneOperatorTest\r\n";
	if(testingBool) passedTests++;

	s += Convert::ToString(passedTests) + "/" + UNITS + " tests passed";

	return s;
}