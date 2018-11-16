#pragma once

#include "IInput.h"
#include "Matrix.h"

namespace Matrix {

	class InputFile : public IInput
	{
	public:
		InputFile();
		~InputFile();
		std::string Get();

		std::string fileName;
	};
}
