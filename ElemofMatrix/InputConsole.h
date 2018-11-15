#pragma once
#include "IInput.h"
class InputConsole :
	public IInput
{
public:
	InputConsole();
	~InputConsole();
	std::string Get();
};


