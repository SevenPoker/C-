#include <iostream>
#include <type_traits>

// type traits 종류
// 1. 타입 질의     : std::is_pointer<T>::value        ===> return bool;
// 2. 변형 타입얻기 : std::remove_pointer<T>::type   (포인터를 제거한 타입을 얻고 싶을때) 
//												===> T가 int* 였다면 return int;

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

