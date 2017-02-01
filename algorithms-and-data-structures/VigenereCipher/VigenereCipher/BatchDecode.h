#pragma once
#include "VigenereWorker.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class BatchDecode
{
private:
	
	static String^ OUTPUT_FILE = "decodeFile.txt";
	static String^ FAIL_MSG = "decode failed, check file path/format";
	static String^ FINISH_MSG = "file has finished decoding, check decodeFile.txt";	
	static String^ ENCRYPT_WRITE = "Encrypted: ";
	static String^ KEY_WRITE = "\r\nKey: ";
	static String^ DECODED_WRITE = "\r\nDecoded: ";
	static String^ END_SECTION_WRITE = "\r\n\r\n";

	void writeDecodeFile(ArrayList^ keys, ArrayList^  messages);

	/***************************************************************
	 *Precondition:  The BatchDecode::writeDecodeFile method must 
	 *				 successfully finish writing a decoded text file.
	 *
	 *Postcondition: A messagebox will display the FINISH_MSG string.
	 ***************************************************************/
	void displayFinish(){ MessageBox::Show(FINISH_MSG); };

	/***********************************************************************
	 *Precondition:  The BatchDecode::decode method must throw an exception.
	 *
	 *Postcondition: A messagebox will display the FAIL_MSG string.
	 **********************************************************************/
	void displayFail() { MessageBox::Show(FAIL_MSG); };
public:
	BatchDecode();
	void decode(String^ filePath);
};
