#pragma once
#include "TileMap.h"
#include "TileMapList.h"
#include "TileList.h"
#include "Goblin.h"
#include "Ninja.h"
#include "Sprite.h"
#include "Shuriken.h"

#define	GOBLIN_DRAW_WIDTH 32
#define	GOBLIN_DRAW_HEIGHT 32
#define GOBLIN_DRAW_OFFSET_X 0
#define GOBLIN_DRAW_OFFSET_Y 0
#define GOBLIN_HITBOX_WIDTH 30
#define GOBLIN_HITBOX_HEIGHT 32
#define GOBLIN_XVEL 4

#define TILE_SIZE 32
#define MAP_TILE_SIZE 20
#define SCREEN_SIZE 640

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//*******************************************************************************************
//GoblinList is a linked list that is responsible for creating, storing, deleting, and giving 
//commands to the goblins that inhabit the game world.
//*******************************************************************************************
ref class GoblinList
{
private:
	Goblin^ head;
	Goblin^ tail;
	Random^ rand;
public:
	//constructor
	GoblinList(Random^ sRand);

	//functions
	int Count();
	void GenerateGoblins(int mapType, int mapYLat, Graphics^ canvas);
	void AddGoblin(Goblin^ nGoblin);
	void PerformListUpkeep(int waterLevel);
	void DeleteGoblin(Goblin^ dGoblin);
	void DrawGoblins(int mapYLat);
	void PerformGoblinActions(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite);
	void UpdateGoblinState();
	void CheckShurikenHit(array<Shuriken^>^ shurikenArray);
};
