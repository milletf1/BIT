#pragma once
#include "Cell.h"
#define CELL_WIDTH 25
#define CELL_HEIGHT 25

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

enum BlockDirection{
	North,
	South,
	East,
	West
};
ref class BlockTemplate
{
protected:
	BlockDirection myBlockDirection;
	Point^ offset;
	Graphics^ canvas;
	array<Cell^>^ blockArray;
public:
	//constructor
	BlockTemplate(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);

	//methods
	void Draw();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	virtual void Rotate();
	virtual void InitializeBlockArray(Point^ startDrawPoint);

	//sets and gets
	array<Cell^>^ getBlockArray() {return blockArray;}
	void setBlockArray(array<Cell^>^ newBlockArray) {blockArray = newBlockArray;}
	void setOffset(Point^ p) { offset = p; }

};
