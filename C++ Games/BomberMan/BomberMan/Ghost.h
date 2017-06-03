#pragma once
#include "sprite.h"

ref class Ghost :
public Sprite
{
private:
	Rectangle^ bounds;
public:
	Ghost(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, Random^ sRand, Rectangle^ sBounds);

virtual void Move() override;
void BounceGhost();
};
