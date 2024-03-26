#include <iostream>
#include <list>
#include <iterator>

int main(int argc, char** argv)
{
	std::list<int> s = { 1, 2, 3, 4, 5};

	// 컨테이너의 끝에 요소를 "추가"하는 방법
	// #1. push_back 멤버 함수 사용
	s.push_back(10);

	// #2. 삽입 반복자 사용
	std::back_insert_iterator<std::list<int>> p1(s); // s의 끝에 추가하는 반복자
	std::back_insert_iterator p2(s); // C++17 부터는 타입생략이 가능하다.

	auto p3 = std::back_inserter(s); // object generator 기술로 만든
									 // 삽입 반복자 객체를 만드는 함수 템플릿
	*p1 = 20;
}
