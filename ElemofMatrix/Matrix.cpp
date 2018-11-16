#include "Matrix.h"
#include "InputConsole.h"
#include "InputFile.h"
#include "OutputConsole.h"
#include "OutputFile.h"

using namespace std;
namespace Matrix
{
	Matrix::Matrix(int rows, int columns)
	{
		std::vector <std::vector <ElemOfMatrix> >  M(rows + 1, vector <ElemOfMatrix>(columns + 1));
	}

	Matrix::~Matrix()
	{
	}

	vector < vector <ElemOfMatrix> > Matrix::GetMatrix()
	{
		return m_matrix;
	}

	bool Matrix::GetIsText(int i, int j)
	{
		return m_matrix[i][j].GetIsText();
	}

	void Matrix::CheckPointer(int first, int second, int x)
	{
		if (m_matrix.size() <= first || m_matrix[first].size() <= second || first <= 0 || second <= 0)
		{
			char ch = char() + 'A' - 1;
			string textEx = "Pointer to non-existent link in element: ";
			textEx += ch;
			textEx += to_string(x);
			throw MyException(textEx.c_str());
		}
	}


	const bool Matrix::PointerIsInf(int first, int second)
	{
		char ch = 'A' + m_errors[0].second - 1;
		string message = "Reference is inf in element: ";
		message += ch + to_string(m_errors[0].first);

		if (m_flag[first][second] || m_matrix[first][second].GetIsText()) {
			for (int i = 0; i < m_errors.size(); i++) {
				m_matrix[m_errors[i].first][m_errors[i].second].SetStr("'Error");
				m_matrix[m_errors[i].first][m_errors[i].second].SetIsText(true);
			}
			throw MyException(message.c_str());
		}
		else
			return false;

	}

	template <typename T> void Matrix::ResizeVec(vector <vector<T> > &vec, const unsigned short rows, const unsigned short columns)
	{
		vec.resize(rows);
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			it->resize(columns);
		}
	}

	const bool Matrix::IsFile(const std::string filename)
	{
		for (int i = 0; i < filename.size(); i++) if (filename[i] == '.') return true;
		return false;
	}

	void Matrix::Read(const string filename)
	{
		bool file;
		if (filename == ".NoFile")  file = false; else true;

		try
		{
			int i = 1;
			int j = 1;
			string s = "string";
			int maxJ = -1;
			m_matrix.push_back(vector <ElemOfMatrix>(1));
			m_matrix.push_back(vector <ElemOfMatrix>(1));

			InputFile IF;
			IF.fileName = filename;
			InputConsole IC;
			bool finish = false;
			while (!finish)
			{
				s = (file ? IF.Get() : IC.Get());
				if (s[s.size() - 1] == '@')
				{
					s.erase(s.size() - 1, 1);
					finish = true;
				}
				m_matrix[i].push_back(ElemOfMatrix(s, i, j));
				if (s[0] == 39) m_matrix[i][j].SetIsText(true); else
					m_matrix[i][j].SetIsText(false);
				if (s[s.size() - 1] == ',')
					j++;
				else
				{
					i++;
					j = 1;
					m_matrix.push_back(vector <ElemOfMatrix>(1));
				}
				if (maxJ < j) maxJ = j;
			}

			ResizeVec(m_flag, i + 1, maxJ + 1);
			ResizeVec(m_clearOfFlags, i + 1, maxJ + 1);
		}
		catch (MyException& MyE)
		{
			std::cout << MyE.what() << std::endl;
		}

	}

	void Matrix::Write(const std::string filename)
	{
		bool file;
		if (filename == ".NoFile") file = false; else true;
		OutputConsole OC;
		OutputFile OF;
		OF.fileName = filename;
		file ? OF.ThisMatrix(m_matrix) : OC.ThisMatrix(m_matrix);

	}

	void Matrix::Calculation(int x, int y)
	{
		try
		{
			string temp;
			string currentExpression = m_matrix[x][y].GetStr();
			char currentOperator = '0';
			int first;
			int second;
			int negative = 1;
			for (int position = 0; position < m_matrix[x][y].GetStr().size(); position++)
			{
				if (m_matrix[x][y].GetStr()[position] == '(' || m_matrix[x][y].GetStr()[position] == ')') m_matrix[x][y].SetStr(currentExpression.erase(position, 1));

				if (m_matrix[x][y].GetStr()[position] >= 'A' && m_matrix[x][y].GetStr()[position] <= 'Z')
				{
					m_flag[x][y] = true;
					m_errors.push_back(make_pair(x, y));

					first = m_matrix[x][y].GetFirst(position);
					second = m_matrix[x][y].GetStr()[position] - 'A' + 1;

					CheckPointer(first, second, x);
					if (!PointerIsInf(first, second))
						Calculation(first, second);

					if (m_matrix[first][second].GetIsText()) break;
					m_matrix[x][y].Remake(position, m_matrix[first][second].GetValue());

					m_flag = m_clearOfFlags;
					m_errors.clear();
				}

				if (m_matrix[x][y].isNumb(m_matrix[x][y].GetStr()[position]))
				{
					temp += m_matrix[x][y].GetStr()[position];
				}

				if ((!m_matrix[x][y].isNumb(m_matrix[x][y].GetStr()[position]) && temp != "") || m_matrix[x][y].GetStr().size() - 1 == position)
				{
					if (m_matrix[x][y].GetValue() == 0) m_matrix[x][y].SetValue(stoi(temp)*negative);
					else m_matrix[x][y].SetValue(m_matrix[x][y].CalcWithOperator(currentOperator, m_matrix[x][y].GetValue(), stoi(temp)*negative));
					temp = "";
				}

				if (m_matrix[x][y].IsOperator(position))
				{
					currentOperator = m_matrix[x][y].CheckOperator(position);
					if (m_matrix[x][y].GetStr()[position] == '-') negative = -1; else negative = 1;
				}
			}

		}
		catch (MyException& MyE)
		{
			cout << MyE.what() << endl;
		}
	}
}