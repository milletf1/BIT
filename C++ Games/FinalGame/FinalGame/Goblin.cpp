#include "StdAfx.h"
#include "Goblin.h"

//***********
//Constructor
//***********
Goblin::Goblin(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize)
: Sprite (sCanvas, sDrawWidth, sDrawHeight, sHitBoxWidth, sHitBoxHeight, 
		sXPos, sYPos, sDrawOffsetX, sDrawOffsetY, sSpriteState, sDirFacing, sXSpeed, sScreenSize, sTileSize)
{
	Next = nullptr;
	curWalkFrame = 0;
	totWalkFrame = GOBLIN_FRAMES;
	
	//set goblins movement
	ChangeDirection();
	
	//initialze the goblin sprites
	InitializeSprites();
}//**************************************************************************************

//********************************
//Initializes the sprites bitmaps.
//********************************
void Goblin::InitializeSprites()
{
	String^ filePath = "Sprites\\";
	//construct the sprite arrays that hold the goblin bitmap
	spriteWalkAnimation = gcnew array<Bitmap^>(2);
	chargeBitmap = gcnew array<Bitmap^>(2);

	//************************************
	//initialize the goblin walk animation
	//************************************

	//initialize the bitmaps
	Bitmap^ walkLeft = gcnew Bitmap(filePath + "monsterWalkLeft.bmp");
	walkLeft->MakeTransparent(walkLeft->GetPixel(0, 0));

	Bitmap^ walkRight = gcnew Bitmap(filePath + "monsterWalkRight.bmp");
	walkRight->MakeTransparent(walkRight->GetPixel(0, 0));

	//add to the spriteWalkAnimation array
	spriteWalkAnimation[LEFT] = walkLeft;
	spriteWalkAnimation[RIGHT] = walkRight;
	
	//**************************************
	//initialize the goblin charge animation
	//**************************************

	//initialize the bitmaps
	Bitmap^ chargeLeft = gcnew Bitmap(filePath + "monsterChargeLeft.bmp");
	chargeLeft->MakeTransparent(chargeLeft->GetPixel(0, 0));

	Bitmap^ chargeRight = gcnew Bitmap(filePath + "monsterChargeRight.bmp");
	chargeRight->MakeTransparent(chargeRight->GetPixel(0, 0));

	//add to the spriteWalkAnimation array
	chargeBitmap[LEFT] = chargeLeft;
	chargeBitmap[RIGHT] = chargeRight;
}//**************************************************************************************

//******************************
//Changes the sprites direction.
//******************************
void Goblin::ChangeDirection()
{
	int speed;
	
	//Set the goblins move speed based on its current state.
	if(spriteState == WALKING)
		speed = xSpeed;
	else
		speed = CHARGE_SPEED;
	
	//set goblins movement direction
	if(dirFacing == RIGHT)
	{
		dirFacing = LEFT;
		xVel = speed * -1;
	}
	else
	{
		dirFacing = RIGHT;
		xVel = speed;
	}
}//**************************************************************************************

//****************************************
//Draws the goblin to the graphics buffer.
//****************************************
void Goblin::Draw(int mapYLat)
{
	//set the coordinates for the goblins on screen position
	int screenYPos = (mapYLat + (yPos * -1)) * - 1;
	int screenXPos = xPos - drawOffsetX;
	Point^ drawPos = gcnew Point(screenXPos, screenYPos);

	//draw the goblins sprite based on its current state
	switch(spriteState)
	{
	case WALKING:
		canvas->DrawImage(spriteWalkAnimation[dirFacing],drawPos->X, drawPos->Y, 
			Rectangle(curWalkFrame * drawWidth, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		IncrementFrame();
		break;
	case CHARGE:
		canvas->DrawImage(chargeBitmap[dirFacing],drawPos->X, drawPos->Y, 
			Rectangle(curWalkFrame * drawWidth, 0, drawWidth, drawHeight), GraphicsUnit::Pixel);
		IncrementFrame();
		break;
	default: 
		break;
	}
}//**************************************************************************************
	
//**********************************************************************************************
//UpdateState chooses a function for the goblin to use to check if it needs to update its state.
//**********************************************************************************************
void Goblin::UpdateState()
{
	switch(spriteState)
	{
	case WALKING:
		
		SpriteWalkUpdate();
		break;

	case CHARGE:

		SpriteChargeUpdate();
		break;

	default:
		break;
	}
}//**************************************************************************************

//**********************************************************************************
//Performs the checks needed to see if the goblin needs to change its state when its
//in the walk state.
//**********************************************************************************
void Goblin::SpriteWalkUpdate()
{
	if(startCharge)
	{
		//change the goblins state
		spriteState = CHARGE;
		startCharge = false;

		//set xVel to charge speed
		if(dirFacing == RIGHT)
			xVel = CHARGE_SPEED;
		else
			xVel = CHARGE_SPEED * -1;
	}
}//**************************************************************************************

//**********************************************************************************
//Performs the checks needed to see if the goblin needs to change its state when its
//in the charge state.
//**********************************************************************************
void Goblin::SpriteChargeUpdate()
{
	if(startWalk)
	{
		//change the goblins state
		spriteState = WALKING;
		startWalk = false;
		
		//set xVel to the default walk speed
		if(dirFacing == RIGHT)
			xVel = xSpeed;
		else
			xVel = xSpeed * -1;		
	}
}//**************************************************************************************

//******************************************************************************
//PerformAction chooses a function for the goblin to perform its current action.
//******************************************************************************
void Goblin::PerformAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite)
{
	if(spriteState == WALKING)
		MoveAction(tileMapList, tileList, otherSprite);
	else
		ChargeAction(tileMapList, tileList, otherSprite);
}//**************************************************************************************

//*********************************
//Performs the goblins move action.
//*********************************
void Goblin::MoveAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite)
{
	//set nextPos
	Point^ nextPos = NextPosition();
	
	//get this goblin and the players floor tile (this will be used to determine the interaction 
	//between the player and goblin later in the function)
	int playerFloorY = otherSprite->getYPos() + otherSprite->getHitBoxHeight();
	int floorY = nextPos->Y + hitBoxHeight;

	//get the map number that the goblin occupies
	int mapNum = ResolveMapNumber(nextPos->Y);

	//get the bot y number for tile reference 
	int botTileY = ResolveTileYNumber(nextPos->Y + hitBoxHeight);

	//get the  left and right x number for tile reference
	int tileLeftX = ResolveTileXNumber(nextPos->X);
	int tileRightX = ResolveTileXNumber(nextPos->X + hitBoxWidth);
	

	//if it isn't check if it can see the player
	if(playerFloorY == floorY)
	{
		if(dirFacing == LEFT && xPos > otherSprite->getXPos())  			
		{
			startCharge = true;
		}
		else if(dirFacing == RIGHT && xPos < otherSprite->getXPos()) 
		{
			startCharge = true;
		}
	}

	//check if the next move will make the goblin move over the edge of the platform
	if(CheckOverEdge(tileMapList, tileList, nextPos))
	{
		//if yes change direction and reset nextPos
		ChangeDirection();
		nextPos = NextPosition();		
	}
	//when the previous code is completed successfully, the sprite can 
	//be moved to a new position on the screen 
	xPos = nextPos->X;
	yPos = nextPos->Y;	
}//**************************************************************************************

