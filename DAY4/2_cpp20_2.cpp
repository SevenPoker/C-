#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

// 핵심 2
// 1. 기존 알고리즘은 구간을 전달하기 위헤 "반복자 2개"를 인자로 받고 있습니다.
// 2. 그런데, C++20 부터 일부 반복자는 한개로 구간 표현.
//    => last를 표현할ㄹ 방법이 필요했다.
//    => "sentonel(보초병)" 의 개념이 등장한다.

// C++98 구간 : first ~ last
// C++20 구간 : first ~ sentinel
//						=> last 일 수도 있고, default_sentinel 일 수도있다.


int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	std::counted_iterator ci(v.begin(), 5);

	// ? 를 생각해 보세요
//	auto ret = std::find(ci, ?, 3);


//	while( ci.count() != 0 )
	while( ci != std::default_sentinel )
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}

