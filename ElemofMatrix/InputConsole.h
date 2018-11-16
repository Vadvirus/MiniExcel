#pragma once
#include "IInput.h"

namespace Matrix
{
	class InputConsole : public IInput
	{
	public:
		InputConsole();
		~InputConsole();

		std::string Get();
	};
}

