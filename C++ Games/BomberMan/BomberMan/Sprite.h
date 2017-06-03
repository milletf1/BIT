#pragma once

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define NONE 4

#define HIT_TIMER 1500
#define TIMER_DECAY 50

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Sprite
{
protected:
	Random^ rand;
	Graphics^ canvas;
	int nFrames;
	int curFrame;
	array<Bitmap^>^ moveBitmaps;
	//draw variables
	Point^ drawPos;
	int drawWidth;
	int drawHeight;
	//hitbox Variables;
	Point^ hitBoxPos;
	int hitBoxWidth;
	int hitBoxHeight;
	int hitBoxXOffset;
	int hitBoxYOffset;
	//currentDir is used to pick the sprite sheet to draw from.  when the sprite is not moving it will draw from 
	//the sprite sheet picked my currentDir, but it will not increment the frame, giving the appearance of standing still.
	//it is also used to move the sprite by selecting the array slot in moveDir.
	int currentDir;
	int lastDir;
	//moveDir is used to move the sprite. it contains the x and y directions which 
	//get multiplied by movespeed (e.g. moveDir[LEFT] = Point(-1, 0)  moveDir[REST] = 0,0 etc...)
	array<Point^>^ moveDir;
	int moveSpeed;
	int lives;
	bool isHit;
	int isHitTimer;	
	//canMovePastBomb is needed in the sprite class because certain sprites can move through bombs
	bool canMovePastBomb;
public:
	Sprite^ Next;
	//constructor for the player
	Sprite(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight);
	//constructor for the monsters 
	Sprite(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight, Random^ sRand);
	//constructor for the ghosts
	Sprite(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, Random^ sRand);
	void Draw();
	virtual void Move();
	void IncrementFrame();
	bool CheckCollision(Sprite^ otherSprite);

	void ChangeDirection(int dir);
	int getCurrentDir() {return currentDir;}

	Point^ getPosition() {return hitBoxPos;}
	int getTop() {return hitBoxPos->Y;}
	int getBottom() {return hitBoxPos->Y + hitBoxHeight;}
	int getLeft() {return hitBoxPos->X;}
	int getRight() {return hitBoxPos->X + hitBoxWidth;}
	int getWidth() {return hitBoxWidth;}
	int getHeight() {return hitBoxHeight;}

	int getHitBoxWidth() {return hitBoxWidth;}
	int getHitBoxHeight() {return hitBoxHeight;}

	void SpriteGotHit();	
	void DecayHitTimer();
	bool getIsHit() {return isHit;}

	void setLives(int nLives) {lives = nLives;}
	int getLives() {return lives;}
	Point^ LookAhead();

	bool getCanMovePastBomb() {return canMovePastBomb;}
	void setCanMovePastBomb(bool b) {canMovePastBomb = b;}

	void setDrawPos(Point^ nDrawPos) {drawPos = nDrawPos;}	
	void MoveHitBox();
	void SetHitBox();
	

	void ChooseRandomDirection();
};
