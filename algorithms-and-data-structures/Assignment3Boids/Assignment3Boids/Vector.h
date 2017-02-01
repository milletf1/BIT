#pragma once

using namespace System;

ref class Vector
{
public:
	float X;
	float Y;
	
	Vector(float x, float y);

	float getMagnitude();

	float getDistance(Vector^ other);
	
	void limit(float max);
	void forceMove(float speed);
	void normalize();

	void subtract(Vector^ other);
	void add(Vector^ other);
	void multiply(float n);
	void divide(float n);
};
