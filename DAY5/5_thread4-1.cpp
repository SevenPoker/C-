#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 방법 #1. out parameter 사용
// 이거의 단점은 아래처럼 sleep으로 인해 스레드가 길어지면 종료될때 까지 대기해야한다.(아래 주석 참고)

void add(int a, int b, int& s)
{
	s = a + b;

	// 자원정리등의 추가적인 작업
	std::this_thread::sleep_for(2s);
}

int main()
{
	int ret = 0;
	std::thread t(&add, 1, 2, std::ref(ret));

	t.join();

	std::cout << ret << std::endl;
}
