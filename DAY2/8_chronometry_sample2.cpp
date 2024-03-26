#include "chronometry.h"
#include <vector>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }

struct Less { inline bool operator()(int a, int b) { return a < b; }};

std::vector<int> v1;
std::vector<int> v2;
std::vector<int> v3;
std::vector<int> v4;
constexpr std::size_t size = 5'000'000; 	

void init()
{
	v1.reserve(size);
	v2.reserve(size);
	v3.reserve(size);
	v4.reserve(size);

	for( int i = 0; i < size; i++)
	{	
		int value = rand();

		v1.push_back(value);
		v2.push_back(value);
		v3.push_back(value);
		v4.push_back(value);
	}
}

void use_default_policy()
{
	std::sort(v1.begin(), v1.end());
}

void use_function()
{
	std::sort(v2.begin(), v2.end(), cmp1);
}

void use_function_object()
{
	Less f;
	std::sort(v3.begin(), v3.end(), f);
}

void use_lambda()
{
	std::sort(v2.begin(), v2.end(), [](int a, int b){ return a < b;});
}

int main()
{	
	init();
	chronometry(use_default_policy);
	chronometry(use_function);
	chronometry(use_function_object);
	chronometry(use_lambda);
}
