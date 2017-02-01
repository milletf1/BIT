#include "StdAfx.h"
#include "StringList.h"

StringList::StringList()
{
	head = nullptr;
	tail = nullptr;
}

/**
 * Precondition:  X
 *
 * Postcondition: Creates a node that contains the value paramater as a value, and adds it
 *			      to this linked list.
 */
void StringList::push(String^ value)
{
	StringNode^ newNode = gcnew StringNode(value);

	// Check if the linked list is empty.
	if(head != nullptr)
	{
		// If not, add the new node to the end of the list. 
		tail->Next = newNode;
		tail = newNode;
	}
	else
	{
		//If it is, set head and tail to the newNode.
		head = newNode;
		tail = newNode;
	}
}

/**
 * Precondition:  X
 *
 * Postcondition: Removes the first node that contains the value parmater from this list. 
 */
void StringList::remove(String^ value)
{
	// Check that the linked list is contains the value parameter.
	if(contains(value))
	{
		// Check if the first item in this list contains the delete value.
		if(head->getValue()->CompareTo(value) == 0)
		{
			// Check if the list contains only one value.
			if(tail->getValue()->CompareTo(value) == 0)
			{
				head = nullptr;
				tail = nullptr;
			}
			// If the list contains more than 1 value, set head to head's Next value.
			else
			{
				head = head->Next;
			}
		}
		// If head isn't the delete node, traverse list till either the delete value is 
		// found, or the end of the list is reached.
		else
		{
			// Node to start searching from.
			StringNode^ node = head;			
			
			// Node to delete.
			StringNode^ deleteNode;

			// Traverse the linked list till the node containing the delete value is found.
			while(node->Next->getValue()->CompareTo(value) != 0)
				node = node->Next;

			// Set the node to delete.
			deleteNode = node->Next;

			// Check if the delete node is the tail.
			if(tail == deleteNode)
				tail = node;

			// Remove the delete node from the list.
			node->Next = deleteNode->Next;
		}
	}
}

/**
 * Precondition:  X
 *
 * Postcondition: Returns a count of the total number of values in this linked list.
 */
int StringList::count()
{
	int count = 0;
	StringNode^ node = head;

	//Iterate through each node in this linked list, incrementing count on each iteration.
	while (node != nullptr)
	{
		count++;
		node = node->Next;
	}
	return count;
}

/**
 * Precondition:  X
 *
 * Postcondition: Checks if the given string parameter is contained in this linked list.
 *				  Returns a boolean value indicating the result.
 */
bool StringList::contains(String^ value) 
{
	bool hasString = false;
	StringNode^ node = head;
	
	// Iterate through each node in the linked list until the search value is found or the 
	// list ends.
	while(node != nullptr && hasString == false)
	{
		String^ nodeValue = node->getValue();

		// Check if the current nodes value is equal to the search term.
		if(nodeValue->CompareTo(value) == 0)
			hasString = true;
		
		// Get the next node if the current node's value is not the search value. 	
		else
			node = node->Next;
	}
	return hasString;
}

/**
 * Precondition:  
 *
 * Postcondition: Public function used to reverse the order of the linked list.
 */
void StringList::reverse()
{
	recurseList(head);
}

/**
 * Precondition:
 *
 * Postcondition: Recursive function used to reverse the list.
 */
void StringList::recurseList(StringNode^ n)
{
	// Check that the given node is has been initialized.
	if(n != nullptr)
	{
		// Check if the given node is the tail.
		if(n == tail)
		{
			// If node n is the tail node, switch the tail and head node.
			tail = head;			
			head = n;	
		}
		else
		{
			// Call this function with the next node.
			recurseList(n->Next);
			
			// Make the next nodes next pointer point to n (reversing the list).
			n->Next->Next = n; 

			// Set node n's next pointer to nullptr.  The previous call of this 
			// function will correctly set n's next pointer using the above line 
			// of code.
			n->Next = nullptr;
		}
	}
}

/**
 * Precondition:  
 *
 * Postcondition: Returns an array that contains every string in the list ordered from head 
 *				  to tail.
 */
array<String^>^ StringList::getList()
{
	array<String^>^ valueArray = gcnew array<String^>(count());
	StringNode^ node = head;
	int nextIndex = 0;
	
	while(node != nullptr)
	{
		String^ nodeValue = node->getValue();
		valueArray[nextIndex] = nodeValue;

		node = node->Next;
		nextIndex++;
	}
	return valueArray;
}