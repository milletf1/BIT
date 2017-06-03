#include "StdAfx.h"
#include "BlockTemplate.h"

BlockTemplate::BlockTemplate(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas)
{
	myBlockDirection = BlockDirection::North;
	offset = startOffset;
	canvas = startCanvas;
	blockArray = gcnew array<Cell^>(4);
	for (int i = 0; i < blockArray->Length; i++)
	{
		blockArray[i] = gcnew Cell(startColor, true, startCanvas, CELL_WIDTH, CELL_HEIGHT);
	}
	InitializeBlockArray(startDrawPoint);
}
//Draw the cells in the blockArray to the canvas
void BlockTemplate::Draw()
{
	for(int i = 0; i < blockArray->Length; i++)
	{
		blockArray[i]->Draw(offset);
	}
}
//Move the cells in the blockArray down 1 cell 
void BlockTemplate::MoveDown()
{
	//Declare a new point
	Point^ newGridPoint;
	for(int i = 0; i < blockArray->Length; i++)
	{
		//Set the new Point equal to the old point with the Y position incremented
		newGridPoint = gcnew Point(blockArray[i]->getGridPoint()->X, blockArray[i]->getGridPoint()->Y + 1);
		//Set the cells gridPoint to the new point
		blockArray[i]->setGridPoint(newGridPoint);
	}
}
//Move the cells in the blockArray left 1 cell 
void BlockTemplate::MoveLeft()
{
	//Declare a new point
	Point^ newGridPoint;
	for(int i = 0; i < blockArray->Length; i++)
	{
		//Set the new Point equal to the old point with the X position decremented
		newGridPoint = gcnew Point(blockArray[i]->getGridPoint()->X - 1, blockArray[i]->getGridPoint()->Y);
		//Set the cells gridPoint to the new point
		blockArray[i]->setGridPoint(newGridPoint);
	}
}
//Move the cells in the blockArray right 1 cell 
void BlockTemplate::MoveRight()
{
	//Declare a new point
	Point^ newGridPoint;
	for(int i = 0; i < blockArray->Length; i++)
	{
		//Set the new Point equal to the old point with the X position incremented
		newGridPoint = gcnew Point(blockArray[i]->getGridPoint()->X + 1, blockArray[i]->getGridPoint()->Y);
		//Set the cells gridPoint to the new point
		blockArray[i]->setGridPoint(newGridPoint);
	}
}
void BlockTemplate::Rotate(){}
void BlockTemplate::InitializeBlockArray(Point^ startDrawPoint){}
