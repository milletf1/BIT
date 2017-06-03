#include "StdAfx.h"
#include "Shuriken.h"

//***********
//Constructor
//***********
Shuriken::Shuriken(Graphics^ sCanvas, int sXPos, int sYPos, int sXVel)
{
	canvas = sCanvas;
	xPos = sXPos;
	yPos = sYPos;
	xVel = sXVel;
	size = 16;
	curFrame = 0;
	totFrame = 4;
	throwTimer = THROW_TIMER;
	image = gcnew Bitmap("Sprites\\shuriken.bmp");
	image->MakeTransparent(image->GetPixel(0, 0));
	isAlive = true;

	Next = nullptr;
}//*************************************************************************************

//******************
//Move the shuriken.
//******************
void Shuriken::Move()
{
	xPos += xVel;
}//*************************************************************************************

//*****************************************
//Draw the shuriken to the graphics buffer.
//*****************************************
void Shuriken::Draw(int mapYLat)
{
	int screenYPos = (mapYLat + (yPos * -1)) * -1;
	int screenXPos = xPos;
	Point^ drawPos = gcnew Point(screenXPos, screenYPos);

	canvas->DrawImage(image, drawPos->X, drawPos->Y, Rectangle(curFrame * size, 0, size, size), GraphicsUnit::Pixel);
	IncrementFrame();
}//*************************************************************************************

//***********************************************************
//Set the shuriken image to the next one in the sprite sheet.
//***********************************************************
void Shuriken::IncrementFrame()
{
	curFrame += 1;
	curFrame = curFrame % totFrame;
}//*************************************************************************************

//****************************
//Decrease the shuriken timer.
//****************************
void Shuriken::DecrementTimer()
{
	throwTimer -= 1;

	if(throwTimer <= 0)
		isAlive = false;
}//*************************************************************************************

//*******************************************************
//Check for collision between a goblin and this shuriken.
//*******************************************************
bool Shuriken::CheckCollision(Sprite^ goblin)
{
	bool didCollide = true;

	//check this shurikens left for a collision
	if(getLeft() > goblin->getRight())
	{
		didCollide = false;
	}
	//check this shurikens right for a collision
	else if (getRight() < goblin->getLeft())
	{
		didCollide = false;
	}
	//check this shurikens top for a collision
	else if(getTop() > goblin->getBot())
	{
		didCollide = false;
	}
	//check this shurikens bottom for a collision
	else if(getBot() < goblin->getTop())
	{
		didCollide = false;
	}
	return didCollide;
}//*************************************************************************************