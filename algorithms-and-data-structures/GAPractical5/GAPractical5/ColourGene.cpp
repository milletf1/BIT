#include "StdAfx.h"
#include "ColourGene.h"

ColourGene::ColourGene(Random^ rand, int populationSize, String^ targetValue)
:Gene(rand, populationSize)
{
	myTargetValue = targetValue;
	initPopulation();
}

/*************************************************************************************************
 * Precondition:  Chromosome a and b must have been initialized and contain a value of the correct
 *                format (r:g:b, where rgb represent red, blue, and green color values).
 *
 * Postcondition: Produces and returns two new chromosomes using the values of the 
 *				  given chromosomes.
 *************************************************************************************************/
array<Chromosome^>^ ColourGene::reproduce(Chromosome^ a, Chromosome^ b)
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
	int splitPoint = myRandom->Next(RGB - 1);

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

/*********************************************************************************************
 * Precondition:  The chromosome parameter must have contain a chromosome value of the correct
 *                format (r:g:b, where rgb represent red, blue, and green color values).
 *
 * Postcondition: Determines the fitness of the given chromosome.
 *********************************************************************************************/
void ColourGene::deriveFitness(Chromosome^ c)
{
	// determine the maximum possible fitness score.
	int fitness = COLOR_MAX * RGB;
	int scoreModifier = 0;

	// get the rgb colour values from the target and actual chromosome.
	array<String^>^ rgbTarget = myTargetValue->Split(':');
	array<String^>^ rgbActual = c->getValue()->Split(':');
	
	for(int i = 0; i < RGB; i++)
	{
		int targetValue = Convert::ToInt16(rgbTarget[i]);
		int actualValue = Convert::ToInt16(rgbActual[i]);

		// determine the score modifier by calculating the difference between the target 
		// and actual value.
		int modifier = (targetValue > actualValue)?
			targetValue - actualValue : actualValue - targetValue;

		scoreModifier += modifier;
	}
	fitness -= scoreModifier;
	c->setFitness(fitness);
}

/*****************************************************************************
 * Precondition:  Chromosome c must have been initialized and contain a value.
 *
 * Postcondition: Mutates a chromosome by giving a char a new value.
 *****************************************************************************/
void ColourGene::mutate(Chromosome^ %c)
{
	// determine a random mutation point.
	int mutatePoint = myRandom->Next(RGB);

	// determine a random mutation value.
	int mutateValue = myRandom->Next(COLOR_MAX);
	array<String^>^ rgbArray = c->getValue()->Split(':');

	// mutate a chromosome.
	rgbArray[mutatePoint] = Convert::ToString(mutateValue);
	String^ newValue = rgbArray[0] + ":" + rgbArray[1] + ":" + rgbArray[2];
	
	c->setValue(newValue);
}

/**************************************************************
 * Precondition:  
 *
 * Postcondition: Creates a new chromosome and sets its value.
 *************************************************************/
Chromosome^ ColourGene::buildChromosome()
{
	// set integer values used for color.
	int r = myRandom->Next(COLOR_MAX);
	int g = myRandom->Next(COLOR_MAX);
	int b = myRandom->Next(COLOR_MAX);
	
	// create a color string.
	String^ red = Convert::ToString(r);
	String^ green = Convert::ToString(g);
	String^ blue = Convert::ToString(b);
	String^ value =  red + ":" + green + ":" + blue;

	// create a new chromosome with the color string value.
	Chromosome^ c = gcnew Chromosome();
	c->setValue(value);

	return c;
}

/***********************************************************************
 * Precondition:  
 *
 * Postcondition: Returns the chromosome with the highest fitness value.
 ***********************************************************************/
Chromosome^ ColourGene::getBest()
{	
	orderByFitness();		
	return myChromosomes[0];
}
