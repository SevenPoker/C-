#include <iostream>

// T가 포인터인지를 조사하는 기술

template<typename T>
struct is_pointer
{
	// bool value = false;
	// C++ 이전에는 여기서 멤버 초기화 안되고
	// 컴파일 시간 상수가 아닙니다.

//	enum { value = false }; // C++11 이전에 사용하던 기술
	static constexpr bool value = false; // 실제 C++ 표준은 이렇게 구현
};

// template partial specialization(부분 특수화) 문법
template<typename T>
struct is_pointer<T*> // 개발자들이 이렇게 사용하면 이 struct를 불러줘
{
//	enum { value = true };
	static constexpr bool value = true; // 실제 C++ 표준은 이렇게 구현
};


template<typename T>
void foo(const T& b)
{
	// T : int, int*
	if ( is_pointer<T>::value ) // 컴파일 하면 이미 결정이 되는거다
								// 컴파일 시간에 사용하는 함수이다.
								// 러닝타임이 아니다
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

