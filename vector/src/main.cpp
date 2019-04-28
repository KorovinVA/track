#include <iostream>
#include "vector.h"

int main()
{
	//Constructors:
	vector<int> A(5, 5);
	vector<int> B(6, 6);
	B = vector<int>(6, 6);
	for (int m = 0; m < 5; m++)
	{
		std::cout << B.data_[m] << std::endl;
	}
}