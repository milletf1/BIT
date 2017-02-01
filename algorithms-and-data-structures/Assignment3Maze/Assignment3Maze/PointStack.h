#pragma once
#include "PointNode.h"

using namespace System;
using namespace System::Drawing;

ref class PointStack
{
private:
	PointNode^ head;
	PointNode^ tail;
public:
	PointStack();

	void push(Point^ p);
	Point^ pop();
	Point^ peek();

	int count();
	bool isEmpty() { return count() == 0; }

};
