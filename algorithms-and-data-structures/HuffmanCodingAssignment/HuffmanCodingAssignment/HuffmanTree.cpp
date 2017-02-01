#include "StdAfx.h"
#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{}


/************************************************************************************
 * Precondition:  The filePath parameter must be initialized and contain the path to
 *				  a valid file.  A valid file is defined as a file that contains 
 *				  alphanumeric characters.
 * 
 * Postcondition: Creates a new symbolFrequency dictionary from the chars in the file
 *				  specified by the filePath parameter.
 ************************************************************************************/
array<HuffmanNode^>^ HuffmanTree::initHuffmanTreeBuild(String^ filePath)
{	
	symbolFrequency = gcnew Dictionary<Char, int>();
	array<HuffmanNode^>^  treeBuildNodes; 

	StreamReader^ sr = gcnew StreamReader(filePath);
	String^ line = sr->ReadLine();

	// Iterate through each line in the given text file.
	while(line != nullptr)
	{
		// Iterate through each character in the current line.
		for(int i = 0; i < line->Length; i++)
		{
			// Check if the current character is in the symbol frequency dictionary.
			if(symbolFrequency->ContainsKey(line[i]))
				
				// If it is, increment it's frequency.
				symbolFrequency[line[i]]++;

			else
				// Otherwise, add the current character to the dictionary with a value of 1.
				symbolFrequency[line[i]] = 1;
		}
		// Read the next line.
		line = sr->ReadLine();
	}
	sr->Close();

	// Create an array of Huffman nodes.
	treeBuildNodes = gcnew array<HuffmanNode^>(symbolFrequency->Count);
	int count = 0;

	// Iterate through each KeyValuePair in the symbolFrequency dictionary.
	for each(KeyValuePair<Char, int>^ pair in symbolFrequency)
	{
		// Create a new huffman node and add the symbol and frequency from the KeyValuePair.
		HuffmanNode^ n = gcnew HuffmanNode();

		n->symbols = Convert::ToString(pair->Key);
		n->frequency = pair->Value;

		treeBuildNodes[count] = n;
		count++;
	}
	return treeBuildNodes;
}

/*******************************************************************************************
 * Precondition:  The symbols dictionary must have been initialized.
 * 
 * Postcondition: Initializes and returns an array of Huffman nodes from the symbolFrequency 
 *				  dictionary.
 *******************************************************************************************/
array<HuffmanNode^>^ HuffmanTree::initHuffmanTreeBuild()	
{
	array<HuffmanNode^>^ treeBuildNodes = gcnew array<HuffmanNode^>(symbolFrequency->Count);
	int count = 0;

	// Iterate through each KeyValuePair in the symbolFrequency dictionary.
	for each(KeyValuePair<Char, int>^ pair in symbolFrequency)
	{
		// Create a new huffman node and add the symbol and frequency from the KeyValuePair.
		HuffmanNode^ n = gcnew HuffmanNode();
		n->symbols = Convert::ToString(pair->Key);
		n->frequency = pair->Value;

		treeBuildNodes[count] = n;
		count++;
	}
	return treeBuildNodes;
}

/********************************************************************************
 * Precondition:  The symbols dictionary must have been initialized.
 * 
 * Postcondition: Public function that takes a dictionary of symbols and their 
 *				  frequencies as a parameter and uses it to build a Huffman tree.
 ********************************************************************************/
void HuffmanTree::buildHuffmanTree(Dictionary<Char, int>^ symbols)
{
	symbolFrequency = symbols;
	huffmanCode = gcnew Dictionary<Char, String^>();
	String^ huffmanCode = "";

	// Build Huffman Tree.
	array<HuffmanNode^>^ treeBuildNodes = initHuffmanTreeBuild();	
	buildTree(treeBuildNodes);

	// Build Huffman Code.
	buildHuffmanCode(rootNode, huffmanCode);
}

/**************************************************************************************
 * Precondition:  The filePath parameter must be initialized and contain the path to
 *				  a valid file.  A valid file is defined as a file that contains 
 *				  alphanumeric characters.
 *
 * Postcondition: Public function that takes a string that specifies a file path.  uses 
 *				  the chars in the given file to build a huffman tree.
 **************************************************************************************/
void HuffmanTree::buildHuffmanTree(String^ filePath)
{
	huffmanCode = gcnew Dictionary<Char, String^>();
	String^ huffmanCode = "";

	// Build Huffman Tree.
	array<HuffmanNode^>^ treeBuildNodes = initHuffmanTreeBuild(filePath);		
	buildTree(treeBuildNodes);

	// Build Huffman Code.
	buildHuffmanCode(rootNode, huffmanCode);
}

/******************************************************************************************
 * Precondition:  The treeBuildNodes array must have been initialized and contain the
 *				  Huffman nodes needed to build a Huffman tree.
 * 
 * Postcondition: Builds a huffman tree from the Huffman nodes stored in the treeBuildNodes
				  array.
 ******************************************************************************************/
