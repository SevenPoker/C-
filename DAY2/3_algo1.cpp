#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 알고리즘 기본
// 일반적인 의미 : 문제를 해결하는 방법ㄴ

// STL에서는 std::find와 같은 일반 함수 템플릿

// <algorithm>, <numeric>

// 핵심 : 멤버 함수가 아닌 일반함수(템플릿)

int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
	
	auto p = std::find( v.begin(), v.end(), 3);

	return 0;
}

