#include "StdAfx.h"
#include "PowerUpList.h"

//***********
//Constructor
//***********
PowerUpList::PowerUpList(Random^ sRand)
{
	rand = sRand;
}//*************************************************************************************


//*******************************************************************************
//GeneratePowerUp decides if a power up appears, and creates them if they do when
//a new tile map is added to the tile list.
//*******************************************************************************
void PowerUpList::GeneratePowerUp(int mapType, int mapYLat, Graphics^ canvas)
{
	PowerUp^ powerUp;

	int powerUpXPos;
	int powerUpYPos;

	int spawn;
	int powerUpType;

	switch(mapType)
	{
	case 0:
		//first power up

		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);
			
			//set the power ups position
			powerUpXPos = 288;
			powerUpYPos = mapYLat + 320;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}
		//second power up
		
		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);

			//set the power ups position
			powerUpXPos = 96;
			powerUpYPos = mapYLat + 256;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}		
		break;
	case 1:
		//first power up

		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);
			
			//set the power ups position
			powerUpXPos = 96;
			powerUpYPos = mapYLat + 288;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}
		//second power up
		
		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);

			//set the power ups position
			powerUpXPos = 512;
			powerUpYPos = mapYLat + 96;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}		
		break;
	case 2:
		//first power up

		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);
			
			//set the power ups position
			powerUpXPos = 48;
			powerUpYPos = mapYLat + 160;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}
		//second power up
		
		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);

			//set the power ups position
			powerUpXPos = 48;
			powerUpYPos = mapYLat + 196;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}	
		//third power up
		
		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);

			//set the power ups position
			powerUpXPos = 48;
			powerUpYPos = mapYLat + 232;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}	
		//fourth power up
		
		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);

			//set the power ups position
			powerUpXPos = 48;
			powerUpYPos = mapYLat + 266;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}	
		break;
	case 3:
		//first power up

		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);
			
			//set the power ups position
			powerUpXPos = 576;
			powerUpYPos = mapYLat + 32;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}	
		break;	
	case 4:
		//first power up

		//decide if the powerup appears
		spawn = rand->Next(2);
		if(spawn == 0)
		{
			//choose the type of powerup	
			powerUpType = rand->Next(2);
			
			//set the power ups position
			powerUpXPos = 96;
			powerUpYPos = mapYLat + 100;

			//create the power up
			powerUp = gcnew PowerUp(canvas, TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE, powerUpXPos, powerUpYPos, 
				0, 0, 0, 0, 0, SCREEN_SIZE, TILE_SIZE, powerUpType);
			//add the power up to the list
			AddPowerUp(powerUp);
		}	
		break;	
	default:
		break;
	}
}//*************************************************************************************

//*********************************************
//AddPowerUp adds a power up to the linked list
//*********************************************
void PowerUpList::AddPowerUp(PowerUp^ nPowerUp)
{
	//check that the list is not empty
	if(head != nullptr)
	{
		//make the sprite that tail is pointing to point
		//to the new sprite.
		tail->Next = nPowerUp;
		//add the new sprite to the end of the list
		tail = nPowerUp;
	}
	//if the list is empty
	else
	{
		//set head and tails next to nSprite
		head = nPowerUp;
		tail = nPowerUp;
	}
}//*************************************************************************************

//***************************************************************************************
//PerformUpkeep decides if a power up needs to be removed from the linked list.  They get
//removed whenever their position is below the water level or a player colllects them.
//***************************************************************************************
void PowerUpList::PerformListUpkeep(int waterLevel)
{
	//create an array of power ups
	array<PowerUp^>^ powerUpArray = gcnew array<PowerUp^>(Count());
	int count = 0;
	PowerUp^ curPowerUp = head;
	
	//add the power ups in this list to the array
	while(curPowerUp != nullptr)
	{
		powerUpArray[count] = curPowerUp;
		
		curPowerUp = curPowerUp->Next;
		count += 1;
	}

	//cycle through the array, checking if a powerup needs to be removed from the list
	for(int i = 0; i < powerUpArray->Length; i++)
	{
		if(powerUpArray[i]->getIsAlive() == false ||
			powerUpArray[i]->getTop() > waterLevel)
			DeletePowerUp(powerUpArray[i]);
	}
}//*************************************************************************************

//******************************************************
//DeletePowerUp removes a power up from the linked list.
//******************************************************
void PowerUpList::DeletePowerUp(PowerUp^ dPowerUp)
{
	PowerUp^ curPowerUp = head;
	
	//check if the head sprite needs to be deleted
	if(head == dPowerUp)
	{
		//check if the head and tail sprite are the same
		if(tail == dPowerUp)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = dPowerUp->Next;
	}
	//check that the tail spprite is not the one being
	//deleted
	else 
	{
		//run this while loop until curSprite points to 
		//the sprite that needs deleting
		while(curPowerUp->Next != dPowerUp)
			curPowerUp = curPowerUp->Next;

		//set curSprites next to dSprites next
		curPowerUp->Next = dPowerUp->Next;
	}
}//*************************************************************************************

//*************************************************************
//DrawPowerUp controls drawing all the power ups  to the screen
//*************************************************************
void PowerUpList::DrawPowerUp(int mapYLat)
{
	PowerUp^ curPowerUp = head;

	while(curPowerUp != nullptr)
	{
		//check that curPowerUp is visible on screen
		if(curPowerUp->getYPos()>= mapYLat - 32 && curPowerUp->getYPos() <= mapYLat + SCREEN_SIZE)
			//draw the powerup
			curPowerUp->Draw(mapYLat);

		curPowerUp = curPowerUp->Next;
	}
}//*************************************************************************************

//***********************************************************
//CheckCollision checks if the player has collected a powerup
//***********************************************************
void PowerUpList::CheckCollision(Sprite^ player)
{
	PowerUp^ curPowerUp = head;
	
	while(curPowerUp != nullptr)
	{
		//check if the player has collided with the powerup
		if(curPowerUp->CheckCollision(player))
		{
			//add the power up to the players inventory
			if(curPowerUp->getType() == SHURIKEN)
			{
				player->setNumShuriken(player->getNumShuriken() + 1);
				curPowerUp->setIsAlive(false);
			}
			else
			{
				player->setNumJet(player->getNumJet() + 1);
				curPowerUp->setIsAlive(false);
			}
		}
		curPowerUp = curPowerUp->Next;
	}
}//*************************************************************************************

//**********************************************************************
//Count returns a count of all the power ups stored in this linked list.
//**********************************************************************
int PowerUpList::Count()
{
	int count = 0;
	PowerUp^ curSprite = head;

	while(curSprite != nullptr)
	{		
		curSprite = curSprite->Next;
		count += 1;
	}
	return count;
}//*************************************************************************************