#include "StdAfx.h"
#include "BatchDecode.h"

BatchDecode::BatchDecode()
{}

/************************************************************************
 *Precondition:  The caller must give an array list of keys and encrypted
 *				 messages.  These lists are extracted from a text file by
 *               the encode method.
 *
 *Postcondition: A text file will be created which gives gives the result
 *				 of each key decrypting each message.
 ***********************************************************************/
void BatchDecode::writeDecodeFile(ArrayList^  keys, ArrayList^ messages)
{
	StreamWriter^ sw = gcnew StreamWriter(OUTPUT_FILE);
	VigenereWorker^ vw = gcnew VigenereWorker("");
	
	//Iterate through each key in the keys list.
	for each(Object^ key in keys)
	{
		//Set the VigenereWorker's key to the current key.
		vw->setKey(key->ToString());

		//Iterate through each message in the messages list.
		for each(Object^ msg in messages)
		{
			//Decrypt the current message and write to a string.
			String^ decodedMsg = vw->decrypt(msg->ToString());
			
			//Write the encrypted message, the key, and the decrypted message to a
			//text file.
			sw->WriteLine(ENCRYPT_WRITE + msg->ToString() + KEY_WRITE + key->ToString() + 
				DECODED_WRITE + decodedMsg + END_SECTION_WRITE);
		}
	}
	sw->Close();
	displayFinish();
}

/**************************************************************************
 *Precondition:  The user must give a path to the file that contains
 *				 the number of keys and messages (first line), a line
 *				 for each key specified by the number on the first line
 *				 (these must come after the number), and a line for each
 *				 encrypted message (after the keys' section).
 *
 *Postcondition: If the given file path either doesn't exist, or the file 
 *               is not formatted properly, the displayFail method will be
 *				 called to let the user know that the decode failed.  
 *				 If this method completes successfully, writeDecode will 
 *			     output the decryption result.
 ************************************************************************/
void BatchDecode::decode(String^ filePath)
{
	try {
		ArrayList^ keys = gcnew ArrayList();
		ArrayList^ messages  = gcnew ArrayList();
		StreamReader^ sr = gcnew StreamReader(filePath);

		//counter is used by the while loop to determine if the current
		//line is iteration total, a key, or an encrypted message.
		int counter = 0;

		//iterations is the number of keys and messages.
		int iterations = 0;		
				
		String^ s;
		while((s = sr->ReadLine()) != nullptr)
		{
			//Check the data type of the current line.
			if(counter == 0)
				//Iteration total.
				iterations = Convert::ToInt16(s);

			else if(counter / (iterations + 1) == 0)
				//Key.
				keys->Add(s);

			else if(counter / iterations == 1)
				//Encrypted message.
				messages->Add(s);
			
			counter++;			
		}
		sr->Close();
		
		writeDecodeFile(keys, messages);
	
	//Display a failure message whenever an exception is caught.
	} catch(Exception^ e){ 
		displayFail(); 
	}	
}
