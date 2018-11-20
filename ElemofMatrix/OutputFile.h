#pragma once

#include "IOutput.h"

namespace Matrix
{
	class OutputFile : public IOutput
	{
	public:
		OutputFile(std::string filename);
		OutputFile();
		~OutputFile();

		void ThisMatrix(std::vector <std::vector <ElemOfMatrix> > matrix);
		std::string fileName;
	};
}