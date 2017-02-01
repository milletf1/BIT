#pragma once
#include "LineSegment.h"

using namespace System::Drawing;

ref class LineSegmentLinkedList
{
private:
	LineSegment^ head;
	LineSegment^ tail;
public:
	LineSegmentLinkedList();

	void addLineSegment(LineSegment^ line);

	LineSegment^ getLast()	{ return tail; }

	int count();

	array<LineSegment^>^ getLineSegmentArray();
};
