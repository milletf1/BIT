#pragma once
#include "Animal.h"

#define INDEX 0
#define NAME 1
#define SPECIES 2
#define CAGE 3
#define AGE 4
#define FOOD 5

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

ref class Table
{
protected:
	
	array<Animal^>^ animalArray;
	RichTextBox^ dbOutput;
	RichTextBox^ animalOutput;

public:
	Table(RichTextBox^ db, RichTextBox^ animal);

	void loadFromFile(String^ filePath);
	void displayTable();	
	void displayItem(int key);

	bool findItem(int key);
};
