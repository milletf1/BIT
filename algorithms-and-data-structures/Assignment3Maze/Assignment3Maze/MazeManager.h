#pragma once
#include "Maze.h"
#include "PointStack.h"
#include "PrimsMaze.h"
#include "MazeDisplay.h"
#include "MazeFactory.h"

#define THREAD_SLEEP 100

using namespace System;
using namespace System::Threading;

ref class MazeManager
{
private:
	int mazeWidth, mazeHeight;
	Random^ rand;
	Maze^ maze;
	MazeDisplay^ display;
	MazeFactory^ mazeFactory;

	Point^ checkLegalPoint(Point^ curPoint, int direction);

public:
	MazeManager(MazeDisplay^ mazeDisplay, int startWidth, int startHeight, Random^ r);

	void generateMaze();
	void generateMaze(int width, int height);
	void solveMaze();
};
