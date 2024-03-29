#include <atomic>
#include <iostream>

struct Point
{
	int x;
	int y;


};

int main()
{
	std::atomic<Point> p1;
	std::atomic<Point> p2(p1.lock()); // 멀티스레드 안전하게 복사

	std::cout << p1.lock_free() <<std::endl;
}
