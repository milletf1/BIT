#pragma once
#include "VariableTargetGene.h"
#include "Chromosome.h"


#define POPULATION_SIZE 20

namespace GAPractical2 {

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
	private: System::Windows::Forms::TextBox^  msgInput;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  chromosomeDisplay;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  generationDisplay;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Random^ rand;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->msgInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chromosomeDisplay = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->generationDisplay = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(141, 28);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(75, 23);
			this->btnRun->TabIndex = 0;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// msgInput
			// 
			this->msgInput->Location = System::Drawing::Point(12, 30);
			this->msgInput->Name = L"msgInput";
			this->msgInput->Size = System::Drawing::Size(123, 20);
			this->msgInput->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter Message:";
			// 
			// chromosomeDisplay
			// 
			this->chromosomeDisplay->FormattingEnabled = true;
			this->chromosomeDisplay->Location = System::Drawing::Point(16, 57);
			this->chromosomeDisplay->Name = L"chromosomeDisplay";
			this->chromosomeDisplay->Size = System::Drawing::Size(200, 355);
			this->chromosomeDisplay->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 419);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Generation:";
			// 
			// generationDisplay
			// 
			this->generationDisplay->AutoSize = true;
			this->generationDisplay->Location = System::Drawing::Point(85, 419);
			this->generationDisplay->Name = L"generationDisplay";
			this->generationDisplay->Size = System::Drawing::Size(13, 13);
			this->generationDisplay->TabIndex = 5;
			this->generationDisplay->Text = L"0";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(228, 471);
			this->Controls->Add(this->generationDisplay);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->chromosomeDisplay);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->msgInput);
			this->Controls->Add(this->btnRun);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// run button click handler.
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) {
				 // run evolution progress if the user has entered a message.
				 if(msgInput->Text != String::Empty)
					runGeneration();
			 }

		// executes gene generation code, displays gene status, and determines when to stop 
		// evolving gene.
	private: void runGeneration() {				
				// get user entered message.
				String^ targetString = getMessage();

				VariableTargetGene^ myGene = gcnew VariableTargetGene(rand, targetString, POPULATION_SIZE);
				 
				 array<Chromosome^>^ chroms;
				 bool isComplete = false;

				 while(!isComplete)
				 {
					chroms = myGene->getChoromosomes();

					chromosomeDisplay->Items->Clear();

					// display chromosomes.
					for(int i = 0; i <chroms->Length; i++)
					{
						// display current chromosome.						
						chromosomeDisplay->Items->Add(chroms[i]->getValue());

						// check if the target chromosome has been generated.
						if(chroms[i]->getValue()->CompareTo(targetString) == 0)
							isComplete = true;
					}								
					// display current generation.			
					generationDisplay->Text = Convert::ToString(myGene->getCurrentGeneration());
					
					chromosomeDisplay->Refresh();
					generationDisplay->Refresh();

					Thread::Sleep(500);

					// create the next generation if the target chromosme hasn't been found.
					if(!isComplete)						 
						myGene->nextGeneration();
				 }
			}

		// formats and returns string from msgInput textbox.
	private: String^ getMessage() {
				String^ s = msgInput->Text->ToUpper();				
				String^ returnString = "";

				for each(Char c in s)
				{
					if((int)c >= (int)'A' && (int)c <= (int)'Z')
						returnString += c;
				}
				if(returnString == String::Empty)
					returnString = "demo";

				return returnString;
			 }

		// form load handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 rand = gcnew Random();
			 }
};
}

