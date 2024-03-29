#include <iostream>
#include <thread>
#include <mutex>

// RAII
// => Resource Acquision Is Initialization
// => 자원의 획득은 (자원관리객체)가 초기화 될때 이다.
// => 생성자에서 획득, 소멸자에서 반납하도록 하라는 기법

// C++ 표준에 4개의 lock management 가 있다.
// 1. std::lock_guard - 기본권장 (오버헤드가 없다)
// 2. std::unique_lock - 기능이 제일 많음. 무겁다.
// 3. std::shared_lock - shared-mutex 전용
// 4. std::scoped_lock - 2개 이상의 뮤텍스를 동시에 lock 할때(dead lock 방지용)

template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) {mtx.lock();}
	~lock_guard()			  {mtx.unlock();}
}


std::mutex m;
int shared_data = 10;

void foo()
{
	int data = 0;

	lock_guard<std::mutex> g(m); // 핵심 - lock_guard 의 생성자에서 lock
								 //        g 가 파괴될때 소멸자에서 unlock

//  장점 : 중간에 예외 빠지면 catch로 가는데 이때 지역변수는 안전하게 파괴(stack unwinding)되기 떄문에
//  소멸자가 불린다. unlock을 보장

//  함수 중간에 unlock 하고 싶다?? 그러면 {} 을 치면 된다.

//	m.lock();
	shared_data = 200;
//	m.unlock();

}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

