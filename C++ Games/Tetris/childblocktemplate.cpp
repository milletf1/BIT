#include "StdAfx.h"
#include "child.h"

child::child(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas)
: BlockTemplate (startDrawPoint, startOffset, startColor, startCanvas)
{
}
void child::Rotate()
{
	//Declare a temporary Point for passing the starting grid point to each cell
	Point^ newPoint;
	
	//Set new block direction
		myBlockDirection = BlockDirection::new;
		//Set cell 1
		newPoint = gcnew Point(blockArray[0]->getGridPoint()->X - 1, blockArray[0]->getGridPoint()->Y + 1);
		blockArray[0]->setGridPoint(newPoint);
		//Set cell 3
		newPoint = gcnew Point(blockArray[2]->getGridPoint()->X + 1, blockArray[2]->getGridPoint()->Y - 1);
		blockArray[2]->setGridPoint(newPoint);	
		//Set cell 4
		newPoint = gcnew Point(blockArray[3]->getGridPoint()->X + 2, blockArray[2]->getGridPoint()->Y - 2);
		blockArray[3]->setGridPoint(newPoint);	
}
void child::InitializeBlockArray(Point^ startDrawPoint)
{
	//Declare a temporary Point for passing the starting grid point to each cell
	Point^ newPoint;

	//set cell 0
	newPoint = gcnew Point(startDrawPoint->X, startDrawPoint->Y);
	blockArray[0]->setGridPoint(newPoint);
	
	//set cell 1
	newPoint = gcnew Point(startDrawPoint->X, startDrawPoint->Y);
	blockArray[1]->setGridPoint(newPoint);
	
	//set cell 2
	newPoint = gcnew Point(startDrawPoint->X, startDrawPoint->Y);
	blockArray[2]->setGridPoint(newPoint);
	
	//set cell 3
	newPoint = gcnew Point(startDrawPoint->X, startDrawPoint->Y);
	blockArray[3]->setGridPoint(newPoint);
}