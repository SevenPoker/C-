#include <vector>

template<typename T> 
class Queue 
{
	std::vector<T> v;

public:
	// vector에서는 pop_front()가 없다.
	void pop() { v.pop_front(); }
	void push() {v.push_back();}
};

// template란 class가 아니라 class를 찍어내는 틀이다.
// Queue라는 틀에다가 int형 class를 만들어라~
// 그러면 vector<T> -> vector<int> 로바뀜
// 만약 100개를 만들고 2개만 사용하면 나머지 98개는 class 생성을 안한다
// push_back을 사용하면 틀에서 안에 push_back을 만든다. (사용하는 것만 찍어낸다.)
// 사용 되지 않은 함수는 찍어내지 않는다.

int main()
{
	Queue<int> q;

	// 지연된 인스턴스화
	// => 클래스 템플릿의 멤버함수는 "사용되는 것만 인스턴스화 한다."
	// => 따라서 아래 코드가 없다면 위 queue 코드는 에러가 아니다.
	q.pop();
}
