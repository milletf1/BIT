#pragma once
#include "Maze.h"
#include "PointLinkedList.h"

// Algorithm is from http://weblog.jamisbuck.org/2011/1/10/maze-generation-prim-s-algorithm
using namespace System;
using namespace System::Drawing;
using namespace System::Threading;

ref class PrimsMaze :
public Maze
{
private:
	PointLinkedList^ frontierCells;
	PointLinkedList^ visitedCells;

	void getFrontierCells(Point^ cell);
	void getFrontierCells();

	void linkCells(Point^ cellA, Point^ cellB);
	PointLinkedList^ getVisitedNeighbours(Point^ curCell);

public:
	PrimsMaze(int width, int height, Random^ r);
	virtual void generateMaze() override;
};
