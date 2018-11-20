#include "InputFile.h"
#include <fstream>

using namespace std;

namespace Matrix
{

	InputFile::InputFile(std::string filename):fileName(filename)
	{

	}

	InputFile::InputFile()
	{

	}

	InputFile::~InputFile()
	{
	}

	const string InputFile::Get()
	{
		ifstream fin(fileName);
		string s;

		try
		{
			fin >> s;
			return s;
		}
		catch (MyException& MyE)
		{
			std::cout << MyE.what() << std::endl;
		}

	}
}
