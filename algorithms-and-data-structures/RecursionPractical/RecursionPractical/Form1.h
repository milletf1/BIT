#pragma once
#include "RecursionWorker.h"
#include "RecursionWorkerTest.h"

namespace RecursionPractical {

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
	private: System::Windows::Forms::TextBox^  tbInput;
	protected: 
	private: System::Windows::Forms::TextBox^  tbOutput;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnReverseIt;
	private: System::Windows::Forms::Button^  btnPalindrome;
	private: System::Windows::Forms::Button^  btnRemoveIt;


	private: System::Windows::Forms::Button^  btnSumToN;
	private: System::Windows::Forms::TextBox^  tbChar;
	private: System::Windows::Forms::Label^  label3;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  btnPowerOfThree;
	private: System::Windows::Forms::ListBox^  lbMergeSortOut;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnMergeSort;

			 
	private: System::Windows::Forms::Button^  btnBinarySearch;
			 Random^ rand;
	private: System::Windows::Forms::Button^  btnTests;
			 RecursionWorker^ myRecursionWorker;		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbInput = (gcnew System::Windows::Forms::TextBox());
			this->tbOutput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnReverseIt = (gcnew System::Windows::Forms::Button());
			this->btnPalindrome = (gcnew System::Windows::Forms::Button());
			this->btnRemoveIt = (gcnew System::Windows::Forms::Button());
			this->btnSumToN = (gcnew System::Windows::Forms::Button());
			this->tbChar = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnPowerOfThree = (gcnew System::Windows::Forms::Button());
			this->lbMergeSortOut = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnMergeSort = (gcnew System::Windows::Forms::Button());
			this->btnBinarySearch = (gcnew System::Windows::Forms::Button());
			this->btnTests = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tbInput
			// 
			this->tbInput->Location = System::Drawing::Point(12, 33);
			this->tbInput->Name = L"tbInput";
			this->tbInput->Size = System::Drawing::Size(100, 20);
			this->tbInput->TabIndex = 0;
			// 
			// tbOutput
			// 
			this->tbOutput->Location = System::Drawing::Point(12, 72);
			this->tbOutput->Name = L"tbOutput";
			this->tbOutput->Size = System::Drawing::Size(100, 20);
			this->tbOutput->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Input";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Output";
			// 
			// btnReverseIt
			// 
			this->btnReverseIt->Location = System::Drawing::Point(121, 72);
			this->btnReverseIt->Name = L"btnReverseIt";
			this->btnReverseIt->Size = System::Drawing::Size(75, 23);
			this->btnReverseIt->TabIndex = 4;
			this->btnReverseIt->Text = L"reverse it";
			this->btnReverseIt->UseVisualStyleBackColor = true;
			this->btnReverseIt->Click += gcnew System::EventHandler(this, &Form1::btnReverseIt_Click);
			// 
			// btnPalindrome
			// 
			this->btnPalindrome->Location = System::Drawing::Point(121, 130);
			this->btnPalindrome->Name = L"btnPalindrome";
			this->btnPalindrome->Size = System::Drawing::Size(75, 23);
			this->btnPalindrome->TabIndex = 5;
			this->btnPalindrome->Text = L"palindrome";
			this->btnPalindrome->UseVisualStyleBackColor = true;
			this->btnPalindrome->Click += gcnew System::EventHandler(this, &Form1::btnPalindrome_Click);
			// 
			// btnRemoveIt
			// 
			this->btnRemoveIt->Location = System::Drawing::Point(121, 159);
			this->btnRemoveIt->Name = L"btnRemoveIt";
			this->btnRemoveIt->Size = System::Drawing::Size(75, 23);
			this->btnRemoveIt->TabIndex = 6;
			this->btnRemoveIt->Text = L"removeit";
			this->btnRemoveIt->UseVisualStyleBackColor = true;
			this->btnRemoveIt->Click += gcnew System::EventHandler(this, &Form1::btnRemoveIt_Click);
			// 
			// btnSumToN
			// 
			this->btnSumToN->Location = System::Drawing::Point(121, 101);
			this->btnSumToN->Name = L"btnSumToN";
			this->btnSumToN->Size = System::Drawing::Size(75, 23);
			this->btnSumToN->TabIndex = 7;
			this->btnSumToN->Text = L"sum to n";
			this->btnSumToN->UseVisualStyleBackColor = true;
			this->btnSumToN->Click += gcnew System::EventHandler(this, &Form1::btnSumToN_Click);
			// 
			// tbChar
			// 
			this->tbChar->Location = System::Drawing::Point(143, 33);
			this->tbChar->Name = L"tbChar";
			this->tbChar->Size = System::Drawing::Size(31, 20);
			this->tbChar->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(118, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"remove it char";
			// 
			// btnPowerOfThree
			// 
			this->btnPowerOfThree->Location = System::Drawing::Point(121, 188);
			this->btnPowerOfThree->Name = L"btnPowerOfThree";
			this->btnPowerOfThree->Size = System::Drawing::Size(75, 44);
			this->btnPowerOfThree->TabIndex = 10;
			this->btnPowerOfThree->Text = L"power of three";
			this->btnPowerOfThree->UseVisualStyleBackColor = true;
			this->btnPowerOfThree->Click += gcnew System::EventHandler(this, &Form1::btnPowerOfThree_Click);
			// 
			// lbMergeSortOut
			// 
			this->lbMergeSortOut->FormattingEnabled = true;
			this->lbMergeSortOut->Location = System::Drawing::Point(15, 117);
			this->lbMergeSortOut->Name = L"lbMergeSortOut";
			this->lbMergeSortOut->Size = System::Drawing::Size(97, 264);
			this->lbMergeSortOut->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Merge Sort Output";
			// 
			// btnMergeSort
			// 
			this->btnMergeSort->Location = System::Drawing::Point(121, 238);
			this->btnMergeSort->Name = L"btnMergeSort";
			this->btnMergeSort->Size = System::Drawing::Size(75, 44);
			this->btnMergeSort->TabIndex = 13;
			this->btnMergeSort->Text = L"Merge Sort";
			this->btnMergeSort->UseVisualStyleBackColor = true;
			this->btnMergeSort->Click += gcnew System::EventHandler(this, &Form1::btnMergeSort_Click);
			// 
			// btnBinarySearch
			// 
			this->btnBinarySearch->Location = System::Drawing::Point(121, 288);
			this->btnBinarySearch->Name = L"btnBinarySearch";
			this->btnBinarySearch->Size = System::Drawing::Size(75, 44);
			this->btnBinarySearch->TabIndex = 14;
			this->btnBinarySearch->Text = L"Binary Search";
			this->btnBinarySearch->UseVisualStyleBackColor = true;
			this->btnBinarySearch->Click += gcnew System::EventHandler(this, &Form1::btnBinarySearch_Click);
			// 
			// btnTests
			// 
			this->btnTests->Location = System::Drawing::Point(121, 338);
			this->btnTests->Name = L"btnTests";
			this->btnTests->Size = System::Drawing::Size(75, 44);
			this->btnTests->TabIndex = 15;
			this->btnTests->Text = L"tests";
			this->btnTests->UseVisualStyleBackColor = true;
			this->btnTests->Click += gcnew System::EventHandler(this, &Form1::btnTests_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(214, 402);
			this->Controls->Add(this->btnTests);
			this->Controls->Add(this->btnBinarySearch);
			this->Controls->Add(this->btnMergeSort);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbMergeSortOut);
			this->Controls->Add(this->btnPowerOfThree);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbChar);
			this->Controls->Add(this->btnSumToN);
			this->Controls->Add(this->btnRemoveIt);
			this->Controls->Add(this->btnPalindrome);
			this->Controls->Add(this->btnReverseIt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbOutput);
			this->Controls->Add(this->tbInput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/*
		 * Button click handler for reverse it.
		 */
	private: System::Void btnReverseIt_Click(System::Object^  sender, System::EventArgs^  e) {
	
				 String^ s = tbInput->Text;
				 s = myRecursionWorker->reverseIt(s);
				 tbOutput->Text = s;
		}
		/*
		 *  Form load handler.
		 */
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				rand = gcnew Random();
				myRecursionWorker = gcnew RecursionWorker();
		 }
		/*
		 * Sum to n button click handler.
		 */
	private: System::Void btnSumToN_Click(System::Object^  sender, System::EventArgs^  e) {

				 int n = Convert::ToInt16(tbInput->Text);
				 int sum = myRecursionWorker->sumToN(n);
				 tbOutput->Text = Convert::ToString(sum);
		 }
		/*
		 * palindrome button click handler.
		 */
	private: System::Void btnPalindrome_Click(System::Object^  sender, System::EventArgs^  e) {

				 String^ s = tbInput->Text;
				 bool b = myRecursionWorker->palindrome(s);
				 tbOutput->Text = Convert::ToString(b);
		 }
		/*
		 * remove it button click handler.
		 */
private: System::Void btnRemoveIt_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 String^ s = tbInput->Text;
			 String^ ch = tbChar->Text;
			 s = myRecursionWorker->removeIt(ch, s);
			 tbOutput->Text = s;
		 }
		 /*
		  * power of three button click handler.	 
		  */
