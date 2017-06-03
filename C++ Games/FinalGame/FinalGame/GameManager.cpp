#include "StdAfx.h"
#include "GameManager.h"

//***********
//Constructor
//***********
GameManager::GameManager(Graphics^ sCanvas, Random^ sRand, Label^ sShurikenOutput, Label^ sJetOutput, Label^ sHeightOutput)
{
	canvas = sCanvas;
	rand = sRand;
	mapPixelSize = TILE_SIZE * MAP_TILE_SIZE;
	drawSurface = gcnew Bitmap(mapPixelSize, mapPixelSize);
	buffer = Graphics::FromImage(drawSurface);
	
	myWater = gcnew Water(buffer);
	myGoblinList = gcnew GoblinList(rand);
	myPowerUps = gcnew PowerUpList(rand);
	myShurikenList = gcnew ShurikenList();

	shurikenOutput = sShurikenOutput;
	jetOutput = sJetOutput;
	heightOutput = sHeightOutput;

	InitializePlayer();
	InitializeViewPort();
	InitializeTileList();
	InitializeTileMap();

	inGame = true;	
}//*************************************************************************************

//**************************************
//initializes the view port on game load
//**************************************
void GameManager::InitializeViewPort()
{
	//determine the starting latitude of the view port
	int startViewPortY = mapPixelSize * -1;

	//construct the view port
	myViewPort = gcnew ViewPort(buffer, startViewPortY, VIEW_OFFSET, mapPixelSize, mapPixelSize, 
		MAP_TILE_SIZE, MAP_TILE_SIZE, TILE_SIZE);
}//*************************************************************************************

//************************************************************
//initializes the first  tile map and the tile map linked list 
//on game load.  After the first map is created, any new  
//maps are generated with the GenerateTileMap Function
//************************************************************
void GameManager::InitializeTileMap()
{
	//construct the tile map linked list
	myTileMapList = gcnew TileMapList();

	//determine the variables for the first map
	int firstMapNum = 1;
	int firstMapLat = firstMapNum * mapPixelSize * -1;

	//construct the first map
	TileMap^ newTileMap = gcnew TileMap(firstMapNum, firstMapLat, MAP_TILE_SIZE, MAP_TILE_SIZE);

	//add the tile map data from a csv file
	newTileMap->LoadMapFromFile("Maps\\startMap.csv");

	//add the map to the tile map linked list
	myTileMapList->AddTileMap(newTileMap);

	//set the variables needed to generate new tile maps properly
	lastMapNum = 1;
	lastMapBotYLat = myTileMapList->FetchMap(1)->getMapYLatitude() + mapPixelSize;	

	//generate the second map
	GenerateTileMap();
}//*************************************************************************************

//**************************************
//Initializes the tile list on game load
//**************************************
void GameManager::InitializeTileList()
{
	String^ tilePath = "Tiles\\";
	//create a temp tile that will be used to fill the tilelist
	Tile^ tempTile;

	//create a temp bitmap that will be given to the tempTile
	Bitmap^ tempBitmap;

	//construct the tile list
	myTileList = gcnew TileList(TILE_LIST_SIZE);

	//************************************
	//Construct the tiles used in the game
	//************************************

	//tile 0
	tempBitmap = gcnew Bitmap(tilePath + "wallTile.bmp");
	tempTile = gcnew Tile(tempBitmap, false);	
	myTileList->setTileArrayEntry(0 ,tempTile);

	//tile 1
	tempBitmap = gcnew Bitmap(tilePath + "solidWall.bmp");
	tempTile = gcnew Tile(tempBitmap, true);
	myTileList->setTileArrayEntry(1 ,tempTile);

	//tile 2
	tempBitmap = gcnew Bitmap(tilePath + "grassFloor.bmp");
	tempTile = gcnew Tile(tempBitmap, true);
	myTileList->setTileArrayEntry(2 ,tempTile);

	//tile 3
	tempBitmap = gcnew Bitmap(tilePath + "grassFloorLeftEdge.bmp");
	tempTile = gcnew Tile(tempBitmap, false);
	myTileList->setTileArrayEntry(3 ,tempTile);

	//tile 4
	tempBitmap = gcnew Bitmap(tilePath + "grassFloorRightEdge.bmp");
	tempTile = gcnew Tile(tempBitmap, false);
	myTileList->setTileArrayEntry(4 ,tempTile);

	//tile 5
	tempBitmap = gcnew Bitmap(tilePath + "botLeftWall.bmp");
	tempTile = gcnew Tile(tempBitmap, true);
	myTileList->setTileArrayEntry(5 ,tempTile);

	//tile 6
	tempBitmap = gcnew Bitmap(tilePath + "botRightWall.bmp");
	tempTile = gcnew Tile(tempBitmap, true);
	myTileList->setTileArrayEntry(6 ,tempTile);

	//tile 7
	tempBitmap = gcnew Bitmap(tilePath + "bridgeRail.bmp");
	tempTile = gcnew Tile(tempBitmap, false);
	myTileList->setTileArrayEntry(7 ,tempTile);

	//tile 8
	tempBitmap = gcnew Bitmap(tilePath + "bridgeGround.bmp");
	tempTile = gcnew Tile(tempBitmap, true);
	myTileList->setTileArrayEntry(8 ,tempTile);
}//*************************************************************************************

