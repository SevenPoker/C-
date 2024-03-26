#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2 = { 0,0,0,0,0,0,0,0,0,0 };

	// #1. 기본형 (in place 버전)
	auto p1 = std::remove(v1.begin(), v1.end(), 3);

	// #2. 조건자(predicator) 버전
	// 짝수들을 제거하고싶다.
	auto p2 = std::remove_if(v1.begin(), v1.end(), [](int n) { return n %2 == 0;});

	// #3. 복사 버전
	// p3의 경우 v2의 반복자를 return 한다.
	// _copy 의 경우 성능 향상이 되는 애들만 존재한다.
	auto p3 = std::remove_copy(v1.begin(), v1.end(), v2.begin(), 3);

	// #4. 복사 조건자 버전
	auto p4 = std::remove_copy_if(v1.begin(), v1.end(), v2.begin(),
									[](int n) { return n %2 == 0;});

	show(v1);
	show(v2);
}
