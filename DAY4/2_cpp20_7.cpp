#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <ranges>
#include "show.h"

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	// #1. 중첩도 가능
	std::ranges::take_view tv(v, 5);
	std::ranges::reverse_view rv(tv);

	// #2. 단축 표기법 (syntax sugar) 도 제공한다.
	// => 리눅스의 파이프라인을 흉내낸것

	auto rv2 = v | std::views::filter( [](int n){return n % 2 == 0;} )
			     | std::views::take(3) | std::views::reverse;


	for(auto e : rv2)
	{
		std::cout << e << ", ";
	}	
}

