#pragma once
#include "CharNode.h"
using namespace System;
ref class CharLinkedList abstract
{
protected: 
	CharNode^ head;
	CharNode^ tail;

	CharNode^ buildNode(Char c);
public:
	CharLinkedList();

	void push(Char i);
	int count();

	virtual Char pop() abstract;
	virtual Char peek() abstract;
	virtual String^ ToString() override;
	/***************************************************************
	 * Precondition:  The caller needs to know if this linked list
	 *                contains any char values.
	 * Postcondition: Returns a boolean value that indicates whether
	 *				  this list contains any char values.
	 **************************************************************/
	bool isEmpty() { return head == nullptr; }
};
