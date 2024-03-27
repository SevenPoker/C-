#include <vector>
#include "show.h"

void f1()
{
	int x[10];
}

void f2()
{
	std::vector<int> v(10);
}

void use_array()
{
	for(int i = 0; i < 1'000'000; i++) f1();
}

void use_vector()
{
	for(int i = 0; i < 1'000'000; i++) f2();
}

int main()
{
	chronometry(use_array);
	chronometry(use_vector);
}
