#pragma once
#include "Maze.h"
#include "PrimsMaze.h"
#include "MazeManager.h"
#include "MazeFactory.h"
#include "MazeDisplay.h"

#define DEFAULT_SIZE 8

namespace Assignment3Maze {

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
	private: System::Windows::Forms::Panel^  mazeDisplay;
	private: System::Windows::Forms::Button^  generateBtn;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  sizePicker;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		
		MazeDisplay^ display;
		MazeManager^ manager;
		Random^ r;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mazeDisplay = (gcnew System::Windows::Forms::Panel());
			this->generateBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sizePicker = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sizePicker))->BeginInit();
			this->SuspendLayout();
			// 
			// mazeDisplay
			// 
			this->mazeDisplay->BackColor = System::Drawing::Color::Gray;
			this->mazeDisplay->Location = System::Drawing::Point(13, 13);
			this->mazeDisplay->Name = L"mazeDisplay";
			this->mazeDisplay->Size = System::Drawing::Size(450, 450);
			this->mazeDisplay->TabIndex = 0;
			// 
			// generateBtn
			// 
			this->generateBtn->Location = System::Drawing::Point(124, 510);
			this->generateBtn->Name = L"generateBtn";
			this->generateBtn->Size = System::Drawing::Size(90, 23);
			this->generateBtn->TabIndex = 1;
			this->generateBtn->Text = L"Generate Maze";
			this->generateBtn->UseVisualStyleBackColor = true;
			this->generateBtn->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(220, 510);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Solve Maze";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 497);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Maze Size:";
			// 
			// sizePicker
			// 
			this->sizePicker->Location = System::Drawing::Point(15, 513);
			this->sizePicker->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {64, 0, 0, 0});
			this->sizePicker->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->sizePicker->Name = L"sizePicker";
			this->sizePicker->Size = System::Drawing::Size(84, 20);
			this->sizePicker->TabIndex = 4;
			this->sizePicker->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 537);
			this->Controls->Add(this->sizePicker);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->generateBtn);
			this->Controls->Add(this->mazeDisplay);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sizePicker))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Form load handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			
				Left = 0;
				Top = 0;
				display = gcnew MazeDisplay(mazeDisplay->CreateGraphics(), mazeDisplay->Width, mazeDisplay->Height);
				r = gcnew Random();
				manager = gcnew MazeManager(display, DEFAULT_SIZE, DEFAULT_SIZE, r);				
			 }

			 // Maze generation click handler.
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
				 int mazeSize = (int)sizePicker->Value;
				manager->generateMaze(mazeSize, mazeSize); 
			 }

			 // Solve maze button click handler.
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				manager->solveMaze();
			 }
};
}

