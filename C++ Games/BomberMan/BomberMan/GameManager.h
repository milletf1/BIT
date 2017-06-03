#pragma once
#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include "Player.h"
#include "Bomb.h"
#include "BombLinkedList.h"
#include "Explosion.h"
#include "ExplosionLinkedList.h"
#include "Buff.h"
#include "BuffLinkedList.h"
#include "BasicMonster.h"
#include "Ghost.h"
#include "SpriteLinkedList.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define NONE 4
#define DROP_BOMB 5

#define BTN_POSX 448
#define BTN_POSY 512
#define BTN_WIDTH 45
#define BTN_HEIGHT 27

#define MAP_COLS 29
#define MAP_ROWS 19
#define TILE_SIZE 32

#define FLOOR_TILE 0
#define WALL_TILE 1
#define BREAK_TILE 2
#define PORTAL 3

#define PLAYER_DEFAULT_FRAMES 8
#define PLAYER_DRAW_WIDTH 32
#define PLAYER_DRAW_HEIGHT 64


#define PLAYER_DEFAULT_MOVESPEED 8
#define MONSTER_DEFAULT_MOVESPEED 2
#define GHOST_DEFAULT_MOVESPEED 10

#define PLAYER_HITX_OFFSET 6
#define PLAYER_HITY_OFFSET 40
#define PLAYER_HITBOX_HEIGHT 22
#define PLAYER_HITBOX_WIDTH 22

#define BASIC_HITBOX_OFFSETX 1
#define BASIC_HITBOX_OFFSETY 1
#define BASIC_HITBOX_HEIGHT 30
#define BASIC_HITBOX_WIDTH 30

#define BOMB_TIMER 2000
#define BUFF_TIMER 8000
#define EXPLOSION_TIMER 500

#define POINT 10
#define AOE_BUFF 0
#define BOMB_NUM_BUFF 1
#define MOVE_BUFF 2

#define LVL_1 0
#define TITLE_SCREEN 3

#define PLAYER_LIVES 10
#define WEAK_MONSTER_LIVES 1
#define STRONG_MONSTER_LIVES 3

#define PLAYER 0
#define WEAK_MONSTER 1
#define STRONG_MONSTER 2

#define MONSTER_FRAMES 6
#define GHOST_FRAMES 4

#define SPRITE_TYPE 0
#define SPRITE_DRAWX 1
#define SPRITE_DRAWY 2
using namespace System;

using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class GameManager
{
private:
	int screen;
	
	Label^ scoreOutput;
	Label^ livesOutput;

	Bitmap^ playButton;
	Random^ rand;
	TileMap^ myTileMap;
	Player^ myPlayer;
	BombLinkedList^ bombList;
	ExplosionLinkedList^ explosionList;
	BuffLinkedList^ buffList;
	SpriteLinkedList^ monsterList;
	SpriteLinkedList^ ghostList;

	Graphics^ canvas;
	Graphics^ buffer;
	Bitmap^ drawSurface;
	int screenWidth;
	int screenHeight;	
	
	void DrawMap();
	void HandlePlayer();
	void HandleBomb();
	void HandleExplosion();
	void HandleBuff();
	void HandleMonsters();
	void HandleGhosts();
	void AddBuffToList(Point^ drawPoint);
	void PlayerDropBomb();
	bool MoveSprite(Sprite^ sprite);

public:
	GameManager(Graphics^ sCanvas, Random^ sRand, int sScreenWidth, int sScreenHeight, Label^ sScore, Label^ sLives);
	void InitTileMap();
	void InitPlayer();
	void AddBomb();
	void BombDetonation(Point^ sPoint);
	bool CheckExplosionPoint(int row, int col);
	void AddExplosion(Point^ sPoint);
	void TimerTick();
	void GetPlayerInput(int input);
	void GetPlayerInput(Point^ click);
	bool DropBuff();
	int PickBuff() {return rand->Next(3);}
	bool ClickedButton(Point^ click);
	void NewGame();
	void LoadLevel();
	void LoadSprites(String^ spriteFile);
	void LevelTransitionCleanup();
	void PlayerHit();
	void WarpPlayer(int row, int col);
	void AddGhost(Point^ drawPos);
};
