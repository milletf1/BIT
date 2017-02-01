#pragma once
#include "Patient.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*************************************************************************
 *	PatientPriorityQueue is a priority queue that manages Patient objects.
 ************************************************************************/
ref class PatientPriorityQueue
{
private: 
	int numberInQueue;
	array<Patient^>^ patientQueue;

public:
	PatientPriorityQueue();

	Patient^ pop();
	Patient^ peek();
	void push(Patient^ p);

	bool isEmpty();
	int count();
	
	//Getters and setters
	array<Patient^>^ getPatientQueue() { return patientQueue; }
};
