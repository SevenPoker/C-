#include <iostream>
#include "show.h"

#include <set> 

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// #1. 중복 허용 안함, 반환값
	s.insert(15);

	// #2. 요소 삽입은 insert(또는 emplace) 만 가능
	s.push_back(50); // ?

	// #3. 반복자는 읽기만 가능
	auto p = s.begin();
	*p = 20;
	

	// #4. 검색
	auto ret1 = std::find(s.begin(), s.end(), 30);


	// #5. 값이 있는지 조사
	
}







