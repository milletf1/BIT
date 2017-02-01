#include "StdAfx.h"
#include "Testing.h"

Testing::Testing()
{}

//performs ze test!
String^ Testing::performTest()
{ 
	String^ s = "";
	int passedTests = 0;
	bool testingBool;

	//Perform all of the tests in this class	
	testingBool =  performIntLinkedListPushTest();
	s += Convert::ToString(testingBool) + " performIntLinkedListPushTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntLinkedListCountTest();
	s += Convert::ToString(testingBool) + " performIntLinkedListCountTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntLinkedListIsEmptyTrueTest();
	s += Convert::ToString(testingBool) + " performIntLinkedListIsEmptyTrueTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntLinkedListIsEmptyFalseTest();	
	s += Convert::ToString(testingBool) + " performIntLinkedListIsEmptyFalseTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePeekEmptyTest();
	s += Convert::ToString(testingBool) + " performIntQueuePeekEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePeekOneTest();
	s += Convert::ToString(testingBool) + " performIntQueuePeekOneTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePeekManyTest();
	s += Convert::ToString(testingBool) + " performIntQueuePeekManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePeekAfterPopTest();	
	s += Convert::ToString(testingBool) + " performIntQueuePeekAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueueCountAfterPeekTest();	
	s += Convert::ToString(testingBool) + " performIntQueueCountAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePopEmptyTest();
	s += Convert::ToString(testingBool) + " performIntQueuePopEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePopOneTest();
	s += Convert::ToString(testingBool) + " performIntQueuePopOneTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePopManyTest();
	s += Convert::ToString(testingBool) + " performIntQueuePopManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueuePopAfterPeekTest();
	s += Convert::ToString(testingBool) + " performIntQueuePopAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntQueueCountAfterPopTest();		
	s += Convert::ToString(testingBool) + " performIntQueueCountAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackPeekEmptyTest();
	s += Convert::ToString(testingBool) + " performIntStackPeekEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackPeekOneTest();
	s += Convert::ToString(testingBool) + " performIntStackPeekOneTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackPeekManyTest();
	s += Convert::ToString(testingBool) + " performIntStackPeekManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackPeekAfterPopTest();	
	s += Convert::ToString(testingBool) + " performIntStackPeekAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackCountAfterPeekTest();	
	s += Convert::ToString(testingBool) + " performIntStackCountAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackPopEmptyTest();
	s += Convert::ToString(testingBool) + " performIntStackPopEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackPopOneTest();
	s += Convert::ToString(testingBool) + " performIntStackPopOneTest" + "\r\n";
	if(testingBool) passedTests++;
		
	testingBool =  performIntStackPopManyTest();
	s += Convert::ToString(testingBool) + " performIntStackPopManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackPopAfterPeekTest();
	s += Convert::ToString(testingBool) + " performIntStackPopAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performIntStackCountAfterPopTest();
	s += Convert::ToString(testingBool) + " performIntStackCountAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharLinkedListPushTest();
	s += Convert::ToString(testingBool) + " performCharLinkedListPushTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharLinkedListCountTest();
	s += Convert::ToString(testingBool) + " performCharLinkedListCountTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharLinkedListIsEmptyTrueTest();
	s += Convert::ToString(testingBool) + " performCharLinkedListIsEmptyTrueTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharLinkedListIsEmptyFalseTest();
	s += Convert::ToString(testingBool) + " performCharLinkedListIsEmptyFalseTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePeekEmptyTest();
	s += Convert::ToString(testingBool) + " performCharQueuePeekEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePeekOneTest();
	s += Convert::ToString(testingBool) + " performCharQueuePeekOneTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePeekManyTest();
	s += Convert::ToString(testingBool) + " performCharQueuePeekManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePeekAfterPopTest();
	s += Convert::ToString(testingBool) + " performCharQueuePeekAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueueCountAfterPeekTest();	
	s += Convert::ToString(testingBool) + " performCharQueueCountAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePopEmptyTest();
	s += Convert::ToString(testingBool) + " performCharQueuePopEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePopOneTest();
	s += Convert::ToString(testingBool) + " performCharQueuePopOneTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePopManyTest();
	s += Convert::ToString(testingBool) + " performCharQueuePopManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueuePopAfterPeekTest();
	s += Convert::ToString(testingBool) + " performCharQueuePopAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharQueueCountAfterPopTest();
	s += Convert::ToString(testingBool) + " performCharQueueCountAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPeekEmptyTest();
	s += Convert::ToString(testingBool) + " performCharStackPeekEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPeekOneTest();
	s += Convert::ToString(testingBool) + " performCharStackPeekOneTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPeekManyTest();
	s += Convert::ToString(testingBool) + " performCharStackPeekManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPeekAfterPopTest();
	s += Convert::ToString(testingBool) + " performCharStackPeekAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackCountAfterPeekTest();
	s += Convert::ToString(testingBool) + " performCharStackCountAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPopEmptyTest();
	s += Convert::ToString(testingBool) + " performCharStackPopEmptyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPopOneTest();
	s += Convert::ToString(testingBool) + " performCharStackPopOneTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPopManyTest();
	s += Convert::ToString(testingBool) + " performCharStackPopManyTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackPopAfterPeekTest();
	s += Convert::ToString(testingBool) + " performCharStackPopAfterPeekTest" + "\r\n";
	if(testingBool) passedTests++;

	testingBool =  performCharStackCountAfterPopTest();
	s += Convert::ToString(testingBool) + " performCharStackCountAfterPopTest" + "\r\n";
	if(testingBool) passedTests++;
	
	s += Convert::ToString(passedTests) + "\\" + Convert::ToString(UNITS) + " passed";

	return s;
}

