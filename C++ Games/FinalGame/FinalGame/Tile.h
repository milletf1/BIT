#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//********************************************************
// A tile contains the following information about a tile:
// * its image
// * if it is a solid object
//********************************************************
ref class Tile
{
private:
	Bitmap^ tileBitmap;
	bool isSolidObject;
public:
	//constructor
	Tile(Bitmap^ sTileBitmap, bool sIsSolidObject);
	
	//get and sets
	Bitmap^ getTileBitmap() {return tileBitmap;}
	bool getIsSolidObject() {return isSolidObject;}	
};
