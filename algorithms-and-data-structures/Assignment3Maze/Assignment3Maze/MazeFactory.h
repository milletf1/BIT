#pragma once
#include "Maze.h"
#include "PrimsMaze.h"

#define PRIMS_MAZE 0
#define KRUSKALS_MAZE 1
#define RECURSIVE_MAZE 2

using namespace System;
ref class MazeFactory
{
private:
	Random^ rand;
public:
	MazeFactory(Random^ r);

	Maze^ createMaze(int mapType, int width, int height);
};
