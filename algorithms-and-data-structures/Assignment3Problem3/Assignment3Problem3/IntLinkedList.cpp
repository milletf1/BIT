#include "StdAfx.h"
#include "IntLinkedList.h"


IntLinkedList::IntLinkedList()
{
	head = nullptr;
	tail = nullptr;
}
/**
* Precondition: A new int value needs to be added to the linked list.
*
* Postcondition: Creates a new IntNode with the given int and
*				 returns it.
*/
IntNode^ IntLinkedList::buildNode(int i)
{
	IntNode^ n = gcnew IntNode(i);
	return n;
}

/**
* Precondition: A new int value needs to be added to the linked
*				list.
*
* Postcondition: Adds the given int value to the linked list.
*/
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

/**
* Precondition: The caller requires a count of each int value
*			    stored in this linked list.
*
* Postcondition: Returns a count of the number of int values
*				 in this linked list.
*/
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
///////
array<int>^ IntLinkedList::getList() 
{
	array<int>^ arr = gcnew array<int>(count());
	IntNode^ cur = head;

	for(int i = 0; i < arr->Length; i++)
	{
		arr[i] = cur->getMyInt();
		cur = cur->Next;
	}

	return arr;	
}
/////

void IntLinkedList::sort()
{
	quickSort(this);
}

IntLinkedList^ IntLinkedList::quickSort(IntLinkedList^ ll)
{
	//Base case
	if(ll->count() <= 1)
		return ll;
	else
	{	
		// Create a left and a right linked list.
		IntLinkedList^ left = gcnew IntLinkedList();
		IntLinkedList^ right = gcnew IntLinkedList();

		// Set the pivot node.
		IntNode^  pivot = ll->getHead();

		// Get the value from the pivot node.
		int pivotValue = pivot->getMyInt();

		IntNode^ curNode = pivot->Next;

		// Place all the non pivot nodes into either the left or right linked list.
		while(curNode != nullptr)
		{
			int curValue = curNode->getMyInt();

			if(curValue <= pivotValue)
				left->push(curValue);

			else
				right->push(curValue);

			curNode = curNode->Next;
		}

		// Call quicksort on the left and right linked lists.
		quickSort(left);
		quickSort(right);

		// Set the head and tail of the current linked list.
		if(left->count() > 0)
		{
			left->getTail()->Next = pivot;
			ll->setHead(left->getHead());			
		}
		else		
			ll->setHead(pivot);

		if(right->count() > 0)
		{
			pivot->Next = right->getHead();
			ll->setTail(right->getTail());
		}
		else
			ll->setTail(pivot);		
	}
}