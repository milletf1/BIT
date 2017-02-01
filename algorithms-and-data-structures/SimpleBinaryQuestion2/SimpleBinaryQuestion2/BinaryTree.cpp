#include "StdAfx.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	rootNode = gcnew Node();
}

BinaryTree::BinaryTree(String^ rootValue)
{ 
	rootNode = gcnew Node();
	rootNode->setNodeValue(rootValue);
}


BinaryTree::BinaryTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree)
{ 
	rootNode = gcnew Node();
	rootNode->setNodeValue(rootValue);

	setLeftNode(leftSubTree->getRootNode());
	setRightNode(rightSubTree->getRootNode());
}

/************************************************************************
 * Precondition:  The tree must have been built.  The node values must be
 *                either an arithmetic value, or an integer value.
 *
 * Postcondition: Solves the postfix expression value determined by the 
 *                values in the tree.
 ************************************************************************/
int BinaryTree::parseExpressionTree(Node^ inputRoot)
{
	int result = 0;
	String^ s = inputRoot->getNodeValue();
	Char c = s->ToCharArray()[0];

	Regex^ operatorRegex = gcnew Regex(OPERATOR_REGEX);
	Match^ operatorResult = operatorRegex->Match(s); 

	// Check if the node value is an arithmetic expression.
	if(operatorResult->Success)
	{
		// If the node value is an arithmetic expression, determine 
		// and perform the calculation on the node's descendants.
		switch(c)
		{
		case '+':
			result = parseExpressionTree(inputRoot->getLeftNode()) + 
				parseExpressionTree(inputRoot->getRightNode());
			break;

		case '-':
			result = parseExpressionTree(inputRoot->getLeftNode()) - 
				parseExpressionTree(inputRoot->getRightNode());
			break;

		case '*':
			result = parseExpressionTree(inputRoot->getLeftNode()) * 
				parseExpressionTree(inputRoot->getRightNode());
			break;

		case '/':
			result = parseExpressionTree(inputRoot->getLeftNode()) /
				parseExpressionTree(inputRoot->getRightNode());
			break;
		}
	}
	else
	{
		// If the node value is not an arithmetic expression, return
		// it as an integer value.
		try
		{			
			result = Convert::ToInt16(inputRoot->getNodeValue());
		}
		catch(FormatException^ e){}
	}	
	return result;
}

/***********************************************************************
 * Precondition:  The string parameter must have been initialized.  The 
 *				  tree must have been built.
 *
 * Postcondition: Performs a postorder traversal of this tree and writes
 *				  the node values to the referenced string. 
 ***********************************************************************/
void BinaryTree::postorderTraverse(Node^ inputRoot, String^ &output)
{
	if(inputRoot != nullptr)
	{
		// Traverse left node.
		Node^ leftNode = inputRoot->getLeftNode();
		postorderTraverse(leftNode, output);

		// Traverse right node.
		Node^ rightNode = inputRoot->getRightNode();
		postorderTraverse(rightNode, output);

		// Add the node value to the output string.
		output += inputRoot->getNodeValue();
	}
}

/*****************************************************
 * Precondition:
 *
 * Postcondition: Builds an expression tree for 26*3+.
 *****************************************************/
void BinaryTree::buildTree1()
{
	// Addition node.
	rootNode->setNodeValue("+");
	
	// Multiplication node.
	BinaryTree^ multiplication = gcnew BinaryTree("*");
	
	// Two node.
	BinaryTree^ two = gcnew BinaryTree("2");
	
	// Six node.
	BinaryTree^ six = gcnew BinaryTree("6");
	
	// Three node.
	BinaryTree^ three = gcnew BinaryTree("3");

	// Build this tree.
	setLeftNode(multiplication->getRootNode());
	setRightNode(three->getRootNode());
	
	// Build the multiplication tree.
	multiplication->getRootNode()->setLeftNode(two->getRootNode());
	multiplication->getRootNode()->setRightNode(six->getRootNode());
}
/*****************************************************
 * Precondition:
 *
 * Postcondition: Builds an expression tree for 263+*.
 *****************************************************/
void BinaryTree::buildTree2()
{
	// Multiplication node.
	rootNode->setNodeValue("*");
	
	// Addition node.
	BinaryTree^ addition = gcnew BinaryTree("+");
	
	// Two node.
	BinaryTree^ two = gcnew BinaryTree("2");
	
	// Six node.
	BinaryTree^ six = gcnew BinaryTree("6");
	
	// Three node.
	BinaryTree^ three = gcnew BinaryTree("3");

	// Build this tree.
	setLeftNode(two->getRootNode());
	setRightNode(addition->getRootNode());

	// Build the addition tree.
	addition->setLeftNode(six->getRootNode());
	addition->setRightNode(three->getRootNode());
}