#include "StdAfx.h"
#include "SquareBlock.h"

SquareBlock::SquareBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas)
: BlockTemplate (startDrawPoint, startOffset, startColor, startCanvas)
{
}
void SquareBlock::Rotate(){}
void SquareBlock::InitializeBlockArray(Point^ startDrawPoint)
{
	//Declare a temporary Point for passing the starting grid point to each cell
	Point^ newPoint;

	//set cell 0
	newPoint = gcnew Point(startDrawPoint->X + 1, startDrawPoint->Y);
	blockArray[0]->setGridPoint(newPoint);
	
	//set cell 1
	newPoint = gcnew Point(startDrawPoint->X + 2, startDrawPoint->Y);
	blockArray[1]->setGridPoint(newPoint);
	
	//set cell 2
	newPoint = gcnew Point(startDrawPoint->X + 1, startDrawPoint->Y + 1);
	blockArray[2]->setGridPoint(newPoint);
	
	//set cell 3
	newPoint = gcnew Point(startDrawPoint->X + 2, startDrawPoint->Y + 1);
	blockArray[3]->setGridPoint(newPoint);
}
