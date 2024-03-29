#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <future>
using namespace std::literals;

// 방법 #2. promise & future

// 1. 스레드 함수는 인자로 promise 참조를 받아야한다.
void add(int a, int b, std::promise<int>& p)
{
	try
	{
		int s = a + b;

		// 연산이 종료되면 promise 객체를 통해서 주스레드에 알려주세요.
		p.set_value(s); // 이 순간 대기중인 주 스레드가 깨어나게 됩니다.
	}
	catch(...)
	{
		// promise는 예외전달도 가능하다.
		p.set_exception(std::current_exception());
	}
		

	std::this_thread::sleep_for(10s);

	std::cout << "end thread\n";
}

int main()
{
	// 스레드 생성시
	// 1. promise를 만들고
	// 2. promise 안에 있는 미래 결과를 담은 future를 꺼냅니다.
	std::promise<int> p;

	std::future<int> ft = p.get_future();

	// 3. 스레드 생성시 promise의 참조를 인자로 전달
	std::thread t(&add, 1, 2, std::ref(p));

	std::cout << "other operation~~~~\n";

	try
	{
		// 4. 결과가 필요하면 future를 통해서 꺼내면 된다.
		int ret = ft.get(); // 결과가 나올때 까지 대기

		std::cout << "result : " << ret << std::endl;
	}
	catch(...) // ... 은 모든 예외를 잡겠다는 의미
	{

	}

	t.join();
}
