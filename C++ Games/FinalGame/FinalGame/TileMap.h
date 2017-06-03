#pragma once

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//********************************************************************************************
//TileMap stores a 2d array of tile values that make up part of the game world.  The tile 
//values are references to TileList, which stores the bitmap and data on related to each tile.
//********************************************************************************************
ref class TileMap
{
private:

	//mapYLatitude is used to synchronize with the viewport when drawing the map.
	//mapNumber is used to refer to which map to draw from.
	int mapNumber, mapYLatitude;
	
	int mapTileHeight, mapTileWidth;
	array<int, 2>^ myMap;

public:	
	//constructor
	TileMap(int sMapNumber, int sMapYLatitude, int sMapTileHeight, int sMapTileWidth);
	
	//functions 
	void LoadMapFromFile(String^ fileName);	
	
	//get and sets
	int getMapYLatitude() {return mapYLatitude;}
	int getMapNumber() {return mapNumber;}
	int getTileValue(int x, int y){return myMap[x, y];}

	//pointer to next tilemap in the list
	TileMap^ Next;	
};
