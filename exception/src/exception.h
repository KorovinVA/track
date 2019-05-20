#pragma once
#include <string>
#include <iostream>

class MyException
{
public:
	enum ErrType
	{
		_BAD_ALLOC_,
		_OVERFLOW_,
		_BAD_OPERATION_,
		_UNKNOW_
	};
public:
	MyException(ErrType error, int linenum, std::string message, std::string function);
	void display();
private:
	ErrType error_;
	int linenum_;
	std::string message_;
	std::string function_;
};