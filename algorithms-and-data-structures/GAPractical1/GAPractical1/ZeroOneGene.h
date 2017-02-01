#pragma once
#include "Gene.h"

#define CHROM_LENGTH 16
#define POP_SIZE 20

ref class ZeroOneGene :
public Gene
{
public:
	ZeroOneGene(Random^ rand);

	virtual void deriveFitness(Chromosome^ c) override;
	virtual void mutate(Chromosome^ %c) override; 
	virtual Chromosome^ buildChromosome() override; 
};

