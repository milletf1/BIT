#pragma once

using namespace System;
using namespace System::Drawing;

ref class PointNode
{
public:	
	Point^ myPoint;
	PointNode^ Next;

	PointNode(void);
};
