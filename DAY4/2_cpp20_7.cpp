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
	// v를 그 다음에 보내, 그리고 또 그다음에 보내, 그리고 또 그다음에 보내
	// v -> filter -> take -> reverse 순으로

	auto rv2 = v | std::views::filter( [](int n){return n % 2 == 0;} )
			     | std::views::take(3) | std::views::reverse;

	// 새롭게 나오고 있는 방식 - 아래처럼 사용하게 하자!!
	// C#의 Linq 방식, Rust의 iterator 방식
//	auto rv3 = v.filter( [](int n){return n % 2 == 0;} ).take(3).reverse();

	for(auto e : rv2)
	{
		std::cout << e << ", ";
	}	
}

