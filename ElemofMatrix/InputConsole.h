#pragma once
#include "IInput.h"

namespace Matrix
{
	class InputConsole : public IInput
	{
	public:
	
		const std::string Get();
	};
}

