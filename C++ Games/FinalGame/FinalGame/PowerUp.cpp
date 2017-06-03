#include "StdAfx.h"
#include "PowerUp.h"

//***********
//Constructor
//***********
PowerUp::PowerUp(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize, int sType)
		: Sprite (sCanvas, sDrawWidth, sDrawHeight, sHitBoxWidth, sHitBoxHeight, 
		sXPos, sYPos, sDrawOffsetX, sDrawOffsetY, sSpriteState, sDirFacing, sXSpeed, sScreenSize, sTileSize)
{
	type = sType;
	Next = nullptr;
	InitializeSprites();
}//*************************************************************************************

//******************************************************************************
//InitializeSprites initializes the bitmap for the type of sprite that is drawn.
//******************************************************************************
void PowerUp::InitializeSprites()
{
	String^ filePath = "Sprites\\";

	if(type == JET)
	{
		picture = gcnew Bitmap(filePath + "jetPO.bmp");
		picture->MakeTransparent(picture->GetPixel(0, 0));
	}
	else if(type == SHURIKEN)
	{
		picture = gcnew Bitmap(filePath + "shurikenPO.bmp");
		picture->MakeTransparent(picture->GetPixel(0, 0));
	}
}//*************************************************************************************

//***********************************************
//Draw draws the power up to the graphics buffer.
//***********************************************
void PowerUp::Draw(int mapYLat)
{
	int screenYPos = (mapYLat + (yPos * -1)) * - 1;
	int screenXPos = xPos;
	Point^ drawPos = gcnew Point(screenXPos, screenYPos);

	canvas->DrawImage(picture, drawPos->X, drawPos->Y, Rectangle(0, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
}//*************************************************************************************