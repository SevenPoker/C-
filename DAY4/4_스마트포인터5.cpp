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
	// 근데 이러면 공유자원 객체와 Point 객체가 떨어져 있어서 퍼포먼스가 떨어진다.

	// std::make_shared()
	// 1. operator new( sizeof(Point) + sizeof(control_block)) 으로 한번에 할당
	// 2. new(객체부분의 주소) Point(1,2); 로 생성자호출후
	// 3. std::shared_ptr 을 만들어서 반환
	// 메모리가 줄어든다. (장점)
	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1,2);
	// std::make_shared 의 장점
	// 1. 효율적인 메모리 사용 (객체 + 관리객체를 한번에 할당)
	// 2. 안정성 향상(RAII 기술)


	// B,A,C 순서대로 실행되면 안전한 코드
	// B,C,A 순서대로 실행되는데, C에서 예외가 나오면?
	// B 할당을 했는데 c에서 예외빠져서 메모리 누수가 발생한다.

	foo( std::shared_ptr<int>(new int), goo());
	//          A                B        C
    
	// 위 코드는
	// => 자원의 할당과, 자원 관리 객체의 생성이 분리되어 있습니다.
	// => 안전하지 않다.

	// 자원의 할당과 관리객체의 생성은 "한번에" 해야 안전하다.
	foo( std::make_shared<int>(), goo());

}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

