#pragma once
#include "Chromosome.h"
#include "SumGene.h"

#define TARGET_NUMBER 42
#define POPULATION_SIZE 4

namespace GAPractical3 {

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  generationDisplay;
	private: System::Windows::Forms::ListBox^  chromosomeDisplay;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

		Random^ r;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->generationDisplay = (gcnew System::Windows::Forms::Label());
			this->chromosomeDisplay = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(3, 488);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(75, 23);
			this->btnRun->TabIndex = 0;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 469);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Generation:";
			// 
			// generationDisplay
			// 
			this->generationDisplay->AutoSize = true;
			this->generationDisplay->Location = System::Drawing::Point(73, 469);
			this->generationDisplay->Name = L"generationDisplay";
			this->generationDisplay->Size = System::Drawing::Size(13, 13);
			this->generationDisplay->TabIndex = 2;
			this->generationDisplay->Text = L"0";
			// 
			// chromosomeDisplay
			// 
			this->chromosomeDisplay->FormattingEnabled = true;
			this->chromosomeDisplay->Location = System::Drawing::Point(3, 33);
			this->chromosomeDisplay->Name = L"chromosomeDisplay";
			this->chromosomeDisplay->Size = System::Drawing::Size(180, 433);
			this->chromosomeDisplay->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Numbers";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(152, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Total";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(192, 519);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->chromosomeDisplay);
			this->Controls->Add(this->generationDisplay);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnRun);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 SumGene^ sg = gcnew SumGene(r, POPULATION_SIZE, TARGET_NUMBER);
				 array<Chromosome^>^ chroms;
				 bool isComplete = false;

				 while(!isComplete)
				 {
					chroms = sg->getChoromosomes();

					chromosomeDisplay->Items->Clear();

					for each(Chromosome^ ch in chroms)
					{
						// calculate the total of the chromosome parts.
						array<String^>^ numbers = ch->getValue()->Split(':');
						int a = Convert::ToInt16(numbers[0]);
						int b = Convert::ToInt16(numbers[1]);
						int c = Convert::ToInt16(numbers[2]);
						int d = Convert::ToInt16(numbers[3]);
						int total = a + (b*2) + (c*3) + (d*4);

						// display chromosome and total of its parts.
						chromosomeDisplay->Items->Add(ch->getValue() + "\t\t\t" + total);

						// check if the total is the target number.
						if(total == TARGET_NUMBER)
							isComplete = true;
					}								
					// display current generation.			
					generationDisplay->Text = Convert::ToString(sg->getCurrentGeneration());
					
					chromosomeDisplay->Refresh();
					generationDisplay->Refresh();

					Thread::Sleep(500);

					// create the next generation if the target chromosome hasn't been found.
					if(!isComplete)						 
						sg->nextGeneration();
				 }
			
			 }// end button click handler.


		 // form load handler
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 r = gcnew Random();
			 }
};
}

