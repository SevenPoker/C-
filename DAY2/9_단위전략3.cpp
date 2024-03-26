#include <set> // Red Black Tree
#include <functional>
#include "show.h"


int main()
{
	std::set<int> s; // Red Black Tree 입니다.

	s.insert(15);
	s.insert(25);
	s.insert(5);
	s.insert(17);
	s.insert(10);

	show(s);
}
