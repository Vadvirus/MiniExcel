#include <iostream>

class MyException :public std::runtime_error
{
public:
	MyException(const char* msg);
	~MyException();
};

