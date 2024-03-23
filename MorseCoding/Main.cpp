#include "Core/Morse.h"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		Morse morse(argv[1]);

		morse.RunFile();
	}

	return 0;
}