#include "StdAfx.h"
#include "SBlock.h"

SBlock::SBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas)
: BlockTemplate (startDrawPoint, startOffset, startColor, startCanvas)
{
}
void SBlock::Rotate()
{
	//Declare a temporary Point for passing the starting grid point to each cell
	Point^ newPoint;
	
	//Check for north to east rotation
	if(myBlockDirection == BlockDirection::North)
	{
		//Set new block direction
		myBlockDirection = BlockDirection::East;
		
		//Set cell 0
		newPoint = gcnew Point(blockArray[0]->getGridPoint()->X - 1, blockArray[0]->getGridPoint()->Y + 1);
		blockArray[0]->setGridPoint(newPoint);
		
		//Set cell 2
		newPoint = gcnew Point(blockArray[2]->getGridPoint()->X - 1, blockArray[2]->getGridPoint()->Y - 1);
		blockArray[2]->setGridPoint(newPoint);	
		
		//Set cell 3
		newPoint = gcnew Point(blockArray[3]->getGridPoint()->X, blockArray[3]->getGridPoint()->Y - 2);
		blockArray[3]->setGridPoint(newPoint);	
	}
	//Check for east to north rotation
	else if(myBlockDirection == BlockDirection::East)
	{
		//Set new block direction
		myBlockDirection = BlockDirection::North;
		
		//Set cell 0
		newPoint = gcnew Point(blockArray[0]->getGridPoint()->X + 1, blockArray[0]->getGridPoint()->Y - 1);
		blockArray[0]->setGridPoint(newPoint);
		
		//Set cell 2
		newPoint = gcnew Point(blockArray[2]->getGridPoint()->X + 1, blockArray[2]->getGridPoint()->Y + 1);
		blockArray[2]->setGridPoint(newPoint);	
		
		//Set cell 3
		newPoint = gcnew Point(blockArray[3]->getGridPoint()->X, blockArray[3]->getGridPoint()->Y + 2);
		blockArray[3]->setGridPoint(newPoint);
	}
}
void SBlock::InitializeBlockArray(Point^ startDrawPoint)
{
	//Declare a temporary Point for passing the starting grid point to each cell
	Point^ newPoint;

	//set cell 0
	newPoint = gcnew Point(startDrawPoint->X + 3, startDrawPoint->Y);
	blockArray[0]->setGridPoint(newPoint);
	
	//set cell 1
	newPoint = gcnew Point(startDrawPoint->X + 2, startDrawPoint->Y);
	blockArray[1]->setGridPoint(newPoint);
	
	//set cell 2
	newPoint = gcnew Point(startDrawPoint->X + 2, startDrawPoint->Y + 1);
	blockArray[2]->setGridPoint(newPoint);
	
	//set cell 3
	newPoint = gcnew Point(startDrawPoint->X + 1, startDrawPoint->Y + 1);
	blockArray[3]->setGridPoint(newPoint);
}