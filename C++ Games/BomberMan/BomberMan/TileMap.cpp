#include "StdAfx.h"
#include "TileMap.h"

/// <summary>
/// Constructor
/// </summary>
TileMap::TileMap(TileList^ sTileList, int mapRows, int mapCols)
{
	tileList = sTileList;
	map = gcnew array<int, 2>(mapRows, mapCols);
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Loads the tilemap from a csv file.
/// </summary>
void TileMap::LoadFromFile(String^ fileName)
{
	//set up a streamreader
	StreamReader^ sr = File::OpenText(fileName);
	String^ line;
	//set up a counter to dictate the map row to write to.
	int row = 0;

	while(line = sr->ReadLine())
	{
		//create an array of strings that is a split of the current line
		array<String^>^ lineArray = line->Split(',');
		for (int col = 0; col < lineArray->Length; col++)
		{
			//add the value in the line array at x to the map
			map[row, col] = Convert::ToInt16(lineArray[col]);
		}
		//increment the row counter
		row += 1;	
	}
}//End//////////////////////////////////////////////////////////////////////////////
