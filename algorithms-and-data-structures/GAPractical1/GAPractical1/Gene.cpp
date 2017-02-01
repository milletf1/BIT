#include "StdAfx.h"
#include "Gene.h"

/**
 * Constructors
 */
Gene::Gene(Random^ rand)
{	
	myChromosomeLength = DEFAULT_CHROM_LENGTH;
	myCurrentGeneration = 0;
	myRandom = rand;
	myPopulationSize = DEFAULT_POPULATION;
	myKeepPercent = DEFAULT_KEEP;
	myElite = DEFAULT_ELITE;
	myMutationChance = DEFAULT_MUTATION;
	initPopulation();
	System::Diagnostics::Debug::WriteLine("finished gene.");
}

Gene::Gene(Random^ rand, int populationSize)
{
	myChromosomeLength = DEFAULT_CHROM_LENGTH;
	myCurrentGeneration = 0;
	myRandom = rand;
	myPopulationSize = populationSize;
	myKeepPercent = DEFAULT_KEEP;
	myElite = DEFAULT_ELITE;
	myMutationChance = DEFAULT_MUTATION;

	initPopulation();
}

Gene::Gene(Random^ rand, int populationSize, double keepPercent)
{
	myChromosomeLength = DEFAULT_CHROM_LENGTH;
	myCurrentGeneration = 0;
	myRandom = rand;
	myPopulationSize = populationSize;
	myKeepPercent = keepPercent;
	myElite = DEFAULT_ELITE;
	myMutationChance = DEFAULT_MUTATION;

	initPopulation();
}
Gene::Gene(Random^ rand, int populationSize, int elite)
{
	myChromosomeLength = DEFAULT_CHROM_LENGTH;
	myCurrentGeneration = 0;
	myRandom = rand;
	myPopulationSize = populationSize;
	myKeepPercent = DEFAULT_KEEP;
	myElite = elite;
	myMutationChance = DEFAULT_MUTATION;

	initPopulation();
}
Gene::Gene(Random^ rand, double mutationChance, int populationSize)
{
	myChromosomeLength = DEFAULT_CHROM_LENGTH;
	myCurrentGeneration = 0;
	myRandom = rand;
	myPopulationSize = populationSize;
	myKeepPercent = DEFAULT_KEEP;
	myElite = DEFAULT_ELITE;
	myMutationChance = mutationChance;

	initPopulation();
}
Gene::Gene(Random^ rand, int populationSize, int elite, double keepPercent, double mutationChance)
{
	myChromosomeLength = DEFAULT_CHROM_LENGTH;
	myCurrentGeneration = 0;
	myRandom = rand;
	myPopulationSize = populationSize;
	myKeepPercent = keepPercent;
	myElite = elite;
	myMutationChance = mutationChance;

	initPopulation();
}
/**
 * End constructors.
 */

/***********************************************************************************
 * Precondition:  The myChromosome array must have been initialized an have a length
 *				  equal to my population size.
 *
 * Postcondition: Populates the myChromosome array with chromosomes.
 ***********************************************************************************/
void Gene::initPopulation()
{	
	myChromosomes = gcnew array<Chromosome^>(myPopulationSize);

	for(int i = 0; i < myPopulationSize; i++)
	{
		Chromosome^ c = buildChromosome();
		myChromosomes[i] = c;
	}
}

/********************************************************************
 * Precondition:  The chromosome parameter must have contain a value.
 *
 * Postcondition: Determines the fitness of the given chromosome.
 ********************************************************************/
