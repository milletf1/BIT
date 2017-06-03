#include "StdAfx.h"
#include "TileList.h"

/// <summary>
/// Constructor
/// </summary>
TileList::TileList(int gameTilesLength)
{
	gameTiles = gcnew array<Tile^>(gameTilesLength);
}//End//////////////////////////////////////////////////////////////////////////////
