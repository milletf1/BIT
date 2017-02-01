#pragma once
#include "IntNode.h"

using namespace System;

ref class IntLinkedList
{
private:
	IntNode^ head;
	IntNode^ tail;

	IntNode^ buildNode(int i);

	IntLinkedList^ quickSort(IntLinkedList^ ll);
public:
	IntLinkedList();

	void push(int i);
	int count();

	array<int>^ getList();

	void sort();

	IntNode^ getHead()			{ return head; }
	void  setHead(IntNode^ n)	{ head = n; }

	IntNode^ getTail()			{ return tail; }
	void setTail(IntNode^ n)	{ tail = n; }
};
