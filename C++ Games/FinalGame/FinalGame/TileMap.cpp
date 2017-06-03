#include "StdAfx.h"
#include "TileMap.h"

//***********
//Constructor
//***********
TileMap::TileMap(int sMapNumber, int sMapYLatitude, int sMapTileHeight, int sMapTileWidth)
{
	mapTileHeight = sMapTileHeight;
	mapTileWidth = sMapTileWidth;
	myMap = gcnew array<int, 2>(mapTileWidth, mapTileHeight);
	mapNumber = sMapNumber;
	mapYLatitude = sMapYLatitude;

	Next = nullptr;
}//*************************************************************************************

//********************************
//Loads a TileMap From a .csv file
//********************************
void TileMap::LoadMapFromFile(String^ fileName)
{
	//create a stream reader
	StreamReader^ sr = File::OpenText(fileName);

	//create a String that wil read the streamreader line
	String^ line;

	//set up a counter to decide which map row to write to
	int row = mapTileHeight - 1;

	//read each line in the .csv file
	while(line = sr->ReadLine())
	{
		//create an array to store the chars in the line
		array<String^>^ lineArray = line->Split(',');

		//for loop through each char in the lineArray, adding it to myMap
		for(int col = 0; col < lineArray->Length; col++)
		{
			myMap[col, row] = Convert::ToInt16(lineArray[col]);
		}
		//decrement the row counter
		row -= 1;
	}
}//*************************************************************************************
