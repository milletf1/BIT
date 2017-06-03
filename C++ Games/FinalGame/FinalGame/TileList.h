#pragma once
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//****************************************************************************************
//TileList is a storage array for all the tiles in the game.  The TileMap class holds a 2d 
//integer array which refers to a  tile in tileArray
//****************************************************************************************
ref class TileList
{
private:
	array<Tile^>^ tileArray;

public:
	//constructor
	TileList(int sTiles);
	
	//functions 
	Bitmap^ getTileBitmap(int index) {return tileArray[index]->getTileBitmap();}
	bool getIsSolidObject(int index) {return tileArray[index]->getIsSolidObject();}
	void setTileArrayEntry(int index, Tile^ newTile) {tileArray[index] = newTile;}
};
