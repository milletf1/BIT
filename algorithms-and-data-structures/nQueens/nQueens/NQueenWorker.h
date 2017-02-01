#pragma once

using namespace System;
using namespace System::Windows::Forms;

ref class NQueenWorker
{
private:
	delegate void invokeTextBox(array<int>^ queens);
	delegate void clearTextBox();
	RichTextBox^ displayOuput;

	void findSolutions(array<int>^ queens, int nextQueen);
	bool checkLegal(array<int>^ queens, int curQueen);
	void displaySolution(array<int>^ queens);
public:
	NQueenWorker(RichTextBox^ rtb);

	void solveNQueens(Object^ n);
};
