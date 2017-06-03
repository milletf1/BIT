#pragma once
#include "Explosion.h"
#include "Sprite.h"
#include "Bomb.h"

ref class ExplosionLinkedList
{
private:
	Explosion^ head;
	Explosion^ tail;
	
	
public:
	ExplosionLinkedList();

	int CountExplosion();
	void AddExplosion(Explosion^ nExplosion);
	void DeleteExplosion(Explosion^ dExplosion);
	void ExplosionCleanup();
	void DecayTimer();
	bool CheckSpriteCollision(Sprite^ sprite);
	bool CheckBombCollision(Bomb^ bomb);
	void DrawAll();
	array<Explosion^>^ MakeArray();
};

