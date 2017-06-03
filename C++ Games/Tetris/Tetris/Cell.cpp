#include "StdAfx.h"
#include "Cell.h"

Cell::Cell(Point^ startPoint, Color startColor, bool startGameBlock, Graphics^ startCanvas
		,int startWidth, int startHeight)
{
	gridPoint = startPoint;
	cellColor = startColor;
	isGameBlock = startGameBlock;
	canvas = startCanvas;
	width = startWidth;
	height = startHeight;
}
Cell::Cell(Color startColor, bool startGameBlock, Graphics^ startCanvas
		,int startWidth, int startHeight)
{
	cellColor = startColor;
	isGameBlock = startGameBlock;
	canvas = startCanvas;
	width = startWidth;
	height = startHeight;
}
void Cell::Draw(Point^ offset)
{
	//make sure the cell is in the gamegrid
	if(gridPoint->Y >= 0)
	{
		Brush^ myBrush = gcnew SolidBrush(cellColor);
		canvas->FillRectangle(myBrush, offset->X + (width * gridPoint->X), offset->Y + (height * gridPoint->Y), width, height);
		//check if the cell is a game block. if it is, draw a border round the cell
		if(isGameBlock)
		{
			Pen^ myPen = gcnew Pen(Color::Black, 1);
			canvas->DrawRectangle(myPen,  offset->X + (width * gridPoint->X), offset->Y + (height * gridPoint->Y), width - 1, height - 1);		
		}
	}
}
