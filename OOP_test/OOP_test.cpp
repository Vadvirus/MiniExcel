#include "pch.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Matrix.h"

using namespace std;
//using namespace Matrix;

int main()
{	
	Matrix::Matrix MainMatrix(0,0);
	const string inFile = "Input.txt";
	const string outFile = "Output.txt";

	MainMatrix.Read();

	for (int i = 1; i < MainMatrix.GetMatrix().size(); i++)
		for (int j = 1; j < MainMatrix.GetMatrix()[i].size(); j++)
			 if (!MainMatrix.GetIsText(i,j)) MainMatrix.Calculation(i,j);

	MainMatrix.Write();
	return 0;
}

