#include <iostream>
#include <thread>
#include <atomic>

constexpr std::size_t cnt = 1'000'000;
// atomic

// int x = 0;

std::atomic<int> x = 0; // ++, + 등을 연산자 재정의 했고
						// atomic_fetch_add() 등의 함수로 구현되어있다.

void foo()
{
	for ( int i = 0; i < cnt; i++)
	{

		++x;

//      x = x + 1;
//		1. 위 한줄을 아래 3줄이므로 thread safe 하지않다.
//		mov eax, x
//		add eax, 1
//		mov x, eax

//		2. mutex를 사용하면 안전합니다.
//		하지만 성능이 너무너무 떨어진다.
//		m.lock();
//		x = x + 1;
//		m.unlock();

//		3. CPU가 제공하는 멀티코어에 안전하게 1증가하는 함수가 존재함
//		lock inc x; (CPU의 lock 을 쓰기 때문에 운영체제의 lock을 안씀 lock-free 기술)
//		이거는 어셈코드이다.
///		fetch_and_add(&x); // 이게 위 어셈을 수행하는 C 함수

	}
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);
	std::thread t3(&foo);
	t1.join();
	t2.join();
	t3.join();
	std::cout << x << std::endl;
}
