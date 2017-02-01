#pragma once

using namespace System;

ref class Animal
{

public:	
	int ID;
	String^ Name;
	String^ Species;
	int CageNumber;
	int Age;
	String^ Food;

	Animal();
	Animal(int id, String^ name, String^ species, int cageNumber, int age, String^ food);
};
