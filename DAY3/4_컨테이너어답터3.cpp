#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

int main()
{
	// 다음중 에러를 모두 골라 보세요
	std::stack<int, std::list<int>>   s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int, std::deque<int>>  s3;

	std::queue<int, std::list<int>>   q1;
	std::queue<int, std::vector<int>> q2;
	std::queue<int, std::deque<int>>  q3;
}



