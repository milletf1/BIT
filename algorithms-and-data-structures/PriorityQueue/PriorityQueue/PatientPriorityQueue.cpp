#include "StdAfx.h"
#include "PatientPriorityQueue.h"

//Constructor
PatientPriorityQueue::PatientPriorityQueue()
{
	numberInQueue = 0;
	patientQueue = gcnew array<Patient^>(10);
}

/****************************************************************************************
 * Precondition:  The consumer needs the next patient in the queue.  The returned patient
 *				  must not be needed again after retrieval.
 *
 * Postcondition: The patient with the highest priority is removed from the patient array
 *				  and returned.  If no patients are in queue, null is returned.
 ****************************************************************************************/
Patient^ PatientPriorityQueue::pop()
{
	Patient^ myPatient = nullptr;
	
	//Check if the queue has any patients.
	if(numberInQueue > 0)
	{
		//If it does, return the patient with the highest priority and remove it from the 
		//queue.
		myPatient = patientQueue[numberInQueue - 1];
		patientQueue[numberInQueue - 1] = nullptr;
		numberInQueue--;
	}
	return myPatient;
}

/****************************************************************************************
 * Precondition:  The consumer needs the next patient in the queue. 
 *
 * Postcondition: The patient with the highest priority is returned. If no patients are 
 *				  in queue, null is returned.
 ****************************************************************************************/
Patient^ PatientPriorityQueue::peek()
{
	Patient^ myPatient = nullptr;
	
	//Check if the queue has any patients.
	if(numberInQueue > 0)
	{
		//If it does, return the patient with the highest priority.
		myPatient = patientQueue[numberInQueue - 1];
	}
	return myPatient;
}

 /****************************************************************************************
 * Precondition:  The consumer needs to add a patient to the priority queue.
 *
 * Postcondition: If there is room in the queue for the given patient, it will be placed
 *				  in the queue.  The patients position in the queue will be based on its
 *			      priority relative to the other patients already in queue.
 ****************************************************************************************/
void PatientPriorityQueue::push(Patient^ p)
{
	//Check that there is room in the queue for the given patient.
	if(numberInQueue < patientQueue->Length)
	{
		numberInQueue++;
		//If this is the only patient in the queue, put it in array slot 0.
		if(numberInQueue == 1)
		{
			patientQueue[0] = p;			
		}
		//If their are other patients in the queue, we need to order them by priority.		
		else
		{
			//Iterate through the patients in queue.
			for(int i = 0; i < numberInQueue; i++)
			{
				//Check if array slot i is null.
				if(patientQueue[i] == nullptr)
				{
					//If it is, we are at the end of the for loop, so patient p can be put in the array.
					patientQueue[i] = p;
				}
				//Check if the patient in array slot i has a higher priority that patient p.
				else if (patientQueue[i]->getPriority() > p->getPriority())
				{
					//If the patient in array slot i has the higher priority, swap it with patient p.
					Patient^ temp = p;
					p = patientQueue[i];
					patientQueue[i] = temp;
				}
			}
		}
	}
}

/****************************************************************************************
 * Precondition:  
 *
 * Postcondition: Returns true if there are no patients in queue.  Returns false if there
 *				  are patients in queue.
 ****************************************************************************************/
bool PatientPriorityQueue::isEmpty()
{	
	return numberInQueue == 0;
}

/****************************************************************************************
 * Precondition:  
 *
 * Postcondition: Returns a count of the number of patients in queue.
 ****************************************************************************************/
int PatientPriorityQueue::count()
{	
	return numberInQueue;
}