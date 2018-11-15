#include "OutputFile.h"
#include <fstream>


OutputFile::OutputFile()
{
}

OutputFile::~OutputFile()
{
}

void OutputFile::ThisMatrix(std::vector <std::vector <NameElemOfMatrix::ElemOfMatrix> > v)
{
	
	try
	{
		std::ofstream fout(fileName);
		fout << std::endl;
		for (int i = 1; i < v.size(); i++)
		{
			if (i != 1) fout << std::endl;
			for (int j = 1; j < v[i].size(); j++)
				if (v[i][j].GetIsText())
					fout << v[i][j].RemakeStrForOut() << "\t";
				else fout << v[i][j].GetValue() << "\t";
		}
		fout << std::endl;
	}
	catch (MyException& MyE)
	{
		std::cout << MyE.what() << std::endl;
	}
}