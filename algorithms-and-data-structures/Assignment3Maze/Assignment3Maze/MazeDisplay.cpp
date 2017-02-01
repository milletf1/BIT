#include "StdAfx.h"
#include "MazeDisplay.h"

MazeDisplay::MazeDisplay(Graphics^ g, int width, int height)
{
	view = g;
	viewWidth = width;
	viewHeight = height;
}

void MazeDisplay::drawMaze(Maze^ maze)
{
	// initialize a pen to draw the cell walls.
	Pen^ pen = gcnew Pen(Color::Black);

	//initialize a graphics buffer.
	Bitmap^ buffer = gcnew Bitmap(viewWidth, viewHeight);
	Graphics^ g = Graphics::FromImage(buffer);

	// refresh the background color
	g->FillRectangle(gcnew SolidBrush(Color::Gray), 0, 0, viewWidth, viewHeight);

	// get the cells from the given maze.
	array<MazeCell^, 2>^ cells = maze->getCells();

	// get the total number of rows and columns in the maze.
	int cols = cells->GetLength(ROW);
	int rows = cells->GetLength(COL);

	// get the width and height of each cell.
	float cellWidth =  viewWidth / cols;
	float cellHeight = viewHeight / rows;

	// draw the background.
	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < cols; col++)
		{
			MazeCell^ c = cells[row, col];
			
			float xPos = col * cellWidth;
			float yPos = row * cellHeight;

			// Set the cell background color to indicate if it has been visited.
			Brush^ baseColor = (c->getIsVisited())? gcnew SolidBrush(Color::Red) : gcnew SolidBrush(Color::Yellow);

			// Draw the cell
			g->FillRectangle(baseColor, xPos, yPos, cellWidth, cellHeight);			
		}
	}

	// draw the foreground (walls).
	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < cols; col++)
		{
			MazeCell^ c = cells[row, col];
			
			float xPos = col * cellWidth;
			float yPos = row * cellHeight;
			
			// Draw the cells walls.
			array<bool>^ openWall = c->getIsPassable();

			if(!openWall[NORTH])
			{
				g->DrawLine(pen, xPos, yPos, xPos + cellWidth, yPos);
			}
			if(!openWall[SOUTH])
			{
				g->DrawLine(pen, xPos, yPos + cellHeight, xPos + cellWidth, yPos + cellHeight);
			}
			if(!openWall[EAST])
			{
				g->DrawLine(pen, xPos + cellWidth, yPos, xPos + cellWidth, yPos + cellHeight);
			}
			if(!openWall[WEST])
			{
				g->DrawLine(pen, xPos, yPos, xPos, yPos + cellHeight);
			}
		}
	}
	// draw the image buffer to the view
	view->DrawImage(buffer, 0, 0);
}