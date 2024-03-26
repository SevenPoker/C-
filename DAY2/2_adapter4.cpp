#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10 };

	// container에서 꺼낼수 있는 반복자는 4가지 종류가 있다.
	// #1. 정방향 반복자
	std::list<int>::iterator p1 = s.begin(); // 일반함수버전 : std::begin(s)

	// #2. 역방향 반복자
	std::list<int>::reverse_iterator p2 = s.rbegin(); // std::rbegin(s)

	// #3. 상수반복자
	// 아래는 쓰기가 안된다.(안정성을 위해서)
	std::list<int>::const_iterator p3 = s.cbegin(); // std::cbegin(s)
	// *p3 = 10; // error 쓰기 안됨
	int n = *p3;

	// #4. 상수 역방향 반복자
	std::list<int>::const_reverse_iterator p4 = s.crbegin(); // std::crbegin(s)



}
