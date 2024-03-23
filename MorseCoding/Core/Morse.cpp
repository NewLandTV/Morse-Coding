#include <iostream>
#include <fstream>
#include "Morse.h"

#define LINE_BUFFER_SIZE 1024

const char* Morse::MorseCodeToCharacter(std::string morseCode)
{
	bool upperCase = false;

	// Upper case
	if (morseCode[0] == '_')
	{
		upperCase = true;

		morseCode.erase(morseCode.begin());
	}

	// Alphabets
	if (morseCode == ".-")
	{
		return upperCase ? "A" : "a";
	}
	else if (morseCode == "-...")
	{
		return upperCase ? "B" : "b";
	}
	else if (morseCode == "-.-.")
	{
		return upperCase ? "C" : "c";
	}
	else if (morseCode == "-..")
	{
		return upperCase ? "D" : "d";
	}
	else if (morseCode == ".")
	{
		return upperCase ? "E" : "e";
	}
	else if (morseCode == "..-.")
	{
		return upperCase ? "F" : "f";
	}
	else if (morseCode == "--.")
	{
		return upperCase ? "G" : "g";
	}
	else if (morseCode == "....")
	{
		return upperCase ? "H" : "h";
	}
	else if (morseCode == "..")
	{
		return upperCase ? "I" : "i";
	}
	else if (morseCode == ".---")
	{
		return upperCase ? "J" : "j";
	}
	else if (morseCode == "-.-")
	{
		return upperCase ? "K" : "k";
	}
	else if (morseCode == ".-..")
	{
		return upperCase ? "L" : "l";
	}
	else if (morseCode == "--")
	{
		return upperCase ? "M" : "m";
	}
	else if (morseCode == "-.")
	{
		return upperCase ? "N" : "n";
	}
	else if (morseCode == "---")
	{
		return upperCase ? "O" : "o";
	}
	else if (morseCode == ".--.")
	{
		return upperCase ? "P" : "p";
	}
	else if (morseCode == "--.-")
	{
		return upperCase ? "Q" : "q";
	}
	else if (morseCode == ".-.")
	{
		return upperCase ? "R" : "r";
	}
	else if (morseCode == "...")
	{
		return upperCase ? "S" : "s";
	}
	else if (morseCode == "-")
	{
		return upperCase ? "T" : "t";
	}
	else if (morseCode == "..-")
	{
		return upperCase ? "U" : "u";
	}
	else if (morseCode == "...-")
	{
		return upperCase ? "V" : "v";
	}
	else if (morseCode == ".--")
	{
		return upperCase ? "W" : "w";
	}
	else if (morseCode == "-..-")
	{
		return upperCase ? "X" : "x";
	}
	else if (morseCode == "-.--")
	{
		return upperCase ? "Y" : "y";
	}
	else if (morseCode == "--..")
	{
		return upperCase ? "Z" : "z";
	}

	// Numbers
	else if (morseCode == "-----")
	{
		return "0";
	}
	else if (morseCode == ".----")
	{
		return "1";
	}
	else if (morseCode == "..---")
	{
		return "2";
	}
	else if (morseCode == "...--")
	{
		return "3";
	}
	else if (morseCode == "....-")
	{
		return "4";
	}
	else if (morseCode == ".....")
	{
		return "5";
	}
	else if (morseCode == "-....")
	{
		return "6";
	}
	else if (morseCode == "--...")
	{
		return "7";
	}
	else if (morseCode == "---..")
	{
		return "8";
	}
	else if (morseCode == "----.")
	{
		return "9";
	}

	// Signs
	else if (morseCode == "-.-.--")
	{
		return "!";
	}
	else if (morseCode == ".--.-.")
	{
		return "@";
	}
	else if (morseCode == "-.--.")
	{
		return "(";
	}
	else if (morseCode == "-.--.-")
	{
		return ")";
	}
	else if (morseCode == ".-.-.-")
	{
		return ".";
	}
	else if (morseCode == ".----.")
	{
		return "\'";
	}
	else if (morseCode == ".-..-.")
	{
		return "\"";
	}
	else if (morseCode == "-...-")
	{
		return "=";
	}
	else if (morseCode == "--..--")
	{
		return ",";
	}
	else if (morseCode == "...+.--.+.-+-.-.+.")
	{
		return " ";
	}

	return nullptr;
}

Morse::Morse(char* filePath) : data()
{
	std::ifstream file;

	file.open(filePath);

	if (!file.is_open())
	{
		return;
	}

	for (char line[LINE_BUFFER_SIZE]; !file.eof();)
	{
		file.getline(line, LINE_BUFFER_SIZE);

		if (file.fail())
		{
			break;
		}

		char* context = nullptr;
		
		for (char* ptr = strtok_s(line, " ", &context); ptr != nullptr; ptr = strtok_s(nullptr, " ", &context))
		{
			data += MorseCodeToCharacter(ptr);
		}

		data += "\n";
	}

	file.close();

	std::cout << data << std::endl;
}

void Morse::RunFile()
{
	std::ofstream file;

	file.open("Temp.py");
	file.write(data.c_str(), data.size());
	file.close();

	system("Python Temp.py");
	remove("Temp.py");
}