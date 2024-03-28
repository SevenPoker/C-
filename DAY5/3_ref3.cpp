#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

template<typename F, typename T> 
void forward(F f, T arg)
{
	f(arg);
}
int main()
{
	int n = 10;

	foo(n);	// 직접 전달, n은 200으로 변경됩니다.

//	forward(foo, n); // ?

	std::cout << n << std::endl; 
}
