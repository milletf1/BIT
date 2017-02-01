#pragma once
#include "Node.h"

#define CIRCLE_SIZE 40
#define TEXT_SIZE 12
#define TEXT_OFFSET_X 10
#define TEXT_OFFSET_Y 10

using namespace System;
using namespace System::Drawing;

ref class BinaryTree
{
private:

	int inspectionCount;

	void insertItem(Node^ %rootPtr, int insertValue);
	bool findItem(Node^ rootPtr, int targetValue);
public:	
	
	Node^ rootNode;

	BinaryTree();
	BinaryTree(int rootValue);
	BinaryTree(int rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree);

	Node^ getRootNode() { return rootNode; }

	void add(int n);
	bool find(int n);
	int findNodeCount(int n);

	void setLeftNode(Node^ newNode) { rootNode->setLeftNode(newNode); }
	void setRightNode(Node^ newNode) { rootNode->setRightNode(newNode); }	
	
	void preorderTraverse(Node^ %inputRoot, String^ &output);
	void inorderTraverse(Node^ %inputRoot, String^ &output);
	void postorderTraverse(Node^ %inputRoot, String^ &output);

	void drawTree(Node^ rootNode, int xPos, int yPos, int xOffset, Graphics^ canvas);

	void buildMasterTree();
	void buildRandomTree(Random^ r, String^ %output);
};
