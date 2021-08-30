#include "TextEncryption.h"




void Encrypt::transformLetterToNumber(char transform, Letter& let)
{
	if (transform >= 65 && transform <= 90) // stores the ascii value for the letter and weather it is upper case or lower case
	{
		let.num = transform % 65;
		let.ID = 0;
	}

	else if (transform >= 97 && transform <= 122)
	{
		let.num = transform % 97;
		let.ID = 1;
	}
}

char Encrypt::transformNumberToLetter(Letter numberOfLetter) // encrypts the single letter to the letter 3 alphabet spaces to the left
{
	char letterFromNumber = '\0';
	int shiftNum = 3;

	if (numberOfLetter.num - shiftNum < 0)
	{
		numberOfLetter.num += 26;
	}

	numberOfLetter.num -= shiftNum;


	if (numberOfLetter.ID == 0)
	{
		letterFromNumber = numberOfLetter.num + 65 ;
	}
	else if (numberOfLetter.ID == 1)
	{
		letterFromNumber = numberOfLetter.num + 97;
	}

	return letterFromNumber;
}

void Encrypt::EncryptText(std::ifstream& inFile, std::ofstream& outFile) // encrypts the text
{
	std::string line;
	std::string encryptedLine = "";
	Letter let;
	char encryptedLetter;
	while (std::getline(inFile, line))
	{
		line = line.c_str();
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ')
			{
				encryptedLine += " ";
				continue;
			}
			transformLetterToNumber(line[i], let);
			encryptedLetter = transformNumberToLetter(let);
			encryptedLine += encryptedLetter;
		}
		outFile << encryptedLine;
		outFile << "\n";
		encryptedLine = "";
	}
}

int Encrypt::decryptLetter(char letter) // decrypts the letter by using the reverse algorithm
{
	int shiftNum = 3;
	int numberOfLetter = -1;
	int ID = -1;
	if (letter >= 65 && letter <= 90)
	{
		numberOfLetter = letter % 65;
		ID = 0;
	}
	else if (letter >= 97 && letter <= 122)
	{
		numberOfLetter = letter % 97;
		ID = 1;
	}

	if (numberOfLetter + shiftNum > 25)
	{
		numberOfLetter -= 26;
	}

	numberOfLetter += shiftNum;

	if (ID == 0)
	{
		numberOfLetter += 65;
	}
	else if (ID == 1)
	{
		numberOfLetter += 97;
	}
	
	return numberOfLetter;
}

void Encrypt::decryptText(std::ifstream& inFile, std::ofstream& outFile) // decrypts the file
{
	std::string getLine;
	std::string decryptLine = "";
	char let;
	while (std::getline(inFile, getLine))
	{
		getLine = getLine.c_str();
		for (int i = 0; i < getLine.length(); i++)
		{
			if (getLine[i] == ' ')
			{
				decryptLine += " ";
				continue;
			}
			let = decryptLetter(getLine[i]);
			decryptLine += let;
		}
		outFile << decryptLine;
		outFile << "\n";
		decryptLine = "";
	}
}