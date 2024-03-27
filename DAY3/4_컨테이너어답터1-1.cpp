#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 단위전략 (policy Base design)

// STL의 stack이 이렇게 만들어져 있다.
#include <stack> // 흔히 "stack adapter" 라고 부릅니다.
template<typename T, typename Container = std::deque<T> >
class stack
{
	Container c;
public:
	void push(const T& a) {c.push_back(a);}
	void pop()			  {c.pop_back();}
	T& top()			{return c.back();}
};

int main()
{
	stack<int, std::list<int>> s1; // list를 stack 처럼 사용하겠다는 의미
	stack<int, std::vector<int>> s2;
	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}
