#include "StdAfx.h"
#include "HuffmanNode.h"

HuffmanNode::HuffmanNode()
{
	LeftNode = nullptr;
	RightNode = nullptr;
}


int HuffmanNode::CompareTo (Object^ o)
{
	HuffmanNode^ other = static_cast<HuffmanNode^>(o);
	return (other->frequency > frequency)? 1 : 0;
}