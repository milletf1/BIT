#include "StdAfx.h"
#include "SpriteLinkedList.h"

/// <summary>
/// Constructor
/// </summary>
SpriteLinkedList::SpriteLinkedList()
{
	head = nullptr;
	tail = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns a count of all sprites stored in the linked list
/// </summary>
int SpriteLinkedList::CountSprites()
{
	int spriteCount = 0;
	Sprite^ curSprite = head;
	
	//cycles through each object in the list, incrementing spriteCount by one
	while( curSprite != nullptr)
	{
		spriteCount +=1;
		curSprite = curSprite->Next;
	}
	return spriteCount;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Adds a sprite to the end of the linked list
/// </summary>
void SpriteLinkedList::AddSprite(Sprite^ nSprite)
{
	//check that the list is not empty
	if(head != nullptr)
	{
		//make the sprite that tail is pointing to point
		//to the new sprite.
		tail->Next = nSprite;
		//add the new sprite to the end of the list
		tail = nSprite;
	}
	//if the list is empty
	else
	{
		//set head and tails next to nSprite
		head = nSprite;
		tail = nSprite;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Deletes a given sprite from the linked list
/// </summary>
void SpriteLinkedList::DeleteSprite(Sprite^ dSprite)
{
	Sprite^ curSprite = head;
	
	//check if the head sprite needs to be deleted
	if(head == dSprite)
	{
		//check if the head and tail sprite are the same
		if(tail == dSprite)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = dSprite->Next;
	}
	//check that the tail spprite is not the one being
	//deleted
	else 
	{
		//run this while loop until curSprite points to 
		//the sprite that needs deleting
		while(curSprite->Next != dSprite)
			curSprite = curSprite->Next;

		//set curSprites next to dSprites next
		curSprite->Next = dSprite->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////


/// <summary>
/// Moves all the sprites stored in the linked list
/// </summary>
void SpriteLinkedList::MoveAll()
{
	Sprite^ curSprite = head;

	while(curSprite != nullptr)
	{
		curSprite->Move();
		curSprite = curSprite->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws all the sprites in the linked list
/// </summary>
void SpriteLinkedList::DrawAll()
{
	Sprite^ curSprite = head;	

	while(curSprite != nullptr)
	{
		curSprite->Draw();
		curSprite = curSprite->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Checks if the sprite given as a parameter has collided with any of the sprites in the list
/// </summary>
bool SpriteLinkedList::CheckCollision(Sprite^ otherSprite)
{
	bool didCollide = false;
	Sprite^ curSprite = head;

	while (curSprite != nullptr 
		&& didCollide == false)
	{
		if (curSprite->CheckCollision(otherSprite))
			didCollide = true;
		
		curSprite = curSprite->Next;
	}
	return didCollide;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns an array containing all the sprites in the list
/// </summary>
array<Sprite^>^ SpriteLinkedList::MakeArray()
{
	array<Sprite^>^ spriteArray = gcnew array<Sprite^>(CountSprites());
	int count = 0;
	Sprite^ curSprite = head;
	while(curSprite != nullptr)
	{
		spriteArray[count] = curSprite;
		curSprite = curSprite->Next;
		count += 1;
	}
	return spriteArray;
}//End//////////////////////////////////////////////////////////////////////////////