//***********************************
//Performs the goblins charge action.
//***********************************
void Goblin::ChargeAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite)
{
	//set nextPos
	Point^ nextPos = NextPosition();
	
	//get this goblin and the players floor tile (this will be used to determine the interaction 
	//between the player and goblin later in the function)
	int playerFloorY = otherSprite->getYPos() + otherSprite->getHitBoxHeight();
	int floorY = nextPos->Y + hitBoxHeight;

	//get the map number that the goblin occupies
	int mapNum = ResolveMapNumber(nextPos->Y);

	//get the bot y number for tile reference 
	int botTileY = ResolveTileYNumber(nextPos->Y + hitBoxHeight);

	//get the  left and right x number for tile reference
	int tileLeftX = ResolveTileXNumber(nextPos->X);
	int tileRightX = ResolveTileXNumber(nextPos->X + hitBoxWidth);

	//set the ninjas new y position variable
	int newX;
	int newY  = floorY - otherSprite->getHitBoxHeight();

	//***********************************************
	//check if the player has been hit by the monster
	//***********************************************
	if(playerFloorY == floorY && otherSprite->getIsHit())
	{
		otherSprite->setYPos(newY);

		//set the players x position variable based on the direction the goblin is facing
		if(dirFacing == LEFT)
		{
			newX = nextPos->X - otherSprite->getHitBoxWidth() - 1;						
		}
		else
		{
			newX = nextPos->X + hitBoxWidth + 1;
		}		
		otherSprite->setXPos(newX);	
		otherSprite->setYPos(newY);
	}
	//*********************************
	//if it hasn't, check for collision
	//*********************************
	else if(CheckCollision(otherSprite))
	{
		otherSprite->setIsHit(true);
	}
	//*******************************************
	//check if the goblin has moved over the edge
	//*******************************************
	if(CheckOverEdge(tileMapList, tileList, nextPos))
	{
		//check if the player need to stop being hit
		if(playerFloorY == floorY && otherSprite->getIsHit())
		{
			//if yes, set the players isHit to false
			otherSprite->setIsHit(false);
			
			//move the player further over the edge
			if(dirFacing ==LEFT)
				newX -= hitBoxWidth / 2;
			else
				newX += hitBoxWidth / 2;

			otherSprite->setXPos(newX);	
			otherSprite->setYPos(newY + hitBoxHeight);	
		}
		//change direction and reset nextPos
		ChangeDirection();
		nextPos = NextPosition();
		
		//set its update to start walking
		startWalk = true;							
	}
	//when the previous code is completed successfully, the sprite can 
	//be moved to a new position on the screen 
	xPos = nextPos->X;
	yPos = nextPos->Y;	
}//**************************************************************************************

//**************************************************************
//checks if the goblin has walked over the edge of its platform.
//**************************************************************
bool Goblin::CheckOverEdge(TileMapList^ tileMapList, TileList^ tileList, Point^ nextPos)
{
	bool rValue = false;

	//get the map number that the goblin occupies
	int mapNum = ResolveMapNumber(nextPos->Y);

	//get the bot y coordinate for tile reference
	int botTileY = ResolveTileYNumber(nextPos->Y + hitBoxHeight + 1);

	//get the  left and right x number for tile reference
	int tileLeftX = ResolveTileXNumber(nextPos->X);
	int tileRightX = ResolveTileXNumber(nextPos->X + hitBoxWidth);

	//check if the bot right tile is a solid object
	bool botRightSolid =  tileMapList->FetchIsTileSolid(mapNum, tileList, tileRightX, botTileY);

	//check if the bot left tile is a solid object
	bool botLeftSolid =  tileMapList->FetchIsTileSolid(mapNum, tileList, tileLeftX,  botTileY);
	
	//check if  the goblin has walked over the edge
	if(!botRightSolid || !botLeftSolid)
		rValue = true;
	
	return rValue;
}//**************************************************************************************


