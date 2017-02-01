#include "StdAfx.h"
#include "SierpinskiTriangle.h"

SierpinskiTriangle::SierpinskiTriangle(Graphics^ g)
{
	canvas = g;
	gc = gcnew GraphicsCalculator();
}

/*******************************************************************************************
 * Precondition:  The Object parameter depth must be an integer.
 * 
 * Postcondition: Public function used to generate a Sierpinski triangle.  Draws the initial
 *                traingle and sets the number of draw iterations.
 *******************************************************************************************/
void SierpinskiTriangle::generateTriangle(Object^ depth)
{
	int iterations = (int)depth;

	// Set the points of the initial triangle.
	Point^ left = gcnew Point(ST_START_X, ST_START_Y);
	Point^ right = gcnew Point(ST_START_X + ST_START_LENGTH, ST_START_Y);
	Point^ top = gc->calculatePoint(left, -60 * gc->Radians, ST_START_LENGTH);
	
	// Put the triangle points in an array to be passed to the drawTriangle function.
	array<Point^>^ coordinates = gcnew array<Point^>(ST_COORD_LENGTH);
	coordinates[ST_TOP] = top;
	coordinates[ST_LEFT] = left;
	coordinates[ST_RIGHT] = right;

	// Create an array of points to draw the initial triangle.
	array<Point>^ drawCoords = {
		Point(top->X, top->Y), 
		Point(left->X, left->Y), 
		Point(right->X, right->Y)
	};

	// Draw the Initial triangle (later draws remove sections of this triangle).
	Brush^ fill = gcnew SolidBrush(Color::White);
	canvas->FillPolygon(fill, drawCoords);

	drawTriangle(iterations, coordinates);
}

/****************************************************************************************
 * Precondition:  The coordinates array must be points in a triangle.  The index position
 *                of these coordinates must match the values defined in the header file.
 * 
 * Postcondition: Removes the middle section of the given triangle by filling in an 
 *                upside down triangle with the canvas' background colour.
 ***************************************************************************************/
void SierpinskiTriangle::drawTriangle(int depth, array<Point^>^ coordinates)
{
	if(depth > 0)
	{
		//Determine the distance and the angle of the bottom line of the triangle.
		int distance = gc->calculateDistance(coordinates[ST_LEFT], coordinates[ST_RIGHT]);
		float leftAngle = gc->getAngle(coordinates[ST_LEFT], coordinates[ST_TOP]);
		float rightAngle = gc->getAngle(coordinates[ST_RIGHT], coordinates[ST_TOP]);
		
		// Get the middle point of each line in the triangle.
		Point^ leftMid = gc->calculatePoint(coordinates[ST_LEFT], leftAngle, distance / 2);
		Point^ rightMid = gc->calculatePoint(coordinates[ST_RIGHT], rightAngle, distance / 2);
		Point^ botMid = gc->calculatePoint(coordinates[ST_LEFT], 0, distance / 2);

		// Create a new triangle from the top point and the left and right line's mid points.
		array<Point^>^ topTriangle = gcnew array<Point^>(ST_COORD_LENGTH);
		topTriangle[ST_TOP] = coordinates[ST_TOP];
		topTriangle[ST_LEFT] = leftMid;
		topTriangle[ST_RIGHT] = rightMid;
		
		// Create a new triangle from the left point and the left and bottom line's mid points.
		array<Point^>^ leftTriangle = gcnew array<Point^>(ST_COORD_LENGTH);
		leftTriangle[ST_TOP] = leftMid;
		leftTriangle[ST_LEFT] = coordinates[ST_LEFT];
		leftTriangle[ST_RIGHT] = botMid;
	
		// Create a new triangle from the right point and the right and bottom lin'es mid points.
		array<Point^>^ rightTriangle = gcnew array<Point^>(ST_COORD_LENGTH);
		rightTriangle[ST_TOP] = rightMid;
		rightTriangle[ST_LEFT] = botMid;
		rightTriangle[ST_RIGHT] = coordinates[ST_RIGHT];
		
		// Create an array of points to empty the middle triangle.
		array<Point>^ drawCoords = {
			Point(rightMid->X, rightMid->Y),
			Point(leftMid->X, leftMid->Y),
			Point(botMid->X, botMid->Y)
		};

		Brush^ bgColor = gcnew SolidBrush(Color::Black);

		// Empty out the middle triangle.
		canvas->FillPolygon(bgColor, drawCoords);

		// Call this function for each new triangle.
		drawTriangle(depth -1, topTriangle);
		drawTriangle(depth -1, leftTriangle);
		drawTriangle(depth -1, rightTriangle);
	}
}