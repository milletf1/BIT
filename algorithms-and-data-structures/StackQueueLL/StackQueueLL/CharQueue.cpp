#include "StdAfx.h"
#include "CharQueue.h"

CharQueue::CharQueue() : CharLinkedList()
{}

/******************************************************************************
 * Precondition:  This stack must hold at least one CharNode.
 * Postcondition: Returns the char stored in the first CharNode that was added to 
 *                this stack.  Removes the first CharNode that was added to this 
 *                stack.
 *****************************************************************************/
Char CharQueue::pop() 
{	
	CharNode^ returnNode = head;
	head = head->Next;

	return returnNode->getMyChar();
}

/******************************************************************************
 * Precondition:  This stack must hold at least one CharNode.
 * Postcondition: Returns the char stored in the first CharNode that was added to 
 *                this stack. 
 *****************************************************************************/
Char CharQueue::peek() 
{
	return head->getMyChar();
}

