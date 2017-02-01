#include "StdAfx.h"
#include "MazeFactory.h"

MazeFactory::MazeFactory(Random^ r)
{
	rand = r;
}

Maze^ MazeFactory::createMaze(int mapType, int width, int height)
{
	Maze^ maze = nullptr;

	switch(mapType)
	{
	case PRIMS_MAZE:
		maze = gcnew PrimsMaze(width, height, rand);
		break;

	case KRUSKALS_MAZE:
	case RECURSIVE_MAZE:
	default:
		break;
	}
	
	return maze;
}
