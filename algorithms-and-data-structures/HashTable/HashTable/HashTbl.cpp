#include "StdAfx.h"
#include "HashTbl.h"

HashTbl::HashTbl(RichTextBox^ db, RichTextBox^ animal) : Table(db, animal)
{
	animalArray = gcnew array<Animal^>(ARRAY_LENGTH);
}

/************************************************************************************
 * Precondition:  The animal parmeter must be initialized and have and ID property.
 *
 * Postcondition: Inserts the given animal into the animalArray using double hashing.
 ************************************************************************************/
void HashTbl::insertItem(Animal^ a)
{	
	int probe = h1(a->ID);

	if(animalArray[probe] == nullptr)
		animalArray[probe] = a;
	else
	{
		int startPoint = probe;
		int offset = h2(a->ID);

		probe = (probe + offset) % ARRAY_LENGTH;

		while(animalArray[probe] != nullptr && probe != startPoint)	
			probe = (probe + offset) % ARRAY_LENGTH;

		if(animalArray[probe] == nullptr)
			animalArray[probe] = a;
	}
}

/************************************************************************************
 * Precondition:  
 *
 * Postcondition: Searches for and returns the animal in the animalArray with an ID
 *				  equal to the key parameter and writes the probe sequence to the
 *				  probeSequence string.
 ************************************************************************************/
Animal^ HashTbl::findItem(int key)
{
	int probe = h1(key);	
	probeSequence = Convert::ToString(probe) + "\n";
	Animal^ a = nullptr;

	if(animalArray[probe] != nullptr && animalArray[probe]->ID == key)
		a = animalArray[probe];

	else if(animalArray[probe] != nullptr)
	{
		int firstProbe = probe;

		int offset = h2(key);

		probe = (probe + offset) % ARRAY_LENGTH;
		probeSequence += Convert::ToString(probe) + "\n";

		while(animalArray[probe] != nullptr && animalArray[probe]->ID != key
			&& probe != firstProbe)	
		{
			probe = (probe + offset) % ARRAY_LENGTH;
			probeSequence += Convert::ToString(probe) + "\n";
		}

		if(animalArray[probe] != nullptr && animalArray[probe]->ID == key)
			a = animalArray[probe];
	}
	return a;
}
