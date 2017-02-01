#include "StdAfx.h"
#include "Chromosome.h"

Chromosome::Chromosome()
{
}

Chromosome::Chromosome(String^ value, int fitness)
{
	myValue = value;
	myFitness = fitness;
}