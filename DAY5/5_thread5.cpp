#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

int add(int a, int b)
{
	int s = a + b;

    std::cout << std::this_thread::get_id() << std::endl;

	return s;
}

int main()
{
    // std::async : 스레드를 고려하지 않은 일반함수( 결과를 반환값으로 알려주는)
    //              를 스레드로 수행하고 결과를 얻을때 사용

    std::future<int> ft = std::async(&add, 1, 2);
    std::future<int> ft2 = std::async(&add, 1, 2);
    std::future<int> ft3 = std::async(&add, 1, 2);

    int ret = ft.get(); // thread가 끝나서 준건지, thread내부에서 처리된 후에 온건지는 이걸로는 확인을 할 수가 없다.

    // 그래서 wait를 써서 확인한다.
    std::future_status s = ft.wait_for(2s);

    if ( s == future_status::timeout)
    {

    }
    else if ( s == future_status::ready)
    {
        int ret = ft.get();
        std::cout << ret << std::endl;
    }

    std::cout << ret << std::endl;
}


// std::async       : 내부적으로 아래 2개를 사용해서 만들어진 편의 함수
//                     => 단, 대부분의 컴파일러에서 구현시
//                     => 스레드 풀링 기술로 구현해서, 성능도 좋다.

// std::promise     : 스레드간 결과를 꺼내는 도구
// std::thread      : c++에서 스레드를 생성하는 유일한 방법
