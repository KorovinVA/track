#include <iostream>
#include "exception.h"

float divide(float x, float y)
{

	if(y == 0) throw new MyException(MyException::_BAD_OPERATION_, __LINE__, "divider is 0", __FUNCTION__);
	return x / y;
}

void foo(float y)
{
	if (y == 0) throw new MyException(MyException::_OVERFLOW_, __LINE__, "call stack overflow", __FUNCTION__);
	foo(--y);
};

int main()
{
	float x = 0, y = 5;
	try
	{
		divide(x, y);
		foo(y);
	}
	catch (MyException * exception)
	{
		exception->display();
		delete exception;
	}
}