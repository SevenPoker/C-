#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);

	auto first = s.begin();
	auto last  = s.end();

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
	
}