void HuffmanTree::buildTree(array<HuffmanNode^>^ treeBuildNodes)
{
	// Check that there are enough nodes in the given array to build the Huffman tree.
	if(treeBuildNodes->Length >= 2)
	{
		// Sort array.
		treeBuildNodes = sortNodes(treeBuildNodes);

		// Create a new Huffman node.
		HuffmanNode^ topNode = gcnew HuffmanNode();
		
		// Initialize the values of the new Huffman node.
		topNode->frequency = treeBuildNodes[0]->frequency + treeBuildNodes[1]->frequency;
		topNode->symbols = treeBuildNodes[0]->symbols + treeBuildNodes[1]->symbols;
		topNode->LeftNode = treeBuildNodes[0];
		topNode->RightNode = treeBuildNodes[1];

		// Check if we have finished building the Huffman tree.
		if(treeBuildNodes->Length == 2)		

			// If we have, set the topNode as the root node.
			rootNode = topNode;
		
		else
		{
			// Build a new array that includes the new top node and excludes the topNode's left 
			// and right nodes.
			array<HuffmanNode^>^ tempNodes = gcnew array<HuffmanNode^>(treeBuildNodes->Length - 1);
			tempNodes[0] = topNode;
			
			for(int i = 2; i < treeBuildNodes->Length; i++)
				tempNodes[i - 1] = treeBuildNodes[i];

			// Call this function with the new array.
			buildTree(tempNodes);
		}
	}
}

/****************************************************************************************
 * Precondition:  
 * 
 * Postcondition: Sorts the given array of Huffman nodes in descending order using a 
 *				  selection sort.
 ****************************************************************************************/
array<HuffmanNode^>^ HuffmanTree::sortNodes(array<HuffmanNode^>^ nodeArray)
{
	// Iterate through nodeArray starting from the unsorted area of the array
	// (we assume that nodeArray[0] is already sorted).
	for(int i = 1; i < nodeArray->Length; i++)
	{
		HuffmanNode^ unsortedNode = nodeArray[i];
		
		// Iterate backwards through the sorted area of nodeArray.
		for(int sortedNode = i - 1; sortedNode >=0; sortedNode--)
		{
			// If the unsortedNode's frequency is smaller than the frequency defined by sortedNode,
			// swap their position.
			if(unsortedNode->frequency < nodeArray[sortedNode]->frequency)
			{
				nodeArray[sortedNode + 1] = nodeArray[sortedNode];
				nodeArray[sortedNode] = unsortedNode;
			}
		}
	}
	return nodeArray;
}

/***********************************************************************************
 * Precondition:  A Huffman tree must have been built prior to calling this function
 * 
 * Postcondition: Public function that returns a bitmap of the current Huffman tree.
 ***********************************************************************************/
Bitmap^ HuffmanTree::getHuffmanTree(int width, int height, Color bgColor)
{
	// Initialize the point to start drawing this tree.
	int startX = width / 2 - (CIRCLE_SIZE / 2);
	int startY = 0;

	// Initialize the return bitmap.
	Bitmap^ treeBmp = gcnew Bitmap(width, height);

	//Draw a background.  If this step is skipped the text appears blurry on the return bitmap.
	Graphics::FromImage(treeBmp)->FillRectangle(gcnew SolidBrush(bgColor), 0, 0, width, height);
	
	// Draw and return the Huffman tree bitmap.
	drawTree(rootNode, startX, startY, X_OFFSET, treeBmp);
	
	return treeBmp;
}

/***************************************************************************************
 * Precondition:  The encoded string parameter must be encoded using the current Huffman 
 *                code and only contain '1' and '0' chars.
 * 
 * Postcondition: Uses the current Huffman code to decode and return the given string.
 ***************************************************************************************/
String^ HuffmanTree::decodeString(String^ encoded)
{
	String^ decodedString = "";
	HuffmanNode^ node = rootNode;

	// Iterate through each character in the encoded string.
	for(int i = 0; i < encoded->Length; i++)
	{
		Char encodedBit = encoded->ToCharArray()[i];
	
		// Determine which direction to traverse from the current char.
		if(encodedBit == '1')		
			node = node->LeftNode;
		
		else if(encodedBit == '0')		
			node = node->RightNode;		
		
		// If the current node has no descendant nodes, we can add the symbol from it to 
		// the decoded string.
		if(node->LeftNode == nullptr && node->RightNode == nullptr)
		{
			decodedString += node->symbols;
			node = rootNode;
		}
	}
	return decodedString;
}

/****************************************************************************************
 * Precondition:  
 * 
 * Postcondition: Returns the total number of bits needed to represent the current symbol
 *                frequency data using Huffman coding.
 ****************************************************************************************/
int HuffmanTree::getHuffmanBits()
{
	int huffmanBits = 0;

	for each (KeyValuePair<Char, String^>^ pair in huffmanCode)
	{
		// Get the total number of bits needed to represent the current char from the 
		// symbolFrequency dictionary and add it to the Huffman bits count.
		int totalBits = pair->Value->Length * symbolFrequency[pair->Key];
		huffmanBits += totalBits;
	}
	return huffmanBits;
}

