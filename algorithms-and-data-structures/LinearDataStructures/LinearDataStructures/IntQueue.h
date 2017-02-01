#pragma once
#include "intlinkedlist.h"

ref class IntQueue :
public IntLinkedList
{
public:
	IntQueue();	
	virtual int pop() override;
	virtual int peek() override;	
};
