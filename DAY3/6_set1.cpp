#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

// 표준 문서 : set을 구현할때 tree를 사용하라고 강제하지는 않았다.
// 동작에 대한 정의만 해놓았음. (몇초내로 나와야대~ 이런느낌으로)
// 그래서 대부분 컴파일러는 "RED BLACK TREE"로 구현되어 있다.

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);
	s.insert(17);
	s.insert(25);

	auto first = s.begin(); // 가장 왼쪽
	auto last  = s.end(); // 오른쪽 마지막 다음 노드

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
}







