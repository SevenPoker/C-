#include <iostream>

// list 가 이미 있습니다
#include <list>
#include <vector>
#include <deque>

// 그런데, 스택이 필요합니다.
// 1. 새로 만들자.
// 2. list를 스택처럼 보이게 하자.

// 1. list 의 멤버함수 이름을 stack 처럼 보이게 하고
// 2. list 를 뒷쪽으로만 입/출력 할수 있게 하자

// adapter 패턴 : 기존 클래스의 인터페이스(멤버함수이름)을 변경해서
//				  다른 클래스처럼 보이게 만드는 디자인 기법

// STL의 stack이 "adapter 패턴"으로 설계된 것

template<typename T>
class stack
{
	std::list<T> c;
public:
	void push(const T& a) {c.push_back(a);}
	void pop()			  {c.pop_back();}
	T& top()			{return c.back();}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}
