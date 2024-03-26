#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> s = { 1,2,3,4,5,6,7,8,9, 10};
	auto p = s.begin();

	// 반복자 p를 5칸 전진하고 싶다.
	p = p + 5; // vector 등의 random access iterator 만 가능
			   // list 반복자는 error
	++p; ++p; ++p; ++p; ++p; // ok 모든 반복자에 동작.
							// 임의 접근인 경우에는 성능이 느리다.

	// 아래처럼 하세요!!

	std::advance(p,5); // 반복자를 5칸 전진해달라.
						// 1. p가 임의 접근이면 + 사용
						// 2. 임의 접근이 아니면 ++ 사용

	std::cout << *p << std::endl;
}
