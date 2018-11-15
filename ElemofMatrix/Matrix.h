#pragma once

#include "ElemofMatrix.h"

namespace NameMatrix
{
	class Matrix
	{
	public:
		Matrix(int rows, int columns);
		~Matrix();

		std::vector <std::vector < NameElemOfMatrix::ElemOfMatrix> > GetMatrix();
		bool GetIsText(int i, int j);
		const bool PointerIsInf(int first, int second);
		const bool IsFile(const std::string filename);

		void Calculation(int x, int y);
		void CheckPointer(int first, int second, int x);

		void Read(const std::string filename = ".NoFile");
		void Write(const std::string filename = ".NoFile");

		template <typename T> void ResizeVec(std::vector <std::vector <T> > &vec, const unsigned short rows, const unsigned short columns);


	private:
		std::vector <std::vector <bool> > m_flag;
		std::vector <std::vector <bool> > m_clearOfFlags;
		std::vector <std::pair <int, int> > m_errors;

		std::vector <std::vector < NameElemOfMatrix::ElemOfMatrix> >  m_matrix;

		
	};

}