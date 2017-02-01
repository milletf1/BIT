#include "StdAfx.h"
#include "VariableTargetGene.h"

VariableTargetGene::VariableTargetGene(Random^ rand, String^ target, int populationSize)
: Gene(rand, populationSize)
{
	myTarget = target->ToUpper();
	if(myTarget->Length > MAX_LENGTH)
		myTarget = myTarget->Substring(0, MAX_LENGTH);

	myChromosomeLength = target->Length;
	initPopulation();
}

/********************************************************************
 * Precondition:  The chromosome parameter must have contain a value.
 *
 * Postcondition: Determines the fitness of the given chromosome.
 ********************************************************************/
void VariableTargetGene::deriveFitness(Chromosome^ c)
{
	
	int fitness = 0;				// fitness value.
	double correctMod = 0.5;		// modifier used to determine the points to add to fitness.
	String^ value = c->getValue();	// chromosome value.

	// iterate through each char in the chromosome value.
	for (int i = 0; i < value->Length; i++)
	{
		Char^ target = myTarget[i];	// get target chromosome value.
		Char^ actual = value[i];	// get actual chromosome value.

		// check for a match between target and actual.
		if(target->CompareTo(actual) == 0)
		{
			// if there is a match, add points to fitness.
			fitness += (correctMod * BASE_POINTS);
			correctMod++;
		}
	}
	c->setFitness(fitness);
	
}

/*****************************************************************************
 * Precondition:  Chromosome c must have been initialized and contain a value.
 *
 * Postcondition: Mutates a chromosome by giving a char a new value.
 *****************************************************************************/
void VariableTargetGene::mutate(Chromosome^ %c)
{
	// choose a random point to mutate.
	int mutatePoint = myRandom->Next(myChromosomeLength);

	// chose a random integer to mutate into.
	Char^ mutateValue = static_cast<Char>(myRandom->Next(CHAR_A, CHAR_Z));
	
	// perform mutation.
	String^ value = c->getValue();
	value = value->Substring(0, mutatePoint) + mutateValue + value->Substring(mutatePoint + 1);	
	c->setValue(value);
}

/**************************************************************
 * Precondition:  
 *
 * Postcondition: Creates a new chromosome and sets its value.
 *************************************************************/
Chromosome^ VariableTargetGene::buildChromosome()
{
	Chromosome^ c = gcnew Chromosome();
	String^ chromosomeValue = "";

	for(int i = 0; i < myChromosomeLength; i ++)
	{
		Char^ nextChar = static_cast<Char>(myRandom->Next(CHAR_A, CHAR_Z));
		chromosomeValue += nextChar;
	}
	c->setValue(chromosomeValue);
	return c;
}
