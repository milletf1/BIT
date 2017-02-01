#include "StdAfx.h"
#include "VigenereWorker.h"

VigenereWorker::VigenereWorker(String^ newKey)
{
	key = newKey->ToUpper();
}

/****************************************************************************************
 * Precondition: The consumer needs to encrypt a string using a vigenere cipher.  The key
 *               that they wish to encrypt the string with must match this classes key 
 *				 attribute.
 *
 * Postcondition: Encrypts the given string and returns it.
 ***************************************************************************************/
String^ VigenereWorker::encrpyt(String^ s)
{	
	s = s->ToUpper();
	array<Char>^ message = s->ToCharArray();	
	String^ rString = "";

	//Create a getModNumber delegate to add key chars to message chars.
	getModNumber^ add = gcnew getModNumber(this, &VigenereWorker::performAddition);
	
	//counter is used to iterate through the key chars.
	int counter = 0;
	
	for each(Char c in message)
	{
		//check that char c is an alphabet char.
		if((int)c >= CHAR_A && (int)c <= CHAR_Z)
		{
			//Encrypt the current char.
			int n = add(c, key[counter]);
			Char newChar = getChar(n);

			//Add the new char to the return string.
			rString = rString + newChar;

			//Increment the key char counter.
			counter = (counter + 1) % key->Length; 
		}
		else
		{
			//If the current char is not in the alphabet, add it to the message unencrypted.
			rString = rString + c;
		}
	}	
	return rString;
}

/****************************************************************************************
 * Precondition: The consumer needs to decrypt a string using a vigenere cipher.  The key
 *               to decrypt the string must match this classes key attribute.
 *
 * Postcondition: Decrypts the given string and returns it.
 ***************************************************************************************/
String^ VigenereWorker::decrypt(String^ s)
{
	s = s->ToUpper();
	array<Char>^ message = s->ToCharArray();
	String^ rString = "";

	//Create a getModNumber delegate to subtract key chars from message chars.
	getModNumber^ subtract = gcnew getModNumber(this, &VigenereWorker::performSubtraction);

	//counter is used to iterate through the key chars.
	int counter = 0;

	for each(Char c in message)
	{
		//check that char c is an alphabet char.
		if((int)c >= CHAR_A && (int)c <= CHAR_Z)
		{
			//Decrypt the current char.
			int n = subtract(c, key[counter]);
			Char newChar = getChar(n);
			
			//Add the new char to the return string.
			rString = rString + newChar;
			
			//Increment the key char counter.
			counter = (counter + 1) % key->Length; 
		}
		else
		{
			//If the current char is not in the alphabet, add it to the message unencrypted.
			rString = rString + c;
		}
	}	
	return rString;
}

/************************************************************************************** 
 * Precondition:  The consumer needs to get a char between A - Z from an integer 
 *				  after the integer has had a modulo operation applied to it to so that 
 *                it is between 0 - 26.
 *
 * Postcondition: Performs a modulo operation on the given integer and returns its char 
 *                representation.
 *************************************************************************************/
Char VigenereWorker::getChar(int n)
{
	//m represents the integer that dictates the position of the char to return.
	int m; 

	//r is the return char.
	Char r;
	
	//Perform a modulo operation on the given integer.
	(n < 0)? m = n + MOD_CONST : m = n % MOD_CONST;
	
	//Cast the result of the modulo operation as char between A - Z.
	r = static_cast<char>(m + CHAR_INCREMENT);

	return r;
}