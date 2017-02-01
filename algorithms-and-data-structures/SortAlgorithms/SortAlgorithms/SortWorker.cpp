#include "StdAfx.h"
#include "SortWorker.h"

SortWorker::SortWorker(int arrayLength, Random^ r)
{
	intArray = gcnew array<int>(arrayLength); 
	rand = r;
}

/***************************************************************************************
 * Precondition:  
 *
 * Postcondition: Generates a random set of integers between 0 and 999, and puts them in 
 *                intArray.
 **************************************************************************************/
void SortWorker::generateDataSet()
{
	for(int i = 0; i < intArray->Length; i++)
	{
		int n = rand->Next(1000);
		intArray[i] = n;
	}
}

//SELECTION SORT
/*******************************************************************************************
 * Precondition:  The length of the intArray must be greater than 1.
 *
 * Postcondition: Generates a set of random numbers, selection sorts them, and returns them.
 ******************************************************************************************/
array<int>^ SortWorker::selectionSort()
{
	generateDataSet();	
	count = 0;

	// Iterate from the last array index down to array index 1.
	for(int putPoint = intArray->Length - 1; putPoint > 0; putPoint--)
	{
		count +=2; //Assignment and comparison of putpoint in the for loop.

		// Biggest int is used to keep track of the array index containing
		// the largest integer.
		count++; //Assigment of biggestInt.
		int biggestInt = 0;
		
		// Iterate from array index 1 (ignore 0 since we check it with biggestInt)
		// up to the index position defined by putPoint.
		for (int lookPoint = 1; lookPoint <= putPoint; lookPoint++)
		{
			count +=2; //Assignment and comparison of lookPoint in the for loop.

			count++; //Comparision of intArray[biggestInt] < intArray[lookPoint].
			if(intArray[biggestInt] < intArray[lookPoint])
			{
				count++;  //Assignment of biggestInt.
				biggestInt = lookPoint;
			}
		}
		
		// Place the largest integer found in the array index defined by putPoint.
		
		count +=3; //Assignment of tempInt, intArray[putPoint], and intArray[biggestInt].

		int tempInt = intArray[putPoint];
		intArray[putPoint] = intArray[biggestInt];
		intArray[biggestInt] = tempInt;
	}
	return intArray;
}

//INSERTION SORT
/*******************************************************************************************
 * Precondition:  The length of the intArray must be greater than 1.
 *
 * Postcondition: Generates a set of random numbers, insertion sorts them, and returns them.
 ******************************************************************************************/
array<int>^ SortWorker::insertionSort()
{
	generateDataSet();
	count = 0;

	// Iterate through intArray starting from the unsorted area of the array
	// (we assume that intArray[0] is already sorted).
	for(int i = 1; i < intArray->Length; i++)
	{
		count +=2; //Assignment and comparison of i in the for loop.
		
		count++; //Assignment of unsortedInt.
		int unsortedInt = intArray[i];
		
		// Iterate backwards through the sorted area of intArray.
		for(int sortedInt = i - 1; sortedInt >=0; sortedInt--)
		{
			count +=2;  //Assignment and comparison of sorted int.

			// If the unsorted in is smaller than the int defined by sortedInt,
			// move the int defined by sorted int to the right and place unsorted in
			// sortedInts position.
			count++; //Comparison of unsortedInt < intArray[sortedInt].
			if(unsortedInt < intArray[sortedInt])
			{
				count +=2; // Assignemt of intArray[sortedInt] and intArray[unsortedInt].
				intArray[sortedInt + 1] = intArray[sortedInt];
				intArray[sortedInt] = unsortedInt;
			}
		}
	}
	return intArray;
}

//BUBBLE SORT
/****************************************************************************************
 * Precondition:  The length of the intArray must be greater than 1.
 *
 * Postcondition: Generates a set of random numbers, bubble sorts them, and returns them.
 ***************************************************************************************/
array<int>^ SortWorker::bubbleSort()
{
	generateDataSet();
	count = 0;
		
	for(int j = intArray->Length - 1; j > 0; j--)
	{	
		count += 2; //Assignment and comparison of j.

		//Iterate through the intArray.
		for(int i = 0; i < j - 1; i++)
		{	
			count += 2; //Assignment and comparison of i.

			// If the int in array index i is greater than the int in array index i + 1, swap them.
			count++; //Comparison of intArray[i] > intArray[i + 1].
			if(intArray[i] > intArray[i + 1])
			{
				count +=3; //Assignment of tempInt, intArray[i], and intArray[i + 1].
				int tempInt = intArray[i];
				intArray[i] = intArray[i + 1];
				intArray[i + 1] = tempInt;
			}			
		}		
	}
	return intArray;
}

