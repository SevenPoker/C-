#include <iostream>
#include <thread>
#include <mutex>

// 스택 : 스레드당 한개
// 힙, data 메모리, 코드 메모리 : 프로세스당 한개 (모든 스레드가 공유)

// gui는 스레드당 관리한다.

std::mutex m;
int shared_data = 10; // 파일같은 작업이라고 생각 (프로세스가 관리한다.)
					  // 스레드가 죽어도 열려있다.

void foo()
{
	int data = 0; // 스레드당 한개

	m.lock();
	// 공유 자원 사용	
	shared_data = 200;
	m.unlock();
	// 공유자원은 다른 스레드에서 쓸수있기 때문에
	// mutex로 막아준다.
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

