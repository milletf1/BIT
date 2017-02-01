#include "StdAfx.h"
#include "ZeroOneGene.h"

ZeroOneGene::ZeroOneGene(Random^ rand) : Gene(rand)
{
	myChromosomeLength = CHROM_LENGTH;
	myPopulationSize = POP_SIZE;
	initPopulation();
}

/*****************************************************************************
 * Precondition:  Chromosome c must have been initialized and contain a value.
 *
 * Postcondition: Mutates a chromosome by giving a switching between 0 and 1.
 *****************************************************************************/
void ZeroOneGene::mutate(Chromosome^ %c)
{	
	String^ value = c->getValue();
	// choose a random point to mutate.
	int mutatePoint = myRandom->Next(myChromosomeLength);
	
	// chose a random integer to mutate into.
	int mutateValue = (Convert::ToInt16(value[mutatePoint]) + 1) % 2;
	
	// perform mutation.
	value = value->Substring(0, mutatePoint) + Convert::ToString(mutateValue) + value->Substring(mutatePoint + 1);	
	c->setValue(value);
}

/**************************************************************
 * Precondition:  
 *
 * Postcondition: Creates a new chromosome and sets its value.
 *************************************************************/
Chromosome^ ZeroOneGene::buildChromosome() 
{ 
	String^ chromosomeValue = "";

	for(int i = 0; i < myChromosomeLength; i ++)
		chromosomeValue += Convert::ToString(myRandom->Next(100) % 2);
	
	Chromosome^ c = gcnew Chromosome();

	c->setValue(chromosomeValue);
	return c;  
}

/********************************************************************
 * Precondition:  The chromosome parameter must have contain a value.
 *
 * Postcondition: Determines the fitness of the given chromosome.
 ********************************************************************/
void ZeroOneGene::deriveFitness(Chromosome^ c)
{
	int fitness = 0;				// fitness value.
	int correctMod = 1;				// modifier used to determine the points to add to fitness.
	String^ value = c->getValue();	// chromosome value.

	// iterate through each char in the chromosome value.
	for (int i = 0; i < value->Length; i++)
	{
		String^ target = Convert::ToString(i % 2);		// get target chromosome value.
		String^ actual = Convert::ToString(value[i]);	// get actual chromosome value.

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