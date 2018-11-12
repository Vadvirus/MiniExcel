
#include "Matrix.h"

using namespace NameMatrix;
using namespace NameElemOfMatrix;

Matrix::Matrix(int rows, int columns)
{
	std::vector <std::vector <ElemOfMatrix> >  M(rows+1, vector <ElemOfMatrix> (columns+1));
}

Matrix::~Matrix()
{
}

vector<vector<ElemOfMatrix>> Matrix::GetM()
{
	return M;
}

void Matrix::CheckPointer(int First, int Second, int x)
{
	if (M.size() <= First || M[First].size() <= Second || First <= 0 || Second <= 0)
	{
		char ch = char() + 'A' - 1;
		string textEx = "Pointer to non-existent link in element: ";
		textEx += ch;
		textEx += to_string(x);
		throw MyException(textEx.c_str());
	}
}

const bool Matrix::PointerIsInf(int First, int Second)
{
	char ch = 'A' + errors[0].second - 1;
	string message = "Reference is inf in element: ";
	message += ch + to_string(errors[0].first);

	if (flag[First][Second] || M[First][Second].GetIsText()) {
		for (int i = 0; i < errors.size(); i++) {
			M[errors[i].first][errors[i].second].SetStr("'Error");
			M[errors[i].first][errors[i].second].SetIsText(true);
		}
		throw MyException(message.c_str());
	}
	else
		return false;

}

template <typename T> void Matrix::resizeVec (vector <vector<T> > &vec, const unsigned short ROWS, const unsigned short COLUMNS)
{
	vec.resize(ROWS);
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		it->resize(COLUMNS);
	}
}

const bool Matrix::IsFile(const std::string filename)
{
	for (int i = 0; i < filename.size(); i++) if (filename[i] == '.') return true;
	return false;
}

void Matrix::Input(std::istream & stream)
{
	int rows, columns;
	string s;
	try
	{
		stream >> rows >> columns;

		ResizeAll(rows + 1, columns + 1);
		resizeVec(M, rows + 1, columns + 1);
		for (int i = 1; i <= rows; i++)
			for (int j = 1; j <= columns; j++)
			{
				stream >> s;
				M[i][j] = ElemOfMatrix(s, i, j);
				if (s[0] == 39) M[i][j].SetIsText(true); else
					M[i][j].SetIsText(false);
			}
	}
	catch (MyException& MyE)
	{
		std::cout << MyE.what() << std::endl;
	}
}


void Matrix::Output(std::ostream &stream)
{

	try
	{
		std::cout << std::endl;
		for (int i = 1; i < M.size(); i++)
		{
			if (i != 1) std::cout << std::endl;
			for (int j = 1; j < M[i].size(); j++)
				if (M[i][j].GetIsText())
					std::cout << M[i][j].RemakeStrForOut() << "\t";
				else std::cout << M[i][j].GetValue() << "\t";
		}
		std::cout << std::endl;
	}
	catch (MyException& MyE)
	{
		std::cout << MyE.what() << std::endl;
	}

}

void Matrix::ResizeAll(int rows, int columns)
{
	resizeVec(M, rows, columns);
	resizeVec(flag, rows, columns);
	resizeVec(clearOfFlags, rows, columns);
}

void Matrix::Calc(int x, int y)
{
	try
	{
		string t;
		string str = M[x][y].GetStr();
		char op = '0';
		int First, Second;
		int negative = 1;
		for (int position = 0; position < M[x][y].GetStr().size(); position++)
		{
			if (M[x][y].GetStr()[position] == '(' || M[x][y].GetStr()[position] == ')') M[x][y].SetStr(str.erase(position, 1));

			if (M[x][y].GetStr()[position] >= 'A' && M[x][y].GetStr()[position] <= 'Z')
			{
				flag[x][y] = true;
				errors.push_back(make_pair(x, y));

				First = M[x][y].GetFirst(position);
				Second = M[x][y].GetStr()[position] - 'A' + 1;
				
				CheckPointer(First, Second, x);
				if (!PointerIsInf(First, Second))
					Calc(First,Second);
				
				if (M[First][Second].GetIsText()) break;
				M[x][y].Remake(position, M[First][Second].GetValue());
				
				flag = clearOfFlags;
				errors.clear();

			}

			if (M[x][y].isNumb(M[x][y].GetStr()[position]))
			{
				t += M[x][y].GetStr()[position];
			}
			
			if ((!M[x][y].isNumb(M[x][y].GetStr()[position]) && t != "") || M[x][y].GetStr().size() - 1 == position)
			{
				if (M[x][y].GetValue() == 0) M[x][y].SetValue (stoi(t)*negative);
				else M[x][y].SetValue (M[x][y].CalcWithOperator(op, M[x][y].GetValue(), stoi(t)*negative));
				t = "";
			}

			if (M[x][y].IsOperator(position)) {
				op = M[x][y].CheckOperator(position);
				if (M[x][y].GetStr()[position] == '-') negative = -1; else negative = 1;
			}
		}

	}
	catch (MyException& MyE)
	{
		cout << MyE.what() << endl;
	}
}

