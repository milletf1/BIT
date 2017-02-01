#pragma once
#include "BinaryTree.h"

#define START_DRAW_Y 20
#define X_OFFSET 60

namespace SimpleBinaryTreeQuestion1 {

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
	private: System::Windows::Forms::TextBox^  tbOutput;
	protected: 

	private: System::Windows::Forms::Button^  btnPreorder;
	private: System::Windows::Forms::Button^  btnPostorder;
	private: System::Windows::Forms::Button^  btnInorder;
	private: System::Windows::Forms::Button^  btnDraw;
	private: System::Windows::Forms::Panel^  canvas;
	private: System::Windows::Forms::TextBox^  tbInput;

	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: BinaryTree^ bt;
	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnGenerate;
	private: Graphics^ g;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbUnorderedOutput;
	private: System::Windows::Forms::Button^  btnGenerateSearch;

	private: Random^ r;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbOutput = (gcnew System::Windows::Forms::TextBox());
			this->btnPreorder = (gcnew System::Windows::Forms::Button());
			this->btnPostorder = (gcnew System::Windows::Forms::Button());
			this->btnInorder = (gcnew System::Windows::Forms::Button());
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->tbInput = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbUnorderedOutput = (gcnew System::Windows::Forms::TextBox());
			this->btnGenerateSearch = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tbOutput
			// 
			this->tbOutput->Location = System::Drawing::Point(11, 28);
			this->tbOutput->Name = L"tbOutput";
			this->tbOutput->Size = System::Drawing::Size(481, 20);
			this->tbOutput->TabIndex = 0;
			// 
			// btnPreorder
			// 
			this->btnPreorder->Location = System::Drawing::Point(11, 116);
			this->btnPreorder->Name = L"btnPreorder";
			this->btnPreorder->Size = System::Drawing::Size(75, 23);
			this->btnPreorder->TabIndex = 1;
			this->btnPreorder->Text = L"Preorder";
			this->btnPreorder->UseVisualStyleBackColor = true;
			this->btnPreorder->Click += gcnew System::EventHandler(this, &Form1::btnPreorder_Click);
			// 
			// btnPostorder
			// 
			this->btnPostorder->Location = System::Drawing::Point(92, 116);
			this->btnPostorder->Name = L"btnPostorder";
			this->btnPostorder->Size = System::Drawing::Size(75, 23);
			this->btnPostorder->TabIndex = 2;
			this->btnPostorder->Text = L"Postorder";
			this->btnPostorder->UseVisualStyleBackColor = true;
			this->btnPostorder->Click += gcnew System::EventHandler(this, &Form1::btnPostorder_Click);
			// 
			// btnInorder
			// 
			this->btnInorder->Location = System::Drawing::Point(12, 148);
			this->btnInorder->Name = L"btnInorder";
			this->btnInorder->Size = System::Drawing::Size(75, 23);
			this->btnInorder->TabIndex = 3;
			this->btnInorder->Text = L"Inorder";
			this->btnInorder->UseVisualStyleBackColor = true;
			this->btnInorder->Click += gcnew System::EventHandler(this, &Form1::btnInorder_Click);
			// 
			// btnDraw
			// 
			this->btnDraw->Location = System::Drawing::Point(93, 148);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(75, 23);
			this->btnDraw->TabIndex = 4;
			this->btnDraw->Text = L"Draw";
			this->btnDraw->UseVisualStyleBackColor = true;
			this->btnDraw->Click += gcnew System::EventHandler(this, &Form1::btnDraw_Click);
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(12, 177);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(480, 459);
			this->canvas->TabIndex = 5;
			// 
			// tbInput
			// 
			this->tbInput->Location = System::Drawing::Point(380, 148);
			this->tbInput->Name = L"tbInput";
			this->tbInput->Size = System::Drawing::Size(112, 20);
			this->tbInput->TabIndex = 6;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(174, 116);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 7;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &Form1::btnSearch_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(255, 148);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAdd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Traverse:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(377, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Search/Add:";
			// 
			// btnGenerate
			// 
			this->btnGenerate->Location = System::Drawing::Point(174, 148);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(75, 23);
			this->btnGenerate->TabIndex = 11;
			this->btnGenerate->Text = L"Generate";
			this->btnGenerate->UseVisualStyleBackColor = true;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &Form1::btnGenerate_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Unordered:";
			// 
			// tbUnorderedOutput
			// 
			this->tbUnorderedOutput->Location = System::Drawing::Point(11, 70);
			this->tbUnorderedOutput->Name = L"tbUnorderedOutput";
			this->tbUnorderedOutput->Size = System::Drawing::Size(481, 20);
			this->tbUnorderedOutput->TabIndex = 12;
			// 
			// btnGenerateSearch
			// 
			this->btnGenerateSearch->Location = System::Drawing::Point(255, 116);
			this->btnGenerateSearch->Name = L"btnGenerateSearch";
			this->btnGenerateSearch->Size = System::Drawing::Size(105, 23);
			this->btnGenerateSearch->TabIndex = 14;
			this->btnGenerateSearch->Text = L"Generate Search";
			this->btnGenerateSearch->UseVisualStyleBackColor = true;
			this->btnGenerateSearch->Click += gcnew System::EventHandler(this, &Form1::btnGenerateSearch_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 710);
			this->Controls->Add(this->btnGenerateSearch);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbUnorderedOutput);
			this->Controls->Add(this->btnGenerate);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbInput);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->btnDraw);
			this->Controls->Add(this->btnInorder);
			this->Controls->Add(this->btnPostorder);
			this->Controls->Add(this->btnPreorder);
			this->Controls->Add(this->tbOutput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
			//Preorder button click handler.
	private: System::Void btnPreorder_Click(System::Object^  sender, System::EventArgs^  e) {

				String^ s = "";
				bt->preorderTraverse(bt->rootNode, s);
				
				tbOutput->Clear();
				tbOutput->Text = s;
			 }
			 //Postorder button click handler.
	private: System::Void btnPostorder_Click(System::Object^  sender, System::EventArgs^  e) {
			 
				String^ s = "";
				bt->postorderTraverse(bt->rootNode, s);
				
				tbOutput->Clear();
				tbOutput->Text = s;
			 }
			//Inorder button click handler.
	private: System::Void btnInorder_Click(System::Object^  sender, System::EventArgs^  e) {

				String^ s = "";
				bt->inorderTraverse(bt->rootNode, s);
				
				tbOutput->Clear();
				tbOutput->Text = s;
		 }
		// Draw button click handler.
private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e) {
			  				
				Graphics^ g = canvas->CreateGraphics();
			 
				g->Clear(this->BackColor);
				
				bt->drawTree(bt->getRootNode(), canvas->Width / 2, START_DRAW_Y, X_OFFSET, g);
		 }
		 // Form Load handler
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 bt = gcnew BinaryTree();
			 g = canvas->CreateGraphics();
			 r = gcnew Random();
		 }
		 // Search button handler.
