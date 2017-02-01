#include "StdAfx.h"
#include "IntLinkedList.h"

IntLinkedList::IntLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

/****************************************************************
 * Precondition:  A new int value needs to be added to the linked
                  list.
 * Postcondition: Creates a new IntNode with the given int and 
 *                returns it.
 ***************************************************************/
IntNode^ IntLinkedList::buildNode(int i)
{
	IntNode^ n = gcnew IntNode(i);
	return n;
}

/****************************************************************
 * Precondition:  A new int value needs to be added to the linked
 *                list.
 * Postcondition: Adds the given int value to the linked list.
 ***************************************************************/
void IntLinkedList::push(int i)
{
	IntNode^ n = buildNode(i);

	//Check if there are any IntNodes in the linked list.
	if(head != nullptr)
	{
		//If there are, add the new IntNode to the end of the 
		//linked list.
		tail->Next = n;
		tail = n;
	}
	else
	{
		//If there aren't, set head and tail to the new IntNode.
		head = n;
		tail = n;
	}
}

/**************************************************************
 * Precondition:  The caller requires a count of each int value
 *                stored in this linked list.
 * Postcondition: Returns a count of the number of int values
 *                in this linked list.
 *************************************************************/
int IntLinkedList::count()
{ 
	int count = 0;
	IntNode^ cur = head;
	
	//Iterate through each IntNode in this linked list, incrementing
	//count on each iteration.
	while (cur != nullptr)
	{
		count++;
		cur = cur->Next;
	}
	return count;
}

String^ IntLinkedList::ToString()
{
	String^ s = "";
	IntNode^ cur = head;
	while(cur != nullptr)
	{
		s = s + Convert::ToString(cur->getMyInt()) + "\r\n";
		cur = cur->Next;
	}
	return s;
}