//MERGE SORT
/***************************************************************************************
 * Precondition:  The length of the intArray must conform to n=2k.
 *
 * Postcondition: Generates a set of random numbers, merge sorts them, and returns them.
 **************************************************************************************/
array<int>^ SortWorker::mergeSort()
{
	generateDataSet();

	// Set the size of the "sorted" sections to 1.	
	count = 1; //Assignment of pileSize.
	int pileSize = 1;

	while(pileSize < intArray->Length)
	{
		count ++; // Comparison in the while loop.

		// Iterate through each pair of sorted sections.
		for(int i = 0; i < intArray->Length; i += pileSize * 2)
		{	
			count +=2; //Comparision and assignment of i.

			// Define the area indexs that the left and right sections start (inclusive), and end (exclusive).
			count +=4; //Assignment of leftIndex, leftEnd, rightIndex, and rightEnd.
			int leftIndex = i;						
			int leftEnd = leftIndex + pileSize;		
			int rightIndex = i + pileSize;			
			int rightEnd = rightIndex + pileSize;	

			// Merge the left and right section.
			count++; //assignment of tempArray.
			array<int>^ tempArray = mergePiles(leftIndex, leftEnd, rightIndex, rightEnd);
			
			// Copy the merged sections to the int array.
			for(int j = 0 ; j < tempArray->Length; j++)
			{
				count +=4; //Assignment and comparison of j.  Assignment of intArray[leftIndex] and leftIndex.
				intArray[leftIndex] = tempArray[j];
				leftIndex++;
			}			
		}		
		// Prepare for next iteration by doubling the size of the sorted sections.
		count++; //Assignment of pileSize.
		pileSize *= 2;
	}
	count ++; // comparison in the while loop when it exits.
	return intArray;
}

/*******************************************************************************************
 * Precondition:  The value of leftEnd - leftIndex and rightEnd - rightIndex must be equal.
 *
 * Postcondition: builds and returns an array of sorted integers from integers stored in two 
 *                defined sections of the intArray.
 ******************************************************************************************/
array<int>^ SortWorker::mergePiles(int leftIndex, int leftEnd, int rightIndex, int rightEnd)
{
	// Define the size of the array that will store the merged sections.
	count++; //assignment of tempArray.
	array<int>^ tempArray = gcnew array<int>((leftEnd - leftIndex) + (rightEnd - rightIndex));
	
	// Iterate through the temp array.
	for(int x = 0; x < tempArray->Length; x++)
	{	
		count +=2; //Assignment and comparison of x.
		// Determine the section to retrieve the smallest integer from.
		 
		// If the left section has reached its end, use the right section.		
		if(leftIndex == leftEnd)
		{			
			count++; //comparison of leftIndex == leftEnd.

			count +=2; //Assignment of tempArray[x] and rightIndex. 
			tempArray[x] = intArray[rightIndex];
			rightIndex++;		
		}
		// If the right section has reached its end, use the left section.
		else if(rightIndex == rightEnd)
		{		
			count += 2; //comparison of leftIndex == leftEnd and rightIndex == rightEnd.

			count +=2; //Assignment of tempArray[x] and leftIndex. 
			tempArray[x] = intArray[leftIndex];
			leftIndex++;
		}
		// Add the int from the left section if smaller than the int in the right section.
		else if(intArray[leftIndex] < intArray[rightIndex])
		{		
			count += 3; //comparison of leftIndex == leftEnd, rightIndex == rightEnd, and intArray[leftIndex] < intArray[rightIndex].

			count +=2; //Assignment of tempArray[x] and leftIndex.
			tempArray[x] = intArray[leftIndex];
			leftIndex++;							
		}
		// Add the int from the right section if smaller than the int in the left section.
		else
		{
			count +=2; //Assignment of tempArray[x] and rightIndex.
			tempArray[x] = intArray[rightIndex];
			rightIndex++;			
		}
	}
	return tempArray;
}