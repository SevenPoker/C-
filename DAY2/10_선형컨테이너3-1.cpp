#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = std::remove(v.begin(), v.end(), 3);

	std::cout << v.size() << ", " << v.capacity() << std::endl; // 10, 10

	v.erase(p,v.end()); // p ~ v.end() 제거..

	show(v);
	std::cout << v.size() << ", " << v.capacity() << std::endl; // 7, 10

	v.clear(); // 모두 clear
	std::cout << v.size() << ", " << v.capacity() << std::endl; // 0, 10

	// 제거하려면 shrink_to_fit 또는 복사 생성자 사용
	v.shrink_to_fit();
	std::cout << v.size() << ", " << v.capacity() << std::endl; // 0, 10

	return 0;
}

