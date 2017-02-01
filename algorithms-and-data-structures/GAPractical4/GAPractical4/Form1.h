#pragma once
#include "QueenGene.h"
#include "Chromosome.h"

#define POPULATION_SIZE 20

namespace GAPractical4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnRun;
	private: System::Windows::Forms::ListBox^  displayOutput;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		
		static String^ ROW = "row: ";
		static String^ COL = "\tcolumn: ";
		static String^ IN_PROGRESS = "Evolving chromosomes please wait...";
		static String^ GENERATION_TITLE = "Generation: ";
		Random^ r;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->displayOutput = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(591, 12);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(75, 23);
			this->btnRun->TabIndex = 0;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// displayOutput
			// 
			this->displayOutput->FormattingEnabled = true;
			this->displayOutput->Location = System::Drawing::Point(13, 12);
			this->displayOutput->Name = L"displayOutput";
			this->displayOutput->Size = System::Drawing::Size(252, 745);
			this->displayOutput->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 764);
			this->Controls->Add(this->displayOutput);
			this->Controls->Add(this->btnRun);
			this->Name = L"Form1";
			this->Text = L"N Queens";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}

#pragma endregion
		// Run Button Click Handler.
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				// display a message to let the user know it is running.
				displayOutput->Items->Clear();
				displayOutput->Items->Add(IN_PROGRESS);
				displayOutput->Items->Add("");
				displayOutput->Refresh();

				// initialize a new gene.
				QueenGene^ gene = gcnew QueenGene(r, POPULATION_SIZE);
				 
				// find solution to nQueens problem (this doesn't resolve with 8 queens, stops after 10000 generations).
				gene->solveProblem();

				array<Chromosome^>^ chroms = gene->getChoromosomes();
					
				// display generation.
				displayOutput->Items->Add(GENERATION_TITLE + Convert::ToString(gene->getCurrentGeneration()));
				displayOutput->Items->Add("");

				// display each chromosome in the gene.
				for each(Chromosome^ c in chroms)
				{
					array<String^>^ chromParts = c->getValue()->Split(':');
				
					for(int i = 0; i < chromParts->Length; i++)
					{
						int row = i + 1;
						displayOutput->Items->Add(ROW + Convert::ToString(row) + COL + chromParts[i]);
					}					
					displayOutput->Items->Add("");
				}			
			 }
			 // form load handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			
				r = gcnew Random();
			 }
};
}

