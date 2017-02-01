#pragma once
#include "StateNode.h"

#define FARMER_INDEX 0			// Position of entities in the state string.
#define FOX_INDEX 1
#define DUCK_INDEX 2
#define CORN_INDEX 3

#define ARRAY_LENGTH 16			// Length of array needed to store every possible entity state.

#define START_STATE 0
#define FINISH_STATE 15

#define FOX_DUCK_LEFT 9			// States where the fox and duck are left alone.	
#define FOX_DUCK_RIGHT 6

#define DUCK_CORN_LEFT 12		// States where the duck and corn are left alone.		
#define DUCK_CORN_RIGHT 3

#define ABANDONED_ALL_LEFT 8	// States where the farmer leaves everything on the other side of the river.
#define ABANDONED_ALL_RIGHT 7

//add reckless farmer 8 and 7

#define ABANDONED_CORN_STATE 1	// State where the corn is left alone on the far side of the river.

using namespace System;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Threading;

ref class Graph
{
private: 
	
	static String^ FARMER = "Farmer";
	static String^ FOX = "Fox";
	static String^ DUCK = "Duck";
	static String^ CORN = "Corn";

	static String^ FILE_PATH = "edges.txt";

	ListBox^ leftSide;
	ListBox^ rightSide;
	array<StateNode^>^ nodeArray;
	array<bool, 2>^ adjacencyMatrix;

	void buildNodeArray(String^ state);
	void buildAdjacencyMatrix();

	void findSolution(String^ path, array<bool>^ visitedArray);

	bool determineEndCondition(int stateNumber);
	void displayAnimation(String^ path);

public:
	Graph(ListBox^ left, ListBox^ right);

	void solveProblem();
};
