#include "StdAfx.h"
#include "Water.h"

//***********
//Constructor
//***********
Water::Water(Graphics^ sCanvas)
{
	canvas = sCanvas;
	yPos = START_Y;
	speed = START_SPEED;
	timer = START_TIMER;
}//*************************************************************************************

//****************************************************************************************
//Draws the water on the form.  Only occurs if the current water level is at a height that
//makes it viewable on screen.
//****************************************************************************************
void Water::Draw(int mapYLat)
{	
	//check if the water level is within the coordinates of the view port
	if(yPos >= mapYLat - 32 && yPos <= mapYLat + SCREEN_SIZE)
	{
		//if it is, calculate its on screen coordinates
		int screenYPos = (mapYLat + (yPos * -1)) * - 1;
		int screenXPos = START_X;

		Brush^ fillColor = gcnew SolidBrush(Color::LightBlue);
		//draw the water to screen
		canvas->FillRectangle(fillColor,Rectangle(screenXPos, screenYPos, LENGTH_X, SCREEN_SIZE));
	}
}//*************************************************************************************

//****************************************************
//Increases the height of the water level in the game.
//****************************************************
void Water::IncrementYPos()
{
	yPos -= speed;
}//*************************************************************************************

//*****************************************************************************************
//IncrementTimer counts down the water levels timer.  When it reaches 0, the speed that the 
//water level is rising increases.
//*****************************************************************************************
void Water::IncementTimer()
{
	timer += speed;
	timer = timer % RAISE_SPEED;

	if(timer == 0)
		speed += 1;
}//*************************************************************************************

