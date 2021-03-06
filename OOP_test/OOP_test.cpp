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

unique_ptr <Matrix::IInput> GetConsoleOrFileInput(bool file, string fileName)
{	
	if (!file) 
	{
		unique_ptr <Matrix::IInput> uniq(new Matrix::InputConsole);
		return uniq;
	}
	else
	{
		unique_ptr <Matrix::IInput> uniq(new Matrix::InputFile(fileName));
		return uniq;
	}
}
unique_ptr <Matrix::IOutput> GetConsoleOrFileOutput(bool file, string fileName)
{
	if (!file)
	{
		unique_ptr <Matrix::IOutput> uniq(new Matrix::OutputConsole);
		return uniq;
	}
	else
	{
	  unique_ptr <Matrix::IOutput> uniq(new Matrix::OutputFile(fileName));
		return uniq;
	}
}
void CheckFileOrConsoleStream(bool &file, string& inputFilename, string& outputFilename)
{
	cout << "if you plan work with file - press 1, with console - press 2" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		file = true;
		cout << "Please enter file name with data" << endl;
		cout << "inputFilename = ";
		cin >> inputFilename;
		cout << "Please enter file name for answer" << endl;
		cout << "outputFilename = ";
		cin >> outputFilename;
	}
	else file = false;
}
int main()
{	
	string inputFilename;
	string outputFilename;
	bool file;
	
	CheckFileOrConsoleStream(file, inputFilename, outputFilename);
	
	unique_ptr <Matrix::IInput> input = GetConsoleOrFileInput(file, inputFilename);
	unique_ptr <Matrix::IOutput> output = GetConsoleOrFileOutput(file, outputFilename);
	Matrix::Matrix mainMatrix(0,0);

	mainMatrix.Read(*input);
	mainMatrix.CalcForAll();
	mainMatrix.Write(*output);

	return 0;
}

