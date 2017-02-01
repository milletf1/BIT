#include "StdAfx.h"
#include "LineSegment.h"

LineSegment::LineSegment()
{}

LineSegment::LineSegment(Point^ start, Point^ end)
{
	startPoint = start;
	endPoint = end;
}
