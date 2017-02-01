#pragma once
#include "StringList.h"

namespace Assignment3Problem2 {

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
	private: System::Windows::Forms::ListBox^  listDisplay;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnAdd;

	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Button^  btnReverse;
	private: System::Windows::Forms::TextBox^  tbAdd;
	private: System::Windows::Forms::TextBox^  tbDelete;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		StringList^ myStringList;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listDisplay = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnReverse = (gcnew System::Windows::Forms::Button());
			this->tbAdd = (gcnew System::Windows::Forms::TextBox());
			this->tbDelete = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// listDisplay
			// 
			this->listDisplay->FormattingEnabled = true;
			this->listDisplay->Location = System::Drawing::Point(13, 28);
			this->listDisplay->Name = L"listDisplay";
			this->listDisplay->Size = System::Drawing::Size(120, 225);
			this->listDisplay->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"List Contents:";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(258, 39);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAd_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(258, 81);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 3;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);
			// 
			// btnReverse
			// 
			this->btnReverse->Location = System::Drawing::Point(258, 119);
			this->btnReverse->Name = L"btnReverse";
			this->btnReverse->Size = System::Drawing::Size(75, 23);
			this->btnReverse->TabIndex = 4;
			this->btnReverse->Text = L"Reverse";
			this->btnReverse->UseVisualStyleBackColor = true;
			this->btnReverse->Click += gcnew System::EventHandler(this, &Form1::btnReverse_Click);
			// 
			// tbAdd
			// 
			this->tbAdd->Location = System::Drawing::Point(140, 41);
			this->tbAdd->Name = L"tbAdd";
			this->tbAdd->Size = System::Drawing::Size(100, 20);
			this->tbAdd->TabIndex = 5;
			// 
			// tbDelete
			// 
			this->tbDelete->Location = System::Drawing::Point(140, 83);
			this->tbDelete->Name = L"tbDelete";
			this->tbDelete->Size = System::Drawing::Size(100, 20);
			this->tbDelete->TabIndex = 6;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(489, 262);
			this->Controls->Add(this->tbDelete);
			this->Controls->Add(this->tbAdd);
			this->Controls->Add(this->btnReverse);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listDisplay);
			this->Name = L"Form1";
			this->Text = L"Linked List Reverse";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Form Load handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				
				Left = 0;
				Top = 0;

				myStringList = gcnew StringList();
			 }

		// Displays the contents of the linked list in the list display.
	 private: System::Void displayList() {
				
				// Clear the list display.
				listDisplay->Items->Clear();

				// Check that the list contains values.
				if(!myStringList->isEmpty())
				{
					// Get the string values from the list.
					array<String^>^ listValues = myStringList->getList();
					
					// Display the string values from the list in the list display.
					for(int i = 0; i < listValues->Length; i++)					
						listDisplay->Items->Add(listValues[i]);
				}
			}
		// Add button click handler.
private: System::Void btnAd_Click(System::Object^  sender, System::EventArgs^  e) {
				
				String^ addValue = tbAdd->Text;
				myStringList->push(addValue);
				displayList();
			}

		// Delete button click handler.
private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) {
		
				String^ deleteValue = tbDelete->Text;
				myStringList->remove(deleteValue);
				displayList();
			}

		// Reverse button click handler.
private: System::Void btnReverse_Click(System::Object^  sender, System::EventArgs^  e) {

			 myStringList->reverse();
			 displayList();
		 }
};
}

