#include "StdAfx.h"
#include "StringNode.h"

StringNode::StringNode()
{
	Next = nullptr;
}

StringNode::StringNode(String^ nodeValue)
{
	Next = nullptr;
	value = nodeValue;
}