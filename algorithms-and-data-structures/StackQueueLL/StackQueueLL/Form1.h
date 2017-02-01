#pragma once
#include "IntStack.h"
#include "IntQueue.h"
#include "CharStack.h"
#include "CharQueue.h"
#include "Testing.h"

namespace StackQueueLL {

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

	protected: 




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		IntStack^ myIntStack;
		IntQueue^ myIntQueue;
		CharStack^ myCharStack;
		CharQueue^ myCharQueue;

		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RichTextBox^  charQueueList;
	private: System::Windows::Forms::RichTextBox^  charStackList;
	private: System::Windows::Forms::RichTextBox^  intQueueList;
	private: System::Windows::Forms::RichTextBox^  intStackList;
	private: System::Windows::Forms::TextBox^  varCharStackPush;
	private: System::Windows::Forms::NumericUpDown^  varIntStackPush;
	private: System::Windows::Forms::TextBox^  varCharStackPop;
	private: System::Windows::Forms::TextBox^  varCharStackPeek;
	private: System::Windows::Forms::TextBox^  varIntStackPeek;
	private: System::Windows::Forms::TextBox^  varIntStackPop;
	private: System::Windows::Forms::Button^  btnCharStackPush;
	private: System::Windows::Forms::Button^  btnCharStackPop;
	private: System::Windows::Forms::Button^  btnCharStackPeek;
	private: System::Windows::Forms::Button^  btnCharQueuePeek;
	private: System::Windows::Forms::Button^  btnCharQueuePop;
	private: System::Windows::Forms::Button^  btnCharQueuePush;
	private: System::Windows::Forms::TextBox^  varCharQueuePeek;
	private: System::Windows::Forms::TextBox^  varCharQueuePop;
	private: System::Windows::Forms::TextBox^  varCharQueuePush;
	private: System::Windows::Forms::Button^  btnIntStackPeek;
	private: System::Windows::Forms::Button^  btnIntStackPop;
	private: System::Windows::Forms::Button^  btnIntStackPush;
	private: System::Windows::Forms::Button^  btnIntQueuePeek;
	private: System::Windows::Forms::Button^  btnIntQueuePop;
	private: System::Windows::Forms::Button^  btnIntQueuePush;
	private: System::Windows::Forms::TextBox^  varIntQueuePeek;
	private: System::Windows::Forms::TextBox^  varIntQueuePop;
	private: System::Windows::Forms::Button^  testBtn;
	private: System::Windows::Forms::NumericUpDown^  varIntQueuePush;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->charQueueList = (gcnew System::Windows::Forms::RichTextBox());
			this->charStackList = (gcnew System::Windows::Forms::RichTextBox());
			this->intQueueList = (gcnew System::Windows::Forms::RichTextBox());
			this->intStackList = (gcnew System::Windows::Forms::RichTextBox());
			this->varCharStackPush = (gcnew System::Windows::Forms::TextBox());
			this->varIntStackPush = (gcnew System::Windows::Forms::NumericUpDown());
			this->varCharStackPop = (gcnew System::Windows::Forms::TextBox());
			this->varCharStackPeek = (gcnew System::Windows::Forms::TextBox());
			this->varIntStackPeek = (gcnew System::Windows::Forms::TextBox());
			this->varIntStackPop = (gcnew System::Windows::Forms::TextBox());
			this->btnCharStackPush = (gcnew System::Windows::Forms::Button());
			this->btnCharStackPop = (gcnew System::Windows::Forms::Button());
			this->btnCharStackPeek = (gcnew System::Windows::Forms::Button());
			this->btnCharQueuePeek = (gcnew System::Windows::Forms::Button());
			this->btnCharQueuePop = (gcnew System::Windows::Forms::Button());
			this->btnCharQueuePush = (gcnew System::Windows::Forms::Button());
			this->varCharQueuePeek = (gcnew System::Windows::Forms::TextBox());
			this->varCharQueuePop = (gcnew System::Windows::Forms::TextBox());
			this->varCharQueuePush = (gcnew System::Windows::Forms::TextBox());
			this->btnIntStackPeek = (gcnew System::Windows::Forms::Button());
			this->btnIntStackPop = (gcnew System::Windows::Forms::Button());
			this->btnIntStackPush = (gcnew System::Windows::Forms::Button());
			this->btnIntQueuePeek = (gcnew System::Windows::Forms::Button());
			this->btnIntQueuePop = (gcnew System::Windows::Forms::Button());
			this->btnIntQueuePush = (gcnew System::Windows::Forms::Button());
			this->varIntQueuePeek = (gcnew System::Windows::Forms::TextBox());
			this->varIntQueuePop = (gcnew System::Windows::Forms::TextBox());
			this->varIntQueuePush = (gcnew System::Windows::Forms::NumericUpDown());
			this->testBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varIntStackPush))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varIntQueuePush))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(42, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Char";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(314, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 55);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Int";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(7, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Stack";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(233, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Stack";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(233, 245);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Queue";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(7, 245);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(81, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Queue";
			// 
			// charQueueList
			// 
			this->charQueueList->Enabled = false;
			this->charQueueList->Location = System::Drawing::Point(12, 273);
			this->charQueueList->Name = L"charQueueList";
			this->charQueueList->Size = System::Drawing::Size(76, 96);
			this->charQueueList->TabIndex = 6;
			this->charQueueList->Text = L"";
			// 
			// charStackList
			// 
			this->charStackList->Enabled = false;
			this->charStackList->Location = System::Drawing::Point(12, 120);
			this->charStackList->Name = L"charStackList";
			this->charStackList->Size = System::Drawing::Size(76, 96);
			this->charStackList->TabIndex = 7;
			this->charStackList->Text = L"";
			// 
			// intQueueList
			// 
			this->intQueueList->Enabled = false;
			this->intQueueList->Location = System::Drawing::Point(238, 273);
			this->intQueueList->Name = L"intQueueList";
			this->intQueueList->Size = System::Drawing::Size(76, 96);
			this->intQueueList->TabIndex = 8;
			this->intQueueList->Text = L"";
			// 
			// intStackList
			// 
			this->intStackList->Enabled = false;
			this->intStackList->Location = System::Drawing::Point(238, 121);
			this->intStackList->Name = L"intStackList";
			this->intStackList->Size = System::Drawing::Size(76, 96);
			this->intStackList->TabIndex = 9;
			this->intStackList->Text = L"";
			// 
			// varCharStackPush
			// 
			this->varCharStackPush->Location = System::Drawing::Point(100, 123);
			this->varCharStackPush->MaxLength = 1;
			this->varCharStackPush->Name = L"varCharStackPush";
			this->varCharStackPush->Size = System::Drawing::Size(22, 20);
			this->varCharStackPush->TabIndex = 10;
			// 
			// varIntStackPush
			// 
			this->varIntStackPush->Location = System::Drawing::Point(330, 124);
			this->varIntStackPush->Name = L"varIntStackPush";
			this->varIntStackPush->Size = System::Drawing::Size(41, 20);
			this->varIntStackPush->TabIndex = 12;
			// 
			// varCharStackPop
			// 
			this->varCharStackPop->Location = System::Drawing::Point(100, 152);
			this->varCharStackPop->MaxLength = 1;
			this->varCharStackPop->Name = L"varCharStackPop";
			this->varCharStackPop->Size = System::Drawing::Size(22, 20);
			this->varCharStackPop->TabIndex = 14;
			// 
			// varCharStackPeek
			// 
			this->varCharStackPeek->Location = System::Drawing::Point(100, 180);
			this->varCharStackPeek->MaxLength = 1;
			this->varCharStackPeek->Name = L"varCharStackPeek";
			this->varCharStackPeek->Size = System::Drawing::Size(22, 20);
			this->varCharStackPeek->TabIndex = 15;
			// 
			// varIntStackPeek
			// 
			this->varIntStackPeek->Location = System::Drawing::Point(330, 182);
			this->varIntStackPeek->MaxLength = 1;
			this->varIntStackPeek->Name = L"varIntStackPeek";
			this->varIntStackPeek->Size = System::Drawing::Size(41, 20);
			this->varIntStackPeek->TabIndex = 19;
			// 
			// varIntStackPop
			// 
			this->varIntStackPop->Location = System::Drawing::Point(330, 153);
			this->varIntStackPop->MaxLength = 1;
			this->varIntStackPop->Name = L"varIntStackPop";
			this->varIntStackPop->Size = System::Drawing::Size(41, 20);
			this->varIntStackPop->TabIndex = 18;
			// 
			// btnCharStackPush
			// 
			this->btnCharStackPush->Location = System::Drawing::Point(128, 120);
			this->btnCharStackPush->Name = L"btnCharStackPush";
			this->btnCharStackPush->Size = System::Drawing::Size(75, 23);
			this->btnCharStackPush->TabIndex = 22;
			this->btnCharStackPush->Text = L"Push";
			this->btnCharStackPush->UseVisualStyleBackColor = true;
			this->btnCharStackPush->Click += gcnew System::EventHandler(this, &Form1::btnCharStackPush_Click);
			// 
			// btnCharStackPop
			// 
			this->btnCharStackPop->Location = System::Drawing::Point(128, 149);
			this->btnCharStackPop->Name = L"btnCharStackPop";
			this->btnCharStackPop->Size = System::Drawing::Size(75, 23);
			this->btnCharStackPop->TabIndex = 23;
			this->btnCharStackPop->Text = L"Pop";
			this->btnCharStackPop->UseVisualStyleBackColor = true;
			this->btnCharStackPop->Click += gcnew System::EventHandler(this, &Form1::btnCharStackPop_Click);
			// 
			// btnCharStackPeek
			// 
			this->btnCharStackPeek->Location = System::Drawing::Point(128, 178);
			this->btnCharStackPeek->Name = L"btnCharStackPeek";
			this->btnCharStackPeek->Size = System::Drawing::Size(75, 23);
			this->btnCharStackPeek->TabIndex = 24;
			this->btnCharStackPeek->Text = L"Peek";
			this->btnCharStackPeek->UseVisualStyleBackColor = true;
			this->btnCharStackPeek->Click += gcnew System::EventHandler(this, &Form1::btnCharStackPeek_Click);
			// 
			// btnCharQueuePeek
			// 
			this->btnCharQueuePeek->Location = System::Drawing::Point(128, 331);
			this->btnCharQueuePeek->Name = L"btnCharQueuePeek";
			this->btnCharQueuePeek->Size = System::Drawing::Size(75, 23);
			this->btnCharQueuePeek->TabIndex = 30;
			this->btnCharQueuePeek->Text = L"Peek";
			this->btnCharQueuePeek->UseVisualStyleBackColor = true;
			this->btnCharQueuePeek->Click += gcnew System::EventHandler(this, &Form1::btnCharQueuePeek_Click);
			// 
			// btnCharQueuePop
			// 
			this->btnCharQueuePop->Location = System::Drawing::Point(128, 302);
			this->btnCharQueuePop->Name = L"btnCharQueuePop";
			this->btnCharQueuePop->Size = System::Drawing::Size(75, 23);
			this->btnCharQueuePop->TabIndex = 29;
			this->btnCharQueuePop->Text = L"Pop";
			this->btnCharQueuePop->UseVisualStyleBackColor = true;
			this->btnCharQueuePop->Click += gcnew System::EventHandler(this, &Form1::btnCharQueuePop_Click);
			// 
			// btnCharQueuePush
			// 
			this->btnCharQueuePush->Location = System::Drawing::Point(128, 273);
			this->btnCharQueuePush->Name = L"btnCharQueuePush";
			this->btnCharQueuePush->Size = System::Drawing::Size(75, 23);
			this->btnCharQueuePush->TabIndex = 28;
			this->btnCharQueuePush->Text = L"Push";
			this->btnCharQueuePush->UseVisualStyleBackColor = true;
			this->btnCharQueuePush->Click += gcnew System::EventHandler(this, &Form1::btnCharQueuePush_Click);
			// 
			// varCharQueuePeek
			// 
			this->varCharQueuePeek->Location = System::Drawing::Point(100, 333);
			this->varCharQueuePeek->MaxLength = 1;
			this->varCharQueuePeek->Name = L"varCharQueuePeek";
			this->varCharQueuePeek->Size = System::Drawing::Size(22, 20);
			this->varCharQueuePeek->TabIndex = 27;
			// 
			// varCharQueuePop
			// 
			this->varCharQueuePop->Location = System::Drawing::Point(100, 305);
			this->varCharQueuePop->MaxLength = 1;
			this->varCharQueuePop->Name = L"varCharQueuePop";
			this->varCharQueuePop->Size = System::Drawing::Size(22, 20);
			this->varCharQueuePop->TabIndex = 26;
			// 
			// varCharQueuePush
			// 
			this->varCharQueuePush->Location = System::Drawing::Point(100, 276);
			this->varCharQueuePush->MaxLength = 1;
			this->varCharQueuePush->Name = L"varCharQueuePush";
			this->varCharQueuePush->Size = System::Drawing::Size(22, 20);
			this->varCharQueuePush->TabIndex = 25;
			// 
			// btnIntStackPeek
			// 
			this->btnIntStackPeek->Location = System::Drawing::Point(377, 179);
			this->btnIntStackPeek->Name = L"btnIntStackPeek";
			this->btnIntStackPeek->Size = System::Drawing::Size(75, 23);
			this->btnIntStackPeek->TabIndex = 33;
			this->btnIntStackPeek->Text = L"Peek";
			this->btnIntStackPeek->UseVisualStyleBackColor = true;
			this->btnIntStackPeek->Click += gcnew System::EventHandler(this, &Form1::btnIntStackPeek_Click);
			// 
			// btnIntStackPop
			// 
			this->btnIntStackPop->Location = System::Drawing::Point(377, 150);
			this->btnIntStackPop->Name = L"btnIntStackPop";
			this->btnIntStackPop->Size = System::Drawing::Size(75, 23);
			this->btnIntStackPop->TabIndex = 32;
			this->btnIntStackPop->Text = L"Pop";
			this->btnIntStackPop->UseVisualStyleBackColor = true;
			this->btnIntStackPop->Click += gcnew System::EventHandler(this, &Form1::btnIntStackPop_Click);
			// 
			// btnIntStackPush
			// 
			this->btnIntStackPush->Location = System::Drawing::Point(377, 121);
			this->btnIntStackPush->Name = L"btnIntStackPush";
			this->btnIntStackPush->Size = System::Drawing::Size(75, 23);
			this->btnIntStackPush->TabIndex = 31;
			this->btnIntStackPush->Text = L"Push";
			this->btnIntStackPush->UseVisualStyleBackColor = true;
			this->btnIntStackPush->Click += gcnew System::EventHandler(this, &Form1::btnIntStackPush_Click);
			// 
			// btnIntQueuePeek
			// 
			this->btnIntQueuePeek->Location = System::Drawing::Point(371, 331);
			this->btnIntQueuePeek->Name = L"btnIntQueuePeek";
			this->btnIntQueuePeek->Size = System::Drawing::Size(75, 23);
			this->btnIntQueuePeek->TabIndex = 39;
			this->btnIntQueuePeek->Text = L"Peek";
			this->btnIntQueuePeek->UseVisualStyleBackColor = true;
			this->btnIntQueuePeek->Click += gcnew System::EventHandler(this, &Form1::btnIntQueuePeek_Click);
			// 
			// btnIntQueuePop
			// 
			this->btnIntQueuePop->Location = System::Drawing::Point(371, 302);
			this->btnIntQueuePop->Name = L"btnIntQueuePop";
			this->btnIntQueuePop->Size = System::Drawing::Size(75, 23);
			this->btnIntQueuePop->TabIndex = 38;
			this->btnIntQueuePop->Text = L"Pop";
			this->btnIntQueuePop->UseVisualStyleBackColor = true;
			this->btnIntQueuePop->Click += gcnew System::EventHandler(this, &Form1::btnIntQueuePop_Click);
			// 
			// btnIntQueuePush
			// 
			this->btnIntQueuePush->Location = System::Drawing::Point(371, 273);
			this->btnIntQueuePush->Name = L"btnIntQueuePush";
			this->btnIntQueuePush->Size = System::Drawing::Size(75, 23);
			this->btnIntQueuePush->TabIndex = 37;
			this->btnIntQueuePush->Text = L"Push";
			this->btnIntQueuePush->UseVisualStyleBackColor = true;
			this->btnIntQueuePush->Click += gcnew System::EventHandler(this, &Form1::btnIntQueuePush_Click);
			// 
			// varIntQueuePeek
			// 
			this->varIntQueuePeek->Location = System::Drawing::Point(324, 334);
			this->varIntQueuePeek->MaxLength = 1;
			this->varIntQueuePeek->Name = L"varIntQueuePeek";
			this->varIntQueuePeek->Size = System::Drawing::Size(41, 20);
			this->varIntQueuePeek->TabIndex = 36;
			// 
			// varIntQueuePop
			// 
			this->varIntQueuePop->Location = System::Drawing::Point(324, 305);
			this->varIntQueuePop->MaxLength = 1;
			this->varIntQueuePop->Name = L"varIntQueuePop";
			this->varIntQueuePop->Size = System::Drawing::Size(41, 20);
			this->varIntQueuePop->TabIndex = 35;
			// 
			// varIntQueuePush
			// 
			this->varIntQueuePush->Location = System::Drawing::Point(324, 276);
			this->varIntQueuePush->Name = L"varIntQueuePush";
			this->varIntQueuePush->Size = System::Drawing::Size(41, 20);
			this->varIntQueuePush->TabIndex = 34;
			// 
			// testBtn
			// 
			this->testBtn->Location = System::Drawing::Point(13, 416);
			this->testBtn->Name = L"testBtn";
			this->testBtn->Size = System::Drawing::Size(439, 23);
			this->testBtn->TabIndex = 40;
			this->testBtn->Text = L"Run Test!!!";
			this->testBtn->UseVisualStyleBackColor = true;
			this->testBtn->Click += gcnew System::EventHandler(this, &Form1::testBtn_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 462);
			this->Controls->Add(this->testBtn);
			this->Controls->Add(this->btnIntQueuePeek);
			this->Controls->Add(this->btnIntQueuePop);
			this->Controls->Add(this->btnIntQueuePush);
			this->Controls->Add(this->varIntQueuePeek);
			this->Controls->Add(this->varIntQueuePop);
			this->Controls->Add(this->varIntQueuePush);
			this->Controls->Add(this->btnIntStackPeek);
			this->Controls->Add(this->btnIntStackPop);
			this->Controls->Add(this->btnIntStackPush);
			this->Controls->Add(this->btnCharQueuePeek);
			this->Controls->Add(this->btnCharQueuePop);
			this->Controls->Add(this->btnCharQueuePush);
			this->Controls->Add(this->varCharQueuePeek);
			this->Controls->Add(this->varCharQueuePop);
			this->Controls->Add(this->varCharQueuePush);
			this->Controls->Add(this->btnCharStackPeek);
			this->Controls->Add(this->btnCharStackPop);
			this->Controls->Add(this->btnCharStackPush);
			this->Controls->Add(this->varIntStackPeek);
			this->Controls->Add(this->varIntStackPop);
			this->Controls->Add(this->varCharStackPeek);
			this->Controls->Add(this->varCharStackPop);
			this->Controls->Add(this->varIntStackPush);
			this->Controls->Add(this->varCharStackPush);
			this->Controls->Add(this->intStackList);
			this->Controls->Add(this->intQueueList);
			this->Controls->Add(this->charStackList);
			this->Controls->Add(this->charQueueList);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varIntStackPush))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->varIntQueuePush))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			myIntStack = gcnew IntStack();
			myIntQueue = gcnew IntQueue();
			myCharStack = gcnew CharStack();
			myCharQueue = gcnew CharQueue();
		 }
		//CharStackPush event handler.
