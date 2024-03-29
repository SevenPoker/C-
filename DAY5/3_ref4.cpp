#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

int main()
{
	std::function<void()> f;

	int n = 10;

//	f = &foo; // error. foo는 인자 한개를 요구한다.

//	f = std::bind(&foo, n);
	// 이 순간 foo의 인자를
	// 1. n으로 고정할까?
	// 2. n의 값 10으로 고정할까?? (이걸로 된다.)

	// 만약 {} 가 int n =10 부터 f() 위까지 묶는다면 
	// f()는 에러다
	// 그래서 bind 일때 값으로 들어간다.
	// => std::bind는 기본적으로 값 보관

    f = std::bind(&foo, std::ref(n));
	// 이렇게 하면 reference로 보관
	// 정확한 원리는 포인터로 보관하다가 참조로 변환가능한 것

	f();	// foo(n) ? foo(10)

	std::cout << n << std::endl; 
}
