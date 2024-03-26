#include <iostream>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sum(s.begin(), s.end());

	std::cout << n << std::endl; // 55
}
