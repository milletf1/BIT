#pragma once
#include "sprite.h"

#define JET 0
#define SHURIKEN 1

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//*********************************************************************************************************
//PowerUp is a descendant of Sprite.  A power-up object is one that the player can collect to get a one off 
//ability.  The two types of power-ups the player can get include:
//* Shuriken: allows the player to throw a shuriken that kills a goblin
//* Jet-Pack: allows the player to perform a jump that reaches greater heights than a normal jump
//*********************************************************************************************************
ref class PowerUp :
public Sprite
{
private:
	int type;
	Bitmap^ picture;

public:
	//constructor
	PowerUp(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize, int sType);

	//functions 
	PowerUp^ Next;
	virtual void Draw(int mapYLat) override;
	virtual void InitializeSprites() override;

	//get and sets
	int getType() {return type;}
};
