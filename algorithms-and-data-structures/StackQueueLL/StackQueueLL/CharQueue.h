#pragma once
#include "charlinkedlist.h"

ref class CharQueue :
public CharLinkedList
{
public:
	CharQueue();

	virtual Char pop() override;
	virtual Char peek() override;	
};