private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n = Convert::ToInt16(tbInput->Text);
			 bool result = bt->find(n);

			 tbOutput->Clear();
			 tbOutput->Text = Convert::ToString(result);
		 }
		 // Add button handler.
private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n = Convert::ToInt16(tbInput->Text);
			 bt->add(n);
		 }

		 // Generate button handler.
private: System::Void btnGenerate_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ s = "";

			bt->buildRandomTree(r, s);
			tbUnorderedOutput->Clear();
			tbUnorderedOutput->Text = s;
			s = "";
			bt->inorderTraverse(bt->rootNode, s);

			tbOutput->Clear();
			tbOutput->Text = s;
		 }
		// Generate Search button click handler (writes 1000 searches to searchResult.csv).
private: System::Void btnGenerateSearch_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			String^ s = "";
			String^ iterations = "";

			// Create a sample of searches.
			for(int i = 0; i < 1000; i++)
			{
				// Build a new tree.
				bt->buildRandomTree(r, s);

				// Convert the items stored in the new tree to a string array.
				array<String^>^ contents = s->Split(',');				
				int randSelector = r->Next(32);

				// Chose a random Integer from the string array to search for.
				int searchItem = Convert::ToInt16(contents[randSelector]);
				
				// Count how many nodes need to be searched to find the search item.
				int inspectionCount = bt->findNodeCount(searchItem);
			
				// Add results of the search to the output string.
				iterations += Convert::ToString(inspectionCount) + "\r\n";	
			}
			
			StreamWriter^ sw = gcnew StreamWriter("searchResults.csv");
			sw->WriteLine(iterations);
			sw->Close();
		 }
};
}

