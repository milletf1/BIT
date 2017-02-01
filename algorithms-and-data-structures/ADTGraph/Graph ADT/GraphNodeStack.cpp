#include "StdAfx.h"
#include "GraphNodeStack.h"

GraphNodeStack::GraphNodeStack(void)
{
	head = nullptr;
	tail = nullptr;
}

void GraphNodeStack::push(GraphNode^ v)
{
	//Check if there are any CharNodes in the linked list.
	if(head != nullptr)
	{
		//If there are, add the new CharNode to the end of the 
		//linked list.
		tail->Next = v;
		tail = v;
	}
	else
	{
		//If there aren't, set head and tail to the new CharNode.
		head = v;
		tail = v;
	}
}
GraphNode^ GraphNodeStack::pop()
{
	GraphNode^ cur = head;
	GraphNode^ returnNode = tail;

	if(head->Next == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{		
		while(cur->Next != returnNode)
		{
			cur = cur->Next;
		}
		cur->Next = nullptr;
		tail = cur;
	}
	return returnNode;
}

GraphNode^ GraphNodeStack::peek()
{
	return tail;
}

bool GraphNodeStack::isEmpty()
{
	return tail == nullptr;
}