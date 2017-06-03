#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Tile
{
private:
	Bitmap^ tileBitmap;
	bool isFloor;
	bool isBreakable;
	bool isWarpTile;
public:
	Tile(Bitmap^ sTileBitmap, bool sIsFloor, bool sIsBreakable, bool sIsWarpTile);

	Bitmap^ getTileBitmap() {return tileBitmap;}
	void setTileBitmap(Bitmap^ nTileBitmap) {tileBitmap = nTileBitmap;}

	bool getIsFloor() {return isFloor;}
	void setIsFloor(bool nIsFloor) {isFloor = nIsFloor;}

	bool getIsBreakable() {return isBreakable;}
	void setIsBreakable(bool nIsBreakable) {isBreakable = nIsBreakable;}

	bool getIsWarpTile() {return isWarpTile;}
};
