#pragma once

#include <vector>
#include "IInput.h"
#include "IOutput.h"
#include "ElemofMatrix.h"
namespace Matrix
{
	class Matrix
	{
	public:
		Matrix(int rows, int columns);
		~Matrix();

		std::vector <std::vector < ElemOfMatrix> > GetMatrix();
		bool GetIsText(int i, int j);
		const bool PointerIsInf(int first, int second);
		const bool IsFile(const std::string filename);

		void Calculation(int x, int y);
		void CalcForAll();
		void CheckPointer(int first, int second, int x);

		void Read(IInput& input);
		void Write(IOutput& output);

		template <typename T> void ResizeVec(std::vector <std::vector <T> > &vec, const unsigned short rows, const unsigned short columns);


	private:
		std::vector <std::vector <bool> > m_flag;
		std::vector <std::vector <bool> > m_clearOfFlags;
		std::vector <std::pair <int, int> > m_errors;

		std::vector <std::vector < ElemOfMatrix> >  m_matrix;

		
	};

}