#pragma once
#include "VigenereWorker.h"
#include "BatchDecode.h"

namespace VigenereCipher {

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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RadioButton^  rbEncrypt;
	private: System::Windows::Forms::RadioButton^  rbDecrypt;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnRunCipher;

	private: System::Windows::Forms::TextBox^  tbString;
	private: System::Windows::Forms::TextBox^  tbKey;
	private: System::Windows::Forms::TextBox^  tbResult;
	private: System::Windows::Forms::Button^  btnRunBatch;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbBatchInput;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		static String^ DEFAULT_BATCH_FILE = "ViginereTestInput.txt";

		System::ComponentModel::Container ^components;

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
			this->rbEncrypt = (gcnew System::Windows::Forms::RadioButton());
			this->rbDecrypt = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnRunCipher = (gcnew System::Windows::Forms::Button());
			this->tbString = (gcnew System::Windows::Forms::TextBox());
			this->tbKey = (gcnew System::Windows::Forms::TextBox());
			this->tbResult = (gcnew System::Windows::Forms::TextBox());
			this->btnRunBatch = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbBatchInput = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Message:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Key:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Function:";
			// 
			// rbEncrypt
			// 
			this->rbEncrypt->AutoSize = true;
			this->rbEncrypt->Checked = true;
			this->rbEncrypt->Location = System::Drawing::Point(12, 159);
			this->rbEncrypt->Name = L"rbEncrypt";
			this->rbEncrypt->Size = System::Drawing::Size(61, 17);
			this->rbEncrypt->TabIndex = 3;
			this->rbEncrypt->TabStop = true;
			this->rbEncrypt->Text = L"Encrypt";
			this->rbEncrypt->UseVisualStyleBackColor = true;
			// 
			// rbDecrypt
			// 
			this->rbDecrypt->AutoSize = true;
			this->rbDecrypt->Location = System::Drawing::Point(11, 182);
			this->rbDecrypt->Name = L"rbDecrypt";
			this->rbDecrypt->Size = System::Drawing::Size(62, 17);
			this->rbDecrypt->TabIndex = 4;
			this->rbDecrypt->Text = L"Decrypt";
			this->rbDecrypt->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1, 145);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(212, 71);
			this->panel1->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 249);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Result:";
			// 
			// btnRunCipher
			// 
			this->btnRunCipher->Location = System::Drawing::Point(11, 223);
			this->btnRunCipher->Name = L"btnRunCipher";
			this->btnRunCipher->Size = System::Drawing::Size(202, 23);
			this->btnRunCipher->TabIndex = 7;
			this->btnRunCipher->Text = L"Run Cipher";
			this->btnRunCipher->UseVisualStyleBackColor = true;
			this->btnRunCipher->Click += gcnew System::EventHandler(this, &Form1::btnRunCipher_Click);
			// 
			// tbString
			// 
			this->tbString->Location = System::Drawing::Point(15, 63);
			this->tbString->Name = L"tbString";
			this->tbString->Size = System::Drawing::Size(198, 20);
			this->tbString->TabIndex = 8;
			// 
			// tbKey
			// 
			this->tbKey->Location = System::Drawing::Point(15, 102);
			this->tbKey->Name = L"tbKey";
			this->tbKey->Size = System::Drawing::Size(198, 20);
			this->tbKey->TabIndex = 9;
			// 
			// tbResult
			// 
			this->tbResult->Location = System::Drawing::Point(11, 265);
			this->tbResult->Name = L"tbResult";
			this->tbResult->Size = System::Drawing::Size(202, 20);
			this->tbResult->TabIndex = 10;
			// 
			// btnRunBatch
			// 
			this->btnRunBatch->Location = System::Drawing::Point(12, 389);
			this->btnRunBatch->Name = L"btnRunBatch";
			this->btnRunBatch->Size = System::Drawing::Size(201, 23);
			this->btnRunBatch->TabIndex = 11;
			this->btnRunBatch->Text = L"Run Batch";
			this->btnRunBatch->UseVisualStyleBackColor = true;
			this->btnRunBatch->Click += gcnew System::EventHandler(this, &Form1::btnRunBatch_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(15, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(180, 25);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Single Message";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(15, 303);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(192, 25);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Batch Decryption";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 336);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Input File:";
			// 
			// tbBatchInput
			// 
			this->tbBatchInput->Location = System::Drawing::Point(15, 352);
			this->tbBatchInput->Name = L"tbBatchInput";
			this->tbBatchInput->Size = System::Drawing::Size(203, 20);
			this->tbBatchInput->TabIndex = 16;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(225, 424);
			this->Controls->Add(this->tbBatchInput);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnRunBatch);
			this->Controls->Add(this->tbResult);
			this->Controls->Add(this->tbKey);
			this->Controls->Add(this->tbString);
			this->Controls->Add(this->btnRunCipher);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->rbDecrypt);
			this->Controls->Add(this->rbEncrypt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/**************************
	 * Form load event handler.
	 *************************/
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{				 
		tbBatchInput->Text = DEFAULT_BATCH_FILE;
	}	

	/******************************************************************************************	 
	 * Precondition:  The user must click the btnRunCipher button on the form.  The user must 
	 *				  also enter text into the tbKey and tbString textboxes, and chose if they
	 *                want to decrypt or encrypt the given string.
     *
	 * Postcondition: The result of the strings encryption/decryption will be displayed in the 
	 *                tbResult textbox. 
	 ****************************************************************************************/
	private: System::Void btnRunCipher_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ message = tbString->Text;
		String^ key = tbKey->Text;
		VigenereWorker^ vigenere = gcnew VigenereWorker(key);
		
		//Check if the user wants to decrypt or encrypt the given message.
		(rbEncrypt->Checked)? 
			tbResult->Text = vigenere->encrpyt(message) 
			: tbResult->Text = vigenere->decrypt(message);
	}

    /***************************************************************************************
	 * Precondition:  The user must click the btnRunBatch button on the form.  The user must
	 *				  also enter the path to the text file that the function will decode.	
	 *
     * Postcondition: If the given text file successfully decodes, a message will inform
	 *				  the user that it was successful, and give the name of the file that
	 *                the result was written to. 
	 *                If the text file fails to decode, a message will inform the user that
	 *				  it failed.	
	 **************************************************************************************/
	private: System::Void btnRunBatch_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ filePath = tbBatchInput->Text;
		BatchDecode^ bd = gcnew BatchDecode();

		bd->decode(filePath);
	}
};
}

