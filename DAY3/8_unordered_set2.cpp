#include <iostream>
#include <set>
#include <unordered_set>
#include "show.h"

int main()
{
//	std::set<int> s;
	std::unordered_set<int> s;

	s.insert(10);
	s.insert(35);
	s.insert(20);
	s.insert(25);	// set 		 	 : root 와 비교해서 왼쪽/오른쪽으로 배치
					// unordered_set : 25 를 hash 함수로 보내서, hash값을 얻은 후
					// 					bucket에 보관한다.

	auto p = s.find(20); 
	// set : root 부터 크기를 비교해서 검색
	// unordered_set : 해쉬 함수로 해쉬값 얻어서 검색한다.

	// unordered_set의 경우는 정렬이 되지 않는다.
	// 정렬되지 않은 set이라고 해서 unordered set이라고 불림
	std::cout << *p << std::endl;

	show(s);
}

