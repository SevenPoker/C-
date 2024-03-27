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

	std::cout << s.bucket_count() << std::endl;
    // bucket count는 unordered_set에서 사용가능
	// s.reserve(200) 하면 bucket size가 200으로 증가한다.
	// 초기는 size가 13인데 계속 넣으면 늘어난다. 재할당이 또 일어난다.

	for (int i = 0; s.bucket_count(); i++)
	{
		std::cout << s.bucket_size(i) << std::endl;
	}
}

