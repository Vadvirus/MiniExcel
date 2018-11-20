#pragma once
#include <string>

namespace Matrix
{
	class IInput
	{
	public:
		virtual ~IInput() = default;

		virtual const std::string Get() = 0;
	};
}
