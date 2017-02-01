#include "StdAfx.h"
#include "DragonCurve.h"

DragonCurve::DragonCurve(Graphics^ g)
{
	gc = gcnew GraphicsCalculator();
	canvas = g;
}

/********************************************************************************************
 * Precondition:  The LineSegment parameter line must be initialized and contain 2 points.
 * 
 * Postcondition: Recursive function used to calculate and draw each line in the Dragon Curve.
 ********************************************************************************************/
void DragonCurve::drawDragonCurve(int depth, LineSegment^ line)
{
	// If depth is 0 we don't need to calucate any more line points and can draw the given line.
	if(depth == 0)
	{		
		Pen^ p = gcnew Pen(Color::White);

		canvas->DrawLine(p, line->getStartPoint()->X, line->getStartPoint()->Y,
							line->getEndPoint()->X, line->getEndPoint()->Y);		
	}
	else
	{
		// Calculate the length of each new line segment.
		float length = gc->calculateDistance(line->getStartPoint(), line->getEndPoint());
		length = length * DC_BENT_LINE_MOD; 

		// Calculate the angle of the given line parameter.
		float angle = gc->getAngle(line->getStartPoint(), line->getEndPoint());
			
		// Calculate a new middle point.  This point is used to "Bend" the line parameter.
		Point^ midPoint = gc->calculatePoint(line->getStartPoint(), 
			angle + ( DC_FOURTYFIVE_DEGREES * gc->Radians ), length);
		
		// Create two new line segments with the new middle point.  
		LineSegment^ left = gcnew LineSegment(line->getStartPoint(), midPoint);
		LineSegment^ right = gcnew LineSegment(line->getEndPoint(), midPoint);

		// Call this function on each new line segment.
		drawDragonCurve(depth - 1, left);
		drawDragonCurve(depth - 1, right);
	}
}

/***********************************************************************************
 * Precondition:  The depth parameter must be initialized with an integer value.
 * 
 * Postcondition: Initializes the first line segment used to recursively draw a
 *                Dragon Curve.
 ***********************************************************************************/
void DragonCurve::generateDragonCurve(Object^ depth)
{
	int iterations = (int)depth;

	// Define the first line.
	Point^ startPoint = gcnew Point(DC_START_X, DC_START_Y);
	Point^ endPoint = gcnew Point(DC_START_X + DC_START_LENGTH, DC_START_Y);
	LineSegment^ line = gcnew LineSegment(startPoint, endPoint);	

	// Start calculating the line segments for the Dragon Curve.
	drawDragonCurve(iterations, line);
}	
