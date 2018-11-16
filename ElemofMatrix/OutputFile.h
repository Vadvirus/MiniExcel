#pragma once

#include "IOutput.h"

namespace Matrix
{
	class OutputFile : public IOutput
	{
	public:
		OutputFile();
		~OutputFile();

		void ThisMatrix(std::vector <std::vector <ElemOfMatrix> > matrix);
		std::string fileName;
	};
}