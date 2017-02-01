#pragma once
#include "gene.h"
#include "Chromosome.h"

#define BASE_SCORE 200
#define POINT_MOD 5
#define CHROM_PARTS 4

using namespace System;

ref class SumGene :
public Gene
{
private:
	int myTargetValue;		// the target value for a chromosome.  Used to determine fitness.
	int myMaxPartValue;		// the max value that a chromosome part can hold.
public:
	SumGene(Random^ rand, int populationSize, int targetValue);

	virtual array<Chromosome^>^ reproduce(Chromosome^ a, Chromosome^ b) override;
	virtual void deriveFitness(Chromosome^ c) override;
	virtual void mutate(Chromosome^ %c) override;
	virtual Chromosome^ buildChromosome() override;
};
