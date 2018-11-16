#include "InputConsole.h"
#include "MyException.h"

#include <string>
#include <iostream>



using namespace std;
namespace Matrix
{
	InputConsole::InputConsole()
	{
	}

	InputConsole::~InputConsole()
	{
	}

	string InputConsole::Get()
	{
		string s;
		try
		{
			std::cin >> s;
			return s;
		}
		catch (MyException& MyE)
		{
			std::cout << MyE.what() << std::endl;
		}
	}
}