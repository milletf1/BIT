#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Cell
{
private:
	Graphics^ canvas;
	//gridPoint is the point on the form where the cell is drawn,
	Point^ gridPoint;
	Color cellColor;
	//isFull is used by the game grid to detect if a game block is resting on
	//a previous block.
	bool isFull;
	//isGameBlock is used by the draw method to determine if a border needs to be 
	//drawn around the cell
	bool isGameBlock;
	int width;
	int height;
	int spacer;
public:
	//constructors (two different constructors, one for the game and preview window grids, and one for BlockTemplate)
	Cell(Point^ startPoint, Color startColor, bool startGameBlock, Graphics^ startCanvas
		,int startWidth, int startHeight);
	Cell(Color startColor, bool startGameBlock, Graphics^ startCanvas
		,int startWidth, int startHeight);
	//Methods
	void Draw(Point^ offset);
	//sets and gets
	Point^ getGridPoint() {return gridPoint;}
	void setGridPoint(Point^ p) {gridPoint = p;} 
	
	bool getIsFull() {return isFull;}
	void setIsFull(bool b) {isFull = b;}

	bool getIsGameBlock() {return isGameBlock;}
	void setIsGameBlock(bool b) {isGameBlock = b;}

	Color getCellColor() {return cellColor;}
	void setCellColor(Color c) {cellColor = c;}
};
