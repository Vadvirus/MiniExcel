#include "InputConsole.h"
#include "MyException.h"

#include <string>
#include <iostream>



using namespace std;
namespace Matrix
{

	const string InputConsole::Get()
	{
		string s;
		
			std::cin >> s;
			return s;
	}
}