#include "StdAfx.h"
#include "Boid.h"

Boid::Boid(Vector^ sLocation, Vector^ sVelocity)
{
	location = sLocation;
	velocity = sVelocity;
}


// Calculates and returns the average location of the boids in the neigbours array.

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
Vector^ Boid::cohesion(array<Boid^>^ neighbours)
{	
	Vector^ locationAvg = gcnew Vector(0, 0);

	if(neighbours->Length > 0)
	{
		for each (Boid^ b in neighbours)
			locationAvg->add(b->getLocation());

		locationAvg->divide(neighbours->Length);
		locationAvg->subtract(locationAvg);
		locationAvg->normalize();
		locationAvg->limit(FORCE);
	}
	return locationAvg;
}

// Calculates and returns the average velocity of the boids in the neighbours array.

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
Vector^ Boid::alignment(array<Boid^>^ neighbours)
{
	Vector^ velocityAvg = gcnew Vector(0, 0);

	if(neighbours->Length > 0)
	{
		for each (Boid^ b in neighbours)
			velocityAvg->add(b->getVelocity());

		velocityAvg->divide(neighbours->Length);
		velocityAvg->limit(FORCE);
	}
	return velocityAvg;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
Vector^ Boid::seperation(array<Boid^>^ neighbours)
{
	Vector^ velocityAvg = gcnew Vector(0, 0);
	
	if(neighbours->Length > 0)
	{
		for each (Boid^ b in neighbours)
		{
			float distance = location->getDistance(b->getLocation());
			
			if(distance < SEPERATION_AREA)
			{
				Vector^ diff = gcnew Vector(location->X, location->Y);
				
				diff->subtract(b->getLocation());
				diff->normalize();
				diff->divide(distance);

				velocityAvg->add(diff);
			}
		}
		velocity->divide(neighbours->Length);
	}

	return velocityAvg;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Boid::moveBoid(array<Boid^>^ neighbours)
{	
	Vector^ alignmentVector = alignment(neighbours);
	Vector^ cohesionVector = cohesion(neighbours);
	Vector^ seperationVector = seperation(neighbours);

	alignmentVector->multiply(ALIGNMENT_WEIGHT);
	cohesionVector->multiply(COHESION_WEIGHT);
	seperationVector->multiply(SEPERATION_WEIGHT);

	velocity->add(alignmentVector);
	velocity->add(cohesionVector);
	velocity->add(seperationVector);

	// Make sure the is moving within the bounds of the min and max speed.
	velocity->limit(MAX_SPEED);
	velocity->forceMove(MIN_SPEED);

	location->add(velocity);
}
