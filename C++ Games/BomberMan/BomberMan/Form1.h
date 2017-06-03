#pragma once
#include "GameManager.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define NONE 4
#define DROP_BOMB 5

namespace BomberMan {

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
	private: System::Windows::Forms::Panel^  gameArea;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  gameTimer;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		GameManager^ myGameManager;
	private: System::Windows::Forms::Label^  scoreLabel;
	private: System::Windows::Forms::Label^  scoreOutput;
	private: System::Windows::Forms::Label^  livesOutput;
	private: System::Windows::Forms::Label^  livesLabel;

			 Random^ rand;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->gameArea = (gcnew System::Windows::Forms::Panel());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->scoreOutput = (gcnew System::Windows::Forms::Label());
			this->livesOutput = (gcnew System::Windows::Forms::Label());
			this->livesLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// gameArea
			// 
			this->gameArea->Location = System::Drawing::Point(0, 0);
			this->gameArea->Name = L"gameArea";
			this->gameArea->Size = System::Drawing::Size(928, 608);
			this->gameArea->TabIndex = 0;
			this->gameArea->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::gameArea_MouseClick);
			// 
			// gameTimer
			// 
			this->gameTimer->Enabled = true;
			this->gameTimer->Interval = 50;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &Form1::gameTimer_Tick);
			// 
			// scoreLabel
			// 
			this->scoreLabel->AutoSize = true;
			this->scoreLabel->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->scoreLabel->ForeColor = System::Drawing::Color::White;
			this->scoreLabel->Location = System::Drawing::Point(150, 627);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(117, 47);
			this->scoreLabel->TabIndex = 1;
			this->scoreLabel->Text = L"Score:";
			// 
			// scoreOutput
			// 
			this->scoreOutput->AutoSize = true;
			this->scoreOutput->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 26.25F, System::Drawing::FontStyle::Bold));
			this->scoreOutput->ForeColor = System::Drawing::Color::White;
			this->scoreOutput->Location = System::Drawing::Point(382, 627);
			this->scoreOutput->Name = L"scoreOutput";
			this->scoreOutput->Size = System::Drawing::Size(38, 47);
			this->scoreOutput->TabIndex = 2;
			this->scoreOutput->Text = L"0";
			// 
			// livesOutput
			// 
			this->livesOutput->AutoSize = true;
			this->livesOutput->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 26.25F, System::Drawing::FontStyle::Bold));
			this->livesOutput->ForeColor = System::Drawing::Color::White;
			this->livesOutput->Location = System::Drawing::Point(775, 627);
			this->livesOutput->Name = L"livesOutput";
			this->livesOutput->Size = System::Drawing::Size(38, 47);
			this->livesOutput->TabIndex = 3;
			this->livesOutput->Text = L"0";
			// 
			// livesLabel
			// 
			this->livesLabel->AutoSize = true;
			this->livesLabel->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 26.25F, System::Drawing::FontStyle::Bold));
			this->livesLabel->ForeColor = System::Drawing::Color::White;
			this->livesLabel->Location = System::Drawing::Point(519, 627);
			this->livesLabel->Name = L"livesLabel";
			this->livesLabel->Size = System::Drawing::Size(121, 47);
			this->livesLabel->TabIndex = 4;
			this->livesLabel->Text = L"Lives: ";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(930, 698);
			this->Controls->Add(this->livesLabel);
			this->Controls->Add(this->livesOutput);
			this->Controls->Add(this->scoreOutput);
			this->Controls->Add(this->scoreLabel);
			this->Controls->Add(this->gameArea);
			this->Name = L"Form1";
			this->Text = L"Bomber Man";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->Left = 0;
			this->Top = 0;
		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 rand = gcnew Random();
				 myGameManager = gcnew GameManager(gameArea->CreateGraphics(), rand, gameArea->Width, gameArea->Height, scoreOutput,livesOutput);
			 }
	private: System::Void gameTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
				 myGameManager->TimerTick();
			 }
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				//up
				if(e->KeyCode == Keys::Up)
				 myGameManager->GetPlayerInput(UP);
				//down
				if(e->KeyCode == Keys::Down)
				 myGameManager->GetPlayerInput(DOWN);
				//left
				if(e->KeyCode == Keys::Left)
				 myGameManager->GetPlayerInput(LEFT);
				//right
				if(e->KeyCode == Keys::Right)
				 myGameManager->GetPlayerInput(RIGHT);
				if(e->KeyCode == Keys::Space)
					myGameManager->GetPlayerInput(DROP_BOMB);

			 }
			 
			 
	private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

				 if(e->KeyCode == Keys::Up ||
					e->KeyCode == Keys::Down ||
					e->KeyCode == Keys::Left ||
					e->KeyCode == Keys::Right)
				 myGameManager->GetPlayerInput(NONE);
			 }
	
private: System::Void gameArea_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				Point^ click = gcnew Point(e->X, e->Y);
				myGameManager->GetPlayerInput(click);
		 }
};
}