private: System::Void btnPowerOfThree_Click(System::Object^  sender, System::EventArgs^  e) {

				 int n = Convert::ToInt16(tbInput->Text);
				 bool isPowerOfThree = myRecursionWorker->powerOfThree(n);
				 tbOutput->Text = Convert::ToString(isPowerOfThree);
		 }
		 /*
		  * Merge sort button click handler.	 
	      */
private: System::Void btnMergeSort_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 //Initialize array.
			 array<int>^ intArray = gcnew array<int>(1024);
			 
			 //Clear sorted array output listbox.
			 lbMergeSortOut->Items->Clear();

			 //Fill array with random numbers.
			 for(int i = 0; i < intArray->Length; i++)	
				intArray[i] = rand->Next(1000);

			 //Sort array.
			 myRecursionWorker->mergeSortV2(intArray, 0, intArray->Length);

			 //Display sort result in output listbox.
			 for(int i = 0; i < intArray->Length; i++)
				 lbMergeSortOut->Items->Add(intArray[i]);
		 }
		 /*
		  * Binary search button click handler.  Searches the integers in the output listbox.
		  */
private: System::Void btnBinarySearch_Click(System::Object^  sender, System::EventArgs^  e) {
		
			array<int>^ intArray = gcnew array<int>( lbMergeSortOut->Items->Count );
			int target = Convert::ToInt16(tbInput->Text);
			int lBound = 0;
			int uBound = intArray->Length - 1;

			for(int i = 0; i < intArray->Length; i++)
				intArray[i] = (int)lbMergeSortOut->Items[i];
			
			bool isFound = myRecursionWorker->binarySearch(intArray, lBound, uBound, target);

			tbOutput->Text = Convert::ToString(isFound);
		 }
		 /*
		  * Run tests button click handler.  outputs results to debug.
		  */
private: System::Void btnTests_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			 RecursionWorkerTest^ rwt = gcnew RecursionWorkerTest();
			 String^ result = rwt->runTests();

			 System::Diagnostics::Debug::WriteLine(result);
		 }
};
}

