#include "StdAfx.h"
#include "Maze.h"

Maze::Maze(int width, int height, Random^ r)
{
	rand = r;
	generateCells(width, height);
//	generateMaze();
}

void Maze::generateCells(int width, int height)
{
	
	cells = gcnew array<MazeCell^, 2>(height, width);

	for(int row = 0; row < height; row++)
	{
		for(int col = 0; col < width; col++)
		{
			cells[row, col] = gcnew MazeCell();
		}
	}
}

void Maze::resetVisitedCells()
{
	for(int row = 0; row < cells->GetLength(0); row++)
	{
		for(int col = 0; col < cells->GetLength(1); col++)
			cells[row, col]->setIsVisited(false);
	}
}

Point^ Maze::getPoint(int direction, Point^ p)
{
	Point^ nextPoint;

	switch(direction)
	{
	case NORTH:
		nextPoint = getNorth(p);
		break;

	case SOUTH:
		nextPoint = getSouth(p);
		break;

	case EAST:
		nextPoint = getEast(p);
		break;

	case WEST:
		nextPoint = getWest(p);
		break;

	default:
		break;
	}
	return nextPoint;

}