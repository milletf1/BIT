#include "StdAfx.h"
#include "BuffLinkedList.h"

/// <summary>
/// Constructor
/// </summary>
BuffLinkedList::BuffLinkedList()
{
	head = nullptr;
	tail = nullptr;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns a count of the explosions in the linked list
/// </summary>
int BuffLinkedList::CountBuffs()
{
	Buff^ curBuff = head;
	int count = 0;

	while(curBuff != nullptr)
	{
		curBuff = curBuff->Next;
		count += 1;
	}
	
	return count;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Adds a buff to the linked list
/// </summary>
void BuffLinkedList::AddBuff(Buff^ buff)
{
	//check that the list is not empty
	if(head != nullptr)
	{
		//make the buff that tail is pointing to point
		//to the new buff
		tail->Next = buff;
		//add the new buff to the end of the list
		tail = buff;
	}
	//if the list is empty
	else
	{
		//set head and tails next to new buff
		head = buff;
		tail = buff;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Deletes a buff from the linked list
/// </summary>
void BuffLinkedList::DeleteBuff(Buff^ buff)
{
	Buff^ curBuff = head;
	
	//check if the head buff needs to be deleted
	if(head == buff)
	{
		//check if the head and tail buff are the same
		if(tail == buff)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
			head = buff->Next;
	}
	else 
	{
		//run this while loop until curBuff points to 
		//the sprite that needs deleting
		while(curBuff->Next != buff)/* && curBuff->Next != nullptr*/
			curBuff = curBuff->Next;

		//set curBuffs Next to buffs next
		curBuff->Next = buff->Next;
	}	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Removes all buffs from the linked list when the player changes levels
/// </summary>
void BuffLinkedList::BuffCleanup()
{
	//count the number of buffs in the list
	int buffCount = CountBuffs();
	//create a counter that dictates which array slot to store the buff in
	int count = 0;
	//create an array to be filled with buffs
	array<Buff^>^ buffArray = gcnew array<Buff^>(buffCount);
	//create a node walker to walk through the linked list
	Buff^ curBuff = head;
	
	//cycle through the list
	while(curBuff != nullptr)
	{
		buffArray[count] = curBuff;
		curBuff = curBuff->Next;
		count += 1;
	}
	//cycle through the array, looking for buffs to remove from the linked list
	for(int i = 0; i < buffArray->Length; i++)
	{
		//check if the buff is no longer active (the timer has run out)
		if(!buffArray[i]->getIsActive())
			//if it has, delete it from the linked list
			DeleteBuff(buffArray[i]);
	}	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Draws all buffs to the form
/// </summary>
void BuffLinkedList::Draw()
{
	Buff^ curBuff = head;
	while(curBuff != nullptr)
	{
		curBuff->Draw();
		curBuff = curBuff->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Decrements the timers of every buff in the linked list
/// </summary>
void BuffLinkedList::DecayTimer()
{
	Buff^ curBuff = head;
	while(curBuff != nullptr)
	{
		curBuff->DecayTimer();
		curBuff = curBuff->Next;
	}
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Returns an array of buffs. Needed to check if the player has picked any up (the player can pick up more than one at a time)
/// </summary>
array<Buff^>^ BuffLinkedList::MakeArray()
{
	//count the number of buffs in the list
	int buffCount = CountBuffs();
	//create a counter that dictates which array slot to store the buff in
	int count = 0;
	//create an array to be filled with buffs
	array<Buff^>^ buffArray = gcnew array<Buff^>(buffCount);
	//create a node walker to walk through the linked list
	Buff^ curBuff = head;
	
	//cycle through the list
	while(curBuff != nullptr)
	{
		//add buff to the array
		buffArray[count] = curBuff;
		count += 1;
		curBuff = curBuff->Next;
	}
	return buffArray;
}//End//////////////////////////////////////////////////////////////////////////////
