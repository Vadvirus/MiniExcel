#include "pch.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "..\ElemOfMatrix\Matrix.h"

using namespace std;
using namespace NameMatrix;

int main()
{
	Matrix MainMatrix(1,1);
	bool useFile = false;
	const string inFile = "Input.txt";
	const string outFile = "Output.txt";
	ifstream inFileStream;
	ofstream outFileStream;
	if (useFile) {
		inFileStream.open(inFile);
		outFileStream.open(outFile);
	}
	istream& inStream = useFile ? inFileStream : std::cin;
	ostream& outStream = useFile ? outFileStream : std::cout;
	MainMatrix.Input(inStream);
	for (int i = 1; i < MainMatrix.GetM().size(); i++)
		for (int j = 1; j < MainMatrix.GetM()[i].size(); j++)
			MainMatrix.Calc(i,j);
	MainMatrix.Output(outStream);
	return 0;
}

