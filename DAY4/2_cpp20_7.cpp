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

	for(auto e : rv)
	{
		std::cout << e << ", ";
	}	
}

