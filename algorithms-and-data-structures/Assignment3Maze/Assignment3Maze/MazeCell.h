#pragma once

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define DIRECTIONS 4

ref class MazeCell
{
private:
	bool isVisited;
	array<bool>^ isPassable;	// can you move in the given direction from this cell.
public:
	MazeCell();

	bool getIsVisited()								{ return isVisited;}
	void setIsVisited(bool b)						{ isVisited = b; }

	array<bool>^ getIsPassable()							{ return isPassable; }
	bool getIsPassable(int direction)				{ return isPassable[direction]; }
	void setIsPassable(int direction, bool value)	{ isPassable[direction] = value; }
};