//************************************************************
//generates a tile map and adds it to the tile map linked list
//************************************************************
void GameManager::GenerateTileMap()
{
	//create a new map number for the new map
	int newMapNum = lastMapNum + 1;

	//determine the new maps y latitude by looking at the latitude of the last map
	int newMapYLat = myTileMapList->FetchMap(lastMapNum)->getMapYLatitude() - mapPixelSize;

	//construct a new tile map with the previously determined data
	TileMap^ newTileMap = gcnew TileMap(newMapNum, newMapYLat, MAP_TILE_SIZE, MAP_TILE_SIZE);
	
	//***************************
	//choose a random map to draw
	//***************************

	//pick a random number
	int mapSelect = rand->Next(5);

	//switch statement to choose map to draw based on map select
	//also initializes the goblins that appear in the section of the map, and
	//the power ups that appear in the section of the map.
	switch(mapSelect)
	{
	case 0:
		newTileMap->LoadMapFromFile("Maps\\map0.csv");
		myGoblinList->GenerateGoblins(mapSelect, newTileMap->getMapYLatitude(), buffer);
		myPowerUps->GeneratePowerUp(mapSelect, newTileMap->getMapYLatitude(), buffer);
		break;
	case 1:
		newTileMap->LoadMapFromFile("Maps\\map1.csv");
		myGoblinList->GenerateGoblins(mapSelect, newTileMap->getMapYLatitude(), buffer);
		myPowerUps->GeneratePowerUp(mapSelect, newTileMap->getMapYLatitude(), buffer);
		break;
	case 2:
		newTileMap->LoadMapFromFile("Maps\\map2.csv");
		myGoblinList->GenerateGoblins(mapSelect, newTileMap->getMapYLatitude(), buffer);
		myPowerUps->GeneratePowerUp(mapSelect, newTileMap->getMapYLatitude(), buffer);
		break;
	case 3:
		newTileMap->LoadMapFromFile("Maps\\map3.csv");
		myGoblinList->GenerateGoblins(mapSelect, newTileMap->getMapYLatitude(), buffer);
		myPowerUps->GeneratePowerUp(mapSelect, newTileMap->getMapYLatitude(), buffer);
		break;
	case 4:
		newTileMap->LoadMapFromFile("Maps\\map4.csv");
		myGoblinList->GenerateGoblins(mapSelect, newTileMap->getMapYLatitude(), buffer);
		myPowerUps->GeneratePowerUp(mapSelect, newTileMap->getMapYLatitude(), buffer);
		break;
	default: 
		break;
	}	

	//add the new tile map to the tile map list
	myTileMapList->AddTileMap(newTileMap);

	//update the variables used by the game manager to both retrieve tile maps and
	//determine if a new tile map needs to be generated
	lastMapNum = newMapNum;
	lastMapBotYLat = newMapYLat + mapPixelSize;
}//*************************************************************************************

//****************************************************************************
//moves the viewport when the player presses the up or down key (testing only)
//****************************************************************************
void GameManager::MoveViewPort()
{
	//move the viewport
	myViewPort->SetView(myNinja->getTop());
	
	//determine if a new map needs to be added to the tile map linked list.
	//this occurs when the view port draws tiles from the last map in the 
	//tile map linked list
	if(myViewPort->getYLat() < lastMapBotYLat)
		GenerateTileMap();
}//*************************************************************************************

//****************************
//draws the tile map to screen
//****************************
void GameManager::DrawTileMap()
{
	//draw the tile map to the buffer
	MoveViewPort();
	myViewPort->DrawView(myTileMapList, myTileList);	
}//*************************************************************************************

//****************************************
//Performs the sprites action based on the  
//sprites state when the timer ticks
//****************************************
void GameManager::PerformSpriteAction()
{
	myGoblinList->PerformGoblinActions(myTileMapList, myTileList, myNinja);
	myNinja->PerformAction(myTileMapList, myTileList);	
	myShurikenList->MoveShurikens();
	myWater->IncrementYPos();
	myWater->IncementTimer();
}//*************************************************************************************

//**********************************************
//updates the sprites state after the sprite has 
//performed an action when the timer ticks
//**********************************************
void GameManager::UpdateSpriteState()
{
	//check if the player has drowned
	if(myNinja->getTop() > myWater->getYPos())
	{
		//if yes, set inGame to false to end the game
		inGame = false;
	}
	//update the state of the other entities involved in the game
	myNinja->UpdateState();
	myGoblinList->UpdateGoblinState();
	myPowerUps->CheckCollision(myNinja);
	myGoblinList->CheckShurikenHit(myShurikenList->MakeArray());
}//*************************************************************************************

