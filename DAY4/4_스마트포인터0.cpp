#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

int main()
{
	// 포인터를 직접 사용하는 경우의 문제점
	Ptr p = new Car; 

	// #1. 메모리 누수
	// #2. dangling pointer
	// #3. double delete
	
}


