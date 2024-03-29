#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// promise & future

// 스레드를 고려 하지 않은 함수
int add1(int a, int b)
{
	int s = a + b;
	return s;
}

int main()
{
	// 핵심 1. 스레드가 아닌 직접 호출은 함수의 결과를 반환값으로 받으면 됩니다.
	int ret1 = add1(1, 2);

	// thread로 add1 수행하고, 반환값을 얻고 싶다?
	// => 스레드로 수행한 함수의 반환값을 주 스레드에서 받을 수 없다.!!
	std::thread t(&add1, 1, 2);

	t.join();
}
