#pragma once
#include "IntLinkedList.h"

namespace Assignment3Problem3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Button^  btnSort;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ListBox^  unsortedDisplay;
	private: System::Windows::Forms::ListBox^  sortedDisplay;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numPicker;

	private: System::Windows::Forms::Label^  label3;

		Random^ rand;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->unsortedDisplay = (gcnew System::Windows::Forms::ListBox());
			this->sortedDisplay = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numPicker = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numPicker))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(284, 78);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(75, 23);
			this->btnSort->TabIndex = 0;
			this->btnSort->Text = L"Run";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &Form1::btnSort_Click);
			// 
			// unsortedDisplay
			// 
			this->unsortedDisplay->FormattingEnabled = true;
			this->unsortedDisplay->Location = System::Drawing::Point(13, 36);
			this->unsortedDisplay->Name = L"unsortedDisplay";
			this->unsortedDisplay->Size = System::Drawing::Size(120, 225);
			this->unsortedDisplay->TabIndex = 1;
			// 
			// sortedDisplay
			// 
			this->sortedDisplay->FormattingEnabled = true;
			this->sortedDisplay->Location = System::Drawing::Point(158, 36);
			this->sortedDisplay->Name = L"sortedDisplay";
			this->sortedDisplay->Size = System::Drawing::Size(120, 225);
			this->sortedDisplay->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Unsorted";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(154, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Sorted";
			// 
			// numPicker
			// 
			this->numPicker->Location = System::Drawing::Point(284, 52);
			this->numPicker->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {512, 0, 0, 0});
			this->numPicker->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numPicker->Name = L"numPicker";
			this->numPicker->Size = System::Drawing::Size(75, 20);
			this->numPicker->TabIndex = 5;
			this->numPicker->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(285, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"integers";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(374, 262);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numPicker);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sortedDisplay);
			this->Controls->Add(this->unsortedDisplay);
			this->Controls->Add(this->btnSort);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numPicker))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Sort button click handler.
	private: System::Void btnSort_Click(System::Object^  sender, System::EventArgs^  e) {
				
				// Clear list displays.
				unsortedDisplay->Items->Clear();
				sortedDisplay->Items->Clear();

				// Create a new linked list.
				IntLinkedList^ ll = gcnew IntLinkedList();

				// Get the total number of integers to place in the list.
				int totalNumbers = (int)numPicker->Value;

				// Generate and place random numbers in the list.
				for(int i = 0; i < totalNumbers; i++)
				{
					int randomNumber = rand->Next(1000);
					ll->push(randomNumber);
				}
				ll->getTail();
				// Get an array of unsorted numbers from the list.
				array<int>^ unsorted = ll->getList();

				// Sort the list.
				ll->sort();

				// Get an array of sorted numbers from the list.
				array<int>^ sorted = ll->getList();

				// Display both the sorted and unsorted list.
				for(int i = 0; i < totalNumbers; i++)
				{
					unsortedDisplay->Items->Add(unsorted[i]);
					sortedDisplay->Items->Add(sorted[i]);
				}
			 }

		// Form load handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 
				rand = gcnew Random();
			 }
	};
}

