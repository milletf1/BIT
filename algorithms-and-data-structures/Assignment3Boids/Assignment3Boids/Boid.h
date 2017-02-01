#pragma once
#include "Vector.h"

#define BOID_SIZE 6
#define SEPERATION_AREA 14

#define MAX_SPEED 3
#define MIN_SPEED 1
#define FORCE 0.05

#define SEPERATION_WEIGHT 2
#define ALIGNMENT_WEIGHT  1
#define COHESION_WEIGHT 1

using namespace System;
using namespace System::Drawing;
using namespace System::Windows;

ref class Boid
{

private:
	int stagingTime;
	Vector^ location;
	Vector^ velocity;

	Vector^ cohesion(array<Boid^>^ neighbours);
	Vector^ alignment(array<Boid^>^ neighbours);
	Vector^ seperation(array<Boid^>^ neighbours);
public:
	Boid(Vector^ sLocation, Vector^ sVelocity);

	void moveBoid(array<Boid^>^ neighbours);
	// gets/sets

	Vector^ getLocation()	{ return location; }
	Vector^ getVelocity()	{ return velocity; }
};
