#include "StdAfx.h"
#include "Bomb.h"

/// <summary>
/// Constructor
/// </summary>
Bomb::Bomb(Graphics^ sCanvas, int sWidth, int sHeight, int sNFrames, array<Bitmap^>^ sBombAnimation, int sDetonationTime, Point^ sPosition)
{
	hasDetonated = false;
	canvas = sCanvas;
	width = sWidth;
	height = sHeight;
	position = sPosition;
	nFrames = sNFrames;
	curFrame = 0;
	bombAnimation = sBombAnimation;
	detonationTime = sDetonationTime; 
	Next = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decrements the bombs timer.  Sets it to detonate when the timer expires.
/// </summary>
void Bomb::BurnFuse()
{
	detonationTime = detonationTime - TIMER_DECAY;
	if(detonationTime <= 0)
	{
		hasDetonated = true;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws the bomb image to the form
/// </summary>
void Bomb::Draw()
{
	canvas->DrawImage(bombAnimation[curFrame],position->X, position->Y, 
		Rectangle(0, 0, width, height), GraphicsUnit::Pixel);
	IncrementFrame();
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// 
/// </summary>
void Bomb::IncrementFrame()
{
	curFrame += 1;
	curFrame = curFrame % nFrames;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if the player is standing on the bomb.  sets it to false if they are not.
/// This is needed to allow the player to move once they have dropped a bomb, as the 
/// the player drops a bomb under the sprite.
/// </summary>
bool Bomb::CheckOnBomb(Sprite^ sprite)
{
	bool onBomb = true;

	//check this sprites left for a collision
	if(getLeft() > sprite->getRight())
	{
		onBomb = false;
	}
	//check this sprites right for a collision
	else if (getRight() < sprite->getLeft())
	{
		onBomb = false;
	}
	//check this sprites top for a collision
	else if(getTop() > sprite->getBottom())
	{
		onBomb = false;
	}
	//check this sprites bottom for a collision
	else if(getBottom() < sprite->getTop())
	{
		onBomb = false;
	}
	return onBomb;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if a proposed sprite move is going to collide with a bomb (that the sprite isn't standing on)
/// </summary>
bool Bomb::CheckCollsion(Sprite^ sprite)
{
	bool didCollide = true;
	int nextPlayerLeft = sprite->LookAhead()->X + 1;
	int nextPlayerRight = sprite->LookAhead()->X + sprite->getWidth() - 1;
	int nextPlayerTop = sprite->LookAhead()->Y + 1;
	int nextPlayerBot = sprite->LookAhead()->Y + sprite->getHeight() - 1;

	//check this sprites left for a collision
	if(getLeft() > nextPlayerRight)
	{
		didCollide = false;
	}
	//check this sprites right for a collision
	else if (getRight() < nextPlayerLeft)
	{
		didCollide = false;
	}
	//check this sprites top for a collision
	else if(getTop() > nextPlayerBot)
	{
		didCollide = false;
	}
	//check this sprites bottom for a collision
	else if(getBottom() < nextPlayerTop)
	{
		didCollide = false;
	}
	return didCollide;
}//End//////////////////////////////////////////////////////////////////////////////
