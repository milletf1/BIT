#pragma once

using namespace System::Drawing;

ref class LineSegment
{
private:
	Point^ startPoint;
	Point^ endPoint;
public:
	LineSegment^ Next;

	LineSegment();
	LineSegment(Point^ start, Point^ end);

	Point^ getStartPoint()			{ return startPoint; }
	void setStartPoint(Point^ p)	{ startPoint = p; }

	Point^ getEndPoint()			{ return endPoint; }
	void setEndPoint(Point^ p)		{ endPoint = p; }
};
