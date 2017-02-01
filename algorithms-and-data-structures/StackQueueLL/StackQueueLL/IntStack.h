#pragma once
#include "intlinkedlist.h"

ref class IntStack :
public IntLinkedList
{
public:
	IntStack();

	virtual int pop() override;
	virtual int peek() override;
};
