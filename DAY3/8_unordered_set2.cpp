#include <iostream>
#include <set>
#include <unordered_set>
#include "show.h"

int main()
{
//	std::set<int> s;
	std::unordered_set<int> s;

	s.insert(10);
	s.insert(35);
	s.insert(20);
	s.insert(25);	// set 		 	 : 
					// unordered_set : 

	auto p = s.find(20); 

	std::cout << *p << std::endl;

	show(s);
}

