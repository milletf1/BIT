#include "StdAfx.h"
#include "Player.h"

/// <summary>
/// Constructor
/// </summary>
Player::Player(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight)
		: Sprite(sCanvas, upSheet, downSheet, leftSheet, rightSheet, sNFrames, sDrawPos, sDrawWidth, 
		sDrawHeight, sMoveSpeed, sLives, sHitBoxXOffset, sHitBoxYOffset, sHitBoxWidth, sHitBoxHeight)
{	
	//initialize the players game powerup variables
	hasBombAOEBuff = false;
	bombAOEBuffTimer = 0;
	hasMultiBombs = false;
	multiBombsTimer = 0;
	hasMoveSpeedBuff = false;
	MoveSpeedBuffTimer = 0;
	//once the player drops a bomb, they can temporarily move over the bomb, once they have moved off it
	//they can no longer walk past them
	canMovePastBomb = false;
	MoveCenterPoint();
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Moves the players center point.  the center point is used to determine what tile the
/// player drops a bomb on, and when they use a warp portal.
/// </summary>
void Player::MoveCenterPoint()
{
	int newXPos = hitBoxPos->X + (hitBoxWidth / 2);
	int newYPos = hitBoxPos->Y + (hitBoxHeight / 2);
	centerPoint = gcnew Point(newXPos, newYPos);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Activates a given buff on the player, and sets the buff duration timer.
/// </summary>
void Player::RecieveBuff(int buff)
{
	switch(buff)
	{
	case AOE_BUFF:
		hasBombAOEBuff = true;
		bombAOEBuffTimer = BUFF_DURATION;
		break;
	case BOMB_NUM_BUFF:
		hasMultiBombs = true;
		multiBombsTimer = BUFF_DURATION;
		break;
	case MOVE_BUFF:
		hasMoveSpeedBuff = true;
		MoveSpeedBuffTimer = BUFF_DURATION;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if the player has any of the buffs.  If they have, it decrements that buffs
/// timer.  when the timer reaches 0, it removes the buff from the player.
/// </summary>
void Player::PerformBuffUpkeep()
{
	//Bomb AOE Buff 
	if(hasBombAOEBuff)
	{
		bombAOEBuffTimer -= TIMER_DECAY;
		//check if the "timer" has run out
		if(bombAOEBuffTimer == 0)
			hasBombAOEBuff = false;
	}
	//Multi Bombs
	if(hasMultiBombs)
	{
		multiBombsTimer -= TIMER_DECAY;
		//check if the "timer" has run out
		if(multiBombsTimer == 0)
			hasMultiBombs = false;
	}
	//Move Speed Buff
	if(hasMoveSpeedBuff)
	{
		MoveSpeedBuffTimer -= TIMER_DECAY;
		//check if the "timer" has run out
		if(MoveSpeedBuffTimer == 0)
			hasMoveSpeedBuff = false;		
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Removes all buffs from the player.  Is used when the player dies or changes level
/// </summary>
void Player::ClearAllBuffs()
{
	hasBombAOEBuff = false;
	bombAOEBuffTimer = 0;
	hasMultiBombs = false;
	multiBombsTimer = 0;
	hasMoveSpeedBuff = false;
	MoveSpeedBuffTimer = 0;	
}//End//////////////////////////////////////////////////////////////////////////////