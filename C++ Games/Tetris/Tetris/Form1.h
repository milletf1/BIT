#pragma once
#include "GameManager.h"

namespace Tetris {

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
	private: System::Windows::Forms::Timer^  gameTimer;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Random^ rand;
		GameManager^ myGameManager;
		Graphics^ canvas;

	private: System::Windows::Forms::Label^  scoreLabel;

	private: System::Windows::Forms::Label^  scoreOutput;
	private: System::Windows::Forms::Label^  levelOutput;
	private: System::Windows::Forms::Label^  levelLabel;




			 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->scoreOutput = (gcnew System::Windows::Forms::Label());
			this->levelOutput = (gcnew System::Windows::Forms::Label());
			this->levelLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// gameTimer
			// 
			this->gameTimer->Interval = 300;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &Form1::gameTimer_Tick);
			// 
			// scoreLabel
			// 
			this->scoreLabel->AutoSize = true;
			this->scoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->scoreLabel->Location = System::Drawing::Point(295, 100);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(61, 20);
			this->scoreLabel->TabIndex = 0;
			this->scoreLabel->Text = L"Score:";
			// 
			// scoreOutput
			// 
			this->scoreOutput->AutoSize = true;
			this->scoreOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->scoreOutput->Location = System::Drawing::Point(299, 135);
			this->scoreOutput->Name = L"scoreOutput";
			this->scoreOutput->Size = System::Drawing::Size(19, 20);
			this->scoreOutput->TabIndex = 1;
			this->scoreOutput->Text = L"0";
			// 
			// levelOutput
			// 
			this->levelOutput->AutoSize = true;
			this->levelOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->levelOutput->Location = System::Drawing::Point(299, 217);
			this->levelOutput->Name = L"levelOutput";
			this->levelOutput->Size = System::Drawing::Size(0, 20);
			this->levelOutput->TabIndex = 3;
			// 
			// levelLabel
			// 
			this->levelLabel->AutoSize = true;
			this->levelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->levelLabel->Location = System::Drawing::Point(295, 182);
			this->levelLabel->Name = L"levelLabel";
			this->levelLabel->Size = System::Drawing::Size(56, 20);
			this->levelLabel->TabIndex = 2;
			this->levelLabel->Text = L"Level:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightBlue;
			this->ClientSize = System::Drawing::Size(634, 499);
			this->Controls->Add(this->levelOutput);
			this->Controls->Add(this->levelLabel);
			this->Controls->Add(this->scoreOutput);
			this->Controls->Add(this->scoreLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"Tetris";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				
				Left = 0;
				Top = 0;
				Width = 440;
				Height = 600;
				rand = gcnew Random();
				canvas = CreateGraphics();
				myGameManager = gcnew GameManager(rand, gameTimer, canvas, levelOutput,scoreOutput);
				
			 }
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 myGameManager->Draw();
			 }
	private: System::Void gameStart_Click(System::Object^  sender, System::EventArgs^  e) {
				 myGameManager->InitiateGame();
			 }
	private: System::Void gameTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
				 myGameManager->GameCycle();
			 }

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {
				 //check for pressing the left key				 
				 if(e->KeyCode == Keys::Left)
				 {
					 myGameManager->MoveBlockLeft();
				 }
				 
				 //check for pressing the right key
				 else if(e->KeyCode == Keys::Right)
				 {
					 myGameManager->MoveBlockRight();
				 }
				
				 //check for pressing the up key
				 else if(e->KeyCode == Keys::Up)
				 {
					 myGameManager->RotateBlock();
				 }
				
				 //check for pressing the down key
				 else if(e->KeyCode == Keys::Down)
				 {
					 myGameManager->RaiseSpeed();
				 }
			 }
	private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				  if(e->KeyData == Keys::Down)
				 {
					 myGameManager->LowerSpeed();
				 }
			 }
private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 myGameManager->HandleClick(Point(e->X, e->Y));
		 }
};
}

