#pragma once
#include "Buff.h"
#include "Sprite.h"

ref class BuffLinkedList
{
private:
	Buff^ head;
	Buff^ tail;
public:
	BuffLinkedList();
	int CountBuffs();
	void AddBuff(Buff^ buff);
	void DeleteBuff(Buff^ buff);
	void BuffCleanup();
	void Draw();
	void DecayTimer();
	//an array of buffs is needed to check if the player has picked 
	//picked any up (the player can pick up more than one at a time)
	array<Buff^>^ MakeArray();
};
