#include <iostream>

// Step 4. 보다 일반화(유연)되도록


// 아래처럼 템플릿으로 만들면 2가지 단점이 있음
// 1. 구간의 타입과 검색 요소의 타입이 연관된다. ==> double 배열에서 int 검색이 안됨

// 2. T* 라고 표기하면 구간은 항상 "raw pointer"만 가능하다. => 스마트 포인터등을 사용할 수 없다.


// template<typename T>
//T* find(T* first, T* last, T c)


// 아래처럼 만들면
// 1. 구간의 타입과 검색 요소의 타입이 분리되고
// 2. 구간은 반드시 "Raw pointer"일 필요가 없다.
// => 단, 구간을 나타내는 타입은 ++, ==, !=, * 연산이 가능해야 한다.

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	double x[10]= {1,2,3,4,5,5,6,67,7,1};

	double* p = find(x, x+4, 5);
    // 끝을 보내서 중간에서 찾게끔 한다.'
    // 하지만 끝은 검색대상에서 제외된다.

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
