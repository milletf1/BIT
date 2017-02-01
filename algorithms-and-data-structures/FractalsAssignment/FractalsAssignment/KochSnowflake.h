#pragma once
#include "LineSegment.h"
#include "GraphicsCalculator.h"

#define START_X 50
#define START_Y 175
#define START_LENGTH 600

#define KS_SECTION_MOD 3

#define KS_ONETWENTY_DEGREES 120
#define KS_60_DEGREES 60

using namespace System;
using namespace System::Drawing;

ref class KochSnowflake
{
private:
	GraphicsCalculator^ gc;
	Graphics^ canvas;
	void drawSnowflake(LineSegment^ line, int depth);
public:
	KochSnowflake(Graphics^ g);

	void generateSnowflake(Object^ depth);
};