//*************************************************************
//Initializes the player sprite on game manager initialization.
//*************************************************************
void GameManager::InitializePlayer()
{
	myNinja = gcnew Ninja(buffer, PLAYER_DRAW_SIZE, PLAYER_DRAW_SIZE, PLAYER_HITBOX_WIDTH, PLAYER_HITBOX_HEIGHT, 
		PLAYER_START_X, PLAYER_START_Y, PLAYER_DRAW_OFFSET_X, PLAYER_DRAW_OFFSET_Y, STANDING, LEFT, PLAYER_XVEL, 
		SCREEN_SIZE, TILE_SIZE, GRAVITY, JUMP_HEIGHT, MAX_FALL_SPEED);
}//*************************************************************************************

//***********************************************************
//TimerTick manages the game cycle when the form timer ticks.
//***********************************************************
void GameManager::TimerTick()
{
	//check if a game is in progress
	if(inGame)
	{
		PerformSpriteAction();
		UpdateSpriteState();
		PerformListUpkeep();
		DrawTileMap();
		DrawSprites();
		UpdateStatistics();
		//draw the tile map to screen TODO:give this its own method
		canvas->DrawImage(drawSurface, Rectangle(0, 0, mapPixelSize, mapPixelSize));
	}
}//*************************************************************************************

//**************************************************************************************
//GetPlayerInput handles the user input when the press the left, right or up (jump) key.
//**************************************************************************************
void GameManager::GetPlayerInput(int input)
{
	//check if the player pressed the jump key
	if(input == JUMP)
	{
		if(!myNinja->getStartJump())
			myNinja->setStartJump(true);
		else if(myNinja->getSpriteState() == JUMP)
			myNinja->PrepareWallJump();
	}
	
	//if not check if its direction needs changed
	else if(input == LEFT || input == RIGHT)
	{
		switch(input)
		{
		case LEFT:
			myNinja->setXVel(myNinja->getXSpeed() * -1);
			break;

		case RIGHT:
			myNinja->setXVel(myNinja->getXSpeed());
			break;
		default:
			break;
		}
		if(myNinja->getDirFacing() != input)
		{
			myNinja->setDirFacing(input);
		}		
	}
		
	//if it is standing, make the ninja start walking
	if(myNinja->getSpriteState() == STANDING)
	{
		myNinja->setStartWalk(true);
	}
}//*************************************************************************************

//****************************************************************************************************
//PlayerKeyUp is called by the form when the player releases the left or right key 
//when the player is walking.  If the player sprite is walking, tells it to update to the stand state.
//****************************************************************************************************
void GameManager::PlayerKeyUp()
{
	if(myNinja->getSpriteState() == WALKING)
	{
		myNinja->setStartStand(true);
	}
}//*************************************************************************************

//******************************************************************************************
//DrawSprites draws all the sprites involved in the game.  Called by the TimerTick function.
//******************************************************************************************
void GameManager::DrawSprites()
{
	myPowerUps->DrawPowerUp(myViewPort->getYLat());
	myShurikenList->DrawShurikens(myViewPort->getYLat());
	myNinja->Draw();
	myGoblinList->DrawGoblins(myViewPort->getYLat());
	myWater->Draw(myViewPort->getYLat());
}//*************************************************************************************

//****************************************************************************************
//PerformListUpkeep tells the various linked lists involved in the game to perform upkeep.
//This purpose of this upkeep is to remove any objects that are below the water level, as 
//they are no longer needed.
//****************************************************************************************
void GameManager::PerformListUpkeep()
{
	myPowerUps->PerformListUpkeep(myWater->getYPos());
	myGoblinList->PerformListUpkeep(myWater->getYPos());
	myShurikenList->PerformListUpkeep();
	myTileMapList->PerformListUpkeep(myWater->getYPos());
}//*************************************************************************************

//*************************************************************************************
//PlayerThrowShuriken checks if the player has any shurikens available.  If it does, it
//tells the player sprite to generate one and add it to the linked list. 
//(this is probably the wrong way to go about it).
//*************************************************************************************
void GameManager::PlayerThrowShuriken()
{
	if(myNinja->getNumShuriken() > 0)
	{
		myShurikenList->AddShuriken(myNinja->GenerateShuriken()); 
	}
}//*************************************************************************************

//************************************************************************************************
//Update Statistics outputs the maximum height the player has reached, and the number of shurikens
//and number of jetpack charges the player posesses.
//************************************************************************************************
void GameManager::UpdateStatistics()
{
	//convert the text on the maxHeight label to an integer
	int maxHeight = Convert::ToInt16(heightOutput->Text);

	//check if the players current height is greater than the height displayed 
	//by the max height label.
	if(maxHeight < myNinja->CurrentHeight())
	{
		//if it is, display the player sprites current height
		heightOutput->Text = Convert::ToString(myNinja->CurrentHeight());
	}
	
	//display the player sprites current count of shurikens and jetpack charges
	shurikenOutput->Text = Convert::ToString(myNinja->getNumShuriken());
	jetOutput->Text = Convert::ToString(myNinja->getNumJet());
}//*************************************************************************************