#include "StdAfx.h"
#include "BalancedBraces.h"

BalancedBraces::BalancedBraces()
{}

/***************************************************************************
 * Precondition:  The function caller must want to know if a string contains 
 *				  balanced braces. This string must be given as a parameter.
 *
 * Postcondition: Checks if the string parameter s contains balanced braces.  
 *				  Balanced braces are defined as curly brackets that are 
 *				  closed (each { has a closing }).  Returns true if balanced.
 ***************************************************************************/
bool BalancedBraces::isBalanced(String^ s)
{
	CharStack^ charStack = gcnew CharStack();
	//Return boolean.
	bool balanced = false;
	
	//The computation is contained within a try catch block to handle instances
	//when the stack attempts to pop when empty.
	try
	{
		//Iterate through each char in the given string.
		for each(Char c in s->ToCharArray())
		{
			//Check if the given char is an open brace.
			if(c == OPEN_BRACE)
			{
				//If the given char is an open brace, push it to the stack.
				charStack->push(PUSH_CHAR);
			}
			//Check if the given char is a closed brace.
			else if(c == CLOSE_BRACE)
			{
				//If the given char is a closed brace, push it to the stack.
				charStack->pop();
			}
		}
		//Check if the stack's empty once all the chars have been checked.
		if(charStack->isEmpty())
		{
			//If the stack's empty, the string is balanced.
			balanced = true;
		}
	}
	catch(NullReferenceException^ e){}

	return balanced;
}