#include "StdAfx.h"
#include "Explosion.h"

/// <summary>
/// Constructor
/// </summary>
Explosion::Explosion(Graphics^ sCanvas, array<Bitmap^>^ sAnimation, Point^ sPosition, int sWidth, int sHeight, int sLifeTimer, int sNFrames)
{
	canvas = sCanvas;
	width = sWidth;
	height = sHeight;
	position = sPosition;
	nFrames = sNFrames;
	curFrame = 0;
	animation = sAnimation;
	lifeTimer = sLifeTimer; 
	isLive = true;
	Next = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if the explosion has hit a sprite.  Returns true if it has.
/// </summary>
bool Explosion::HitSprite(Sprite^ sprite)
{
	bool didHit = true;

	//check this sprites left for a collision
	if(getLeft() > sprite->getRight())
	{
		didHit = false;
	}
	//check this sprites right for a collision
	else if (getRight() < sprite->getLeft())
	{
		didHit = false;
	}
	//check this sprites top for a collision
	else if(getTop() > sprite->getBottom())
	{
		didHit = false;
	}
	//check this sprites bottom for a collision
	else if(getBottom() < sprite->getTop())
	{
		didHit = false;
	}
	return didHit;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if the explosion has hit a bomb.  Returns true if it has.
/// </summary>
bool Explosion::HitBomb(Bomb^ bomb)
{
	bool didHit = true;

	//check this sprites left for a collision
	if(getLeft() > bomb->getRight())
	{
		didHit = false;
	}
	//check this sprites right for a collision
	else if (getRight() < bomb->getLeft())
	{
		didHit = false;
	}
	//check this sprites top for a collision
	else if(getTop() > bomb->getBottom())
	{
		didHit = false;
	}
	//check this sprites bottom for a collision
	else if(getBottom() < bomb->getTop())
	{
		didHit = false;
	}
	return didHit;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws the explosion image to the form.
/// </summary>
void Explosion::Draw()
{
	canvas->DrawImage(animation[curFrame],position->X, position->Y, Rectangle(0, 0, width, height), GraphicsUnit::Pixel);
	IncrementFrame();
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decrements the explosions timer.  Sets its isLive bool to false when it reaches 0.
/// </summary>
void Explosion::DecayLifeTimer()
{
	lifeTimer -= TIMER_DECAY;
	if(lifeTimer <=0)	
		isLive = false;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Increments the explosions draw image.
/// </summary>
void Explosion::IncrementFrame()
{
	curFrame += 1;
	curFrame = curFrame % nFrames;
}//End//////////////////////////////////////////////////////////////////////////////

