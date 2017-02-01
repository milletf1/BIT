#pragma once
#include "GraphicsCalculator.h"
#include "LineSegment.h"

#define TOP 0
#define RIGHT 1
#define BOT 2
#define LEFT 3

#define SQUARE_SIDES 4

#define PT_NINETY_DEGREES 90
#define PT_ONEEIGHTY_DEGREES 180

#define TREE_START_X 200
#define TREE_START_Y 500
#define TREE_START_LENGTH 80

using namespace System;
using namespace System::Drawing;

ref class PythagoreanTree
{
private:
	Graphics^ canvas;
	GraphicsCalculator^ gc;

	void drawTree(int depth, array<LineSegment^>^ squareCoordinates);
	
	void draw(array<LineSegment^>^ squareCoordinates);

	array<LineSegment^>^ generateSquare(LineSegment^ botLine);
public:
	PythagoreanTree(Graphics^ g);

	void generateTree(Object^ depth);
};