/********************
 *IntLinkedList tests
 *******************/

//Tests that the IntLinkedList class pushes correctly.
bool Testing::performIntLinkedListPushTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	String^ expected = "1\r\n";
	//Act
	intQueue->push(1);
	String^ actual = intQueue->ToString();
	//Assert
	return expected->CompareTo(actual) == 0; 
}

//Tests that the IntLinkedList class returns a count of 
//integers in the list correctly.
bool Testing::performIntLinkedListCountTest()
{
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 1;
	//Act
	intQueue->push(5);
	int actual = intQueue->count();
	//Assert
	return expected == actual; 
}

//Tests that the IntLinkedList class returns true when isEmpty 
//is called on an empty linked list.
bool Testing::performIntLinkedListIsEmptyTrueTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	bool expected = true;
	//Act
	bool actual = intQueue->isEmpty();
	//Assert
	return expected == actual; 
}

//Tests that the IntLinkedList class returns false when isEmpty 
//is called on an empty linked list.
bool Testing::performIntLinkedListIsEmptyFalseTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	bool expected = false;
	//Act
	intQueue->push(0);
	bool actual = intQueue->isEmpty();
	//Assert
	return expected == actual;  
}
/***************
 *IntQueue tests
 **************/

//Tests that the IntQueue class throws a NullReferenceException
//when peek is called on an empty queue.
bool Testing::performIntQueuePeekEmptyTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	bool actual = false;
	bool expected = true;
	//Act
	try
	{
		intQueue->peek();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}
	return expected == actual; 
}

//Tests that the IntQueue class returns the correct result
//when peek is called on a queue containing one integer.
bool Testing::performIntQueuePeekOneTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 0;
	//Act
	intQueue->push(0);
	int actual = intQueue->peek();
	//Assert
	return expected == actual; 
}

