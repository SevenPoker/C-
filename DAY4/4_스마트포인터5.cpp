#include <iostream>
#include <memory>


void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	// => 2번의 메모리 할당
	// => 1. new Point(1,2)
	// => 2. shared_ptr 의 생성자에서 new control_block(참조계수등)

	std::shared_ptr<Point> sp(new Point(1, 2));
	// Heap에 Point 객체를 하나 만들고
	// 공유 자원 객체 생성 (counting 하는것)
	// 과 Point 객체 크기만큼 할당하는것 
	// 2번 이뤄진다.
}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

