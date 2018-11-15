#pragma once

#include <string>
#include <vector>

#include "MyException.h"

namespace NameElemOfMatrix
{
	class ElemOfMatrix
	{
	public:
		ElemOfMatrix(std::string str, int posX, int posY);
		ElemOfMatrix();
		~ElemOfMatrix();

		const int GetValue() const;
		const std::string GetStr() const;
		const bool GetIsText() const;

		void SetStr(const std::string& value);
		void SetValue(const int value);
		void SetIsText(const bool value);
		
		const int GetFirst(const int position);
		const std::string RemakeStrForOut();

		void Remake(int posB, int value);

		int CalcWithOperator(char operatorr, int mainValue, int value);
		int CheckOperator(int& position);

		const bool IsOperator(const int position);
		const bool isNumb(const char ch);

	private:
		std::string m_str;

		int m_value;
		int m_posX;
		int m_posY;
		bool m_isText;
	};
}

