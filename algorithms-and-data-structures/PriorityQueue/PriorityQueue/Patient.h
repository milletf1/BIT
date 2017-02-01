#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*******************************************************************
 * Patient is a data model used to represent a patient.  The
 * priority attribute is used to order patients in a priority queue.
 ******************************************************************/
ref class Patient
{
private:
	String^ name;
	int priority;
public:
	Patient(String^ sName, int sPriority);

	//Getters and setters.
	String^ getName() { return name; }
	int getPriority() { return priority; }
};
