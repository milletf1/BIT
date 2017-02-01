#pragma once
#include "Table.h"
#include "Animal.h"

#define ARRAY_LENGTH 127
#define STEP 31

using namespace System;
using namespace System::Windows::Forms;

ref class HashTbl :
public Table
{
private:
	String^ probeSequence;
public:
	HashTbl(RichTextBox^ db, RichTextBox^ animal);

	String^ getProbeSequence() { return probeSequence; }

	void insertItem(Animal^ a);
	Animal^ findItem(int key);

	int h1(int k) { return k % ARRAY_LENGTH; }		// Function to determine the probe.
	int h2(int k) { return STEP - (k % STEP); }		// Function to determine the offset.
};
