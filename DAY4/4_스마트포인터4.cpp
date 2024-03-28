#include <iostream>

// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// 핵심 1. 
	std::shared_ptr<int> p1(new int);  // ok
	std::shared_ptr<int> p2 = new int; // error.
									   // 생성자가 explicit 라는 의미

	// 핵심 2. 스마트 포인터의 크기
	std::cout << sizeof(p1)   << std::endl; // raw pointer 의 2배
	std::cout << sizeof(int*) << std::endl; // 32bit 환경 - 4byte
											// 64bit 환경 - 8byte

	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> : 대상체의 멤버에 접근할때 사용
	sp1->Go();

	// . : shared_ptr 자체의 멤버에 접근.
	int n = sp1.use_count();
	std::cout << n << std::endl; // 2

	Car* cp = sp1.get(); // sp1이 관리하는 객체의 실제 주소

	sp1.reset(); // 아래와 동일
	sp1 = nullptr;



}

