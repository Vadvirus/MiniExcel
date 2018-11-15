#pragma once
#include "IOutput.h"

class OutputConsole :
	public IOutput
{
public:
	OutputConsole();
	~OutputConsole();
	void ThisMatrix(std::vector <std::vector <NameElemOfMatrix::ElemOfMatrix> > v);
	
};

