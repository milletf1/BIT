#pragma once
#include "HuffmanNode.h"

#define CIRCLE_SIZE 60
#define TEXT_SIZE 8
#define TEXT_OFFSET_X 10
#define TEXT_OFFSET_Y 24
#define X_OFFSET 120

using namespace System;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class HuffmanTree
{
private:
	HuffmanNode^ rootNode;
	Dictionary<Char, String^>^ huffmanCode;
	Dictionary<Char, int>^ symbolFrequency;
	
	array<HuffmanNode^>^ sortNodes(array<HuffmanNode^>^ nodeArray);						// sorts nodes stored in an array by frequency.

	array<HuffmanNode^>^ initHuffmanTreeBuild();										// Initialize huffman tree build when given a set of symbol frequencies.
	array<HuffmanNode^>^ initHuffmanTreeBuild(String^ filePath);						// Initialize huffman tree build when given a file.
	
	void buildTree(array<HuffmanNode^>^ treeBuildNodes);								// builds a huffman tree.
	void buildHuffmanCode(HuffmanNode^ node, String^ code);								// builds a huffman code.

	
	void drawTree(HuffmanNode^ node, int xPos, int yPos, int xOffset, Bitmap^ %canvas);	// draws a huffman tree bitmap.
public:
	HuffmanTree();

	void buildHuffmanTree(Dictionary<Char, int>^ symbols);								// public function to build a huffman tree from given symbol frequencies.
	void buildHuffmanTree(String^ filePath);											// public function to build a huffman tree from a file.

	Dictionary<Char, int>^ getSymbolFrequency() { return symbolFrequency; }				// returns the frequency of all symbols in the huffman tree.
	Dictionary<Char, String^>^ getHuffmanCode()	{ return huffmanCode; }					// returns the huffman code from the current huffman tree.

	Bitmap^ getHuffmanTree(int width, int height, Color bgColor);
	String^ decodeString(String^ encoded);
	int getHuffmanBits();
	int getFixedLengthBits();
};

// foreach (KeyValuePair<string, Int16> author in AuthorList.OrderBy(key => key.Value))