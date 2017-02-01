#pragma once
#include "Vector.h"
#include "Boid.h"

using namespace System;
using namespace System::Drawing;

ref class BoidDisplay
{
private:
	Graphics^ canvas;
	int cWidth;
	int cHeight;

public:
	BoidDisplay(Graphics^ g, int canvasWidth, int canvasHeight);
	void drawBoids(array<Boid^>^ boids);
};
