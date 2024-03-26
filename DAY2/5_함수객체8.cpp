#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// #1. 비교정책을 전달하지 않으면 오름 차순
	std::sort(v.begin(), v.end());

	// #2. 비교 정책을 교체하는 방법.

	
}









