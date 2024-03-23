#ifndef __MORSE_H__
#define __MORSE_H__

#include <string>

class Morse
{
private:
	std::string data;

	const char* MorseCodeToCharacter(std::string morseCode);

public:
	Morse(char* filePath);

	void RunFile();
};

#endif