private: System::Void btnCharStackPush_Click(System::Object^  sender, System::EventArgs^  e) {
			
			Char c = varCharStackPush->Text[0];
			myCharStack->push(c);
			charStackList->Text = myCharStack->ToString();
		 }
		//CharStackPop event handler.
private: System::Void btnCharStackPop_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 Char c = myCharStack->pop();
			 varCharStackPop->Text = Convert::ToString(c);
			 charStackList->Text = myCharStack->ToString();
		 }
		 //CharStackPeek event handler.
private: System::Void btnCharStackPeek_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 Char c = myCharStack->peek();
			 varCharStackPeek->Text = Convert::ToString(c);
		 }
		 //CharQueuePush event handler.
private: System::Void btnCharQueuePush_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			Char c = varCharQueuePush->Text[0];
			myCharQueue->push(c);
			charQueueList->Text = myCharQueue->ToString();
		 }
		 //CharQueuePop event handler.
private: System::Void btnCharQueuePop_Click(System::Object^  sender, System::EventArgs^  e) {
			
			Char c = myCharQueue->pop();
			varCharQueuePop->Text = Convert::ToString(c);
			charQueueList->Text = myCharQueue->ToString();
		 }
		 //CharQueuePeek event handler.
private: System::Void btnCharQueuePeek_Click(System::Object^  sender, System::EventArgs^  e) {

			Char c = myCharQueue->peek();
			varCharQueuePeek->Text = Convert::ToString(c);
		 }
		 //IntStackPush event handler.
