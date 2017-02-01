#pragma once
#include "GridDisplay.h"
#include "Chromosome.h"
#include "ColourGene.h"

#define POPULATION_SIZE 10
#define GENERATION 100000
#define CELLS 6
#define FORM_COLOR 256
#define THREAD_SLEEP 100

namespace GAPractical5 {

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
	private: System::Windows::Forms::Panel^  algorithmDisplay;
	protected: 
	private: System::Windows::Forms::Panel^  targetDisplay;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnRun;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Random^ rand;
		GridDisplay^ targetGrid;
		GridDisplay^ geneGrid;
		Thread^ t;

		array<ColourGene^, 2>^ genes;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->algorithmDisplay = (gcnew System::Windows::Forms::Panel());
			this->targetDisplay = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// algorithmDisplay
			// 
			this->algorithmDisplay->Location = System::Drawing::Point(105, 43);
			this->algorithmDisplay->Name = L"algorithmDisplay";
			this->algorithmDisplay->Size = System::Drawing::Size(480, 480);
			this->algorithmDisplay->TabIndex = 0;
			// 
			// targetDisplay
			// 
			this->targetDisplay->BackColor = System::Drawing::SystemColors::Control;
			this->targetDisplay->Location = System::Drawing::Point(624, 43);
			this->targetDisplay->Name = L"targetDisplay";
			this->targetDisplay->Size = System::Drawing::Size(480, 480);
			this->targetDisplay->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(102, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Algorithm";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(621, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Target";
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(15, 68);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(75, 23);
			this->btnRun->TabIndex = 4;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1117, 538);
			this->Controls->Add(this->btnRun);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->targetDisplay);
			this->Controls->Add(this->algorithmDisplay);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Form load Handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 rand = gcnew Random();

				 targetGrid = gcnew GridDisplay(targetDisplay);
				 geneGrid = gcnew GridDisplay(algorithmDisplay);
			 }
		 // Run button click handler.
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) {
								
				abortThread();
				initialize();

				// start a new thread.
				ThreadStart^ ts = gcnew ThreadStart(this, &Form1::run);
				t = gcnew Thread(ts);
				t->Start();
				
			 }

			 // retrieves colors from each chromosome in the genes array and displays in the gene
			 // grid.
		private: void run() {

				//repeat untill max generation has been reahed
				while(genes[0, 0]->getCurrentGeneration() < GENERATION)
				{
					// array for storing color value of the best chromosome in each gene.
					array<String^, 2>^ colorArray = gcnew array<String^, 2>(CELLS, CELLS);

					for(int row = 0; row < CELLS; row++)
					{
						for(int col = 0; col < CELLS; col++)
						{							
							// get best chromosome from the current gene.
							colorArray[row, col] = genes[row, col]->getBest()->getValue();
							
							// set current gene's next generation.
							genes[row, col]->nextGeneration();
						}
					}
					//display colors recieved from the gene array in the gene grid.
					geneGrid->createImage(colorArray);
					Thread::Sleep(THREAD_SLEEP);
				}
			}

			// Creates a random colour string.
		 private: String^ createColor(){
					  
					// choose random rgb values...
					int r = rand->Next(FORM_COLOR);
					int g = rand->Next(FORM_COLOR);
					int b = rand->Next(FORM_COLOR);
					
					// convert to string.
					String^ red = Convert::ToString(r);
					String^ green = Convert::ToString(g);
					String^ blue = Convert::ToString(b);

					// return in the chromosome format.
					return  red + ":" + green + ":" + blue;
				}

		  // checks if the thread responsible for displaying the evolution of the color gene is running.
		  // If it is, aborts it.
		  private: void abortThread() {
				// Check if the thread is running and needs to be aborted.
				if(t != nullptr && t->IsAlive)			
					t->Abort();
			}

		// Initializes the needed genes the target grid display, and the gene grid display.
		private: void initialize() {
				
					// create two random target colours.
					String^ targetColorA = createColor();
					String^ targetColorB = createColor();

					// create a color array to display the target grid.
					array<String^, 2>^ colorArray = gcnew array<String^, 2>(CELLS, CELLS);

					genes = gcnew array<ColourGene^, 2>(CELLS, CELLS);

					for(int row = 0; row < CELLS; row++)
					{
						for(int col = 0; col < CELLS; col++)
						{
							// create a gene to represent the current cell
							ColourGene^ gene;

							// set target color for the gene and the color array.
							if(row == 0 || col == 0 || row == 5 || col == 5)
							{
								gene = gcnew ColourGene(rand, POPULATION_SIZE, targetColorA);
								colorArray[row, col] = targetColorA;
							}	
							else if(row == 2 && (col == 2 || col == 3) ||
									row == 3 && (col == 2 || col == 3) )
							{
								gene = gcnew ColourGene(rand, POPULATION_SIZE, targetColorA);
								colorArray[row, col] = targetColorA;
							}
							else
							{
								gene = gcnew ColourGene(rand, POPULATION_SIZE, targetColorB);
								colorArray[row, col] = targetColorB;
							}
							// add new gene to the gene array
							genes[row, col] = gene;
						}
					}
					// display the color array in the target grid.
					targetGrid->createImage(colorArray);					 
				}

			 // Form closed handler
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 abortThread();
		 }
};
}

