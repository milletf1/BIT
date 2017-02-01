#include "StdAfx.h"
#include "BoidManager.h"

BoidManager::BoidManager(int lBounds, int rBounds, int tBounds, int bBounds, Random^ r, BoidDisplay^ display)
{
	leftBounds = lBounds;
	rightBounds = rBounds;
	topBounds = tBounds;
	botBounds = bBounds;
	rand = r;
	output = display;

	init();
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void BoidManager::init()
{
	db = gcnew BoidList();

	
	for(int i = 0; i < FLOCK_SIZE; i++)
	{
		db->add(createBoidFlockA());
		db->add(createBoidFlockB());
		db->add(createBoidFlockC());
		db->add(createBoidFlockD());
	}
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
Boid^ BoidManager::createBoidFlockA()
{
	float xPos = (float)rand->Next(FLOCK_A_X_START, FLOCK_A_X_END);
	float yPos = (float)rand->Next(FLOCK_A_Y_START, FLOCK_A_Y_END);

	Vector^ position = gcnew Vector(xPos, yPos);

	float xVel = rand->NextDouble() * MAX_SPEED;
	float yVel = rand->NextDouble() * MAX_SPEED;
	Vector^ velocity = gcnew Vector(xVel, yVel);

	Boid^ b = gcnew Boid(position, velocity);

	return b;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
Boid^ BoidManager::createBoidFlockB()
{
	float xPos = (float)rand->Next(FLOCK_B_X_START, FLOCK_B_X_END);
	float yPos = (float)rand->Next(FLOCK_B_Y_START, FLOCK_B_Y_END);

	Vector^ position = gcnew Vector(xPos, yPos);

	float xVel = (rand->NextDouble() * MAX_SPEED) * - 1;
	float yVel = rand->NextDouble() * MAX_SPEED;
	Vector^ velocity = gcnew Vector(xVel, yVel);

	Boid^ b = gcnew Boid(position, velocity);

	return b;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
Boid^ BoidManager::createBoidFlockC()
{
	float xPos = (float)rand->Next(FLOCK_C_X_START, FLOCK_C_X_END);
	float yPos = (float)rand->Next(FLOCK_C_Y_START, FLOCK_C_Y_END);

	Vector^ position = gcnew Vector(xPos, yPos);

	float xVel = rand->NextDouble() * MAX_SPEED;
	float yVel = (rand->NextDouble() * MAX_SPEED) * - 1;
	Vector^ velocity = gcnew Vector(xVel, yVel);

	Boid^ b = gcnew Boid(position, velocity);

	return b;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
Boid^ BoidManager::createBoidFlockD()
{
	float xPos = (float)rand->Next(FLOCK_D_X_START, FLOCK_D_X_END);
	float yPos = (float)rand->Next(FLOCK_D_Y_START, FLOCK_D_Y_END);

	Vector^ position = gcnew Vector(xPos, yPos);

	float xVel = (rand->NextDouble() * MAX_SPEED) * - 1;
	float yVel = (rand->NextDouble() * MAX_SPEED) * - 1;
	Vector^ velocity = gcnew Vector(xVel, yVel);

	Boid^ b = gcnew Boid(position, velocity);

	return b;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void BoidManager::moveBoids()
{
	for each(Boid^ b in boidsArray)
	{
		array<Boid^>^ neighbours = getNeighbours(b);
		b->moveBoid(neighbours);
	}
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void BoidManager::timerTick()
{
	boidsArray = db->getBoidArray();
	moveBoids();
	output->drawBoids(boidsArray);
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
array<Boid^>^ BoidManager::getNeighbours(Boid^ boid)
{
	BoidList^ neighbourList = gcnew BoidList();
	array<Boid^>^ arr;

	for each(Boid^ b in boidsArray)
	{
		// Check if the birds are neighbours.
		if(b != boid && boid->getLocation()->getDistance(b->getLocation()) < NEIGHBOUR_RADIUS)	
			// If they are, add the bird to the array.		
			neighbourList->add(b);
	}
	arr = neighbourList->getBoidArray();

	return arr;
}
