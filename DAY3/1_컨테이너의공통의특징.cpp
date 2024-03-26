// STL 컨테이너의 특징
#include <vector>
#include <iostream>
#include "show.h"


template<typename T, typename Ax = std::allocator<T> >
{
	Ax ax;
public:
	// STL 컨테이너에는 많은 멤버 타입이 있습니다.
	using iterator = vector_iterator;
	using value_type = T;
	using pointer = T*;
	using size_type = std::size_t;

	size_type size() const {return sz;}
};


int main()
{
	std::vector<int> v = { 1,2,3 };

	// 1. 멤버 타입이 있다.
	// auto 빼고 최선의 코드는??
	// std::size_t == unsigned int (하지만 이럴경우 나중에 vector가 진화해서 unsigned int에 못담을 수도 있다.)
	// 따라서 아래처럼 vector를 만들때의 size type을 알려주는 인자를 사용해야한다.
	// 미래를 생각해서 그렇게 만들었다.
	// cppreference에 보면 알수 있다.
	std::vector<int>::size_type sz = v.size();
	// int를 쓰는것 보다는 auto를 써라

    std::vector<int>::difference_type cnt = v.end() - v.begin();

	// 2. 반환과 제거를 동시에 하는 멤버함수는 없다!!
	int n = v.pop_back();	// error. pop_back은 제거만 하고 반환을 하지 않는다.
	// 따라서 제일 마지막꺼를 얻고 싶을떄는 먼저 찾아야한다.
	int k = v.back();
	// 찾고 제거하려면 back하고 pop_back을 해야한다.
	// 동기화할때 주의해야한다.

	// 3. 단위 전략을 많이 사용한다.
	std::vector<int, debug_alloc<int>> v2; // ?
}
