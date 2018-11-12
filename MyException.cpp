#include "MyException.h"


MyException::MyException(const char* msg) :std::runtime_error(msg)
{
	std::cout << "**********************Error**********************" << std::endl;
	std::cout << "Info: ";
}

MyException::~MyException()
{
}