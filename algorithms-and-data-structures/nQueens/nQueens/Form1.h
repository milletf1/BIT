#pragma once
#include "NQueenWorker.h"

namespace nQueens {

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
	private: System::Windows::Forms::RichTextBox^  displayOutput;
	protected: 

	private: System::Windows::Forms::Button^  btnNQueens;
	private: System::Windows::Forms::NumericUpDown^  nSelector;
	protected: 



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Thread^ t1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->displayOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->btnNQueens = (gcnew System::Windows::Forms::Button());
			this->nSelector = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nSelector))->BeginInit();
			this->SuspendLayout();
			// 
			// displayOutput
			// 
			this->displayOutput->Location = System::Drawing::Point(13, 13);
			this->displayOutput->Name = L"displayOutput";
			this->displayOutput->Size = System::Drawing::Size(306, 301);
			this->displayOutput->TabIndex = 0;
			this->displayOutput->Text = L"";
			// 
			// btnNQueens
			// 
			this->btnNQueens->Location = System::Drawing::Point(342, 13);
			this->btnNQueens->Name = L"btnNQueens";
			this->btnNQueens->Size = System::Drawing::Size(90, 23);
			this->btnNQueens->TabIndex = 1;
			this->btnNQueens->Text = L"get nQueens";
			this->btnNQueens->UseVisualStyleBackColor = true;
			this->btnNQueens->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// nSelector
			// 
			this->nSelector->Location = System::Drawing::Point(342, 53);
			this->nSelector->Name = L"nSelector";
			this->nSelector->Size = System::Drawing::Size(90, 20);
			this->nSelector->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(439, 325);
			this->Controls->Add(this->nSelector);
			this->Controls->Add(this->btnNQueens);
			this->Controls->Add(this->displayOutput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nSelector))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Calculate nQueens button click handler.
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 NQueenWorker^ worker = gcnew NQueenWorker(displayOutput);
				 int n = (int)nSelector->Value;
				 t1 = gcnew Thread(gcnew ParameterizedThreadStart(worker, &NQueenWorker::solveNQueens));
				 t1->Start(n);
			 }

		// Form closing handler.
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 
				 if(t1 != nullptr && t1->IsAlive)
					 t1->Abort();
			 }
	};
}

