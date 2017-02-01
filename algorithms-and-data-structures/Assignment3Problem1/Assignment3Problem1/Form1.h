#pragma once

#define FB_START 1
#define FB_END 100

#define FIZZ_MOD 3
#define BUZZ_MOD 5

namespace Assignment3Problem1 {

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
	private: System::Windows::Forms::ListBox^  displayOutput;
	private: System::Windows::Forms::Button^  btnRun;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		static String^ FIZZ = "Fizz";
		static String^ BUZZ = "Buzz";

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->displayOutput = (gcnew System::Windows::Forms::ListBox());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(27, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"FizzBuzz";
			// 
			// displayOutput
			// 
			this->displayOutput->FormattingEnabled = true;
			this->displayOutput->Location = System::Drawing::Point(13, 38);
			this->displayOutput->Name = L"displayOutput";
			this->displayOutput->Size = System::Drawing::Size(134, 303);
			this->displayOutput->TabIndex = 1;
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(13, 348);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(134, 23);
			this->btnRun->TabIndex = 2;
			this->btnRun->Text = L"Run FizzBuzz";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(159, 378);
			this->Controls->Add(this->btnRun);
			this->Controls->Add(this->displayOutput);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		// Run FizzBuzz button click handler.
	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				displayOutput->Items->Clear();
				fizzBuzz();
			 
			}

	/**
	 * Precondition:  FB_START must be less than FB_END
	 * 
	 * Postcondition: Displays a count from FB_START to FB_END.  For each
	 *				  integer that is a multiple of 3, displays Fizz instead
	 *				  of the integer.  For each integer that is a multiple of 5, 
	 *				  displays Buzz instead of the integer.  Integers that are 
	 *				  a multiple of both 3 and 5 will display FizzBuzz.
	 */
	private: System::Void fizzBuzz() 
			{
				for(int i = FB_START; i <= FB_END; i++)
				{
					String^ s = "";
					
					// Check if i is a multiple of 3.
					if(i % FIZZ_MOD == 0)
						s += FIZZ;

					// Check if i is a multiple of 5.
					if(i % BUZZ_MOD == 0)
						s += BUZZ;

					// Check if we need to display i.  This occurs when
					// i is not a multiple of 3 or 5.
					if(String::IsNullOrEmpty(s))
						s = Convert::ToString(i);

					displayOutput->Items->Add(s);
				}
			}
	};
}

