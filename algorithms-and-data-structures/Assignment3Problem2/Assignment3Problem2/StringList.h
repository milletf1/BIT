#pragma once
#include "StringNode.h"

ref class StringList
{
private:
	StringNode^ head;
	StringNode^ tail;

	void recurseList(StringNode^ n);
public:
	StringList();
	
	void push(String^ value);
	void remove(String^ value);
	int count();
	bool contains(String^ value);

	void reverse();
	array<String^>^ getList();		

	bool isEmpty() { return head == nullptr; }
};
