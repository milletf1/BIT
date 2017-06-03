#pragma once
#include "TileMap.h"
#include "TileMapList.h"
#include "TileList.h"

#define UP 0
#define DOWN 1
#define INCREMENT 15

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//****************************************************************************
//ViewPort is the camera that follows the player as they move around the world
//****************************************************************************
ref class ViewPort
{
private:
	Graphics^ canvas;
	//yLat is the y latitude of the viewport.  It is used to synchronise with the game world
	int yLat;
	int playerOffset;
	int viewPixWidth;
	int viewPixHeight;
	int viewTileWidth;
	int viewTileHeight;
	int tileSize;
	int botYLat;
public:
	//constructor
	ViewPort(Graphics^ sCanvas, int sYLat, int sPlayerOffset, int sViewPixWidth, int sViewPixHeight, int sViewTileHeight
		,int sViewTileWidth, int sTileSize);
	
	//functions 
	void DrawView(TileMapList^ tileMap, TileList^ tileList);	
	int RoundUpTile(int num);
	void SetView(int playerTop); 
	
	//get and sets
	int getYLat() {return yLat;}
};
