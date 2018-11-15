#pragma once
#include "ElemofMatrix.h"

#include <vector>

class IOutput
{
public:
	IOutput();
	~IOutput();
	virtual void ThisMatrix(std::vector <std::vector <NameElemOfMatrix::ElemOfMatrix> > v) = 0;
};

