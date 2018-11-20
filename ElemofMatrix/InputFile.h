#pragma once

#include "IInput.h"
#include "Matrix.h"

namespace Matrix {

	class InputFile : public IInput
	{
	public:
		InputFile(std::string filename);
		InputFile();
		~InputFile();
		const std::string Get();

		std::string fileName;
	};
}
