#include "StdAfx.h"
#include "SumGene.h"

SumGene::SumGene(Random^ rand, int populationSize, int targetValue)
:Gene(rand, populationSize)
{
	myTargetValue = targetValue;
	myMaxPartValue = targetValue / CHROM_PARTS;
	initPopulation();
}

/***********************************************************************************
 * Precondition:  Chromosome a and b must have been initialized and contain a value
 *				  that confirms to the chromsome standard (a:b:c:d).
 *
 * Postcondition: Produces and returns two new chromosomes using the values of the 
 *				  given chromosomes.
 ***********************************************************************************/
array<Chromosome^>^ SumGene::reproduce(Chromosome^ a, Chromosome^ b) 
{
	array<Chromosome^>^ children = gcnew array<Chromosome^>(2);	
	children[0] = gcnew Chromosome();
	children[1] = gcnew Chromosome();

	String^ childAValue = "";
	String^ childBValue = "";

	// get the parts from the parent chromosome.
	array<String^>^ aValues = a->getValue()->Split(':');
	array<String^>^ bValues = b->getValue()->Split(':');
	
	// determine the point to split each parent chromosome.
	int splitPoint = myRandom->Next(aValues->Length - 1);

	// create the first part of the children's chromosome value.
	for(int i = 0; i <= splitPoint; i++)
	{
		childAValue += aValues[i] + ":";
		childBValue += bValues[i] + ":";
	}

	// create the second part of the children's chromosome value.
	for(int i = splitPoint + 1; i < aValues->Length; i++)
	{
		childAValue += bValues[i] + ":";
		childBValue += aValues[i] + ":";
	}

	// strip the colon of the end of the new child strings.
	childAValue = childAValue->Substring(0, childAValue->Length - 1);
	childBValue = childBValue->Substring(0, childBValue->Length - 1);
	
	children[0]->setValue(childAValue);
	children[1]->setValue(childBValue);

	return children;
}
/*******************************************************************
 * Precondition:  The chromosome parameter must have contain a value
 *				  that confirms to the chromsome standard (a:b:c:d).
 *
 * Postcondition: Determines the fitness of the given chromosome.
 *				  this is done my subtracting the difference of the 
 *				  sum of the value parts from a base score.
 *******************************************************************/
void SumGene::deriveFitness(Chromosome^ c) 
{
	int scoreModifier;
	int fitness = BASE_SCORE;

	// determine the integer value of the chromosome parts.
	array<String^>^ numbers = c->getValue()->Split(':');
	int aNum = Convert::ToInt16(numbers[0]);
	int bNum = Convert::ToInt16(numbers[1]);
	int cNum = Convert::ToInt16(numbers[2]);
	int dNum = Convert::ToInt16(numbers[3]);
	int total = aNum + (bNum * 2) + (cNum * 3) + (dNum * 4);

	// determine the score.
	if(total > myTargetValue)
		scoreModifier = ( total - myTargetValue ) * POINT_MOD;
	else
		scoreModifier = ( myTargetValue - total ) * POINT_MOD;

	fitness -= scoreModifier;

	c->setFitness(fitness);
	
}
/*****************************************************************************
 * Precondition:  Chromosome c must have been initialized and contain a value.
 *				  that confirms to the chromsome standard (a:b:c:d).
 *
 * Postcondition: Mutates a chromosome by giving a char a new value.
 *****************************************************************************/
void SumGene::mutate(Chromosome^ %c) 
{
	// parse the parts of the chromsome.
	array<String^>^ chromosomeNumbers = c->getValue()->Split(':');

	// determine the part to mutate.
	int mutatePoint = myRandom->Next(chromosomeNumbers->Length);

	// determine the new value of the mutated part.
	int partValue = myRandom->Next(1, myMaxPartValue);

	// create a new chromosome value using the mutated part.
	chromosomeNumbers[mutatePoint] = Convert::ToString(partValue);
	String^ value = chromosomeNumbers[0] + ":" + chromosomeNumbers[1] + ":"
		+ chromosomeNumbers[2] + ":" + chromosomeNumbers[3];

	c->setValue(value);
}
/**************************************************************
 * Precondition:  
 *
 * Postcondition: Creates a new chromosome and sets its value.
 *************************************************************/
Chromosome^ SumGene::buildChromosome() 
{
	Chromosome^ c = gcnew Chromosome();

	// Create the chromosome parts.
	int part1 = myRandom->Next(1, myMaxPartValue);
	int part2 = myRandom->Next(1, myMaxPartValue);
	int part3 = myRandom->Next(1, myMaxPartValue);
	int part4 = myRandom->Next(1, myMaxPartValue);

	// Create the chromosome value.
	String^ value = Convert::ToString(part1) + ":"
		+ Convert::ToString(part2) + ":"
		+ Convert::ToString(part3) + ":"
		+ Convert::ToString(part4);

	c->setValue(value);

	return c;
}
