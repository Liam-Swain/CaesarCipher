#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "TextEncryption.h"



int main()
{
	Encrypt text; // creates instance of class
	text.inFileEncrypt.open("test.txt");
	text.outFile.open("crypt.txt");
	if (!text.inFileEncrypt.is_open()) // opens files that stores the text, and the output file
	{
		return -1;
	}

	text.EncryptText(text.inFileEncrypt, text.outFile); // encrypts the text and puts it in the output file
	text.inFileEncrypt.close();
	text.outFile.close();


	std::ifstream cryptText;
	std::ofstream regText;

	cryptText.open("crypt.txt"); // ***this is used to test to see if the encryption worked as intended
	regText.open("plswork.txt");

	if (!cryptText.is_open())
	{
		return -1;
	}

	text.decryptText(cryptText, regText);
	return 0;
}