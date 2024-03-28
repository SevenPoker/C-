#include <iostream>
#include <thread>

constexpr std::size_t cnt = 1'000'000;
// atomic

int x = 0;

void foo()
{
	for ( int i = 0; i < cnt; i++)
	{
		x = x + 1;
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
