#include "StdAfx.h"
#include "Ghost.h"

/// <summary>
/// Constructor
/// </summary>
Ghost::Ghost(Graphics^ sCanvas, String^ upSheet, String^ downSheet, String^ leftSheet, String^ rightSheet,
		int sNFrames, Point^ sDrawPos, int sDrawWidth, int sDrawHeight, int sMoveSpeed, Random^ sRand, Rectangle^ sBounds)
		: Sprite(sCanvas, upSheet, downSheet, leftSheet, rightSheet, sNFrames, sDrawPos, sDrawWidth, 
		sDrawHeight, sMoveSpeed, sRand)
{
	bounds = sBounds;
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Overridden move function.  This is needed because the ghost sprite can move through walls, 
/// and uses a rectangle as its bounds.
/// </summary>
void Ghost::Move()
{	
	//the new position to draw the ghost
	int newXPos;
	int newYPos;
	//set the bounds  of the rectangle		
	int leftBounds = bounds->X;
	int rightBounds = bounds->X + bounds->Width;
	int bottomBounds = bounds->Y + bounds->Height;
	int topBounds = bounds->Y;
	
	//set the bounds of the ghost
	int myLeft = drawPos->X;
	int myRight = drawPos->X + drawWidth;
	int myTop = drawPos->Y;
	int myBottom = drawPos->Y + drawHeight;	
	
		//set the new draw positions
		newXPos = drawPos->X + (moveDir[currentDir]->X * moveSpeed);
		newYPos = drawPos->Y + (moveDir[currentDir]->Y * moveSpeed);
		
		//check that the new draw position is within the ghosts bounds
		if( (myLeft < leftBounds && currentDir == LEFT) ||
			(myRight > rightBounds && currentDir == RIGHT) ||
			(myTop < topBounds && currentDir == UP) ||
			(myBottom > bottomBounds && currentDir == DOWN) )
		{
			//if not, make the ghost move in the other direction
			BounceGhost();
			//set the new draw positions
			newXPos = drawPos->X + (moveDir[currentDir]->X * moveSpeed);
			newYPos = drawPos->Y + (moveDir[currentDir]->Y * moveSpeed);
		}
	//set the draw position to the new positions
	drawPos->X = newXPos;
	drawPos->Y = newYPos;
	
	//increment the frame
	IncrementFrame();	
}//End//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Reverses the ghosts direction when it hits it's bounds
/// </summary>
void Ghost::BounceGhost()
{
	if(currentDir == DOWN)
		ChangeDirection(UP);

	else if(currentDir = UP)
		ChangeDirection(DOWN);

	else if(currentDir == LEFT)
		ChangeDirection(RIGHT);

	else if(currentDir == RIGHT)
		ChangeDirection(LEFT);
}//End//////////////////////////////////////////////////////////////////////////////