#pragma once
#include "Node.h"

using namespace System::Text::RegularExpressions;

ref class BinaryTree
{
private:
	static String^ OPERATOR_REGEX = "[\/\+\*\-]{1}";

	Node^ rootNode;
	
public:
	BinaryTree();
	BinaryTree(String^ rootValue);
	BinaryTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree);

	Node^ getRootNode() { return rootNode; }

	void setLeftNode(Node^ newNode) { rootNode->setLeftNode(newNode); }
	void setRightNode(Node^ newNode) { rootNode->setRightNode(newNode); }	
	
	int parseExpressionTree(Node^ inputRoot);
	void postorderTraverse(Node^ inputRoot, String^ &output);
	void buildTree1();		//Builds an expression tree for 26*3+
	void buildTree2();		//Builds an expression tree for 263+*
};
