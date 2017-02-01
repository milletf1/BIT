#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class SortWorker
{
private:
	array<int>^ intArray;
	Random^ rand;
	int count;		//counts the operations of each algorithm.

	void generateDataSet();
	array<int>^ mergePiles(int leftIndex, int leftEnd, int rightIndex, int rightEnd);
public:
	
	int getCount() {return count;}

	SortWorker(int arrayLength, Random^ r);

	void setIntArraySize(int i) {intArray = gcnew array<int>(i); }

	array<int>^ selectionSort();
	array<int>^ insertionSort();
	array<int>^ bubbleSort();
	array<int>^ mergeSort();
};
