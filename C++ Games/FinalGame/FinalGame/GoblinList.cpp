#include "StdAfx.h"
#include "GoblinList.h"

//***********
//Constructor
//***********
GoblinList::GoblinList(Random^ sRand)
{
	head = nullptr;
	tail = nullptr;
	rand = sRand;
}//**************************************************************************************

//**************************************************************************************
//GenerateGoblins is responsible for initializing the goblins that appear on the screen.
//It places them according to the mapType integer given as an argument.
//**************************************************************************************
void GoblinList::GenerateGoblins(int mapType, int mapYLat, Graphics^ canvas)
{
	Goblin^ goblin;
		
	int goblinXPos;
	int goblinYPos;
	
	int direction;

	switch(mapType)
	{
	case 0:	
		//no goblins on this section of the map.
		break;

	case 1:

		//create the first goblin for map type 1
		direction = rand->Next(2);
		goblinXPos = 256;
		goblinYPos = mapYLat + 128;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);
		
		//create the second goblin for map type 1
		direction = rand->Next(2);
		goblinXPos = 384;
		goblinYPos = mapYLat + 384;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);
		
		//create the third goblin for map type 1
		direction = rand->Next(2);
		goblinXPos = 384;
		goblinYPos = mapYLat + 256;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);
		
		break;

	case 2:

		//create the first goblin for map type 2
		direction = rand->Next(2);
		goblinXPos = 320;
		goblinYPos = mapYLat;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);
		
		//create the second goblin for map type 2
		direction = rand->Next(2);
		goblinXPos = 416;
		goblinYPos = mapYLat + 160;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);
	
		break;

	case 3:

		//create the first goblin for map type 3
		direction = rand->Next(2);
		goblinXPos = 288;
		goblinYPos = mapYLat + 128;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);
		
		//create the second goblin for map type 3
		direction = rand->Next(2);
		goblinXPos = 288;
		goblinYPos = mapYLat + 256;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);
		
		//create the third goblin for map type 3
		direction = rand->Next(2);
		goblinXPos = 288;
		goblinYPos = mapYLat + 384;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);

		break;
	
	case 4:

		//create the first goblin for map type 4
		direction = rand->Next(2);
		goblinXPos = 320;
		goblinYPos = mapYLat + 128;
		
		goblin = gcnew Goblin(canvas, GOBLIN_DRAW_WIDTH, GOBLIN_DRAW_HEIGHT, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT, goblinXPos,
			goblinYPos, GOBLIN_DRAW_OFFSET_X, GOBLIN_DRAW_OFFSET_Y, WALKING, direction, GOBLIN_XVEL, SCREEN_SIZE, TILE_SIZE);
		
		AddGoblin(goblin);

		break;

	default:
		break;
	}
}//**************************************************************************************

//********************************************
//AddGoblin adds a goblin to this linked list.
//********************************************
void GoblinList::AddGoblin(Goblin^ nGoblin)
{
	//check that the list is not empty
	if(head != nullptr)
	{
		//make the sprite that tail is pointing to point to the new sprite.
		tail->Next = nGoblin;
		//add the new sprite to the end of the list
		tail = nGoblin;
	}
	//if the list is empty
	else
	{
		//set head and tails next to nSprite
		head = nGoblin;
		tail = nGoblin;
	}
}//**************************************************************************************

//*******************************************************************************************
//PerformListUpkeep decides if a goblin needs to be removed from the linked list.
//Goblins are removed from the list when they are below the water level or hit by a shuriken.
//*******************************************************************************************
void GoblinList::PerformListUpkeep(int waterLevel)
{
	//create an array of goblins
	array<Goblin^>^ goblinArray = gcnew array<Goblin^>(Count());
	int count = 0;
	Goblin^ curGoblin = head;
	
	//cycle through the linked list
	while(curGoblin != nullptr)
	{
		//add curGoblin to the array
		goblinArray[count] = curGoblin;

		//set curGoblin to its Next and increment the counter.
		curGoblin = curGoblin->Next;
		count += 1;
	}

	//cycle through the goblin array
	for(int i = 0; i < goblinArray->Length; i++)
	{
		//check if the goblin has been hit or is below the water level
		if(!goblinArray[i]->getIsAlive() || goblinArray[i]->getTop() > waterLevel)
		{
			//if yes, remove the goblin from the list
			DeleteGoblin(goblinArray[i]);
		}
	}
}//**************************************************************************************