//Tests that the IntQueue class returns the correct result
//when peek is called on a queue containing many integers.
bool Testing::performIntQueuePeekManyTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 0;
	//Act
	intQueue->push(0);
	intQueue->push(1);
	intQueue->push(2);
	int actual = intQueue->peek();
	//Assert
	return expected == actual; 
}
//Tests that the IntQueue class returns the correct result
//when peek is called after a pop.
bool Testing::performIntQueuePeekAfterPopTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 1;
	//Act
	intQueue->push(0);
	intQueue->push(1);
	intQueue->pop();
	int actual = intQueue->peek();
	//Assert
	return expected == actual;  
}
//Tests that the IntQueue class returns the correct result
//when count is called after a peek.
bool Testing::performIntQueueCountAfterPeekTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 3;
	//Act
	intQueue->push(0);
	intQueue->push(1);
	intQueue->push(2);
	intQueue->peek();
	int actual = intQueue->count();
	//Assert
	return expected == actual; 
}
//Tests that the IntQueue class throws a NullReferenceException when 
//pop is called on an empty queue.
bool Testing::performIntQueuePopEmptyTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	bool actual = false;
	bool expected = true;
	//Act
	try
	{
		intQueue->pop();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}

	return expected == actual; 
}
//Tests that the IntQueue class returns the correct result
//when pop is called on a queue that contains one int.
bool Testing::performIntQueuePopOneTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 0;
	//Act
	intQueue->push(0);
	int actual = intQueue->pop();
	//Assert
	return expected == actual; 
}
//Tests that the IntQueue class returns the correct result 
//when pop is called on a queue that contains many ints.
bool Testing::performIntQueuePopManyTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 0;
	//Act
	intQueue->push(0);
	intQueue->push(1);
	intQueue->push(2);
	int actual = intQueue->pop();
	//Assert
	return expected == actual; 
}
//Tests that the IntQueue class returns the correct result 
//when pop is called after a peek.
bool Testing::performIntQueuePopAfterPeekTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 0;	
	//Act
	intQueue->push(0);
	intQueue->push(1);
	intQueue->push(2);
	intQueue->peek();
	int actual = intQueue->pop();
	//Assert
	return expected == actual; 
}
//Tests that the IntQueue class returns the correct result 
//when count is called after a pop.
bool Testing::performIntQueueCountAfterPopTest()
{ 
	//Arrange
	IntQueue^ intQueue = gcnew IntQueue();
	int expected = 2;	
	//Act
	intQueue->push(0);
	intQueue->push(1);
	intQueue->push(2);
	intQueue->pop();
	int actual = intQueue->count();
	//Assert
	return expected == actual; 
}

/***************
 *IntStack tests
 **************/

//Tests that the IntStack class returns NullReferenceException
//when peek is called on an empty stack.
bool Testing::performIntStackPeekEmptyTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	bool actual = false;
	bool expected = true;
	//Act
	try
	{
		intStack->peek();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}
	//Assert
	return expected == actual; 
}
//Tests that the IntStack class returns the correct result
//when peek is called on a stack that contains one int.
bool Testing::performIntStackPeekOneTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 0;
	//Act
	intStack->push(0);
	int actual = intStack->peek();
	//Assert
	return expected == actual; 
}
//Tests that the IntStack class returns the correct result
//when peek is called on a stack that contains many ints.
bool Testing::performIntStackPeekManyTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 2;
	//Act
	intStack->push(0);
	intStack->push(1);
	intStack->push(2);
	int actual = intStack->peek();
	//Assert
	return expected == actual; 
}
//Tests that the IntStack class returns the correct result
//when a peek is called after a pop.
bool Testing::performIntStackPeekAfterPopTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 1;
	//Act
	intStack->push(0);
	intStack->push(1);
	intStack->push(2);
	intStack->pop();
	int actual = intStack->peek();
	//Assert
	return expected == actual; 
}
//Tests that the IntStack class returns the correct result
//when count is called after a peek.
bool Testing::performIntStackCountAfterPeekTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 1;
	//Act
	intStack->push(0);
	intStack->peek();
	int actual = intStack->count();
	return expected == actual; 
}
//Tests that the IntStack class returns NullReferenceException
//when pop is called on an empty stack.
bool Testing::performIntStackPopEmptyTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	bool actual = false;
	bool expected = true;
	//Act
	try
	{
		intStack->pop();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}
	//Assert
	return expected == actual; 
}
//Tests that the IntStack class returns the correct result
//when pop is called on a stack that contains one int.
bool Testing::performIntStackPopOneTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 0;
	//Act
	intStack->push(0);
	int actual = intStack->pop();
	//Assert
	return  expected == actual; 
}
//Tests that the IntStack class returns the correct result
//when pop is called on a stack that contains many ints.
bool Testing::performIntStackPopManyTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 2;
	//Act
	intStack->push(0);
	intStack->push(1);
	intStack->push(2);
	int actual = intStack->pop();
	//Assert
	return expected == actual; 
}
//Tests that the IntStack class returns the correct result
//When pop is called after a peek.
bool Testing::performIntStackPopAfterPeekTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 0;
	//Act
	intStack->push(0);
	intStack->peek();
	int actual = intStack->pop();
	//Assert
	return expected == actual; 
}
//Tests that the IntStack class returns the correct result
//when count is called after a pop.
bool Testing::performIntStackCountAfterPopTest()
{ 
	//Arrange
	IntStack^ intStack = gcnew IntStack();
	int expected = 2;
	//Act
	intStack->push(0);
	intStack->push(1);
	intStack->push(3);
	intStack->pop();
	int actual = intStack->count();
	//Assert
	return expected == actual; 
}
/*********************
 *CharLinkedList tests
 ********************/
