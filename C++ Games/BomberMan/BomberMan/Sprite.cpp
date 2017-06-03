#include "StdAfx.h"
#include "Sprite.h"

/// <summary>
/// Constructor for the player sprite
/// </summary>
Sprite::Sprite(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight)
{
	canvas = sCanvas;
	nFrames = sNFrames;		
	curFrame = 0;
	//move direction
	moveDir = gcnew array<Point^>(5);
	moveDir[LEFT] = gcnew Point(-1, 0);
	moveDir[RIGHT] = gcnew Point(1, 0);
	moveDir[UP] = gcnew Point(0, -1);
	moveDir[DOWN] = gcnew Point(0, 1);
	moveDir[NONE] = gcnew Point(0, 0);

	//moveImages
	moveBitmaps = gcnew array<Bitmap^>(4);
	moveBitmaps[UP] =  gcnew Bitmap(upSheet);
	moveBitmaps[UP]->MakeTransparent(moveBitmaps[UP]->GetPixel(0,0));

	moveBitmaps[DOWN] =  gcnew Bitmap(downSheet);	
	moveBitmaps[DOWN]->MakeTransparent(moveBitmaps[DOWN]->GetPixel(0,0));

	moveBitmaps[LEFT] =  gcnew Bitmap(leftSheet);	
	moveBitmaps[LEFT]->MakeTransparent(moveBitmaps[LEFT]->GetPixel(0,0));

	moveBitmaps[RIGHT] =  gcnew Bitmap(rightSheet);	
	moveBitmaps[RIGHT]->MakeTransparent(moveBitmaps[RIGHT]->GetPixel(0,0));
	
	//sprite drawing data
	drawPos = sDrawPos;
	drawHeight = sDrawHeight;
	drawWidth = sDrawWidth;
	moveSpeed = sMoveSpeed;
	//hitbox data
	hitBoxXOffset = sHitBoxXOffset;
	hitBoxYOffset = sHitBoxYOffset;
	SetHitBox();
	hitBoxWidth = sHitBoxWidth;
	hitBoxHeight = sHitBoxHeight;

	//life data
	lives = sLives;
	isHit = false;
	isHitTimer = 0;
	//movement data
	lastDir = DOWN;
	currentDir = NONE;
	
	Next = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Constructor for the monster sprite
/// </summary>
Sprite::Sprite(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, int sLives, 
		int sHitBoxXOffset, int sHitBoxYOffset, int sHitBoxWidth, int sHitBoxHeight, Random^ sRand)
{
	rand = sRand;
	canvas = sCanvas;
	nFrames = sNFrames;		
	curFrame = 0;
	//move direction
	moveDir = gcnew array<Point^>(5);
	moveDir[LEFT] = gcnew Point(-1, 0);
	moveDir[RIGHT] = gcnew Point(1, 0);
	moveDir[UP] = gcnew Point(0, -1);
	moveDir[DOWN] = gcnew Point(0, 1);
	moveDir[NONE] = gcnew Point(0, 0);

	//moveImages
	moveBitmaps = gcnew array<Bitmap^>(4);
	moveBitmaps[UP] =  gcnew Bitmap(upSheet);
	moveBitmaps[UP]->MakeTransparent(moveBitmaps[UP]->GetPixel(0,0));

	moveBitmaps[DOWN] =  gcnew Bitmap(downSheet);	
	moveBitmaps[DOWN]->MakeTransparent(moveBitmaps[DOWN]->GetPixel(0,0));

	moveBitmaps[LEFT] =  gcnew Bitmap(leftSheet);	
	moveBitmaps[LEFT]->MakeTransparent(moveBitmaps[LEFT]->GetPixel(0,0));

	moveBitmaps[RIGHT] =  gcnew Bitmap(rightSheet);	
	moveBitmaps[RIGHT]->MakeTransparent(moveBitmaps[RIGHT]->GetPixel(0,0));
	
	//draw data
	drawPos = sDrawPos;
	drawHeight = sDrawHeight;
	drawWidth = sDrawWidth;
	
	//hitbox data
	hitBoxXOffset = sHitBoxXOffset;
	hitBoxYOffset = sHitBoxYOffset;
	SetHitBox();
	hitBoxWidth = sHitBoxWidth;
	hitBoxHeight = sHitBoxHeight;

	moveSpeed = sMoveSpeed;
	//life data
	lives = sLives;
	isHit = false;
	isHitTimer = 0;
	//movement data
	lastDir = DOWN;
	currentDir = NONE;
	
	Next = nullptr;	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Constructor for the ghost sprite
/// </summary>
Sprite::Sprite(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, Random^ sRand)
{
	rand = sRand;
	canvas = sCanvas;
	nFrames = sNFrames;		
	curFrame = 0;
	//move direction
	moveDir = gcnew array<Point^>(5);
	moveDir[LEFT] = gcnew Point(-1, 0);
	moveDir[RIGHT] = gcnew Point(1, 0);
	moveDir[UP] = gcnew Point(0, -1);
	moveDir[DOWN] = gcnew Point(0, 1);
	moveDir[NONE] = gcnew Point(0, 0);

	//moveImages
	moveBitmaps = gcnew array<Bitmap^>(4);
	moveBitmaps[UP] =  gcnew Bitmap(upSheet);
	moveBitmaps[UP]->MakeTransparent(moveBitmaps[UP]->GetPixel(0,0));

	moveBitmaps[DOWN] =  gcnew Bitmap(downSheet);	
	moveBitmaps[DOWN]->MakeTransparent(moveBitmaps[DOWN]->GetPixel(0,0));

	moveBitmaps[LEFT] =  gcnew Bitmap(leftSheet);	
	moveBitmaps[LEFT]->MakeTransparent(moveBitmaps[LEFT]->GetPixel(0,0));

	moveBitmaps[RIGHT] =  gcnew Bitmap(rightSheet);	
	moveBitmaps[RIGHT]->MakeTransparent(moveBitmaps[RIGHT]->GetPixel(0,0));
	
	//draw data
	drawPos = sDrawPos;
	drawHeight = sDrawHeight;
	drawWidth = sDrawWidth;

	moveSpeed = sMoveSpeed;	
	lastDir = DOWN;
	currentDir = rand->Next(4);
	
	Next = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws the sprite to screen
/// </summary>
void Sprite::Draw()
{
	//draws the sprite when it is moving
	if(currentDir != NONE)
	{
		canvas->DrawImage(moveBitmaps[currentDir], drawPos->X, drawPos->Y, 
			Rectangle(curFrame * drawWidth, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		IncrementFrame();
	}
	//draws the sprite when it is not moving
	else
	{
		canvas->DrawImage(moveBitmaps[lastDir], drawPos->X, drawPos->Y, 
			Rectangle(curFrame * drawWidth, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Moves the sprite on screen
/// </summary>
void Sprite::Move()
{		
	//set the new draw positions
	int newXPos = drawPos->X + (moveDir[currentDir]->X * moveSpeed);
	int newYPos = drawPos->Y + (moveDir[currentDir]->Y * moveSpeed);
	
	//set the draw position to the new positions
	drawPos->X = newXPos;
	drawPos->Y = newYPos;	
	
	//increment the frame
	IncrementFrame();		
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Moves the sprites hitbox.  Used when the sprite moves
/// </summary>
void Sprite::MoveHitBox()
{	 
	//set the new hit box positions
	int newXPos = hitBoxPos->X + (moveDir[currentDir]->X * moveSpeed);
	int newYPos = hitBoxPos->Y + (moveDir[currentDir]->Y * moveSpeed);
	hitBoxPos->X = newXPos;
	hitBoxPos->Y = newYPos;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Increments the sprites draw frame
/// </summary>
void Sprite::IncrementFrame()
{
	curFrame += 1;
	curFrame = curFrame % nFrames;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if any 2 sprites have collided.  Returns true if they have.
/// </summary>
bool Sprite::CheckCollision(Sprite^ otherSprite)
{
	bool didCollide = true;

	//check this sprites left for a collision
	if(getLeft() > otherSprite->getRight())
	{
		didCollide = false;
	}
	//check this sprites right for a collision
	else if (getRight() < otherSprite->getLeft())
	{
		didCollide = false;
	}
	//check this sprites top for a collision
	else if(getTop() > otherSprite->getBottom())
	{
		didCollide = false;
	}
	//check this sprites bottom for a collision
	else if(getBottom() < otherSprite->getTop())
	{
		didCollide = false;
	}
	return didCollide;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns the sprites hit box position after it has been incremented by a move.  It is used to check for wall collisions
/// </summary>
Point^ Sprite::LookAhead()
{
	//set the new hit box positions
	int newXPos = hitBoxPos->X + (moveDir[currentDir]->X * moveSpeed);
	int newYPos = hitBoxPos->Y + (moveDir[currentDir]->Y * moveSpeed);
	return gcnew Point(newXPos, newYPos);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Changes the sprite's movement direction
/// </summary>
void Sprite::ChangeDirection(int dir)
{
	if(currentDir != NONE)
		lastDir = currentDir;

	currentDir = dir;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decays the sprites hit timer.  The hit timer is activated when the sprite is hit by
/// an explosion, or in the case of the player, a monster sprite.  the isHitTimer prevents
/// the sprite from taking another hit when they have been hit recently.
/// </summary>
void Sprite::DecayHitTimer()
{
	isHitTimer -= TIMER_DECAY;

	if(isHitTimer == 0)
		isHit = false;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// sets the sprite's isHit bool to true, indicating they have been hit
/// </summary>
void Sprite::SpriteGotHit()
{
	isHit = true;
	isHitTimer = HIT_TIMER;
}//End//////////////////////////////////////////////////////////////////////////////

void Sprite::ChooseRandomDirection()
{
	int newDir = rand->Next(4);
	ChangeDirection(newDir);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Sets the sprites hitbox position.
/// </summary>
void Sprite::SetHitBox()
{
	int hitXPos = drawPos->X + hitBoxXOffset;
	int hitYPos = drawPos->Y + hitBoxYOffset;
	hitBoxPos = gcnew Point(hitXPos, hitYPos);
}//End//////////////////////////////////////////////////////////////////////////////