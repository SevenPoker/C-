#include "show.h"
#include <stack>
#include <list>
#include <vector>

int main()
{
	std::vector<int, debug_alloc<int>> v;

//	std::stack<int> s;
//	std::stack<int, debug_alloc<int>> s; // error

	std::stack<int, std::vector<int, debug_alloc<int>> > s;
	std::stack<int, std::vector<int, debug_alloc<int>> > s;

	s.push(0);
	// 이 순간 메모리 할당 정보를 볼 수 있도록
	// 위코드에 allocator를 변경해보자, debug alloc으로
	// 1-1. cpp 코드를 보고 생각해보자.
}