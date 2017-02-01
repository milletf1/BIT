#pragma once
#include "LineSegment.h"
#include "GraphicsCalculator.h"

#define DC_START_X 200
#define DC_START_Y 350
#define DC_START_LENGTH 300
#define DC_BENT_LINE_MOD 0.71

#define DC_FOURTYFIVE_DEGREES 45

using namespace System::Drawing;
using namespace System;

ref class DragonCurve
{
private:
	GraphicsCalculator^ gc;
	Graphics^ canvas;

	void drawDragonCurve(int depth, LineSegment^ line);
public:
	DragonCurve(Graphics^ g);

	void generateDragonCurve(Object^ depth);	
};
