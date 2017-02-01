#pragma once
#include "MazeCell.h"
#include "Maze.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows;

ref class MazeDisplay
{
private:
	int viewWidth, viewHeight;
	Graphics^ view;
public:
	MazeDisplay(Graphics^ g, int width, int height);

	void drawMaze(Maze^ maze);
};
