#include <iostream>
#include <chrono>

// duration 정의 : 특정 단위의 갯수(tick count)를 표현하는 자료구조
//				  10초 => 1초의 10개
//					   => 1/1000초의 10000개..

int main()
{
	// 1. duration 사용
	std::chrono::duration<int, std::ratio<1, 100>>  d1(2); // 1/100 * 2
	std::chrono::duration<int, std::ratio<1, 1000>> d2(d1); 

}
