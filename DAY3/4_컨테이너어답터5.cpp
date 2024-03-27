#include "show.h"
#include <queue> // queue와 priority queue

template<typename T>
class PQ : public std::priority_queue<T>
{
public:
	void print() const
	{
		show(this->c); // 기반 클래스인 std::priority_queue<T> 가 가진
				       // 컨테이너의 멤버이름이 "c" 입니다.
	}
};	


int main()
{
	PQ<int> pq; // Heap 알고리즘
	pq.push(10); pq.print();
	pq.push(-10); pq.print();
	pq.push(-20); pq.print();
	pq.push(20); pq.print();
	pq.push(15); pq.print();

	pq.pop(); pq.print();
	pq.pop(); pq.print();
	pq.pop(); pq.print();
	pq.pop(); pq.print();
}
