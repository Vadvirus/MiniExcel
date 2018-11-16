#include "OutputConsole.h"
#include <iostream>

namespace Matrix
{

	OutputConsole::OutputConsole()
	{
	}


	OutputConsole::~OutputConsole()
	{
	}

	void OutputConsole::ThisMatrix(std::vector <std::vector <Matrix::ElemOfMatrix> > matrix)
	{
		try
		{
			std::cout << std::endl;
			for (int i = 1; i < matrix.size(); i++)
			{
				if (i != 1) std::cout << std::endl;
				for (int j = 1; j < matrix[i].size(); j++)
					if (matrix[i][j].GetIsText())
						std::cout << matrix[i][j].RemakeStrForOut() << "\t";
					else std::cout << matrix[i][j].GetValue() << "\t";
			}
			std::cout << std::endl;
		}
		catch (MyException& MyE)
		{
			std::cout << MyE.what() << std::endl;
		}
	}
}