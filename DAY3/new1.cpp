#include <iostream>
#include <vector>
#include "show.h"

constexpr int size = 1'000'000;
constexpr int element_size = 10000;
void ex1()
{
	std::vector<int> v(element_size);
}

void ex2()
{
	std::vector<int> v;
	v.reserve(element_size);
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