#pragma once
#include "gene.h"
#include "Chromosome.h"

#define BASE_SCORE 200
#define POINT_MOD 2
#define NQUEENS 4
#define MAX_GENERATIONS 10000

using namespace System;

/**
 * README:
 *
 * A chromosome is presented as a string that contains integer values seperated by colons (e.g. 1:2:3:4).
 * Each integer value represents the column placement of the queen, while the integer values placement 
 * within the string determines the queen's row placement (1:2:3 = row 1, row 2 etc...).
 */

ref class QueenGene :
public Gene
{
private:
	bool problemSolved;
public:
	QueenGene(Random^ rand, int populationSize);

	void solveProblem();

	virtual void reset() override;

	virtual array<Chromosome^>^ reproduce(Chromosome^ a, Chromosome^ b) override;
	
	virtual void deriveFitness(Chromosome^ c) override;
	virtual void mutate(Chromosome^ %c) override;
	virtual Chromosome^ buildChromosome() override;

	bool getProblemSolved()			{ return problemSolved; }
	void setProblemSolved(bool b)	{ problemSolved = b; }

};
