// 4_traits
#include <iostream>
#include <type_traits> 

template<typename T> void printv(const T& v)
{
	// if constexpr : 컴파일 시간 if 문
	//				  조건식은 반드시 컴파일 할 때 계산할 수 있어야 한다.
	//				  조건식이 false인 경우
	//			      "template => C++함수생성" 에서 제외 된다.

	if constexpr( std::is_pointer<T>::value )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

