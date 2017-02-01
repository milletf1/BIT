#include "StdAfx.h"
#include "Animal.h"

Animal::Animal()
{}

Animal::Animal(int id, String^ name, String^ species, int cageNumber, int age, String^ food)
{
	ID = id;
	Name = name;
	Species = species;
	CageNumber = cageNumber;
	Age = age;
	Food = food;
}
