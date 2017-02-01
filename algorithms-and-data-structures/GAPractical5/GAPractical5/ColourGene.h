#pragma once
#include "gene.h"
#include "Chromosome.h"

#define COLOR_MAX 256
#define RGB 3

using namespace System;

ref class ColourGene :
public Gene
{
private:
	String^ myTargetValue;

public:
	ColourGene(Random^ rand, int populationSize, String^ targetValue);

	virtual array<Chromosome^>^ reproduce(Chromosome^ a, Chromosome^ b) override;
	virtual void deriveFitness(Chromosome^ c) override;
	virtual void mutate(Chromosome^ %c) override;
	virtual Chromosome^ buildChromosome() override;

	Chromosome^ getBest();
};
