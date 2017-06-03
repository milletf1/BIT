#pragma once
#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//************************************************************************************
//TileMapList is a linked list that is responsible for storing and deleting the random 
//tile maps that make up the game world.
//************************************************************************************
ref class TileMapList
{
private:
	TileMap^ head;
	TileMap^ tail;
public:
	//constructor
	TileMapList();

	//functions 
	int Count();
	void AddTileMap(TileMap^ newTileMap);
	void DeleteTileMap(TileMap^ dMap);
	TileMap^ FetchMap(int mapIndex);
	bool FetchIsTileSolid(int mapIndex, TileList^ tileList, int tileX, int tileY);
	void PerformListUpkeep(int waterLevel);
};
