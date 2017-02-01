#include "StdAfx.h"
#include "MazeManager.h"

MazeManager::MazeManager(MazeDisplay^ mazeDisplay,int startWidth, int startHeight, Random^ r)
{
	mazeWidth = startWidth;
	mazeHeight = startHeight;

	rand = r;
	display = mazeDisplay;
	mazeFactory = gcnew MazeFactory(r);
	generateMaze();
}

void MazeManager::generateMaze()
{
	maze = mazeFactory->createMaze(PRIMS_MAZE, mazeWidth, mazeHeight);
	maze->generateMaze();
	maze->resetVisitedCells();
	display->drawMaze(maze);
}

void MazeManager::generateMaze(int width, int height)
{
	mazeWidth = width;
	mazeHeight = height;
	generateMaze();
}

void MazeManager::solveMaze()
{	
	maze->resetVisitedCells();
	PointStack^ explorer = gcnew  PointStack();
	
	// The point that we are trying to get to.
	Point^ endPoint = gcnew Point(mazeHeight - 1, mazeWidth - 1);	
	// The starting point.
	Point^ curPoint = gcnew Point(0, 0);
	// set start cell as visited.
	maze->getCells()[curPoint->Y, curPoint->X]->setIsVisited(true);
	//push start cell point onto stack.
	explorer->push(curPoint);

	//draw
	display->drawMaze(maze);
	Thread::Sleep(THREAD_SLEEP);

	while(explorer->peek()->X != endPoint->X || explorer->peek()->Y != endPoint->Y)
	{
		// get the last visited point.
		curPoint = explorer->peek();
		// The next point that we are going to move to (if possible).
		Point^ nextPoint = nullptr;
		// The first direction we are going to try and move.
		int startDirection = rand->Next(DIRECTIONS);
		
		//check if we can move to an unvisited cell in the start direction.
		nextPoint = checkLegalPoint(curPoint, startDirection);
				
		// Check if moving in the given start direction was allowed.
		if(nextPoint == nullptr)
		{
			// if it wasn't get the next direction.
			int nextDirection = startDirection + 1;
			nextDirection = nextDirection % DIRECTIONS;

			// run this while loop until a legal next direction is found or we loop back to the start direction.
			while(nextDirection != startDirection && nextPoint == nullptr)
			{
				// check if we can move to an unvisited cell in the next direction.
				nextPoint = checkLegalPoint(curPoint, nextDirection);
				
				if(nextPoint == nullptr)
				{
					//if the move isn't legal, check the next direciton.
					nextDirection++;
					nextDirection = nextDirection % DIRECTIONS;
				}
			}
		}
		// pop from the stack if it has reached a dead end.
		if(nextPoint == nullptr)
			explorer->pop();
		else
		{			
			// set the nextPoint cell as visited and push it on the stack.
			maze->getCells()[nextPoint->Y, nextPoint->X]->setIsVisited(true);
			explorer->push(nextPoint);
			
			//draw the maze.
			display->drawMaze(maze);
			Thread::Sleep(THREAD_SLEEP);
		}
	}
}

//Takes a point and a direction, checks if it is possible to move in the given
//direction from the given point.  If it is possible to make this move, checks if 
//the next point has been visited.  Returns the next point if it is legal, otherwise,
//returns nullptr
Point^ MazeManager::checkLegalPoint(Point^ curPoint, int direction)
{
	// the next point we are going to move to if its possible.
	Point^ nextPoint = nullptr;

	// check if the cell has a wall in the given direction.
	if( maze->getCells()[curPoint->Y, curPoint->X]->getIsPassable(direction) )					
	{		
		// if it doesn't, get the point that is in the given direction from the start point.
		Point^ checkPoint = maze->getPoint(direction, curPoint);
		
		// check if we have already visited the check point.
		if(!maze->getCells()[checkPoint->Y, checkPoint->X]->getIsVisited())
			// if we haven't, set the return point to the check point.
			nextPoint = checkPoint;		
	}
	return nextPoint;
}