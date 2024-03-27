#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

int main()
{
	// stack : 한방향으로 접근
	// queue : 양방향으로 접근. vector는 앞쪽이 막혀있다.

	// 다음중 에러를 모두 골라 보세요
	std::stack<int, std::list<int>>   s1; // ok
	std::stack<int, std::vector<int>> s2; // ok
	std::stack<int, std::deque<int>>  s3; // ok

	std::queue<int, std::list<int>>   q1; // ok
	std::queue<int, std::vector<int>> q2; // error, 단 컴파일은 된다.
	std::queue<int, std::deque<int>>  q3; // ok

	q2.push(90); // ok
	q2.pop(); // error. 내부적으로 vector.pop_front() 호출

}



