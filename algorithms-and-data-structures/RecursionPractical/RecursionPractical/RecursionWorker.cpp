#include "StdAfx.h"
#include "RecursionWorker.h"

RecursionWorker::RecursionWorker()
{}

/************************************************************************
 * Precondition:  The string parameter must not be empty.
 *
 * Postcondition: Takes a string as a parameter and returns it in reverse 
 *				  order.
 ************************************************************************/		
String^ RecursionWorker::reverseIt(String^ s)
{ 	
	if(s->Length == 1)
		return s;	
	
	else
		return s->Substring(s->Length -1) + reverseIt(s->Substring(0, s->Length -1)); 	
}

/***********************************************************************************
 * Precondition:  The string parameter s must not be empty.  The string parameter
 *                ch must contain exactly one char.
 *
 * Postcondition: Takes two string parameters, s and ch.  Removes the char specified
 *                by ch from string s and returns string s.
 ***********************************************************************************/		
String^ RecursionWorker::removeIt(String^ ch, String^ s)
{ 
	
	if(s->Length == 1)
		return (s->CompareTo(ch) == 0) ? "" : s;
	
	else
	{
		String^ s0 = (s->Substring(0,1)->CompareTo(ch) == 0)? "" : s->Substring(0,1);
		return s0 + removeIt(ch, s->Substring(1)); 
	}
}

/***********************************************************************************
 * Precondition:  The string parameter must not be empty.
 *
 * Postcondition: Checks if the given string is a palindrome.  Returns true if it is 
 *                and false if it isn't.
 ***********************************************************************************/	
bool RecursionWorker::palindrome(String^ s)
{ 
	if(s->Length == 1 || s->Length == 2)
	{
		return (s->Length == 1)? 
			true : s->Substring(0,1)->CompareTo(s->Substring(1)) == 0;
	}
	else
		return palindrome(s->Substring(1, s->Length -2)) && 
			( s->Substring(0,1)->CompareTo(s->Substring(s->Length -1)) == 0 ); 
}

/******************************************************************************
 * Precondition:  The double parameter n must be at greater than or equal to 1.
 *
 * Postcondition: Returns the sum of all integers up to and including parameter
 *                n.
 ******************************************************************************/	
int RecursionWorker::sumToN(int n)
{ 
	if(n == 1)
		return n;
	else	
		return n + (n - 1); 
}
/******************************************************************************
 * Precondition:  
 *
 * Postcondition: Returns a boolean that indicates if parameter n is a perfect
 *                power of 3.
 ******************************************************************************/
bool RecursionWorker::powerOfThree(double n)
{
	if(n < 3)
		return n == 1;
	else
		return  powerOfThree(n / 3);
}

/***********************************************************************************
 * Precondition:  lBound must be smaller than uBound.  uBound must refer to the last 
 *                array index.  intArray must be sorted in ascending order.
 *
 * Postcondition: Performs a binary search for target in the given array.
 **********************************************************************************/
bool RecursionWorker::binarySearch(array<int>^ intArray, int lBound, int uBound, int target)
{
	//Base case checks if we are down to one or two possible index positions to search.
	if(uBound - lBound == 1)

		//Search index positions defined by lBound and uBound for the target.
		return intArray[lBound] == target || intArray[uBound] == target;

	else if(uBound - lBound == 0)

		//Search lBound for the target (uBound refers to the same position).
		return intArray[lBound] == target;

	else
	{
		//Get the index position in the middle of uBound and lBound.
		int mid =  ( uBound + lBound ) / 2;

		//Return true if the int in the mid position is the target.
		if(intArray[mid] == target)
			return true;

		else
		{
			//If the int defined by the mid is smaller than the target, search up.
			if(intArray[mid] < target)
				return binarySearch(intArray, mid, uBound, target);
			
			//If the int defined by the mid is larger than the target, search down.
			else
				return binarySearch(intArray, lBound, mid, target);	
		}
	}
}

/******************************************************************************************
 * Precondition:  The length of the intArray must conform to n=2k.  The lower param must be  
 *                inclusive.  The upper param must be exclusive. Lower must be less than 
 *                upper.
 *
 * Postcondition: Sorts and returns an array of random integers.
 *****************************************************************************************/
void RecursionWorker::mergeSortV2(array<int>^ arr, int lower, int upper)
{
	//Base case checks if the boundaries defined by upper and lower refer to two integers.
	if( (upper - lower) == 2)
	{
		//Order the two values defined by upper and lower.
		if(arr[lower] > arr[upper - 1])
		{
			int temp = arr[lower];
			arr[lower] = arr[upper - 1];
			arr[upper - 1] = temp;
		}
	}
	else
	{
		//Determine the mid point between upper and lower.
		int mid = ( upper + lower ) / 2;	
		
		//Perform a merge sort on both halves of the array.
		mergeSortV2(arr, lower, mid);				
		mergeSortV2(arr, mid, upper);

		//Merge the "piles" of the array/
		mergePilesV2(arr, lower, mid, upper);
	}
}

/*********************************************************************************************
 * Precondition:  Lower must be less than mid. mid must be less than upper.
 *
 * Postcondition: Builds an array by merging two sections of the given array.  The sections  
 *                are defined as the index value between lower(inclusive) and mid(exclusive),
 *                and mid(inclusive) and upper(exclusive).  The sorted array is then copied
 *                back into the given array starting at index lower.
 ********************************************************************************************/
void RecursionWorker::mergePilesV2(array<int>^ arr, int lower, int mid, int upper)
{
	array<int>^ tempArray = gcnew array<int>(upper - lower);

	//Remember the start index of the array that this merge function is working with.
	int lowerBuffer = lower;
	int midBuffer = mid;
	int upperBuffer = upper;

	//Perform merge.
	for(int i = 0; i < tempArray->Length; i++)
	{	
		//Copy the upper section if the lower section has reached its end.
		if(lower == midBuffer)
		{
			tempArray[i] = arr[mid];		
			mid++;
		}
		//Copy the lower section if the upper section has reached its end.
		else if(mid == upperBuffer)
		{
			tempArray[i] =  arr[lower];
			lower++;
		}
		//Copy lower if its int is smaller than or equal to the next int in the upper section.
		else if(arr[lower] <= arr[mid])
		{
			tempArray[i] = arr[lower];
			lower++;
		}
		//If we are at this point, copy the int from the upper section.
		else
		{
			tempArray[i] = arr[mid];
			mid++;
		}
	}
	//Copy values from tempArray to the main array.
	for(int j = 0 ; j < tempArray->Length; j++)
	{
		arr[lowerBuffer] = tempArray[j];
		lowerBuffer++;
	}
}