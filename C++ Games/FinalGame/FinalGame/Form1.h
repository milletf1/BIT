/*										Final Game

						Created by Tim Miller for IN613 C++ Games

How to play:

The object of the game is to try and get as high as possible on the map before being drowned
by the rising water level.  Throughout the world their are shuriken and jet pack power ups to
help the player reach this goal.  There are also object in the form of Goblins, which stroll 
along the platforms in this game. upon sight of the player, they charge in an attempt to knock
the player to his watery grave.  Click the start button in the bottom right corner to get started.

Controls:

* Move the Player: Left and Right arrow keys.
* Jump:  Up arrow key.
* Wall Jump: Up arrow key when jumping just before you hit a wall.
* Throw Shuriken: Q key.
* Jet Pack Jump: W key.
*/

#pragma once
#include "GameManager.h"

#define LEFT 0
#define RIGHT 1
#define JUMP 3
#define USE_JET 4
#define USE_SHURIKEN 5



namespace FinalGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
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
	private: System::Windows::Forms::Panel^  gameOutput;
	protected: 

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  gameTimer;
	protected: 

	private:
		/// <summary>
		/// variables needed by the form to run the game.
		/// </summary>
		GameManager^ myGameManager;
		Random^ rand;

	private: System::Windows::Forms::Label^  heightLabel;
	private: System::Windows::Forms::Label^  startButton;
	private: System::Windows::Forms::Label^  shurikenLabel;
	private: System::Windows::Forms::Label^  jetpackLabel;
	private: System::Windows::Forms::Label^  heightOutput;
	private: System::Windows::Forms::Label^  shurikenOutput;
	private: System::Windows::Forms::Label^  jetOutput;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->gameOutput = (gcnew System::Windows::Forms::Panel());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->heightLabel = (gcnew System::Windows::Forms::Label());
			this->startButton = (gcnew System::Windows::Forms::Label());
			this->shurikenLabel = (gcnew System::Windows::Forms::Label());
			this->jetpackLabel = (gcnew System::Windows::Forms::Label());
			this->heightOutput = (gcnew System::Windows::Forms::Label());
			this->shurikenOutput = (gcnew System::Windows::Forms::Label());
			this->jetOutput = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// gameOutput
			// 
			this->gameOutput->Location = System::Drawing::Point(12, 12);
			this->gameOutput->Name = L"gameOutput";
			this->gameOutput->Size = System::Drawing::Size(640, 640);
			this->gameOutput->TabIndex = 0;
			// 
			// gameTimer
			// 
			this->gameTimer->Interval = 50;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &Form1::gameTimer_Tick);
			// 
			// heightLabel
			// 
			this->heightLabel->AutoSize = true;
			this->heightLabel->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->heightLabel->Location = System::Drawing::Point(676, 28);
			this->heightLabel->Name = L"heightLabel";
			this->heightLabel->Size = System::Drawing::Size(127, 30);
			this->heightLabel->TabIndex = 1;
			this->heightLabel->Text = L"Max Height:";
			// 
			// startButton
			// 
			this->startButton->AutoSize = true;
			this->startButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->startButton->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->startButton->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->startButton->Location = System::Drawing::Point(681, 620);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(124, 32);
			this->startButton->TabIndex = 2;
			this->startButton->Text = L"Start Game";
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// shurikenLabel
			// 
			this->shurikenLabel->AutoSize = true;
			this->shurikenLabel->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->shurikenLabel->Location = System::Drawing::Point(676, 92);
			this->shurikenLabel->Name = L"shurikenLabel";
			this->shurikenLabel->Size = System::Drawing::Size(112, 30);
			this->shurikenLabel->TabIndex = 3;
			this->shurikenLabel->Text = L"Shurikens:";
			// 
			// jetpackLabel
			// 
			this->jetpackLabel->AutoSize = true;
			this->jetpackLabel->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->jetpackLabel->Location = System::Drawing::Point(676, 157);
			this->jetpackLabel->Name = L"jetpackLabel";
			this->jetpackLabel->Size = System::Drawing::Size(182, 30);
			this->jetpackLabel->TabIndex = 4;
			this->jetpackLabel->Text = L"Jet Pack Charges:";
			// 
			// heightOutput
			// 
			this->heightOutput->AutoSize = true;
			this->heightOutput->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->heightOutput->Location = System::Drawing::Point(678, 58);
			this->heightOutput->Name = L"heightOutput";
			this->heightOutput->Size = System::Drawing::Size(25, 30);
			this->heightOutput->TabIndex = 5;
			this->heightOutput->Text = L"0";
			// 
			// shurikenOutput
			// 
			this->shurikenOutput->AutoSize = true;
			this->shurikenOutput->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->shurikenOutput->Location = System::Drawing::Point(678, 122);
			this->shurikenOutput->Name = L"shurikenOutput";
			this->shurikenOutput->Size = System::Drawing::Size(25, 30);
			this->shurikenOutput->TabIndex = 6;
			this->shurikenOutput->Text = L"0";
			// 
			// jetOutput
			// 
			this->jetOutput->AutoSize = true;
			this->jetOutput->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->jetOutput->Location = System::Drawing::Point(676, 187);
			this->jetOutput->Name = L"jetOutput";
			this->jetOutput->Size = System::Drawing::Size(25, 30);
			this->jetOutput->TabIndex = 7;
			this->jetOutput->Text = L"0";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(878, 664);
			this->Controls->Add(this->jetOutput);
			this->Controls->Add(this->shurikenOutput);
			this->Controls->Add(this->heightOutput);
			this->Controls->Add(this->jetpackLabel);
			this->Controls->Add(this->shurikenLabel);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->heightLabel);
			this->Controls->Add(this->gameOutput);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//********************************************
	//Load Initializes the game manager and Random
	//********************************************
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		Left = 0;
		Top = 0;
		rand = gcnew Random();
		myGameManager = gcnew GameManager(gameOutput->CreateGraphics(), rand, shurikenOutput, jetOutput, heightOutput);
	}
	
	//**************************************
	//KeyDown handles the player key presses
	//**************************************
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{		 
		 //player left input
		 if(e->KeyCode == Keys::Left)
			 myGameManager->GetPlayerInput(LEFT);
		
		 //player right input
		 else if(e->KeyCode == Keys::Right)
			 myGameManager->GetPlayerInput(RIGHT);
		
		 //player up input (performs jump)
		 else if(e->KeyCode == Keys::Up)
			 myGameManager->GetPlayerInput(JUMP);
		 
		 //player q input (throws shuriken)
		 else if(e->KeyCode == Keys::Q)
			 myGameManager->PlayerThrowShuriken();
		 
		 //player x input (uses jetpack)
		 else if(e->KeyCode == Keys::W)
			 myGameManager->PlayerUseJetPack();
	}
	
	//*************************************************************************
	//Tick calls the GameManager's TimerTick function when the gameTimer ticks.
	//this powers the game cycle.
	//*************************************************************************
	private: System::Void gameTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		myGameManager->TimerTick();
	}
	
	//**************************************************************************
	//KeyUp determines if the player is no longer holding the left or right key.  
	//Tells the game manager to stop moving the player in that direction.
	//**************************************************************************
	private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		if(e->KeyCode == Keys::Left || e->KeyCode == Keys::Right)
			myGameManager->PlayerKeyUp();
	}
	
	//*****************************************************************************************
	//Click starts the game when the player clicks the start button(which is actually a label).
	//*****************************************************************************************
	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		gameTimer->Enabled = false;
		shurikenOutput->Text = "0";
		jetOutput->Text = "0";
		heightOutput->Text = "0";
		myGameManager = gcnew GameManager(gameOutput->CreateGraphics(), rand, shurikenOutput, jetOutput, heightOutput);
		gameTimer->Enabled = true;
	}
};
}

