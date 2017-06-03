#include "StdAfx.h"
#include "ExplosionLinkedList.h"

/// <summary>
/// Constructor
/// </summary>
ExplosionLinkedList::ExplosionLinkedList(void)
{
	head = nullptr;
	tail = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decrements the timers of the explosions in the linked list
/// </summary>
void ExplosionLinkedList::DecayTimer()
{
	Explosion^ curExplosion = head;
	while(curExplosion != nullptr)
	{
		curExplosion->DecayLifeTimer();
		curExplosion = curExplosion->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
///	Returns a count of the explosions in the linked list
/// </summary>
int ExplosionLinkedList::CountExplosion()
{
	int count = 0;
	Explosion^ curExplosion = head;

	while(curExplosion != nullptr)
	{
		count += 1;
		curExplosion = curExplosion->Next;	
	}
	return count;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Adds an explosion to the linked list
/// </summary>
void ExplosionLinkedList::AddExplosion(Explosion^ nExplosion)
{
	//check that the list is not empty
	if(head != nullptr)
	{
		//make the bomb that tail is pointing to point
		//to the new bomb
		tail->Next = nExplosion;
		//add the new bomb to the end of the list
		tail = nExplosion;
	}
	//if the list is empty
	else
	{
		//set head and tails next to new bomb
		head = nExplosion;
		tail = nExplosion;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Removes an explosion from the linked list
/// </summary>
void ExplosionLinkedList::DeleteExplosion(Explosion^ dExplosion)
{
	Explosion^ curExplosion = head;
	
	//check if the head bomb needs to be deleted
	if(head == dExplosion)
	{
		//check if the head and tail bomb are the same
		if(tail == dExplosion)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = dExplosion->Next;
	}
	else 
	{
		//run this while loop until curSprite points to 
		//the sprite that needs deleting
		while(curExplosion->Next != dExplosion)
			curExplosion = curExplosion->Next;

		//set curSprites next to dSprites next
		curExplosion->Next = dExplosion->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if a sprite has collided wih an explosion
/// </summary>
bool ExplosionLinkedList::CheckSpriteCollision(Sprite^ sprite)
{
	bool didHit = false;
	Explosion^ curExplosion = head;
	while(curExplosion != nullptr)
	{
		if(curExplosion->HitSprite(sprite))
			didHit = true;
		curExplosion = curExplosion->Next;
	}
	return didHit;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// 
/// </summary>
bool ExplosionLinkedList::CheckBombCollision(Bomb^ bomb)
{
	bool didHit = false;
	Explosion^ curExplosion = head;
	while(curExplosion != nullptr)
	{
		if(curExplosion->HitBomb(bomb))
			didHit = true;
		curExplosion = curExplosion->Next;
	}
	return didHit;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws all the explosions in the linked list
/// </summary>
void ExplosionLinkedList::DrawAll()
{
	Explosion^ curExplosion = head;
	while(curExplosion != nullptr)
	{
		curExplosion->Draw();
		curExplosion = curExplosion->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Removes all explosions in the linked list when the player changes levels
/// </summary>
void ExplosionLinkedList::ExplosionCleanup()
{
	//build array of explosions
	array<Explosion^>^ explosionArray = gcnew array<Explosion^>(CountExplosion());
	int count = 0;
	Explosion^ curExplosion = head;
	//cycle through the linked list, adding the entries into the array
	while(curExplosion != nullptr)
	{
		explosionArray[count] = curExplosion;
		curExplosion = curExplosion->Next;
		count += 1;
	}
	//cycle through the array, looking for explosions to remove from the linked list
	for(int i = 0; i < explosionArray->Length; i++)
	{
		//check if the explosion has stopped living (the timer has run out)
		if(!explosionArray[i]->getIsLive())
			//if it has, delete it from the linked list
			DeleteExplosion(explosionArray[i]);
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns an array of the explosions in the linked list
/// </summary>
array<Explosion^>^ ExplosionLinkedList::MakeArray()
{
	int total = CountExplosion();
	array<Explosion^>^ explosionArray = gcnew array<Explosion^>(CountExplosion());
	int count = 0;
	Explosion^ curExp = head;

	while(curExp != nullptr)
	{
		explosionArray[count] = curExp;
		curExp = curExp->Next;
		count += 1;
	}
	return explosionArray;
}//End//////////////////////////////////////////////////////////////////////////////