#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int, debug_alloc<int> > v1;

	v1.reserve(100);
	// 아래 코드가 몇번의 할당이 있을것인가?
	// 2배씩 커진다.
	for (int i = 0; i < 30; i++)
	{
		v1.push_back(0);
	}
}

