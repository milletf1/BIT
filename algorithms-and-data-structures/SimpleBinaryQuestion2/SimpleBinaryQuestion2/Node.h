#pragma once

using namespace System;

ref class Node
{
private:
	Node^ leftNode;
	Node^ rightNode;
	String^ value;
public:
	Node();

	Node^ getLeftNode() { return leftNode; }	
	void setLeftNode(Node^ newNode) { leftNode = newNode; }

	Node^ getRightNode() { return rightNode; }
	void setRightNode(Node^ newNode) { rightNode = newNode; }

	String^ getNodeValue() { return value; }
	void setNodeValue(String^ newValue) { value = newValue; }
};
