#pragma once
#include <string>
class IInput
{
public:
	IInput();
	~IInput();
	virtual std::string Get() = 0;
};

