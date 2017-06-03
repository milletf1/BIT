#include "StdAfx.h"
#include "ViewPort.h"

//***********
//Constructor
//***********
ViewPort::ViewPort(Graphics^ sCanvas, int sYLat, int sPlayerOffset, int sViewPixWidth, int sViewPixHeight, int sViewTileHeight
		,int sViewTileWidth, int sTileSize)
{
	canvas = sCanvas;
	yLat = sYLat;
	playerOffset = sPlayerOffset;
	viewPixWidth = sViewPixWidth;
	viewPixHeight = sViewPixHeight;
	viewTileWidth = sViewTileWidth;
	viewTileHeight = sViewTileHeight;
	tileSize = sTileSize;
	botYLat = yLat;
}//*************************************************************************************

//*********************************************************************
//DrawView draws a snapshot of the world based on the players position.
//*********************************************************************
void ViewPort::DrawView(TileMapList^ tileMap, TileList^ tileList)
{
	//get the first tile map to draw from
	int firstMapNum = ((yLat * -1) + viewPixHeight) / viewPixHeight;
	TileMap^ firstMap = tileMap->FetchMap(firstMapNum); 

	//get the second tile map to draw from
	int secondMapNum = firstMapNum -1;
	TileMap^ secondMap = tileMap->FetchMap(secondMapNum);
	//because the first map will start drawing from the same row as the second map draws last,
	//rowBounds is used to determine which row this has is to happen from.
	int rowBounds = (RoundUpTile(yLat * -1) / tileSize) % (viewPixHeight / tileSize);

	//set rowBounds to viewTileHeight if it modded to 0
	if (rowBounds == 0)
	{
		rowBounds = viewTileHeight;
	}
	//decrement rowBounds by height (to reference the correct slot in the tile map)
	rowBounds -= 1;
	//drawCursor is the point on the screen that the viewport starts drawing from
	//it gets incremented as the tiles are drawn to screen 
	int drawY = (yLat % tileSize * -1)  - tileSize;
	Point^ drawCursor = gcnew Point(0, drawY);

	//*********************************************************************
	//cycle through each tile in each tile map, drawing the tiles to screen 
	//*********************************************************************
	//draw the highest map first
	for(int y = rowBounds ; y >= 0; y--)
	{
		for(int x = 0; x < viewTileWidth; x++)
		{
			canvas->DrawImage(tileList->getTileBitmap(firstMap->getTileValue(x, y)),drawCursor->X, drawCursor->Y, 
				Rectangle(0, 0, tileSize, tileSize), GraphicsUnit::Pixel);
			drawCursor->X += tileSize;
		}
		drawCursor->X = 0;
		drawCursor->Y +=tileSize;
	}
	//then draw the lowest map
	for(int y = viewTileHeight - 1 ; y >= rowBounds; y--)
	{
		for(int x = 0; x < viewTileWidth; x++)
		{
			canvas->DrawImage(tileList->getTileBitmap(secondMap->getTileValue(x, y)),drawCursor->X, drawCursor->Y, 
				Rectangle(0, 0, tileSize, tileSize), GraphicsUnit::Pixel);
			drawCursor->X += tileSize;
		}
		drawCursor->X = 0;
		drawCursor->Y +=tileSize;
	}
}//*************************************************************************************

//********************************************************************
//SetView sets the viewports position based on the players y position.
//********************************************************************
void ViewPort::SetView(int playerTop)
{
	yLat = playerTop + playerOffset;
}//*************************************************************************************

//************************************************************************************
//RoundUpTile is used to dteremine which row to start and draw form the tile maps used
// to display the world.  It takes the view ports y position and rounds it off to 
//the next tiles y position.
//************************************************************************************
int ViewPort::RoundUpTile(int num)
{
	return num + (tileSize - (num % tileSize));
}//*************************************************************************************