//Tests that the CharLinkedList class pushes correctly.
bool Testing::performCharLinkedListPushTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	String^ expected = "c\r\n";
	//Act
	charQueue->push('c');
	String^ actual = charQueue->ToString();
	//Assert
	return expected->CompareTo(actual) == 0;
}
//Tests that the CharLinkedList class returns a count of 
//chars in the list correctly.
bool Testing::performCharLinkedListCountTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	int expected = 1;
	//Act
	charQueue->push('c');
	int actual = charQueue->count();
	//Assert
	return expected == actual;
}
//Tests that the CharLinkedList class returns the correct result
//when isEmpty is called on a linked list that doesn't contain chars.
bool Testing::performCharLinkedListIsEmptyTrueTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	bool expected = true;
	//Act
	bool actual = charQueue->isEmpty();
	//Assert
	return expected == actual;
}
//Tests that the CharLinkedList class returns the correct result
//when isEmpty is called on a linked list that contains chars.
bool Testing::performCharLinkedListIsEmptyFalseTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	bool expected = false;
	//Act
	charQueue->push('c');
	bool actual = charQueue->isEmpty();
	//Assert
	return expected == actual;
}
/****************
 *CharQueue tests
 ***************/

//Tests that the CharQueue class returns NullReferenceException
//when peek is called on an empty queue.
bool Testing::performCharQueuePeekEmptyTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	int actual = false;
	int expected = true;
	//Act
	try
	{
		charQueue->peek();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}
	//Assert
	return expected == actual; 
}
//Tests that the CharQueue class returns the correct result
//when peek is called on a queue that contains one char.
bool Testing::performCharQueuePeekOneTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	Char expected = 'c';
	//Act
	charQueue->push('c');
	Char actual = charQueue->peek();
	//Assert
	return expected == actual;
}
//Tests that the CharQueue class returns the correct result
//when peek is called on a queue that contains many chars.
bool Testing::performCharQueuePeekManyTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	Char expected = 'a';
	//Act
	charQueue->push('a');
	charQueue->push('b');
	charQueue->push('c');
	Char actual = charQueue->peek();
	//Assert
	return expected == actual; 
}
//Tests that the CharQueue class returns the correct result
//when peek is called after a pop.
bool Testing::performCharQueuePeekAfterPopTest()
{
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	Char expected = 'b';
	//Act
	charQueue->push('a');
	charQueue->push('b');
	charQueue->push('c');
	charQueue->pop();
	Char actual = charQueue->peek();
	//Assert
	return expected == actual;
}
//Tests that the CharQueue class returns the correct result
//when count is called after a peek.
bool Testing::performCharQueueCountAfterPeekTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	int expected = 3;
	//Act
	charQueue->push('a');
	charQueue->push('b');
	charQueue->push('c');
	charQueue->peek();
	int actual = charQueue->count();
	//Assert
	return expected == actual;
}
//Tests that the CharQueue class returns the NullReferenceException
//when pop is called on an empty queue.
bool Testing::performCharQueuePopEmptyTest()
{ 
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	int actual = false;
	int expected = true;
	//Act
	try
	{
		charQueue->pop();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}
	//Assert
	return expected == actual;  
}
//Tests that the CharQueue class returns the correct result
//When pop is called on a queue that contains one char.
bool Testing::performCharQueuePopOneTest()
{
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	Char expected = 'c';
	//Act
	charQueue->push('c');
	Char actual = charQueue->pop();
	//Assert
	return expected == actual; 
}
//Tests that the CharQueue class returns the correct result
//when pop is called on a queue that contains many chars.
bool Testing::performCharQueuePopManyTest()
{
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	Char expected = 'a';
	//Act
	charQueue->push('a');
	charQueue->push('b');
	charQueue->push('c');
	Char actual = charQueue->pop();
	//Assert
	return expected == actual;  
}
//Tests that the CharQueue class returns the correct result
//when pop is called after a peek.
bool Testing::performCharQueuePopAfterPeekTest()
{
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	Char expected = 'a';
	//Act
	charQueue->push('a');
	charQueue->push('b');
	charQueue->push('c');
	charQueue->peek();
	Char actual = charQueue->pop();
	//Assert
	return expected == actual; 
}
//Tests that the CharQueue class returns the correct result
//when count is called after a pop.
bool Testing::performCharQueueCountAfterPopTest()
{
	//Arrange
	CharQueue^ charQueue = gcnew CharQueue();
	int expected = 0;
	//Act
	charQueue->push('1');
	charQueue->pop();
	int actual = charQueue->count();
	//Assert
	return expected == actual; 
}

