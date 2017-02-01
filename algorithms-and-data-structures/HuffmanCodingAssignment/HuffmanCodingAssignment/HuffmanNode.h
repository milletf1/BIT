#pragma once

using namespace System;

ref class HuffmanNode : public IComparable
{
private:
	
public:
	String^ symbols;
	int frequency;

	HuffmanNode^ LeftNode;
	HuffmanNode^ RightNode;
	HuffmanNode();

	String^ getSymbols()		{ return symbols; }
	void setSymbols(String^ s)	{ symbols = s; }

	int getFrequency()			{ return frequency; }
	void setFrequency(int i)	{ frequency = i; }

	virtual int CompareTo (Object^ o);
};
