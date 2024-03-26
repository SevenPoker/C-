#include <forward_list>
#include <list>

int main()
{
	std::forward_list<int> s1 = { 1,2,3 }; // single linked list

	std::list<int> s2 = { 1,2,3 }; // double linked list

	auto p1 = s1.begin();
	auto p2 = s2.begin();
	
	++p1; // ok
	--p1; // error. 자료구조 특성상 안된다.
	++p2; // ok
	--p2; // ok

}
