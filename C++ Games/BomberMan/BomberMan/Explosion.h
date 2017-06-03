#pragma once
#include "Sprite.h"
#include "Bomb.h"

#define TIMER_DECAY 50

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Explosion
{
private:
	Graphics^ canvas;
	array<Bitmap^>^ animation;
	int nFrames;
	int curFrame;
	bool isLive;
	int lifeTimer;
	Point^ position;
	int width;
	int height;
	void IncrementFrame();
public:
	Explosion^ Next;
	Explosion(Graphics^ sCanvas, array<Bitmap^>^ sAnimation, Point^ sPosition, int sWidth, int sHeight, int sLifeTimer, int sNFrames);

	
	bool HitSprite(Sprite^ sprite);
	bool HitBomb(Bomb^ bomb);
	void Draw();
	void DecayLifeTimer();
	bool getIsLive() {return isLive;}
	

	int getTop() {return position->Y;}
	int getBottom() {return position->Y + height;}
	int getLeft() {return position->X;}
	int getRight() {return position->X + width;}
};
