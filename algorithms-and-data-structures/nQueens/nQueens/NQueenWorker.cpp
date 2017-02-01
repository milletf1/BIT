#include "StdAfx.h"
#include "NQueenWorker.h"

NQueenWorker::NQueenWorker(RichTextBox^ rtb)
{
	displayOuput = rtb;
}

/*************************************************************************************
 * Precondition:  The queens array must be initialized.  Its length must be
 *				  equal to the number of queens that this function is attempting
 *				  to find a solution for.
 * 
 * Postcondition: Determines the position of the queen in the given column (nextQueen)
 *                to other queen positions in the queens array to see if they can 
 *				  attack each other.
 *************************************************************************************/
void NQueenWorker::findSolutions(array<int>^ queens, int nextQueen)
{
	// Base  case checks if we are at the last row.
	if(nextQueen == queens->Length)
	{
		// If all the queens have been placed legally, display
		// the row/column locations of each queen.
		if(checkLegal(queens, nextQueen -1))
		{
			invokeTextBox^ callback = gcnew invokeTextBox(
				this, 
				&NQueenWorker::displaySolution
			);
			displayOuput->Invoke(callback, queens);
		}
	}	
	else
	{
		// Iterate through each row (i determines the row placement).
		for(int i = 1; i <= queens->Length; i++)	
		{
			// Set the row value of the queen we are checking (nextQueen determines 
			// column placement).
			queens[nextQueen] = i;

			// Check that a prior queen has been placed.  
			if(nextQueen > 0)
			{
				// If so, check for legal positioning.
				if(checkLegal(queens, nextQueen))
					// Recall this function if the positioning of all queens is legal.
					findSolutions(queens, nextQueen +1);
			}
			else
			{
				// If not, recall this function to place a queen in the next column.
				findSolutions(queens, nextQueen +1);
			}
		}// End for loop.
	}
}

/********************************************************************************
 * Precondition:  curQueen must be at greater than 0.
 * 
 * Postcondition: Compares queens[curQueen] to the position of earlier
 *				  queens in the array to check if they can attack each other.
 *                Returns true if queens[curQueen] can't attack the other queens.
 ********************************************************************************/
bool NQueenWorker::checkLegal(array<int>^ queens, int curQueen)
{
	
	bool rValue = true;
	int nextQueen = curQueen -1;

	while(nextQueen >= 0 && rValue == true)
	{
		// Modifier used to determine if the queens are facing each other diagonally.
		int diagMod = curQueen - nextQueen;	
		
		// Check if the queens are on the same row.
		if(queens[nextQueen] == queens[curQueen])
			rValue = false;
		
		// Check if the queens can attack each other diagonally.
		else if(queens[nextQueen] == queens[curQueen] -diagMod ||
				queens[nextQueen] == queens[curQueen] +diagMod)		
			rValue = false;

		else
			nextQueen--;			
	}
	return rValue;
}

/*************************************************************
 * Precondition:  
 * 
 * Postcondition: Displays a solution for the nQueens problem.
 *************************************************************/
void NQueenWorker::displaySolution(array<int>^ queens)
{	
	String^ s = "****************\n"; 

	for(int i = 0; i < queens->Length; i++)
		s += "Row " + Convert::ToString(queens[i]) + 
			" Column " + Convert::ToString(i + 1) + "\n";

	displayOuput->Text += s;
}

/********************************************************************************
 * Precondition:  n must be an integer value that determines the number of queens
 *                to find a solution for.
 * 
 * Postcondition: Wrapper function to find solutions for nQueens.
 ********************************************************************************/
void NQueenWorker::solveNQueens(Object^ n)
{	
	array<int>^ queens = gcnew array<int>((int)n);
	
	clearTextBox^ callback = gcnew clearTextBox(
		displayOuput, 
		&RichTextBox::Clear
	);

	displayOuput->Invoke(callback);

	findSolutions(queens, 0);	
}