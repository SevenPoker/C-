// 3_함수객체1
#include <iostream>

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
	int operator[](int a, int b)
	{
		return a * b;
	}
};
int main()
{
	Plus p; // p 는 Plus 타입의 객체이다. 함수가 아니다!

	int n = p(1, 2); // 객체인 p를 함수처럼 사용하고 있다.
					 // "함수 객체" 라고 합니다.

	int k = p[3, 4];
	int n1 = p.operator()(1,2); // 위 코드를 컴파일러가 이렇게 해석한다.
								// 이 코드처럼 사용해도 된다.

	std::cout << k << std::endl;
}


// function object
// => () 연산자를 재정의해서 함수 처럼 사용 가능한 객체

// 왜?? 일반함수를 만들지 않고, 함수 객체를 사용??
// 1. 상태를 가지는 함수 - closure
// 2. 특정 문맥에서 함수객체가 함수보다 빠르다.
// 3. 그 외에도 장점이 많다.

// C++20 에서 추가된 대부분의 함수는 "함수가 아닌 함수객체"

