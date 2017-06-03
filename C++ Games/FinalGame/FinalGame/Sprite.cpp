#include "StdAfx.h"
#include "Sprite.h"

//***********
//Constructor
//***********
Sprite::Sprite(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize)
{
	//set the draw canvas 
	canvas = sCanvas;
	//set the draw width and height
	drawWidth = sDrawWidth;
	drawHeight = sDrawHeight;

	//set the offset used to get the draw position
	drawOffsetX = sDrawOffsetX;
	drawOffsetY = sDrawOffsetY;

	//set the hitbox width and height
	hitBoxWidth = sHitBoxWidth;
	hitBoxHeight = sHitBoxHeight;

	//set the hitbox x and y position
	xPos = sXPos;
	yPos = sYPos;
	
	//set the sprites xSpeed
	xSpeed = sXSpeed;
	
	//set the world variables
	screenSize = sScreenSize;
	tileSize = sTileSize;
	mapTileSize = screenSize / tileSize;

	//set the sprites default state and direction
	spriteState = sSpriteState;
	dirFacing = sDirFacing;

	isAlive = true;
	isHit = false;
}//*************************************************************************************

//*************************************************************
//sets the sprites world position equal to the given parameters
//*************************************************************
void Sprite::Move(int newX, int newY)
{
	xPos = newX;
	yPos = newY;
}//*************************************************************************************

//**************************************************************************************
//calculate the sprites next position after its x and y position have had velocity added
//**************************************************************************************
Point^ Sprite::NextPosition()
{
	int nextX = xPos += xVel;
	int nextY = yPos += yVel;

	//check that nextX is within the bounds of the map
	//(this is to prevent the ninja falling off the map when he 
	//changes directions when jumping and against a wall)

	//right
	if(nextX + hitBoxWidth >= screenSize - tileSize)
		nextX = screenSize - tileSize - hitBoxWidth;
	//left
	else if(nextX <= tileSize)
		nextX = tileSize;

	return gcnew Point(nextX, nextY);
}//*************************************************************************************

//**********************************************
//increments the sprites current animation frame
//**********************************************
void Sprite::IncrementFrame()
{
	curWalkFrame += 1;
	curWalkFrame = curWalkFrame % totWalkFrame;
}//*************************************************************************************

//*************************************************
//Check collision checks if 2 sprites have collided
//*************************************************
bool Sprite::CheckCollision(Sprite^ otherSprite)
{
	bool didCollide = true;

	//check this sprites left for a collision
	if(getLeft() > otherSprite->getRight())
	{
		didCollide = false;
	}
	//check this sprites right for a collision
	else if (getRight() < otherSprite->getLeft())
	{
		didCollide = false;
	}
	//check this sprites top for a collision
	else if(getTop() > otherSprite->getBot())
	{
		didCollide = false;
	}
	//check this sprites bottom for a collision
	else if(getBot() < otherSprite->getTop())
	{
		didCollide = false;
	}
	return didCollide;
}//*************************************************************************************

void Sprite::Draw(){}
void Sprite::Draw(int mapYLat){}
void Sprite::InitializeSprites(){}
void Sprite::UpdateState(){}
void Sprite::SpriteWalkUpdate(){}
void Sprite::MoveAction(TileMapList^ tileMapList, TileList^ tileList){}
void Sprite::MoveAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite){}
void Sprite::PerformAction(TileMapList^ tileMapList, TileList^ tileList){}
void Sprite::PerformAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite){}