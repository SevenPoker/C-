#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

// C++20 의 핵심 1.
// C++98 : 구간을 표현하려면 "2개의 반복자" 필요
// C++20 : 한개의 반복자도 구간을 표현할 수 있다.
//			ex) std::counted_iterator

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	// C++20 에서 새로 추가된 반복자
	// v.begin 부터 5칸을 가겠다.
	std::counted_iterator ci(v.begin(), 5);
	// 위의 코드는
	// std::counted_iterator<std::vector<int>::iterator> ci(v.begin(),5);

	while( ci.count() != 0 )
	{
		std::cout << *ci << std::endl;
		++ci;
	}

}
