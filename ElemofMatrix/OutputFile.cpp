#include "OutputFile.h"
#include <fstream>

namespace Matrix
{
	OutputFile::OutputFile()
	{
	}

	OutputFile::~OutputFile()
	{
	}

	void OutputFile::ThisMatrix(std::vector <std::vector <ElemOfMatrix> > matrix)
	{

		try
		{
			std::ofstream fout(fileName);
			fout << std::endl;
			for (int i = 1; i < matrix.size(); i++)
			{
				if (i != 1) fout << std::endl;
				for (int j = 1; j < matrix[i].size(); j++)
					if (matrix[i][j].GetIsText())
						fout << matrix[i][j].RemakeStrForOut() << "\t";
					else fout << matrix[i][j].GetValue() << "\t";
			}
			fout << std::endl;
		}
		catch (MyException& MyE)
		{
			std::cout << MyE.what() << std::endl;
		}
	}
}