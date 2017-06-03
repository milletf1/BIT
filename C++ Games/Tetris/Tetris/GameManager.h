#pragma once
#include "Cell.h"
#include "BlockTemplate.h"
#include "LongBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "SBlock.h"
#include "TBlock.h"
#include "SquareBlock.h"
#include "ZBlock.h"

#define GAMEGRID_OFFSET_X 20
#define GAMEGRID_OFFSET_Y 20
#define GAMEGRID_COLUMNS 10
#define GAMEGRID_ROWS 20

#define BUTTON_TOP 485
#define BUTTON_LEFT 280

#define INITIAL_SPEED 300
#define LEVELUP_SPEED_DEC 30
#define DROP_SPEED 50

#define NEXTWINDOW_OFFSET_X 300
#define NEXTWINDOW_OFFSET_Y 20
#define NEXTWINDOW_COLUMNS 4
#define NEXTWINDOW_ROWS 3

#define CELL_WIDTH 25
#define CELL_HEIGHT 25

#define SINGLE_ROW_POINT 10
#define DOUBLE_ROW_POINT 40
#define TRIPLE_ROW_POINT 90
#define QUADRUPLE_ROW_POINT 120

#define POINTS_TO_LVL_2 140
#define POINTS_TO_LVL_3 480
#define POINTS_TO_LVL_4 820
#define POINTS_TO_LVL_5 1640

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class GameManager
{
private:
	//gameBlock holds the block controled by the player
	BlockTemplate^ gameBlock;
	BlockTemplate^ nextBlock;
	//gameGridOffset and nextWindowOffset are used to determine where to 
	//draw the cells used by the game grid and the next game-block preview window	
	Point^ gameGridOffset;
	Point^ nextWindowOffset;

	Color emptyCellColour;
	array<Cell^, 2>^ gameGrid;
	array<Cell^, 2>^ nextWindow;

	Graphics^ canvas;
	Graphics^ canvasBuffer;
	Bitmap^ canvasImage;
	Bitmap^ startButton;
	Random^ rand;
	Timer^ gameTimer;
	int timerSpeed;
	Label^ scoreOutput;
	Label^ levelOutput;
	int playerScore;
	int currentLevel;
	bool inGame;
public:
	//constructor
	GameManager(Random^ startRand, Timer^ startGameTimer, Graphics^ startCanvas, Label^ startLevelOutput, Label^ startScoreOutput);

	//methods
	
	void InitiateGame();
	void RaiseSpeed();
	void LowerSpeed();
	void MoveBlockLeft();
	void MoveBlockRight();
	void RotateBlock();
	void HandleClick(Point^ p);
	bool CheckOverlap();

	void GameCycle();
	bool CheckFullGrid();
	void Draw();
	void DrawGridCells();
	void DrawNextCells();
	void DrawButton();
	void DrawBlocks();

	bool CheckBlockStopped();
	void AddBlockToPile();
	void SetRowInactive(int row);
	void HandleRowRemoval();
	void MoveRowsDown(int row);
	void AddPoints(int rowsCleared);
	void PlaceNextOnGrid();	
	void PickNextBlock();
	void HandleLevelSwitch(int preScore);
};
