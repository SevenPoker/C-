#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// 알고리즘은 컨테이너를 알지 못한다.

int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = std::remove(v.begin(), v.end(), 3);

	show(v);  


	return 0;
}



















//
