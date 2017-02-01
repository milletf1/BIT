#pragma once
#include "Patient.h"
#include "PatientPriorityQueue.h"

namespace PriorityQueue {

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
	private: System::Windows::Forms::ListBox^  lbPatientList;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbPushPatient;

	private: System::Windows::Forms::NumericUpDown^  numPatientPriority;
	private: System::Windows::Forms::Button^  btnPushPatient;
	private: System::Windows::Forms::TextBox^  tbPopPatient;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  btnPopPatient;
	private: System::Windows::Forms::Button^  btnPeekPatient;
	private: System::Windows::Forms::TextBox^  tbPeekPatient;
	private: System::Windows::Forms::Label^  label8;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		
		static String^ QUEUE_FULL_MSG = "The queue is full.";
		static String^ QUEUE_EMPTY_MSG = "The queue is empty.";	
		PatientPriorityQueue^ patientQueue;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbPatientList = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbPushPatient = (gcnew System::Windows::Forms::TextBox());
			this->numPatientPriority = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnPushPatient = (gcnew System::Windows::Forms::Button());
			this->tbPopPatient = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnPopPatient = (gcnew System::Windows::Forms::Button());
			this->btnPeekPatient = (gcnew System::Windows::Forms::Button());
			this->tbPeekPatient = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numPatientPriority))->BeginInit();
			this->SuspendLayout();
			// 
			// lbPatientList
			// 
			this->lbPatientList->FormattingEnabled = true;
			this->lbPatientList->Location = System::Drawing::Point(13, 34);
			this->lbPatientList->Name = L"lbPatientList";
			this->lbPatientList->Size = System::Drawing::Size(181, 212);
			this->lbPatientList->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(228, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Push";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(465, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Pop";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(465, 128);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Peek";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Patients";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(232, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Name:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(229, 94);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Priority:";
			// 
			// tbPushPatient
			// 
			this->tbPushPatient->Location = System::Drawing::Point(232, 51);
			this->tbPushPatient->Name = L"tbPushPatient";
			this->tbPushPatient->Size = System::Drawing::Size(181, 20);
			this->tbPushPatient->TabIndex = 7;
			// 
			// numPatientPriority
			// 
			this->numPatientPriority->Location = System::Drawing::Point(232, 116);
			this->numPatientPriority->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numPatientPriority->Name = L"numPatientPriority";
			this->numPatientPriority->Size = System::Drawing::Size(181, 20);
			this->numPatientPriority->TabIndex = 8;
			this->numPatientPriority->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// btnPushPatient
			// 
			this->btnPushPatient->Location = System::Drawing::Point(232, 157);
			this->btnPushPatient->Name = L"btnPushPatient";
			this->btnPushPatient->Size = System::Drawing::Size(178, 23);
			this->btnPushPatient->TabIndex = 9;
			this->btnPushPatient->Text = L"Add Patient";
			this->btnPushPatient->UseVisualStyleBackColor = true;
			this->btnPushPatient->Click += gcnew System::EventHandler(this, &Form1::btnPushPatient_Click);
			// 
			// tbPopPatient
			// 
			this->tbPopPatient->Location = System::Drawing::Point(466, 51);
			this->tbPopPatient->Name = L"tbPopPatient";
			this->tbPopPatient->Size = System::Drawing::Size(181, 20);
			this->tbPopPatient->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(466, 34);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Name:";
			// 
			// btnPopPatient
			// 
			this->btnPopPatient->Location = System::Drawing::Point(466, 94);
			this->btnPopPatient->Name = L"btnPopPatient";
			this->btnPopPatient->Size = System::Drawing::Size(178, 23);
			this->btnPopPatient->TabIndex = 12;
			this->btnPopPatient->Text = L"Get Patient";
			this->btnPopPatient->UseVisualStyleBackColor = true;
			this->btnPopPatient->Click += gcnew System::EventHandler(this, &Form1::btnPopPatient_Click);
			// 
			// btnPeekPatient
			// 
			this->btnPeekPatient->Location = System::Drawing::Point(467, 217);
			this->btnPeekPatient->Name = L"btnPeekPatient";
			this->btnPeekPatient->Size = System::Drawing::Size(178, 23);
			this->btnPeekPatient->TabIndex = 15;
			this->btnPeekPatient->Text = L"View Patient";
			this->btnPeekPatient->UseVisualStyleBackColor = true;
			this->btnPeekPatient->Click += gcnew System::EventHandler(this, &Form1::btnPeekPatient_Click);
			// 
			// tbPeekPatient
			// 
			this->tbPeekPatient->Location = System::Drawing::Point(467, 174);
			this->tbPeekPatient->Name = L"tbPeekPatient";
			this->tbPeekPatient->Size = System::Drawing::Size(181, 20);
			this->tbPeekPatient->TabIndex = 14;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(467, 157);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(38, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Name:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 262);
			this->Controls->Add(this->btnPeekPatient);
			this->Controls->Add(this->tbPeekPatient);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->btnPopPatient);
			this->Controls->Add(this->tbPopPatient);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btnPushPatient);
			this->Controls->Add(this->numPatientPriority);
			this->Controls->Add(this->tbPushPatient);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbPatientList);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Form1";
			this->Text = L"PriorityQueue";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numPatientPriority))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		//Form Load handler.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			{
				this->Left = 0;
				this->Top = 0;
				patientQueue = gcnew PatientPriorityQueue();
			}
	
		//Push Patient button click event handler.
	private: System::Void btnPushPatient_Click(System::Object^  sender, System::EventArgs^  e) 
			{	
				pushPatient();				
			}
	
		//Peek Patient button click event handler.
	private: System::Void btnPeekPatient_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				peekPatient();				
			}

		//Pop Patient button click event handler.
	private: System::Void btnPopPatient_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				popPatient();				
			}

	 /****************************************************************************************
	 * Precondition:  The number of patients in patientQueue's patient array should have 
	 *				  changed due to a patient being either pushed or popped from the patient	
	 *				  queue.
	 *
	 * Postcondition: Displays the patients and their priorities in the lbPatient list box.
	 ***************************************************************************************/
	void displayPatients()
	{		
		lbPatientList->Items->Clear();
		array<Patient^>^ patients = patientQueue->getPatientQueue();

		//Iterate through the patients in queue.
		for(int i = patients->Length - 1; i >= 0; i--)
		{
			//Check that the current array slot has a patient.
			if(patients[i] != nullptr)
			{
				//Display the patient.
				String^ patientDetails = patients[i]->getName() + "\t"
					+ Convert::ToString(patients[i]->getPriority());
				lbPatientList->Items->Add(patientDetails);
			}
		}
	}

	/*****************************************************************************************
	 * Precondition:  The user must have clicked on the btnPushPatient button.
	 *
	 * Postcondition: Creates a new patient with a name equal to the text in the tbPushPatient
	 *				  text box and a priority equal to the decimal in the numPatientPriorty
	 *				  numeric up/down selector.  This patient is pushed to the patient queue.
	 *				  and the patients in queue are displayed in the lbPatient list box.
	 ****************************************************************************************/
	void pushPatient()
	{
		//Check that there is room for the new patient in the queue.
		if(patientQueue->count() < patientQueue->getPatientQueue()->Length)
		{
			//Put the new patient's details into local variables.
			String^ patientName = tbPushPatient->Text;
			int patientPriority = (int)numPatientPriority->Value;

			//Create a new patient and add to patientQueue.
			Patient^ newPatient = gcnew Patient(patientName, patientPriority);
			patientQueue->push(newPatient);

			//Display updated patient queue.
			displayPatients();
		}
		else
		{			
			MessageBox::Show(QUEUE_FULL_MSG);
		}
	}

	/****************************************************************************************
	 * Precondition:  The user must have clicked on the btnPeekPatient button.
	 *
	 * Postcondition: Displays the patient with the highest priority in the patient queue
	 *				  in the tbPatientPeek text box.
	 ***************************************************************************************/
	void peekPatient()
	{
		//Check that there is a patient in the queue.
		if(!patientQueue->isEmpty())
		{
			Patient^ patient = patientQueue->peek();
			String^ patientName = patient->getName();
			tbPeekPatient->Text = patientName;
		} 
		else
		{
			MessageBox::Show(QUEUE_EMPTY_MSG);
		}
	}

	/****************************************************************************************
	 * Precondition:  The user must have clicked on the btnPopPatient button.
	 *
	 * Postcondition: Displays the patient with the highest priority in the patient queue
	 *				  in the tbPatientPop text box.  This patient is removed from the queue,
	 *				  the remaining patients are displayed lbPatient list box.
	 ***************************************************************************************/
	void popPatient() 
	{
		//Check that there is a patient in the queue.
		if(!patientQueue->isEmpty())
		{
			Patient^ patient = patientQueue->pop();
			String^ patientName = patient->getName();
			tbPopPatient->Text = patientName;				 
			displayPatients();
		} 
		else
		{
			MessageBox::Show(QUEUE_EMPTY_MSG);
		}
	}
};
}

