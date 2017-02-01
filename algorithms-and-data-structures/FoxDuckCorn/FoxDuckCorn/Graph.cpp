#include "StdAfx.h"
#include "Graph.h"

Graph::Graph(ListBox^ left, ListBox^ right)
{
	leftSide = left;
	rightSide = right;

	nodeArray = gcnew array<StateNode^>(ARRAY_LENGTH);
	adjacencyMatrix = gcnew array<bool, 2>(ARRAY_LENGTH, ARRAY_LENGTH);
	buildNodeArray("");
	buildAdjacencyMatrix();	
}

/*************************************************************************************
 * Precondition:  The state string parameter must have been initialized. The nodeArray
 *				  must have been initialized.			
 *
 * Postcondition: Recursive function that builds every possible entity state.
 *				  Once an entity state has been built, it is added to the node array.
 *************************************************************************************/
void Graph::buildNodeArray(String^ state)
{
	// Check if every entity is accounted for in the state string.
	if(state->Length == 4)
	{
		// If all entities are accounted for, create a new node with the state string.
		int stateId = Convert::ToInt32(state, 2);		
		bool endCondition = determineEndCondition(stateId);
		StateNode^ newNode = gcnew StateNode(state, stateId, endCondition);

		nodeArray[stateId] = newNode;
	}
	// If not, create a state string branch for the next entities possible positions.
	else
	{
		String^ state0String = state + "0";		// entity on left side of river.
		String^ state1String = state + "1";		// entity on right side of river.

		buildNodeArray(state0String);
		buildNodeArray(state1String);
	}
}

/***********************************************************************************
 * Precondition:  The adjacency matrix must have been initialized.  The file path
 *				  must exist, hold data in the proper format, and have all the edges
 *				  between each state.
 *
 * Postcondition: builds an adjacency matrix that is used to show the edges 
 *			      between each state node in the node array.
 ***********************************************************************************/
void Graph::buildAdjacencyMatrix()
{
	// Set every edge value in the adjacency matrix to false.
	for(int x = 0; x < nodeArray->Length; x++)
	{
		for(int y = 0; y < nodeArray->Length; y++)		
			adjacencyMatrix[x, y] = false;
	}
	
	StreamReader^ sr = gcnew StreamReader(FILE_PATH);
	String^ line = sr->ReadLine();

	// Populate the adjacency matrix with the edges in the edge text file.
	while(line != nullptr)
	{
		int from = Convert::ToInt16(line->Split(':')[0]);
		int to = Convert::ToInt16(line->Split(':')[1]);

		adjacencyMatrix[from, to] = true;
		
		line = sr->ReadLine();
	}
}

/****************************************************************************
 * Precondition:  
 *
 * Postcondition: Determines if the given state number results should end the
 *				  current path search.
 ****************************************************************************/
bool Graph::determineEndCondition(int stateNumber)
{
	return (stateNumber == FINISH_STATE || 
		   stateNumber == DUCK_CORN_LEFT ||
		   stateNumber == DUCK_CORN_RIGHT ||
		   stateNumber == FOX_DUCK_LEFT ||
		   stateNumber == FOX_DUCK_RIGHT ||
		   stateNumber == ABANDONED_CORN_STATE) ? false : true;
}

/************************************************************************************
 * Precondition:  visitedArray must have been initialized.  path must be initialised,
 *				  and contain a string that contains entity states seperated by :
 *
 * Postcondition: Recursive function used to check each possible path between 
 *				  stateNodes for the purpose of finding the win condition.
 ************************************************************************************/
void Graph::findSolution(String^ path, array<bool>^ visitedArray)
{	
	array<String^>^ pathway = path->Split(':');
	int lastStateIndex = Convert::ToInt32(pathway[pathway->Length - 2], 2);

	// Check if the last state is the win condition (everything on right side of river.
	if(lastStateIndex == FINISH_STATE)	
		// If it is, display the pathing used to reach this state to the user.
		displayAnimation(path);

	// Otherwise, continue if the last state hasn't resulted in a lose condition.
	else if(determineEndCondition(lastStateIndex))
	{	
		for(int i = 0; i < nodeArray->Length; i++)
		{
			// Check if there is an unvisited edge between the last state and all other states.
			if(adjacencyMatrix[lastStateIndex, i] && !visitedArray[i])
			{
				// If there is an unvisited edge, add the new state to the path and call this function.
				// with the new path string.
				String^ newPath = path + nodeArray[i]->getState() + ":";
				array<bool>^ newVisitedArray = visitedArray;
				newVisitedArray[i] = true;
				findSolution(newPath, newVisitedArray);
			}
		}
	}
}

/*****************************************************************************
 * Precondition:  
 *
 * Postcondition: Public interface called by the user to solve and display the 
 *				  Fox-Duck-Corn problem.
 *****************************************************************************/
void Graph::solveProblem()
{
	String^ path = nodeArray[START_STATE]->getState() + ":";
	array<bool>^ visitedArray = gcnew array<bool>(ARRAY_LENGTH);
	visitedArray[0] = true;

	findSolution(path, visitedArray);
}

/**************************************************************************************************
 * Precondition:  The path must be initialised, and contain a string that contains entity states 
 *				  seperated by a colon.  The leftSide and rightSide listboxes must be seperate
 *				  components.
 *
 * Postcondition: displays the transition between states needed to solve the Fox-Duck-Corn problem.
 **************************************************************************************************/
void Graph::displayAnimation(String^ path)
{
	array<String^>^ pathway = path->Split(':');

	// Iterate through each state in the given path string, display to the user.
	for(int i = 0; i < pathway->Length - 1; i++)
	{
		// Clear left and right listboxes.
		leftSide->Items->Clear();
		rightSide->Items->Clear();		

		// Display the farmer.
		if(pathway[i][FARMER_INDEX] == '0')
			leftSide->Items->Add(FARMER);
		else
			rightSide->Items->Add(FARMER);

		// Display the fox.
		if(pathway[i][FOX_INDEX] == '0')
			leftSide->Items->Add(FOX);
		else
			rightSide->Items->Add(FOX);

		// Display the duck.
		if(pathway[i][DUCK_INDEX] == '0')
			leftSide->Items->Add(DUCK);
		else
			rightSide->Items->Add(DUCK);

		// Display the corn.
		if(pathway[i][CORN_INDEX] == '0')
			leftSide->Items->Add(CORN);
		else
			rightSide->Items->Add(CORN);

		leftSide->Refresh();
		rightSide->Refresh();

		Thread::Sleep(750);
	}
}