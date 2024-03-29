#include <atomic>
#include <iostream>

// 사용자 정의 타입을 atomic에 넣어서, 대입 복사 등을 thread safe 하게 하려면

// 1. 복사 생성자, 소멸자, 대입연산자 등이 없는 타입만 가능하다.(trivial 한 타입)
// 2. 64 비트 보다 같거나 작은 경우, "lock-free"로 제공 (CPU 명령)

// 3. 64 비트 이상은 "lock-free" 아니고, 대부분 "spin lock"
struct Point
{
	int x;
	int y;
	int z;

	Point() {}
	Point(const Point& other) {}
};

int main()
{
	std::atomic<Point> p1;
	std::atomic<Point> p2(p1.load()); // 멀티스레드 안전하게 복사

	std::cout << p1.is_lock_free() <<std::endl;
}
