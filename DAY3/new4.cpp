#include <iostream>
#include <vector>
#include "show.h"

constexpr int size = 1'000'000;
constexpr int element_size = 10000;

void ex1()
{
	int* p1 = (int*)operator new(sizeof(int)*element_size);
	std::uninitialized_fill_n(p1, element_size, 0);

	operator delete(p1);
}

void ex2()
{
	int* p2 = (int*)operator new(sizeof(int)* element_size);
	operator delete(p2);
}

void use_size()
{
	for( int i = 0; i < size; i++)
	{
		ex1();
	}
}

void use_reserve()
{
	for( int i = 0; i < size; i++)
	{
		ex2();
	}
}

int main()
{
	chronometry(use_size);
	chronometry(use_reserve);

	
}