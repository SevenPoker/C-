#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <ranges>
#include "show.h"


template<typename R>
class take_view
{
	R& rg;
	std::size_t cnt;
public:
	take_view(R& r, std::size_t c) : rg(r), cnt(c) {}

	auto begin() {return rg.begin();}
	auto end() {return std::next(rg.begin(),cnt);}
};



template<typename R>
class reverse_view
{
	R& rg;
public:
	reverse_view(R& r) : rg(r) {}

	auto begin() {return rg.rbegin();}
	auto end() {return rg.rend();}
};

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};


	take_view tv(v, 5);
	// vector를 모두 열거하는 코드
	for(auto e : v)
	{
		std::cout << e << ", ";
	}

	// 5개만 읽어간다.

	for(auto e : tv)
	{
		std::cout << e << ", ";
	}

	// reverse로 읽는다.
	for(auto e : reverse_view(v))
	{
		std::cout << e << ", ";
	}

}

