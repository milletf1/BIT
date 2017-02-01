#pragma once
#include "HuffmanNode.h"
#include "HuffmanTree.h"

namespace HuffmanCodingAssignment {

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
	private: System::Windows::Forms::Button^  btnBuildHuffman;
	private: System::Windows::Forms::Panel^  displayOutput;
	protected: 


	private: System::Windows::Forms::TextBox^  symbol1Input;
	private: System::Windows::Forms::TextBox^  symbol8Input;


	private: System::Windows::Forms::TextBox^  symbol7Input;

	private: System::Windows::Forms::TextBox^  symbol6Input;

	private: System::Windows::Forms::TextBox^  symbol5Input;

	private: System::Windows::Forms::TextBox^  symbol4Input;

	private: System::Windows::Forms::TextBox^  symbol3Input;

	private: System::Windows::Forms::TextBox^  symbol2Input;
	private: System::Windows::Forms::NumericUpDown^  frequency1Input;
	private: System::Windows::Forms::NumericUpDown^  frequency8Input;



	private: System::Windows::Forms::NumericUpDown^  frequency7Input;

	private: System::Windows::Forms::NumericUpDown^  frequency6Input;

	private: System::Windows::Forms::NumericUpDown^  frequency5Input;

	private: System::Windows::Forms::NumericUpDown^  frequency4Input;

	private: System::Windows::Forms::NumericUpDown^  frequency3Input;

	private: System::Windows::Forms::NumericUpDown^  frequency2Input;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  huffmanCodeOutput;

	private: System::Windows::Forms::Button^  btnShowCode;
	private: System::Windows::Forms::TextBox^  encodedTextInput;
	private: System::Windows::Forms::Button^  btnDecode;



