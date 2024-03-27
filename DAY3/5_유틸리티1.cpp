#include <iostream>
#include <tuple>
#include "show.h"

int main()
{
	// pair : 서로다른 타입 2개를 보관하는 구조체

	std::pair<int, double> p1(1, 3.4);

	std::cout << p1.first << std::endl; // 1
	std::cout << p2.second << std::endl; // 3.4

	std::pair<int, std::pair<double, int>> p2(1,{3.4, 2});

	// C++11 부터 pair의 일반화 버전이 tuple 제공
	std::tuple<int, double, int> t1(1, 3.4, 3);

	// template 인자라서 <1> 안에 변수를 못넣는다.
	std::cout << std::get<1>(t1) << std::endl; // 3.4

	// pair, tuple 을 만드는 함수도 있습니다.
	auto p3 = std::make_pair (1, 3.4);
	auto t4 = std::make_tuple (1, 3.4, 1);
}


