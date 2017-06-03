#pragma once
#include "Sprite.h"
ref class SpriteLinkedList
{
private:
	Sprite^ head;
	Sprite^ tail;
public:
	SpriteLinkedList();
	int CountSprites();
	void AddSprite(Sprite^ nSprite);
	void DeleteSprite(Sprite^ dSprite);
	bool CheckCollision(Sprite^ otherSprite);
	void MoveAll();
	void DrawAll();
	array<Sprite^>^ MakeArray();
};
