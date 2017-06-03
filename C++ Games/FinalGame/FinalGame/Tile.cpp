#include "StdAfx.h"
#include "Tile.h"

//***********
//Constructor
//***********
Tile::Tile(Bitmap^ sTileBitmap, bool sIsSolidObject)
{
	tileBitmap = sTileBitmap;
	isSolidObject = sIsSolidObject;
}//*************************************************************************************