private: System::Void btnIntStackPush_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			int i  = (int)varIntStackPush->Value;
			myIntStack->push(i);
			intStackList->Text = myIntStack->ToString();
		 }
		 //IntStackPop event handler.
private: System::Void btnIntStackPop_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			int i  = myIntStack->pop();
			varIntStackPop->Text = Convert::ToString(i);
			intStackList->Text = myIntStack->ToString();
		 }
		 //IntStackPeek event handler.
private: System::Void btnIntStackPeek_Click(System::Object^  sender, System::EventArgs^  e) {
			
			int i  = myIntStack->peek();
			varIntStackPeek->Text = Convert::ToString(i);
		 }
		 //IntQueuePush event handler.
private: System::Void btnIntQueuePush_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			int i  = (int)varIntQueuePush->Value;
			myIntQueue->push(i);
			intQueueList->Text = myIntQueue->ToString();
		 }
		 //IntQueuePop event handler.
private: System::Void btnIntQueuePop_Click(System::Object^  sender, System::EventArgs^  e) {
			
			int i  = myIntQueue->pop();
			varIntQueuePop->Text = Convert::ToString(i);
			intQueueList->Text = myIntQueue->ToString();
		 }
		 //IntQueuePeek event handler.
private: System::Void btnIntQueuePeek_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			int i  = myIntQueue->peek();
			varIntQueuePeek->Text = Convert::ToString(i);
		 }
		//test button event handler.
private: System::Void testBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 Testing^ myTest = gcnew Testing();
			 String^ testResult = myTest->performTest();

			 System::Diagnostics::Debug::Write(testResult);
		 }
};
}

