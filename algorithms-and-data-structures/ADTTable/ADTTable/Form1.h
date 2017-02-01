#pragma once
#include "Table.h"
#include "Animal.h"

namespace ADTTable {

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
	private: System::Windows::Forms::RichTextBox^  dbOutput;
	protected: 
	private: System::Windows::Forms::RichTextBox^  animalOutput;
	private: System::Windows::Forms::TextBox^  keyInput;
	private: System::Windows::Forms::Button^  btnAnimalSearch;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Table^ dbTable;
		static String^ animalFile = "Zoo.txt";

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dbOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->animalOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->keyInput = (gcnew System::Windows::Forms::TextBox());
			this->btnAnimalSearch = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// dbOutput
			// 
			this->dbOutput->Location = System::Drawing::Point(12, 12);
			this->dbOutput->Name = L"dbOutput";
			this->dbOutput->Size = System::Drawing::Size(631, 284);
			this->dbOutput->TabIndex = 0;
			this->dbOutput->Text = L"";
			// 
			// animalOutput
			// 
			this->animalOutput->Location = System::Drawing::Point(649, 39);
			this->animalOutput->Name = L"animalOutput";
			this->animalOutput->Size = System::Drawing::Size(204, 257);
			this->animalOutput->TabIndex = 1;
			this->animalOutput->Text = L"";
			// 
			// keyInput
			// 
			this->keyInput->Location = System::Drawing::Point(650, 12);
			this->keyInput->Name = L"keyInput";
			this->keyInput->Size = System::Drawing::Size(122, 20);
			this->keyInput->TabIndex = 2;
			// 
			// btnAnimalSearch
			// 
			this->btnAnimalSearch->Location = System::Drawing::Point(778, 10);
			this->btnAnimalSearch->Name = L"btnAnimalSearch";
			this->btnAnimalSearch->Size = System::Drawing::Size(75, 23);
			this->btnAnimalSearch->TabIndex = 3;
			this->btnAnimalSearch->Text = L"Search";
			this->btnAnimalSearch->UseVisualStyleBackColor = true;
			this->btnAnimalSearch->Click += gcnew System::EventHandler(this, &Form1::btnAnimalSearch_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(861, 302);
			this->Controls->Add(this->btnAnimalSearch);
			this->Controls->Add(this->keyInput);
			this->Controls->Add(this->animalOutput);
			this->Controls->Add(this->dbOutput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 dbTable = gcnew Table(dbOutput, animalOutput);
				 dbTable->loadFromFile(animalFile);
				 dbTable->displayTable();
			 }
	private: System::Void btnAnimalSearch_Click(System::Object^  sender, System::EventArgs^  e) {
				 int animalID = Convert::ToInt16(keyInput->Text);

				 if(dbTable->findItem(animalID))
					 dbTable->displayItem(animalID);
			 }
};
}

