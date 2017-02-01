#include "StdAfx.h"
#include "PointStack.h"

PointStack::PointStack()
{
	head = nullptr;
	tail = nullptr;
}

void PointStack::push(Point^ p)
{
	PointNode^ node = gcnew PointNode();
	node->myPoint = p;

	if(head != nullptr)
	{
		PointNode^ tempNode = head;
		head = node;
		head->Next = tempNode;
		
	}
	else
	{
		head = node;
		tail = node;
	}

}
Point^ PointStack::pop()
{
	Point^ p = head->myPoint;
	head = head->Next;
	return p;
}
Point^ PointStack::peek()
{
	Point^ p = head->myPoint;
	return p;
}

int PointStack::count()
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
