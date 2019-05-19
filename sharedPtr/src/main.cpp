#include "SharedPtr.h"
#include <memory>
#include <iostream>

#define NOT_OK {\
std::cout << __LINE__ << std::endl;\
return false;\
}\

#define SOME_NUMBER 5

bool TestSharedPtr()
{
	int * x = new int(SOME_NUMBER);
	int * X = new int(SOME_NUMBER);

	std::shared_ptr<int> a(x);
	std::shared_ptr<int> b = a;
	std::shared_ptr<int> c;
	c = a;
	a = a;
	SharedPtr<int> A(X);
	SharedPtr<int> B = A;
	SharedPtr<int> C;
	C = A;
	A = A;
	if (a.use_count() != A.use_count())
		NOT_OK
	if (*a != *A)
		NOT_OK
	a.reset();
	A.reset();
	if (a.use_count() != A.use_count())
		NOT_OK
	return true;
}

int main()
{
	bool isOk = TestSharedPtr();
	if (isOk)
		std::cout << "All tests have been passed" << std::endl;
	else
		std::cout << "One test has not been passed, see the line above" << std::endl;
}