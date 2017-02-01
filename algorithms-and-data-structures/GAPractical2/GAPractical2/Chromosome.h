#pragma once

using namespace System;
ref class Chromosome
{
private:
 String^ myValue;
 int myFitness;
public:
	Chromosome();
	Chromosome(String^ value, int fitness);

	String^ getValue()				{ return myValue; }
	void setValue(String^ value)	{ myValue = value; }

	int getFitness()				{ return myFitness; }
	void setFitness(int fitness)	{ myFitness = fitness; }
};
