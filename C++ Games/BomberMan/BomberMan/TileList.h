#pragma once
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileList
{
private:
	array<Tile^>^ gameTiles;
public:
	TileList(int gameTilesLength);

	void setGameTile(int pos, Tile^ nTile) {gameTiles[pos] = nTile;}
	Bitmap^ getGameTile(int pos) {return gameTiles[pos]->getTileBitmap();}
	bool getIsFloor(int pos) {return gameTiles[pos]->getIsFloor();}
	bool getIsBreakable(int pos) {return gameTiles[pos]->getIsBreakable();}
	bool getIsWarpTile(int pos) {return gameTiles[pos]->getIsWarpTile();}
};
