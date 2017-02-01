#include "StdAfx.h"
#include "LineSegmentLinkedList.h"

LineSegmentLinkedList::LineSegmentLinkedList()
{
	head = nullptr;
	tail = nullptr;
}


void LineSegmentLinkedList::addLineSegment(LineSegment^ line)
{

	if(head == nullptr)
	{
		head = line;
		tail = line;
	}
	else
	{
		tail->Next = line;
		tail = line;
	}
}

int LineSegmentLinkedList::count()
{
	int count = 0;
	LineSegment^ cur = head;

	while(cur != nullptr)
	{
		count++;
		cur = cur->Next;
	}
	
	return count;
}

array<LineSegment^>^ LineSegmentLinkedList::getLineSegmentArray()
{
	array<LineSegment^>^ arr = gcnew array<LineSegment^>(count());
	int arrayPointer = 0;
	LineSegment^ cur = head;

	while(arrayPointer < arr->Length)
	{
		arr[arrayPointer] = cur;
		arrayPointer++;
		cur = cur->Next;
	}	
	return arr;
}