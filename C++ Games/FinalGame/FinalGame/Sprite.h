#pragma once
#include "TileMap.h"
#include "TileMapList.h"
#include "TileList.h"
#include "Tile.h"

#define LEFT 0
#define RIGHT 1
#define USE_JET 4
#define USE_SHURIKEN 5

#define STANDING 0
#define WALKING 1
#define FALLING 2
#define JUMPING 3
#define HIT 4
#define CHARGE 5
#define JET_JUMP 6

#define NONE 255

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//*************************************************************************************************************
//Sprite is the base class for the player character (Ninja), the enemies (Goblin), and the power-ups (PowerUp).
//*************************************************************************************************************
ref class Sprite
{
protected:
	Graphics^ canvas;
	
	//the draw width and height
	int drawWidth, drawHeight;
	
	//the hitbox width and height
	int hitBoxWidth, hitBoxHeight;
	
	//the hit box position of the sprite in the game world
	int xPos, yPos;
	
	//the draw offset for the sprite
	int drawOffsetX, drawOffsetY;

	//xVel and yVel are the sprites current x and y velocity
	int xVel, yVel;
	
	//walkSpeed is the speed that the tile walks
	int xSpeed;

	//dirFacing is the direction the sprite is currently facing
	int dirFacing;

	int numShuriken;
	int numJet;

	int curWalkFrame, totWalkFrame;
	bool isAlive;
	bool isHit;

	//array spriteWalkAnimation stores bitmap sprite sheets for the sprites movement in each direction
	array<Bitmap^>^ spriteWalkAnimation;

	//array spriteStandBitmap stores the bitmap for when the sprite is standing still in each direction
	array<Bitmap^>^ standBitmap;

	int spriteState;

	//the world variables
	int screenSize, mapTileSize, tileSize;

public:
	//constructor
	Sprite(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize);
	
	//functions 
	void Move(int newX, int newY);
	Point^ NextPosition();
	void IncrementFrame();

	virtual void InitializeSprites();
	virtual void Draw();
	virtual void Draw(int mapYLat);

	virtual void UpdateState();
	virtual void SpriteWalkUpdate();
	
	virtual void PerformAction(TileMapList^ tileMapList, TileList^ tileList);
	virtual void PerformAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite);
	virtual void MoveAction(TileMapList^ tileMapList, TileList^ tileList);
	virtual void MoveAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite);

	bool CheckCollision(Sprite^ otherSprite);

	//gets and sets
	bool getIsAlive() {return isAlive;}
	void setIsAlive(bool nIsAlive) {isAlive = nIsAlive;}

	int getDirFacing() {return dirFacing;}
	void setDirFacing(int newDir) {dirFacing = newDir;}
	
	int getSpriteState() {return spriteState;}
	void setSpriteState(int nSpriteState) {spriteState = nSpriteState;}
	
	void setXPos(int newX) {xPos = newX;}
	void setYPos(int newY) {yPos = newY;}
	int getXPos() {return xPos;}
	int getYPos() {return yPos;}

	int getHitBoxWidth() {return hitBoxWidth;}
	int getHitBoxHeight() { return hitBoxHeight;}

	int getXVel() {return xVel;}
	void setXVel(int i) {xVel = i;}

	int getYVel() {return yVel;}
	void setYVel(int i) {yVel = i;}

	void setCurWalkFrame(int i) { curWalkFrame = i;}

	int getTop() {return yPos;}
	int getBot() {return yPos + hitBoxHeight;}
	int getLeft() {return xPos;}
	int getRight() {return xPos + hitBoxWidth;}

	int getXSpeed() {return xSpeed;}

	bool getIsHit() {return isHit;}
	void setIsHit(bool b) {isHit = b;}

	int getNumShuriken() {return numShuriken;}
	void setNumShuriken(int i) {numShuriken = i;}

	int getNumJet() {return numJet;}
	void setNumJet(int i) {numJet = i;}
	
	//********************************************************
	//ResolveMapNumber takes a sprites y coordinate and returns 
	//the number of the map that it occupies.  This is used
	//alongside ResolveTileYNumber to determine if the sprite
	//is going to move into a solid block.
	//********************************************************
	int ResolveMapNumber(int yPos) {return ((yPos * -1) + screenSize) / screenSize;}

	//*******************************************************
	//ResolveTileYNumber takes a sprites y coordinate and 
	//returns the related tile number.  This is used to check 
	//that the sprite isn't going to move into a solid block.
	//*******************************************************
	int ResolveTileYNumber(int nextY) {return ((nextY * -1) / tileSize) % mapTileSize;}

	//********************************************************
	//ResolveTileXNumber takes the sprites x coordinate and 
	//returns its related tile number.  used to check that the
	//sprite isn't going to move into a solid block.
	//********************************************************
	int ResolveTileXNumber(int nextX) {return (nextX / tileSize)  % mapTileSize;}
};
