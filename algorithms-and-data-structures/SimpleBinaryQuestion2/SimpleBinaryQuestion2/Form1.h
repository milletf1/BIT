#pragma once
#include "BinaryTree.h"

namespace SimpleBinaryQuestion2 {

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
	private: System::Windows::Forms::Button^  btnSolve1;
	private: System::Windows::Forms::Button^  btnSolve2;
	private: System::Windows::Forms::Button^  btnDisplay1;
	private: System::Windows::Forms::Button^  btnDisplay2;
	protected: 




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbOutput;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnSolve1 = (gcnew System::Windows::Forms::Button());
			this->btnSolve2 = (gcnew System::Windows::Forms::Button());
			this->btnDisplay1 = (gcnew System::Windows::Forms::Button());
			this->btnDisplay2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbOutput = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnSolve1
			// 
			this->btnSolve1->Location = System::Drawing::Point(11, 38);
			this->btnSolve1->Name = L"btnSolve1";
			this->btnSolve1->Size = System::Drawing::Size(91, 23);
			this->btnSolve1->TabIndex = 0;
			this->btnSolve1->Text = L"Solve tree 1";
			this->btnSolve1->UseVisualStyleBackColor = true;
			this->btnSolve1->Click += gcnew System::EventHandler(this, &Form1::btnSolve1_Click);
			// 
			// btnSolve2
			// 
			this->btnSolve2->Location = System::Drawing::Point(11, 74);
			this->btnSolve2->Name = L"btnSolve2";
			this->btnSolve2->Size = System::Drawing::Size(91, 23);
			this->btnSolve2->TabIndex = 1;
			this->btnSolve2->Text = L"solve tree 2";
			this->btnSolve2->UseVisualStyleBackColor = true;
			this->btnSolve2->Click += gcnew System::EventHandler(this, &Form1::btnSolve2_Click);
			// 
			// btnDisplay1
			// 
			this->btnDisplay1->Location = System::Drawing::Point(108, 38);
			this->btnDisplay1->Name = L"btnDisplay1";
			this->btnDisplay1->Size = System::Drawing::Size(91, 23);
			this->btnDisplay1->TabIndex = 2;
			this->btnDisplay1->Text = L"display tree 1";
			this->btnDisplay1->UseVisualStyleBackColor = true;
			this->btnDisplay1->Click += gcnew System::EventHandler(this, &Form1::btnDisplay1_Click);
			// 
			// btnDisplay2
			// 
			this->btnDisplay2->Location = System::Drawing::Point(108, 74);
			this->btnDisplay2->Name = L"btnDisplay2";
			this->btnDisplay2->Size = System::Drawing::Size(91, 23);
			this->btnDisplay2->TabIndex = 3;
			this->btnDisplay2->Text = L"display tree 2";
			this->btnDisplay2->UseVisualStyleBackColor = true;
			this->btnDisplay2->Click += gcnew System::EventHandler(this, &Form1::btnDisplay2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 120);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Tree 1:  26*3+";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(116, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Tree 2:  263+*";
			// 
			// tbOutput
			// 
			this->tbOutput->Location = System::Drawing::Point(12, 12);
			this->tbOutput->Name = L"tbOutput";
			this->tbOutput->Size = System::Drawing::Size(187, 20);
			this->tbOutput->TabIndex = 6;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(208, 165);
			this->Controls->Add(this->tbOutput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnDisplay2);
			this->Controls->Add(this->btnDisplay1);
			this->Controls->Add(this->btnSolve2);
			this->Controls->Add(this->btnSolve1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		// Solves the postfix expression for tree 1.
private: System::Void btnSolve1_Click(System::Object^  sender, System::EventArgs^  e) {
			
			BinaryTree^ bt = gcnew BinaryTree();
			bt->buildTree1();
			int i = bt->parseExpressionTree(bt->getRootNode());

			tbOutput->Clear();
			tbOutput->Text = Convert::ToString(i);
		 }

		// Solves the postfix expression for tree 2.
private: System::Void btnSolve2_Click(System::Object^  sender, System::EventArgs^  e) {

			BinaryTree^ bt = gcnew BinaryTree();
			bt->buildTree2();
			int i = bt->parseExpressionTree(bt->getRootNode());

			tbOutput->Clear();
			tbOutput->Text = Convert::ToString(i);
		 }

	    // Displays the postfix expression for tree 1.
private: System::Void btnDisplay1_Click(System::Object^  sender, System::EventArgs^  e) {

			BinaryTree^ bt = gcnew BinaryTree();
			bt->buildTree1();			 
			String^ s = "";

			bt->postorderTraverse(bt->getRootNode(), s);

			tbOutput->Clear();
			tbOutput->Text = s;
		 }
	    // Displays the postfix expression for tree 2.
private: System::Void btnDisplay2_Click(System::Object^  sender, System::EventArgs^  e) {

			BinaryTree^ bt = gcnew BinaryTree();
			bt->buildTree2();			 
			String^ s = "";

			bt->postorderTraverse(bt->getRootNode(), s);

			tbOutput->Clear();
			tbOutput->Text = s;
		 }
};
}

