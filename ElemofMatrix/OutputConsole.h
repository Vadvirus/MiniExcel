#pragma once
#include "IOutput.h"

namespace Matrix {

	class OutputConsole : public IOutput
	{
	public:
		OutputConsole();
		~OutputConsole();
		void ThisMatrix(std::vector <std::vector <ElemOfMatrix> > matrix);
	};
}
