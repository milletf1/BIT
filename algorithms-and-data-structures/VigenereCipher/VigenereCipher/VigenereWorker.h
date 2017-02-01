#pragma once

#define MOD_CONST 26
#define CHAR_INCREMENT 65
#define CHAR_A 65
#define CHAR_Z 90

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class VigenereWorker
{
private:
	String^ key;	
	Char getChar(int n);

	/*********************************************************************	 
	 * Precondition:  The consumer needs to get an integer by performing a 
	 *			      calculation on a message char and key char.
	 *
     * Postcondition: Returns the integer result of the calculation.
     ********************************************************************/
	delegate int getModNumber(Char c, Char k);

	/***************************************************************	 
	 * Precondition:  The consumer needs to get an integer by adding 
	 *			      a message char to a key char.  
	 *
     * Postcondition: Returns the integer result of adding the 
	 *				  integer value of char c and char k.
     **************************************************************/
	int performAddition(Char c, Char k)
	{ return((int)c - CHAR_INCREMENT)  + ((int)k - CHAR_INCREMENT); }

	/********************************************************************
	 * Precondition:  The consumer needs to get an integer by subtracting 
	 *			      a key char from a message char.  
	 *
     * Postcondition: Returns the integer result of subtracting the 
	 *				  integer value of char k from char c. 
     *******************************************************************/
	int  performSubtraction(Char c, Char k) 
	{ return((int)c - CHAR_INCREMENT)  - ((int)k - CHAR_INCREMENT); }	

public:
	VigenereWorker(String^ newKey);
	
	String^ encrpyt(String^ s);
	String^ decrypt(String^ s);

	/**********************
	 * Getters and setters.
	 *********************/
	void setKey(String^ s) { key = s; } 
	String^ getKey() { return key; }
};
