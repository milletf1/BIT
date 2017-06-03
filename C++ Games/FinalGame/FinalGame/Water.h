#pragma once

#define START_X 32
#define LENGTH_X 576
#define SCREEN_SIZE 640
#define START_Y -50
#define START_SPEED 1
#define RAISE_SPEED 800
#define START_TIMER 1

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//**************************************************************************************
//Water is the class that is responsible for determining the position of and drawing the
//rising water level in the game.
//**************************************************************************************
ref class Water
{
private:
	Graphics^ canvas;
	int yPos;
	int timer;
	int speed;
public:
	//constructor
	Water(Graphics^ sCanvas);

	//functions
	void Draw(int mapYLat);
	void IncrementYPos();
	void IncementTimer();

	//gets and sets
	int getYPos() {return yPos;}
};
