#pragma once
#include "MazeCell.h"

#define ROW 1
#define COL 0

using namespace System;
using namespace System::Drawing;

ref class Maze abstract
{
protected:
	Random^ rand;
	array<MazeCell^, 2>^ cells;

	void generateCells(int width, int height);
public:
	Maze(int width, int height, Random^ r);

	virtual void generateMaze() = 0;
	
	Point^ getPoint(int direction, Point^ p);

	Point^ getNorth(Point^ cellPos)	{ return gcnew Point(cellPos->X, cellPos->Y  - 1); }
	
	Point^ getSouth(Point^ cellPos)	{ return gcnew Point(cellPos->X, cellPos->Y + 1); }
	
	Point^ getEast(Point^ cellPos)	{ return gcnew Point(cellPos->X + 1, cellPos->Y); }

	Point^ getWest(Point^ cellPos)	{ return  gcnew Point(cellPos->X - 1, cellPos->Y); }

	array<MazeCell^, 2>^ getCells() { return cells; }

	void resetVisitedCells();

};
