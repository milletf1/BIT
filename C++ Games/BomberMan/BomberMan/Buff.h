#pragma once
#include "Sprite.h"

#define BUFF_DECAY 50;

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Buff
{
private:
	Graphics^ canvas;
	Bitmap^ image;
	Point^ position;
	int width;
	int height;
	bool isActive;
	int liveTimer;
	int buffDuration;
	int type;
	
public:

	Buff^ Next;
	Buff(Graphics^ sCanvas, Bitmap^ sImage, Point^ sPosition, int sWidth, int sHeight, int sLiveTimer, int sType);
	void Deactivate() {isActive = false;}
	bool getIsActive() {return isActive;}
	int getType() {return type;}
	void Draw();
	void DecayTimer();
	bool SpriteCollision(Sprite^ sprite);

	int getTop() {return position->Y;}
	int getBottom() {return position->Y + height;}
	int getLeft() {return position->X;}
	int getRight() {return position->X + width;}
};
