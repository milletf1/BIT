#include "StdAfx.h"
#include "BoidDisplay.h"

BoidDisplay::BoidDisplay(Graphics^ g, int canvasWidth, int canvasHeight)
{
	canvas = g;
	cWidth = canvasWidth;
	cHeight = canvasHeight;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void BoidDisplay::drawBoids(array<Boid^>^ boids)
{
	Bitmap^ buffer = gcnew Bitmap(cWidth, cHeight);
	Graphics^ g = Graphics::FromImage(buffer);

	// Draw background.
	Brush^ brush = gcnew SolidBrush(Color::LightBlue);
	g->FillRectangle(brush, 0, 0, cWidth, cHeight);

	// Set boid color.
	brush = gcnew SolidBrush(Color::DarkBlue);

	for each (Boid^ b in boids)
	{
		Vector^ position = b->getLocation();
		float offset = BOID_SIZE / 2;

		g->FillEllipse(brush, position->X - offset, position->Y - offset, (float)BOID_SIZE, (float)BOID_SIZE);
	}
	canvas->DrawImage(buffer, 0, 0, cWidth, cHeight);
}
