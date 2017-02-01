#pragma once

#define SC_SIDE 680
#define SC_START_X 10
#define SC_START_Y 10

using namespace System::Drawing;

ref class SierpinskiCarpet
{
private:
	Graphics^ canvas;

	void drawCarpet(int depth, Point^ drawPoint, int sideLength);
public:
	SierpinskiCarpet(Graphics^ g);
	void generateCarpet(Object^ depth);
};

	