#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

int main()
{
	std::function<void()> f;

	int n = 10;

	f = &foo;
	
	f();

	std::cout << n << std::endl; 
}
