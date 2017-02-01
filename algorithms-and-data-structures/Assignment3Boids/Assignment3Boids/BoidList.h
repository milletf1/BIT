#pragma once
#include "Boid.H"
#include "BoidNode.H"

ref class BoidList
{
private:
	BoidNode^ head;
	BoidNode^ tail;
public:
	BoidList();

	void add(Boid^ boid);
	void remove(Boid^ boid);

	int count();

	array<Boid^>^ getBoidArray();
};
