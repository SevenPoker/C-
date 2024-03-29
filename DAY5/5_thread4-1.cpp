#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 방법 #1. out parameter 사용

void add(int a, int b, int& s)
{
	s = a + b;
}

int main()
{
	int ret = 0;
	std::thread t(&add, 1, 2, std::ref(ret));

	t.join();

	std::cout << ret << std::endl;
}
