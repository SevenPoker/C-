#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals;

int main()
{
	std::cout << "============== \n";

	// 현재 thread를 특정시간 동안 재우는 함수는 "std::this_thread::sleep_for"입니다.
	// 3초간 재우자.
	
//	std::this_thread::sleep_for(3); // error
	
	std::this_thread::sleep_for(0.5s);
	
	std::this_thread::sleep_for(std::chrono::seconds(3)); // error
	
	std::cout << "============== \n";

}
