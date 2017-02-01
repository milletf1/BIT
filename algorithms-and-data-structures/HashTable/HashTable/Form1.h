#pragma once
#include "Hashtbl.h"
#include "Animal.h"

namespace HashTable {

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

	private: System::Windows::Forms::TextBox^  tbInputId;
	private: System::Windows::Forms::TextBox^  tbInputFood;


	private: System::Windows::Forms::TextBox^  tbInputAge;

	private: System::Windows::Forms::TextBox^  tbInputCage;

	private: System::Windows::Forms::TextBox^  tbInputSpecies;

	private: System::Windows::Forms::TextBox^  tbInputName;
	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::TextBox^  tbSearch;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  btnInsert;
	private: System::Windows::Forms::Label^  label7;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		HashTbl^ hashTbl;
	private: System::Windows::Forms::RichTextBox^  probeOutput;
	private: System::Windows::Forms::Label^  label8;


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
			this->tbInputId = (gcnew System::Windows::Forms::TextBox());
			this->tbInputFood = (gcnew System::Windows::Forms::TextBox());
			this->tbInputAge = (gcnew System::Windows::Forms::TextBox());
			this->tbInputCage = (gcnew System::Windows::Forms::TextBox());
			this->tbInputSpecies = (gcnew System::Windows::Forms::TextBox());
			this->tbInputName = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->tbSearch = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnInsert = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->probeOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// dbOutput
			// 
			this->dbOutput->Location = System::Drawing::Point(12, 12);
			this->dbOutput->Name = L"dbOutput";
			this->dbOutput->Size = System::Drawing::Size(521, 465);
			this->dbOutput->TabIndex = 0;
			this->dbOutput->Text = L"";
			// 
			// animalOutput
			// 
			this->animalOutput->Location = System::Drawing::Point(539, 54);
			this->animalOutput->Name = L"animalOutput";
			this->animalOutput->Size = System::Drawing::Size(186, 179);
			this->animalOutput->TabIndex = 1;
			this->animalOutput->Text = L"";
			// 
			// tbInputId
			// 
			this->tbInputId->Location = System::Drawing::Point(807, 54);
			this->tbInputId->Name = L"tbInputId";
			this->tbInputId->Size = System::Drawing::Size(100, 20);
			this->tbInputId->TabIndex = 2;
			// 
			// tbInputFood
			// 
			this->tbInputFood->Location = System::Drawing::Point(807, 184);
			this->tbInputFood->Name = L"tbInputFood";
			this->tbInputFood->Size = System::Drawing::Size(100, 20);
			this->tbInputFood->TabIndex = 3;
			// 
			// tbInputAge
			// 
			this->tbInputAge->Location = System::Drawing::Point(807, 158);
			this->tbInputAge->Name = L"tbInputAge";
			this->tbInputAge->Size = System::Drawing::Size(100, 20);
			this->tbInputAge->TabIndex = 4;
			// 
			// tbInputCage
			// 
			this->tbInputCage->Location = System::Drawing::Point(807, 132);
			this->tbInputCage->Name = L"tbInputCage";
			this->tbInputCage->Size = System::Drawing::Size(100, 20);
			this->tbInputCage->TabIndex = 5;
			// 
			// tbInputSpecies
			// 
			this->tbInputSpecies->Location = System::Drawing::Point(807, 106);
			this->tbInputSpecies->Name = L"tbInputSpecies";
			this->tbInputSpecies->Size = System::Drawing::Size(100, 20);
			this->tbInputSpecies->TabIndex = 6;
			// 
			// tbInputName
			// 
			this->tbInputName->Location = System::Drawing::Point(807, 80);
			this->tbInputName->Name = L"tbInputName";
			this->tbInputName->Size = System::Drawing::Size(100, 20);
			this->tbInputName->TabIndex = 7;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(650, 25);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 8;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &Form1::btnSearch_Click);
			// 
			// tbSearch
			// 
			this->tbSearch->Location = System::Drawing::Point(539, 27);
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Size = System::Drawing::Size(105, 20);
			this->tbSearch->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(732, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"ID:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(732, 187);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Food:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(732, 161);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Age:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(732, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Cage Number:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(732, 109);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Species:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(732, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Name:";
			// 
			// btnInsert
			// 
			this->btnInsert->Location = System::Drawing::Point(807, 210);
			this->btnInsert->Name = L"btnInsert";
			this->btnInsert->Size = System::Drawing::Size(100, 23);
			this->btnInsert->TabIndex = 16;
			this->btnInsert->Text = L"Insert";
			this->btnInsert->UseVisualStyleBackColor = true;
			this->btnInsert->Click += gcnew System::EventHandler(this, &Form1::btnInsert_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(539, 11);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"ID:";
			// 
			// probeOutput
			// 
			this->probeOutput->Location = System::Drawing::Point(542, 280);
			this->probeOutput->Name = L"probeOutput";
			this->probeOutput->Size = System::Drawing::Size(365, 197);
			this->probeOutput->TabIndex = 18;
			this->probeOutput->Text = L"";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(539, 264);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(90, 13);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Probe Sequence:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 489);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->probeOutput);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btnInsert);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbSearch);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbInputName);
			this->Controls->Add(this->tbInputSpecies);
			this->Controls->Add(this->tbInputCage);
			this->Controls->Add(this->tbInputAge);
			this->Controls->Add(this->tbInputFood);
			this->Controls->Add(this->tbInputId);
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
				 hashTbl = gcnew HashTbl(dbOutput, animalOutput);
			 }
			 // Search button click handler.
	private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e) {
				 try {
					
					 int key = Convert::ToInt16(tbSearch->Text);	
					Animal^ a = hashTbl->findItem(key);
					
					animalOutput->Clear();

					if(a == nullptr)
						animalOutput->Text = "Animal not found.";
					else
					{
						animalOutput->Text = "ID:         \t\t" + Convert::ToString(a->ID)
									+ "\nName:       \t" + a->Name 
									+ "\nSpecies:    \t" + a->Species
									+ "\nCage Number:\t" + Convert::ToString(a->CageNumber)
									+ "\nAge:        \t\t" + Convert::ToString(a->Age)
									+ "\nFood:       \t" + a->Food;
					}
					probeOutput->Clear();
					probeOutput->Text = hashTbl->getProbeSequence();
				 } 
				 catch(InvalidCastException^ e){}

			 }
			 //Insert animal button click handler.
private: System::Void btnInsert_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 try {
				 Animal^ a = gcnew Animal();

				 if(! String::IsNullOrEmpty( tbInputName->Text ) )
					 a->Name = tbInputName->Text;

				 if(! String::IsNullOrEmpty( tbInputSpecies->Text ) )
					 a->Species = tbInputSpecies->Text;

				 if(! String::IsNullOrEmpty( tbInputCage->Text ) )
					 a->CageNumber = Convert::ToInt16( tbInputCage->Text );

				 if(! String::IsNullOrEmpty( tbInputAge->Text ) )
					 a->Age = Convert::ToInt16( tbInputAge->Text );

				 if(! String::IsNullOrEmpty( tbInputFood->Text ) )
					 a->Food = tbInputFood->Text;
				
				 
				 if(! String::IsNullOrEmpty( tbInputId->Text ) )
				 {
					 a->ID = Convert::ToInt16( tbInputId->Text );
					 hashTbl->insertItem(a);
					 hashTbl->displayTable();
				 }
			 } catch(InvalidCastException^ e){}
		 }
};
}

