#include "StdAfx.h"
#include "IntStack.h"

IntStack::IntStack() : IntLinkedList()
{}

/*****************************************************************************
 * Precondition:  This stack must hold at least one IntNode.
 * Postcondition: Returns the int stored in the last IntNode that was added to 
 *                this stack.  Removes the last IntNode that was added to this 
 *                stack.
 ****************************************************************************/
int IntStack::pop() 
{	
	IntNode^ cur = head;
	IntNode^ returnNode = tail;

	//Check if the linked list contains 1 node.	
	if(head->Next == nullptr)
	{
		//If it does, set head and tail to null.
		head = nullptr;
		tail = nullptr;
	}
	else
	{		
		//Otherwise, set tail to the IntNode pointing to tail.
		while(cur->Next != returnNode)
		{
			cur = cur->Next;
		}
		cur->Next = nullptr;
		tail = cur;
	}
	return returnNode->getMyInt();
}

/*****************************************************************************
 * Precondition:  This stack must hold at least one IntNode.
 * Postcondition: Returns the int stored in the last IntNode that was added to 
 *                this stack. 
 ****************************************************************************/
int IntStack::peek() 
{
	return tail->getMyInt();
}

