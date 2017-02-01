#include "StdAfx.h"
#include "GridDisplay.h"

GridDisplay::GridDisplay(Panel^ output)
{
	displayOutput = output;
}

/**********************************************************************************
 * Precondition:  The given string parameter must be formatted correctly 
 *				  (r:g:b, where rgb represent red, blue, and green color values).
 *
 * Postcondition: Converts the given string parameter into a colour and returns it.
 **********************************************************************************/
Color GridDisplay::fetchColor(String^ rgbColor)
{
	array<String^>^ colorArray = rgbColor->Split(':');
	int red = Convert::ToInt16(colorArray[GRIDDISPLAY_RED]);
	int blue = Convert::ToInt16(colorArray[GRIDDISPLAY_BLUE]);
	int green = Convert::ToInt16(colorArray[GRIDDISPLAY_GREEN]);

	Color c = Color::FromArgb(red, green, blue);

	return c;
}

/**********************************************************************************
 * Precondition:  The given string array must contain correctly formatted strings
 *				  (r:g:b, where rgb represent red, blue, and green color values).
 *
 * Postcondition: Converts the given string parameter into a colour and returns it.
 **********************************************************************************/
void GridDisplay::createImage(array<String^,2>^ rgbColors)
{
	// initialize the image buffer.
	displayImage = gcnew Bitmap(displayOutput->Width, displayOutput->Height);
	Graphics^ g = Graphics::FromImage(displayImage);

	// set the size of each square in the grid.
	int cellSize = displayOutput->Width / CELLS;
	
	for(int row = 0; row < CELLS; row++)
	{
		for(int col = 0; col < CELLS; col++)
		{			
			// get the draw color.
			Color c = fetchColor(rgbColors[row, col]);
			Brush^ b = gcnew SolidBrush(c);

			// get the draw position.
			int xPos = col * cellSize;
			int yPos = row * cellSize;

			//draw the new cell to the bitmap.
			g->FillRectangle(b, xPos, yPos, cellSize, cellSize);
		}
	}
	//draw the bitmap to the panel.
	displayOutput->CreateGraphics()->DrawImage(displayImage,0, 0);
}
