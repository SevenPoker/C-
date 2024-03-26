#include <stack>
#include <queue> // queue, priority_queue
#include <iostream>
#include "show.h"

int main()
{
	// 우선순위큐 : 요소를 꺼낼때 우선순위가 가장 높은
	//			요소가 나오게 된다.
	std::priority_queue<int> pq;
	pq.push(10);
	pq.push(-10);
	pq.push(-20);
	pq.push(20);
	pq.push(15);

	std::cout << pq.top() << std::endl; 
	pq.pop();
	std::cout << pq.top() << std::endl; 

}



