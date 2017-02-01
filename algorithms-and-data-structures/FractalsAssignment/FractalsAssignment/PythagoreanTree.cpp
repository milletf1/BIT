#include "StdAfx.h"
#include "PythagoreanTree.h"

PythagoreanTree::PythagoreanTree(Graphics^ g)
{
	canvas = g;
	gc = gcnew GraphicsCalculator();
}

/************************************************************************************
 * Precondition:  Each index in the squareCoordinates array must have a line segment.
 * 
 * Postcondition: Draws a square with the given coordinates.
 ************************************************************************************/
void PythagoreanTree::draw(array<LineSegment^>^ squareCoordinates)
{
	Pen^ p = gcnew Pen(Color::White);

	// Draw each line in the squareCoordinates array.
	for(int i = 0; i < squareCoordinates->Length; i++)
	{
		canvas->DrawLine(p, squareCoordinates[i]->getStartPoint()->X, squareCoordinates[i]->getStartPoint()->Y,
			squareCoordinates[i]->getEndPoint()->X, squareCoordinates[i]->getEndPoint()->Y);
	}
}

/*******************************************************************************************
 * Precondition:  Each index in the squareCoordinates array must have a line segment.
 * 
 * Postcondition: Determines the position of the next two squares to draw, draws the current
 *                square, and resursively calls this function with the new squares.
 *******************************************************************************************/
void PythagoreanTree::drawTree(int depth, array<LineSegment^>^ squareCoordinates)
{
	if(depth == 0)
	{
		// Draw the square if recursion has finished.
		draw(squareCoordinates);
	}
	else
	{		
		// Calculate Base angle and side length.
		int sideLength = gc->calculateDistance(squareCoordinates[TOP]->getStartPoint(), squareCoordinates[TOP]->getEndPoint());
		float angle = gc->getAngle(squareCoordinates[TOP]->getEndPoint(), squareCoordinates[TOP]->getStartPoint());

		// Calculate left hanging square.
		Point^ leftStart = squareCoordinates[TOP]->getEndPoint();
		Point^ leftEnd = gc->calculatePoint(leftStart, angle - (60 * gc->Radians), sideLength * 0.5);
		
		// Generate left hanging square.
		LineSegment^ leftBase = gcnew LineSegment(leftStart, leftEnd);
		array<LineSegment^>^ leftSquareCoordinates  = generateSquare(leftBase);

		// Calculate right hanging square.
		Point^ rightStart = leftSquareCoordinates[BOT]->getEndPoint();
		Point^ rightEnd = squareCoordinates[TOP]->getStartPoint();
		
		// Generate right hanging square.
		LineSegment^ rightBase = gcnew LineSegment(rightStart, rightEnd);
		array<LineSegment^>^ rightSquareCoordinates = generateSquare(rightBase);

		// Call drawTree on both left and right hanging squares.
		drawTree(depth -1, leftSquareCoordinates);
		drawTree(depth -1, rightSquareCoordinates);

		// Draw this square.
		draw(squareCoordinates);
	}
}

/*************************************************************************************
 * Precondition:  The botLine parameter must be initialized.
 * 
 * Postcondition: Generates the coordinates of a square with the given line segment as 
 *				  the base.
 *************************************************************************************/
array<LineSegment^>^ PythagoreanTree::generateSquare(LineSegment^ botLine)
{
	array<LineSegment^>^ squareCoordinates = gcnew array<LineSegment^>(SQUARE_SIDES);
	
	squareCoordinates[BOT] = botLine;
	
	// Calculate the length of the squares sides.
	int sideLength = gc->calculateDistance(botLine->getStartPoint(), botLine->getEndPoint());	

	// Calculate the angle of the square.
	float angle = gc->getAngle(botLine->getStartPoint(), botLine->getEndPoint());
	
	// Initialize right hand side of square.
	Point^ rightStart = botLine->getEndPoint();
	Point^ rightEnd = gc->calculatePoint(rightStart, angle - ( PT_NINETY_DEGREES * gc->Radians ), sideLength);
	LineSegment^ rightLine = gcnew LineSegment(rightStart, rightEnd);
	squareCoordinates[RIGHT] = rightLine;

	// Initialize top of square.
	Point^ topStart = rightEnd;
	Point^ topEnd = gc->calculatePoint(topStart, angle - ( PT_ONEEIGHTY_DEGREES * gc->Radians ), sideLength);
	LineSegment^ topLine = gcnew LineSegment(topStart, topEnd);
	squareCoordinates[TOP] = topLine;

	// Initialize left hand side of square.
	Point^ leftStart = topEnd;
	Point^ leftEnd = botLine->getStartPoint();
	LineSegment^ leftLine = gcnew LineSegment(leftStart, leftEnd);
	squareCoordinates[LEFT] = leftLine;

	return squareCoordinates;
}

/**************************************************************************
 * Precondition:  The depth parameter must be an integer.
 * 
 * Postcondition: Public function that enables drawing a Pythagorean tree.  
 *				  The depth parameter dictates how many iterations to draw.
 **************************************************************************/
void PythagoreanTree::generateTree(Object^ depth)
{
	int iterations = (int)depth;

	// Set the line segments for the initial square.
	Point^ botStart = gcnew Point(TREE_START_X, TREE_START_Y);
	Point^ botEnd = gcnew Point(TREE_START_X + TREE_START_LENGTH, TREE_START_Y);
	LineSegment^ botLine = gcnew LineSegment(botStart, botEnd);
	
	array<LineSegment^>^ squareCoordinates = generateSquare(botLine);
	
	drawTree(iterations, squareCoordinates);	
}
