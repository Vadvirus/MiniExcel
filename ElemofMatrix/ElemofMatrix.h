#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "MyException.h"

using namespace std;

class ElemOfMatrix
{

public:
	ElemOfMatrix(std::string str, int posX, int posY);
	ElemOfMatrix();
	~ElemOfMatrix();
	
	const int GetValue();
	
	const string GetStr();
	const void SetStr(const string s);
	const void SetValue(const int value);
	const void SetIsText(const bool b);
	const bool GetIsText();

	const int GetFirst(const int position);
	const string RemakeStrForOut();

	void Remake(int posB, int value);

	int CalcWithOperator(char operatorr, int main_value, int value);
	int CheckOperator(int& position);
	
	const bool IsOperator(const int position);
	const bool isNumb(const char ch);
	
private:

	std::string m_str;
	
	int m_value;
	int m_posX;
	int m_posY;
	bool text;

};


