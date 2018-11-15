#pragma once
#include <string>
class IInput
{
public:
	~IInput()=default;
	virtual std::string Get() = 0;
};

