#include <iostream>
#include <type_traits> // 헤더 필요


// C++14 부터 아래 기술을 도입한다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T> void foo(const T& b)
{
	// 조사
	bool b1 = std::is_pointer<T>::value; // C++11
	bool b2 = std::is_pointer_v<T>; // C++17 부터 들어오는 표기법

	// 변형된 타입 얻기
	typename std::remove_pointer<T>::type n1; // C++11
	std::remove_pointer_t<T> n2; // 위와 동일 // C++14
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

