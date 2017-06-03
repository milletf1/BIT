#include "StdAfx.h"
#include "Tile.h"
/// <summary>
/// Constructor
/// </summary>
Tile::Tile(Bitmap^ sTileBitmap, bool sIsFloor, bool sIsBreakable, bool sIsWarpTile)
{
	tileBitmap = sTileBitmap;
	isFloor = sIsFloor;
	isBreakable = sIsBreakable;
	isWarpTile = sIsWarpTile;
}//End//////////////////////////////////////////////////////////////////////////////
