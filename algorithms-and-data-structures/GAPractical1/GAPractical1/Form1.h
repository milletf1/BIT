#pragma once
#include "ZeroOneGene.h"
#include "Chromosome.h"

namespace GAPractical1 {

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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ListBox^  chromosomeDisplay;

	private: System::Windows::Forms::Button^  btnRun;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  generationDisplay;

				Random^ rand;
				static  String^  targetString = "0101010101010101";	
				Thread^ generationThread;
				delegate void invokeComponent();			// delegates used for cross threading.
				delegate void invokeWithString(String^ s);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->chromosomeDisplay = (gcnew System::Windows::Forms::ListBox());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->generationDisplay = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// chromosomeDisplay
			// 
			this->chromosomeDisplay->FormattingEnabled = true;
			this->chromosomeDisplay->Location = System::Drawing::Point(12, 12);
			this->chromosomeDisplay->Name = L"chromosomeDisplay";
			this->chromosomeDisplay->Size = System::Drawing::Size(216, 472);
			this->chromosomeDisplay->TabIndex = 0;
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(12, 535);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(75, 23);
			this->btnRun->TabIndex = 1;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 491);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Current Generation: ";
			// 
			// generationDisplay
			// 
			this->generationDisplay->AutoSize = true;
			this->generationDisplay->Location = System::Drawing::Point(122, 491);
			this->generationDisplay->Name = L"generationDisplay";
			this->generationDisplay->Size = System::Drawing::Size(13, 13);
			this->generationDisplay->TabIndex = 3;
			this->generationDisplay->Text = L"0";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(237, 570);
			this->Controls->Add(this->generationDisplay);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnRun);
			this->Controls->Add(this->chromosomeDisplay);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// form load handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				rand = gcnew Random();
				
			 }
		// run button click handler.
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) {
				 ThreadStart^ tStart = gcnew ThreadStart(this, &Form1::runGeneration);
				 generationThread = gcnew Thread(tStart);
				 generationThread->Start();				
			 }

		// clears the chromosome display listbox.
	private: void clearDisplay() { chromosomeDisplay->Items->Clear(); }
	
		// displays a chromosome in the listbox.
	private: void displayChroms(String^ value) {chromosomeDisplay->Items->Add(value); }
		// displays the current generation.
	private: void displayGeneration(String^ value) { generationDisplay->Text = value; }
		// refreshes the chromosome display.
	private: void refreshChromDisplay(){ chromosomeDisplay->Refresh(); }
		// refreshes the generation display.
	private: void refreshGenerationDisplay(){ generationDisplay->Refresh(); }

		// executes gene generation code, displays gene status, and determines when to stop 
		// evolving gene.
	private: void runGeneration() {
				invokeComponent^ inv;
				invokeWithString^ invS;

				ZeroOneGene^ myGene = gcnew ZeroOneGene(rand);
				 
				 array<Chromosome^>^ chroms;
				 bool isComplete = false;

				 while(!isComplete)
				 {
					chroms = myGene->getChoromosomes();
										
					inv = gcnew invokeComponent(this, &Form1::clearDisplay);
					chromosomeDisplay->Invoke(inv);
				
					// display chromosomes.
					for(int i = 0; i <chroms->Length; i++)
					{
						// display current chromosome.
						invS = gcnew invokeWithString(this, &Form1::displayChroms);
						chromosomeDisplay->Invoke(invS, chroms[i]->getValue());

						// check if the target chromosome has been generated.
						if(chroms[i]->getValue()->CompareTo(targetString) == 0)
							isComplete = true;
					}			
					
					// display current generation.
					invS = gcnew invokeWithString(this, &Form1::displayGeneration);
					generationDisplay->Invoke(invS, Convert::ToString(myGene->getCurrentGeneration()));					

					// refresh chromosome display.
					inv = gcnew invokeComponent(this, &Form1::refreshChromDisplay);
					chromosomeDisplay->Invoke(inv);

					// refresh generation display.
				    inv = gcnew invokeComponent(this, &Form1::refreshGenerationDisplay);
					generationDisplay->Invoke(inv);

					Thread::Sleep(500);

					// create the next generation if the target chromosme hasn't been found.
					if(!isComplete)						 
						myGene->nextGeneration();
				 }
			}
			 // Form closed handler
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				
				 // kill generation thread if it is running.
				 if(generationThread != nullptr && generationThread->IsAlive)			
					generationThread->Abort();
			 }
};
}

