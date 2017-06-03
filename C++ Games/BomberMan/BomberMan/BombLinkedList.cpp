#include "StdAfx.h"
#include "BombLinkedList.h"

/// <summary>
/// Constructor
/// </summary>
BombLinkedList::BombLinkedList()
{
	head = nullptr;
	tail = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns a count of all the bombs in the linked list
/// </summary>
int BombLinkedList::CountBombs()
{
	int bombCount = 0;
	Bomb^ curBomb = head;

	while(curBomb != nullptr)
	{
		bombCount += 1;
		curBomb = curBomb->Next;	
	}

	return bombCount;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Adds a bomb to the linked list
/// </summary>
void BombLinkedList::AddBomb(Bomb^ nBomb)
{
	//check that the list is not empty
	if(head != nullptr)
	{
		//make the bomb that tail is pointing to point
		//to the new bomb
		tail->Next = nBomb;
		//add the new bomb to the end of the list
		tail = nBomb;
	}
	//if the list is empty
	else
	{
		//set head and tails next to new bomb
		head = nBomb;
		tail = nBomb;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Deletes a bomb from the linked list
/// </summary>
void BombLinkedList::DeleteBomb(Bomb^ dBomb)
{
	Bomb^ curBomb = head;
	
	//check if the head bomb needs to be deleted
	if(head == dBomb)
	{
		//check if the head and tail bomb are the same
		if(tail == dBomb)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = dBomb->Next;
	}
	else 
	{
		//run this while loop until curSprite points to 
		//the sprite that needs deleting
		while(curBomb->Next != dBomb)
			curBomb = curBomb->Next;

		//set curSprites next to dSprites next
		curBomb->Next = dBomb->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decrements the timer of all the bombs in the linked list
/// </summary>
void BombLinkedList::BurnFuse()
{
	Bomb^ curBomb = head;

	while(curBomb != nullptr)
	{
		//burn the bombs fuse
		curBomb->BurnFuse();	
		curBomb = curBomb->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if a bomb in the linked list has exploded
/// </summary>
Bomb^ BombLinkedList::CheckExplosion()
{
	Bomb^ curBomb = head;
	//rBomb is the value that gets returned. 
	Bomb^ rBomb = nullptr;
	//detonation is used to jump out of the while loop if an instance of detonation is found
	bool detonation = false;

	while(curBomb != nullptr &&
		detonation == false)
	{
		//check if the bomb has detonated
		if(curBomb->getHasDetonated())
		{
			detonation = true;
			rBomb = curBomb;
		}
		else
			curBomb = curBomb->Next;
	}
	return rBomb;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// This function is used to check the rest of the bomb linked list Once the first bomb has exploded
/// </summary>
Bomb^ BombLinkedList::CheckExplosion(Bomb^ sBomb)
{
	Bomb^ curBomb = head;
	//rBomb is the value that gets returned. 
	Bomb^ rBomb = nullptr;
	//detonation is used to jump out of the while loop if an instance of detonation is found
	bool detonation = false;

	while(curBomb != nullptr &&
		detonation == false)
	{
		//check if the bomb has detonated
		if(curBomb->getHasDetonated())
		{
			detonation = true;
			rBomb = curBomb;
		}
		else
			curBomb = curBomb->Next;
	}
	return rBomb;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws all the bombs in the linked list
/// </summary>
void BombLinkedList::DrawAll()
{
	Bomb^ curBomb = head;
	while(curBomb != nullptr)
	{
		curBomb->Draw();
		curBomb = curBomb->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Detonates a bomb in the linked list
/// </summary>
void BombLinkedList::ExplodeBomb(Bomb^ targetBomb)
{
	bool bombFound = false;
	Bomb^ curBomb = head;
	while(curBomb != nullptr &&
		bombFound == false)
	{
		if(curBomb == targetBomb)
			curBomb->DetonateBomb();
		else
			curBomb = curBomb->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns the bombs in the linked list as an array
/// </summary>
array<Bomb^>^ BombLinkedList::MakeArray()
{
	array<Bomb^>^ bombArray = gcnew array<Bomb^>(CountBombs());
	int count = 0;
	Bomb^ curBomb = head;
	while(curBomb != nullptr)
	{
		bombArray[count] = curBomb;
		curBomb = curBomb->Next;
		count += 1;
	}
	return bombArray;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if the given sprite is standing on a bomb
/// </summary>
bool BombLinkedList::CheckOnBomb(Sprite^ sprite)
{
	bool onBomb = false;

	Bomb^ curBomb = head;
	while(curBomb != nullptr)
	{
		if(curBomb->CheckOnBomb(sprite))
		{
			onBomb = true;
		}
		curBomb = curBomb->Next;
	}
	
	return onBomb;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
///	Checks if a given sprite is going to collide with a bomb.
/// </summary>
bool BombLinkedList::CheckSpriteCollision(Sprite^ sprite)
{
	bool didCollide = false;

	Bomb^ curBomb = head;
	while(curBomb != nullptr)
	{
		if(curBomb->CheckCollsion(sprite))
		{
			didCollide = true;
		}
		curBomb = curBomb->Next;
	}	
	return didCollide;
}//End//////////////////////////////////////////////////////////////////////////////