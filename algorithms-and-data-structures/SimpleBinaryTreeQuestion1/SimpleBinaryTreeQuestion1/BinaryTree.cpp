#include "StdAfx.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	rootNode = nullptr;
}

BinaryTree::BinaryTree(int rootValue)
{ 
	rootNode = gcnew Node();
	rootNode->setNodeValue(rootValue);
}


BinaryTree::BinaryTree(int rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree)
{ 
	rootNode = gcnew Node();
	rootNode->setNodeValue(rootValue);

	setLeftNode(leftSubTree->getRootNode());
	setRightNode(rightSubTree->getRootNode());
}

/**********************************************************************
 * Precondition:  The string parameter must have been initialized.
 *
 * Postcondition: Performs a preorder traversal of this tree and writes
 *				  the integer values to the referenced string delimited 
 *                with commas.
 **********************************************************************/
void BinaryTree::preorderTraverse(Node^ %inputRoot, String^ &output)
{ 
	if(inputRoot != nullptr)
	{
		// Add the root node value to the output string.
		int curValue = inputRoot->getNodeValue();
		output += Convert::ToString(curValue) + ",";

		// Traverse the left node.
		preorderTraverse(inputRoot->leftNode, output);

		// Traverse the right node.
		preorderTraverse(inputRoot->rightNode, output);
	}
}

/**********************************************************************
 * Precondition:  The string parameter must have been initialized.
 *
 * Postcondition: Performs an inorder traversal of this tree and writes
 *				  the integer values to the referenced string delimited 
 *                with commas.
 **********************************************************************/
void BinaryTree::inorderTraverse(Node^ %inputRoot, String^ &output)
{ 
	if(inputRoot != nullptr)
	{
		// Traverse the left node.
		inorderTraverse(inputRoot->leftNode, output);

		// Add the root node value to the output string.
		int curValue = inputRoot->getNodeValue();	
		output += Convert::ToString(curValue) + ",";

		// Traverse the right node.
		inorderTraverse(inputRoot->rightNode, output);
	}
}

/***********************************************************************
 * Precondition:  The string parameter must have been initialized.
 *
 * Postcondition: Performs a postorder traversal of this tree and writes
 *				  the integer values to the referenced string delimited 
 *                with commas.
 ***********************************************************************/
void BinaryTree::postorderTraverse(Node^ %inputRoot, String^ &output)
{
	if(inputRoot != nullptr)
	{
		// Traverse the left node.
		postorderTraverse(inputRoot->leftNode, output);

		// Traverse the right node.
		postorderTraverse(inputRoot->rightNode, output);

		// Add the root node value to the output string.
		int curValue = inputRoot->getNodeValue();		
		output += Convert::ToString(curValue) + ",";
	}
}

/***********************************************************************
 * Precondition:  
 *
 * Postcondition: Performs a preorder traversal of this tree and draws
 *				  the integer values to the canvas.
 ***********************************************************************/
void BinaryTree::drawTree(Node^ rootNode, int xPos, int yPos, int xOffset, Graphics^ canvas)
{
	if(rootNode!= nullptr)
	{
		// Coordinates used to draw a line between nodes.
		int xLineStart;
		int yLineStart;
		int xLineEnd;
		int yLineEnd;

		// Coordinates to be passed to this function when making a recursive 
		// call.
		int xNext;
		int yNext;
		int xOffsetNext = xOffset * 0.75;

		Brush^ b = gcnew SolidBrush(Color::Black);
		Pen^ p = gcnew Pen(Color::Black);
	
		// Coordinates and values used to draw the node value to the canvas.
		int xText = xPos + TEXT_OFFSET_X;
		int yText = yPos + TEXT_OFFSET_Y;
		Font^ textFont = gcnew Font("Arial", 12);
		String^ s = Convert::ToString(rootNode->getNodeValue());

		canvas->DrawEllipse(p, xPos, yPos, CIRCLE_SIZE, CIRCLE_SIZE);
		canvas->DrawString(s, textFont, b, xText, yText);

		// Check if there is a left node.
		if(rootNode->getLeftNode() != nullptr)
		{
			// Initialize coordinates to draw the connecting line.
			xLineStart = xPos;
			yLineStart = yPos + (CIRCLE_SIZE / 2);
			xLineEnd = xPos - xOffset + (CIRCLE_SIZE / 2);
			yLineEnd = yPos + CIRCLE_SIZE;

			// Initialize coordinates for the recursive call.
			xNext = xPos - xOffset;
			yNext = yPos + CIRCLE_SIZE;

			canvas->DrawLine(p, xLineStart, yLineStart, xLineEnd, yLineEnd);

			drawTree(rootNode->getLeftNode(), xNext, yNext, xOffsetNext, canvas);
		}

		//Check if there is a right node.
		if(rootNode->getRightNode() != nullptr)
		{
			// Initialize coordinates to draw the connecting line.
			xLineStart = xPos + CIRCLE_SIZE;
			yLineStart = yPos + (CIRCLE_SIZE / 2);
			xLineEnd = xPos + xOffset + (CIRCLE_SIZE / 2);
			yLineEnd = yPos + CIRCLE_SIZE;
			
			// Initialize coordinates for the recursive call.
			xNext = xPos + xOffset;
			yNext = yPos + CIRCLE_SIZE;

			canvas->DrawLine(p, xLineStart, yLineStart, xLineEnd, yLineEnd);

			drawTree(rootNode->getRightNode(), xNext, yNext, xOffsetNext, canvas);	
		}
	}
}

