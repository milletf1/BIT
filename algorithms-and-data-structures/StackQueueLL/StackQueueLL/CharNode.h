#pragma once
using namespace System;
ref class CharNode
{
private:
	Char myChar;
	
public:
	CharNode^ Next;

	CharNode(Char c);
	Char getMyChar() { return myChar; }
};
