#pragma once
#include "PowerUp.h"
#include "Sprite.h"

#define TILE_SIZE 32
#define MAP_TILE_SIZE 20
#define SCREEN_SIZE 640

#define JET 0
#define SHURIKEN 1

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//****************************************************************************************************
//PowerUpList is a linked list that is responsible for creating, storing, deleting, and displaying the 
//various power-ups that appear in the game world.
//****************************************************************************************************
ref class PowerUpList
{
private:
	PowerUp^ head;
	PowerUp^ tail;
	Random^ rand;
public:
	//constructor
	PowerUpList(Random^ sRand);

	//functions 
	int Count();
	void GeneratePowerUp(int mapType, int mapYLat, Graphics^ canvas);
	void AddPowerUp(PowerUp^ nPowerUp);
	void PerformListUpkeep(int waterLevel);
	void DeletePowerUp(PowerUp^ dPowerUp);
	void DrawPowerUp(int mapYLat);
	void CheckCollision(Sprite^ player);
};
