#pragma once
#include "Boid.H"

ref class BoidNode
{
private:
	Boid^ boid;
public:
	BoidNode^ Next;

	BoidNode(Boid^ boid);

	Boid^ getBoid() { return boid; }
	void setBoid(Boid^ boid) { this->boid = boid; }

};
