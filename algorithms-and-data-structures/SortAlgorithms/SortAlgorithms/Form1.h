#pragma once
#include "SortWorker.h"
#include "Testing.h"

namespace SortAlgorithms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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
	private: System::Windows::Forms::ListBox^  sortedIntDisplay;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  rbMerge;
	private: System::Windows::Forms::RadioButton^  rbSelection;
	private: System::Windows::Forms::RadioButton^  rbInsertion;
	private: System::Windows::Forms::RadioButton^  rbBubble;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnSort;
	private: System::Windows::Forms::NumericUpDown^  numPicker;

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
			this->sortedIntDisplay = (gcnew System::Windows::Forms::ListBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->rbMerge = (gcnew System::Windows::Forms::RadioButton());
			this->rbSelection = (gcnew System::Windows::Forms::RadioButton());
			this->rbInsertion = (gcnew System::Windows::Forms::RadioButton());
			this->rbBubble = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->numPicker = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numPicker))->BeginInit();
			this->SuspendLayout();
			// 
			// sortedIntDisplay
			// 
			this->sortedIntDisplay->FormattingEnabled = true;
			this->sortedIntDisplay->Location = System::Drawing::Point(12, 7);
			this->sortedIntDisplay->Name = L"sortedIntDisplay";
			this->sortedIntDisplay->Size = System::Drawing::Size(120, 238);
			this->sortedIntDisplay->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->rbMerge);
			this->panel1->Controls->Add(this->rbSelection);
			this->panel1->Controls->Add(this->rbInsertion);
			this->panel1->Controls->Add(this->rbBubble);
			this->panel1->Location = System::Drawing::Point(138, 49);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(116, 121);
			this->panel1->TabIndex = 1;
			// 
			// rbMerge
			// 
			this->rbMerge->AutoSize = true;
			this->rbMerge->Location = System::Drawing::Point(4, 88);
			this->rbMerge->Name = L"rbMerge";
			this->rbMerge->Size = System::Drawing::Size(55, 17);
			this->rbMerge->TabIndex = 2;
			this->rbMerge->TabStop = true;
			this->rbMerge->Text = L"Merge";
			this->rbMerge->UseVisualStyleBackColor = true;
			// 
			// rbSelection
			// 
			this->rbSelection->AutoSize = true;
			this->rbSelection->Location = System::Drawing::Point(4, 65);
			this->rbSelection->Name = L"rbSelection";
			this->rbSelection->Size = System::Drawing::Size(69, 17);
			this->rbSelection->TabIndex = 2;
			this->rbSelection->Text = L"Selection";
			this->rbSelection->UseVisualStyleBackColor = true;
			// 
			// rbInsertion
			// 
			this->rbInsertion->AutoSize = true;
			this->rbInsertion->Location = System::Drawing::Point(4, 42);
			this->rbInsertion->Name = L"rbInsertion";
			this->rbInsertion->Size = System::Drawing::Size(65, 17);
			this->rbInsertion->TabIndex = 1;
			this->rbInsertion->Text = L"Insertion";
			this->rbInsertion->UseVisualStyleBackColor = true;
			// 
			// rbBubble
			// 
			this->rbBubble->AutoSize = true;
			this->rbBubble->Checked = true;
			this->rbBubble->Location = System::Drawing::Point(4, 19);
			this->rbBubble->Name = L"rbBubble";
			this->rbBubble->Size = System::Drawing::Size(58, 17);
			this->rbBubble->TabIndex = 0;
			this->rbBubble->TabStop = true;
			this->rbBubble->Text = L"Bubble";
			this->rbBubble->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(133, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Sort Method";
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(138, 222);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(116, 23);
			this->btnSort->TabIndex = 3;
			this->btnSort->Text = L"Sort";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &Form1::btnSort_Click);
			// 
			// numPicker
			// 
			this->numPicker->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numPicker->Location = System::Drawing::Point(139, 186);
			this->numPicker->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {4096, 0, 0, 0});
			this->numPicker->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numPicker->Name = L"numPicker";
			this->numPicker->Size = System::Drawing::Size(120, 20);
			this->numPicker->TabIndex = 4;
			this->numPicker->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4096, 0, 0, 0});
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 261);
			this->Controls->Add(this->numPicker);
			this->Controls->Add(this->btnSort);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->sortedIntDisplay);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numPicker))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Sort Button click handler
	private: System::Void btnSort_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 // Initialize variables.
				 int arrSize = (int)numPicker->Value;
				 array<int>^ intArray;
				 SortWorker^ sw = gcnew SortWorker(arrSize, rand);
				 
				 // Clear the sorted integer display
				 sortedIntDisplay->Items->Clear();
				 
				 //Determine the sort method used to build intArray.
				 if(rbBubble->Checked)
				 {
					 intArray = sw->bubbleSort();
				 }
				 else if(rbInsertion->Checked)
				 {
					 intArray = sw->insertionSort();
				 }
				 else if(rbSelection->Checked)
				 {
					 intArray = sw->selectionSort();
				 }
				 else if (rbMerge->Checked)
				 {
					 intArray = sw->mergeSort();
				 }
				 
				 //Display the sorted list.
				 try
				{
					for each(int i in intArray)
					{
						sortedIntDisplay->Items->Add(i);	
					}
				}
				catch(NullReferenceException^ e)
				{}
			 }
		 //Form load
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			
			rand = gcnew Random();
			
			// Test the sort algorithms' efficiency and write to a text file.
			SortWorker^ sw = gcnew SortWorker(1, rand);
			Testing^ t = gcnew Testing(sw);
			String^ testResults = t->runTest();
			
			StreamWriter^ writer = gcnew StreamWriter("test_results.csv");
			writer->Write(testResults);
			writer->Close();			 
		 }
};
}

