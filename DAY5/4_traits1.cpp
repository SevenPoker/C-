// 4_traits
#include <iostream>

template<typename T> void printv(const T& b)
{
	std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 10;

	printv(n);
	printv(d);
	printv(&n);
}