	private: System::Windows::Forms::Label^  decodeOutput;
	private: System::Windows::Forms::Button^  btnBuildFile;
	private: System::Windows::Forms::TextBox^  filePathInput;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  huffmanBitsOutput;
	private: System::Windows::Forms::Label^  fixedLengthBitsOutput;
	private: System::Windows::Forms::Button^  btnSearchFile;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		HuffmanTree^ tree;
		static String^ decodedStringTitle = "Plain text: ";
		static String^ huffmanBitsTitle = "Huffman bits: ";
		static String^ fixedLengthTitle = "Fixed Length bits: ";

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnBuildHuffman = (gcnew System::Windows::Forms::Button());
			this->displayOutput = (gcnew System::Windows::Forms::Panel());
			this->symbol1Input = (gcnew System::Windows::Forms::TextBox());
			this->symbol8Input = (gcnew System::Windows::Forms::TextBox());
			this->symbol7Input = (gcnew System::Windows::Forms::TextBox());
			this->symbol6Input = (gcnew System::Windows::Forms::TextBox());
			this->symbol5Input = (gcnew System::Windows::Forms::TextBox());
			this->symbol4Input = (gcnew System::Windows::Forms::TextBox());
			this->symbol3Input = (gcnew System::Windows::Forms::TextBox());
			this->symbol2Input = (gcnew System::Windows::Forms::TextBox());
			this->frequency1Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->frequency8Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->frequency7Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->frequency6Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->frequency5Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->frequency4Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->frequency3Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->frequency2Input = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->huffmanCodeOutput = (gcnew System::Windows::Forms::ListBox());
			this->btnShowCode = (gcnew System::Windows::Forms::Button());
			this->encodedTextInput = (gcnew System::Windows::Forms::TextBox());
			this->btnDecode = (gcnew System::Windows::Forms::Button());
			this->decodeOutput = (gcnew System::Windows::Forms::Label());
			this->btnBuildFile = (gcnew System::Windows::Forms::Button());
			this->filePathInput = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->huffmanBitsOutput = (gcnew System::Windows::Forms::Label());
			this->fixedLengthBitsOutput = (gcnew System::Windows::Forms::Label());
			this->btnSearchFile = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency1Input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency8Input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency7Input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency6Input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency5Input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency4Input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency3Input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency2Input))->BeginInit();
			this->SuspendLayout();
			// 
			// btnBuildHuffman
			// 
			this->btnBuildHuffman->Location = System::Drawing::Point(39, 253);
			this->btnBuildHuffman->Name = L"btnBuildHuffman";
			this->btnBuildHuffman->Size = System::Drawing::Size(113, 23);
			this->btnBuildHuffman->TabIndex = 0;
			this->btnBuildHuffman->Text = L"Build Huffman";
			this->btnBuildHuffman->UseVisualStyleBackColor = true;
			this->btnBuildHuffman->Click += gcnew System::EventHandler(this, &Form1::btnBuildHuffman_Click);
			// 
			// displayOutput
			// 
			this->displayOutput->Location = System::Drawing::Point(278, 22);
			this->displayOutput->Name = L"displayOutput";
			this->displayOutput->Size = System::Drawing::Size(700, 700);
			this->displayOutput->TabIndex = 1;
			// 
			// symbol1Input
			// 
			this->symbol1Input->Location = System::Drawing::Point(40, 35);
			this->symbol1Input->MaxLength = 1;
			this->symbol1Input->Name = L"symbol1Input";
			this->symbol1Input->Size = System::Drawing::Size(53, 20);
			this->symbol1Input->TabIndex = 2;
			// 
			// symbol8Input
			// 
			this->symbol8Input->Location = System::Drawing::Point(40, 217);
			this->symbol8Input->MaxLength = 1;
			this->symbol8Input->Name = L"symbol8Input";
			this->symbol8Input->Size = System::Drawing::Size(53, 20);
			this->symbol8Input->TabIndex = 3;
			// 
			// symbol7Input
			// 
			this->symbol7Input->Location = System::Drawing::Point(40, 191);
			this->symbol7Input->MaxLength = 1;
			this->symbol7Input->Name = L"symbol7Input";
			this->symbol7Input->Size = System::Drawing::Size(53, 20);
			this->symbol7Input->TabIndex = 4;
			// 
			// symbol6Input
			// 
			this->symbol6Input->Location = System::Drawing::Point(40, 165);
			this->symbol6Input->MaxLength = 1;
			this->symbol6Input->Name = L"symbol6Input";
			this->symbol6Input->Size = System::Drawing::Size(53, 20);
			this->symbol6Input->TabIndex = 5;
			// 
			// symbol5Input
			// 
			this->symbol5Input->Location = System::Drawing::Point(40, 139);
			this->symbol5Input->MaxLength = 1;
			this->symbol5Input->Name = L"symbol5Input";
			this->symbol5Input->Size = System::Drawing::Size(53, 20);
			this->symbol5Input->TabIndex = 6;
			// 
			// symbol4Input
			// 
			this->symbol4Input->Location = System::Drawing::Point(40, 113);
			this->symbol4Input->MaxLength = 1;
			this->symbol4Input->Name = L"symbol4Input";
			this->symbol4Input->Size = System::Drawing::Size(53, 20);
			this->symbol4Input->TabIndex = 7;
			// 
			// symbol3Input
			// 
			this->symbol3Input->Location = System::Drawing::Point(40, 87);
			this->symbol3Input->MaxLength = 1;
			this->symbol3Input->Name = L"symbol3Input";
			this->symbol3Input->Size = System::Drawing::Size(53, 20);
			this->symbol3Input->TabIndex = 8;
			// 
			// symbol2Input
			// 
			this->symbol2Input->Location = System::Drawing::Point(40, 61);
			this->symbol2Input->MaxLength = 1;
			this->symbol2Input->Name = L"symbol2Input";
			this->symbol2Input->Size = System::Drawing::Size(53, 20);
			this->symbol2Input->TabIndex = 9;
			// 
			// frequency1Input
			// 
			this->frequency1Input->Location = System::Drawing::Point(99, 35);
			this->frequency1Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency1Input->Name = L"frequency1Input";
			this->frequency1Input->Size = System::Drawing::Size(53, 20);
			this->frequency1Input->TabIndex = 10;
			this->frequency1Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// frequency8Input
			// 
			this->frequency8Input->Location = System::Drawing::Point(99, 217);
			this->frequency8Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency8Input->Name = L"frequency8Input";
			this->frequency8Input->Size = System::Drawing::Size(53, 20);
			this->frequency8Input->TabIndex = 11;
			this->frequency8Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// frequency7Input
			// 
			this->frequency7Input->Location = System::Drawing::Point(99, 191);
			this->frequency7Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency7Input->Name = L"frequency7Input";
			this->frequency7Input->Size = System::Drawing::Size(53, 20);
			this->frequency7Input->TabIndex = 12;
			this->frequency7Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// frequency6Input
			// 
			this->frequency6Input->Location = System::Drawing::Point(99, 165);
			this->frequency6Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency6Input->Name = L"frequency6Input";
			this->frequency6Input->Size = System::Drawing::Size(53, 20);
			this->frequency6Input->TabIndex = 13;
			this->frequency6Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// frequency5Input
			// 
			this->frequency5Input->Location = System::Drawing::Point(99, 140);
			this->frequency5Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency5Input->Name = L"frequency5Input";
			this->frequency5Input->Size = System::Drawing::Size(53, 20);
			this->frequency5Input->TabIndex = 14;
			this->frequency5Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// frequency4Input
			// 
			this->frequency4Input->Location = System::Drawing::Point(99, 114);
			this->frequency4Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency4Input->Name = L"frequency4Input";
			this->frequency4Input->Size = System::Drawing::Size(53, 20);
			this->frequency4Input->TabIndex = 15;
			this->frequency4Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// frequency3Input
			// 
			this->frequency3Input->Location = System::Drawing::Point(99, 87);
			this->frequency3Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency3Input->Name = L"frequency3Input";
			this->frequency3Input->Size = System::Drawing::Size(53, 20);
			this->frequency3Input->TabIndex = 16;
			this->frequency3Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// frequency2Input
			// 
			this->frequency2Input->Location = System::Drawing::Point(99, 62);
			this->frequency2Input->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->frequency2Input->Name = L"frequency2Input";
			this->frequency2Input->Size = System::Drawing::Size(53, 20);
			this->frequency2Input->TabIndex = 17;
			this->frequency2Input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Symbol";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(96, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Frequency";
			// 
			// huffmanCodeOutput
			// 
			this->huffmanCodeOutput->FormattingEnabled = true;
			this->huffmanCodeOutput->Location = System::Drawing::Point(159, 35);
			this->huffmanCodeOutput->Name = L"huffmanCodeOutput";
			this->huffmanCodeOutput->Size = System::Drawing::Size(113, 212);
			this->huffmanCodeOutput->TabIndex = 20;
			// 
			// btnShowCode
			// 
			this->btnShowCode->Location = System::Drawing::Point(159, 253);
			this->btnShowCode->Name = L"btnShowCode";
			this->btnShowCode->Size = System::Drawing::Size(113, 23);
			this->btnShowCode->TabIndex = 21;
			this->btnShowCode->Text = L"Show Codes";
			this->btnShowCode->UseVisualStyleBackColor = true;
			this->btnShowCode->Click += gcnew System::EventHandler(this, &Form1::btnShowCode_Click);
			// 
			// encodedTextInput
			// 
			this->encodedTextInput->Location = System::Drawing::Point(39, 310);
			this->encodedTextInput->Name = L"encodedTextInput";
			this->encodedTextInput->Size = System::Drawing::Size(233, 20);
			this->encodedTextInput->TabIndex = 22;
			// 
			// btnDecode
			// 
			this->btnDecode->Location = System::Drawing::Point(39, 375);
			this->btnDecode->Name = L"btnDecode";
			this->btnDecode->Size = System::Drawing::Size(113, 23);
			this->btnDecode->TabIndex = 23;
			this->btnDecode->Text = L"Decode";
			this->btnDecode->UseVisualStyleBackColor = true;
			this->btnDecode->Click += gcnew System::EventHandler(this, &Form1::btnDecode_Click);
			// 
			// decodeOutput
			// 
			this->decodeOutput->AutoSize = true;
			this->decodeOutput->Location = System::Drawing::Point(36, 346);
			this->decodeOutput->Name = L"decodeOutput";
			this->decodeOutput->Size = System::Drawing::Size(60, 13);
			this->decodeOutput->TabIndex = 24;
			this->decodeOutput->Text = L"Plain Text: ";
			// 
			// btnBuildFile
			// 
			this->btnBuildFile->Location = System::Drawing::Point(37, 459);
			this->btnBuildFile->Name = L"btnBuildFile";
			this->btnBuildFile->Size = System::Drawing::Size(115, 23);
			this->btnBuildFile->TabIndex = 25;
			this->btnBuildFile->Text = L"Build Huffman";
			this->btnBuildFile->UseVisualStyleBackColor = true;
			this->btnBuildFile->Click += gcnew System::EventHandler(this, &Form1::btnBuildFile_Click);
			// 
			// filePathInput
			// 
			this->filePathInput->Location = System::Drawing::Point(36, 433);
			this->filePathInput->Name = L"filePathInput";
			this->filePathInput->Size = System::Drawing::Size(233, 20);
			this->filePathInput->TabIndex = 26;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 294);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 13);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Encoded Text";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(37, 417);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 13);
			this->label4->TabIndex = 28;
			this->label4->Text = L"File Path";
			// 
			// huffmanBitsOutput
			// 
			this->huffmanBitsOutput->AutoSize = true;
			this->huffmanBitsOutput->Location = System::Drawing::Point(36, 506);
			this->huffmanBitsOutput->Name = L"huffmanBitsOutput";
			this->huffmanBitsOutput->Size = System::Drawing::Size(70, 13);
			this->huffmanBitsOutput->TabIndex = 29;
			this->huffmanBitsOutput->Text = L"Huffman Bits:";
			// 
			// fixedLengthBitsOutput
			// 
			this->fixedLengthBitsOutput->AutoSize = true;
			this->fixedLengthBitsOutput->Location = System::Drawing::Point(36, 537);
			this->fixedLengthBitsOutput->Name = L"fixedLengthBitsOutput";
			this->fixedLengthBitsOutput->Size = System::Drawing::Size(91, 13);
			this->fixedLengthBitsOutput->TabIndex = 30;
			this->fixedLengthBitsOutput->Text = L"Fixed Length Bits:";
			// 
			// btnSearchFile
			// 
			this->btnSearchFile->Location = System::Drawing::Point(159, 459);
			this->btnSearchFile->Name = L"btnSearchFile";
			this->btnSearchFile->Size = System::Drawing::Size(110, 23);
			this->btnSearchFile->TabIndex = 31;
			this->btnSearchFile->Text = L"Search";
			this->btnSearchFile->UseVisualStyleBackColor = true;
			this->btnSearchFile->Click += gcnew System::EventHandler(this, &Form1::btnSearchFile_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 725);
			this->Controls->Add(this->btnSearchFile);
			this->Controls->Add(this->fixedLengthBitsOutput);
			this->Controls->Add(this->huffmanBitsOutput);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->filePathInput);
			this->Controls->Add(this->btnBuildFile);
			this->Controls->Add(this->decodeOutput);
			this->Controls->Add(this->btnDecode);
			this->Controls->Add(this->encodedTextInput);
			this->Controls->Add(this->btnShowCode);
			this->Controls->Add(this->huffmanCodeOutput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->frequency2Input);
			this->Controls->Add(this->frequency3Input);
			this->Controls->Add(this->frequency4Input);
			this->Controls->Add(this->frequency5Input);
			this->Controls->Add(this->frequency6Input);
			this->Controls->Add(this->frequency7Input);
			this->Controls->Add(this->frequency8Input);
			this->Controls->Add(this->frequency1Input);
			this->Controls->Add(this->symbol2Input);
			this->Controls->Add(this->symbol3Input);
			this->Controls->Add(this->symbol4Input);
			this->Controls->Add(this->symbol5Input);
			this->Controls->Add(this->symbol6Input);
			this->Controls->Add(this->symbol7Input);
			this->Controls->Add(this->symbol8Input);
			this->Controls->Add(this->symbol1Input);
			this->Controls->Add(this->displayOutput);
			this->Controls->Add(this->btnBuildHuffman);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency1Input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency8Input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency7Input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency6Input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency5Input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency4Input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency3Input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frequency2Input))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/**
		 * Build Huffman Tree button click handler.  Builds and displays a huffman tree, 
		 * and Huffman and fixed length bits from a give set of symbol frequencies.
		 */
	private: System::Void btnBuildHuffman_Click(System::Object^  sender, System::EventArgs^  e) {
			
				Dictionary<Char, int>^ symbolFrequency = buildSymbolList();
				tree->buildHuffmanTree(symbolFrequency);

				// Display the huffman tree.
				Bitmap^ img = tree->getHuffmanTree(displayOutput->Width, displayOutput->Height, displayOutput->BackColor);
				displayOutput->BackgroundImage = img;
				
				int huffmanBits = tree->getHuffmanBits();
				int fixedLengthBits = tree->getFixedLengthBits();

				// Display the Huffman coded bits.
				huffmanBitsOutput->Text = huffmanBitsTitle + Convert::ToString(huffmanBits);
				// Display the fixed length coded bits.
				fixedLengthBitsOutput->Text = fixedLengthTitle + Convert::ToString(fixedLengthBits);
			 }
		/**
		 * Build Huffman code from text file button click handler. 
		 * Builds and displays a huffman code from a given text file.
		 */
	private: System::Void btnBuildFile_Click(System::Object^  sender, System::EventArgs^  e) {

				Dictionary<Char, int>^ symbolFrequency = buildSymbolList();
				tree->buildHuffmanTree(filePathInput->Text);

				// Display the huffman code.
				Dictionary<Char, String^>^ huffmanCode = tree->getHuffmanCode();
				huffmanCodeOutput->Items->Clear();
	
				for each(KeyValuePair<Char, String^>^ code in huffmanCode)
				{
					String^ displayString = Convert::ToString(code->Key) + ": " + code->Value;
					huffmanCodeOutput->Items->Add(displayString);
				}
			 }

			/**
			 * Function to build a list of symbols and their frequencies.
			 */
	private: Dictionary<Char, int>^ buildSymbolList() {
				Dictionary<Char, int>^ symbolFrequency = gcnew Dictionary<Char, int>();
				Char c;

				if(symbol1Input->Text->Length > 0)
				{
					c = symbol1Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency1Input->Value;
				}
				if(symbol2Input->Text->Length > 0)
				{
					c = symbol2Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency2Input->Value;
				}
				if(symbol3Input->Text->Length > 0)
				{
					c = symbol3Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency3Input->Value;
				}
				if(symbol4Input->Text->Length > 0)
				{
					c = symbol4Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency4Input->Value;
				}
				if(symbol5Input->Text->Length > 0)
				{
					c = symbol5Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency5Input->Value;
				}
				if(symbol6Input->Text->Length > 0)
				{
					c = symbol6Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency6Input->Value;
				}
				if(symbol7Input->Text->Length > 0)
				{
					c = symbol7Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency7Input->Value;
				}
				
				if(symbol8Input->Text->Length > 0)
				{
					c = symbol8Input->Text->ToCharArray()[0];
					symbolFrequency[c] = (int)frequency8Input->Value;
				}
				return symbolFrequency;
			 }
		/**
		* Search for text file button click handler.			
		*/
