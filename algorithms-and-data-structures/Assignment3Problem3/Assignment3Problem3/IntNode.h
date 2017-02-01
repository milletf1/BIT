#pragma once
using namespace System;
ref class IntNode
{
private:
	int myInt;	
public:
	IntNode^ Next;

	IntNode(int i);
	int getMyInt() { return myInt; }
};
