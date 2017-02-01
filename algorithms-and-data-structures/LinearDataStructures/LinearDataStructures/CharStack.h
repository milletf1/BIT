#pragma once
#include "charlinkedlist.h"

ref class CharStack :
public CharLinkedList
{
public:
	CharStack();

	virtual Char pop() override;
	virtual Char peek() override;

};
