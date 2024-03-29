#include <iostream>
#include <functional>

// 결국 reference_wrapper는
// 1.객체(변수)의 주소를 보관하고 있다가
// 2."raw reference" 로 암시적 변환이 가능한 도구이다.
// reference_wrapper 원리는?
// reference의 기계어 코드는 다 포인터다.

template<typename T>
class reference_wrapper
{
    T* obj;
public:
    reference_wrapper(T& r) : obj(&r) {}

    // 변환 연산자 : 객체가 다른타입으로 변환이 필요 할 때 호출되는 함수
    operator T&() {return *obj;}
};

int main()
{
	int n1 = 10;
	int n2 = 20;

    reference_wrapper<int> r1 = n1;
	reference_wrapper<int> r2 = n2;

	r1 = r2;

    int& r3 = r1; // r1.operator int&() 가 있으면 된다.
                  // 변환 연산자 함수


	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;	
	std::cout << r1 << std::endl;  // std::cout << r1.operator int&() 로 컴파일러가 변환해준다.
	std::cout << r2 << std::endl;
}