/****************************************************************************************
 * Precondition:  
 * 
 * Postcondition: Returns the total number of bits needed to represent the current symbol
 *				  frequency data using fixed length coding.
 ****************************************************************************************/
int HuffmanTree::getFixedLengthBits()
{
	int fixedLengthBits = 0;
	// Calculate how many bits each char will require.
	int requiredBits = Math::Ceiling(Math::Log(symbolFrequency->Count, 2));

	for each (KeyValuePair<Char, String^>^ pair in huffmanCode)
	{
		// Get the total number of bits needed to represent the current char from the 
		// symbolFrequency dictionary and add it to the fixed length bits count.
		int totalBits = requiredBits * symbolFrequency[pair->Key];
		fixedLengthBits += totalBits;
	}
	return fixedLengthBits;
}

/****************************************************************************************
 * Precondition:  The huffman tree must have been initialized.
 * 
 * Postcondition: Builds a huffman code reference from a huffman tree using recursion.
 ****************************************************************************************/
void HuffmanTree::buildHuffmanCode(HuffmanNode^ node, String^ code)
{
	// Check that the current node is not null.
	if(node != nullptr)
	{
		// If there is a left descendant node, call this function on it and
		// add 1 to the code string.
		if(node->LeftNode != nullptr)
		{
			String^ leftCode = code + "1";
			buildHuffmanCode(node->LeftNode, leftCode);
		}

		// If there is a left descendant node, call this function on it and
		// add 0 to the code string.
		if(node->RightNode != nullptr)
		{
			String^ rightCode = code + "0";
			buildHuffmanCode(node->RightNode, rightCode);
		}

		// If there are no descendant nodes, add the current code as the value in the huffmanCode 
		// dictionary where the key is defined as the current nodes symbol.
		if(node->LeftNode == nullptr && node->RightNode == nullptr)
			huffmanCode[node->symbols->ToCharArray()[0]] = code;
	}
}


/******************************************************************************************
 * Precondition:  The canvas parameter must be initialized.  The symbolFrequency dictionary
 *				  must have been initialized.
 * 
 * Postcondition: Draws a huffman tree bitmap from the data stored in the symbolFrequency 
 *				  dictionary.
 ******************************************************************************************/
void HuffmanTree::drawTree(HuffmanNode^ node, int xPos, int yPos, int xOffset, Bitmap^ %canvas)
{	
	if(node!= nullptr)
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
		int xOffsetNext = xOffset * 0.8;

		Brush^ b = gcnew SolidBrush(Color::Black);
		Pen^ p = gcnew Pen(Color::Black);
	
		// Coordinates and values used to draw the node value to the canvas.
		int xText = xPos + TEXT_OFFSET_X;
		int yText = yPos + TEXT_OFFSET_Y;
		Font^ textFont = gcnew Font("Arial", TEXT_SIZE);
		String^ s = node->symbols + " " +Convert::ToString(node->frequency);
		
		Graphics::FromImage(canvas)->DrawEllipse(p, xPos, yPos, CIRCLE_SIZE, CIRCLE_SIZE);
		Graphics::FromImage(canvas)->DrawString(s, textFont, b, xText, yText);

		// Check if there is a left node.
		if(node->LeftNode != nullptr)
		{
			// Initialize coordinates to draw the connecting line.
			xLineStart = xPos;
			yLineStart = yPos + (CIRCLE_SIZE / 2);
			xLineEnd = xPos - xOffset + (CIRCLE_SIZE / 2);
			yLineEnd = yPos + (CIRCLE_SIZE * 1.5);

			// Initialize coordinates for the recursive call.
			xNext = xPos - xOffset;
			yNext = yPos + (CIRCLE_SIZE * 1.5);

			Graphics::FromImage(canvas)->DrawLine(p, xLineStart, yLineStart, xLineEnd, yLineEnd);

			drawTree(node->LeftNode, xNext, yNext, xOffsetNext, canvas);
		}

		//Check if there is a right node.
		if(node->RightNode != nullptr)
		{
			// Initialize coordinates to draw the connecting line.
			xLineStart = xPos + CIRCLE_SIZE;
			yLineStart = yPos + (CIRCLE_SIZE / 2);
			xLineEnd = xPos + xOffset + (CIRCLE_SIZE / 2);
			yLineEnd = yPos + (CIRCLE_SIZE * 1.5);
			
			// Initialize coordinates for the recursive call.
			xNext = xPos + xOffset;
			yNext = yPos + (CIRCLE_SIZE * 1.5);

			Graphics::FromImage(canvas)->DrawLine(p, xLineStart, yLineStart, xLineEnd, yLineEnd);

			drawTree(node->RightNode, xNext, yNext, xOffsetNext, canvas);	
		}
	}
}
