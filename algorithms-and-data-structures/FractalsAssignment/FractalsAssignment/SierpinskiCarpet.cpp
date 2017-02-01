#include "StdAfx.h"
#include "SierpinskiCarpet.h"

SierpinskiCarpet::SierpinskiCarpet(Graphics^ g)
{
	canvas = g;
}

/****************************************************************
 * Precondition:  The drawPoint parameter must be initialized.
 * 
 * Postcondition: Removes the middle section of the given square.
 ****************************************************************/
void SierpinskiCarpet::drawCarpet(int depth, Point^ drawPoint, int sideLength)
{
	if(depth > 0)
	{
		// Calculate the side length of the new squares.
		int newSideLength = sideLength / 3;

		// Calculate the point to draw the empty middle square.
		int emptySquareX = drawPoint->X + newSideLength;
		int emptySquareY = drawPoint->Y + newSideLength;

		// empty out the middle square.
		Brush^ b = gcnew SolidBrush(Color::Black);
		canvas->FillRectangle(b, emptySquareX, emptySquareY, newSideLength, newSideLength);

		// Calculate start point parameters for each new square.
		Point^ topLeft = drawPoint;
		Point^ top = gcnew Point(drawPoint->X + newSideLength, drawPoint->Y);
		Point^ topRight = gcnew Point(drawPoint->X + (newSideLength * 2), drawPoint->Y);

		Point^ left = gcnew Point(drawPoint->X, drawPoint->Y + newSideLength);
		Point^ right = gcnew Point(drawPoint->X + (newSideLength * 2), drawPoint->Y + newSideLength);

		Point^ bottomLeft = gcnew Point(drawPoint->X, drawPoint->Y + (newSideLength * 2));
		Point^ bottom = gcnew Point(drawPoint->X + newSideLength, drawPoint->Y + (newSideLength * 2));
		Point^ bottomRight = gcnew Point(drawPoint->X + (newSideLength * 2), drawPoint->Y + (newSideLength * 2));

		// Call this function for each new square.
		drawCarpet(depth -1, topLeft, newSideLength);
		drawCarpet(depth -1, top, newSideLength);
		drawCarpet(depth -1, topRight, newSideLength);

		drawCarpet(depth -1, left, newSideLength);
		drawCarpet(depth -1, right, newSideLength);

		drawCarpet(depth -1, bottomLeft, newSideLength);
		drawCarpet(depth -1, bottom, newSideLength);
		drawCarpet(depth -1, bottomRight, newSideLength);
	}
}

/*****************************************************************************************
 * Precondition:  The Object parameter depth must be an integer.
 * 
 * Postcondition: Public function used to generate a Sierpinski carpet.  Draws the initial
 *                squares and sets the number of draw iterations.
 *****************************************************************************************/
void SierpinskiCarpet::generateCarpet(Object^ depth)
{
	int iterations = (int)depth;

	// Draw the initial square.
	Brush^ b = gcnew SolidBrush(Color::White);
	canvas->FillRectangle(b, SC_START_X, SC_START_Y, SC_SIDE, SC_SIDE);

	drawCarpet(iterations, gcnew Point(SC_START_X, SC_START_Y), SC_SIDE);
}