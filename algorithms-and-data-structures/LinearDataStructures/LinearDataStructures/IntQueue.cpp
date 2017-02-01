#include "StdAfx.h"
#include "IntQueue.h"

IntQueue::IntQueue() : IntLinkedList()
{}

/******************************************************************************
 * Precondition:  This stack must hold at least one IntNode.
 * Postcondition: Returns the int stored in the first IntNode that was added to 
 *                this stack.  Removes the first IntNode that was added to this 
 *                stack.
 *****************************************************************************/
int IntQueue::pop() 
{	
	IntNode^ returnNode = head;
	head = head->Next;

	return returnNode->getMyInt();
}

/******************************************************************************
 * Precondition:  This stack must hold at least one IntNode.
 * Postcondition: Returns the int stored in the first IntNode that was added to 
 *                this stack. 
 *****************************************************************************/
int IntQueue::peek() 
{
	return head->getMyInt();
}
