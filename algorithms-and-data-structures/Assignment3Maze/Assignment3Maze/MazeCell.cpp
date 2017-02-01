#include "StdAfx.h"
#include "MazeCell.h"

MazeCell::MazeCell()
{
	isVisited = false;
	isPassable = gcnew array<bool>(DIRECTIONS);

	for each(bool b in isPassable)
		b = false;
}
