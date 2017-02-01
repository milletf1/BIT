#include "StdAfx.h"
#include "PrimsMaze.h"

PrimsMaze::PrimsMaze(int width, int height, Random^ r)
:Maze(width, height, r)
{
}

void PrimsMaze::generateMaze()
{
	visitedCells = gcnew PointLinkedList();
	//frontierCells = gcnew PointLinkedList();
	//display->drawMaze(this);
	//Thread::Sleep(200);

	// Select a cell in the cell array and set as visited.
	int startRow = rand->Next(cells->GetLength(0));
	int startCol = rand->Next(cells->GetLength(1));
	cells[startRow, startCol]->setIsVisited(true);	
	// Get the frontier cells of the intial visited cell.
	Point^ startPoint = gcnew Point(startCol, startRow);
	visitedCells->add(startPoint);
	//getFrontierCells(startPoint);
	getFrontierCells();

	while(!frontierCells->isEmpty())
	{		
		// Choose a random frontier cell from the frontier cells list and set is as the current cell.
		int randCellIndex = rand->Next(frontierCells->count());
		Point^ curCell = frontierCells->getPoint(randCellIndex);

		// Choose a cell from the list of the current cell's neighbours.
		PointLinkedList^ visitedNeighbours = getVisitedNeighbours(curCell);
		int randNeighbour = rand->Next(visitedNeighbours->count());
		Point^ neighbour = visitedNeighbours->getPoint(randNeighbour);
		
		//Create a path from the frontier cell to the visited neighbour cell.
		linkCells(curCell, neighbour);
		
		// Set the selected cell as visited and add it to visitedCells.
		cells[curCell->Y, curCell->X]->setIsVisited(true);
		visitedCells->add(curCell);

		
		// remove the current cell from the frontiercells list.
		frontierCells->remove(curCell);
		
		// Add the current unvisited neighbours to the frontierCells list.
		getFrontierCells();
	}	
}



