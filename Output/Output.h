#pragma once
#include "C:\Users\user\Documents\OOP_test\ElemofMatrix\Matr.h"
#include "C:\Users\user\Documents\OOP_test\MyException\MyException.h"
#include <fstream>

class Output
{
public:
	Output();
	Output(std::ofstream &fout, std::string FileName);
	Output(std::ostream &cout);
	~Output();
	bool IsFile(std::string filename);
};

