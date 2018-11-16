#pragma once

#include <vector>

#include "ElemofMatrix.h"

namespace Matrix
{
	class IOutput
	{
	public:
		virtual ~IOutput() = default;

		virtual void ThisMatrix(std::vector <std::vector <ElemOfMatrix> > matrix) = 0;
	};
}
