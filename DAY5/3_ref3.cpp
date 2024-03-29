#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

// 2번째 인자를 다른 함수로 전달하고 있습니다.
// => 그런데, 값의 개념으로 동작하도록 설계되었다.

template<typename F, typename T> 
void forward(F f, T arg)
{
	f(arg);
}

int main()
{
	int n = 10;

//	foo(n);	// 직접 전달, n은 200으로 변경됩니다.

//	forward(foo, n); // 복사본 생성됩니다.
	forward(foo, &n); // 주소로 전달.
					  // T arg = &n 에서 T = int* 이므로
					  // foo(int*) 가 되어서 error

///	std::reference_wrapper<int> r = n;
//	forward(foo, r);

	forward(foo, std::ref(n));
				// std::ref가 reference_wrapper를 만들어 주는 함수이다.
				// => "object generator" 기술

	std::cout << n << std::endl; 
}
