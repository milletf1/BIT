#pragma once
#include "IntNode.h"
using namespace System;
ref class IntLinkedList abstract
{
protected: 
	IntNode^ head;
	IntNode^ tail;

	IntNode^ buildNode(int i);
public:
	IntLinkedList();

	void push(int i);
	int count();

	virtual int pop() abstract;
	virtual int peek() abstract;
	virtual String^ ToString() override;
	/***************************************************************
	 * Precondition:  The caller needs to know if this linked list 
     *                contains any int values.
	 * Postcondition: Returns a boolean value that indicates whether
	 *				  this list contains any int values.
	 **************************************************************/
	bool isEmpty() { return head == nullptr; }
};
