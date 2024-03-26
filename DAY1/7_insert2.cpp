// insert2.cpp
#include <iostream>
#include <algorithm>
#include <list>


int main(int argc, char** argv)
{
	
	std::list<int> s1 = { 1, 2, 3, 4, 5 };
	std::list<int> s2 = { 0, 0, 0, 0, 0 };

	// #1.	
	std::copy(s1.begin(), s1.end(), s2.begin()); // 덮어쓴다.

	for (auto& n : s2)
		std::cout << n << std::endl; 
}
