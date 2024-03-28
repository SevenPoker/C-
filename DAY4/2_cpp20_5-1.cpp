#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <ranges>
#include "show.h"

int main()
{
	std::list<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::list<int> s2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// s1 의 모든 내용을 s2로 복사해 보세요
	std::copy(s1.begin(), s1.end(), s2.begin());

	// C++20
	// => 구간이 요구되는 인자는 "컨테이너 이름"으로 전달 가능합니다.
	std::ranges::copy(s1.begin(), s1.end(), s2.begin());
	std::ranges::copy(s1,s2.begin()); // ok
	
	show(s2);
}

