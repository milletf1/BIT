#pragma once
#include "DragonCurve.h"
#include "KochSnowflake.h"
#include "PythagoreanTree.h"
#include "SierpinskiTriangle.h"
#include "sierpinskiCarpet.h"

namespace FractalsAssignment {

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
	private: System::Windows::Forms::Panel^  displayOutput;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  rbSnowflake;
	private: System::Windows::Forms::RadioButton^  rbDragonCurve;
	private: System::Windows::Forms::RadioButton^  rbTree;
	private: System::Windows::Forms::RadioButton^  rbTriangle;
	private: System::Windows::Forms::RadioButton^  rbCarpet;

	private: System::Windows::Forms::NumericUpDown^  depthSelector;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnGenerate;



	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Thread^ fractalThread;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->displayOutput = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->rbCarpet = (gcnew System::Windows::Forms::RadioButton());
			this->rbTriangle = (gcnew System::Windows::Forms::RadioButton());
			this->rbTree = (gcnew System::Windows::Forms::RadioButton());
			this->rbDragonCurve = (gcnew System::Windows::Forms::RadioButton());
			this->rbSnowflake = (gcnew System::Windows::Forms::RadioButton());
			this->depthSelector = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->depthSelector))->BeginInit();
			this->SuspendLayout();
			// 
			// displayOutput
			// 
			this->displayOutput->BackColor = System::Drawing::Color::Black;
			this->displayOutput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayOutput->Location = System::Drawing::Point(145, 13);
			this->displayOutput->Name = L"displayOutput";
			this->displayOutput->Size = System::Drawing::Size(700, 700);
			this->displayOutput->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Fractal:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->rbCarpet);
			this->panel1->Controls->Add(this->rbTriangle);
			this->panel1->Controls->Add(this->rbTree);
			this->panel1->Controls->Add(this->rbDragonCurve);
			this->panel1->Controls->Add(this->rbSnowflake);
			this->panel1->Location = System::Drawing::Point(17, 52);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(122, 125);
			this->panel1->TabIndex = 2;
			// 
			// rbCarpet
			// 
			this->rbCarpet->AutoSize = true;
			this->rbCarpet->ForeColor = System::Drawing::Color::White;
			this->rbCarpet->Location = System::Drawing::Point(4, 96);
			this->rbCarpet->Name = L"rbCarpet";
			this->rbCarpet->Size = System::Drawing::Size(104, 17);
			this->rbCarpet->TabIndex = 4;
			this->rbCarpet->Text = L"Sierpinski Carpet";
			this->rbCarpet->UseVisualStyleBackColor = true;
			// 
			// rbTriangle
			// 
			this->rbTriangle->AutoSize = true;
			this->rbTriangle->ForeColor = System::Drawing::Color::White;
			this->rbTriangle->Location = System::Drawing::Point(4, 73);
			this->rbTriangle->Name = L"rbTriangle";
			this->rbTriangle->Size = System::Drawing::Size(111, 17);
			this->rbTriangle->TabIndex = 3;
			this->rbTriangle->Text = L"Sierpinski Triangle";
			this->rbTriangle->UseVisualStyleBackColor = true;
			// 
			// rbTree
			// 
			this->rbTree->AutoSize = true;
			this->rbTree->ForeColor = System::Drawing::Color::White;
			this->rbTree->Location = System::Drawing::Point(4, 50);
			this->rbTree->Name = L"rbTree";
			this->rbTree->Size = System::Drawing::Size(110, 17);
			this->rbTree->TabIndex = 2;
			this->rbTree->Text = L"Pythagorean Tree";
			this->rbTree->UseVisualStyleBackColor = true;
			// 
			// rbDragonCurve
			// 
			this->rbDragonCurve->AutoSize = true;
			this->rbDragonCurve->ForeColor = System::Drawing::Color::White;
			this->rbDragonCurve->Location = System::Drawing::Point(4, 27);
			this->rbDragonCurve->Name = L"rbDragonCurve";
			this->rbDragonCurve->Size = System::Drawing::Size(91, 17);
			this->rbDragonCurve->TabIndex = 1;
			this->rbDragonCurve->Text = L"Dragon Curve";
			this->rbDragonCurve->UseVisualStyleBackColor = true;
			// 
			// rbSnowflake
			// 
			this->rbSnowflake->AutoSize = true;
			this->rbSnowflake->Checked = true;
			this->rbSnowflake->ForeColor = System::Drawing::Color::White;
			this->rbSnowflake->Location = System::Drawing::Point(4, 4);
			this->rbSnowflake->Name = L"rbSnowflake";
			this->rbSnowflake->Size = System::Drawing::Size(103, 17);
			this->rbSnowflake->TabIndex = 0;
			this->rbSnowflake->TabStop = true;
			this->rbSnowflake->Text = L"Koch Snowflake";
			this->rbSnowflake->UseVisualStyleBackColor = true;
			// 
			// depthSelector
			// 
			this->depthSelector->Location = System::Drawing::Point(17, 226);
			this->depthSelector->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {25, 0, 0, 0});
			this->depthSelector->Name = L"depthSelector";
			this->depthSelector->Size = System::Drawing::Size(122, 20);
			this->depthSelector->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(13, 189);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Depth:";
			// 
			// btnGenerate
			// 
			this->btnGenerate->Location = System::Drawing::Point(17, 269);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(122, 23);
			this->btnGenerate->TabIndex = 5;
			this->btnGenerate->Text = L"Generate Fractal";
			this->btnGenerate->UseVisualStyleBackColor = true;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &Form1::btnGenerate_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(857, 724);
			this->Controls->Add(this->btnGenerate);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->depthSelector);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->displayOutput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->depthSelector))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		// Generate Fractal button click handler.
	private: System::Void btnGenerate_Click(System::Object^  sender, System::EventArgs^  e) {
				
				// Abort the fractal thread.
				abortThread();
				fractalThread = nullptr;

				// Create a graphics canvas.
				Graphics^ canvas = displayOutput->CreateGraphics();

				// Clear the display panel.
				canvas->Clear(displayOutput->BackColor);

				/**
				 * Determine the chosen fractal and draw it.
				 */
				// Dragon curve.
				if(rbDragonCurve->Checked)
				{
					DragonCurve^ dc = gcnew DragonCurve(canvas);

					fractalThread = gcnew Thread(
						gcnew ParameterizedThreadStart(dc, &DragonCurve::generateDragonCurve)
					);
				}
				// Koch snowflake.
				else if(rbSnowflake->Checked)
				{
					KochSnowflake^ ksf = gcnew KochSnowflake(canvas);

					fractalThread = gcnew Thread(
						gcnew ParameterizedThreadStart(ksf, &KochSnowflake::generateSnowflake)
					);
				}
				// Pythagorean tree.
				else if(rbTree->Checked)
				{
					PythagoreanTree^ pt = gcnew PythagoreanTree(canvas);

					fractalThread = gcnew Thread(
						gcnew ParameterizedThreadStart(pt, &PythagoreanTree::generateTree)
					);
				}
				// Sierpinski triangle.
				else if(rbTriangle->Checked)
				{
					SierpinskiTriangle^ st = gcnew SierpinskiTriangle(canvas);

					fractalThread = gcnew Thread(
						gcnew ParameterizedThreadStart(st, &SierpinskiTriangle::generateTriangle)
					);
				}	
				// Sierpinski carpet.
				else if(rbCarpet->Checked)
				{
					SierpinskiCarpet^ sc = gcnew SierpinskiCarpet(canvas);

					fractalThread = gcnew Thread(
						gcnew ParameterizedThreadStart(sc, &SierpinskiCarpet::generateCarpet)
					);
				}

				// Start fractal thread.
				if(fractalThread != nullptr)
					startThread();
			 }


			 // Start fractal thread handler.
	private: void startThread()
		{
			int depth = (int)depthSelector->Value;
			fractalThread->Start(depth);
		}
			 //End fractal thread handler
	private: void abortThread()
		{
			// Check if the fractal thread is running and needs to be aborted.
			if(fractalThread != nullptr && fractalThread->IsAlive)			
				fractalThread->Abort();
		}

		// Form closing handler.
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		{				 
			abortThread();
		}
};
}

