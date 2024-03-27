#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <ranges>
#include "show.h"

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	for(auto e : v)
	{
		std::cout << e << ", ";
	}	
}

