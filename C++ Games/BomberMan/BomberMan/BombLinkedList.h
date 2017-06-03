#pragma once
#include "Bomb.h"
#include "Sprite.h"

ref class BombLinkedList
{
	Bomb^ head;
	Bomb^ tail;
public:
	BombLinkedList();
	int CountBombs();
	void AddBomb(Bomb^ nBomb);
	void DeleteBomb(Bomb^ dBomb);
	void BurnFuse();
	void ExplodeBomb(Bomb^ targetBomb);
	//a bomb array is needed when a bomb has exploded to see if 
	//the explosion detonates any other bombs
	array<Bomb^>^ MakeArray();
	Bomb^ CheckExplosion();
	Bomb^ CheckExplosion(Bomb^ sBomb);
	bool CheckOnBomb(Sprite^ sprite);
	bool CheckSpriteCollision(Sprite^ sprite);
	void DrawAll();
};
