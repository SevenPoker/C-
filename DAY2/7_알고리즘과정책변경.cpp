// 3_알고리즘과정책변경
#include <iostream>
#include <vector>
#include <algorithm>  // 정렬, 검색등의 알고리즘
#include <numeric>    // 수치 관련 연산 (합, 부분합, 내적...)
#include <functional>
#include "show.h"

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };

	std::sort(v1.begin(), v1.end()); // <algorithm>

	// #1. numeric에 있는 함수이다.
//	int n = std::accumulate(v1.begin(), v1.end(), 0);

	// #2. STL은 많은 알고리즘은 "정책 변경"이 가능합니다.
//	int n = std::accumulate(v1.begin(), v1.end(), 1,
//							[](int a, int b){return a * b;});

	// +, -, *, %, / 등의 연산을 수행하는 함수객체가 이미 있다.
	int n = std::accumulate(v1.begin(), v1.end(), 1,
							std::multiplies<int>() );

	std::cout << n << std::endl;
}

// https://en.cppreference.com/


