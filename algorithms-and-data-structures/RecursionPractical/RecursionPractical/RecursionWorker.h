#pragma once
using namespace System;
ref class RecursionWorker
{
public:
	RecursionWorker();

	String^ reverseIt(String^ s);
	String^ removeIt(String^ ch, String^s);
	
	bool palindrome(String^ s);
	bool powerOfThree(double n);
	bool binarySearch(array<int>^ intArray, int lBound, int uBound, int target);

	void mergeSortV2(array<int>^ arr, int lower, int upper);
	void mergePilesV2(array<int>^ arr, int lower, int mid, int upper);

	int sumToN(int n);
};
