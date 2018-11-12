#pragma once

#include "ElemofMatrix.h"
namespace NameMatrix
{
	using namespace std;
	class Matrix
	{
	public:
		Matrix(int rows, int columns);
		~Matrix();

		std::vector <vector < NameElemOfMatrix::ElemOfMatrix> > GetM();

		const bool PointerIsInf(int First, int Second);
		const bool IsFile(const string filename);

		void Calc(int x, int y);
		void CheckPointer(int First, int Second, int x);

		void Input(istream &stream);
		void Output(ostream &stream);

	private:

		vector <vector <bool> > flag;
		vector <vector <bool> > clearOfFlags;
		vector <pair <int, int> > errors;

		vector <vector < NameElemOfMatrix::ElemOfMatrix> >  M;


		template <typename T> void resizeVec(vector <vector <T> > &vec, const unsigned short ROWS, const unsigned short COLUMNS);

		void ResizeAll(int rows, int columns);
	};

}