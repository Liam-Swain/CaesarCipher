#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Encrypt // encryption class
{
public:
	typedef struct Letter // struct for each letter, num is the ascii value for the char, Id is if it is uppercase or not
	{
		int num;
		int ID;
	}Letter;
	std::ofstream outFile;
	std::ifstream inFileEncrypt;
	std::ofstream test;
	void EncryptText(std::ifstream& inFile, std::ofstream& outFile); // encyrpts the text
	void transformLetterToNumber(char transform, Letter& let); // transforms every number between 0-25
	char transformNumberToLetter(Letter number); // encrypts the letter 
	void decryptText(std::ifstream& inFile, std::ofstream& outFile); // decrypts the contents of the file
	int decryptLetter(char letter); // decrypts the letter by applying the reverse algorithm for encryption
};