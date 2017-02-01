#pragma once
#include "Chromosome.h"

#define DEFAULT_POPULATION 4	// default population size.
#define DEFAULT_KEEP .5			// default percent of population to keep between generations.
#define DEFAULT_ELITE 1			// default number of chromosomes that have elitisim.
#define DEFAULT_MUTATION 10		// default chance of a chromosome mutating (percent chance).
#define DEFAULT_CHROM_LENGTH 9	// default char length of a chromosome
#define BASE_POINTS 10			// number of points used to derive fitness.

using namespace System;

ref class Gene
{
protected:
	int myChromosomeLength;
	array<Chromosome^>^ myChromosomes;
	int myPopulationSize;
	int myElite;
	double myMutationChance;
	double myKeepPercent;
	int myCurrentGeneration;

	Random^ myRandom;

	void initPopulation();	

	array<Chromosome^>^ selectBreedingPair(int breedingChromosomes);
	void orderByFitness();

	virtual array<Chromosome^>^ reproduce(Chromosome^ a, Chromosome^ b);		
	virtual void deriveFitness(Chromosome^ c);
	virtual void mutate(Chromosome^ %c); 
	virtual Chromosome^ buildChromosome(); 

public:	
	void nextGeneration();
	void reset() { initPopulation(); }
	// constructors
	Gene(Random^ rand);
	Gene(Random^ rand, int populationSize);
	Gene(Random^ rand, int populationSize, double keepPercent);
	Gene(Random^ rand, int populationSize, int elite);
	Gene(Random^ rand, double mutationChance, int populationSize);
	Gene(Random^ rand, int populationSize, int elite, double keepPercent, double mutationChance);

	// getters and setters.

	int getPopulationSize()							{ return myPopulationSize; }
	void setPopulationSize(int populationSize)		{ myPopulationSize = populationSize; }

	int getElite()									{ return myElite; }
	void setElite(int elite)						{ myElite = elite; }

	double getMutationChance()						{ return myMutationChance; }
	void setMutationChance(double mutationChance)	{ myMutationChance = mutationChance; }

	double getKeepPercent()							{ return myKeepPercent; }
	void setKeepPercent(double keepPercent)			{ myKeepPercent = keepPercent; }

	int getCurrentGeneration()						{ return myCurrentGeneration; }

	array<Chromosome^>^ getChoromosomes()			{ return myChromosomes; }
	
	int getChromosomeLength()						{ return myChromosomeLength; }
	void setChromsomeLength(int chromosomeLength)	{ myChromosomeLength = chromosomeLength; }
};
