#pragma once

ref class Node
{
private:	
	int value;

public:
	Node^ leftNode;
	Node^ rightNode;

	Node();

	Node^ getLeftNode() { return leftNode; }
	Node^ getRightNode() { return rightNode; }

	void setLeftNode(Node^ newNode) { leftNode = newNode; }
	void setRightNode(Node^ newNode) { rightNode = newNode; }

	int getNodeValue() { return value; }

	void setNodeValue(int newValue) { value = newValue; }
};
