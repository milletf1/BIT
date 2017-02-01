#include "StdAfx.h"
#include "Vector.h"

Vector::Vector(float x, float y)
{
	X = x;
	Y = y;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
float Vector::getMagnitude()
{ 
	return Math::Sqrt( (X * X) + (Y * Y) ); 
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
float Vector::getDistance(Vector^ other) 
{ 	
	float distX = Math::Abs(X - other->X);
	float distY = Math::Abs(Y - other->Y);

	return Math::Sqrt( (distX * distX) + (distY * distY) ); 
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Vector::normalize() 
{ 
	float magnitude = getMagnitude();
	if(magnitude > 0)
		divide(magnitude);
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Vector::subtract(Vector^ other)
{
	X -= other->X;
	Y -= other->Y;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Vector::add(Vector^ other)
{
	X += other->X;
	Y += other->Y;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Vector::multiply(float n)
{
	X = X * n;
	Y = Y * n;
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Vector::divide(float n)
{
	if( n > 0)
	{
		X = X / n;
		Y = Y / n;
	}
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Vector::limit(float max)
{
	float magnitude = getMagnitude();

	if(magnitude > max)
	{
		normalize();
		multiply(max);
	}
}

/**
 * Precondition:  x
 *
 * Postcondition: x
 */
void Vector::forceMove(float speed)
{
	float magnitude = getMagnitude();

	if(magnitude < speed)
	{
		normalize();
		multiply(speed);
	}
}