/*********************************************************************
 * Precondition:
 * 
 * Postcondition: builds an example tree that can be used to determine
 *				  that the traversal functions work as intended.
 *********************************************************************/
void BinaryTree::buildMasterTree()
{	
	rootNode = gcnew Node();

	rootNode->setNodeValue(1);

	BinaryTree^ t9 = gcnew BinaryTree(9);

	BinaryTree^ t7 = gcnew BinaryTree(7);

	BinaryTree^ t8 = gcnew BinaryTree(8);

	BinaryTree^ t6 = gcnew BinaryTree(6);
	t6->setLeftNode(t9->getRootNode());

	BinaryTree^ t4 = gcnew BinaryTree(4);
	t4->setLeftNode(t6->getRootNode());

	BinaryTree^ t5 = gcnew BinaryTree(5, t7, t8);

	BinaryTree^ t2 = gcnew BinaryTree(2, t4, t5);

	BinaryTree^ t3 = gcnew BinaryTree(3);	
	
	setLeftNode(t2->getRootNode());
	setRightNode(t3->getRootNode());
}

/************************************************************* 
 * Precondition:  The n parameter must be an integer.
 *
 * Postcondition: Wrapper function for addItem.  Returns the
 *                number of nodes traversed searching for the
 *                given integer.
 ************************************************************/
void BinaryTree::add(int n)
{
	insertItem(rootNode, n);
}

/******************************************************************** 
 * Precondition:  The n parameter must be an integer.
 *
 * Postcondition: Wrapper function for findItem.  Returns true/false 
 *                 depending on if the given int was found.
 *******************************************************************/
bool BinaryTree::find(int n)
{ 
	return findItem(rootNode, n); 
}

/**************************************************** 
 * Precondition:  The n parameter must be an integer.
 *
 * Postcondition: Wrapper function for findItem.
 ***************************************************/
int BinaryTree::findNodeCount(int n)
{	
	inspectionCount = 0;
	findItem(rootNode, n);
	return inspectionCount;
}

/******************************************************************* 
 * Precondition:  
 *
 * Postcondition: Inserts the insertValue param value into the tree.
 *******************************************************************/
void BinaryTree::insertItem(Node^ %rootPtr, int insertValue)
{
	// Add the insertValue param if rootPtr is null.
	if(rootPtr == nullptr)
	{
		rootPtr = gcnew Node();
		rootPtr->setNodeValue(insertValue);
	}
	else
	{
		// Determine which tree branch to traverse.
		if(insertValue < rootPtr->getNodeValue())		
			insertItem(rootPtr->leftNode, insertValue);
		
		else
			insertItem(rootPtr->rightNode, insertValue);
	}
}

/******************************************************************** 
 * Precondition:  
 *
 * Postcondition: searches the tree for  the insertValue param value.
 ********************************************************************/
bool BinaryTree::findItem(Node^ rootPtr, int targetValue)
{ 
	inspectionCount++;

	// If the rootPtr is null, the value isn't present in the tree.
	if(rootPtr == nullptr)
		return false;

	// Return true if the insertValue is found.
	else if(rootPtr->getNodeValue() == targetValue)
		return true;

	else
	{
		//Determine which tree branch to search.
		if(targetValue <rootPtr->getNodeValue())
			return findItem(rootPtr->leftNode, targetValue);

		else
			return findItem(rootPtr->rightNode, targetValue);
	}
}

/**********************************************************
 * Precondition:  
 *
 * Postcondition: Builds a tree of 32 random integer values 
 *				  between 0 and 99.
 **********************************************************/
void BinaryTree::buildRandomTree(Random^ r, String^ %output)
{
	rootNode = nullptr;
	int n;

	for(int i = 0; i < 32; i++)
	{
		n = r->Next(100);
		insertItem(rootNode, n);
		output += Convert::ToString(n) + ",";
	}	
}