// The two given cells must be stored next to each other in the cells 2d array.
// Creates a path between the two given cells 
void PrimsMaze::linkCells(Point^ cellA, Point^ cellB)
{
	////System::Diagnostics::Debug::WriteLine("cellA: " + cells[cellA->Y, cellA->X]->getIsVisited() + " (false)");
	////System::Diagnostics::Debug::WriteLine("cellB: " + cells[cellB->Y, cellB->X]->getIsVisited() + " (true)");

	// Check if the cell B is above cell A
	if(getNorth(cellA)->X == cellB ->X &&
		getNorth(cellA)->Y == cellB ->Y)
	{
		////System::Diagnostics::Debug::WriteLine("link north");
		cells[cellA->Y, cellA->X]->setIsPassable(NORTH, true);		
		cells[cellB->Y, cellB->X]->setIsPassable(SOUTH, true);
	}
	// Check if cell B is to cell A's right
	if(getEast(cellA)->X == cellB->X &&
	   getEast(cellA)->Y == cellB->Y)
	{
		////System::Diagnostics::Debug::WriteLine("link east");
		cells[cellA->Y, cellA->X]->setIsPassable(EAST, true);		
		cells[cellB->Y, cellB->X]->setIsPassable(WEST, true);
	}
	// Check if cell B is below cell A
	if(getSouth(cellA)->X == cellB->X &&
	   getSouth(cellA)->Y == cellB->Y)
	{
		////System::Diagnostics::Debug::WriteLine("link south");
		cells[cellA->Y, cellA->X]->setIsPassable(SOUTH, true);		
		cells[cellB->Y, cellB->X]->setIsPassable(NORTH, true);
	}

	// Check if cell B to to cell A's left
	if(getWest(cellA)->X == cellB->X && 
	   getWest(cellA)->Y == cellB->Y)
	{
		cells[cellA->Y, cellA->X]->setIsPassable(WEST, true);		
		cells[cellB->Y, cellB->X]->setIsPassable(EAST, true);
	}


	if(cells[cellA->Y, cellA->X]->getIsVisited())
	{
		int nit = 1;
	}
}
void PrimsMaze::getFrontierCells()
{
	frontierCells = gcnew PointLinkedList();
	array<Point^>^ visitedArray = visitedCells->getArray();

	for each(Point^ p in visitedArray)
		getFrontierCells(p);
}
// Adds to the frontierCells list all the unvisited cells that are adjacent to the curCell parameter.
void PrimsMaze::getFrontierCells(Point^ curCell)
{
	// Get the neighbouring cells positions.
	Point^ northCell = getNorth(curCell);
	Point^ southCell = getSouth(curCell);
	Point^ eastCell = getEast(curCell);
	Point^ westCell = getWest(curCell);

	// Check if the north cell has been visited.
	if(northCell->X >= 0 && northCell->X < cells->GetLength(1) &&
		northCell->Y >= 0 && northCell->Y < cells->GetLength(0) )
	{
		if(!cells[northCell->Y, northCell->X]->getIsVisited())
		{
			frontierCells->add(northCell);
		}
	}

	// Check if the south cell has been visited.
	if(southCell->X >= 0 && southCell->X < cells->GetLength(1) &&
		southCell->Y >= 0 && southCell->Y < cells->GetLength(0) )
	{
		if(!cells[southCell->Y, southCell->X]->getIsVisited())
		{
			frontierCells->add(southCell);
		}
	}

	// Check if the east cell has been visited.
	if(eastCell->X >= 0 && eastCell->X < cells->GetLength(1) &&
		eastCell->Y >= 0 && eastCell->Y < cells->GetLength(0) )
	{
		if(!cells[eastCell->Y, eastCell->X]->getIsVisited())
		{
			frontierCells->add(eastCell);
		}
	}

	// Check if the west cell has been visited.
	if(westCell->X >= 0 && westCell->X < cells->GetLength(1) &&
		westCell->Y >= 0 && westCell->Y < cells->GetLength(0) )
	{
		if(!cells[westCell->Y, westCell->X]->getIsVisited())
		{
			frontierCells->add(westCell);
		}
	}
}

PointLinkedList^ PrimsMaze::getVisitedNeighbours(Point^ curCell)
{
	PointLinkedList^ visitedList = gcnew PointLinkedList();

	// Get the neighbouring cells positions.
	Point^ northCell = getNorth(curCell);
	Point^ southCell = getSouth(curCell);
	Point^ eastCell = getEast(curCell);
	Point^ westCell = getWest(curCell);

	// Check if the north cell has been visited.
	if(northCell->X >= 0 && northCell->X < cells->GetLength(1) &&
		northCell->Y >= 0 && northCell->Y < cells->GetLength(0) )
	{
		if(cells[northCell->Y, northCell->X]->getIsVisited())
		{
			visitedList->add(northCell);
		}
	}

	// Check if the south cell has been visited.
	if(southCell->X >= 0 && southCell->X < cells->GetLength(1) &&
		southCell->Y >= 0 && southCell->Y < cells->GetLength(0) )
	{
		if(cells[southCell->Y, southCell->X]->getIsVisited())
		{
			visitedList->add(southCell);
		}
	}

	// Check if the east cell has been visited.
	if(eastCell->X >= 0 && eastCell->X < cells->GetLength(1) &&
		eastCell->Y >= 0 && eastCell->Y < cells->GetLength(0) )
	{
		if(cells[eastCell->Y, eastCell->X]->getIsVisited())
		{
			visitedList->add(eastCell);
		}
	}

	// Check if the west cell has been visited.
	if(westCell->X >= 0 && westCell->X < cells->GetLength(1) &&
		westCell->Y >= 0 && westCell->Y < cells->GetLength(0) )
	{
		if(cells[westCell->Y, westCell->X]->getIsVisited())
		{
			visitedList->add(westCell);
		}
	}
	return visitedList;
}