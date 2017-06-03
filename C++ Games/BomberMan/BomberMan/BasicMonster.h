#pragma once
#include "sprite.h"


#define DIRECTION_CHANGE 12

ref class BasicMonster :
public Sprite
{
private:	
	int distanceMoved;
public:
	BasicMonster(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed,int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight, Random^ sRand);

	virtual void Move() override;
	void IncrementDistanceMoved();	
};