private: System::Void btnSearchFile_Click(System::Object^  sender, System::EventArgs^  e) {
			  
			//Open a file dialog to let the user select a text file.
			OpenFileDialog^ dialog = gcnew OpenFileDialog();
			dialog->Filter = "txt files (*.txt)|*.txt";

			//Display the contents of the text file and its path if a new text file is selected.
			if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				filePathInput->Text = dialog->FileName;
		 }
		 /**
		  * Decode button click handler.
		  */
private: System::Void btnDecode_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 // Get the encoded string.
			 String^ encoded = encodedTextInput->Text;

			 // Get the decoded string.
			 String^ decoded = tree->decodeString(encoded);

			 // Display the decoded string.
			 decodeOutput->Text = decodedStringTitle + decoded;			 
		 }

		 /**
		  * Form load event handler.
		  */
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 
			 Left = 0;
			 Top = 0;

			 tree = gcnew HuffmanTree();
		 }

		 /**
		  * Show Huffman Code button click handler.
		  */
private: System::Void btnShowCode_Click(System::Object^  sender, System::EventArgs^  e) {
			 
				Dictionary<Char, String^>^ huffmanCode = tree->getHuffmanCode();
				
				huffmanCodeOutput->Items->Clear();
	
				//Iterate through each item in the huffmanCode dictionary.
				for each(KeyValuePair<Char, String^>^ code in huffmanCode)
				{
					// Display the current huffman code character and its encoded value.
					String^ displayString = Convert::ToString(code->Key) + ": " + code->Value;
					huffmanCodeOutput->Items->Add(displayString);
				}
		 }
};
}

