#include "StdAfx.h"
#include "Testing.h"

Testing::Testing(SortWorker^ sw)
{
	mySortWorker = sw;	
}
String^ Testing::runTest()
{	
	String^ fileText = FILE_HEADER;	
	
	fileText += runIteration(ITERATION_1);
	fileText += runIteration(ITERATION_2);
	fileText += runIteration(ITERATION_3);
	fileText += runIteration(ITERATION_4);
	fileText += runIteration(ITERATION_5);
	fileText += runIteration(ITERATION_6);
	fileText += runIteration(ITERATION_7);

	return fileText;	
}

String^ Testing::runIteration(int n)
{
	String^ output = n + ",";
		
	output += Convert::ToString(runBubbleSort(n)) + ",";
	output += Convert::ToString(runInsertionSort(n)) + ",";
	output += Convert::ToString(runSelectionSort(n)) + ",";
	output += Convert::ToString(runMergeSort(n)) + "\r\n";
	
	return output;
}

int Testing::runBubbleSort(int n)
{
	mySortWorker->setIntArraySize(n);
	mySortWorker->bubbleSort();
	return mySortWorker->getCount();  
}

int Testing::runInsertionSort(int n)
{ 
	mySortWorker->setIntArraySize(n);
	mySortWorker->insertionSort();
	return mySortWorker->getCount();  
}

int Testing::runSelectionSort(int n)
{ 
	mySortWorker->setIntArraySize(n);
	mySortWorker->selectionSort();
	return mySortWorker->getCount();  
}

int Testing::runMergeSort(int n)
{ 
	mySortWorker->setIntArraySize(n);
	mySortWorker->mergeSort();
	return mySortWorker->getCount(); 
}