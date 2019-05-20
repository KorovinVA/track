#include "exception.h"

MyException::MyException(ErrType error, int linenum, std::string message, std::string function):
	error_(error),
	linenum_(linenum),
	message_(message),
	function_(function)
{
}

void MyException::display()
{
	std::cout << "The fault number: " << error_ << " -- " << message_ << std::endl;
	std::cout << "The line: " << linenum_ << std::endl;
	std::cout << "The Function: " << function_ << std::endl;
}
