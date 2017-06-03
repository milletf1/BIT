#pragma once
#include "TileList.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileMap
{
private:
	TileList^ tileList;
	array<int, 2>^ map;
public:
	TileMap(TileList^ sTileList, int mapRows, int mapCols);
	
	void LoadFromFile(String^ fileName);

	//setMapValue is used to change an explodable block to a normal floor block when it has been exploded
	void setMapValue(int row, int col, int nValue) {map[row, col] = nValue;}
	int getMapValue(int row, int col) {return map[row, col];}//this may be unneeded
	//getTileListBitmap is used get a specific tile as opposed to one defined by the tile map.
	//needed to display a portal tile correctly
	Bitmap^ getTileListBitmap(int pos) {return tileList->getGameTile(pos);}
	Bitmap^ getMapBitmap(int row, int col) {return tileList->getGameTile(map[row, col]);}

	bool getIsFloor(int row, int col) {return tileList->getIsFloor(map[row, col]);}
	bool getIsBreakable(int row, int col) {return tileList->getIsBreakable(map[row, col]);}
	bool getIsWarpTile(int row, int col) {return tileList->getIsWarpTile(map[row, col]);}
};
