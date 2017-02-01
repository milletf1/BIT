#pragma once
#include "Vector.h"
#include "BoidDisplay.h"
#include "BoidList.h"
#include "Boid.h"

#define FLOCK_SIZE 40
#define NEIGHBOUR_RADIUS 36

#define FLOCK_A_X_START 50
#define FLOCK_A_X_END 200
#define FLOCK_A_Y_START 50
#define FLOCK_A_Y_END 200

#define FLOCK_B_X_START 600
#define FLOCK_B_X_END 750
#define FLOCK_B_Y_START 50
#define FLOCK_B_Y_END 200

#define FLOCK_C_X_START 50
#define FLOCK_C_X_END 200
#define FLOCK_C_Y_START 400
#define FLOCK_C_Y_END 550

#define FLOCK_D_X_START 600
#define FLOCK_D_X_END 750
#define FLOCK_D_Y_START 400
#define FLOCK_D_Y_END 550

using namespace System;
using namespace System::Drawing;

ref class BoidManager
{
private:
	int leftBounds, rightBounds, topBounds, botBounds;
	Random^ rand;
	BoidList^ db;
	array<Boid^>^ boidsArray;
		
	void init();

	// Creates a boid within predefined bounds
	Boid^ createBoidFlockA();
	Boid^ createBoidFlockB();
	Boid^ createBoidFlockC();
	Boid^ createBoidFlockD();

	void moveBoids();	
	array<Boid^>^ getNeighbours(Boid^ boid);

public:
	BoidManager(int lBounds, int rBounds, int tBounds, int bBounds, Random^ r, BoidDisplay^ display);	
	void timerTick();	

	BoidDisplay^ output;
};
