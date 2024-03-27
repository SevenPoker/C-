#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	std::counted_iterator ci(v.begin(), 5);

	// ? 를 생각해 보세요
	auto ret = std::find(ci, ?, 3);


	while( ci.count() != 0 )
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}

