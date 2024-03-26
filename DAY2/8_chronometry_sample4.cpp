#include "chronometry.h"
#include <vector>
#include <list>
#include <algorithm>

constexpr std::size_t size = 10'000'000;

//using C = std::list<int>;
using C = std::vector<int>;

C c1;
C c2;

void use_push_back()
{
	for( int i = 0; i < size; i++ )
	{
		c1.push_back(0);
	}
}

void use_back_inserter()
{
	auto p = std::back_inserter(c2);

	for( int i = 0; i < size; i++ )
	{
		*p = 0;
	}
}

int main()
{	
	chronometry(use_push_back);
	chronometry(use_back_inserter);
}
