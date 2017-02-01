#include "StdAfx.h"
#include "QueenGene.h"

QueenGene::QueenGene(Random^ rand, int populationSize) 
: Gene(rand, populationSize)
{
	problemSolved = false;
}

/*
 * Precondition: 
 *
 * Postcondition: 
 */
void QueenGene::reset()
{
	problemSolved = false;
	initPopulation();
}

/*
 * Precondition: 
 *
 * Postcondition: 
 */
void QueenGene::solveProblem()
{
	while(!problemSolved && myCurrentGeneration < MAX_GENERATIONS)
		nextGeneration();
}

/************************************************************************************
 * Precondition:  The chromosome parameter must have contain a value
 *				  that confirms to the chromsome standard.  The values of each part,
 *				  must be convertable to an integer, and each part seperated by a 
 *				  colon.
 *
 * Postcondition: Derives chromosome fitness by comparing each queen (curQueen) to 
 *			      the position of earlier queens in the chromosome (prevQueen) to 
 *				  check if they can attack each other. The chromosome's fitness score 
 *				  is reduced for each possible attack.
 ************************************************************************************/
void QueenGene::deriveFitness(Chromosome^ c) 
{
	int fitness = BASE_SCORE;
	int scoreModifier = 0;

	// put values contained in chromosome string into an array
	array<String^>^ queens = c->getValue()->Split(':');

	// check if the queen values in the queens array can perform attacks on each other.
	for(int curQueen = 1; curQueen < queens->Length; curQueen++)
	{
		for(int prevQueen = curQueen - 1; prevQueen >= 0; prevQueen--)
		{
			// get integer values of the two queens that we are comparing.
			int aQueen = Convert::ToInt16(queens[curQueen]);
			int bQueen = Convert::ToInt16(queens[prevQueen]);

			// Modifier used to determine if the queens are facing each other diagonally.
			int diagMod = curQueen - prevQueen;	

			// check if the queens occupy the same column.
			if(aQueen == bQueen)
			{
				// deduct points if they do.
				scoreModifier += POINT_MOD;
			}
			// check if the queens can attack each other diagonally.
			if(bQueen == aQueen - diagMod || 
				bQueen == aQueen + diagMod)
			{
				// deduct points if they do.
				scoreModifier += POINT_MOD;
			}
		}
	}
	// determine the final score.
	fitness -= scoreModifier;

	// set problemSolved to true if this fitness is a perfect score (BASE_SCORE).
	if(fitness == BASE_SCORE)
		problemSolved = true;

	c->setFitness(fitness);
}

/**************************************************************
 * Precondition:  
 *
 * Postcondition: Creates a new chromosome and sets its value.
 *************************************************************/
Chromosome^ QueenGene::buildChromosome()
{
	Chromosome^ c = gcnew Chromosome();
	String^ value = "";

	// add random column placements to the chromosome value.
	for(int i = 0; i < NQUEENS; i++)
	{
		int colValue = myRandom->Next(1, NQUEENS + 1);
		value += Convert::ToString(colValue) + ":";
	}	
	// remove the last colon from value.
	value = value->TrimEnd(':');

	c->setValue(value);
	
	return c;
}
/**********************************************************************************
 * Precondition:  The chromosome parameter must have contain a value
 *				  that confirms to the chromsome standard.  The values of each part,
 *				  must be convertable to an integer, and each part seperated by a 
 *				  colon.
 *
 * Postcondition: Mutates a chromosome by giving one of the chromsome parts a new 
 *				  integer value.
 **********************************************************************************/
void QueenGene::mutate(Chromosome^ %c)
{
	// String used to store new chromosome value.
	String^ value = "";
	// parse the parts of the chromsome.
	array<String^>^ queens = c->getValue()->Split(':');
	
	// determine the part to mutate.
	int mutatePoint = myRandom->Next(NQUEENS);

	// determine the new value of the mutated part.
	int partValue = myRandom->Next(1, NQUEENS + 1);

	// add the change the mutate point part of the queens array to the new value
	queens[mutatePoint] = Convert::ToString(partValue);

	// create a new chromosome value using the mutated part.
	for(int i = 0; i < NQUEENS; i++)
		value += queens[i] + ":";

	// remove the last colon from value.
	value = value->TrimEnd(':');
	
	c->setValue(value);
}

array<Chromosome^>^ QueenGene::reproduce(Chromosome^ a, Chromosome^ b)
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