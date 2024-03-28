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
	Car* p1 = new Car; 
	Car* p2 = p1;

	// #1. 메모리 누수
	delete p1;


	// #2. dangling pointer
	if (p2 != nullptr)
	{
		p2->Go(); // 버그, p2는 0번지는 아니지만
				  // p2가 가진 주소의 객체는 이미 파괴되었다.
	}

	// #3. double delete
	// delete 한번 더 한거
	delete p2;

}


