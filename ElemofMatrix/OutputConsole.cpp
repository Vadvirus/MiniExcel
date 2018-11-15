#include "OutputConsole.h"
#include <iostream>

OutputConsole::OutputConsole()
{
}


OutputConsole::~OutputConsole()
{
}

void OutputConsole::ThisMatrix(std::vector <std::vector <NameElemOfMatrix::ElemOfMatrix> > v)
{
	try
	{
		std::cout << std::endl;
		for (int i = 1; i < v.size(); i++)
		{
			if (i != 1) std::cout << std::endl;
			for (int j = 1; j < v[i].size(); j++)
				if (v[i][j].GetIsText())
					std::cout << v[i][j].RemakeStrForOut() << "\t";
				else std::cout <<v[i][j].GetValue() << "\t";
		}
		std::cout << std::endl;
	}
	catch (MyException& MyE)
	{
		std::cout << MyE.what() << std::endl;
	}
}
