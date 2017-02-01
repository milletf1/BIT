#pragma once

using namespace System;

ref class StringNode
{
private:
	String^ value;
public:
	StringNode^ Next;
	
	StringNode();
	StringNode(String^ nodeValue);

	// Node value gets/sets. 
	void setValue(String^ nodeValue)	{ value = nodeValue; }
	String^ getValue()					{ return value; }
};
