#include "StdAfx.h"
#include "Buff.h"

/// <summary>
/// Constructor
/// </summary>
Buff::Buff(Graphics^ sCanvas, Bitmap^ sImage, Point^ sPosition, int sWidth, int sHeight, int sLiveTimer, int sType)
{
	canvas = sCanvas;
	image = sImage;
	position = sPosition;
	width = sWidth;
	height = sHeight;
	liveTimer = sLiveTimer;
	type = sType;
	isActive = true;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws the bomb image to the form
/// </summary>
void Buff::Draw()
{
	canvas->DrawImage(image, position->X, position->Y, Rectangle(0, 0, width, height), GraphicsUnit::Pixel);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decrements the buff timer, and deactivates it when it runs out
/// </summary>
void Buff::DecayTimer()
{
	liveTimer = liveTimer - BUFF_DECAY;
	if(liveTimer <= 0)
	{
		Deactivate();
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if the player has picked up the buff.  Returns true if the player has.
/// </summary>
bool Buff::SpriteCollision(Sprite^ sprite)
{
	bool didCollide = true;

	//check this sprites left for a collision
	if(getLeft() > sprite->getRight())
	{
		didCollide = false;
	}
	//check this sprites right for a collision
	else if (getRight() < sprite->getLeft())
	{
		didCollide = false;
	}
	//check this sprites top for a collision
	else if(getTop() > sprite->getBottom())
	{
		didCollide = false;
	}
	//check this sprites bottom for a collision
	else if(getBottom() < sprite->getTop())
	{
		didCollide = false;
	}
	return didCollide;
}//End//////////////////////////////////////////////////////////////////////////////