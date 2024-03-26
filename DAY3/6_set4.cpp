#include "show.h"
#include <set>

struct Compare
{
	bool operator()(int a, int b) const
	{
		return (a / 10) < (b / 10);
	}
};

int main()
{
	std::set<int, Compare> s;
	
	// #1. 다음중 실패는 ?
	s.insert(15);
	s.insert(25);
	s.insert(45);
	s.insert(35);
	s.insert(22); 
	show(s);

	// #2. 아래 2개의 검색 결과는 어떻게 나올까요 ?
	// #2-1. equivalency 
	auto ret1 = s.find(12); 
	
	if (ret1 == s.end())
		std::cout << "실패" << std::endl;
	else 
		std::cout << *ret1 << std::endl;


	// #2-2. 아래 코드가 equality
	auto ret2 = std::find(s.begin(), s.end(), 12); 
	if (ret2 == s.end())
		std::cout << "실패" << std::endl;
	else 
		std::cout << *ret2 << std::endl;
	

}
