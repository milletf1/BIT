#include "StdAfx.h"
#include "KochSnowflake.h"

KochSnowflake::KochSnowflake(Graphics^ g)
{
	canvas = g;
	gc = gcnew GraphicsCalculator();
}

/***********************************************************************************************
 * Precondition:  The LineSegment parameter line must be initialized and contain 2 points.
 * 
 * Postcondition: Recursive function used to calculate and draw each line in the Koch Snowflake.
 ***********************************************************************************************/
void KochSnowflake::drawSnowflake(LineSegment^ line, int depth)
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
		double distance = gc->calculateDistance(line->getStartPoint(), line->getEndPoint());
		double sectionLength =  distance / KS_SECTION_MOD;							

		// Calculate the angle of the given line parameter.
		float angle = gc->getAngle(line->getStartPoint(), line->getEndPoint());

		// Calculate the points of each new line.
		Point^ aStart = line->getStartPoint();
		Point^ aEnd = gc->calculatePoint(aStart, angle, sectionLength);
		LineSegment^ lineA = gcnew LineSegment(aStart, aEnd);
		
		Point^ bStart = aEnd;
		Point^ bEnd = gc->calculatePoint(bStart, angle - (KS_60_DEGREES * gc->Radians ), sectionLength);
		LineSegment^ lineB = gcnew LineSegment(bStart, bEnd);
					
		Point^ cStart = bEnd;
		Point^ cEnd = gc->calculatePoint(cStart, angle + (KS_60_DEGREES * gc->Radians ), sectionLength);
		LineSegment^ lineC = gcnew LineSegment(cStart, cEnd);

		Point^ dStart = cEnd;
		Point^ dEnd = line->getEndPoint();
		LineSegment^ lineD = gcnew LineSegment(dStart, dEnd);

		// Call this function on each new line segment.
		drawSnowflake(lineA, depth - 1);
		drawSnowflake(lineB, depth - 1);
		drawSnowflake(lineC, depth - 1);
		drawSnowflake(lineD, depth - 1);
	}
}

/***********************************************************************************
 * Precondition:  The depth parameter must be initialized with an integer value.
 * 
 * Postcondition: Initializes the first three line segments used to recursively draw
 *                a Koch Snowflake.
 ***********************************************************************************/
void KochSnowflake::generateSnowflake(Object^ depth)
{
	int iterations = (int)depth;

	// Define first line.
	Point^ line1Start = gcnew Point(START_X, START_Y);
	Point^ line1End = gc->calculatePoint(line1Start, 0, START_LENGTH);
	LineSegment^ line1 = gcnew LineSegment(line1Start, line1End);
	
	// Define second line.
	Point^ line2Start = line1End;
	Point^ line2End = gc->calculatePoint(line2Start, KS_ONETWENTY_DEGREES * gc->Radians, START_LENGTH);
	LineSegment^ line2 = gcnew LineSegment(line2Start, line2End);

	// Define third line.
	Point^ line3Start = line2End;
	Point^ line3End = line1Start;
	LineSegment^ line3 = gcnew LineSegment(line3Start, line3End);

	// Start calculating line segments for the Koch Snowflake.
	drawSnowflake(line1, iterations);
	drawSnowflake(line2, iterations);
	drawSnowflake(line3, iterations);
}
