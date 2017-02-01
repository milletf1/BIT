#pragma once
#include "BoidManager.h"
#include "BoidDisplay.h"

namespace Assignment3Boids {

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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		BoidManager^ bm;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
			 BoidDisplay^ bd;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(95, 42);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(800, 600);
			this->panel1->TabIndex = 0;
			// 
			// timer
			// 
			this->timer->Interval = 50;
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 392);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 422);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(903, 657);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		// form load handler
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 bd = gcnew BoidDisplay(panel1->CreateGraphics(), panel1->Width, panel1->Height);
				 bm = gcnew BoidManager(0, 1015, 0, 675, gcnew Random(), bd);
				 timer->Enabled = true;
			 }//1015, 675

		// timer tick handler
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
				 bm->timerTick();
			 }

			 //Testing button click handler
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				bm->timerTick();
			 }
			 //reset
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 bm = gcnew BoidManager(0, 1015, 0, 675, gcnew Random(), bd);
			 }
};
}

