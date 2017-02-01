#pragma once
#include "IntStack.h"
#include "IntQueue.h"
#include "CharStack.h"
#include "CharQueue.h"
#define UNITS 48
using namespace System;
ref class Testing
{
private:

	//IntLinkedList tests
	bool performIntLinkedListPushTest();
	bool performIntLinkedListCountTest();
	bool performIntLinkedListIsEmptyTrueTest();
	bool performIntLinkedListIsEmptyFalseTest();
	
	//IntQueue tests
	bool performIntQueuePeekEmptyTest();
	bool performIntQueuePeekOneTest();
	bool performIntQueuePeekManyTest();
	bool performIntQueuePeekAfterPopTest();	
	bool performIntQueueCountAfterPeekTest();	
	bool performIntQueuePopEmptyTest();
	bool performIntQueuePopOneTest();
	bool performIntQueuePopManyTest();
	bool performIntQueuePopAfterPeekTest();
	bool performIntQueueCountAfterPopTest();
	
	//IntStack tests	
	bool performIntStackPeekEmptyTest();
	bool performIntStackPeekOneTest();
	bool performIntStackPeekManyTest();
	bool performIntStackPeekAfterPopTest();	
	bool performIntStackCountAfterPeekTest();	
	bool performIntStackPopEmptyTest();
	bool performIntStackPopOneTest();
	bool performIntStackPopManyTest();
	bool performIntStackPopAfterPeekTest();
	bool performIntStackCountAfterPopTest();
	
	//CharLinkedList tests
	bool performCharLinkedListPushTest();
	bool performCharLinkedListCountTest();
	bool performCharLinkedListIsEmptyTrueTest();
	bool performCharLinkedListIsEmptyFalseTest();
	
	//CharQueue tests
	bool performCharQueuePeekEmptyTest();
	bool performCharQueuePeekOneTest();
	bool performCharQueuePeekManyTest();
	bool performCharQueuePeekAfterPopTest();
	bool performCharQueueCountAfterPeekTest();	
	bool performCharQueuePopEmptyTest();
	bool performCharQueuePopOneTest();
	bool performCharQueuePopManyTest();
	bool performCharQueuePopAfterPeekTest();
	bool performCharQueueCountAfterPopTest();
	
	//CharStack tests
	bool performCharStackPeekEmptyTest();
	bool performCharStackPeekOneTest();
	bool performCharStackPeekManyTest();
	bool performCharStackPeekAfterPopTest();
	bool performCharStackCountAfterPeekTest();
	bool performCharStackPopEmptyTest();
	bool performCharStackPopOneTest();
	bool performCharStackPopManyTest();
	bool performCharStackPopAfterPeekTest();
	bool performCharStackCountAfterPopTest();
public:
	Testing();
	String^ performTest();
};
