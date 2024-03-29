#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared_data = 10;

void foo()
{
	int data = 0;

	m.lock();
	shared_data = 200;
	m.unlock();

}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

