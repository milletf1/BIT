#pragma once
#include "gene.h"

#define CHAR_A 65
#define CHAR_Z 90
#define MAX_LENGTH 16

using namespace System;

ref class VariableTargetGene :
public Gene
{
private:
	String^ myTarget;
	int myPopulationSize;
public:
	VariableTargetGene(Random^ rand, String^ target, int populationSize);

	virtual void deriveFitness(Chromosome^ c) override;
	virtual void mutate(Chromosome^ %c) override;
	virtual Chromosome^ buildChromosome() override;

	void setTarget(String^ target)	{ myTarget = target; }
	String^ getTarget()				{ return myTarget; }
};