void Gene::deriveFitness(Chromosome^ c)
{ 
	int fitness = 0;				// fitness value.
	int correctMod = 1;				// modifier used to determine the points to add to fitness.
	String^ value = c->getValue();	// chromosome value.

	// iterate through each char in the chromosome value.
	for (int i = 0; i < value->Length; i++)
	{
		String^ target = Convert::ToString(i);			// get target chromosome value.
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

/***********************************************************************************
 * Precondition:  Chromosome a and b must have been initialized and contain a value.
 *
 * Postcondition: Produces and returns two new chromosomes using the values of the 
 *				  given chromosomes.
 ***********************************************************************************/
array<Chromosome^>^ Gene::reproduce(Chromosome^ a, Chromosome^ b)
{
	array<Chromosome^>^ offspring = gcnew array<Chromosome^>(2);
	int splitPosition = myRandom->Next(1, myChromosomeLength - 2);	// determine the value split position.

	// create the first new chromosome value.
	String^ value = a->getValue()->Substring(0, splitPosition) + 
		b->getValue()->Substring(splitPosition);

	offspring[0] = gcnew Chromosome();
	offspring[0]->setValue(value);

	// create the second new chromosome value.
	value = b->getValue()->Substring(0, splitPosition) + 
		a->getValue()->Substring(splitPosition);

	offspring[1] = gcnew Chromosome();
	offspring[1]->setValue(value);

	return offspring;
}

/**************************************************************
 * Precondition:  
 *
 * Postcondition: Creates a new chromosome and sets its value.
 *************************************************************/
Chromosome^ Gene::buildChromosome()
{ 
	String^ chromosomeValue = "";

	for(int i = 0; i <= myChromosomeLength; i ++)
		chromosomeValue += Convert::ToString(myRandom->Next(10));

	Chromosome^ c = gcnew Chromosome();

	c->setValue(chromosomeValue);
	return c; 
}

/**************************************************************************************
 * Precondition:  The chromosome in array slot 0 should have the highest fitness value.
 *
 * Postcondition: Selects and returns two chromosomes for breeding.
 **************************************************************************************/
// TODO: write a better algorithm...
array<Chromosome^>^ Gene::selectBreedingPair(int breedingChromosomes)
{ 
	int total = 0;		// total value of all fitnesses
	int roll;			// roulette number roll.
	int otherParent;	// value used to store the value of the first selected parent.
	array<Chromosome^>^ pair = gcnew array<Chromosome^>(2);
	array<Chromosome^>^ eligibleParents = gcnew array<Chromosome^>(breedingChromosomes);

	// get the total fitness of all breeding candidates.
	for(int i = 0; i < breedingChromosomes; i++)
	{
		total += myChromosomes[i]->getFitness();
		eligibleParents[i] = myChromosomes[i];
	}

	for(int i = 0; i <= 1; i++)
	{
		// Check if we are selecting the second parent
		if(i == 1)
		{
			//if we are, remove the selected parent from the eligbleParents array.
			array<Chromosome^>^ tempChromosomes = gcnew array<Chromosome^>(breedingChromosomes - 1);
			int count = 0;

			for(int i = 0; i < eligibleParents->Length; i++)
			{
				if(otherParent != i)
				{
					tempChromosomes[count] = eligibleParents[i];
					count++;
				}
			}
		}
		roll = myRandom->Next(total);	// choose a random number.

		// check if the first chromosome in the myChromosome array was chosen.		
		if(roll <= eligibleParents[0]->getFitness())	
		{			
			pair[i] = eligibleParents[0];
			otherParent = 0;
			
		}
		// if the first chromosome wasnt chosen...
		else
		{		
			// determine a subtotal to check the roulette roll against.
			int subTotal = eligibleParents[0]->getFitness() + eligibleParents[1]->getFitness();
			int parentIndex = 1;			// the chromosome array index of the winner if the roll is under the subtotal.
			bool selectedParent = false;	// flag used to indicate if a parent has been selected.

			while(!selectedParent)
			{	
				// check if the roll is less than the subtotal.
				if(roll <= subTotal)
				{						
					selectedParent = true; 	
					// set otherParent to parentIndex if this is the first chromosome to be selected.
					if(i == 0)
						otherParent = parentIndex;	
				}	
				if(!selectedParent)
				{
					// increment parent index if we need to check next parent.
					parentIndex++;
					subTotal += eligibleParents[parentIndex]->getFitness();
				}
			}			
			pair[i] = eligibleParents[parentIndex];
		}
	}
	return pair; 
}

/*****************************************************************************
 * Precondition:  Chromosome c must have been initialized and contain a value.
 *
 * Postcondition: Mutates a chromosome by giving a char a new value.
 *****************************************************************************/
void Gene::mutate(Chromosome^ %c)
{
	// choose a random point to mutate.
	int mutatePoint = myRandom->Next(myChromosomeLength + 1);

	// chose a random integer to mutate into.
	String^ mutateValue = Convert::ToString(myRandom->Next(myChromosomeLength + 1));
	
	// perform mutation.
	String^ value = c->getValue();
	value = value->Substring(0, mutatePoint) + mutateValue + value->Substring(mutatePoint + 1);	
	c->setValue(value);
}

/**************************************************************************************************
 * Precondition:  the myChromosomes array must be initalized. every entry in the myChromosome array
 *			      must hold a chromosome with an initialized value.
 *
 * Postcondition: Performs the steps to breed a new generation.  This includes deriving fitness,
 *				  ordering by fitness, selecting eligible breeding pairs, reproducing, and mutating.
 **************************************************************************************************/
void Gene::nextGeneration()
{
	// dervice fitness of each chromosome.
	for(int i = 0; i < myChromosomes->Length; i++)
		deriveFitness(myChromosomes[i]);

	// sort chromosomes by fitness.
	orderByFitness();
	int breedingPopulation = myPopulationSize * myKeepPercent;

	// breed new population.
	for(int i = breedingPopulation; i < myPopulationSize; i += 2)
	{
		// select breeding pair.
		array<Chromosome^>^ pair = selectBreedingPair(breedingPopulation);

		// create new chromosomes.
		array<Chromosome^>^ offspring = reproduce(pair[0], pair[1]);

		// add new chromosomes to array.
		myChromosomes[i] = offspring[0];
		if(i + 1 < myPopulationSize)
			myChromosomes[i + 1] = offspring[1];
	}
	// mutate chromosomes.
	for(int i = 0 + myElite; i < myPopulationSize; i++)
	{		
		if(myRandom->Next(100) < myMutationChance)
			mutate(myChromosomes[i]);
	}
	myCurrentGeneration++;
}

/*************************************************************************************************
 * Precondition:  each chromosome in the myChromosome array must have a fitness value.
 *
 * Postcondition: sorts the chromosomes in the myChromosomes array by fitness in descending order.
 *************************************************************************************************/
void Gene::orderByFitness()
{
	// Iterate from the last array index down to array index 1.
	for(int putPoint = myChromosomes->Length - 1; putPoint > 0; putPoint--)
	{
		// smallestInt is used to determine the array index that contains the chromosome with the 
		// lowest fitness value.
		int smallestInt = 0;

		// Iterate from array index 1 (ignoring 0 since it is the starting value)
		// up to the index position defined by putPoint (the position we are placing the chromosome with
		// the lowest fitness value.
		for (int lookPoint = 1; lookPoint <= putPoint; lookPoint++)
		{
			// if the chromosome indexed by smallestInt is larger than the chromosome indexed by lookPoint
			// we set smallestInt to lookPoint.
			if(myChromosomes[smallestInt]->getFitness() > myChromosomes[lookPoint]->getFitness())
				smallestInt = lookPoint;
		}

		//put the chromosome with the smallest fitness value to current array end.
		Chromosome^ tempChromosome = myChromosomes[putPoint];
		myChromosomes[putPoint] = myChromosomes[smallestInt];
		myChromosomes[smallestInt] = tempChromosome;
	}
}