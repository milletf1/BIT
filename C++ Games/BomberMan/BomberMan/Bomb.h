#pragma once
#include "Sprite.h"

#define TIMER_DECAY 50

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Bomb
{
	Graphics^ canvas;
	Point^ position;
	int width;
	int height;
	int nFrames;
	int curFrame;
	int detonationTime;
	array<Bitmap^>^ bombAnimation;	
	bool hasDetonated;
	void IncrementFrame();	
public:
	Bomb^ Next;
	Bomb(Graphics^ sCanvas, int sWidth, int sHeight, int sNFrames, array<Bitmap^>^ sBombAnimation, int sDetonationTime, Point^ sPosition);
	void BurnFuse();
	void Draw();
	bool getHasDetonated() {return hasDetonated;}
	void DetonateBomb() {hasDetonated = true;}

	
	bool CheckOnBomb(Sprite^ sprite);
	bool CheckCollsion(Sprite^ sprite);

	Point^ getPosition() {return position;}
	int getTop() {return position->Y;}
	int getBottom() {return position->Y + height;}
	int getLeft() {return position->X;}
	int getRight() {return position->X + width;}
};
