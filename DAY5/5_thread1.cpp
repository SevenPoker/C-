#include <iostream>
#include <thread> // thread 관련 헤더. 
#include <chrono>
using namespace std::literals;

// std::this_thread namespace 
// => thread 관련 몇가지 일반 함수 제공


int main()
{
    std::cout << std::this_thread::get_id() << std::endl; // 현재 스레드 ID 얻기

    std::this_thread::sleep_for(3s); // 현재 thread를 재울때

}


