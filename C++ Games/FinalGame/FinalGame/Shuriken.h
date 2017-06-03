#pragma once
#include "sprite.h"

#define SHUR_SIZE 16
#define THROW_TIMER 20
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//***********************************************************************************************************
//The Shuriken class handles the position and movement of a shuriken when a player uses the shuriken ability.
//***********************************************************************************************************
ref class Shuriken
{
private:
	int xPos, yPos;
	
	int size;
	int curFrame, totFrame;
	int throwTimer;

	int xVel;
	
	Bitmap^ image;

	Graphics^ canvas;
	
	bool isAlive;
public:
	//constructor
	Shuriken(Graphics^ sCanvas, int sXPos, int sYPos, int sXVel);

	//functions 
	void Move();
	void DecrementTimer();
	void IncrementFrame();
	void Draw(int mapYLat);
	bool CheckCollision(Sprite^ goblin);

	//get and sets
	bool getIsAlive() {return isAlive;}
	int getTop() {return yPos;}
	int getBot() {return yPos + size;}
	int getLeft() {return xPos;}
	int getRight() {return xPos + size;}

	//pointer to the next shuriken object
	Shuriken^ Next;
};
