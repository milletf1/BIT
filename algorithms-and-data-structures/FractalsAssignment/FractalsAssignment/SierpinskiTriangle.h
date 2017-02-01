#pragma once
#include "GraphicsCalculator.h"

#define ST_START_X 10
#define ST_START_Y 600
#define ST_START_LENGTH 680

#define ST_COORD_LENGTH 3
#define ST_TOP 0
#define ST_LEFT 1
#define ST_RIGHT 2

using namespace System;
using namespace System::Drawing;

ref class SierpinskiTriangle
{
private:
	Graphics^ canvas;
	GraphicsCalculator^ gc;

	void drawTriangle(int depth, array<Point^>^ coordinates);
public:
	SierpinskiTriangle(Graphics^ g);

	void generateTriangle(Object^ depth);
};
