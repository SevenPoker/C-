#include <iostream>
#include <chrono>

// duration 정의 : 특정 단위의 갯수(tick count)를 표현하는 자료구조
//				  값 한개와, 단위를 관리
//				  10초 => 1초의 10개
//				  10분 => 1분의 10개

int main()
{
	// duration 사용
	// 1. duration은 "값 한개"만 보관한다.
	// 2. 그런데, 템플릿 인자로 단위도 전달한다.


	std::chrono::duration<int, std::ratio<1, 100>>  d1(2); // 1/100 * 2

	//                          요게 몇개가 있어야    이게 되냐??
	std::chrono::duration<int, std::ratio<1, 1000>> d2(d1); 

	std::cout << d1.count() << std::endl;
	std::cout << d2.count() << std::endl;

	std::chrono::duration<int, std::ratio<1, 50000>> d3(d1);

	std::cout << d3.count() << std::endl;
}