/****************
 *CharStack tests
 ***************/
//Tests that the CharStack class returns NullReferenceException
//when peek is called on an empty stack
bool Testing::performCharStackPeekEmptyTest()
{
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	bool actual = false;
	bool expected = true;
	//Act
	try
	{
		charStack->peek();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}
	//Assert
	return expected == actual; 
}
//Tests that the CharStack class returns the correct result
//when peek is called on a stack that contains one char.
bool Testing::performCharStackPeekOneTest()
{
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	Char expected = 'a';
	//Act
	charStack->push('a');
	Char actual = charStack->peek();
	//Assert
	return expected == actual; 
}
//Tests that the CharStack class returns the correct result
//when peek is called on a stack that contains many chars.
bool Testing::performCharStackPeekManyTest()
{
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	Char expected = 'c';
	//Act
	charStack->push('a');
	charStack->push('b');
	charStack->push('c');
	Char actual = charStack->peek();
	//Assert
	return expected == actual;
}
//Tests that the CharStack class returns the correct result
//when peek is called after a pop.
bool Testing::performCharStackPeekAfterPopTest()
{
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	Char expected = 'b';
	//Act
	charStack->push('a');
	charStack->push('b');
	charStack->push('c');
	charStack->pop();
	Char actual = charStack->peek();
	//Assert
	return expected == actual; 
}
//Tests that the CharStack class returns the correct result
//when count is called after a peek.
bool Testing::performCharStackCountAfterPeekTest()
{
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	int expected = 1;
	//Act
	charStack->push('z');
	charStack->peek();
	int actual = charStack->count();
	//Assert
	return expected == actual; 
}
//Tests that the CharStack class returns NullReferenceException
//when pop is called on an empty stack.
bool Testing::performCharStackPopEmptyTest()
{ 
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	bool actual = false;
	bool expected = true;
	//Act
	try
	{
		charStack->pop();
	}
	catch(NullReferenceException^ e)
	{
		actual = true;
	}
	//Assert
	return  expected == actual;
}

//Tests that the CharStack class returns the correct result
//when pop is called on a stack that contains one char.
bool Testing::performCharStackPopOneTest()
{
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	Char expected = 'a';
	//Act
	charStack->push('a');
	Char actual = charStack->pop();
	//Assert
	return expected == actual; 
}
//Tests that the CharStack class returns the correct result
//when pop is called on a stack that contains many chars.
bool Testing::performCharStackPopManyTest()
{ 
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	Char expected = 'c';
	//Act
	charStack->push('a');
	charStack->push('b');
	charStack->push('c');
	Char actual = charStack->pop();
	//Assert
	return expected == actual;  
}
//Tests that the CharStack class returns the correct result
//when pop is called after a peek.
bool Testing::performCharStackPopAfterPeekTest()
{ 
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	Char expected = 'b';
	//Act
	charStack->push('a');
	charStack->push('b');
	charStack->peek();
	Char actual = charStack->pop();
	//Assert
	return expected == actual;
}
//Tests that the CharStack class returns the correct result
//when count is called after a pop.
bool Testing::performCharStackCountAfterPopTest()
{
	//Arrange
	CharStack^ charStack = gcnew CharStack();
	int expected = 0;
	//Act
	charStack->push('1');
	charStack->pop();
	int actual = charStack->count();
	//Assert
	return expected == actual; 
}




