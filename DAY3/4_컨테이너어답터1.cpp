#include <iostream>

// list 가 이미 있습니다
#include <list>
#include <vector>
#include <deque>

// 그런데, 스택이 필요합니다.
// 1. 새로 만들자.
// 2. list를 스택처럼 보이게 하자.

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}
