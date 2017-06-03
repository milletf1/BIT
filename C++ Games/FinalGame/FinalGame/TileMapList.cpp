#include "StdAfx.h"
#include "TileMapList.h"

//***********
//Constructor
//***********
TileMapList::TileMapList()
{
	head = nullptr;
	tail = nullptr;
}//*************************************************************************************

//**********************************
//adds a tile map to the linked list
//**********************************
void TileMapList::AddTileMap(TileMap^ newTileMap)
{
	//check if the list is empty
	if(head == nullptr)
	{
		//if it is, set head and tail to newTileMap
		head = newTileMap;
		tail = newTileMap;
	}
	else
	{
		//if it isn't make both the map that the tail is point at
		//and the tail point at newTileMap
		tail->Next = newTileMap;
		tail = newTileMap;
	}
}//*************************************************************************************

//********************************************
//deletes a tile map from the linked list.   
//will only ever need to delete the head value
//********************************************
void TileMapList::DeleteTileMap(TileMap^ dMap)
{
	TileMap^ curMap = head;

	//check if the head tile map needs to be deleted
	if(head == dMap)
	{
		//check if the head and tail tile map are the same
		if(tail == dMap)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = dMap->Next;
	}
	//check that the tail tile map is not the one being
	//deleted
	else 
	{
		//run this while loop until curMap points to 
		//the tile map that needs deleting
		while(curMap->Next != dMap)
			curMap = curMap->Next;

		//set curMaps next to dMap next
		curMap->Next = dMap->Next;
	}
}//*************************************************************************************

//*************************************************
//takes a tile map number and returns that tile map
//*************************************************
TileMap^ TileMapList::FetchMap(int mapIndex)
{
	TileMap^ curMap = head;
	//returnMap is the tileMap that will be returned
	TileMap^ returnMap;

	//cycle through each tile map in the list until the map with the given number is found
	while(curMap->getMapNumber() != mapIndex &&	curMap->Next != nullptr)
		curMap = curMap->Next;
	
	returnMap = curMap;

	return returnMap;
}//*************************************************************************************

//*********************************************************************************
//FetchIsTileSolid takes a map number, the tiles array position, and the tile list.
//Returns that tiles isSolid value.
//*********************************************************************************
bool TileMapList::FetchIsTileSolid(int mapIndex, TileList^ tileList, int tileX, int tileY)
{
	TileMap^ curMap = head;	
	bool rValue; 

	//cycle through each tile map in the list until the map with the given number is found
	while(curMap->getMapNumber() != mapIndex &&	curMap->Next != nullptr)
		curMap = curMap->Next;
		
	//get the tile number of the given tile position in the map
	int tileValue = curMap->getTileValue(tileX, tileY);
	
	//return the isSolidObject value of the tile 
	rValue = tileList->getIsSolidObject(tileValue);
	return rValue;
}//*************************************************************************************

//**********************************************************************************
//PerformListUpkeep takes the water level of the games water entity, and removes any
//tile maps that are below it.
//**********************************************************************************
void TileMapList::PerformListUpkeep(int waterLevel)
{
	//create a TileMap array
	array<TileMap^>^ mapArray = gcnew array<TileMap^>(Count());
	int count = 0;
	TileMap^ curMap = head;

	//populate the array with the TileMaps stored in this linked list
	while(curMap != nullptr)
	{
		mapArray[count] = curMap;
		curMap = curMap->Next;
		count += 1;
	}

	//cycle through the tile map array
	for(int i = 0; i < mapArray->Length; i++)
	{	
		//check if the tile map is below the water level.
		if(mapArray[i]->getMapYLatitude() > waterLevel)
		{
			//if it is, remove it from the linked list
			DeleteTileMap(mapArray[i]);
		}
	}
}//*************************************************************************************

//**************************************************************************
//Count returns the number of tile maps currently stored in the linked list.
//**************************************************************************
int TileMapList::Count()
{
	//set a integer that will keep a count as the linked list cycles through 
	//the stored tile maps
	int count = 0;
	TileMap^ curSprite = head;

	//cycle through the tile maps in the linked list
	while(curSprite != nullptr)
	{		
		curSprite = curSprite->Next;
		//increment count
		count += 1;
	}
	//return the count of the tile maps in the linked list
	return count;
}//*************************************************************************************