#include <iostream>
#include <type_traits>

template<typename T> void foo(const T& b)
{
	typename std::remove_pointer<T>::type n;

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

