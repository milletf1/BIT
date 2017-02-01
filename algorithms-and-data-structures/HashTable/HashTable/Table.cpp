#include "StdAfx.h"
#include "Table.h"

Table::Table(RichTextBox^ db, RichTextBox^ animal)
{
	dbOutput = db;
	animalOutput = animal;

	animalArray = gcnew array<Animal^>(100);
	System::Diagnostics::Debug::WriteLine("finish Table");
}

/*************************************************************
 * Precondition:  The filePath parameter must point to a file.
 *
 * Postcondition: Loads animalArray with animals.
 *************************************************************/
void Table::loadFromFile(String^ filePath)
{
	StreamReader^ sr = gcnew StreamReader(filePath);
	
	// Iterate through each line in the given file, adding its animal data 
	// to the database.
	String^ line = sr->ReadLine();
	while(line != nullptr) 
	{
		// Parse the animal's data properties.
		array<String^>^ animalData = line->Split(',');
		Animal^ a = gcnew Animal;

		// Add animal data to database.
		a->ID = Convert::ToInt16(animalData[INDEX]);
		a->Name = animalData[NAME];
		a->Species = animalData[SPECIES];
		a->CageNumber = Convert::ToInt16(animalData[CAGE]);
		a->Age = Convert::ToInt16(animalData[AGE]);
		a->Food = animalData[FOOD];

		animalArray[a->ID] = a;

		// Read the next line in the given file.
		line = sr->ReadLine();
	}
	sr->Close();
}

/*****************************************************************************************
 * Precondition:  
 *
 * Postcondition: Displays the properties of each animal in animalArray in a rich textbox.
 *****************************************************************************************/
void Table::displayTable()
{
	// dbOutput textbox header.
	String^ dbDisplay = "ID\tName\tSpecies\t\tCage Number\tAge\tFood\n";

	// Display the data of each animal in the dbOutput textbox.
	dbOutput->Clear();
	for(int i = 0; i < animalArray->Length; i++)
	{
		if(animalArray[i] != nullptr)
		{
			dbDisplay += Convert::ToString(animalArray[i]->ID) + "\t" +
				       animalArray[i]->Name + "\t" +
					   animalArray[i]->Species+ "\t\t" +
					   Convert::ToString(animalArray[i]->CageNumber) + "\t" +
					   Convert::ToString(animalArray[i]->Age) + "\t" +
					   animalArray[i]->Food+ "\n";
		}
	}
	dbOutput->Text = dbDisplay;
}

/**************************************************************************************
 * Precondition:  
 *
 * Postcondition: Checks if there is an animal with an ID equal to key in the database.
 **************************************************************************************/
bool Table::findItem(int key)
{
	return animalArray[key] != nullptr;
}

/*******************************************************************************************
 * Precondition:  The animalArray must hold an animal with an ID equal to the key parameter.
 *				  the key parameter must be within the bound of the animal array
 *				  (0 -> animalArray->Length - 1).
 *
 * Postcondition: Displays the animal that has an ID equal to the key parameter in a rich
 *				  text box.
 *******************************************************************************************/
void Table::displayItem(int key)
{
	// Get the animal with an ID equal to the given key.
	Animal^ a = animalArray[key];

	// Display the animals data in the animalOutput textbox.
	animalOutput->Clear();
	animalOutput->Text = "ID:         \t\t" + Convert::ToString(a->ID)
				       + "\nName:       \t" + a->Name 
					   + "\nSpecies:    \t" + a->Species
					   + "\nCage Number:\t" + Convert::ToString(a->CageNumber)
					   + "\nAge:        \t\t" + Convert::ToString(a->Age)
					   + "\nFood:       \t" + a->Food;
}