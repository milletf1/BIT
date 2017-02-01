#pragma once
#include "PointNode.h"

using namespace System;
using namespace System::Drawing;

ref class PointLinkedList
{
private:
	PointNode^ head;
	PointNode^ tail;

	bool contains(Point^ p);

public:
	PointLinkedList();

	void add(Point^ p);
	void remove(Point^ p);
	Point^ getPoint(int index);

	int count();
	bool isEmpty()	{return count() == 0; }

	array<Point^>^ getArray();
};
