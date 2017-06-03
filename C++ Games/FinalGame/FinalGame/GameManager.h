#pragma once
#include "TileMap.h"
#include "TileMapList.h"
#include "TileList.h"
#include "Tile.h"
#include "ViewPort.h"
#include "Ninja.h"
#include "GoblinList.h"
#include "PowerUpList.h"
#include "Shuriken.h"
#include "ShurikenList.h"
#include "Water.h"

#define LEFT 0
#define RIGHT 1
#define JUMP 3
#define USE_JET 4
#define USE_SHURIKEN 5

#define TILE_SIZE 32
#define MAP_TILE_SIZE 20
#define SCREEN_SIZE 640

#define TILE_LIST_SIZE 9

#define VIEW_OFFSET -268

#define PLAYER_DRAW_SIZE 64
#define PLAYER_START_X 320
#define PLAYER_START_Y -308
#define PLAYER_DRAW_OFFSET_X -13
#define PLAYER_DRAW_OFFSET_Y -12
#define PLAYER_HITBOX_WIDTH 38
#define PLAYER_HITBOX_HEIGHT 52
#define PLAYER_XVEL 10

#define GRAVITY 4
#define JUMP_HEIGHT -32
#define MAX_FALL_SPEED 32
#define STANDING 0
#define WALKING 1
#define FALLING 2
#define JUMPING 3
#define HIT 4
#define CHARGE 5

#define JET 0
#define SHURIKEN 1

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//******************************************************
//GameManager is the game management class for the game.
//******************************************************
ref class GameManager
{
private:
	Label^ shurikenOutput;
	Label^ jetOutput;
	Label^ heightOutput;
	Random^ rand;
	Ninja^ myNinja;
	Water^ myWater;
	
	GoblinList^ myGoblinList;
	PowerUpList^ myPowerUps;
	TileMapList^ myTileMapList;
	ShurikenList^ myShurikenList;

	TileList^ myTileList;
	ViewPort^ myViewPort;
	Graphics^ buffer;
	Graphics^ canvas;
	Bitmap^ drawSurface;
	int lastMapNum;
	int mapPixelSize;
	int lastMapBotYLat;

	bool inGame;

public:
	//constructor
	GameManager(Graphics^ sCanvas, Random^ sRand, Label^ sShurikenOutput, Label^ sJetOutput, Label^ sHeightOutput);

	//functions
	void InitializePlayer();
	void InitializeViewPort();
	void InitializeTileMap();
	void InitializeTileList();

	void GenerateTileMap();
	void MoveViewPort();

	void DrawTileMap();
	void DrawSprites();

	void TimerTick();
	void GetPlayerInput(int input);
	void PlayerKeyUp();
	void PlayerThrowShuriken();
	void PlayerUseJetPack() { myNinja->UseJetPack(); }
	void PerformListUpkeep();
	
	void PerformSpriteAction();	
	void UpdateSpriteState();

	void UpdateStatistics();
};
