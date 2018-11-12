#include "Output.h"

Output::Output()
{
}


Output::Output(std::ostream &cout)
{
	try
	{
		std::cout << std::endl;
		for (int i = 1; i < Matr.size(); i++)
		{
			if (i != 1) std::cout << std::endl;
			for (int j = 1; j < Matr[i].size(); j++)
				if (Matr[i][j].GetIsText())
					std::cout << Matr[i][j].GetStrOut() << "\t";
				else std::cout << Matr[i][j].GetValue() << "\t";
		}
		std::cout << std::endl;
	}
	catch (MyException& MyE)
	{
		std::cout << MyE.what() << std::endl;
	}
}

