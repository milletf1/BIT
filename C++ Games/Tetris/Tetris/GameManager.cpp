#include "StdAfx.h"
#include "GameManager.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
GameManager::GameManager(Random^ startRand, Timer^ startGameTimer, Graphics^ startCanvas, Label^ startLevelOutput, Label^ startScoreOutput)
{
	//initialize pointers that point to form objects
	rand = startRand;
	gameTimer = startGameTimer;
	canvas = startCanvas;
	levelOutput = startLevelOutput;
	scoreOutput = startScoreOutput;	
	//initialize graphics 
	canvasImage = gcnew Bitmap(800, 600);
	canvasBuffer = Graphics::FromImage(canvasImage);
	startButton = gcnew Bitmap("newGamebtn.bmp");
	emptyCellColour = Color::DarkBlue;
	//initialize gameGrid array
	gameGrid = gcnew array<Cell^, 2>(GAMEGRID_COLUMNS, GAMEGRID_ROWS);
	for(int col = 0; col < GAMEGRID_COLUMNS; col++)
	{
		for(int row = 0; row < GAMEGRID_ROWS; row++)
		{			
			//set cell properties
			gameGrid[col, row] = gcnew Cell(Point(col, row), emptyCellColour, false, canvasBuffer, CELL_WIDTH, CELL_HEIGHT);
		}
	}

	//initialize nextWindow array
	nextWindow = gcnew array<Cell^, 2>(NEXTWINDOW_COLUMNS, NEXTWINDOW_ROWS);
	for(int col = 0; col < NEXTWINDOW_COLUMNS; col++)
	{
		for(int row = 0; row < NEXTWINDOW_ROWS; row++)
		{			
			//set cell properties
			nextWindow[col, row] = gcnew Cell(Point(col, row), emptyCellColour, false, canvasBuffer, CELL_WIDTH, CELL_HEIGHT);
		}
	}
	//set inGame to false;
	inGame = false;
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//draws all the cells in the gameGrid to the form
void GameManager::DrawGridCells()
{
	for(int x = 0; x < GAMEGRID_COLUMNS; x++)
	{
		for(int y = 0; y < GAMEGRID_ROWS; y++)
		{			
			//draw the cell
			gameGrid[x, y]->Draw(Point(GAMEGRID_OFFSET_X, GAMEGRID_OFFSET_Y));
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//draws all the cells in the nextWindow to the form
void GameManager::DrawNextCells()
{
	for(int x = 0; x < NEXTWINDOW_COLUMNS; x++)
	{
		for(int y = 0; y < NEXTWINDOW_ROWS; y++)
		{			
			//draw the cell
			nextWindow[x, y]->Draw(Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y));
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GameManager::InitiateGame()
{
	playerScore = 0;
	currentLevel = 1;
	scoreOutput->Text = Convert::ToString(playerScore);
	levelOutput->Text = Convert::ToString(currentLevel);
	timerSpeed = INITIAL_SPEED;
	gameTimer->Interval = timerSpeed;
	//"empty" all the cells in the gamegrid
	for(int row = 0; row < GAMEGRID_ROWS; row++)
	{
		SetRowInactive(row);
	}
	
		
	PickNextBlock();
	PlaceNextOnGrid();
	PickNextBlock();
	inGame = true;
	Draw();	
	gameTimer->Enabled = true;
	
}
void GameManager::SetRowInactive(int row)
{
	for(int col = 0; col < GAMEGRID_COLUMNS; col++)
		{
			gameGrid[col, row]->setIsFull(false);
			gameGrid[col, row]->setIsGameBlock(false);
			gameGrid[col, row]->setCellColor(emptyCellColour);
		}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GameManager::PlaceNextOnGrid()
{
	//Set gameBlock equal to nextBlock
	gameBlock = nextBlock;
	//Set gameBlocks offset
	gameBlock->setOffset(Point(GAMEGRID_OFFSET_X, GAMEGRID_OFFSET_Y));
	gameBlock->InitializeBlockArray(Point(3, 0));
	//Set the point for gameBlock to start drawing from
}	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GameManager::PickNextBlock()
{
	int blockPicker = rand->Next(7);
	
	switch(blockPicker)
	{
		//LongBlock
		case 0:
			
			nextBlock =	gcnew LongBlock(Point(0, 1), Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y), Color::Yellow, canvasBuffer);
			break;
		//JBlock
		case 1:
			
			nextBlock =	gcnew JBlock(Point(0, 1), Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y), Color::Green, canvasBuffer);
			break;
		//LBlock
		case 2:
			
			nextBlock =	gcnew LBlock(Point(0, 1), Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y), Color::Red, canvasBuffer);
			break;
		//SBlock
		case 3:
			nextBlock =	gcnew SBlock(Point(0, 1), Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y), Color::BurlyWood, canvasBuffer);
			break;
		//SquareBlock
		case 4:
			nextBlock =	gcnew SquareBlock(Point(0, 1), Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y), Color::YellowGreen, canvasBuffer);
			break;
		//TBlock
		case 5:
			nextBlock =	gcnew TBlock(Point(0, 1), Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y), Color::DarkCyan, canvasBuffer);
			break;
		//ZBlock
		case 6:
			nextBlock =	gcnew ZBlock(Point(0, 1), Point(NEXTWINDOW_OFFSET_X, NEXTWINDOW_OFFSET_Y), Color::HotPink, canvasBuffer);
			break;
		default:
			break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GameManager::DrawBlocks()
{
	gameBlock->Draw();
	array<Cell^>^ tempArray = gameBlock->getBlockArray();
	bool rValue = false;	
	nextBlock->Draw();
}


void GameManager::HandleRowRemoval()
{
	int rowsCleared = 0;
	//cycle through the rows of the array
	for(int row = 0; row < GAMEGRID_ROWS; row++)
	{
		//doRemove is used by the game manager to determine if a row needs removed
		bool doRemove = true;
		//check each cell in the row while doRemove is true
		while(doRemove)
		{
			//cycle through the columns of the array
			for(int col = 0; col < GAMEGRID_COLUMNS; col++)
			{
				//check if the cell is empty
				if(!gameGrid[col, row]->getIsFull())
				{
					doRemove =false;
				}
			}
			//check if the row is full
			if(doRemove)
			{
				rowsCleared = rowsCleared + 1;
				//if it is, set the cells in the row to inactive
				SetRowInactive(row);
				//and move the blocks in the upper rows down
				MoveRowsDown(row);
			}
		}
	}

	if(rowsCleared > 0)
	{
		int preScore = playerScore;
		AddPoints(rowsCleared);
		System::Diagnostics::Debug::WriteLine("old: " + Convert::ToString(preScore) + "\nnew: " + Convert::ToString(playerScore));
		HandleLevelSwitch(preScore);
	}
}
void GameManager::MoveRowsDown(int row)
{
	//cycle through each row starting with the one above the row that is to be removed
	for(int liveRow = row - 1; liveRow >= 0; liveRow--)
	{
		//cycle through the columns of the array
		for(int col = 0; col < GAMEGRID_COLUMNS; col++)
		{
			//set the cell below the currently selected cell equal to the current cell
			gameGrid[col, liveRow + 1]->setIsFull(gameGrid[col, liveRow]->getIsFull());
			gameGrid[col, liveRow + 1]->setIsGameBlock(gameGrid[col, liveRow]->getIsGameBlock());
			gameGrid[col, liveRow + 1]->setCellColor(gameGrid[col, liveRow]->getCellColor());

		}
	}
}
void GameManager::AddPoints(int rowsCleared)
{
	//Add points based on the number of rows cleared.
	switch(rowsCleared)
	{
		case 1:
			playerScore = playerScore + SINGLE_ROW_POINT;
			break;

		case 2:
			playerScore = playerScore + DOUBLE_ROW_POINT;
			break;

		case 3:
			playerScore = playerScore + TRIPLE_ROW_POINT;
			break;

		case 4:
			playerScore = playerScore + QUADRUPLE_ROW_POINT;
			break;

		default:
			break;
	}
	//Output to the form
	scoreOutput->Text = Convert::ToString(playerScore);
}
//RaiseSpeed increases the speed that the blocks descend the game grid
void GameManager::RaiseSpeed()
{
	//set the timer interval to half its previous interval
	gameTimer->Interval = DROP_SPEED;
}
//LowerSpeed decreases the speed that the blocks descend the game grid 
void GameManager::LowerSpeed()
{
	//set the timer interval to double its previous interval
	gameTimer->Interval = timerSpeed;
}
void GameManager::MoveBlockLeft()
{	
	BlockTemplate^ tempBlock = gameBlock;
	gameBlock->MoveLeft();
	
	//check for a collision
	if(CheckOverlap())
	{
		gameBlock->MoveRight();
	}
	else
	{
		Draw();
	}
}
void GameManager::MoveBlockRight()
{
	gameBlock->MoveRight();
	//check for a collision
	if(CheckOverlap())
	{
		gameBlock->MoveLeft();
	}
	else
	{
		Draw();
	}
}
void GameManager::RotateBlock()
{
	
	gameBlock->Rotate();
	//check for a collision
	if(CheckOverlap())
	{
		gameBlock->Rotate();
		gameBlock->Rotate();
		gameBlock->Rotate();
	}
	else
	{
		Draw();
	}
}
//CheckOverlap checks if a block movement given by the player is within the bounds of 
//the game grid, and doesn't enter a cell occupied by a cell that is full
bool GameManager::CheckOverlap()
{
	array<Cell^>^ tempArray = gameBlock->getBlockArray();
	bool rValue = false;
	for(int i = 0; i < tempArray->Length; i++)
	{
		//check if the cell is outside the bounds of the gamegrid (not including the top)	
		if(tempArray[i]->getGridPoint()->X < 0
			|| tempArray[i]->getGridPoint()->X >= GAMEGRID_COLUMNS
			|| tempArray[i]->getGridPoint()->Y >= GAMEGRID_ROWS)
		{
			rValue = true;
		}
		//checks if the program will throw an error if the tempArrays Y position is outside the top bounds of the gamegrid.
		//TODO explain properly ASAP, thats not what really what happens.
		//if it is, it can't possibly share a cell with the gamegrid
		else if(tempArray[i]->getGridPoint()->Y > 0)
		{
			if(gameGrid[tempArray[i]->getGridPoint()->X, tempArray[i]->getGridPoint()->Y]->getIsFull())
			{
				rValue = true;
			}		
		}
		//TODO check if it is outside the top of the gamegrid, ignore if thats the case. 
		//check if the cell occupys the same space as a cell that is full
		
	}
	return rValue;
}
void GameManager::AddBlockToPile()
{
	bool rValue = false;
	array<Cell^>^ tempArray = gameBlock->getBlockArray();

	for(int i = 0; i < tempArray->Length; i++)
	{
		//set the grid cell that occupys the same space as the gameBlock to full.
		gameGrid[tempArray[i]->getGridPoint()->X, tempArray[i]->getGridPoint()->Y]->setIsFull(true);
		//change the color of the cell that occupys the same space as the gameBlock to the gameBlocks colour.
		gameGrid[tempArray[i]->getGridPoint()->X, tempArray[i]->getGridPoint()->Y]->setCellColor(tempArray[i]->getCellColor());
		//set the cell to gameBlock (so that the cells borders are drawn)
		gameGrid[tempArray[i]->getGridPoint()->X, tempArray[i]->getGridPoint()->Y]->setIsGameBlock(true);
	}
}
bool GameManager::CheckBlockStopped()
{
	bool rValue = false;
	array<Cell^>^ tempArray = gameBlock->getBlockArray();

	for(int i = 0; i < tempArray->Length; i++)
	{
		//make sure the cell is not offscreen (for game blocks)
		if(tempArray[i]->getGridPoint()->Y >= 0)
		{
			//check if the block has landed on the bottom of the grid or on a previous gameBlock.
			if(tempArray[i]->getGridPoint()->Y == GAMEGRID_ROWS - 1 ||
				gameGrid[tempArray[i]->getGridPoint()->X, tempArray[i]->getGridPoint()->Y + 1]->getIsFull())
			{
			
				rValue = true;
			}
		}
	}	
	return rValue;
}

void GameManager::GameCycle()
{
//check for full cells below gameBlock
	if(CheckBlockStopped())
	{
		AddBlockToPile();
		HandleRowRemoval();
		if(CheckFullGrid())
		{
			gameTimer->Enabled = false;
			MessageBox::Show("Game Over", "Game Over");
			inGame = false;
		}
		else
		{
			PlaceNextOnGrid();
			PickNextBlock();
		}

//		check if gameGrid is full
//		if true
//			*end game (aka stop timer)
//		else
//			* remove rows if needed
//			* move nextblock from preview window to game grid
//			* create a new block in preview window
//			* draw 
	}
	else
	{
		gameBlock->MoveDown();
	}
	Draw();
}
bool GameManager::CheckFullGrid()
{
	bool rValue = false;
	int row = 0;
	for(int col = 0; col < GAMEGRID_COLUMNS; col++)
	{
		//check each cell at the top of the grid to see if its full
		if(gameGrid[col, row]->getIsFull())
		{
			rValue = true;
		}
	}
	return rValue;
}
void GameManager::Draw()
{
	DrawGridCells();
	DrawNextCells();
	DrawButton();
	if(inGame)
	{
		DrawBlocks();	
	}
	canvas->DrawImageUnscaled(canvasImage, 0, 0);
}

//handle click is used by the game manager to determine if the player has clicked on new game
void GameManager::HandleClick(Point^ p)
{
	
	//new is used to determine if the click was within the bounds of the newGame button
	bool clickNew = true;

	//check if the click too far left
	if(p->X < BUTTON_LEFT)
	{
		clickNew = false;
	}
	//check if the click is too far right
	if(p->X > BUTTON_LEFT + startButton->Width)
	{
		clickNew = false;
	}
	//check if the click is too high
	if(p->Y < BUTTON_TOP)
	{
		clickNew = false;
	}
	//check if the click is too low
	if(p->Y > BUTTON_TOP + startButton->Height)
	{
		clickNew = false;
	}

	// if the clickNew is still true after the previous if statements, the player clicked the start
	//button and a new game can begin
	if(clickNew)
	{
		//check if the player is in game
		if(inGame)
		{
			gameTimer->Enabled = false;
			DialogResult restartGame = MessageBox::Show("A game is in progress, are you sure you want to start a new game?",
				"Game in Progress",MessageBoxButtons::YesNo);
			if(restartGame == DialogResult::Yes)
			{
				InitiateGame();
			}
			else
			{
				gameTimer->Enabled = true;
			}
		}
		else
		{
			//the gametimer is disabled to prevent new blocks spawning below where they're supposed to
			gameTimer->Enabled = false;
			InitiateGame();
		}
	}
}

void GameManager::DrawButton()
{
	canvasBuffer->DrawImage(startButton, Point( BUTTON_LEFT, BUTTON_TOP));
}

void GameManager::HandleLevelSwitch(int preScore)
{
	bool switchLevel = false;

	if(preScore < POINTS_TO_LVL_5 && playerScore >= POINTS_TO_LVL_5)
	{
		switchLevel = true;
	}
	else if(preScore < POINTS_TO_LVL_4 && playerScore >= POINTS_TO_LVL_4)
	{
		switchLevel = true;
	}
	else if(preScore < POINTS_TO_LVL_3 && playerScore >= POINTS_TO_LVL_3)
	{
		switchLevel = true;
	}
	else if(preScore < POINTS_TO_LVL_2 && playerScore >= POINTS_TO_LVL_2)
	{
		switchLevel = true;
	}

	if(switchLevel)
	{
		currentLevel = currentLevel + 1;
		timerSpeed = timerSpeed - LEVELUP_SPEED_DEC;
		gameTimer->Interval = timerSpeed;
		levelOutput->Text = Convert::ToString(currentLevel);
	}
}