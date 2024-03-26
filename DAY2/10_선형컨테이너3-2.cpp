#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v1;		// size = 0, capacity = 0
	std::vector<int> v2(1000);  // size = 1000, capacity = 1000;
	std::vector<int> v3;
	v3.reserve(1000); // size = 0; capacity = 1000

	v1.push_back(0); // 메모리 1개 할당해서 0번째 넣기
	v2.push_back(0); // 메모리 2000개 할당해서 1001번째넣기
	v3.push_back(0); // 메모리 재할당 없고, 1번째 넣기

//	std::cout << v.size() << ", " << v.capacity() << std::endl;
	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
	std::cout << v2.size() << ", " << v2.capacity() << std::endl;
	std::cout << v3.size() << ", " << v3.capacity() << std::endl;

	return 0;
}

