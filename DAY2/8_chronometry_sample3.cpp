#include "chronometry.h"
#include <vector>
#include <list>
#include <algorithm>

constexpr std::size_t size = 10'000'000;

std::vector<int> v;
std::list<int> s;


void use_list()
{
	for( int i = 0; i < size; i++ )
	{
		s.push_back(0);
	}
}

void use_vector()
{
	for( int i = 0; i < size; i++ )
	{
		v.push_back(0);
	}
}

int main()
{	
	chronometry(use_list);
	chronometry(use_vector);
}