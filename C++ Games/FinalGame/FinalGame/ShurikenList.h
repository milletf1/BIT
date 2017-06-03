#pragma once
#include "Shuriken.h"

#define SCREEN_SIZE 640

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//***********************************************************************************************
//ShurikenList is a linked list that is responsible for storing and deleting the shurikens thrown
//by the player in game.
//***********************************************************************************************
ref class ShurikenList
{
private:
	Shuriken^ head;
	Shuriken^ tail;
public:
	//constructor
	ShurikenList();

	//functions 
	int Count();
	void AddShuriken(Shuriken^ nShuriken);
	void DeleteShuriken(Shuriken^ dShuriken);
	array<Shuriken^>^ MakeArray();
	void PerformListUpkeep();
	void MoveShurikens();
	void DrawShurikens(int mapYLat);
};
