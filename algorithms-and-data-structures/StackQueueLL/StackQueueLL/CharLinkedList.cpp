#include "StdAfx.h"
#include "CharLinkedList.h"

CharLinkedList::CharLinkedList()
{
	head = nullptr;
	tail = nullptr;
}




/*****************************************************************
 * Precondition:  A new char value needs to be added to the linked
                  list.
 * Postcondition: Creates a new CharNode with the given char and 
 *                returns it.
 ****************************************************************/
CharNode^ CharLinkedList::buildNode(Char c)
{
	CharNode^ n = gcnew CharNode(c);
	return n;
}

/*****************************************************************
 * Precondition:  A new char value needs to be added to the linked
 *                list.
 * Postcondition: Adds the given char value to the linked list.
 ****************************************************************/
void CharLinkedList::push(Char c)
{
	CharNode^ n = buildNode(c);

	//Check if there are any CharNodes in the linked list.
	if(head != nullptr)
	{
		//If there are, add the new CharNode to the end of the 
		//linked list.
		tail->Next = n;
		tail = n;
	}
	else
	{
		//If there aren't, set head and tail to the new CharNode.
		head = n;
		tail = n;
	}
}

/***************************************************************
 * Precondition:  The caller requires a count of each char value
 *                stored in this linked list.
 * Postcondition: Returns a count of the number of char values
 *                in this linked list.
 **************************************************************/
int CharLinkedList::count()
{ 
	int count = 0;
	CharNode^ cur = head;

	//Iterate through each CharNode in this linked list, incrementing
	//count on each iteration.
	while (cur != nullptr)
	{
		count++;
		cur = cur->Next;
	}
	return count;
}

String^ CharLinkedList::ToString()
{
	String^ s = "";	
	CharNode^ cur = head;

	while(cur != nullptr)
	{
		s = s + Convert::ToString(cur->getMyChar()) + "\r\n";
		cur = cur->Next;
	}
	return s;
}