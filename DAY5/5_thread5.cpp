#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

int add(int a, int b)
{
	int s = a + b;
	return s;
}

int main()
{
    // std::async : 스레드를 고려하지 않은 일반함수( 결과를 반환값으로 알려주는)
    //              를 스레드로 수행하고 결과를 얻을때 사용

    std::future<int> ft = std::async(&add, 1, 2);

    int ret = ft.get();

    std::cout << ret << std::endl;
}


// std::async       : 내부적으로 아래 2개를 사용해서 만들어진 편의 함수
// std::promise     : 스레드간 결과를 꺼내는 도구
// std::thread      : c++에서 스레드를 생성하는 유일한 방법
