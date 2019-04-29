#include <iostream>
#include "vector.h"

constexpr auto VECTOR_SIZE = 5;
constexpr auto VECTOR_DATA_VALUE = 4;
constexpr auto NUMBER_OF_PUSH = 1000;

void CheckConstructors();
void CheckOperators();
void CheckModifiers();

int main()
{
	CheckConstructors();
	CheckOperators();
	CheckModifiers();
}

void CheckConstructors()
{
	int StandartVectorSize = VECTOR_SIZE;
	size_t Value = VECTOR_DATA_VALUE;
	std::cout << "CHECKING CONSTRUCTORS..." << std::endl;
	vector<size_t> A;
	std::cout << "Standart constructor work successfully" << std::endl;
	vector<size_t> B(StandartVectorSize, Value);
	for (int i = 0; i < StandartVectorSize; i++)
	{
		if (B[i] != Value)
		{
			std::cout << "Something is wrong with operator[] or vector(size_t n, const T & val = T()) constructor" << std::endl;
			exit(1);
		}
	}
	std::cout << "vector(size_t n, const T & val = T()) constructor work successfully" << std::endl;

	vector<size_t> C(B);
	for (int i = 0; i < StandartVectorSize; i++)
	{
		if (B[i] != Value)
		{
			std::cout << "Something is wrong with operator[] or vector(const vector & other) constructor" << std::endl;
			exit(2);
		}
	}
	std::cout << "vector(const vector & other) constructor work successfully" << std::endl;

	vector<size_t> D(std::move(C));
	for (int i = 0; i < StandartVectorSize; i++)
	{
		if (D[i] != Value)
		{
			std::cout << "Something is wrong with operator[] or vector(vector && other) constructor" << std::endl;
			exit(3);
		}
	}
	std::cout << "vector(vector && other) constructor work successfully" << std::endl;
	std::cout << "CONSTRUCTORS HAVE BEEN CHECKED" << std::endl << std::endl;
}

void CheckOperators()
{
	std::cout << "CHECKING OPERATORS..." << std::endl;
	vector<int> A(VECTOR_SIZE, VECTOR_DATA_VALUE);
	vector<int> B(A);
	if (B == A) 
	{

	}
	else
	{
		std::cout << "Something is wrong with '=='" << std::endl;
		exit(4);
	}
	std::cout << "'==' work sucessfully" << std::endl;
	vector<int>C = B;
	if (C == B)
	{

	}
	else
	{
		std::cout << "Something is wrong with '='" << std::endl;
		exit(4);
	}
	std::cout << "'=' work sucessfully" << std::endl;
	if (C != B)
	{
		std::cout << "Something is wrong with '!='" << std::endl;
	}
	std::cout << "'!=' work sucessfully" << std::endl;
	std::cout << "OPERATORS HAVE BEEN CHECKED" << std::endl << std::endl;
}

void CheckModifiers()
{
	vector<size_t> A;
	size_t x = VECTOR_DATA_VALUE;
	for (int i = 0; i < NUMBER_OF_PUSH; i++)
	{
		A.push_back(x);
	}
	for (size_t i = 0; i < A.size(); i++)
	{
		if (A[i] != VECTOR_DATA_VALUE)
		{
			std::cout << "Something is wrong with PUSH_BACK" << std::endl;
			exit(5);
		}
	}
	std::cout << "PUSH_BACK succesfully works" << std::endl;
}
