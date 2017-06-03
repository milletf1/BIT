#include "StdAfx.h"
#include "ShurikenList.h"

//***********
//Constructor
//***********
ShurikenList::ShurikenList()
{
	head = nullptr;
	tail = nullptr;
}//*************************************************************************************

//************************************************************************
//Count returns the number of goblins currently stored in the linked list.
//************************************************************************
int ShurikenList::Count()
{
	int count = 0;
	Shuriken^ curShuriken = head;

	while(curShuriken != nullptr)
	{
		count += 1;
		curShuriken = curShuriken->Next;
	}
	return count;
}//*************************************************************************************

//******************************************************
//AddShuriken stores the shurikens thrown by the player.
//******************************************************
void ShurikenList::AddShuriken(Shuriken^ nShuriken)
{
	//check that the list is not empty
	if(head != nullptr)
	{
		//make the sprite that tail is pointing to point
		//to the new sprite.
		tail->Next = nShuriken;
		//add the new sprite to the end of the list
		tail = nShuriken;
	}
	//if the list is empty
	else
	{
		//set head and tails next to nSprite
		head = nShuriken;
		tail = nShuriken;
	}
}//*************************************************************************************

//*************************************************************************************
//DeleteShuriken removes a thrown shuriken from the linked list when its timer expires.
//*************************************************************************************
void ShurikenList::DeleteShuriken(Shuriken^ dShuriken)
{
	Shuriken^ curShuriken = head;
	
	//check if the head sprite needs to be deleted
	if(head == dShuriken)
	{
		//check if the head and tail sprite are the same
		if(tail == dShuriken)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = dShuriken->Next;
	}
	//check that the tail spprite is not the one being
	//deleted
	else 
	{
		//run this while loop until curSprite points to 
		//the sprite that needs deleting
		while(curShuriken->Next != dShuriken)
			curShuriken = curShuriken->Next;

		//set curSprites next to dSprites next
		curShuriken->Next = dShuriken->Next;
	}
}//*************************************************************************************

//******************************************************************************************************
//MakeArray returns an array of the shurikens stored in the linked list.  It is used
//by the GoblinList to check if any goblins have been hit by a shuriken, and this lists upkeep function.
//******************************************************************************************************
array<Shuriken^>^ ShurikenList::MakeArray()
{
	array<Shuriken^>^ shurikenArray = gcnew array<Shuriken^>(Count());
	int count = 0;
	Shuriken^ curShuriken = head;
	while(curShuriken != nullptr)
	{
		shurikenArray[count] = curShuriken;
		
		curShuriken = curShuriken->Next;
		count += 1;
	}
	return shurikenArray;
}//*************************************************************************************

//************************************************************************************
//PerformListUpkeep checks if any of the shurikens in the lists timer has expired, and 
//deletes them if true.
//************************************************************************************
void ShurikenList::PerformListUpkeep()
{
	//create an array of all shurikens in the linked list
	array<Shuriken^>^ shurikenArray = MakeArray();

	//cycle through the shuriken array
	for(int i = 0; i < shurikenArray->Length; i++)
	{
		//check if the shurikens timer has expired
		if(!shurikenArray[i]->getIsAlive())
		{
			//if yes, remove it from the list
			DeleteShuriken(shurikenArray[i]);
		}
	}
}//*************************************************************************************

//*********************************************************************
//MoveShuriken moves the shurikens in this list through the game world.
//*********************************************************************
void ShurikenList::MoveShurikens()
{
	Shuriken^ curShuriken = head;

	while(curShuriken != nullptr)
	{
		curShuriken->Move();
		curShuriken->DecrementTimer();
		curShuriken = curShuriken->Next;
	}
}//*************************************************************************************

//*************************************************************************
//DrawShuriken draws all the shurikens in this list to the graphics buffer.
//*************************************************************************
void ShurikenList::DrawShurikens(int mapYLat)
{
	Shuriken^ curShuriken = head;

	while(curShuriken != nullptr)
	{
		if(curShuriken->getTop() >= mapYLat - 16 && curShuriken->getTop() <= mapYLat + SCREEN_SIZE)
			curShuriken->Draw(mapYLat);

		curShuriken = curShuriken->Next;
	}
}//*************************************************************************************
