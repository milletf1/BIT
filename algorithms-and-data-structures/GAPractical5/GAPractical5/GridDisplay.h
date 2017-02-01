#pragma once

// array positions used to determine new rgb colours from a string.
#define GRIDDISPLAY_RED 0
#define GRIDDISPLAY_GREEN 1
#define GRIDDISPLAY_BLUE 2

#define CELLS 6

using namespace System;
using namespace System::Windows::Forms;
using namespace System::ComponentModel;
using namespace System::Drawing;

ref class GridDisplay
{
private:
	Panel^ displayOutput;
	Bitmap^ displayImage;

	Color fetchColor(String^ rgbColor);
public:
	GridDisplay(Panel^ output);

	void createImage(array<String^,2>^ rgbColors);

};
