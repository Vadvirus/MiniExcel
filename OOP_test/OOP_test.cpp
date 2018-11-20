#include "pch.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Matrix.h"
#include "InputConsole.h"
#include "OutputConsole.h"
#include "InputFile.h"
#include "OutputFile.h"

using namespace std;

int main()
{	
	bool file = false;
	Matrix::InputConsole IC;
	Matrix::InputFile IF("Input.txt");
	Matrix::OutputConsole OC;
	Matrix::OutputFile OF("Output.txt");
	Matrix::Matrix MainMatrix(0,0);

	file ? MainMatrix.Read(IF): MainMatrix.Read(IC);
	MainMatrix.CalcForAll();
	file ? MainMatrix.Write(OF): MainMatrix.Write(OC);

	return 0;
}

