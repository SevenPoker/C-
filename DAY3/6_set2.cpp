#include <iostream>
#include "show.h"

#include <set> 

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// #1. 중복 허용 안함, 반환값
	s.insert(15);	
	// 중복 허용을 안해서 실패!!! set은 실패했을때 해당 위치의 반복자 + 성공/실패의 정보를 내주기 때문에 pair로 받아야한다.
//	std::pair<std::set<int>::iterator ,bool> ret = s.insert(15);
	// auto 쓰면 해결되긴한다.
	auto ret = s.insert(15);	

	if(ret.second == false)
		std::cout << "fail duplicate number \n";


	// #2. 요소 삽입은 insert(또는 emplace) 만 가능
	s.push_back(50); // error !! 어차피 root 부터 찾아서 넣어야하기 때문에 안만듬


	// #3. 반복자는 읽기만 가능
	auto p = s.begin();
	*p = 20; // error!! (중간에 쓰면 root도 다 바뀌어야하는데 말이 안됨)


	// #4. 검색
	// => 아래 코드는 에러가 아니지만 (일반함수)
	// => 성능이 되게 안좋습니다.
	// => std::find는 선형함수이다.
	auto ret1 = std::find(s.begin(), s.end(), 30);

	// 이게 훨씬 좋은 코드이다.
	// 알고리즘 보다 멤버 함수를 우선 사용해라!!
	auto ret2 = s.find(30);


	// #5. 값이 있는지 조사
	auto ret3 = s.find(30);
	if (ret3 == s.end()) std::cout << "값없어요~";

	// C++20 부터 들어온 함수
	if (s.contains(30)) {}
}
