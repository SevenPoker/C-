#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	auto p1 = s.begin();
	auto p2 = s.end();

	// #1. reverse iterator 만들기
	std::reverse_iterator< std::list<int>::iterator > r1(p2);




	std::cout << *r1 << std::endl;
	++r1;
	std::cout << *r1 << std::endl;
	
	// #2. reverse_iterator 만드는 3가지 방법
	// C++17 이전. 타입을 전달
	std::reverse_iterator< std::list<int>::iterator > r1(p2);

	// C++17 부터는 타입 생략 가능
	std::reverse_iterator r1(p2);

	// C++17 이전이라도 함수 버전을 사용하면 편리하다.
	auto r4 = std::make_reverse_iterator(p2);

}
