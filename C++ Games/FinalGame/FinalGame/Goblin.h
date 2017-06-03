#pragma once
#include "sprite.h"
#include "Ninja.h"
#include "Shuriken.h"

#define CHARGE_SPEED 12
#define GOBLIN_FRAMES 3
//*************************************************************************************************
//Goblin is a descendant of the Sprite class and makes up the enemy in the game world.
//The goblins walk back and forth along platforms in the game.  Upon sighting the player, they will
//charge at him in an attempt to knock him off the platform and to his death.
//*************************************************************************************************
ref class Goblin :
public Sprite
{
private:
	bool startWalk;
	bool startCharge;
	array<Bitmap^>^ chargeBitmap;

public:
	Goblin^ Next;
	//constructor
	Goblin(Graphics^ sCanvas, int sDrawWidth, int sDrawHeight, int sHitBoxWidth, int sHitBoxHeight, 
		int sXPos, int sYPos, int sDrawOffsetX, int sDrawOffsetY, int sSpriteState, int sDirFacing,
		int sXSpeed, int sScreenSize, int sTileSize);

	//functions 
	virtual void InitializeSprites() override;
	virtual void Draw(int mapYLat) override;
	
	virtual void UpdateState() override;
	virtual void SpriteWalkUpdate() override;
	void SpriteChargeUpdate();

	virtual void PerformAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite) override;
	virtual void MoveAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite) override;
	void ChargeAction(TileMapList^ tileMapList, TileList^ tileList, Sprite^ otherSprite);
	bool CheckOverEdge(TileMapList^ tileMapList, TileList^ tileList, Point^ nextPos);

	void ChangeDirection();
};
