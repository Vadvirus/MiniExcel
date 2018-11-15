#pragma once
#include "IOutput.h"
class OutputFile :
	public IOutput
{
public:
	OutputFile();
	~OutputFile();
	void ThisMatrix(std::vector <std::vector <NameElemOfMatrix::ElemOfMatrix> > v);
	std::string fileName;
};

