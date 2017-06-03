#include "StdAfx.h"
#include "GameManager.h"

/// <summary>
/// Constructor
/// </summary>
GameManager::GameManager(Graphics^ sCanvas, Random^ sRand, int sScreenWidth, int sScreenHeight, Label^ sScore, Label^ sLives)
{
	rand = sRand;
	canvas = sCanvas;
	scoreOutput = sScore;
	livesOutput = sLives;
	drawSurface = gcnew Bitmap(sScreenWidth, sScreenHeight);
	buffer = Graphics::FromImage(drawSurface);	
	screenWidth = sScreenWidth;
	screenHeight = sScreenHeight;	
	
	bombList = gcnew BombLinkedList();
	explosionList = gcnew ExplosionLinkedList();
	buffList = gcnew BuffLinkedList();
	monsterList = gcnew SpriteLinkedList();
	ghostList = gcnew SpriteLinkedList();
	
	screen = TITLE_SCREEN;
	playButton = gcnew Bitmap("playButton.bmp");
	playButton->MakeTransparent(playButton->GetPixel(0, 0));
	
	InitTileMap();
	LoadLevel();
	InitPlayer();	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Initializes the tile map.
/// </summary>
void GameManager::InitTileMap()
{
	//tilePath is the folder that contains the tiles bitmap images.
	String^ tilePath = "Blocks\\";
	//Create a temporary bitmap that will be used to given to a temporary tile before it is given to the tileList.
	Bitmap^ nBitmap;
	//Create a temporary Tile that will be given used to fill the tileList array
	Tile^ nTile;
	//Create a new tileList that will be given to the tilemap once it has been given the tiles used in the game.
	TileList^ nTileList = gcnew TileList(4);

	//Create tile 1 (floor tile)
	nBitmap = gcnew Bitmap(tilePath + "BackgroundTile.bmp");
	nTile = gcnew Tile(nBitmap, true, false, false);
	nTileList->setGameTile(FLOOR_TILE, nTile);
	//Create tile 2 (Wall Tile)
	nBitmap = gcnew Bitmap(tilePath + "SolidBlock.bmp");
	nTile = gcnew Tile(nBitmap, false, false, false);
	nTileList->setGameTile(WALL_TILE, nTile);
	//Create tile 3 (Explodable tile)
	nBitmap = gcnew Bitmap(tilePath + "ExplodableBlock.bmp");
	nTile = gcnew Tile(nBitmap, false, true, false);
	nTileList->setGameTile(BREAK_TILE, nTile);

	//Create tile 4 (Portal tile tile)
	nBitmap = gcnew Bitmap(tilePath + "Portal.bmp");
	//give the bitmap a transparent background
	nBitmap->MakeTransparent(nBitmap->GetPixel(0, 0));
	nTile = gcnew Tile(nBitmap, true, false, true);
	nTileList->setGameTile(PORTAL, nTile);

	//initialize tile map
	myTileMap = gcnew TileMap(nTileList, MAP_ROWS, MAP_COLS);	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Initializes the player on game load.  Doesn't set any game statistics such as score, lives etc
/// </summary>
void GameManager::InitPlayer()
{
	//the paths to the player's directional sprite sheets
	String^ upSheet = "Bomberman\\bMan_up.bmp";
	String^ downSheet = "Bomberman\\bMan_dwn.bmp";
	String^ leftSheet = "Bomberman\\bMan_left.bmp";
	String^ rightSheet = "Bomberman\\bMan_rght.bmp";
	
	//the players draw point (not needed on form load)
	Point^ sDrawPoint = gcnew Point(0, 0);
	int playerHitX = sDrawPoint->X + PLAYER_HITX_OFFSET;
	int	playerHitY = sDrawPoint->Y + PLAYER_HITY_OFFSET;
	Point^ sHitBoxPos = gcnew Point(playerHitX, playerHitY);
	
	//construct the player
	myPlayer = gcnew Player(buffer, upSheet, downSheet, leftSheet, rightSheet, PLAYER_DEFAULT_FRAMES
		, sDrawPoint, PLAYER_DRAW_WIDTH, PLAYER_DRAW_HEIGHT, PLAYER_DEFAULT_MOVESPEED, 0, PLAYER_HITX_OFFSET, PLAYER_HITY_OFFSET,
		PLAYER_HITBOX_WIDTH, PLAYER_HITBOX_HEIGHT);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws the map from the integer values stored in the tile map
/// </summary>
void GameManager::DrawMap()
{
	////loop through map array	
	for(int col = 0; col < MAP_COLS; col++)
	{
		for(int row = 0; row < MAP_ROWS; row++)
		{
			//calculate the point to draw the tile on
			int xPos = TILE_SIZE * col;
			int yPos = TILE_SIZE * row;	
			
			//check if the tile that is about to be drawn is a portal.  
			if(myTileMap->getMapValue(row, col) == PORTAL)			
				//if the tile is a portal, a floor tile first needs to be draw first because a portal tile has a transparent background
				buffer->DrawImage(myTileMap->getTileListBitmap(FLOOR_TILE), xPos, yPos, Rectangle(0, 0, TILE_SIZE, TILE_SIZE), 
				GraphicsUnit::Pixel);			

			//draw the tile 
			buffer->DrawImage(myTileMap->getMapBitmap(row, col), xPos, yPos, Rectangle(0, 0, TILE_SIZE, TILE_SIZE), GraphicsUnit::Pixel);	
		}
	}	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Handles the player's movement, buff timers, hit timer, and draws the player.
/// </summary>
void GameManager::HandlePlayer()
{	
	int moves;

	//check if the player has the movespeed buff.  If he does he gets 2 moves
	if(myPlayer->getHasMoveSpeedBuff())
		moves = 2;
	else
		moves = 1;

	for(int i = 0; i < moves; i++)
	{
		//create a row and column that will be used to point to a single tile.
		//used to check if the player is on a warp tile, or pick a tile on which
		//to drop a bomb.
		int playerTileCol = myPlayer->getCenterPoint()->X / TILE_SIZE;
		int playerTileRow = myPlayer->getCenterPoint()->Y / TILE_SIZE;

		//check for warp portal hit.  Needs to be checked first because the player can't warp and move in the same game cycle.
		if(myTileMap->getIsWarpTile(playerTileRow, playerTileCol))
		{
			System::Diagnostics::Debug::WriteLine("row " + playerTileRow + " col " + playerTileCol);
			WarpPlayer(playerTileRow, playerTileCol);
			//code for handling warp goes here.  will need to be able to hard set the players draw position to do this.
		}
		
		//check if the player is currently moving in a direction		
		if(myPlayer->getCurrentDir() != NONE)
		{		
			//checks if the player can move.  If so perform move
			if(MoveSprite(myPlayer))
			{
				myPlayer->Move();
				myPlayer->SetHitBox();
				myPlayer->MoveCenterPoint();	
			}
			//check if the player can move past bombs (the player can move past bombs briefly whenever they drop a bomb)
			if(myPlayer->getCanMovePastBomb())
			{
				//check if the player has moved off the bomb
				if(!bombList->CheckOnBomb(myPlayer))	
					//if they have, remove bomb movement privledges
					myPlayer->setCanMovePastBomb(false);
			}	
		}
		//decay the timers on the player's buffs
		myPlayer->PerformBuffUpkeep();

		//decay the players isHit timer if the player has been hit
		if(myPlayer->getIsHit())
			myPlayer->DecayHitTimer();
	}
	myPlayer->Draw();
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Handles the gamecycle whenever the forms timer ticks
/// </summary>
void GameManager::TimerTick()
{
	//draw the map
	DrawMap();
	//if the map is the title screen, draw a play game button over it
	if(screen == TITLE_SCREEN)
	{
		buffer->DrawImage(playButton, BTN_POSX, BTN_POSY, Rectangle(0, 0, BTN_WIDTH, BTN_HEIGHT), GraphicsUnit::Pixel);
	}
	//if not, update all the sprites and entities involved in the game
	else
	{
		HandleBuff();		
		HandleExplosion();
		HandleGhosts();
		HandleMonsters();				
		HandleBomb();
		HandlePlayer();
	}
	//draw the buffered bitmap to screen
	canvas->DrawImage(drawSurface, Rectangle(0, 0, screenWidth, screenHeight));
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Uses the player input whenever the player presses a game key
/// </summary>
void GameManager::GetPlayerInput(int input)
{
	if(input != DROP_BOMB)
		myPlayer->ChangeDirection(input);
	else
		PlayerDropBomb();
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// This function is used to check if the player can drop a bomb.
/// </summary>
void GameManager::PlayerDropBomb()
{
	//create an int that is used to determine how many bombs the player can drop
	int totalBombs;
	//check if the player has the multibomb buff
	if(myPlayer->getHasMultiBombs())
		totalBombs = 3;
	else
		totalBombs = 1;
	
	//check if the player can drop a bomb
	if(bombList->CountBombs() < totalBombs)
	{
		//if they can, place a bomb with the bomb placement function
		AddBomb();
		myPlayer->setCanMovePastBomb(true);
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Recieves the player input when they click on the form
/// </summary>
void GameManager::GetPlayerInput(Point^ click)
{
	
	//check if the player is at the title screen
	if(screen == TITLE_SCREEN)
	{
		//check if they clicked the button 
		if(ClickedButton(click))
			//if they did, start a new game
			NewGame();
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Determines the placement of a new bomb on the game screen, and adds a bomb to the bomblist
/// </summary>
void GameManager::AddBomb()
{
	//create new Bomb;
	Bomb^ myBomb;
	//set bombs position
	int bombTileCol = (myPlayer->getCenterPoint()->X / TILE_SIZE) * TILE_SIZE;
	int bombTileRow = (myPlayer->getCenterPoint()->Y / TILE_SIZE) * TILE_SIZE;
	Point^ bombPoint = gcnew Point(bombTileCol, bombTileRow);
	//create a bitmap array to pass to bomb
	array<Bitmap^>^ bombAnimation = gcnew array<Bitmap^>(3);
	//fill bitmap array with bitmaps
	//bomb 1
	bombAnimation[0] = gcnew Bitmap("Bomb\\Bomb_f01.bmp");
	bombAnimation[0]->MakeTransparent(bombAnimation[0]->GetPixel(0, 0));
	//bomb 2
	bombAnimation[1] = gcnew Bitmap("Bomb\\Bomb_f02.bmp");
	bombAnimation[1]->MakeTransparent(bombAnimation[1]->GetPixel(0, 0));
	//bomb 3
	bombAnimation[2] = gcnew Bitmap("Bomb\\Bomb_f03.bmp");
	bombAnimation[2]->MakeTransparent(bombAnimation[2]->GetPixel(0, 0));

	//create the bomb
	myBomb = gcnew Bomb(buffer, TILE_SIZE, TILE_SIZE, 3, bombAnimation, BOMB_TIMER, bombPoint);
	//add to the list
	bombList->AddBomb(myBomb);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Handles the bomb objects logic when the timer ticks.
/// </summary>
void GameManager::HandleBomb()
{
	if(bombList->CountBombs() > 0)
	{
		//burn the bombs fuses
		bombList->BurnFuse();
		//check if any of the bombs have exploded (explodes when the bombs detonation timer reaches 0)
		Bomb^ curBomb = bombList->CheckExplosion();

		Bomb^ tempBomb = nullptr;
		
		while(curBomb != nullptr)
		{			
			//create a temp bomb;	
			tempBomb = curBomb;		
			//remove curBomb from the bombList
			bombList->DeleteBomb(curBomb);
			//create explosion
			BombDetonation(curBomb->getPosition());
			//create a bomb array to check if the explosion set off any more bombs
			array<Bomb^>^ bombArray = bombList->MakeArray();
			//check if the explosion set off any bombs near the exploded bomb
			for(int i = 0; i < bombArray->Length; i++)
			{
				if(explosionList->CheckBombCollision(bombArray[i]))
					//set the bombs exploded value to true
					bombArray[i]->DetonateBomb();
			}		
			curBomb = bombList->CheckExplosion(tempBomb->Next);
		}

		//draw the bombs
		bombList->DrawAll();
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Creates the explosions caused by a bomb detonation and adds them to the explosionList.
/// </summary>
void GameManager::BombDetonation(Point^ sPoint)
{
	
	//set the draw position for the explosion
	int drawPosX;
	int drawPosY;
	Point^ drawPoint;
	//these booleans are used to prevent extra explosions from travelling through walls
	//(only needed when the player has the AOE buff)
	bool canTravelUp;
	bool canTravelDown;
	bool canTravelLeft;
	bool canTravelRight;

	//set the first explosion at the bombs draw point
	AddExplosion(sPoint);

	//set the Tile values for checking if an explosion can occur on the given tiles
	//surrounding the initial blast point

	//position for explosion one above detonation point
	int oneUpTileCol = sPoint->X / TILE_SIZE;
	int oneUpTileRow = sPoint->Y / TILE_SIZE - 1;	
	////position for explosion one below detonation point
	int oneDownTileCol = sPoint->X / TILE_SIZE;
	int oneDownTileRow = sPoint->Y / TILE_SIZE + 1;
	////position for explosion one left of detonation point
	int oneLeftTileCol = sPoint->X / TILE_SIZE - 1;
	int oneLeftTileRow = sPoint->Y / TILE_SIZE;
	//position for explosion one right of detonation point
	int oneRightTileCol = sPoint->X / TILE_SIZE + 1;
	int oneRightTileRow = sPoint->Y / TILE_SIZE;

	//check the tile map to see if an explosion can occur on the given tile
	//one above detonation point
	if(CheckExplosionPoint(oneUpTileRow, oneUpTileCol))
	{
		canTravelUp = true;
		//if it can, set the draw point for the explosion
		drawPosX = oneUpTileCol * TILE_SIZE;
		drawPosY = oneUpTileRow * TILE_SIZE;
		drawPoint = gcnew Point(drawPosX, drawPosY);
		//add the explosion to the explosion list
		AddExplosion(drawPoint);
	}	
	else
		canTravelUp = false;

	//one below detonation point
	if(CheckExplosionPoint(oneDownTileRow, oneDownTileCol))
	{
		canTravelDown = true;
		//if it can, set the draw point for the explosion
		drawPosX = oneDownTileCol * TILE_SIZE;
		drawPosY = oneDownTileRow * TILE_SIZE;
		drawPoint = gcnew Point(drawPosX, drawPosY);
		//add the explosion to the explosion list
		AddExplosion(drawPoint);
	}
	else
		canTravelDown = false;

	//one left of detonation point
	if(CheckExplosionPoint(oneLeftTileRow, oneLeftTileCol))
	{
		canTravelLeft = true;
		//if it can, set the draw point for the explosion
		drawPosX = oneLeftTileCol * TILE_SIZE;
		drawPosY = oneLeftTileRow * TILE_SIZE;
		drawPoint = gcnew Point(drawPosX, drawPosY);
		//add the explosion to the explosion list
		AddExplosion(drawPoint);
	}
	else
		canTravelLeft = false;

	//one right of detonation point
	if(CheckExplosionPoint(oneRightTileRow, oneRightTileCol))
	{
		canTravelRight = true;
		//if it can, set the draw point for the explosion
		drawPosX = oneRightTileCol * TILE_SIZE;
		drawPosY = oneRightTileRow * TILE_SIZE;
		drawPoint = gcnew Point(drawPosX, drawPosY);
		//add the explosion to the explosion list
		AddExplosion(drawPoint);
	}	
	else
		canTravelRight = false;
	//check if the player has the increased AOE buff
	if(myPlayer->getHasBombAOEBuff())
	{
		//set the tile values for checking if an explosion can occur on the given tiles
		//that make up the increased AOE blast points 

		//position for explosion two above detonation point
		int twoUpTileCol = sPoint->X / TILE_SIZE;
		int twoUpTileRow = sPoint->Y / TILE_SIZE - 2;	
		//position for explosion three above detonation point
		int threeUpTileCol = sPoint->X / TILE_SIZE;
		int threeUpTileRow = sPoint->Y / TILE_SIZE - 3;

		////position for explosion two below detonation point
		int twoDownTileCol = sPoint->X / TILE_SIZE;
		int twoDownTileRow = sPoint->Y / TILE_SIZE + 2;
		////position for explosion three below detonation point
		int threeDownTileCol = sPoint->X / TILE_SIZE;
		int threeDownTileRow = sPoint->Y / TILE_SIZE + 3;

		////position for explosion two left of detonation point
		int twoLeftTileCol = sPoint->X / TILE_SIZE - 2;
		int twoLeftTileRow = sPoint->Y / TILE_SIZE;
		////position for explosion three left of detonation point
		int threeLeftTileCol = sPoint->X / TILE_SIZE - 3;
		int threeLeftTileRow = sPoint->Y / TILE_SIZE;


		//position for explosion two right of detonation point
		int twoRightTileCol = sPoint->X / TILE_SIZE + 2;
		int twoRightTileRow = sPoint->Y / TILE_SIZE;
		//position for explosion three right of detonation point
		int threeRightTileCol = sPoint->X / TILE_SIZE + 3;
		int threeRightTileRow = sPoint->Y / TILE_SIZE;

		//check the tile map to see if an explosion can occur on the given tile
		
		//two above detonation point
		if(canTravelUp && CheckExplosionPoint(twoUpTileRow, twoUpTileCol))
		{
			//if it can, set the draw point for the explosion
			drawPosX = twoUpTileCol * TILE_SIZE;
			drawPosY = twoUpTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}	
		else
			canTravelUp = false;

		//three above detonation point
		if(canTravelUp && CheckExplosionPoint(threeUpTileRow, threeUpTileCol))
		{
			//if it can, set the draw point for the explosion
			drawPosX = threeUpTileCol * TILE_SIZE;
			drawPosY = threeUpTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}	

		//two below detonation point
		if(canTravelDown && CheckExplosionPoint(twoDownTileRow, twoDownTileCol))
		{
			//if it can, set the draw point for the explosion
			drawPosX = twoDownTileCol * TILE_SIZE;
			drawPosY = twoDownTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}
		else
			canTravelDown = false;
		//three below detonation point
		if(canTravelDown && CheckExplosionPoint(threeDownTileRow, threeDownTileCol))
			
		{
			//if it can, set the draw point for the explosion
			drawPosX = threeDownTileCol * TILE_SIZE;
			drawPosY = threeDownTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}

		//two left of detonation point
		if(canTravelLeft && CheckExplosionPoint(twoLeftTileRow, twoLeftTileCol))
			
		{
			//if it can, set the draw point for the explosion
			drawPosX = twoLeftTileCol * TILE_SIZE;
			drawPosY = twoLeftTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}
		else
			canTravelLeft = false;

		//three left of detonation point
		if( canTravelLeft && CheckExplosionPoint(threeLeftTileRow, threeLeftTileCol))
		{
			//if it can, set the draw point for the explosion
			drawPosX = threeLeftTileCol * TILE_SIZE;
			drawPosY = threeLeftTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}

		//two right of detonation point
		if(canTravelRight && CheckExplosionPoint(twoRightTileRow, twoRightTileCol))
		{
			//if it can, set the draw point for the explosion
			drawPosX = twoRightTileCol * TILE_SIZE;
			drawPosY = twoRightTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}
		else
			canTravelRight = false;

		//three right of detonation point
		if(canTravelRight && CheckExplosionPoint(threeRightTileRow, threeRightTileCol))
		{
			//if it can, set the draw point for the explosion
			drawPosX = threeRightTileCol * TILE_SIZE;
			drawPosY = threeRightTileRow * TILE_SIZE;
			drawPoint = gcnew Point(drawPosX, drawPosY);
			//add the explosion to the explosion list
			AddExplosion(drawPoint);
		}	
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if a proposed explosion point is within the bounds of the game area and not on a wall tile.
/// Returns true if an explosion can happen on the given tile row/column
/// </summary>
bool GameManager::CheckExplosionPoint(int row, int col)
{
	bool canExplode = false;
	//check if the explosion point is within the bounds of the game area
	if(col > 0 && col < MAP_COLS && row > 0 && row < MAP_ROWS)
	{
		//set the row and col value as a point
		Point^ explosionPoint = gcnew Point(row, col);
		//check the TileMap to see if the outer explosion point is a breakable tile
		if(myTileMap->getIsBreakable(row, col))
		{
			//set the map value to floor
			myTileMap->setMapValue(row, col, FLOOR_TILE);
			//check if a buff dropped from the tile
			if(DropBuff())
			{
				//create a new point to draw the buff to
				int xPos = col * TILE_SIZE;
				int yPos = row * TILE_SIZE;
				Point^ drawPoint = gcnew Point(xPos, yPos);
				AddBuffToList(drawPoint);
			}			
		}

		//check the tile map to see if the outer explosion point is a floor tile
		if(myTileMap->getIsFloor(row, col))
			//Add explosion to explosion list
			canExplode = true;		
	}
	return canExplode;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Adds an explosion to explosionList.
/// </summary>
void GameManager::AddExplosion(Point^ sPoint)
{
	//create Bitmap array for explosion
	array<Bitmap^>^ animation = gcnew array<Bitmap^>(5);
	animation[0] = gcnew Bitmap("Flame\\Flame_f00.bmp");
	animation[0]->MakeTransparent(animation[0]->GetPixel(0, 0));
	animation[1] = gcnew Bitmap("Flame\\Flame_f01.bmp");
	animation[1]->MakeTransparent(animation[1]->GetPixel(0, 0));
	animation[2] = gcnew Bitmap("Flame\\Flame_f02.bmp");
	animation[2]->MakeTransparent(animation[2]->GetPixel(0, 0));
	animation[3] = gcnew Bitmap("Flame\\Flame_f03.bmp");
	animation[3]->MakeTransparent(animation[3]->GetPixel(0, 0));
	animation[4] = gcnew Bitmap("Flame\\Flame_f04.bmp");
	animation[4]->MakeTransparent(animation[4]->GetPixel(0, 0));

	//create Explosion instance
	Explosion^ nExplosion = gcnew Explosion(buffer, animation, sPoint, TILE_SIZE, TILE_SIZE, EXPLOSION_TIMER, 5);
	//add Explosion to ExplosionLinkedList
	explosionList->AddExplosion(nExplosion);
}

/// <summary>
/// Handles the explosion objects logic when the timer ticks. 
/// </summary>
void GameManager::HandleExplosion()
{
	if(explosionList->CountExplosion() > 0)
	{
		//remove all explosions that are no longer live
		explosionList->ExplosionCleanup();

		//check if the player has been hit by the explosion
		if(explosionList->CheckSpriteCollision(myPlayer))
			PlayerHit();

		//set monsterList as an array
		array<Sprite^>^ monsterArray = monsterList->MakeArray();
		
		for(int i = 0; i < monsterArray->Length; i++)
		{
			//check if the explosion hit the monster and the monster hasn't been hit recently
			if(explosionList->CheckSpriteCollision(monsterArray[i]) 
				&& monsterArray[i]->getIsHit() == false)
			{
				//remove a life from monster
				monsterArray[i]->setLives(monsterArray[i]->getLives() - 1);
				
				//check if the monster has any lives left
				if(monsterArray[i]->getLives() == 0)
				{
					//check if the monster dropped a buff
					if(DropBuff())
					{ 
						//BUG if a monster drops a bug, the ghost will carry it as it moves.(fixed)
						//create a point to draw a buff based on the monsters position
						int buffXPos = monsterArray[i]->getPosition()->X;
						int buffYPos = monsterArray[i]->getPosition()->Y;
						Point^ buffPos = gcnew Point(buffXPos, buffYPos);
						//if it did, add one to the list
						AddBuffToList(monsterArray[i]->getPosition());
					}
					//create a point to draw the ghost based on the dead monsters position
					int ghostXPos = monsterArray[i]->getPosition()->X;
					int ghostYPos = monsterArray[i]->getPosition()->Y;
					Point^ ghostPos = gcnew Point(ghostXPos, ghostYPos);
					//create a ghost on the monsters draw position
					AddGhost(ghostPos);

					//remove the monster from the list
					monsterList->DeleteSprite(monsterArray[i]);
					
					//increment the players score
					myPlayer->setScore(myPlayer->getScore() + POINT);
					scoreOutput->Text = Convert::ToString(myPlayer->getScore());

					//check if the list is empty
					if(monsterList->CountSprites() == 0)
						//if it is, start a new level
						LoadLevel();					
				}
				//if they do, set the timer which prevents the monster from taking another hit
				else
					monsterArray[i]->SpriteGotHit();
			}
		}
		explosionList->DrawAll();
		explosionList->DecayTimer();
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Handles the timer countdown of the buffs currently on the game screen when the timer ticks.
/// </summary>
void GameManager::HandleBuff()
{
	if(buffList->CountBuffs() > 0)
	{
		//create an array of buffs to see if the player has stepped over any
		array<Buff^>^ buffArray = buffList->MakeArray();
		//remove all buffs that are no longer active 
		buffList->BuffCleanup();
		//cycle through each buff in the array
		for(int i = 0; i < buffArray->Length; i++)
		{
			//check if the player has hit a buff
			if(buffArray[i]->SpriteCollision(myPlayer))
			{
				//give the player a buff 
				myPlayer->RecieveBuff(buffArray[i]->getType());
				//delete the buff from the buffList
				buffList->DeleteBuff(buffArray[i]);
			}
		}
		//draw all the buffs
		buffList->Draw();		
		//decay all the buffs timers
		buffList->DecayTimer();		
	}	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decides if a monster or explodable wall object dropped a buff
/// </summary>
bool GameManager::DropBuff()
{
	bool didDrop = false;
	int roll = rand->Next(3);
	if(roll == 0)
		didDrop = true;
	return didDrop;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Adds a buff to the buffList when a monster or explodable wall object drops a buff  
/// </summary>
void GameManager::AddBuffToList(Point^ drawPoint)
{
	Buff^ newBuff;
	Bitmap^ buffImage;
	//choose a buff type
	int buffType = PickBuff();
	//choose a buff to add to the linked list based on buffType;
	switch(buffType)
	{
	case AOE_BUFF:
		//set the buffs image
		buffImage = gcnew Bitmap("Powerups\\FlamePowerup.bmp");
		//make the corners transparent
		buffImage->MakeTransparent(buffImage->GetPixel(0, 0));
		//initialize the new buff
		newBuff = gcnew Buff(buffer, buffImage, drawPoint, TILE_SIZE, TILE_SIZE, BUFF_TIMER, AOE_BUFF);
		//add the new buff to the buffList
		buffList->AddBuff(newBuff);
		break;
	case BOMB_NUM_BUFF:
		//set the buffs image
		buffImage = gcnew Bitmap("Powerups\\BombPowerup.bmp");
		//make the corners transparent
		buffImage->MakeTransparent(buffImage->GetPixel(0, 0));
		//initialize the new buff
		newBuff = gcnew Buff(buffer, buffImage, drawPoint, TILE_SIZE, TILE_SIZE, BUFF_TIMER, BOMB_NUM_BUFF);
		//add the new buff to the buffList
		buffList->AddBuff(newBuff);
		break;
	case MOVE_BUFF:
		//set the buffs image
		buffImage = gcnew Bitmap("Powerups\\SpeedPowerup.bmp");
		//make the corners transparent
		buffImage->MakeTransparent(buffImage->GetPixel(0, 0));
		//initialize the new buff
		newBuff = gcnew Buff(buffer, buffImage, drawPoint, TILE_SIZE, TILE_SIZE, BUFF_TIMER, MOVE_BUFF);
		//add the new buff to the buffList
		buffList->AddBuff(newBuff);
		break;
	default:
		break;	
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Loads the map values to the tile map
/// </summary>
void GameManager::LoadLevel()
{	
	LevelTransitionCleanup();
	
	if(screen == TITLE_SCREEN)
		//load the title screen
		myTileMap->LoadFromFile("titleScreen.csv");
	else if(screen == LVL_1)
	{
		//load the game map
		myTileMap->LoadFromFile("level1.csv");	
		//load the sprites that appear in the game map
		LoadSprites("level1Sprites.csv");		
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// When the player clicks on the form when the title screen is displayed, this function checks if they clicked on 
/// the play button
/// </summary>
bool GameManager::ClickedButton(Point^ click)
{
	bool didClick = true;
	int btnRight = BTN_POSX + BTN_WIDTH;
	int btnBot = BTN_POSY + BTN_HEIGHT;
	
	//check if the click was within the button's left bounds
	if(click->X < BTN_POSX)
		didClick = false;
	//check if the click was within the button's right bounds
	else if(click->X > btnRight)
		didClick = false;
	//check if the click was within the button's top bounds
	else if(click->Y < BTN_POSY)
		didClick = false;
	//check if the click was withing the button's bottom bounds
	else if(click->Y > btnBot)
		didClick = false;

	return didClick;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// This function starts a new game. .
/// </summary>
void GameManager::NewGame()
{
	//set the players score and lives stats
	myPlayer->setScore(0);
	myPlayer->setLives(PLAYER_LIVES);
	//reset the score and lives output
	scoreOutput->Text = Convert::ToString(myPlayer->getScore());
	livesOutput->Text = Convert::ToString(myPlayer->getLives());
	//set the screen to the game level
	screen = LVL_1;
	//load the game level to the tile map
	myTileMap->LoadFromFile("level1.csv");
	LoadLevel();
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Loads the game sprites when the player starts a new level.
/// </summary>
void GameManager::LoadSprites(String^ spriteFile)
{
	//NOTE csv format: sprite type, drawposx, drawposy

	//set up a streamreader
	StreamReader^ sr = File::OpenText(spriteFile);
	String^ line;	
	//initialize the sprites draw coordinates
	Point^ spriteDrawPoint;	
	//initialize the monsters spriteSheet strings
	String^ weakUp = "Monsters\\weak_up.bmp";
	String^ weakDown = "Monsters\\weak_dwn.bmp";
	String^ weakRight = "Monsters\\weak_rght.bmp";
	String^ weakLeft = "Monsters\\weak_lft.bmp";

	String^ strongUp = "Monsters\\strong_up.bmp";
	String^ strongDown = "Monsters\\strong_dwn.bmp";
	String^ strongRight = "Monsters\\strong_rght.bmp";
	String^ strongLeft = "Monsters\\strong_lft.bmp";

	while(line = sr->ReadLine())
	{
		//create an array of strings that is a split of the current line
		array<String^>^ lineArray = line->Split(',');
		
		//choose the type of sprite to draw 
		int spriteType = Convert::ToInt16(lineArray[SPRITE_TYPE]);
		
		//convert to string coordinates in the lineArray to integers
		int drawPosX = Convert::ToInt16(lineArray[SPRITE_DRAWX]);
		int drawPosY = Convert::ToInt16(lineArray[SPRITE_DRAWY]);
		
		//draw the sprite based on the type of sprite
		//draw player
		if(spriteType == PLAYER)
		{
			//create sprite	draw point
			spriteDrawPoint = gcnew Point(drawPosX, drawPosY);
			
			//set the draw and hitbox position
			myPlayer->setDrawPos(spriteDrawPoint);
			myPlayer->SetHitBox();
			myPlayer->MoveCenterPoint();
		}
		//draw weak monster
		else if(spriteType == WEAK_MONSTER)
		{
			//create sprite	draw point
			spriteDrawPoint = gcnew Point(drawPosX, drawPosY);
			
			BasicMonster^ nBasicMonster = gcnew BasicMonster(buffer, weakUp, weakDown, weakLeft, weakRight,
				MONSTER_FRAMES, spriteDrawPoint, TILE_SIZE, TILE_SIZE, MONSTER_DEFAULT_MOVESPEED, WEAK_MONSTER_LIVES, BASIC_HITBOX_OFFSETX, BASIC_HITBOX_OFFSETY, BASIC_HITBOX_WIDTH
				,BASIC_HITBOX_HEIGHT, rand);
			monsterList->AddSprite(nBasicMonster);			
		}		
		//draw strong monster
		else if(spriteType == STRONG_MONSTER)
		{
			//create sprite	draw point
			spriteDrawPoint = gcnew Point(drawPosX, drawPosY);
			
			BasicMonster^ nBasicMonster = gcnew BasicMonster(buffer, strongUp, strongDown, strongLeft, strongRight,
				MONSTER_FRAMES, spriteDrawPoint, TILE_SIZE, TILE_SIZE, MONSTER_DEFAULT_MOVESPEED, STRONG_MONSTER_LIVES, BASIC_HITBOX_OFFSETX, 
				BASIC_HITBOX_OFFSETY, BASIC_HITBOX_WIDTH, BASIC_HITBOX_HEIGHT, rand);
			monsterList->AddSprite(nBasicMonster);			
		}
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Handles the monsters movement logic when the timer ticks, checks if the monsters where hit by
/// an explosion, and draws the monsters to screen
/// </summary>
void GameManager::HandleMonsters()
{
	if(monsterList->CountSprites() > 0)
	{
		//create a monster array
		array<Sprite^>^ monsterArray = monsterList->MakeArray();
		
		for(int i = 0; i < monsterArray->Length; i++)
		{
			//check if the monster can move in the proposed direction
			if(MoveSprite(monsterArray[i]))
			{
				monsterArray[i]->Move();
				monsterArray[i]->SetHitBox();
			}
			//if not change direction
			else
				monsterArray[i]->ChooseRandomDirection();	

			//decay the monsters isHit timer if the monster has been recently hit
			if(monsterArray[i]->getIsHit())
				monsterArray[i]->DecayHitTimer();
		}

		//check if the player recently got hit (grants hit immunity briefly)
		if(!myPlayer->getIsHit())
		{
			//check if the monster collided with the player
			if(monsterList->CheckCollision(myPlayer))
			{
				if(!myPlayer->getIsHit())
					PlayerHit();
			}
		}		
		//draw all the monsters
		monsterList->DrawAll();
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// MoveSprite uses the sprites look ahead function to determine if there next move will cause a 
/// overlap with a wall tile
/// </summary>
bool GameManager::MoveSprite(Sprite^ sprite)
{
	//canMove is used to determine if the sprite will collide with a non wall tile when he moves
	bool canMove = true;
	//get the hitbox area of the sprites proposed move
	Point^ nextHitBoxPos = sprite->LookAhead();
	//calculate the tiles that the sprite will occupy when the proposed move is performed
	//(endRowTile and endColTile have been trimmed so that the sprite can move through
	//narrow passages)
	int startRowTile = nextHitBoxPos->Y / TILE_SIZE;
	int endRowTile = (nextHitBoxPos->Y + sprite->getHitBoxHeight() - 1) / TILE_SIZE;
	int startColTile = nextHitBoxPos->X / TILE_SIZE;
	int endColTile = (nextHitBoxPos->X + sprite->getHitBoxWidth() - 1) / TILE_SIZE;

	//double for loop to cycle through each tile that nextHitBoxPos occupies
	for(int row = startRowTile; row <= endRowTile; row++)
	{
		for(int col = startColTile; col <= endColTile; col++)
		{
			//check that the current tile is a floor
			if(!myTileMap->getIsFloor(row, col))
				//if not, the sprite cant move to that area
				canMove = false;
		}
	}

	//check if the sprite is trying to move into a tile occupied by a bomb
	if(sprite->getCanMovePastBomb() == false &&
		canMove == true)
	{
		//CheckSpriteCollision takes a sprite, and checks if the sprites proposed move will cause
		//a collision with a bomb.
		if(bombList->CheckSpriteCollision(sprite))
		{
			canMove = false;
		}
	}
	return canMove;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Removes all the explosions and buffs from the Linked lists when transitioning levels
/// </summary>
void GameManager::LevelTransitionCleanup()
{

	//check if there are explosions in the linked list
	if(explosionList->CountExplosion() > 0)
	{
		int expTotal = explosionList->CountExplosion();
		//create an array of explosions
		array<Explosion^>^ expArray = explosionList->MakeArray();

		//cycle through the array, removing explosions from the list
		for(int i = 0; i <expTotal; i++)
			explosionList->DeleteExplosion(expArray[i]);
	}

	//check if there are buffs in the linked list
	if(buffList->CountBuffs() > 0)
	{
		int buffTotal = buffList->CountBuffs();
		//create an array of buffs
		array<Buff^>^ buffArray = buffList->MakeArray();

		//cycle through the array, removing buffs from the list
		for(int i = 0; i < buffTotal; i++)
			buffList->DeleteBuff(buffArray[i]);
	}
	
	//check if there are bombs in the linked list
	if(bombList->CountBombs() > 0)
	{
		int bombTotal = bombList->CountBombs();
		//create an array of bombs
		array<Bomb^>^ bombArray = bombList->MakeArray();

		//cycle through the array, removing the bombs from the list
		for(int i = 0; i < bombTotal; i++)
			bombList->DeleteBomb(bombArray[i]);
	}

	//check if there are any monsters in the linked list (needed for returning to the title screen)
	if(monsterList->CountSprites() > 0)
	{
		int monsterTotal = monsterList->CountSprites();
		//create an array of monsters
		array<Sprite^>^ monsterArray = monsterList->MakeArray();

		//cycle through the array, removing monsters from the list
		for(int i = 0; i < monsterTotal; i++)
			monsterList->DeleteSprite(monsterArray[i]);
	}

	//check if there are any ghosts in the linked list 
	if(ghostList->CountSprites() > 0)
	{
		int ghostTotal = ghostList->CountSprites();

		//create an array of ghosts
		array<Sprite^>^ ghostArray = ghostList->MakeArray();

		//cycle through the array, removing monsters from the list
		for(int i = 0; i < ghostTotal; i++)
			ghostList->DeleteSprite(ghostArray[i]);
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// checks if the player has been hit recently, and if they haven't this removes a life and
/// grants the player temporary hit immunity
/// </summary>
void GameManager::PlayerHit()
{
	//check if the player has been hit recently
	if(!myPlayer->getIsHit())
	{
		//remove a life
		myPlayer->setLives(myPlayer->getLives() - 1);
		//update life output
		livesOutput->Text = Convert::ToString(myPlayer->getLives());
		//check if the player has any lives left
		if(myPlayer->getLives() > 0)
		{
			//if yes set PlayerGotHit
			myPlayer->SpriteGotHit();
		}
		else
		{			
			//if not, clear all the player buffs
			myPlayer->ClearAllBuffs();
			//then go to the title screen
			screen = TITLE_SCREEN;
			LoadLevel();
		}
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Moves the player when they use a warp portal
/// </summary>
void GameManager::WarpPlayer(int row, int col)
{
	//initialize the data needed for moving the player
	int drawPosX;
	int drawPosY;
	Point^ playerDrawPoint;
	
	//determine the players new coordinates based on the tile under the players centerPoint
	if(row == 2 && col == 3)
	{
		drawPosX = 832;
		drawPosY = 480;
	}
	else if(row == 16 && col == 25)
	{
		drawPosX = 64;
		drawPosY = 32;
	}
	else if(row == 16 && col == 3)
	{
		drawPosX = 832;
		drawPosY = 32;
	}
	else if(row == 2 && col == 25)
	{
		drawPosX = 64;
		drawPosY = 480;
	}
	//create player	draw point
	playerDrawPoint = gcnew Point(drawPosX, drawPosY);
	//set the draw and hitbox position
	myPlayer->setDrawPos(playerDrawPoint);
	myPlayer->SetHitBox();
	myPlayer->MoveCenterPoint();
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Adds a ghost to the ghostList
/// </summary>
void GameManager::AddGhost(Point^ drawPos)
{
	//set the rectangle that will act as the ghosts bounds
	Rectangle^ ghostBounds = gcnew Rectangle(0, 0, screenWidth, screenHeight);
	//set the strings that refer to the ghosts bitmap sprite sheets
	String^ upSheet = "Monsters\\ghost_up.bmp";
	String^ downSheet = "Monsters\\ghost_dwn.bmp";
	String^ leftSheet = "Monsters\\ghost_lft.bmp";
	String^ rightSheet = "Monsters\\ghost_rght.bmp";
	//initialize a new ghost
	Ghost^ ghost = gcnew Ghost(buffer, upSheet, downSheet, leftSheet, rightSheet, 
		GHOST_FRAMES, drawPos, TILE_SIZE, TILE_SIZE, GHOST_DEFAULT_MOVESPEED, rand, ghostBounds);
	//add to the ghostList
	ghostList->AddSprite(ghost);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Handles the ghosts movement and draw functions
/// </summary>
void  GameManager::HandleGhosts()
{
	if(ghostList->CountSprites() > 0)
	{		
		ghostList->MoveAll();
		ghostList->DrawAll();
	}
}//End//////////////////////////////////////////////////////////////////////////////