#include "StdAfx.h"
#include "Patient.h"

//Constructor
Patient::Patient(String^ sName, int sPriority)
{
	name = sName;
	priority = sPriority;
}
