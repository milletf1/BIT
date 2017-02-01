#pragma once
#include "SortWorker.h"

#define ITERATION_1 32
#define ITERATION_2 64
#define ITERATION_3 128
#define ITERATION_4 256
#define ITERATION_5 1024
#define ITERATION_6 2048
#define ITERATION_7 4096

using namespace System::IO;

ref class Testing
{
private:
	static String^ FILE_HEADER = "n,Bubble,Insertion,Selection,Merge\r\n";
	SortWorker^ mySortWorker;

	String^ runIteration(int n);
	int runBubbleSort(int n);
	int runInsertionSort(int n);
	int runSelectionSort(int n);
	int runMergeSort(int n);
public:
	Testing(SortWorker^ sw);
	String^ runTest();
};
