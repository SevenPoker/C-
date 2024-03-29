#include <iostream>
#include <type_traits>
#include <vector>

void foo(T& c)
{
	? n = c.front();
}

int main()
{
	std::vector<int> v = {1,2,3};
	foo(v);
}

