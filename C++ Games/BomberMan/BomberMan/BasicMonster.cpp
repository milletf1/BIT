#include "StdAfx.h"
#include "BasicMonster.h"

/// <summary>
/// Constructor
/// </summary>
BasicMonster::BasicMonster(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight, Random^ sRand)
		
		: Sprite(sCanvas, upSheet, downSheet, leftSheet, rightSheet, sNFrames, sDrawPos, sDrawWidth, 
		sDrawHeight, sMoveSpeed, sLives, sHitBoxXOffset, sHitBoxYOffset, sHitBoxWidth, sHitBoxHeight, sRand)
{
	distanceMoved = 0;
	canMovePastBomb = false;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Overridden move function.
/// </summary>
void BasicMonster::Move()
{	
	
	//set the new draw positions
	int newXPos = drawPos->X + (moveDir[currentDir]->X * moveSpeed);
	int newYPos = drawPos->Y + (moveDir[currentDir]->Y * moveSpeed);
	//set the draw position to the new positions
	drawPos->X = newXPos;
	drawPos->Y = newYPos;

	//increment the frame
	IncrementFrame();
	//increment distanceMoved
	IncrementDistanceMoved();	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Increments the monsters distance moved timer.  Monsters move in their current direction for a certain distance
/// then choose a new direction (unless they hit a wall or bomb)
/// </summary>
void BasicMonster::IncrementDistanceMoved()
{
	distanceMoved += 1;
	if (distanceMoved == DIRECTION_CHANGE)
	{
		ChooseRandomDirection();
		distanceMoved = 0;
	}
}//End//////////////////////////////////////////////////////////////////////////////



