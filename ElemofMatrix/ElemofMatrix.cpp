#include "ElemofMatrix.h"


ElemOfMatrix::ElemOfMatrix(string str, int posX, int posY) :m_str(str), m_posX(posX), m_posY(posY), m_value(0) {}

ElemOfMatrix::ElemOfMatrix()
{
}

ElemOfMatrix::~ElemOfMatrix()
{
}

const int ElemOfMatrix::GetValue()
{
	return m_value;
}

const string ElemOfMatrix::GetStr()
{
	return m_str;
}

const void ElemOfMatrix::SetStr(const string s)
{
	m_str=s;
}

const void ElemOfMatrix::SetValue(const int value)
{
	m_value = value;
}

const void ElemOfMatrix::SetIsText(const bool b)
{
	text = b;
}

const bool ElemOfMatrix::GetIsText()
{
	return text;
}

const string ElemOfMatrix::RemakeStrForOut()
{
	string t = m_str.erase(0, 1);

	return t;
}

const bool ElemOfMatrix::isNumb(const char ch)
{
	if (ch >= '0' && ch <= '9') return true; else
		return false;
}


int ElemOfMatrix::CalcWithOperator(char operatorr, int mainValue, int value)
{
	if (operatorr == '+') mainValue += value;
	else if (operatorr == '*') mainValue *= value;
	else if (operatorr == '-') mainValue += value;
	else if (operatorr == '/')
		if (value == 0)
			throw MyException("Error value / 0 ");
		else mainValue /= value;

	return mainValue;
}

int const ElemOfMatrix::GetFirst(int const position)
{
	string t = "";
	int p = position + 1;
	if (m_str.size() <= p)
		throw("Function ElemOfMatrix::GetSecond error: out of range, position is wrong");
	while (isNumb(m_str[p])) {
		t += m_str[p];
		p++;
	}
	if (t == "") t = "0";
	return stoi(t);
}


void ElemOfMatrix::Remake(int posBegin, int value)
{

	int posEnd = posBegin + 1;

	if (m_str.size() <= posBegin && posBegin >= 0) throw("Function ElemOfMatrix::Remake error: out of range, position is wrong(posB)");
	if (m_str.size() <= posEnd && posEnd >= 0) throw("Function ElemOfMatrix::Remake error: out of range, position is wrong(posE)");

	while (isNumb(m_str[posEnd])) posEnd++;
	posEnd -= 1;
	m_str.erase(posBegin, posEnd - posBegin + 1);
	m_str.insert(posBegin, to_string(value));
}

int ElemOfMatrix::CheckOperator(int& position)
{

	if (position > 0)
		if (m_str[position - 1] == '+' || m_str[position - 1] == '-' ||
			m_str[position - 1] == '/' || m_str[position - 1] == '*')
		{
			if (m_str[position] == '-' && m_str[position - 1] == '-')
			{
				m_str.erase(position - 1, 2);
				m_str.insert(position - 1, "+");
				position--;
				return m_str[position];
			}
			return m_str[position - 1];
		}
	if (position < 0) throw("Function ElemOfMatrix::CheckOperator error: out of range, position is wrong(position)");
	return m_str[position];
}


const bool ElemOfMatrix::IsOperator(const int position)
{
	return m_str[position] == '+' || m_str[position] == '-' || m_str[position] == '/' || m_str[position] == '*';
}

