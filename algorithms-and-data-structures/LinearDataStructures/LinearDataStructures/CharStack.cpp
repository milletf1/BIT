#include "StdAfx.h"
#include "CharStack.h"

CharStack::CharStack() : CharLinkedList()
{}

/*******************************************************************************
 * Precondition:  This stack must hold at least one CharNode.
 * Postcondition: Returns the char stored in the last CharNode that was added to 
 *                this stack.  Removes the last CharNode that was added to this 
 *                stack.
 ******************************************************************************/
Char CharStack::pop() 
{	
	CharNode^ cur = head;
	CharNode^ returnNode = tail;
	
	//Check if the linked list contains 1 node.	
	if(head->Next == nullptr)
	{
		//If it does, set head and tail to null.
		head = nullptr;
		tail = nullptr;
	}
	else
	{		
		//Otherwise, set tail to the CharNode pointing to tail.
		while(cur->Next != returnNode)
		{
			cur = cur->Next;
		}
		cur->Next = nullptr;
		tail = cur;
	}
	
	return returnNode->getMyChar();
}

/******************************************************************************
 * Precondition:  This stack must hold at least one CharNode.
 * Postcondition: Returns the int stored in the last CharNode that was added to 
 *                this stack. 
 *****************************************************************************/
Char CharStack::peek() 
{
	return tail->getMyChar();
}
