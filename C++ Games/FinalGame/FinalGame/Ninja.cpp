#include "StdAfx.h"
#include "Ninja.h"

//***********
//Constructor
//***********
Ninja::Ninja(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize, int sGravity, int sYSpeed, int sMaxFallSpeed)
		: Sprite (sCanvas, sDrawWidth, sDrawHeight, sHitBoxWidth, sHitBoxHeight, 
		sXPos, sYPos, sDrawOffsetX, sDrawOffsetY, sSpriteState, sDirFacing, sXSpeed, sScreenSize, sTileSize)
{
	numJet = 0;
	numShuriken = 0;

	gravity = sGravity;
	ySpeed = sYSpeed;
	maxFallSpeed = sMaxFallSpeed;
	
	curWalkFrame = 0;
	totWalkFrame = NINJA_FRAMES;

	InitializeSprites();
}//*************************************************************************************

//*********************************************
//Draws the ninja sprite to the graphics buffer
//*********************************************
void Ninja::Draw()
{
	//determine the sprites position on screen
	int screenYPos = NINJA_SCREEN_Y;
	int screenXPos = xPos + drawOffsetX;
	Point^ drawPos = gcnew Point(screenXPos, screenYPos);
	
	//choose the sprite bitmap to draw based on the sprites state
	switch(spriteState)
	{
	case WALKING:
		canvas->DrawImage(spriteWalkAnimation[dirFacing],drawPos->X, drawPos->Y, 
			Rectangle(curWalkFrame * drawWidth, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		IncrementFrame();
		break;
	case STANDING:		
		canvas->DrawImage(standBitmap[dirFacing], drawPos->X, drawPos->Y,
			Rectangle(0, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		break;
	case JUMPING:
		canvas->DrawImage(jumpBitmap[dirFacing], drawPos->X, drawPos->Y,
			Rectangle(0, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		break;
	case FALLING:
		canvas->DrawImage(fallBitmap[dirFacing], drawPos->X, drawPos->Y,
			Rectangle(0, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		break;
	case JET_JUMP:
		canvas->DrawImage(jetBitmap[dirFacing], drawPos->X, drawPos->Y,
			Rectangle(0, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		break;
	case HIT:
		canvas->DrawImage(hitBitmap[dirFacing], drawPos->X, drawPos->Y,
			Rectangle(0, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		break;
	}
}//*************************************************************************************

//**************************************************************
//initializes the ninjas move and animation sprites on game load
//**************************************************************
void Ninja::InitializeSprites()
{
	//path to the sprite folder
	String^ filePath = "Sprites\\";

	//construct the sprite arrays that hold the ninja bitmap
	spriteWalkAnimation = gcnew array<Bitmap^>(2);	
	standBitmap = gcnew array<Bitmap^>(2);
	jumpBitmap = gcnew array<Bitmap^>(2);
	fallBitmap = gcnew array<Bitmap^>(2);
	jetBitmap = gcnew array<Bitmap^>(2);
	hitBitmap = gcnew array<Bitmap^>(2);
	
	//***********************************
	//initialize the ninja walk animation
	//***********************************

	//initialize the bitmaps
	Bitmap^ walkLeft = gcnew Bitmap(filePath + "playerMoveLeft.bmp");
	walkLeft->MakeTransparent(walkLeft->GetPixel(0, 0));

	Bitmap^ walkRight = gcnew Bitmap(filePath + "playerMoveRight.bmp");
	walkRight->MakeTransparent(walkRight->GetPixel(0, 0));

	//add to the spriteWalkAnimation array
	spriteWalkAnimation[LEFT] = walkLeft;
	spriteWalkAnimation[RIGHT] = walkRight;
	
	//*********************************
	//initialize the ninja stand bitmap
	//*********************************

	//initialize the bitmaps
	Bitmap^ standLeft = gcnew Bitmap(filePath + "standLeft.bmp");
	standLeft->MakeTransparent(standLeft->GetPixel(0, 0));

	Bitmap^ standRight = gcnew Bitmap(filePath + "standRight.bmp");
	standRight->MakeTransparent(standRight->GetPixel(0, 0));

	//add to the standBitmap array
	standBitmap[LEFT] = standLeft;
	standBitmap[RIGHT] = standRight;

	//********************************
	//initialize the ninja jump bitmap
	//********************************

	//initialize the bitmaps
	Bitmap^ jumpLeft = gcnew Bitmap(filePath + "jumpLeft.bmp");
	jumpLeft->MakeTransparent(jumpLeft->GetPixel(0, 0));

	Bitmap^ jumpRight = gcnew Bitmap(filePath + "jumpRight.bmp");
	jumpRight->MakeTransparent(jumpRight->GetPixel(0, 0));

	//add to the jump bitmap array
	jumpBitmap[LEFT] = jumpLeft;
	jumpBitmap[RIGHT] = jumpRight;

	//********************************
	//initialize the ninja fall bitmap
	//********************************
	
	//initialize the bitmaps
	Bitmap^ fallLeft = gcnew Bitmap(filePath + "fallLeft.bmp");
	fallLeft->MakeTransparent(fallLeft->GetPixel(0, 0));

	Bitmap^ fallRight = gcnew Bitmap(filePath + "fallRight.bmp");
	fallRight->MakeTransparent(fallRight->GetPixel(0, 0));

	//add the fall bitmaps to array
	fallBitmap[LEFT] = fallLeft;
	fallBitmap[RIGHT] = fallRight;
	
	//*******************************
	//initialize the ninja jet bitmap
	//*******************************

	//initialize the bitmaps
	Bitmap^ jetLeft = gcnew Bitmap(filePath + "boostLeft.bmp");
	jetLeft->MakeTransparent(jetLeft->GetPixel(0, 0));

	Bitmap^ jetRight = gcnew Bitmap(filePath + "boostRight.bmp");
	jetRight->MakeTransparent(jetRight->GetPixel(0, 0));

	//add the jet move bitmaps to the array
	jetBitmap[LEFT] = jetLeft;
	jetBitmap[RIGHT] = jetRight;

	//*********************************
	//initialize the ninja hit bitmap
	//*********************************

	//initialize the bitmaps 
	Bitmap^ hitLeft = gcnew Bitmap(filePath + "hitLeft.bmp");
	hitLeft->MakeTransparent(hitLeft->GetPixel(0, 0));

	Bitmap^ hitRight = gcnew Bitmap(filePath + "hitRight.bmp");
	hitRight->MakeTransparent(hitRight->GetPixel(0, 0));

	//add the hit bitmaps to the array
	hitBitmap[LEFT] = hitLeft;
	hitBitmap[RIGHT] = hitRight;
}//*************************************************************************************

//*****************************************************************************************
//UpdateState calls the functions used to determine if the sprite needs to change its state
//*****************************************************************************************
void Ninja::UpdateState()
{
	//************************
	//update the players state
	//************************
	switch(spriteState)
	{
	case WALKING:

		SpriteWalkUpdate();		
		break;

	case STANDING:
		
		NinjaStandUpdate();		
		break;

	case JUMPING:
	case JET_JUMP:
	case FALLING:
		NinjaJumpUpdate();
		break;

	case HIT:
		NinjaHitUpdate();
		break;

	default:
		break;
	}
}//*************************************************************************************

//************************************************************************************
//Function to decide if the sprite needs to change state while it is in the walk state
//************************************************************************************
void Ninja::SpriteWalkUpdate()
{
	//check if the sprite needs to stop walking
	if(startStand)
	{
		//if yes, set state to standing and turn off startStand flag
		spriteState = STANDING;
		startStand = false;

		//set sprites xVel to 0
		xVel = 0;
		//set sprites curFrame to 0
		curWalkFrame = 0;
	}

	//check if the sprite needs to start jumping
	if(startJump)
	{
		spriteState = JUMPING;
		startJump = false;
		yVel = ySpeed;
		lastWallJumpDir = NONE;
		//turn of isHit if it got activated (bug fix)
		if(isHit)
			isHit = false;
	}

	//check if the sprite needs to start falling
	if(startFall)
	{
		spriteState = FALLING;
		startFall = false;
		yVel = gravity;
	}

	//check if the sprite has started a jet jump
	if(startJetJump)
	{
		spriteState = JET_JUMP;
		startJetJump = false;
		yVel = ySpeed * 2;
	}

	//check if the sprite has been hit
	if(isHit)
	{
		spriteState = HIT;
		hitCountdown = 20;
	}
}//*************************************************************************************

//*************************************************************************************
//Function to decide if the sprite needs to change state while it is in the stand state
//*************************************************************************************
void Ninja::NinjaStandUpdate()
{
	//check if the sprite needs to start walking
	if(startWalk)
	{
		//if yes, set state to walking and turn off startWalk flag
		spriteState = WALKING;
		startWalk = false;

		//set the sprites xVel based on the direction its moving

		//right
		if(dirFacing == RIGHT)
			xVel = xSpeed;
		//left
		else
			xVel = xSpeed * -1;
	}
	//check if the sprite needs to start jumping
	if(startJump)
	{
		spriteState = JUMPING;
		startJump = false;
		yVel = ySpeed;
		lastWallJumpDir = NONE;
	}

	//check if the sprite has started a jet jump
	if(startJetJump)
	{
		spriteState = JET_JUMP;
		startJetJump = false;
		yVel = ySpeed * 2;
	}

	//check if the sprite has been hit
	if(isHit)
	{
		spriteState = HIT;
		hitCountdown = 20;
	}
}//*************************************************************************************

//************************************************************************************
//Function to decide if the sprite needs to change state while it is in the jump state
//************************************************************************************
void Ninja::NinjaJumpUpdate()
{
	//check if the sprite needs to stop jumping
	if(startStand)
	{
		//if yes, set state to standing and turn off startStand flag
		spriteState = STANDING;
		startStand = false;

		//set sprites yVel and xVel to 0
		xVel = 0;
		yVel = 0;
		//set sprites curFrame to 0
		curWalkFrame = 0;
	}
	
	//check if the sprite is ready to perform a wall jump and is in the jump state
	if(readyToWallJump && spriteState == JUMPING)
	{
		//if it is, decrement the wallJumpTimer
		wallJumpTimer -=1;
		if(wallJumpTimer == 0)
		{
			//and set its readyToWallJump bool to false.
			readyToWallJump = false;			
		}
	}
	
	//check if the sprite has been hit (this check is used to prevent a bug)
	if(isHit)
	{
		//if it is, set it's isHit to false		
		isHit = false;
	}
}//*************************************************************************************

//************************************************************************************
//Function to decide if the sprite needs to change state while it is in the jump state
//************************************************************************************
void Ninja::NinjaHitUpdate()
{
	//hitCountdown is used to prevent a bug that causes the player to be permanently hit.
	hitCountdown -= 1;

	if(hitCountdown <= 0)
		isHit = false;

	//when the player has stopped being hit, it enters the fall state by default, as a goblin would
	//of pushed the sprite off the edge of a platform (providing the hit state wasn't triggered by a bug)
	if(!isHit)
	{
		spriteState = FALLING;		
		yVel = gravity;
	}
}//*************************************************************************************

//*******************************************************************************************
//PerformAction calls the functions used to determine if the sprite needs to change its state
//*******************************************************************************************
void Ninja::PerformAction(TileMapList^ tileMapList, TileList^ tileList)
{
	//****************************
	//determine the players action
	//****************************
	switch(spriteState)
	{
		case WALKING:
		{			
			MoveAction(tileMapList, tileList);			
			break;
		}
		case JUMPING:
		case FALLING:
		case JET_JUMP:
		{
			JumpAction(tileMapList, tileList);						
			break;
		}
		default:
			break;
	}
}//*************************************************************************************

//******************************************************
//Move the player sprite when it is in the walking state
//******************************************************
void Ninja::MoveAction(TileMapList^ tileMapList, TileList^ tileList)
{
	//get the sprites next move position 
	Point^ nextPos = NextPosition();	

	//get the top and bot map number 
	int topMapNum = ResolveMapNumber(nextPos->Y);
	int botMapNum = ResolveMapNumber(nextPos->Y + hitBoxHeight);

	//get the top and bot y number for tile reference 
	int topTileY = ResolveTileYNumber(nextPos->Y);
	int botTileY = ResolveTileYNumber(nextPos->Y + hitBoxHeight);

	//get the  left and right x number for tile reference
	int tileLeftX = ResolveTileXNumber(nextPos->X);
	int tileRightX = ResolveTileXNumber(nextPos->X + hitBoxWidth);
					
	//check if the top right tile is a solid object
	bool topRightSolid = tileMapList->FetchIsTileSolid(topMapNum, tileList, tileRightX, topTileY);
	
	//check if the bot right tile is a solid object
	bool botRightSolid =  tileMapList->FetchIsTileSolid(botMapNum, tileList, tileRightX, botTileY);

	//check if the top left tile is a solid object
	bool topLeftSolid = tileMapList->FetchIsTileSolid(topMapNum, tileList, tileLeftX, topTileY);	
				
	//check if the bot left tile is a solid object
	bool botLeftSolid =  tileMapList->FetchIsTileSolid(botMapNum, tileList, tileLeftX,  botTileY);

	//********************************************
	//determine the direction the sprite is moving
	//********************************************
			
	//*****
	//right
	//*****
	if(dirFacing == RIGHT)
	{
		//******************************************
		//check if the player has walked into a wall
		//******************************************
		if(topRightSolid == true || botRightSolid == true)
		{			
			//if they have, set a flag to change the sprites state to standing
			if(spriteState == WALKING)
				startStand = true;

			//set xVel to 0
			xVel = 0;
			
			//set the nextPos->X to the left of the right hand wall
			nextPos->X = AvoidTileCollisionRight(tileRightX);
		}
	}
	//****
	//left
	//****
	else
	{
		//check if the player has walked into a wall
		if(topLeftSolid == true || botLeftSolid == true)
		{			
			//if they have, set a flag to change the sprites state to standing
			if(spriteState == WALKING)
				startStand = true;

			//set xVel to 0
			xVel = 0;

			//set the nextPos->X to the right of the left hand wall
			nextPos->X = AvoidTileCollisionLeft(tileLeftX);
		}
	}
	//when the previous code is completed successfully, the sprite can 
	//be moved to a new position on the screen 
	xPos = nextPos->X;

	//check if the sprite is falling
	Point^ leftFoot = gcnew Point(xPos, yPos + hitBoxHeight);
	Point^ rightFoot = gcnew Point(xPos + hitBoxWidth, yPos + hitBoxHeight);
	
	//check if the player is standing on a solid tile
	if(!CheckGroundTile(tileMapList, tileList)) 
	{	
		//if not, set the flag to tell the update handler to make the sprite start falling
		startFall = true;
	}
}//*************************************************************************************

//***************************************************
//Move the player sprite when it is in the jump state
//***************************************************
void Ninja::JumpAction(TileMapList^ tileMapList, TileList^ tileList)
{
	//check that the ninjas next fall speed isn't going to exceed the max fall speed	
	if(yVel + gravity > maxFallSpeed)	
	{
		//if it is, set its yVel to max fall speed
		yVel = maxFallSpeed;		
	}
	else
	{
		//otherwise, increase its yVel by gravity
		yVel += gravity;
	}

	//get the sprites next move position 
	Point^ nextPos = NextPosition();

	//get the top and bot map number 
	int topMapNum = ResolveMapNumber(nextPos->Y);
	int botMapNum = ResolveMapNumber(nextPos->Y + hitBoxHeight);

	//get the top and bot y number for tile reference 
	int topTileY = ResolveTileYNumber(nextPos->Y);
	int botTileY = ResolveTileYNumber(nextPos->Y + hitBoxHeight);

	//get the  left and right x number for tile reference
	int tileLeftX = ResolveTileXNumber(nextPos->X - 1);
	int tileRightX = ResolveTileXNumber(nextPos->X + hitBoxWidth);
					
	//check if the top right tile is a solid object
	bool topRightSolid = tileMapList->FetchIsTileSolid(topMapNum, tileList, tileRightX, topTileY);
	
	//check if the bot right tile is a solid object
	bool botRightSolid =  tileMapList->FetchIsTileSolid(botMapNum, tileList, tileRightX, botTileY);

	//check if the top left tile is a solid object
	bool topLeftSolid = tileMapList->FetchIsTileSolid(topMapNum, tileList, tileLeftX, topTileY);	
				
	//check if the bot left tile is a solid object
	bool botLeftSolid =  tileMapList->FetchIsTileSolid(botMapNum, tileList, tileLeftX,  botTileY);
	
	//************************************
	//check collision with right hand wall
	//************************************
	if(topRightSolid && botRightSolid)
	{	
		//check if the sprite can perform a wall jump
		if(readyToWallJump && lastWallJumpDir != RIGHT)
		{
			readyToWallJump = false;
			wallJumpTimer = 0;
			yVel = ySpeed;
			xVel = xSpeed * -1;
			dirFacing = LEFT;
			//prevent the sprite from performing another wall jump on a right hand wall
			lastWallJumpDir = RIGHT;
		}
		else
		{
			//set xVel to 0
			xVel = 0;		
		}
		//set the nextPos->X to the left of the right hand wall
		nextPos->X = AvoidTileCollisionRight(tileRightX);
	}
	//************************************
	//check collision with left hand wall
	//************************************
	else if(botLeftSolid && topLeftSolid)
	{
		//check if the sprite can perform a wall jump
		if(readyToWallJump && lastWallJumpDir != LEFT)
		{
			readyToWallJump = false;
			wallJumpTimer = 0;
			yVel = ySpeed;
			xVel = xVel * -1;
			dirFacing = RIGHT;
			//prevent the sprite from performing another wall jump on a left hand wall
			lastWallJumpDir = LEFT;
		}
		else
		{
			//set xVel to 0
			xVel = 0;
		}
		//set the nextPos->X to the right of the left hand wall
		nextPos->X = AvoidTileCollisionLeft(tileLeftX);
	}
	else
	{
		//run a while loop when the ninja occupies a solid tile
		while(topRightSolid || botRightSolid || topLeftSolid || botLeftSolid)
		{			
			//****************************
			//check collision with ceiling
			//****************************
			if(topRightSolid || topLeftSolid)
			{
				//set yVel to 0
				yVel = 0;

				//set nextPos->Y to just below the tile 
				nextPos->Y += AvoidTileCollisionUp(nextPos->Y);	
				
				//move the sprite position back one pixel based on which solid tile it collided with.
				if(topRightSolid)
				{
					nextPos->X -= 1;
				}
				if(topLeftSolid)
				{
					nextPos->X += 1;
				}
				//recalculate the variables used to determine if a tile is solid
				topTileY = ResolveTileYNumber(nextPos->Y);
				tileLeftX = ResolveTileXNumber(nextPos->X);
				tileRightX = ResolveTileXNumber(nextPos->X + hitBoxWidth);
				topRightSolid = tileMapList->FetchIsTileSolid(topMapNum, tileList, tileRightX, topTileY);
				topLeftSolid = tileMapList->FetchIsTileSolid(topMapNum, tileList, tileLeftX, topTileY);	
			}

			//**************************
			//check collision with floor
			//**************************
			else if(botRightSolid || botLeftSolid)
			{
				yVel = 0;
				//set nextPos->Y to just below the tile 
				nextPos->Y -= AvoidCollisionDown(nextPos->Y);
				
				//move the sprite position back one pixel based on which solid tile it collided with.
				if(botRightSolid)
				{
					nextPos->X -= 1;
				}
				if(botLeftSolid)
				{
					nextPos->X += 1;
				}

				//recalculate the variables used to determine if a tile is solid
				botTileY = ResolveTileYNumber(nextPos->Y + hitBoxHeight);	
				tileLeftX = ResolveTileXNumber(nextPos->X);
				tileRightX = ResolveTileXNumber(nextPos->X + hitBoxWidth);
				botRightSolid =  tileMapList->FetchIsTileSolid(botMapNum, tileList, tileRightX, botTileY);		
				botLeftSolid =  tileMapList->FetchIsTileSolid(botMapNum, tileList, tileLeftX,  botTileY);
			}
		}
	}

	//when the previous code is completed successfully, the sprite can 
	//be moved to a new position on the screen 
	xPos = nextPos->X;
	yPos = nextPos->Y;

	//check if the ninja is standing on ground
	if(CheckGroundTile(tileMapList, tileList))
	{
			//tell the FSM that the sprite needs to enter its stand position 
			startStand = true;
	}
}//*************************************************************************************

//*******************************************************************************************
//CheckGroundTile is used to determine if the sprite is standing on a solid tile based on its
//current position(not its look ahead position).
//*******************************************************************************************
bool Ninja::CheckGroundTile(TileMapList^ tileMapList, TileList^ tileList)
{
	bool rValue = false;

	//get the map number of the tile map that stores the tiles the sprite is standing on
	int mapNum = ResolveMapNumber(yPos + hitBoxHeight);
	
	//get the bot y coordinate for tile reference
	int botTileY = ResolveTileYNumber(yPos + hitBoxHeight + 1);

	//get the  left and right x number for tile reference
	int tileLeftX = ResolveTileXNumber(xPos);
	int tileRightX = ResolveTileXNumber(xPos + hitBoxWidth);

	//check if the bot right tile is a solid object
	bool botRightSolid =  tileMapList->FetchIsTileSolid(mapNum, tileList, tileRightX, botTileY);

	//check if the bot left tile is a solid object
	bool botLeftSolid =  tileMapList->FetchIsTileSolid(mapNum, tileList, tileLeftX,  botTileY);

	//check if either the bottom right or bottom left tile that the sprite is standing on in solid
	if(botRightSolid || botLeftSolid)
	{
		//if yes, the sprite is standing on solid ground
		rValue = true;
	}
	return rValue;
}//*************************************************************************************

//********************************************************************************************
//AvoidCollisionDown is used to adjust the player sprites position when it lands from a jump
//to prevent it from standing within a solid tile.  It returns the number of pixels the sprite
//has to move up to stand on top of the tile.
//********************************************************************************************
int Ninja::AvoidCollisionDown(int yPos)
{
	int yMod = (yPos  % tileSize + tileSize) - LANDING_BUFFER;
			
	if(yMod == 0)
		yMod = tileSize;
	
	return yMod;
}//*************************************************************************************

//*****************************************************************************************
//UseJetPack checks if the player sprite has a jet pack powerup before letting it perform a
//jetpack jump.  When it does let the player perform a jetpack jump, it takes decrements the
//amount of jet pack charges the player has.
//******************************************************************************************
void Ninja::UseJetPack()
{
	if(numJet > 0)
	{
		startJetJump = true;
		numJet -= 1;
	}
}//*************************************************************************************

//****************************************************************************************************
//GenerateShuriken initializes and returns a shuriken when the player uses one.  The returned shuriken 
//is stored in the game managers shuriken list.
//****************************************************************************************************
Shuriken^ Ninja::GenerateShuriken()
{
	Shuriken^ shuriken;
	
	int shurVel;
	int shurXPos;
	int shurYPos = yPos + hitBoxHeight / 2;

	if(dirFacing == LEFT)
	{
		shurXPos = xPos - SHUR_SIZE;
		shurVel = SHUR_SPEED * -1;
	}
	else
	{
		shurXPos = xPos + hitBoxWidth;
		shurVel = SHUR_SPEED;
	}
	shuriken = gcnew Shuriken(canvas, shurXPos, shurYPos, shurVel);
	numShuriken -= 1;
	return shuriken;
}//*************************************************************************************

//****************************************************************************************
//PrepareWallJump starts the countdown timer associated with performing a wall jump.
//if the player sprite hits a wall before the timer runs out, it will perform a wall jump.
//****************************************************************************************
void Ninja::PrepareWallJump()
{
	if(!readyToWallJump)
	{
		readyToWallJump = true;
		wallJumpTimer = WALL_JUMP_TIMER;
	}
}//*************************************************************************************

//*******************************************************************************************
//CurrentHeight returns the player sprites current height.  It is used by the game manager
//to determine if the player has reached a new max height, which is the games scoring system.
//*******************************************************************************************
int Ninja::CurrentHeight()
{
	int height = (yPos * -1) - SCORE_Y_MODIFIER;
	return height;
}//*************************************************************************************