#include "StdAfx.h"
#include "PostfixExpressionParser.h"

PostfixExpressionParser::PostfixExpressionParser()
{}

/****************************************************************************
 * Precondition:  The string parameter s must be a valid postfix expression  
 *                that will return exactly 1 integer.  The first instance of  
 *                a operator must be placed after at least 2 integers.
 *
 * Postcondition: This function will calculate and return a valid postfix  
 *				  expression.				 	               
 ***************************************************************************/
int PostfixExpressionParser::evaluate(String^ s)
{
	IntStack^ intStack = gcnew IntStack();
	
	//Return integer
	int result;
	
	//Regular expressions used to determine if the current char
	//is an integer or operator.
	Regex^ intRegex = gcnew Regex(INT_REGEX);
	Regex^ operatorRegex = gcnew Regex(OPERATOR_REGEX);

	//Iterate through each char in the given string.
	for each(Char c in s->ToCharArray())
	{
		String^ s = Convert::ToString(c);		
		Match^ intResult = intRegex->Match(s);
		Match^ operatorResult = operatorRegex->Match(s);
		
		//Check if the char is an integer.
		if(intResult->Success)
		{
			//Convert to integer and add to the stack if it is.
			intStack->push(Convert::ToInt16(s));
		}
		//Check if the char is an operator.
		else if(operatorResult->Success)
		{
			//Check if the stack has contains 2 or more integers.
			if(intStack->count() >= 2)
			{
				int a = intStack->pop();
				int b = intStack->pop();
				int answer;
				//If the char is an operator, perform operation.
				switch(c)
				{
				case '+':
					answer = a + b;
					intStack->push(answer);
					break;

				case '*':
					answer = a * b;
					intStack->push(answer);
					break;
				default: 
					break;
				}
			}
			//If the stack contains less than 2 integers, throw a null reference exception.
			else
			{
				throw gcnew NullReferenceException("Pop from empty stack.");
			}
		}
	}
	//Check if the intStack performed an invald calculation.
	(intStack->count() == 1)? 
		//If it did, return it.If not, throw an invalid operation exception.
		result = intStack->pop() : throw gcnew InvalidOperationException("Invalid expression.");

	return result;
}
