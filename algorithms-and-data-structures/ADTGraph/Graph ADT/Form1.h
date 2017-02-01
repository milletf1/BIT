#pragma once

#include "Graph.h"

namespace GraphADT {

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
	private: System::Windows::Forms::Button^  btnDraw;
	protected: 



	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ListBox^  listBox1;




			 Graph^ mainGraph;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnDraw
			// 
			this->btnDraw->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->btnDraw->Location = System::Drawing::Point(11, 11);
			this->btnDraw->Margin = System::Windows::Forms::Padding(2);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(128, 33);
			this->btnDraw->TabIndex = 0;
			this->btnDraw->Text = L"Make Demo Graph";
			this->btnDraw->UseVisualStyleBackColor = false;
			this->btnDraw->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(777, 100);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(316, 342);
			this->listBox1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Honeydew;
			this->ClientSize = System::Drawing::Size(1181, 570);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->btnDraw);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				Refresh();
			
				mainGraph = gcnew Graph(8,CreateGraphics());
				mainGraph->makeDemoGraph();
				mainGraph->drawGraph();
				mainGraph->traverseGraph(listBox1);
			 }
	
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				Left = 0;
				Top = 0;
			 }
};
}

