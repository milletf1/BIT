#pragma once
#include "Gene.h"
#include "Chromosome.h"


namespace GeneticAlgorithm {

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
	private: System::Windows::Forms::ListBox^  chromosomeDisplay;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  generationDisplay;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Gene^ myGene;
	private: System::Windows::Forms::Button^  btnRun;

			 Random^ rand;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->chromosomeDisplay = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->generationDisplay = (gcnew System::Windows::Forms::Label());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// chromosomeDisplay
			// 
			this->chromosomeDisplay->FormattingEnabled = true;
			this->chromosomeDisplay->Location = System::Drawing::Point(13, 13);
			this->chromosomeDisplay->Name = L"chromosomeDisplay";
			this->chromosomeDisplay->Size = System::Drawing::Size(163, 420);
			this->chromosomeDisplay->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 440);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Generation:";
			// 
			// generationDisplay
			// 
			this->generationDisplay->AutoSize = true;
			this->generationDisplay->Location = System::Drawing::Point(82, 439);
			this->generationDisplay->Name = L"generationDisplay";
			this->generationDisplay->Size = System::Drawing::Size(13, 13);
			this->generationDisplay->TabIndex = 2;
			this->generationDisplay->Text = L"0";
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(13, 484);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(75, 23);
			this->btnRun->TabIndex = 3;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(197, 521);
			this->Controls->Add(this->btnRun);
			this->Controls->Add(this->generationDisplay);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chromosomeDisplay);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Form load handler
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 rand = gcnew Random();
			 }
		 // Run button click handler.
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) {				
				 
				 
				 String^  targetString = "0123456789";	// target chromosome.
				 myGene = gcnew Gene(rand, 20);
				 array<Chromosome^>^ chroms;
				 bool isComplete = false;

				 while(!isComplete)
				 {
					chroms = myGene->getChoromosomes();

					chromosomeDisplay->Items->Clear();
					generationDisplay->Text = Convert::ToString(myGene->getCurrentGeneration());
				
					for(int i = 0; i <chroms->Length; i++)
					{
						chromosomeDisplay->Items->Add(chroms[i]->getValue());
						
						if(chroms[i]->getValue()->CompareTo(targetString) == 0)
							isComplete = true;
					}			
					 
					chromosomeDisplay->Refresh();
					generationDisplay->Refresh();
					Thread::Sleep(500);

					if(!isComplete)						 
						myGene->nextGeneration();
				 }
			 }
};
}

