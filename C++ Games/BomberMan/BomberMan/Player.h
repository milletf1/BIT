#pragma once
#include "sprite.h"



#define AOE_BUFF 0
#define BOMB_NUM_BUFF 1
#define MOVE_BUFF 2

#define BUFF_DURATION 10000
#define TIMER_DECAY 50


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Player :
public Sprite
{
private:
	int score;
	int lives;
	//centerPoint is a point that selects which tile the player drops a bomb on (bombs adhere to a grid)
	//and as collision detection for the warp portals.
	Point^ centerPoint;		
	bool droppedBomb;
	bool hasBombAOEBuff;
	int bombAOEBuffTimer;
	bool hasMultiBombs;
	int multiBombsTimer;
	bool hasMoveSpeedBuff;
	int MoveSpeedBuffTimer;
public:
	Player(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight);
	//collision to check if the player has recieved a powerup
	
	void MoveCenterPoint();
	void RecieveBuff(int buff);
	void PerformBuffUpkeep();
	Point^ getCenterPoint() {return centerPoint;}	
	bool getHasMultiBombs() {return hasMultiBombs;}
	bool getHasBombAOEBuff() {return hasBombAOEBuff;}
	bool getHasMoveSpeedBuff() {return hasMoveSpeedBuff;}

	void setScore(int nScore) {score = nScore;}
	int getScore() {return score;}

	void ClearAllBuffs();
	
};
