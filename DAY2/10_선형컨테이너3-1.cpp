#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = std::remove(v.begin(), v.end(), 3);

	std::cout << v.size() << ", " << v.capacity() << std::endl;

	v.erase(p,v.end());

	return 0;
}

