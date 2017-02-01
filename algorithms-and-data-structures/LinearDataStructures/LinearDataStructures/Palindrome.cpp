#include "StdAfx.h"
#include "Palindrome.h"

Palindrome::Palindrome()
{}

/*******************************************************************
 * Precondition:  The function caller must want to know if a string
 *				  is a Palindrome(symmetrical).	This string must be
 *				  given as a parameter.
 *
 * Postcondition: This function will determine if the given string
 *				  is a Palindrome.  Returns true if it is, otherwise 
 *				  returns false.
 ******************************************************************/
bool Palindrome::evaluate(String^ s)
{
	Char queueChar;
	Char stackChar;
	
	CharQueue^ charQueue = gcnew CharQueue();
	CharStack^ charStack = gcnew CharStack();
	
	//Return boolean
	bool b = true;
	
	//Push each char in the given string to the char queue and stack.
	for each(Char c in s->ToCharArray())
	{
		charQueue->push(c);
		charStack->push(c);
	}
	
	//This while loop runs until the return boolean is false or the
	//char queue or stack are emtpy.
	while(!charQueue->isEmpty() && !charStack->isEmpty() && b)
	{
		//Pop a char from the queue and stack.
		queueChar = charQueue->pop();
		stackChar = charStack->pop();
		
		//Check if the popped chars are equal.
		b = queueChar == stackChar;
	}	
	return b;
}