//*********************************************
//DeleteGoblin removes a goblin from this list.
//*********************************************
void GoblinList::DeleteGoblin(Goblin^ dGoblin)
{
	Goblin^ curGoblin = head;
	
	//check if the head sprite needs to be deleted
	if(head == dGoblin)
	{
		//check if the head and tail sprite are the same
		if(tail == dGoblin)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = dGoblin->Next;
	}
	//check that the tail spprite is not the one being
	//deleted
	else 
	{
		//run this while loop until curSprite points to the sprite that needs deleting.
		while(curGoblin->Next != dGoblin)
			curGoblin = curGoblin->Next;

		//set curSprites next to dSprites next
		curGoblin->Next = dGoblin->Next;
	}
}//**************************************************************************************

//*****************************************************************************
//DrawGoblins controls drawing the goblins in this list to the graphics buffer.
//*****************************************************************************
void GoblinList::DrawGoblins(int mapYLat)
{
	Goblin^ curGoblin = head;

	while(curGoblin != nullptr)
	{
		//check that curGoblin is visible on screen
		if(curGoblin->getYPos()>= mapYLat - 32 && curGoblin->getYPos() <= mapYLat + SCREEN_SIZE)
			//draw the goblin
			curGoblin->Draw(mapYLat);

		curGoblin = curGoblin->Next;
	}
}//**************************************************************************************

//*****************************************************************************
//PerformGoblinActions tells the goblins in this list to perform their actions.
//*****************************************************************************
void GoblinList::PerformGoblinActions(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite)
{
	Goblin^ curGoblin = head;

	while(curGoblin != nullptr)
	{
		curGoblin->PerformAction(tileMapList, tileList, otherSprite);	
		curGoblin = curGoblin->Next;
	}
}//**************************************************************************************

//****************************************************************************
//UpdateGoblinState tells the goblins in this list to check for state updates.
//****************************************************************************
void GoblinList::UpdateGoblinState()
{
	Goblin^ curGoblin = head;

	while(curGoblin != nullptr)
	{
		curGoblin->UpdateState();
		curGoblin = curGoblin->Next;
	}
}//**************************************************************************************

//**************************************************
//Count returns a count of the goblins in this list.
//**************************************************
int GoblinList::Count()
{
	//set a integer to count the goblins in this linked list.
	int count = 0;
	Goblin^ curSprite = head;

	//cycle through the list, incrementing the return count.
	while(curSprite != nullptr)
	{		
		curSprite = curSprite->Next;
		count += 1;
	}

	return count;
}//**************************************************************************************

//**************************************************************************************************
//CheckShurikenHit checks for collisions between the thrown shurikens and the goblins in thils list.
//**************************************************************************************************
void GoblinList::CheckShurikenHit(array<Shuriken^>^ shurikenArray)
{
	Goblin^ curGoblin = head;
	
	///cycle through each shuriken in this linked list.
	for(int i = 0; i < shurikenArray->Length; i++)
	{
		//cycle through each goblin in this list
		while(curGoblin != nullptr)
		{		
			//check for a collision between goblin and shuriken
			if(shurikenArray[i]->CheckCollision(curGoblin))
			{
				//if yes, set the curGoblin's isAlive bool to false
				curGoblin->setIsAlive(false);
			}
			curGoblin = curGoblin->Next;
		}
		//reset curGoblin to head
		curGoblin = head;
	}
}//**************************************************************************************