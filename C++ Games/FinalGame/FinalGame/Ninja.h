#pragma once
#include "Sprite.h"
#include "Shuriken.h"

#define WALL_JUMP_TIMER 10
#define SHUR_SPEED 10
#define SHUR_SIZE 16
#define SCORE_Y_MODIFIER 308
#define NINJA_FRAMES 6
#define NINJA_SCREEN_Y 256
#define LANDING_BUFFER 12

//**********************************************************
//Ninja is the game sprite that is controlled by the player.
//**********************************************************
ref class Ninja :
public Sprite
{
private:

	//gravity is the gravity which is applied when the ninja jumps
	int gravity;
	//ySpeed is the ninjas jump height
	int ySpeed;
	int maxFallSpeed;

	//readyToWallJump is used to check if the sprite can perform a wall jump when 
	//it hits a wall in the jump state.
	bool readyToWallJump;
	//when the player attempts to jump whilst in the jump state, a timer is started.  if it hits a wall
	//whilst jumping and the wallJumpTimer is still active, it performs a wall jump
	int wallJumpTimer;
	//lastWallJumpDir is used to check the last direction the sprite was facing when it performed a wall jump.
	//this is used to prevent the sprite from jumping constantly off the same wall, which makes the game too easy.
	int lastWallJumpDir;

	//the following bools are used by the various state update methods to determine if the sprite needs to change its state.
	bool startWalk;
	bool startStand;
	bool startJump;
	bool startFall;
	bool startJetJump;	
	
	//hitCountdown it a timer that starts when the player is hit by a goblin.  It is a rough fix to a bug that can
	//freeze the player in its hit state.
	int hitCountdown;

	array<Bitmap^>^ jumpBitmap;
	array<Bitmap^>^ fallBitmap;
	array<Bitmap^>^ jetBitmap;
	array<Bitmap^>^ hitBitmap;
	
public:
	//constructor
	Ninja(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize, int sGravity, int sYSpeed, int sMaxFallSpeed);

	//functions 
	virtual void Draw() override;
	virtual void InitializeSprites() override;
	
	virtual void PerformAction(TileMapList^ tileMapList, TileList^ tileList) override;
	virtual void MoveAction(TileMapList^ tileMapList, TileList^ tileList) override;
	void JumpAction(TileMapList^ tileMapList, TileList^ tileList);
	//void PerformHitAction(TileMapList^ tileMapList, TileList^ tileList);//needs monster list

	virtual void UpdateState() override;
	virtual void SpriteWalkUpdate() override;
	void NinjaStandUpdate();
	void NinjaJumpUpdate();
	void NinjaHitUpdate();

	bool CheckGroundTile(TileMapList^ tileMapList, TileList^ tileList);
	
	//handles the ninjas use of shurikens and jetpacks
	void UseJetPack();
	Shuriken^ GenerateShuriken();
	void PrepareWallJump();

	int CurrentHeight();

	//AvoidTile functions return a modifier to prevent the sprite walking through solid tiles
	int AvoidTileCollisionUp(int yPos) {return (yPos * -1) % tileSize + 1;}
	int AvoidCollisionDown(int yPos); 
	int AvoidTileCollisionLeft(int tileLeftX) {return ((tileLeftX + 1) * tileSize) + 1;}
	int AvoidTileCollisionRight(int tileRightX) {return  (tileRightX * tileSize) - hitBoxWidth - 1;}
	
	//sets and gets
	void setStartWalk(bool b) {startWalk = b;}
	void setStartStand(bool b) {startStand = b;}	
	bool getStartJump() {return startJump;}
	void setStartJump(bool b) {startJump = b;}

	int getYPos() {return yPos;}

	
};
