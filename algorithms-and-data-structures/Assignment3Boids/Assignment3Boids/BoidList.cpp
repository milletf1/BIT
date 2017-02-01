#include "StdAfx.h"
#include "BoidList.h"

BoidList::BoidList()
{
	head = nullptr;
	tail = nullptr;
}

void BoidList::add(Boid^ boid)
{
	BoidNode^ node = gcnew BoidNode(boid);

	if(head != nullptr)	
		tail->Next = node;	
	
	else
		head = node;

	tail = node;

}
void BoidList::remove(Boid^ boid)
{
	if(head->getBoid() == boid)
	{
		if(tail->getBoid() == boid)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = head->Next;
	}
	else
	{
		BoidNode^ cur = head;

		while(cur->Next->getBoid() != boid)		
			cur = cur->Next;

		cur->Next = cur->Next->Next;
	}
}

int BoidList::count()
{
	BoidNode^ cur = head;
	int count = 0;

	while(cur != nullptr)
	{
		count++;
		cur = cur->Next;
	}
	return count;
}

//
array<Boid^>^ BoidList::getBoidArray()
{
	array<Boid^>^ arr = gcnew array<Boid^>(count());
	BoidNode^ cur = head;
	int count = 0;

	while(cur != nullptr)
	{
		arr[count] = cur->getBoid();
		cur = cur->Next;	
		count++;
	}

	return arr;
}
