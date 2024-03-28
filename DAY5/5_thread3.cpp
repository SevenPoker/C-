#include <iostream>
#include <thread>
#include <mutex>

int shared_data = 10;

void foo()
{
	// 공유 자원 사용	
	shared_data = 200;
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

