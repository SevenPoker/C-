// 3개의 컨테이너 어답터가 있습니다.
#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

int main()
{
	std::stack<int> s1;
	s1.push(10);
	s1.pop(); // 제거

	int n = s1.top();

	std::queue<int> q1;
	q1.push(10);

	int n2 = q1.front(); // <== !!


}
