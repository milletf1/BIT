#include "StdAfx.h"
#include "PointLinkedList.h"

PointLinkedList::PointLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void PointLinkedList::add(Point^ p)
{
	if(!contains(p))
	{
		PointNode^ node = gcnew PointNode();
		node->myPoint = p;

		if(head != nullptr)
		{
			tail->Next = node;
			tail = node;
		}
		else
		{
			head = node;
			tail = node;
		}
	}	
}

void PointLinkedList::remove(Point^ p)
{
	// Check if the head is the point that needs to be removed.
	if(head->myPoint->X == p->X && head->myPoint->Y == p->Y)
	{
		// Check if the tail is the point that needs to be removed.
		if(tail->myPoint->X == p->X && tail->myPoint->Y == p->Y)
		{
			// If the head and the tail are the same node, remove it.
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			// Otherwise, set the head to the head's next node.
			head = head->Next;
		}
	}
	else
	{
		// Set the current node and the next node.
		PointNode^ node = head;
		PointNode^ toDelete = node->Next;

		// Iterate through the list until the end is reached or the delete point is found.
		while(toDelete->myPoint->X != p->X || toDelete->myPoint->Y != p->Y)
		{
			node = node->Next;
			toDelete = toDelete->Next;
		}	
		node->Next = toDelete->Next;
	}
}

// Gets a point from a given index.
Point^ PointLinkedList::getPoint(int index)
{
	Point^ rPoint = nullptr;
	int nodeCount = count();

	// Check if the first point in the list was selected.
	if(index == 0)
		rPoint = head->myPoint;

	// Check if the last point in the list was selected.
	else if(index == nodeCount)
		rPoint = tail->myPoint;	
	
	// Find the point in the position given by the index.
	else
	{
		PointNode^ node = head->Next;		
		int count = 1;

		while(rPoint == nullptr)
		{
			// Check if we have reached the index point.
			if(count == index)
				rPoint = node->myPoint;
			else
			{
				node = node->Next;
				count++;
			}
		}
	}
	return rPoint;
}
int PointLinkedList::count()
{
	int count = 0;
	PointNode^ node = head;

	while(node != nullptr)
	{
		count++;
		node = node->Next;
	}
	return count;
}

bool PointLinkedList::contains(Point^ p)
{
	bool hasPoint = false;
	PointNode^ node = head;

	while(node != nullptr && !hasPoint)
	{
		if(node->myPoint->X == p->X && node->myPoint->Y == p->Y)		
			hasPoint = true;
		
		node = node->Next;
	}
	return hasPoint;
}

array<Point^>^ PointLinkedList::getArray()
{
	array<Point^>^ arr = gcnew array<Point^>(count());
	int counter = 0;
	PointNode^ node = head;

	while(node != nullptr)
	{
		arr[counter] = node->myPoint;
		counter++;
		node = node->Next;
	}
	return arr;
}